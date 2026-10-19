/*
 * function: DWC_IsBuddyFriendData
 * address:  0x0205912C
 * packet:   pkt_0205912C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_IsBuddyFriendData (libdwcaccount.TWL.HYB.a dwc_account.o)
 *
 * symbols:
 *   DWCi_IsBuddyFriendData  0x0205915C  arm
 *   DWCi_IsReverseBuddyFriendData  0x02059194  arm
 */

typedef unsigned char u8;
typedef int BOOL;

extern BOOL DWCi_IsBuddyFriendData(void *frienddata);
extern BOOL DWCi_IsReverseBuddyFriendData(void *frienddata);

BOOL DWC_IsBuddyFriendData(void *frienddata)
{
    return (DWCi_IsBuddyFriendData(frienddata) && DWCi_IsReverseBuddyFriendData(frienddata)) ? 1 : 0;
}
