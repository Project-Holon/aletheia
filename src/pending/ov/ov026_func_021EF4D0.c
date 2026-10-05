/*
 * function: func_021EF4D0
 * address: 0x021EF4D0
 * packet: pkt_ov026_021EF4D0
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-04: DIFF, 190 bytes vs 188. Semantics settled: c is an s16[6] record (pos x,y at 0,1;
 *   velocity pair at 2,3; last delta pair at 4,5); q+0x16/+0x18 are s16 deltas; pt = pos/8; off-screen
 *   (x >= 0x100 or y >= 0xC0) calls func_021A21E0 else func_021A26C4. Residue: original pushes r7 and keeps
 *   the index constant 2 in r7 (ldrsh [c,r7]), frame is push {r3-r7,lr} with no sub sp; ours uses five regs
 *   plus sub sp,#4, loads c[0] before c[2], and hoists 0x18. Tried: s16 array vs struct C, int dx/dy (worse, 182 B).
 * 2026-10-05 (D4-18): still DIFF 190 vs 188. Tried: int k = 2 local with c[1] read as *(s16 *)((char *)c + k); c[0] = c[0] + (dx = ...) as one expression; int x0 = c[0] read before dx; += forms; dy computed before the c[0] store (worse, 84 vs 90 bytes only by shape). Compiler output unchanged by the first three. Residue: original frame is push {r3-r7,lr} with pt in the r3 slot, dx in r3 and the constant 2 in r7; ours uses five regs plus sub sp,#4 and loads c[0] after dx.
 *
 * 2026-10-05 (wD5 lane20): re-read the listing: the original loads c[2] then c[0] BEFORE the add that builds dx (ldrsh c2; ldrsh c0; adds), and c[3], b[0x18], c[1] before the dy add, so dx stays live in r3 while c[1] is loaded and the index constant 2 spills to r7 (frame push r3-r7, no sub sp). Tried: s16 x0/y0 locals read after dx and before the store (same 90 bytes), c[0] += (dx = ...) compound form (same). Ours loads c[0]/c[1] after the dx/dy add. No change; the load hoisting above the sign extension is not reproduced.
 * 2026-10-05 (wD6 lane17): still DIFF 190 vs 188. Checked callee prototypes against the matched siblings
 *   021EF2D8/021EF3E0 (same three callees, s16 *b, s16 v[2]): sibling style gives the same 90 bytes. Also tried
 *   an inline step(pos, vel, d) helper, x/vx/dx locals read in listing order, *c for c[0], if/else swapped (worse),
 *   int x = (s16)(...), `c[0] + (x = ...)` forms. Finding: with the sum written inline and NOT kept
 *   (`c[0] = c[0] + (s16)(c[2] + b[11]); ... c[4] = c[2] + b[11];`) the head gets the original order
 *   (ldrsh c2; ldrsh c0; add; push r3-r7, no sub sp), but c[4]/c[5] then reload b[11]/b[12] (198 B) and
 *   the constant 0 goes to r7 instead of 2. The original keeps the sum live (r3) with that inline-temp schedule.
 * symbols:
 *   func_021A2640 0x021A2640 thumb ov021
 *   func_021A21E0 0x021A21E0 thumb ov021
 *   func_021A26C4 0x021A26C4 thumb ov021
 */
typedef short s16;
struct PtS {
    s16 x;
    s16 y;
};
extern void func_021A2640(void *a, struct PtS *pt);
extern void func_021A21E0(void *a);
extern void func_021A26C4(void *a, struct PtS *pt);
void func_021EF4D0(void *a, char *b, s16 *c)
{
    struct PtS pt;
    func_021A2640(a, &pt);
    if (*(s16 *)(b + 0x16) != 0) {
        s16 dx = c[2] + *(s16 *)(b + 0x16);
        s16 dy;
        c[0] = c[0] + dx;
        dy = c[3] + *(s16 *)(b + 0x18);
        c[1] = c[1] + dy;
        pt.x = c[0] / 8;
        pt.y = c[1] / 8;
        c[4] = dx;
        c[5] = dy;
    } else {
        c[0] = c[0] + c[4];
        c[1] = c[1] + c[5];
        pt.x = c[0] / 8;
        pt.y = c[1] / 8;
    }
    if (pt.x >= 0x100 || pt.y >= 0xc0) {
        func_021A21E0(a);
    } else {
        func_021A26C4(a, &pt);
    }
}
