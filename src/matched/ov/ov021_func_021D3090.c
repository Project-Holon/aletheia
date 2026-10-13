/*
 * function: SCRCMD_StartEffectTaskC
 * address:  0x021D3090
 * packet:   pkt_ov021_021D3090
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * FIELD_GIMMICK_ARC_EFFECT_CreateWaitPeakEvent resolves in ov064: the only Thumb function starting there
 * that takes one argument (ov043's takes two), and the neighbouring ov021
 * functions SCRCMD_StartEffectAtPosition and SCRCMD_SetEffectPosition already call ov064 code.
 *
 * symbols:
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FIELD_GIMMICK_ARC_EFFECT_CreateWaitPeakEvent  0x021F3AC0  thumb  ov064
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *FIELD_GIMMICK_ARC_EFFECT_CreateWaitPeakEvent(void *a);
extern void SCRIPT_SYS_CallEvent(void *, void *);

int SCRCMD_StartEffectTaskC(u32 a, u32 b)
{
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);
    void *t = FIELD_GIMMICK_ARC_EFFECT_CreateWaitPeakEvent(SCRCMD_WORK_GetGameSystem((void *)b));

    if (t == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(x, t);
    return 1;
}
