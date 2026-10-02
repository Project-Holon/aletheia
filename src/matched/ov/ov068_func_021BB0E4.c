/*
 * function: func_021BB0E4
 * address: 0x021BB0E4
 * packet: pkt_ov068_021BB0E4
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203EFC8 0x0203EFC8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_0203EFC8(const u8 *, const u8 *, u32);
int func_021BB0E4(const u8 *p, const u8 *q)
{
    if (func_0203EFC8(p, q, 5) == 0) return 1;
    return 0;
}
