/*
 * function: BTL_CLIENT_SumSlotFlagsBeforeCurrent
 * address: 0x021CF448
 * packet: pkt_ov093_021CF448
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;
u8 BTL_CLIENT_SumSlotFlagsBeforeCurrent(u8 *p)
{
    u32 i;
    u32 sum;
    u32 n;
    sum = 0;
    n = p[0x11d];
    i = 0;
    for (; i < n; i++) sum += p[0x130+i];
    return sum;
}
