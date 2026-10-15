/*
 * function: DWCs_Send
 * address:  0x021777C0
 * packet:   pkt_ov009_021777C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCs_Send (libdwcmatch.TWL.HYB.a dwc_transport.o)
 *
 * symbols:
 *   DWCi_GetGT2Connection  0x0216BAF4  arm  ov009
 *   DWCi_ProcessReliableQueue  0x02176C00  arm  ov009
 *   gt2Send        0x02195CC0  arm  ov009
 *   DWCi_InsertReliableQueue  0x02176CF8  arm  ov009
 *   DWCi_SetError  0x02059F54  arm
 */

extern int DWCi_GetGT2Connection(int aid);
extern int DWCi_ProcessReliableQueue(void);
extern int gt2Send(void *connection, unsigned char *buffer, int size, int reliable);
extern int DWCi_InsertReliableQueue(void *connection, unsigned char *buffer, int size);
extern void DWCi_SetError(int kind, int code);

void DWCs_Send(unsigned char aid, unsigned char *buffer, int size, int reliable)
{
    void *connection;
    int res;

    connection = (void *)DWCi_GetGT2Connection(aid);
    if (reliable != 0) {
        if (DWCi_ProcessReliableQueue() != 0) {
            res = gt2Send(connection, buffer, size, reliable);
            if (res == 0)
                return;
        }
        if (DWCi_InsertReliableQueue(connection, buffer, size) != 0)
            return;
        DWCi_SetError(6, -0x17D5E);
        return;
    }
    gt2Send(connection, buffer, size, reliable);
}
