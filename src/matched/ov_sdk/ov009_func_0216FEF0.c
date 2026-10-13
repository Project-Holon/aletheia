/*
 * function: DWCi_CanSendMatchCommandDirect
 * address:  0x0216FEF0
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Whether a profile id has both a gt2 connection and a node record.
 *
 * symbols:
 *   DWCi_GetGT2ConnectionByProfileID  0x0216BBDC  arm  ov009
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID  0x021763AC  arm  ov009
 */

extern int *DWCi_GetGT2ConnectionByProfileID(int pid, int flag);
extern char *DWCi_NodeInfoList_GetNodeInfoForProfileID(int pid);

int DWCi_CanSendMatchCommandDirect(unsigned char command, int pid)
{
    int r = 1;

    if (DWCi_GetGT2ConnectionByProfileID(pid, r) == 0) {
        return 0;
    }
    if (DWCi_NodeInfoList_GetNodeInfoForProfileID(pid) == 0) {
        r = 0;
    }
    return r;
}
