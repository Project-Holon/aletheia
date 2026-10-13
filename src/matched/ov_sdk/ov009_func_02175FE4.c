/*
 * function: DWCi_ResetLastSomeDataRecvTimeByAidAll
 * address:  0x02175FE4
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_ResetLastSomeDataRecvTimeByAidAll: restamps every node's transport record.
 *
 * symbols:
 *   DWCi_NodeInfoList_GetCount  0x0217603C  arm  ov009
 *   DWCi_NodeInfoList_GetNodeInfoForIndex  0x0217637C  arm  ov009
 *   func_02177748  0x02177748  arm  ov009
 */

extern int DWCi_NodeInfoList_GetCount(void);
extern unsigned char *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern void func_02177748(int aid);

void DWCi_ResetLastSomeDataRecvTimeByAidAll(void)
{
    int i;

    for (i = 0; i < DWCi_NodeInfoList_GetCount(); i++) {
        func_02177748(DWCi_NodeInfoList_GetNodeInfoForIndex(i)[0x16]);
    }
}
