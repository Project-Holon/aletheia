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
 * symbols:
 *   func_021BFBC8 0x021BFBC8 thumb ov204
 */

extern void func_021BFBC8();
int func_021BFBA0(int *p)
{
    if (p[7] == 3) p[10]++; else p[10]--;
    func_021BFBC8();
    return p[10] == 60;
}
