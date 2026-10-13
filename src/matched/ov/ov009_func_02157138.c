/*
 * function: DWC_RAPCOMMON_InitUserData
 * address:  0x02157138
 * packet:   pkt_ov009_02157138
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MIi_CpuClearFast    0x02082AC0  arm
 *   DWC_CheckUserData       0x02059718  arm
 *   DWC_CreateUserData  0x020596FC  arm
 *   DWC_ClearDirtyFlag       0x02059870  arm
 *
 * Clears the 0x40-byte DWC account user-data block, then rebuilds it when
 * the check at DWC_CheckUserData (CRC validation) fails: DWC_CreateUserData,
 * then the veneer at 0x02059870 into DWCi_Acc_ClearDirty (DWCi_Acc_ClearDirty).
 * Called from arm9 WIFILIST_Init (bl at 0x0200982C), the save-table
 * constructor at 0x0209DB98.
 */

extern void MIi_CpuClearFast(unsigned int data, void *destp, unsigned int size);
struct DWCstAccUserData;
extern int DWC_CheckUserData(struct DWCstAccUserData *userdata);
extern void DWC_CreateUserData(void *userdata);
extern void DWC_ClearDirtyFlag(void *userdata);

void DWC_RAPCOMMON_InitUserData(void *userdata)
{
    MIi_CpuClearFast(0, userdata, 0x40);
    if (DWC_CheckUserData(userdata) == 0) {
        DWC_CreateUserData(userdata);
        DWC_ClearDirtyFlag(userdata);
    }
}
