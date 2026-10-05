/*
 * function: func_0218532C
 * address:  0x0218532C
 * packet:   pkt_ov219_0218532C
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-05 (wD9 lane12): EXACT. The wrap value was a ternary local t merged at a join and stored
 *   to ylo and yhi after it. Writing the stores in each arm (`if (lo2 > 0) yhi = ylo = lo2 - 0x10000;
 *   else yhi = ylo = lo2 + 0x10000;`) gives lo2 r6 and spills yhi, as in the image (tail merging
 *   rebuilds the shared two-store join). See docs/idioms/two-long-lived-values-in-each-others-registers.md.
 * 2026-10-05 (wD8 lane10): still DIFF 91 bytes. Re-read the listing: semantics match (ylo [sp,#0x10], yhi
 *   [sp,#0xc], hi2 [sp,#8], lo2 r6; wrap order lo2-=, hi2+=, ylo-=, yhi+=). No new test closed the r6 swap.
 * 2026-10-05 (wD7 lane14): still DIFF 91 bytes. Re-derived the middle part: no logic error found. Tried: ylo = ternary; yhi = ylo
 *   (no t local, same 91); ylo/yhi as a two-element local array (mwcc scalarises it, 98).
 * 2026-10-05 (wD6 lane16): still DIFF 91 bytes. Tried: else arm as lo2 = ylo; hi2 = yhi (order swap) and the abs test
 *   as a ternary inside the if: no change. Callee 02185D08 reads only r0 (no missing argument).
 * 2026-10-05 (wD5 lane05): DIFF 91 bytes (was 163). Fixes: no e record pointer local (each
 *   field read as *(T *)(p + i * 0x30 + K), loop colours now exact); no cx/cy locals; every use reads
 *   *(int *)(p + 0xC2F4/0xC2F8) directly (CSE gives the original load order; prologue now exact up to
 *   +0x3A). Residue: yhi takes r6 and lo2 is spilled to [sp,#0xc]; the original has lo2 in r6 and yhi
 *   in [sp,#0xc] (a pure swap of the two, all else follows). No change from: lo2 assigned directly
 *   (no y16 temp), declaring lo2 last or before yhi, `yhi = ylo = t`, the ternary as an if/else on
 *   ylo, a struct Ent array for the 0x30 records (worse, hoists p+0x18). lo2/hi2 set before the if
 *   (no else) does give lo2 r6 but loses the else block (257).
 * 2026-10-05 (wD4 lane19): still DIFF 163 bytes. Tried the constant in a local (int off = 0xC2F4; p[off], p[off+4], and for the reload): mwcc folds it, no change.
 * 2026-10-04 (wD2 lane 09): 284 vs 288 bytes, 163 bytes differ, same frame.
 * Semantics read from the listing (x,y at +0xC2F4/+0xC2F8, count at +0x14,
 * 0x30-byte records, s16 fields +0x18/+0x1a, u16 flag +0x40). Residue: the
 * original keeps only lo2 (r6) in a register and spills ylo/yhi/hi2; ours puts
 * yhi in r6, so the wrap test and the range test swap order, and the loop
 * colours ex/ey/e as r1/r2/r0 instead of r0/r1/r2. Tried: lo2/hi2 set through
 * y16 before the temp (89->163 bytes better than the first draft), declaring
 * lo2/hi2 first (169, worse). Not tried: wrap test through different locals.
 *
 * symbols:
 *   func_02185D08  0x02185D08  thumb  ov219
 *   func_02185D64  0x02185D64  thumb  ov219
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern void func_02185D08(int *p);
extern u32 func_02185D64(int *p, int *q);

int func_0218532C(char *p, u32 *out)
{
    int ret = 0;
    int xlo, xhi, ylo, yhi, lo2, hi2;
    u32 i;
    u32 best;
    u32 bestd;
    int cur[2];

    xlo = (s16)(*(int *)(p + 0xC2F4) - 0x80);
    xhi = (s16)(*(int *)(p + 0xC2F4) + 0x80);
    ylo = (s16)(*(int *)(p + 0xC2F8) - 0x80);
    yhi = (s16)(*(int *)(p + 0xC2F8) + 0x80);
    best = *(u32 *)(p + 0x14);
    bestd = 0x100;
    cur[0] = *(int *)(p + 0xC2F4);
    cur[1] = *(int *)(p + 0xC2F8);
    func_02185D08(cur);
    {
        int d = yhi - ylo;
        if (d < 0) d = -d;
        if (d > 0x100) {
            lo2 = (s16)*(int *)(p + 0xC2F8);
            hi2 = lo2;
            if (lo2 > 0)
                yhi = ylo = lo2 - 0x10000;
            else
                yhi = ylo = lo2 + 0x10000;
            lo2 -= 0x80;
            hi2 += 0x80;
            ylo -= 0x80;
            yhi += 0x80;
        } else {
            hi2 = yhi;
            lo2 = ylo;
        }
    }
    for (i = 0; i < *(u32 *)(p + 0x14); i++) {
        int ex = *(s16 *)(p + i * 0x30 + 0x18);
        if (ex > xlo && ex < xhi) {
            int ey = *(s16 *)(p + i * 0x30 + 0x1a);
            if ((ey > ylo && ey < yhi) || (ey > lo2 && ey < hi2)) {
                if (*(u16 *)(p + i * 0x30 + 0x40) != 0) {
                    int pt[2];
                    u32 dd;
                    pt[0] = ex;
                    pt[1] = *(s16 *)(p + i * 0x30 + 0x1a);
                    func_02185D08(pt);
                    dd = func_02185D64(cur, pt);
                    if (dd < bestd) {
                        bestd = dd;
                        best = i;
                    }
                }
            }
        }
    }
    *out = best;
    if (best != *(u32 *)(p + 0x14))
        ret = 1;
    return ret;
}
