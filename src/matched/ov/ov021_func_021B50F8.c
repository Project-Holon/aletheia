/*
 * function: SCRCMD_PROC_FLD_CallCatchTutorial
 * address:  0x021B50F8
 * packet:   pkt_ov021_021B50F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   EVENT_BATTLE_CreateCatchTutorial  0x0216E95C  thumb  ov010
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *EVENT_BATTLE_CreateCatchTutorial(void *sys, u32 arg, u32 heap);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_PROC_FLD_CallCatchTutorial(u32 a, u32 b)
{
    void *s = SCRCMD_WORK_GetScriptWork((void *)b);
    void *d = SCRCMD_WORK_GetGameSystem((void *)b);

    SCRIPT_SYS_CallEvent(s, EVENT_BATTLE_CreateCatchTutorial(d, (u32)GAMESYSTEM_GetFieldMap((void *)d), 4));
    return 1;
}
