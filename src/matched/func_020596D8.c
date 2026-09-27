/*
 * function: DWC_IsValidFriendData
 * address:  0x020596D8
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
extern unsigned long DWCi_Acc_GetFlag_DataType(void *frienddata);

int DWC_IsValidFriendData(void *frienddata)
{
    unsigned long type = DWCi_Acc_GetFlag_DataType(frienddata);
    return type != 0;
}
