/*
 * function: DWCi_SendServerDownQuery
 * address:  0x02175458
 * packet:   pkt_ov009_02175458
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SendServerDownQuery (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   DWCi_NodeInfoList_GetCount  0x0217603C  arm  ov009
 *   DWCi_NodeInfoList_GetNodeInfoForIndex  0x0217637C  arm  ov009
 *   DWC_GetAIDBitmap  0x0216B908  arm  ov009
 *   DWCi_SendMatchCommand  0x0216FF2C  arm  ov009
 *   DWCi_HandleMatchCommandError  0x021719A4  arm  ov009
 *   DWCi_InitClWaitTimeout  0x02173CFC  arm  ov009
 */

extern int func_02175F3C(void);
extern int DWCi_NodeInfoList_GetCount(void);
extern char *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern int DWC_GetAIDBitmap(void);
extern int DWCi_SendMatchCommand(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
extern int DWCi_HandleMatchCommandError(int result);
extern void DWCi_InitClWaitTimeout(void);

int DWCi_SendServerDownQuery(void)
{
    int i;
    int result;
    int hostCount;
    unsigned long aidBitmap;
    char *pNodeInfo;
    unsigned char command;

    func_02175F3C();
    hostCount = DWCi_NodeInfoList_GetCount();
    for (i = 1; i < hostCount; i++) {
        pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
        aidBitmap = DWC_GetAIDBitmap();
        if (*(unsigned int *)(func_02175F3C() + 0x788) & (1 << *(unsigned char *)(pNodeInfo + 0x16)))
            command = 0x55;
        else
            command = 0x52;
        result = DWCi_SendMatchCommand(command, *(int *)pNodeInfo, *(int *)(pNodeInfo + 4), *(unsigned short *)(pNodeInfo + 12), (const unsigned int *)(&aidBitmap), 1);
        if (DWCi_HandleMatchCommandError(result))
            return 0;
    }
    DWCi_InitClWaitTimeout();
    return 1;
}
