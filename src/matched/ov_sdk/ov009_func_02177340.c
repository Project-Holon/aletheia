/*
 * function: DWCi_RecvCallback
 * address:  0x02177340
 * packet:   pkt_ov009_02177340
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RecvCallback (libdwcmatch.TWL.HYB.a dwc_transport.o)
 * symbols:
 *   DWCs_UpdateConnectionKeepAliveTime  0x02177E88 arm
 *   DWCs_HandleReliableMessage          0x0217793C arm
 *   DWCs_HandleUnreliableMessage        0x02177A4C arm
 *   gDwcTransInfo                          0x021AB180 data
 */

extern char gDwcTransInfo[];
extern void DWCs_UpdateConnectionKeepAliveTime(void *connection);
extern void DWCs_HandleReliableMessage(void *connection, unsigned char *message, int size);
extern void DWCs_HandleUnreliableMessage(void *connection, void *message, int size);

void DWCi_RecvCallback(void *connection, unsigned char *message, int size, int reliable)
{
    if (*(char **)gDwcTransInfo == 0 || message == 0 || size == 0)
        return;
    DWCs_UpdateConnectionKeepAliveTime(connection);
    if (reliable)
        DWCs_HandleReliableMessage(connection, message, size);
    else
        DWCs_HandleUnreliableMessage(connection, message, size);
}
