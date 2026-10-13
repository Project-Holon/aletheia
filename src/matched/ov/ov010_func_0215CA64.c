/*
 * function: SCRCMD_PROC_CallSubEvent
 * address:  0x0215CA64
 * packet:   pkt_ov010_0215CA64
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: reads two words and stores EVENT_FIELD_PROCLINK_CreateCommExitEvent's result
 * (over the system and the script's cell) in the script's slot.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_GetEvent  0x02158F50  thumb  ov010
 *   EVENT_FIELD_PROCLINK_CreateCommExitEvent  0x02161B90  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *vm);
extern void *SCRCMD_WORK_GetGameSystem(void *vm);
extern u32 SCRIPT_WORK_ReadWorkValue(void *c, void *vm);
extern void *SCRIPT_WORK_GetEvent(void *p);
extern void *EVENT_FIELD_PROCLINK_CreateCommExitEvent(void *p, void *a1, int kind, int sub, int flag);
extern void SCRIPT_SYS_CallEvent(void *p, void *v);

int SCRCMD_PROC_CallSubEvent(void *c, void *vm)
{
    void *slot;
    void *sys;
    u32 a;
    u32 b;

    slot = SCRCMD_WORK_GetScriptWork(vm);
    sys = SCRCMD_WORK_GetGameSystem(vm);
    a = SCRIPT_WORK_ReadWorkValue(c, vm);
    b = SCRIPT_WORK_ReadWorkValue(c, vm);
    SCRIPT_SYS_CallEvent(slot, EVENT_FIELD_PROCLINK_CreateCommExitEvent(sys, SCRIPT_WORK_GetEvent(slot), a, b, 0));
    return 1;
}
