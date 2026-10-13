/*
 * function: SCRCMD_SCREENEFFECTS_WaitBrightness
 * address:  0x021B2A90
 * packet:   pkt_ov021_021B2A90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_SetWait  0x020113D0  thumb
 *   SCRCMD_SCREENEFFECTS_CheckBrightnessDone  0x021B2860  thumb  ov021
 */

typedef unsigned int u32;

extern void VM_SetWait(char *p, int val);
extern int SCRCMD_SCREENEFFECTS_CheckBrightnessDone(u32 a, u32 b, u32 c, u32 d);

int SCRCMD_SCREENEFFECTS_WaitBrightness(u32 a)
{
    VM_SetWait((char *)a, (u32)SCRCMD_SCREENEFFECTS_CheckBrightnessDone);
    return 1;
}
