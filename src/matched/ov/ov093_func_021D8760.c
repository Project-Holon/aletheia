/*
 * unit: yes
 * function: BTL_CALC_SwiftSwimDoubleSpeed, BTL_CALC_GetSwiftSwimHandlers
 * address: 0x021D8760
 * packet: pkt_ov093_021D8760
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gSwiftSwimHandlers 0x021F0740 data ov093 a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk 0x021C8288 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 gSwiftSwimHandlers[];
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int,int);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(u8 *p);
void BTL_CALC_SwiftSwimDoubleSpeed(int a,int b,int c) { if (c==BTL_EVENT_GetVar(2)) { if (BTL_SERVER_FLOW_GetEffectiveWeatherThunk((u8 *)b)==2) BTL_EVENT_MultiplyVar(53,8192); } }
u8 *BTL_CALC_GetSwiftSwimHandlers(u32 *p) { *p=1; return gSwiftSwimHandlers; }
