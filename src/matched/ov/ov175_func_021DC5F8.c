/*
 * function: func_021DC5F8
 * address: 0x021DC5F8
 * packet: pkt_ov175_021DC5F8
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 */
typedef unsigned int u32;
u32 func_021DC5F8(char *p, int a, int kind)
{
    if (kind == 3 || kind == 6) return *(u32 *)(p + 0x1458);
    return 0;
}
