/*
 * function: BTL_NET_SendParty
 * address: 0x021D4438
 * packet: pkt_ov093_021D4438
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlNet 0x021F3B88 data ov093 a4
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   GFL_NET_SendData 0x0203D3F8 arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern u32 *gBtlNet;
extern int POKE_REGULATION_GetDataSize(void);
extern u32 GFL_NET_SendData(u32,u32,u32,u32,u32,u32,u32,u32);
u8 BTL_NET_SendParty(u32 a) { u32 r; r=POKE_REGULATION_GetDataSize(); return GFL_NET_SendData(*gBtlNet,255,0x102,r,a,0,1,1); }
