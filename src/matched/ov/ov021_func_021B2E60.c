/*
 * function: SCRCMD_SCREENEFFECTS_WaitBuildModelNodeAnim
 * address:  0x021B2E60
 * packet:   pkt_ov021_021B2E60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_SetWait  0x020113D0  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_SCREENEFFECTS_CheckBuildModelNodeAnimDone  0x021B2E80  thumb  ov021
 *   gScrcmdScreeneffectsNodeHandle     0x021EE720  data  a2
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u16 gScrcmdScreeneffectsNodeHandle;
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern void VM_SetWait(char *p, int val);
extern int SCRCMD_SCREENEFFECTS_CheckBuildModelNodeAnimDone(u32, u32);

int SCRCMD_SCREENEFFECTS_WaitBuildModelNodeAnim(u32 a, u32 b)
{
    gScrcmdScreeneffectsNodeHandle = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    VM_SetWait((char *)a, (u32)SCRCMD_SCREENEFFECTS_CheckBuildModelNodeAnimDone);
    return 1;
}
