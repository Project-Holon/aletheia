/*
 * function: DWC_GetFriendKey
 * address:  0x020598C4
 * packet:   pkt_020598C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GetFriendKey (libdwcaccount.TWL.HYB.a(dwc_account.o))
 *
 * symbols:
 *   DWCi_Acc_GetFlag_DataType        0x0205911c arm
 *   DWCi_Acc_GetFriendKey            0x020590ac arm
 */

extern unsigned long DWCi_Acc_GetFlag_DataType(void *userdata);
extern unsigned long long DWCi_Acc_GetFriendKey(void *data);

unsigned long long DWC_GetFriendKey(void *frienddata)
{
    if (DWCi_Acc_GetFlag_DataType(frienddata) != 2) {
        return 0;
    }
    return DWCi_Acc_GetFriendKey(frienddata);
}
