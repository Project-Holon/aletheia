/*
 * function: HAND_TOKUSEI_IllusionBreakOnOwnerEvent
 * address: 0x021DCDF8
 * packet: pkt_ov093_021DCDF8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   HAND_TOKUSEI_IllusionBreak 0x021DCE48 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern void HAND_TOKUSEI_IllusionBreak(int,unsigned char *,int);
void HAND_TOKUSEI_IllusionBreakOnOwnerEvent(int a,unsigned char *b,int c) { if(c==BTL_EVENT_GetVar(2)) HAND_TOKUSEI_IllusionBreak(a,b,c); }
