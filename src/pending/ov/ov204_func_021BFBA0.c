/*
 * function: func_021BFBA0
 * address: 0x021BFBA0
 * packet: pkt_ov204_021BFBA0
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-04: DIFF, 6 bytes: temps for [0x1c]/[0x28] sit in r0, original uses r1 (r0 stays = p for
 *   the bl, no mov r0,r4). Unprototyped call () removes the mov but not the colour. Prototyped f(p),
 *   struct fields, n/k locals, if/else vs ternary all give the mov plus r0 temps (25 diff bytes).
 *   2026-10-04 (D2): callee 0x021BFBC8 takes (p, value) in r0/r1 (r1 = new p[10] is live into the call), so the
 *   original is f(p, v) with v and the p[7] test both in r1 and r0 never clobbered. Prototyped f(p,v) variants
 *   (v local, p[10] reload, q=p alias, raw char* offsets, v reused for p[7]) all load p[7] into r0 and emit
 *   adds r0,r4,#0 before the bl (24 bytes differ). Unprototyped form kept: 6 bytes differ.
 * symbols:
 *   func_021BFBC8 0x021BFBC8 thumb ov204
 *
 * note 2026-10-05 (wD4 lane13): tried f(p, p[10]) and f(p, b) with b a local holding the new p[10] (24 bytes differ: p[7] load goes to r0 and adds r0,r4,#0 appears before the bl), f(p) with int/struct views and a/b locals (25-27 bytes). The unprototyped form stays the closest (6 bytes). Original keeps p live in r0 across the temporaries (they use r1), not reproduced.
 */

extern void func_021BFBC8();
int func_021BFBA0(int *p)
{
    if (p[7] == 3) p[10]++; else p[10]--;
    func_021BFBC8();
    return p[10] == 60;
}
