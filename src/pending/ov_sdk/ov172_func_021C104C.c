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
 *
 * blocker: codegen/register allocation.  Algorithm reconstructed in full
 *   (clear, table copies, huffsize build, huffcode build, mEhufco/mEhufsi)
 *   and all relocations resolve; 520 of ~508 bytes.  mwcc -O4,p assigns the
 *   long-lived locals differently: original has code=sb (r9), kk=r8,
 *   ii/idx=r7 and reserves r6 as a sentinel zero, mine has code=r7,
 *   idx=r8, kk=sb.  Needs the exact source spelling that drives
 *   the callee-saved allocation.
 *
 * Lane U38 (2026-09-30), measured, two findings:
 *  (1) Declaration order is NOT the lever here.  All 120 permutations of the
 *      five local declarations (u16 code; u32 si/kk/jj/ii) compile to 520
 *      bytes / 241 concrete bytes, i.e. mwcc's colouring is invariant, so the
 *      "declaration reordering" doubt above is now settled: stop re-ordering.
 *      The rotation of the DWARF order (code r9, si r2, kk r8, jj r3, ii r7)
 *      is not reachable from any order of these five lines.
 *  (2) The eight ABS32 pool sites (+01E8..+0204, dc0_tbl/dc1_tbl/ac0_tbl/
 *      ac1_tbl at 021C8500/8520/86C0/8600, base and +0x10) stay unresolved
 *      ("021C8500 ... has no witness outside 021C104C..021C1254"), so 6 of
 *      14 relocations resolve.  Dropping the ov172 token, and renaming the
 *      symbols to g_021C8500/func_021C8500, all fail identically (the name
 *      must stay whatever the C extern is called; the failure is the missing
 *      witness).  Cause: 021C8500 is inside ov172's image (range
 *      021B6100..021C88E0) but asm/overlays/ov172.s has no object START there
 *      (the 021C7C64..021C88E0 tail is a raw .word/.byte blob), so
 *      attest_sole_ref_overlay_data refuses.  That is a layout gap in the
 *      listing, not a source problem; the row cannot reach EXACT until the
 *      overlay listing is taught the table starts.
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
    u16 code = 0;
    u32 si;
    u32 kk;
    u32 jj;
    u32 ii;

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
    kk = 0;
    for (ii = 0; ii < 0x10; ii++) {
        for (jj = 0; jj < hf->mHuffBits[ii]; jj++)
            pWork->mHuffSize[kk++] = ii + 1;
        pWork->mHuffSize[kk] = 0;
    }

    MIi_CpuClearFast(0, pWork->mHuffCode, 0x400);
    kk = 0;
    si = pWork->mHuffSize[0];
    while (pWork->mHuffSize[kk] != 0) {
        while (pWork->mHuffSize[kk] == si) {
            pWork->mHuffCode[kk] = code;
            code = code + 1;
            kk++;
        }
        code = code << 1;
        si++;
    }

    for (kk = 0; kk < 0x100; kk++) {
        if (pWork->mHuffSize[kk] != 0) {
            hf->mEhufco[hf->mHuffValues[kk]] = pWork->mHuffCode[kk];
            hf->mEhufsi[hf->mHuffValues[kk]] = pWork->mHuffSize[kk];
        }
    }
}
