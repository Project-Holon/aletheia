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
 *   DWCi_ResetLastSomeDataRecvTimeByAid  0x02177748  arm  ov009
 */

extern int DWCi_NodeInfoList_GetCount(void);
extern unsigned char *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern void DWCi_ResetLastSomeDataRecvTimeByAid(int aid);

void DWCi_ResetLastSomeDataRecvTimeByAidAll(void)
{
    int i;

    for (i = 0; i < DWCi_NodeInfoList_GetCount(); i++) {
        DWCi_ResetLastSomeDataRecvTimeByAid(DWCi_NodeInfoList_GetNodeInfoForIndex(i)[0x16]);
    }
}
