/*
 * function: BTL_NET_SendRelayedParty
 * address: 0x021D4680
 * packet: pkt_ov093_021D4680
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlNet 0x021F3B88 data ov093 a4
 *   GFL_NET_SendData 0x0203D3F8 arm
 */
typedef unsigned int u32;
extern u32 *gBtlNet;
extern u32 GFL_NET_SendData(u32,u32,u32,u32,u32,u32,u32,u32);
u32 BTL_NET_SendRelayedParty(u32 *a) { return GFL_NET_SendData(*gBtlNet,255,0x104,(*a>>8)+4,(u32)a,0,1,1); }
