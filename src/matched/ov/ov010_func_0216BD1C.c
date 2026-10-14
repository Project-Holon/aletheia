/*
 * function: SCRCMD_EVENT_MON_CmdStartSpPokeGimmickStepB
 * address: 0x0216BD1C
 * packet: pkt_ov010_0216BD1C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRCMD_WORK_GetScriptWork 0x0215A5F4 thumb ov010
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 *   SP_POKE_GIMMICK_StartWaitAnimeProgress 0x021F3B40 thumb ov059
 *   SCRIPT_SYS_CallEvent 0x0215897C thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern u32 SCRIPT_WORK_ReadWorkValue(void *, void *);
extern void *SP_POKE_GIMMICK_StartWaitAnimeProgress(void *, u32);
extern void SCRIPT_SYS_CallEvent(void *, void *);
int SCRCMD_EVENT_MON_CmdStartSpPokeGimmickStepB(void *ctx, void *vm)
{
    void *ws, *p, *task;
    ws = SCRCMD_WORK_GetScriptWork(vm);
    p = SCRCMD_WORK_GetGameSystem(vm);
    task = SP_POKE_GIMMICK_StartWaitAnimeProgress(p, SCRIPT_WORK_ReadWorkValue(ctx, vm));
    if (task == 0) return 1;
    SCRIPT_SYS_CallEvent(ws, task);
    return 1;
}
