/*
 * function: DWCi_DeleteAID
 * address:  0x0216BCA4
 * packet:   pkt_ov009_0216BCA4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_DeleteAID (dwc_main.o)
 *
 * symbols:
 *   DWCi_NodeInfoList_GetNodeInfoForAID  0x02176410  arm  ov009
 *   DWCi_NodeInfoList_RemoveAID  0x02176164  arm  ov009
 */

extern char *DWCi_NodeInfoList_GetNodeInfoForAID(unsigned char aid);
extern int DWCi_NodeInfoList_RemoveAID(unsigned char aid);

int DWCi_DeleteAID(unsigned char aid)
{
    char *pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForAID(aid);
    int profileID;

    if (pNodeInfo == 0) return 0;
    profileID = *(int *)pNodeInfo;
    DWCi_NodeInfoList_RemoveAID(aid);
    return profileID;
}
