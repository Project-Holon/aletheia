/*
 * function: DWCi_SendTypeMatchAck
 * address:  0x021735A4
 * packet:   pkt_ov009_021735A4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SendTypeMatchAck (dwc_match.o)
 *
 * symbols:
 *   func_02175FB8  0x02175FB8  arm  ov009
 *   DWCi_NodeInfoList_GetCount  0x0217603C  arm  ov009
 *   DWCi_NodeInfoList_GetNodeInfoForIndex  0x0217637C  arm  ov009
 *   func_02173064  0x02173064  arm  ov009
 *   DWCi_TempNewNodeInfo_IsValid  0x02176554  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   DWCi_SetMatchStatus  0x02175F4C  arm  ov009
 */

extern unsigned char func_02175FB8(void);
extern int DWCi_NodeInfoList_GetCount(void);
extern char *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern void func_02173064(int aid, int type);
extern int DWCi_TempNewNodeInfo_IsValid(void);
extern int func_02175F3C(void);
extern void DWCi_SetMatchStatus(int status);

void DWCi_SendTypeMatchAck(void)
{
    int i;

    if (func_02175FB8() != 2)
        return;
    for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++)
        func_02173064(*(unsigned char *)(DWCi_NodeInfoList_GetNodeInfoForIndex(i) + 0x16), 4);
    if (DWCi_TempNewNodeInfo_IsValid())
        func_02173064(*(unsigned char *)(func_02175F3C() + 0x56a), 4);
    DWCi_SetMatchStatus(20);
}
