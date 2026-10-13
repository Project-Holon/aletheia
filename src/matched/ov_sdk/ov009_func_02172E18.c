/*
 * function: DWCi_CloseCancelHostAsync
 * address:  0x02172E18
 * packet:   pkt_ov009_02172E18
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CloseCancelHostAsync (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   DWCi_GetGT2ConnectionByProfileID  0x0216BBDC  arm  ov009
 *   func_02195DC4  0x02195DC4  arm  ov009
 *   DWCi_NodeInfoList_RemoveProfileID  0x02176254  arm  ov009
 */

extern int func_02175F3C(void);
extern int *DWCi_GetGT2ConnectionByProfileID(int pid, int flag);
extern void func_02195DC4(int a);
extern int DWCi_NodeInfoList_RemoveProfileID(int profileID);

int DWCi_CloseCancelHostAsync(int profileID)
{
    int **connection;
    int ret;

    *(int *)(func_02175F3C() + 0x680) = profileID;
    connection = (int **)DWCi_GetGT2ConnectionByProfileID(profileID, 0);
    if (connection) {
        *(char *)(func_02175F3C() + 0x629) = 1;
        func_02195DC4((int)(*connection));
        *(char *)(func_02175F3C() + 0x629) = 0;
        DWCi_NodeInfoList_RemoveProfileID(profileID);
        ret = 1;
    } else {
        DWCi_NodeInfoList_RemoveProfileID(profileID);
        ret = 0;
    }
    return ret;
}
