/*
 * function: HAND_TOKUSEI_SlowStartOnEnter
 * address: 0x021D8940
 * packet: pkt_ov093_021D8940
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   HAND_TOKUSEI_SlowStartBegin 0x021D8974 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern void HAND_TOKUSEI_SlowStartBegin(void *, int, int, int *);

void HAND_TOKUSEI_SlowStartOnEnter(void *a, int b, int c, int *d)
{
    if(c==BTL_EVENT_GetVar(2)) HAND_TOKUSEI_SlowStartBegin(a,b,c,d);
}
