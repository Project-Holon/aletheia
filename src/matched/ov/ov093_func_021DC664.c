/*
 * unit: yes
 * function: HAND_TOKUSEI_WonderSkin_CapStatusMoveAccuracy,HAND_TOKUSEI_GetAnalyticHandlers
 * address: 0x021DC664
 * packet: pkt_ov093_021DC664
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gAnalyticHandlers 0x021F0628 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
extern unsigned char gAnalyticHandlers[];
extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int,unsigned int);
void HAND_TOKUSEI_WonderSkin_CapStatusMoveAccuracy(int a, int b, int c) { if (c == BTL_EVENT_GetVar(4) && BTL_EVENT_GetVar(26) == 0 && (unsigned int)BTL_EVENT_GetVar(43) > 50) BTL_EVENT_OverwriteVar(43,50); }
void *HAND_TOKUSEI_GetAnalyticHandlers(int *p) { *p = 1; return gAnalyticHandlers; }
