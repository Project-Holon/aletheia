/*
 * function: BTL_CLIENT_HasSlotInOrder
 * address: 0x021CFBBC
 * packet: pkt_ov093_021CFBBC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef signed char s8;
typedef unsigned int u32;
int BTL_CLIENT_HasSlotInOrder(s8 *p, int v)
{
    u32 i = 0;
    for (; i < 6; i++) {
        if ((p+i)[0x10c] == v) return 1;
    }
    return 0;
}
