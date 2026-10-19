/*
 * function: SCRCMD_StartTrainerBattleWithMon
 * address:  0x021AED24
 * packet:   pkt_ov021_021AED24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetScriptId  0x02158F8C  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   EVENT_TRAINER_GetBattleType  0x0215A4C8  thumb  ov010
 *   EVENT_TRAINER_IsDoubleBattle  0x0215A4B4  thumb  ov010
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   EVENT_BATTLE_CreateEncounterTaskWithMon  0x0216EAB0  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * The four SCRIPT_WORK_ReadWorkValue results are u16 locals (the callee returns u16):
 * with u32 locals the stack-argument stores for EVENT_BATTLE_CreateEncounterTaskWithMon schedule
 * after the r1/r2 setup instead of before it.
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern unsigned short SCRIPT_WORK_GetScriptId(unsigned char *p);
extern u16 SCRIPT_WORK_ReadWorkValue(u32 a, u32 b);
extern int EVENT_TRAINER_GetBattleType(int a0);
extern int EVENT_TRAINER_IsDoubleBattle(int a0);
extern void *SCRIPT_WORK_GetGameSystem(void *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern void *EVENT_BATTLE_CreateEncounterTaskWithMon(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 idx);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_StartTrainerBattleWithMon(u32 a, u32 b)
{
    u32 t;
    void *p;
    u16 x, y, z, w;

    p = SCRCMD_WORK_GetScriptWork((void *)b);
    SCRIPT_WORK_GetScriptId((unsigned char *)p);
    x = SCRIPT_WORK_ReadWorkValue(a, b);
    y = SCRIPT_WORK_ReadWorkValue(a, b);
    z = SCRIPT_WORK_ReadWorkValue(a, b);
    w = SCRIPT_WORK_ReadWorkValue(a, b);
    t = EVENT_TRAINER_GetBattleType(x);
    if (y == 0 && EVENT_TRAINER_IsDoubleBattle(x) == 1) {
        y = x;
    }
    SCRIPT_SYS_CallEvent(p, (void *)EVENT_BATTLE_CreateEncounterTaskWithMon((void *)((u32)SCRIPT_WORK_GetGameSystem(p)), ((u32 *)SCRIPT_WORK_ResetFieldParam((int)p))[1], t, 0, x, y, z, w));
    return 1;
}
