/*
 * unit: yes
 * function: HAND_TOKUSEI_Overcoat_BlockWeatherDamage,HAND_TOKUSEI_GetOvercoatHandlers
 * address: 0x021DC4A4
 * packet: pkt_ov093_021DC4A4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gOvercoatHandlers 0x021F05F8 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
extern unsigned char gOvercoatHandlers[];
extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int,unsigned int);
void HAND_TOKUSEI_Overcoat_BlockWeatherDamage(int a, int b, int c) { if (c == BTL_EVENT_GetVar(2) && BTL_EVENT_GetVar(50) > 0) BTL_EVENT_OverwriteVar(65,1); }
void *HAND_TOKUSEI_GetOvercoatHandlers(int *p) { *p = 1; return gOvercoatHandlers; }
