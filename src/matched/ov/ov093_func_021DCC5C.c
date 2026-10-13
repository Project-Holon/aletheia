/*
 * function: HAND_TOKUSEI_UnnerveOnOwnerEnter
 * address: 0x021DCC5C
 * packet: pkt_ov093_021DCC5C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   HAND_TOKUSEI_UnnerveAnnounce 0x021DCC80 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern void HAND_TOKUSEI_UnnerveAnnounce(void *,void *,int,int *);
void HAND_TOKUSEI_UnnerveOnOwnerEnter(void *a,void *b,int c,int *d) { if(c==BTL_EVENT_GetVar(2)) HAND_TOKUSEI_UnnerveAnnounce(a,b,c,d); }
