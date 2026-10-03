/*
 * function: func_02157138
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
 *   func_02059718       0x02059718  arm
 *   DWC_CreateUserData  0x020596FC  arm
 *   func_02059870       0x02059870  arm
 *
 * Clears the 0x40-byte DWC account user-data block, then rebuilds it when
 * the check at func_02059718 (CRC validation) fails: DWC_CreateUserData,
 * then the veneer at 0x02059870 into DWCi_Acc_ClearDirty (func_0205987C).
 * Called from arm9 sub_02009800 (bl at 0x0200982C), the save-table
 * constructor at 0x0209DB98.
 */

extern void MIi_CpuClearFast(unsigned int data, void *destp, unsigned int size);
struct DWCstAccUserData;
extern int func_02059718(struct DWCstAccUserData *userdata);
extern void DWC_CreateUserData(void *userdata);
extern void func_02059870(void *userdata);

void func_02157138(void *userdata)
{
    MIi_CpuClearFast(0, userdata, 0x40);
    if (func_02059718(userdata) == 0) {
        DWC_CreateUserData(userdata);
        func_02059870(userdata);
    }
}
