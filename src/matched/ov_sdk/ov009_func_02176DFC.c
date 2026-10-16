/*
 * function: DWCi_IsSendableReliable
 * address:  0x02176DFC
 * packet:   pkt_ov009_02176DFC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_IsSendableReliable (libdwcmatch.TWL.HYB.a dwc_transport.o)
 *
 * symbols:
 *   DWCi_IsError          0x02059F38  arm
 *   DWC_IsValidAID         0x0216B94C  arm  ov009
 *   DWCi_IsValidAID        0x0216BC3C  arm  ov009
 *   DWCs_GetSendState          0x02177788  arm  ov009
 *   DWCs_GetOutgoingBufferFreeSize  0x02177E64  arm  ov009
 *   DWCs_GetRequiredHeaderSize      0x0217721C  arm  ov009
 *   DWCi_IsReliableQueueFree          0x02176BE4  arm  ov009
 */

extern int DWCi_IsError(void);
extern int DWC_IsValidAID(int aid);
extern int DWCi_IsValidAID(int aid);
extern unsigned char DWCs_GetSendState(int i);
extern int DWCs_GetOutgoingBufferFreeSize(int aid);
extern int DWCs_GetRequiredHeaderSize(int type);
extern int DWCi_IsReliableQueueFree(void);

static int DWCi_IsSendableReliable(int aid, int type)
{
    long freeSpace;

    if (DWCi_IsError() != 0 || (type == 1 && DWC_IsValidAID(aid) == 0))
        return 0;
    if (DWCi_IsValidAID(aid) == 0)
        return 0;
    if (DWCs_GetSendState(aid) == 1)
        return 0;
    freeSpace = DWCs_GetOutgoingBufferFreeSize(aid);
    if (freeSpace < DWCs_GetRequiredHeaderSize(type))
        return 0;
    return DWCi_IsReliableQueueFree() != 0;
}
