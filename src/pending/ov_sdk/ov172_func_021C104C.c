/*
 * function: Yos_JpegEncoderHuffmanEncoderBuildTable
 * address:  0x021C104C
 * packet:   pkt_ov172_021C104C
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  register allocation: image uses 6 callee-saved (r4,r5,r6,r7,r8,sb) with
 *   code=sb and kk=r8 for all three phases; ours uses 5 (code=r8; kk splits r3->r6
 *   across phases). Same 508 B size, pool aligned at +01DC, all 14 relocs resolve.
 *   45 concrete bytes, all register-colouring in the loop bodies/prologue.
 *
 * lane4 (w10): LOOP SHAPE SOLVED.  The image keeps every loop unrotated (`b` to the
 *   bottom test, no peeled guard).  Writing each loop condition as `(cond) ? 1 : 0`
 *   (docs/idioms/a-loop-entered-by-a-branch-to-its-bottom-test-has-a-ternary-condition.md)
 *   on the ii for, the jj for and the two while loops (the kk for stays plain) takes the
 *   function from 520 to 508 bytes (the SDK row size) and the pool lands at +01DC, so the
 *   eight ABS32 table sites now line up.  The last loop body also needs
 *   `u32 v = hf->mHuffValues[kk]` (the image loads the byte once, r2).  241 -> 55 concrete
 *   bytes.  Residue is pure colouring: image idx=r7 / code=sb / ii=r7 / kk=r8 / jj=r3
 *   (six callee-saved regs, pushes r3 as padding); ours idx=r8 / code=r7 / ii=r3 /
 *   kk=r6 / jj=r2 (five).  Permuting the five local declarations (120 orders, now with
 *   the right loop shape) only moves 59 to 55; moving `code = 0` later, a 300+ compile
 *   permuter run: no gain.
 *
 *   lane (w24): still 55.  Tried with no gain: declaration order (irrelevant once ii is
 *   merged into idx), ii merged into idx (same 55; regs become idx=sb/kk=r8/code=r7, the
 *   image wants code=sb/kk=r8/idx=r7), for-scoped locals, int types (signed blt), post-inc
 *   forms, `kk = ii = 0` / comma init variants, hoisting ii = 0 before the first clear, and
 *   a 180-way role renaming of ii/jj/kk/si/last-loop var (best 47, different shape).
 *   Image has ii=0 (r7) hoisted before the clear call with kk = copy; ours hoists kk.
 *
 *   lane (w25): 55 -> 48.  Moving si++ before code = code << 1 matches the image order
 *   (lsl, add si, lsr).  Still colouring only (idx=sb/code=r7 vs r7/sb, kk r8 then r6 then
 *   r3 vs r8 throughout).  No gain: sel copy of idx for the switches, ii=0;kk=0 orders, code
 *   declared late/as block, post-inc/compound forms, last loop on idx, pointer local for the
 *   first clear, for<->while, 12k permuter compiles (random+anneal, 5 seeds), one dummy use
 *   (if (v) {}) of each var at ~25 positions (all >= 48).
 *
 *   lane (w26): 48 concrete bytes, no change.  Image keeps THREE distinct webs across the
 *   phase-2 clear: code=sb, kk=r8, and the materialised constant-0 in r6; ours lets the
 *   constant-0 web (r6) merge with kk in phase 2, so kk lands r3(phase1)->r6(phase2) and we
 *   push 5 callee-saved instead of 6.  Read docs/idioms/reusing-a-loop-variable-across-phases-
 *   changes-the-allocation.md and a-second-same-typed-local-changes-callee-saved-allocation.md.
 *   Hoisting `kk = 0` above the first MIi_CpuClearFast (to make kk's web span the early calls)
 *   compiles to 230 concrete bytes different (scheduling collapses), not a lever.  The residue
 *   is the front end's tie-break between the constant-0 rematerialisation and kk, not a source
 *   shape: park.
 *
 * sdk:      Yos_JpegEncoderHuffmanEncoderBuildTable (libssp.TWL.HYB.a jpegenc.o)
 *
 * symbols:
 *   MIi_CpuClearFast                0x02082AC0  arm
 *   MIi_CpuCopyFast                 0x02082B0C  arm
 *   MI_CpuCopy                      0x02082EA4  arm
 *   dc0_tbl                         0x021C8500  data  ov172
 *   dc1_tbl                         0x021C8520  data  ov172
 *   ac0_tbl                         0x021C86C0  data  ov172
 *   ac1_tbl                         0x021C8600  data  ov172
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct huffman_structure {
    u32 mFrequencies[257];
    u8  mHuffBits[32];
    u8  mHuffValues[256];
    u16 mEhufco[258];
    u8  mEhufsi[260];
} huffman_structure;

typedef struct Yos_JpegEncoderHuffmanEncoderBuildTableWork {
    u32 mHuffSize[256];
    u32 mHuffCode[256];
} Yos_JpegEncoderHuffmanEncoderBuildTableWork;

extern void MIi_CpuClearFast(u32 data, void *destp, u32 size);
extern void MIi_CpuCopyFast(void *srcp, void *destp, u32 size);
extern void MI_CpuCopy(void *srcp, void *destp, u32 size);
extern u8 dc0_tbl[28];
extern u8 dc1_tbl[28];
extern u8 ac0_tbl[178];
extern u8 ac1_tbl[178];

static void Yos_JpegEncoderHuffmanEncoderBuildTable(Yos_JpegEncoderHuffmanEncoderBuildTableWork *pWork,
                          huffman_structure *hf, u32 idx)
{
    u32 jj;
    u32 ii;
    u16 code = 0;
    u32 kk;
    u32 si;


    MIi_CpuClearFast(0, &hf->mHuffBits[0], 0x428);

    switch (idx) {
    case 0: MIi_CpuCopyFast(dc0_tbl, &hf->mHuffBits[0], 0x10); break;
    case 1: MIi_CpuCopyFast(dc1_tbl, &hf->mHuffBits[0], 0x10); break;
    case 2: MIi_CpuCopyFast(ac0_tbl, &hf->mHuffBits[0], 0x10); break;
    case 3: MIi_CpuCopyFast(ac1_tbl, &hf->mHuffBits[0], 0x10); break;
    }

    switch (idx) {
    case 0: MIi_CpuCopyFast(dc0_tbl + 0x10, &hf->mHuffValues[0], 0xc); break;
    case 1: MIi_CpuCopyFast(dc1_tbl + 0x10, &hf->mHuffValues[0], 0xc); break;
    case 2: MI_CpuCopy(ac0_tbl + 0x10, &hf->mHuffValues[0], 0xa2); break;
    case 3: MI_CpuCopy(ac1_tbl + 0x10, &hf->mHuffValues[0], 0xa2); break;
    }

    MIi_CpuClearFast(0, pWork, 0x400);
    ii = 0;
    kk = 0;
    while ((ii < 0x10) ? 1 : 0) {
        for (jj = 0; (jj < hf->mHuffBits[ii]) ? 1 : 0; jj++)
            pWork->mHuffSize[kk++] = ii + 1;
        pWork->mHuffSize[kk] = 0;
        ii++;
    }

    MIi_CpuClearFast(0, pWork->mHuffCode, 0x400);
    kk = 0;
    si = pWork->mHuffSize[0];
    while ((pWork->mHuffSize[kk] != 0) ? 1 : 0) {
        while ((pWork->mHuffSize[kk] == si) ? 1 : 0) {
            pWork->mHuffCode[kk] = code;
            code = code + 1;
            kk++;
        }
        si++;
        code = code << 1;
    }

    for (kk = 0; (kk < 0x100) ? 1 : 0; kk++) {
        if (pWork->mHuffSize[kk] != 0) {
            u32 v = hf->mHuffValues[kk];
            hf->mEhufco[v] = pWork->mHuffCode[kk];
            hf->mEhufsi[v] = pWork->mHuffSize[kk];
        }
    }
}
