/*
 * function: DWCi_IsReverseBuddyFriendData
 * address:  0x02059194
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwcaccount dwc_account.o.
 */
extern unsigned long DWCi_Acc_GetFlags(void *frienddata);

int DWCi_IsReverseBuddyFriendData(void *frienddata)
{
    unsigned long type = DWCi_Acc_GetFlags(frienddata);
    return (type & 8) == 8;
}
