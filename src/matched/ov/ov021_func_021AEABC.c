/*
 * function: SCRCMD_StartTrainerBattle
 * address:  0x021AEABC
 * packet:   pkt_ov021_021AEABC
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
 *   func_0215A4C8  0x0215A4C8  thumb  ov010
 *   func_0215A4B4  0x0215A4B4  thumb  ov010
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   EVENT_BATTLE_CreateEncounterTask  0x0216E818  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_IncrementTrainerRecord  0x021AEDAC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern unsigned short SCRIPT_WORK_GetScriptId(unsigned char *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern int func_0215A4C8(int a0);
extern int func_0215A4B4(int a0);
extern void *SCRIPT_WORK_GetGameSystem(void *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern int EVENT_BATTLE_CreateEncounterTask(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern void SCRCMD_IncrementTrainerRecord(u32 a);

int SCRCMD_StartTrainerBattle(u32 a, u32 b)
{
    void *p;
    u32 x, y, z, w;

    p = SCRCMD_WORK_GetScriptWork((void *)b);
    SCRIPT_WORK_GetScriptId((unsigned char *)p);
    x = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    y = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    z = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    w = (u32)func_0215A4C8((u32)x);
    if (y == 0 && func_0215A4B4(x) == 1) {
        y = x;
    }
    SCRIPT_SYS_CallEvent(p, (void *)EVENT_BATTLE_CreateEncounterTask((int)SCRIPT_WORK_GetGameSystem(p), ((u32 *)SCRIPT_WORK_ResetFieldParam((int)p))[1], w, 0, x, y, z));
    SCRCMD_IncrementTrainerRecord(b);
    return 1;
}
