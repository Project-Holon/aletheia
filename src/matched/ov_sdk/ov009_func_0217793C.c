/*
 * function: DWCs_HandleReliableMessage
 * address:  0x0217793C
 * packet:   pkt_ov009_0217793C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCs_HandleReliableMessage (libdwcmatch.TWL.HYB.a dwc_transport.o)
 * symbols:
 *   DWCi_GetConnectionAID   0x0216BB54 arm
 *   DWCi_SetError           0x02059F54 arm
 *   DWCs_GetRecvState       0x021777A4 arm
 *   DWCs_DecodeHeader       0x021771E0 arm
 *   DWCs_RecvDataHeader     0x02177C1C arm
 *   DWCs_RecvDataBody       0x02177CE4 arm
 *   DWCs_RecvSystemDataBody 0x02177DCC arm
 *   g_021AB180              0x021AB180 data
 */

extern unsigned char DWCi_GetConnectionAID(void *connection);
extern void DWCi_SetError(int error, int errorCode);
extern int DWCs_GetRecvState(unsigned char aid);
extern unsigned short DWCs_DecodeHeader(void *message);
extern void DWCs_RecvDataHeader(unsigned char aid, void *message, int size);
extern void DWCs_RecvDataBody(unsigned char aid, void *message, int size);
extern void DWCs_RecvSystemDataBody(unsigned char aid, void *message, int size);
extern char g_021AB180[];

#define sTransInfo (*(char **)g_021AB180)

void DWCs_HandleReliableMessage(void *connection, unsigned char *message, int size)
{
    unsigned short type;
    unsigned char aid;

    aid = DWCi_GetConnectionAID(connection);
    if (aid == 0xff) {
        DWCi_SetError(6, 0xfffe8298);
        return;
    }
    switch (DWCs_GetRecvState(aid)) {
    case 0:
        type = DWCs_DecodeHeader(message);
        if (type < 2 || type >= 5)
            return;
        DWCs_RecvDataHeader(aid, message, size);
        return;
    case 1:
        DWCs_RecvDataHeader(aid, message, size);
        return;
    case 2:
        DWCs_RecvDataBody(aid, message, size);
        return;
    case 3:
        DWCs_RecvSystemDataBody(aid, message, size);
        return;
    case 4:
        *(char *)(sTransInfo + aid * 0x38 + 0x1d) = 1;
        *(int *)(sTransInfo + aid * 0x38 + 0x10) = 0;
        *(int *)(sTransInfo + aid * 0x38 + 0x18) = 0;
        return;
    default:
        DWCi_SetError(6, 0xfffe82b6);
        return;
    }
}
