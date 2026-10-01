/*
 * function: func_021CFBA4
 * address: 0x021CFBA4
 * packet: pkt_ov093_021CFBA4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * semantic: signed byte -1 has the original stored bits 0xff. The body
 *   only writes bytes and never reads through p. Six stores cover p10c..p111.
 */
typedef signed char s8;
typedef unsigned int u32;
void func_021CFBA4(s8 *p)
{
    u32 i = 0;
    s8 fill = -1;
    for (; i < 6; i++) p[0x10c+i] = fill;
}
