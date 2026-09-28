/*
 * function: DWCi_IsBuddyFriendData
 * address:  0x0205915C
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwcaccount dwc_account.o.
 * The polarity (== 3 first) is what emits the branch instead of a predicated pair.
 */
extern unsigned long DWCi_Acc_GetFlags(void *frienddata);
extern unsigned long DWCi_Acc_GetFlag_DataType(void *frienddata);

int DWCi_IsBuddyFriendData(void *frienddata)
{
    if (DWCi_Acc_GetFlag_DataType(frienddata) == 3)
        return (DWCi_Acc_GetFlags(frienddata) & 4) == 4;
    return 0;
}
