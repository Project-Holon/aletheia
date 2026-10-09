/*
 * file:     unit_021EE860.c
 * function: DWC_IsValidFriendData
 * address:  0x021EE860
 * packet:   pkt_ov024_021EE860
 * region:   ov024
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * sdk:      DWC_IsValidFriendData (libdwcaccount.TWL.HYB.thumb.a(dwc_account.o))
 *
 * symbols:
 *   DWCi_Acc_GetFlag_DataType  0x021A23B0  thumb  ov021
 */

extern unsigned long DWCi_Acc_GetFlag_DataType(void *userdata);

int DWC_IsValidFriendData(void *frienddata)
{
    if (DWCi_Acc_GetFlag_DataType(frienddata))
        return 1;
    return 0;
}
