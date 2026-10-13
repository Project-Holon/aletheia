/*
 * function: DELIVERY_IRC_StepStartChangeover
 * address: 0x02157D98
 * packet: pkt_ov010_02157D98
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_StartChangeoverChild 0x0203D0DC arm
 *   DELIVERY_IRC_SetStepAtLine 0x02157960 thumb ov010
 *   DELIVERY_IRC_StepWaitConnect 0x02157D68 thumb ov010
 */
extern int GFL_NET_StartChangeoverChild(int a0);
extern void DELIVERY_IRC_SetStepAtLine(int, int, int);
extern void DELIVERY_IRC_StepWaitConnect(int *p);
void DELIVERY_IRC_StepStartChangeover(int p)
{
    GFL_NET_StartChangeoverChild(0);
    DELIVERY_IRC_SetStepAtLine(p, (int)DELIVERY_IRC_StepWaitConnect, 0x1B7);
}
