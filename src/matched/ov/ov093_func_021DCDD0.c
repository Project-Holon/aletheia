/*
 * function: HAND_TOKUSEI_IllusionBreakOnHit
 * address: 0x021DCDD0
 * packet: pkt_ov093_021DCDD0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   HAND_TOKUSEI_IllusionBreak 0x021DCE48 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern void HAND_TOKUSEI_IllusionBreak(int,unsigned char *,int);
void HAND_TOKUSEI_IllusionBreakOnHit(int a,unsigned char *b,int c) { if(c==BTL_EVENT_GetVar(4) && BTL_EVENT_GetVar(70)==0) HAND_TOKUSEI_IllusionBreak(a,b,c); }
