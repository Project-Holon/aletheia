/*
 * unit: yes
 * function: BTL_HANDLER_TOKUSEI_HeavyMetalDoubleWeight,BTL_HANDLER_TOKUSEI_AddLightMetal
 * address: 0x021DCBE8
 * packet: pkt_ov093_021DCBE8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gHandlerTableLightMetal 0x021F05E0 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 */
extern unsigned char gHandlerTableLightMetal[];
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int,int);
void BTL_HANDLER_TOKUSEI_HeavyMetalDoubleWeight(int a, int b, int c) { if (c == BTL_EVENT_GetVar(2)) BTL_EVENT_MultiplyVar(53,8192); }
void *BTL_HANDLER_TOKUSEI_AddLightMetal(int *p) { *p = 1; return gHandlerTableLightMetal; }
