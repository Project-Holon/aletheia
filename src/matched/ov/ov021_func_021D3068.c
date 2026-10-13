/*
 * function: SCRCMD_StartEffectTaskB
 * address:  0x021D3068
 * packet:   pkt_ov021_021D3068
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   GIMMICK64_CreateWaitEndEvent  0x021F3ADC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GIMMICK64_CreateWaitEndEvent(void *a);
extern void SCRIPT_SYS_CallEvent(void *, void *);

int SCRCMD_StartEffectTaskB(u32 a, u32 b)
{
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);
    void *t = GIMMICK64_CreateWaitEndEvent(SCRCMD_WORK_GetGameSystem((void *)b));

    if (t == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(x, t);
    return 1;
}
