/*
 * function: func_02059A10
 * address:  0x02059A10
 * packet:   pkt_02059A10
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      DWC_SetGsProfileId (libdwcaccount.TWL.HYB.a(dwc_account.o))
 *
 * symbols:
 *   MI_CpuFill8                      0x02082bcc arm
 *   DWCi_Acc_SetGsProfileId          0x02059100 arm
 *   DWCi_Acc_SetFlag_DataType        0x020591f0 arm
 */

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void DWCi_Acc_SetGsProfileId(void *data, int gs_profile_id);
extern void DWCi_Acc_SetFlag_DataType(void *userdata, int type);

void func_02059A10(void *frienddata, int gs_profile_id)
{
    MI_CpuFill8(frienddata, 0, 12);
    DWCi_Acc_SetGsProfileId(frienddata, gs_profile_id);
    DWCi_Acc_SetFlag_DataType(frienddata, 3);
}
