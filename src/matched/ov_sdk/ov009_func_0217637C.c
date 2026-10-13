/*
 * function: DWCi_NodeInfoList_GetNodeInfoForIndex
 * address:  0x0217637C
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_NodeInfoList_GetNodeInfoForIndex: the 0x28-byte node record at an index, or null past the count.
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 */

extern char *func_02175F3C(void);

char *DWCi_NodeInfoList_GetNodeInfoForIndex(int index)
{
    if (index >= *(int *)(func_02175F3C() + 0x50)) {
        return 0;
    }
    return func_02175F3C() + 0x54 + index * 0x28;
}
