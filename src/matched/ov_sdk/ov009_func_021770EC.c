/*
 * function: DWC_SetRecvBuffer
 * address:  0x021770EC
 * packet:   pkt_ov009_021770EC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_SetRecvBuffer (libdwcmatch.TWL.HYB.a dwc_transport.o)
 * symbols:
 *   DWCs_GetTransConnection  0x02177770 arm
 *   DWCs_GetRecvState        0x021777A4 arm
 */

extern void *DWCs_GetTransConnection(unsigned char aid);
extern int DWCs_GetRecvState(unsigned char aid);

int DWC_SetRecvBuffer(unsigned char aid, void *recvBuffer, int size)
{
    char *connection = DWCs_GetTransConnection(aid);

    if (DWCs_GetRecvState(aid) == 2)
        return 0;
    *(void **)(connection + 4) = recvBuffer;
    *(int *)(connection + 8) = size;
    *(char *)(connection + 0x1d) = 1;
    *(int *)(connection + 0x10) = 0;
    *(int *)(connection + 0x18) = 0;
    return 1;
}
