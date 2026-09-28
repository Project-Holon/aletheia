/*
 * function: func_02059A5C
 * address:  0x02059A5C
 * packet:   pkt_02059A5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_IsEqualFriendData (libdwcaccount.TWL.HYB.a(dwc_account.o))
 *
 * symbols:
 *   DWCi_Acc_GetFlag_DataType        0x0205911c arm
 *   DWCi_Acc_GetGsProfileId          0x020590c0 arm
 *   DWCi_Acc_GetUserId               0x02059084 arm
 *   DWCi_Acc_GetPlayerId             0x020590a4 arm
 *   DWCi_Acc_GetFriendKey            0x020590ac arm
 */

extern unsigned long DWCi_Acc_GetFlag_DataType(void *userdata);
extern int DWCi_Acc_GetGsProfileId(void *data);
extern unsigned long long DWCi_Acc_GetUserId(void *userdata);
extern unsigned long DWCi_Acc_GetPlayerId(void *userdata);
extern unsigned long long DWCi_Acc_GetFriendKey(void *data);

int func_02059A5C(void *frienddata1, void *frienddata2)
{
    unsigned long type1;
    unsigned long type2;

    type1 = DWCi_Acc_GetFlag_DataType(frienddata1);
    type2 = DWCi_Acc_GetFlag_DataType(frienddata2);
    if (type1 != type2) {
        return 0;
    }
    if (type1 == 3) {
        return DWCi_Acc_GetGsProfileId(frienddata1) == DWCi_Acc_GetGsProfileId(frienddata2);
    } else if (type1 == 1) {
        if (DWCi_Acc_GetUserId(frienddata1) == DWCi_Acc_GetUserId(frienddata2)
            && DWCi_Acc_GetPlayerId(frienddata1) == DWCi_Acc_GetPlayerId(frienddata2)) {
            return 1;
        }
        return 0;
    } else if (type1 == 2) {
        return DWCi_Acc_GetFriendKey(frienddata1) == DWCi_Acc_GetFriendKey(frienddata2);
    }
    return 0;
}
