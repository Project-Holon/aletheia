/*
 * function: HAND_TOKUSEI_SlowStartHalveSpeed
 * address: 0x021D88E8
 * packet: pkt_ov093_021D88E8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int,int);

void HAND_TOKUSEI_SlowStartHalveSpeed(int a, int b, int c, int *d)
{
    int k=2; if(c==BTL_EVENT_GetVar(k) && d[3]!=0) BTL_EVENT_MultiplyVar(0x35,k<<10);
}
