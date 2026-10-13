/*
 * function: BTL_NET_FillRelayPacket
 * address: 0x021D4D64
 * packet: pkt_ov093_021D4D64
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void MI_CpuCopy8(const void *, void *, u32);
void BTL_NET_FillRelayPacket(u32 *p, const void *src, u32 a)
{
    *p = (*p & ~255u) | (u8)a;
    MI_CpuCopy8(src, p + 1, *p >> 8);
}
