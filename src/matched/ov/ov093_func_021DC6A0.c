/*
 * function: HAND_TOKUSEI_Analytic_BoostPowerWhenMovingLast
 * address: 0x021DC6A0
 * packet: pkt_ov093_021DC6A0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021DC6DC 0x021DC6DC thumb ov093
 *   func_021E8624 0x021E8624 thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 */
typedef unsigned short u16;
extern int BTL_EVENT_GetVar(int);
extern int func_021DC6DC(u16);
extern int func_021E8624(int a, int b);
extern void BTL_EVENT_MultiplyVar(int,int);
void HAND_TOKUSEI_Analytic_BoostPowerWhenMovingLast(int a, void *b, int c) { if (c == BTL_EVENT_GetVar(3) && func_021DC6DC(BTL_EVENT_GetVar(18)) == 0 && func_021E8624((int)b,c) != 0) BTL_EVENT_MultiplyVar(49,0x14cd); }
