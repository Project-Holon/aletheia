/*
 * file:     unit_021F3D24.c
 * function: DWC_IsValidFriendData
 * address:  0x021F3D24
 * packet:   pkt_ov048_021F3D24
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * sdk:      DWC_IsValidFriendData (libdwcaccount.TWL.HYB.thumb.a(dwc_account.o))
 *
 * symbols:
 *   DWCi_Acc_GetFlag_DataType  0x021F3C2C  thumb  ov048
 */

extern unsigned long DWCi_Acc_GetFlag_DataType(void *userdata);

int DWC_IsValidFriendData(void *frienddata)
{
    if (DWCi_Acc_GetFlag_DataType(frienddata))
        return 1;
    return 0;
}
