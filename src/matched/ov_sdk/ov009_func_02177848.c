/*
 * function: DWCi_SendUnreliable
 * address:  0x02177848
 * packet:   pkt_ov009_02177848
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SendUnreliable (libdwcmatch.TWL.HYB.a dwc_transport.o)
 * symbols:
 *   DWCi_GetGT2Connection                  0x0216BAF4 arm
 *   DWC_IsServerMyself                     0x0216BA08 arm
 *   DWCi_NodeInfoList_GetNodeInfoForIndex  0x0217637C arm
 *   DWC_Alloc                              0x0205A16C arm
 *   strncpy                                0x02094860 arm
 *   MI_CpuCopy8                            0x02082D44 arm
 *   gt2Send                                0x02195CC0 arm
 *   DWC_Free                               0x0205A1B0 arm
 *   g_021A2348                             0x021A2348 data
 */

extern void *DWCi_GetGT2Connection(unsigned char aid);
extern int DWC_IsServerMyself(void);
extern char *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern void *DWC_Alloc(int name, unsigned long size);
extern void strncpy(char *dst, const char *src, int n);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern int gt2Send(void *connection, unsigned char *message, int len, int reliable);
extern void DWC_Free(int name, void *ptr, int flag);
extern char g_021A2348[];

void DWCi_SendUnreliable(unsigned char aidFrom, unsigned char aidTo, unsigned char *buffer,
    int size, int fromDWC_SendUnreliable)
{
    void *connection;
    int bNeedFoward = 0;
    unsigned char *sendBuf;

    connection = DWCi_GetGT2Connection(aidTo);
    if (connection == 0) {
        if (DWC_IsServerMyself())
            return;
        connection = DWCi_GetGT2Connection(
            *(unsigned char *)(DWCi_NodeInfoList_GetNodeInfoForIndex(0) + 0x16));
        if (connection == 0)
            return;
        bNeedFoward = 1;
    }
    if (fromDWC_SendUnreliable == 1 && bNeedFoward == 1) {
        sendBuf = DWC_Alloc(4, size + 8);
        if (sendBuf == 0)
            return;
        strncpy((char *)sendBuf, g_021A2348, 3);
        sendBuf[3] = aidFrom;
        *(unsigned long *)(sendBuf + 4) = 1 << aidTo;
        MI_CpuCopy8(buffer, sendBuf + 8, size);
        gt2Send(connection, sendBuf, size + 8, 0);
        if (sendBuf == 0)
            return;
        DWC_Free(4, sendBuf, 0);
    } else {
        gt2Send(connection, buffer, size, 0);
    }
}
