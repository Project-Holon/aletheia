/*
 * function: func_021EF920
 * address: 0x021EF920
 * packet: pkt_ov026_021EF920
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021A25DC 0x021A25DC thumb ov021
 */

typedef unsigned char u8;
typedef short s16;
extern void func_021A25DC(u8 *, int);
void func_021EF920(u8 *a, s16 *p, int b, int c)
{
    if (b != 0 && p[6] == p[7] - 24)
        func_021A25DC(a, c);
}
