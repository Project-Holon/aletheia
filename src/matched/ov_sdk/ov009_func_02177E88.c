/*
 * function: DWCs_UpdateConnectionKeepAliveTime
 * address:  0x02177E88
 * packet:   pkt_ov009_02177E88
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCs_UpdateConnectionKeepAliveTime (libdwcmatch.TWL.HYB.a dwc_transport.o)
 * symbols:
 *   DWCi_GetConnectionAID    0x0216BB54 arm
 *   DWC_GetMyAID             0x0216B838 arm
 *   OS_GetTick               0x020870D0 arm
 *   DWCs_GetTransConnection  0x02177770 arm
 */

extern unsigned char DWCi_GetConnectionAID(void *connection);
extern unsigned char DWC_GetMyAID(void);
extern unsigned long long OS_GetTick(void);
extern char *DWCs_GetTransConnection(unsigned char aid);

void DWCs_UpdateConnectionKeepAliveTime(void *connection)
{
    unsigned char aid = DWCi_GetConnectionAID(connection);
    unsigned long long tick;

    if (aid >= 0x20)
        return;
    if (aid == DWC_GetMyAID())
        return;
    tick = OS_GetTick();
    *(unsigned long long *)(DWCs_GetTransConnection(aid) + 0x30) = tick;
}
