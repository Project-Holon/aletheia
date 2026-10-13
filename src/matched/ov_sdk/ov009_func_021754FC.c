/*
 * function: DWCi_IsBackupMine
 * address:  0x021754FC
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_IsBackupMine: whether node 0 is this host's own profile.
 *
 * symbols:
 *   DWCi_NodeInfoList_GetNodeInfoForIndex  0x0217637C  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 */

extern int func_02175F3C(void);
extern char *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);

int DWCi_IsBackupMine(void)
{
    int r = 0;
    int *node = (int *)DWCi_NodeInfoList_GetNodeInfoForIndex(r);

    if (node != 0 && *node == *(int *)(func_02175F3C() + 0x678)) {
        r = 1;
    }
    return r;
}
