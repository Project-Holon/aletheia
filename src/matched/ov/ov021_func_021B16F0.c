/*
 * function: SCRCMD_FLDMMDL_WaitAnimeTasks
 * address:  0x021B16F0
 * packet:   pkt_ov021_021B16F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_SetWait  0x020113D0  thumb
 *   SCRCMD_FLDMMDL_CheckAnimeTasksDone  0x021B16DC  thumb  ov021
 */

typedef unsigned int u32;

extern void VM_SetWait(char *p, int val);
extern int SCRCMD_FLDMMDL_CheckAnimeTasksDone(u32 a, u32 b, u32 c, u32 d);

int SCRCMD_FLDMMDL_WaitAnimeTasks(u32 a)
{
    VM_SetWait((char *)a, (u32)SCRCMD_FLDMMDL_CheckAnimeTasksDone);
    return 1;
}
