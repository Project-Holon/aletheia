/*
 * unit: yes
 * function: HAND_TOKUSEI_SandRush_DoubleSpeedInSand,HAND_TOKUSEI_GetWonderSkinHandlers
 * address: 0x021DC630
 * packet: pkt_ov093_021DC630
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gWonderSkinHandlers 0x021F06D0 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk 0x021C8288 thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 */
extern unsigned char gWonderSkinHandlers[];
extern int BTL_EVENT_GetVar(int);
typedef unsigned char  u8;
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(u8 *p);
extern void BTL_EVENT_MultiplyVar(int,int);
void HAND_TOKUSEI_SandRush_DoubleSpeedInSand(int a, void *b, int c) { if (c == BTL_EVENT_GetVar(2) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(b) == 4) BTL_EVENT_MultiplyVar(53,8192); }
void *HAND_TOKUSEI_GetWonderSkinHandlers(int *p) { *p = 1; return gWonderSkinHandlers; }
