/*
 * unit: yes
 * function: HAND_TOKUSEI_ChlorophyllDoubleSpeed, HAND_TOKUSEI_GetChlorophyllHandlers
 * address: 0x021D8794
 * packet: pkt_ov093_021D8794
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gChlorophyllHandlers 0x021F05D8 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk 0x021C8288 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 gChlorophyllHandlers[];
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int,int);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(u8 *p);
void HAND_TOKUSEI_ChlorophyllDoubleSpeed(int a,int b,int c) { if (c==BTL_EVENT_GetVar(2)) { if (BTL_SERVER_FLOW_GetEffectiveWeatherThunk((u8 *)b)==1) BTL_EVENT_MultiplyVar(53,8192); } }
u8 *HAND_TOKUSEI_GetChlorophyllHandlers(u32 *p) { *p=1; return gChlorophyllHandlers; }
