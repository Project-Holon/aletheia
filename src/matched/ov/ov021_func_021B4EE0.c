/*
 * function: SCRCMD_PROC_FLD_SetNextEventAndEnd
 * address:  0x021B4EE0
 * packet:   pkt_ov021_021B4EE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02011290  0x02011290  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRIPT_SYS_SetNextEventFromWork  0x0215898C  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_NETWORK_CreateCommBattleEvent  0x0215F8A8  thumb  ov010
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern void *SCRCMD_NETWORK_CreateCommBattleEvent(void *p, int a1);
struct ScriptVm;
extern void SCRIPT_SYS_SetNextEventFromWork(int a, int b);
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);

int SCRCMD_PROC_FLD_SetNextEventAndEnd(u32 a, u32 b)
{
    void *s = SCRCMD_WORK_GetScriptWork((void *)b);
    void *d = SCRCMD_WORK_GetGameSystem((void *)b);

    GAMESYSTEM_GetFieldMap((void *)d);
    SCRIPT_SYS_SetNextEventFromWork((int)s, (int)SCRCMD_NETWORK_CreateCommBattleEvent(d, SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b)));
    func_02011290((struct ScriptVm *)a);
    return 1;
}
