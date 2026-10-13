/*
 * function: HAND_TOKUSEI_CureSickIfOwner
 * address: 0x021D96DC
 * packet: pkt_ov093_021D96DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   HAND_TOKUSEI_CureSick 0x021D96FC thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern void HAND_TOKUSEI_CureSick(void *a, int b, int c);
void HAND_TOKUSEI_CureSickIfOwner(int a,int b,int c) { if(b==BTL_EVENT_GetVar(2)) HAND_TOKUSEI_CureSick((void *)a,b,c); }
