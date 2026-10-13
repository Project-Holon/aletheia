/*
 * function: DELIVERY_IRC_StepWaitInit
 * address: 0x02157DB8
 * packet: pkt_ov010_02157DB8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   DELIVERY_IRC_SetStepAtLine 0x02157960 thumb ov010
 *   DELIVERY_IRC_StepStartChangeover 0x02157D98 thumb ov010
 */
extern int GFL_NET_GetRunState(void);
extern void DELIVERY_IRC_SetStepAtLine(int, int, int);
extern void DELIVERY_IRC_StepStartChangeover(int);
void DELIVERY_IRC_StepWaitInit(int p)
{
    if (GFL_NET_GetRunState() == 1)
        DELIVERY_IRC_SetStepAtLine(p, (int)DELIVERY_IRC_StepStartChangeover, 0x1BE);
}
