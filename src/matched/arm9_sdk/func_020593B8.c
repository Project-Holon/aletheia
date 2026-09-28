/*
 * function: func_020593B8
 * address:  0x020593B8
 * packet:   pkt_020593B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Acc_FriendKeyToGsProfileId (libdwcaccount.TWL.HYB.a(dwc_account.o))
 *
 * symbols:
 *   DWC_Acc_CheckFriendKey           0x02059374 arm
 */

extern int DWC_Acc_CheckFriendKey(unsigned long long friendkey, unsigned long gamecode, int method);

int func_020593B8(unsigned long long friendkey, unsigned long gamecode)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (DWC_Acc_CheckFriendKey(friendkey, gamecode, i)) {
            return (int)(friendkey & 0xffffffff);
        }
    }
    return 0;
}
