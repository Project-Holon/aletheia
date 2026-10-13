/*
 * function: BTL_NET_SendPlayerInfo
 * address: 0x021D4808
 * packet: pkt_ov093_021D4808
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlNet 0x021F3B88 data ov093 a4
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   GFL_NET_SendData 0x0203D3F8 arm
 */
typedef unsigned int u32;
extern u32 *gBtlNet;
extern int MYSTATUS_GetSize(void);
extern u32 GFL_NET_SendData(u32, u32, u32, u32, u32, u32, u32, u32);
int BTL_NET_SendPlayerInfo(u32 a)
{
    u32 r = MYSTATUS_GetSize();
    return GFL_NET_SendData(*gBtlNet, 255, 0x105, r, a, 0, 1, 1);
}
