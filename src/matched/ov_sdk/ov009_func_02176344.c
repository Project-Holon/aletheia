/*
 * function: DWCi_NodeInfoList_GetMyNodeInfo
 * address:  0x02176344
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Passes the word at +0x678 of the module block on.
 *
 * symbols:
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID  0x021763AC  arm  ov009
 */

extern int func_02175F3C(void);
extern char *DWCi_NodeInfoList_GetNodeInfoForProfileID(int pid);

char *DWCi_NodeInfoList_GetMyNodeInfo(void)
{
    return DWCi_NodeInfoList_GetNodeInfoForProfileID(*(int *)(func_02175F3C() + 0x678));
}

