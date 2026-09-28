/*
 * function: DWCs_RecvSystemDataBody
 * address:  0x02177DCC
 * packet:   pkt_ov009_02177DCC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCs_RecvSystemDataBody (libdwcmatch.TWL.HYB.a dwc_transport.o)
 * symbols:
 *   DWCs_GetTransConnection     0x02177770 arm
 *   DWC_Alloc                   0x0205A16C arm
 *   DWCi_SetError               0x02059F54 arm
 *   MI_CpuCopy8                 0x02082D44 arm
 *   DWCi_ProcessMatchSynPacket  0x0216EC4C arm
 *   DWC_Free                    0x0205A1B0 arm
 */

extern void *DWCs_GetTransConnection(unsigned char aid);
extern void *DWC_Alloc(int name, unsigned long size);
extern void DWCi_SetError(int error, int errorCode);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void DWCi_ProcessMatchSynPacket(unsigned char aid, unsigned short type, unsigned char *data);
extern void DWC_Free(int name, void *ptr, int flag);

void DWCs_RecvSystemDataBody(unsigned char aid, void *message, int size)
{
    unsigned char *transConnection;
    void *alignedMessage;

    transConnection = DWCs_GetTransConnection(aid);
    transConnection[0x1d] = transConnection[0x1e];
    switch (*(unsigned short *)(transConnection + 0x22)) {
    case 2:
    case 3:
    case 4:
        alignedMessage = DWC_Alloc(4, size);
        if (alignedMessage == 0) {
            DWCi_SetError(9, 0xfffe8517);
            return;
        }
        MI_CpuCopy8(message, alignedMessage, size);
        DWCi_ProcessMatchSynPacket(aid, *(unsigned short *)(transConnection + 0x22),
            alignedMessage);
        DWC_Free(4, alignedMessage, 0);
        break;
    }
}
