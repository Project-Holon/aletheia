/*
 * function: func_02059980
 * address:  0x02059980
 * packet:   pkt_02059980
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_CreateFriendKeyToken (libdwcaccount.TWL.HYB.a(dwc_account.o))
 *
 * symbols:
 *   MI_CpuFill8                      0x02082bcc arm
 *   DWCi_Acc_SetFriendKey            0x020590f8 arm
 *   DWCi_Acc_SetFlag_DataType        0x020591f0 arm
 */

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void DWCi_Acc_SetFriendKey(void *data, unsigned long long friendkey);
extern void DWCi_Acc_SetFlag_DataType(void *userdata, int type);

void func_02059980(void *token, unsigned long long friend_key)
{
    MI_CpuFill8(token, 0, 12);
    DWCi_Acc_SetFriendKey(token, friend_key);
    DWCi_Acc_SetFlag_DataType(token, 2);
}
