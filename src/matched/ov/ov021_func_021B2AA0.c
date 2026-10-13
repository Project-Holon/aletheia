/*
 * function: SCRCMD_SCREENEFFECTS_WaitScriptEffect
 * address:  0x021B2AA0
 * packet:   pkt_021B2AA0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   SCRCMD_SCREENEFFECTS_CheckScriptEffectDone  0x021B2874  thumb
 *   sub_020113D0   0x020113D0  thumb
 */

typedef unsigned int   u32;
extern void sub_020113D0(char *p, int val);
extern int SCRCMD_SCREENEFFECTS_CheckScriptEffectDone(u32 a, u32 b, u32 c, u32 d);

int SCRCMD_SCREENEFFECTS_WaitScriptEffect(void *p)
{
    sub_020113D0(p, (int)SCRCMD_SCREENEFFECTS_CheckScriptEffectDone);
    return 1;
}
