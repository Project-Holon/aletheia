/*
 * function: SCRCMD_StartEffectTask
 * address:  0x021D2F44
 * packet:   pkt_ov021_021D2F44
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021F37B8 resolves in ov064 (2026-10-02, lane gA2). Starts exist at
 * 0x021F37B8 in ov041, ov050, ov060 and ov064. ov050 is void(void) and ov060
 * takes two arguments. ov041 is out on two counts: its body ends in a tail
 * call to FLD_EXP_OBJ_RemoveUnit, which is void (src/matched/ov/ov021_func_021BE418.c,
 * EXACT), so it returns no value for the `t == 0` test; and it hands its
 * argument straight to FIELDMAP_GetExpObj and FIELDMAP_FreeCommonWork, the type that
 * GAMESYSTEM_GetFieldMap returns, while this call passes SCRCMD_WORK_GetGameSystem(b), which the
 * sibling SCRCMD_StartEffectAtPosition feeds to GAMESYSTEM_GetFieldMap. ov064's function applies
 * GAMESYSTEM_GetFieldMap to its argument and returns func_020122C0(arg, 0, cb, 0), a
 * task, which is what SCRIPT_SYS_CallEvent(x, t) receives here and in the same-shape
 * siblings SCRCMD_StartEffectTaskB (ov064-only GIMMICK64_CreateWaitEndEvent) and SCRCMD_StartEffectTaskC
 * (func_021F3AC0, ov064). SCRCMD_StartEffectAtPosition and SCRCMD_SetEffectPosition also call ov064.
 *
 * symbols:
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   func_021F37B8  0x021F37B8  thumb  ov064
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *func_021F37B8(int a);
extern void SCRIPT_SYS_CallEvent(void *, void *);

int SCRCMD_StartEffectTask(u32 a, u32 b)
{
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);
    void *t = func_021F37B8((int)SCRCMD_WORK_GetGameSystem((void *)b));

    if (t == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(x, t);
    return 1;
}
