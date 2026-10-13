/*
 * function: DWC_Acc_CheckFriendKey
 * address:  0x02059374
 * packet:   pkt_02059374
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Acc_CheckFriendKey (libdwcaccount.TWL.HYB.a(dwc_account.o))
 *
 * symbols:
 *   DWC_Acc_CreateFriendKey          0x020592d0 arm
 */

extern unsigned long long DWC_Acc_CreateFriendKey(int gs_profile_id, unsigned long gamecode, int method);

int DWC_Acc_CheckFriendKey(unsigned long long friendkey, unsigned long gamecode, int method)
{
    int pid = (int)(friendkey & 0xffffffff);

    if (pid <= 0) {
        return 0;
    }
    if (friendkey == DWC_Acc_CreateFriendKey(pid, gamecode, method)) {
        return 1;
    }
    return 0;
}
