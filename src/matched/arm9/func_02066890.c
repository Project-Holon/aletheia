/*
 * unit:     no
 * function: func_02066890
 * address:  0x02066890
 * packet:   pkt_02066890
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_G2dSrtcInitTable   0x020640B0  arm
 *   NNSi_G2dSrtcSetTable   0x020640CC  arm
 *   sCellTransferStateManager      0x02148B20  data
 *
 * Initialise cell `idx` of the bank at 0x02148B20: clear it with
 * NNSi_G2dSrtcInitTable, set each of the three channels whose argument is not the
 * -1 sentinel through NNSi_G2dSrtcSetTable(rec, 0/1/2, v), then store the four
 * stacked words at +0x0c..+0x18.
 *
 * FRONT END: a `../2.0/sp2` PIN row, the "kept constants" tell in its
 * sentinel form -- the same pin src/matched/func_02066AE0.c takes in this
 * cluster and docs/notes/pkt_02066E30.c.txt records for 0x0206775C.  The
 * image materialises `mvn r0, #0` FRESH before each of the three guards and
 * compares register-to-register (0x020668B8, 0x020668D4, 0x020668F0).
 * dsi/1.1p1 -O4,p folds that: it emits `cmn rN, #1` for guards 2 and 3 and
 * even CSEs the first -1 off the 0x30 stride it already holds
 * (`sub r0, r4, #0x31`), giving 156 bytes against the image's 164.  Ten
 * sentinel spellings were measured under 1.1p1 and every one folds the same
 * way -- `0xffffffffu`, `~0u`, `(u32)(0 - 1)`, `-1` on signed parameters,
 * `(s32)0xffffffff`, `~v != 0`, a plain `u32 s = ~0u` per guard, a shared
 * one, and a `volatile u32 s` (196 bytes, worse) -- and a full permuter hill
 * (142 singles, --types) reaches 164 bytes only through junk type mutations
 * at 87 concrete out.  2.0/sp2 keeps all three rematerialisations and is
 * byte-exact.  The previous DIFF body in docs/notes/pkt_02066890.c.txt is
 * superseded by this file; its residue diagnosis was right, the fix was the
 * front end.
 *
 * THE 0x30 STRIDE is one `mla`, not a shift and an add: 0x30 is not a power
 * of two, so `mov r4, #0x30` / `mla r4, idx, r4, base` is the whole address
 * computation, and it is the inlined form of the cluster's out-of-line
 * accessor NNSi_G2dGetCellTransferState (0x02066878).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02066890.c \
 *       --func func_02066890 --addr 0x02066890 --cc ../2.0/sp2 --arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Rec02066890 {
    u8  pad_00[0xc];
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u8  pad_1c[0x14];
};

struct Bank02066890 {
    u32                 unk_00;
    u32                 unk_04;
    struct Rec02066890 *recs;
};

extern struct Bank02066890 sCellTransferStateManager;
extern void NNSi_G2dSrtcInitTable(signed int *tbl);
typedef signed int     s32;
extern void NNSi_G2dSrtcSetTable(s32 *tbl, u32 i, u32 v);

void func_02066890(u32 idx, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    struct Rec02066890 *rec = &sCellTransferStateManager.recs[idx];

    NNSi_G2dSrtcInitTable((int *)rec);

    if (a != 0xffffffffu) {
        NNSi_G2dSrtcSetTable((s32 *)rec, 0, a);
    }
    if (b != 0xffffffffu) {
        NNSi_G2dSrtcSetTable((s32 *)rec, 1, b);
    }
    if (c != 0xffffffffu) {
        NNSi_G2dSrtcSetTable((s32 *)rec, 2, c);
    }

    rec->unk_0c = d;
    rec->unk_10 = e;
    rec->unk_14 = f;
    rec->unk_18 = g;
}
