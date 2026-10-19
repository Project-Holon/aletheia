/*
 * unit: yes
 * function: HAND_TOKUSEI_ThickFatHalveFireIce, HAND_TOKUSEI_GetHugePowerHandlers
 * address: 0x021D86FC
 * packet: pkt_ov093_021D86FC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gHugePowerHandlers 0x021F07C8 data ov093 a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 gHugePowerHandlers[];
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int,int);
void HAND_TOKUSEI_ThickFatHalveFireIce(int a,int b,int c) { u8 k; if (c==BTL_EVENT_GetVar(4)) { k=BTL_EVENT_GetVar(22); if (k==14 || k==9) BTL_EVENT_MultiplyVar(53,2048); } }
u8 *HAND_TOKUSEI_GetHugePowerHandlers(u32 *p) { *p=1; return gHugePowerHandlers; }
