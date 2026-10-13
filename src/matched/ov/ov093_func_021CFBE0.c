/*
 * function: BTL_CLIENT_SetSlotOrder
 * address: 0x021CFBE0
 * packet: pkt_ov093_021CFBE0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef unsigned int u32;
void BTL_CLIENT_SetSlotOrder(u8 *p, u32 i, u32 v)
{
    if (i < 6) (p + i)[0x10c] = v;
}
