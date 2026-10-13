/*
 * file:     unit_021B2380.c
 * unit:     yes
 * function: SCRCMD_GIMMICK39_CallEvent, SCRCMD_GIMMICK39_SetState, SCRCMD_GIMMICK39_TransferSound, SCRCMD_GIMMICK40_SetFlag, SCRCMD_GIMMICK40_GetFlag, SCRCMD_GIMMICK40_CallEvent, SCRCMD_GIMMICK42_CallEventWithFlag, SCRCMD_GIMMICK42_CallEvent, SCRCMD_GIMMICK42_CallSecondEvent, SCRCMD_GIMMICK39_CallSecondEvent, SCRCMD_GIMMICK38_CallEvent, SCRCMD_GIMMICK38_CallSecondEvent, SCRCMD_GIMMICK43_CallEvent, SCRCMD_GIMMICK43_CallSecondEvent, SCRCMD_GIMMICK44_CallEvent, SCRCMD_GIMMICK43_Cleanup, SCRCMD_GIMMICK44_Cleanup, SCRCMD_GIMMICK45_CallEvent, SCRCMD_GIMMICK42_CallSecondEventU16, SCRCMD_GIMMICK45_SetState, SCRCMD_GIMMICK38_CallCheckEvent, SCRCMD_GIMMICK46_CallEvent, SCRCMD_GIMMICK46_CallSecondEvent, SCRCMD_GIMMICK46_CallThirdEvent
 * address:  0x021B2380
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from scrcmd_screeneffects.c at 0x021B2380 (lane L135, ov043 launcher command handlers; original unknown).
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GIMMICK39_CreateSwitchEvent  0x021F3E24  thumb  ov039
 *   GIMMICK39_UnlockLaneFromScript  0x021F4134  thumb  ov039
 *   GIMMICK39_TransferSound  0x021F3D74  thumb  ov039
 *   GIMMICK40_SetFlag  0x021F37A4  thumb  ov040
 *   GIMMICK40_GetFlag  0x021F37C8  thumb  ov040
 *   GIMMICK40_CreateEvent  0x021F37EC  thumb  ov040
 *   GIMMICK42_CreateStateEvent  0x021F3834  thumb
 *   GIMMICK42_CreateOneShotEvent  0x021F3888  thumb  ov042
 *   GIMMICK39_UnlockLane  0x021F4184  thumb  ov039
 *   GIMMICK38_StartPlateEvent  0x021F41B0  thumb  ov038
 *   GIMMICK38_StartScriptedEvent  0x021F41DC  thumb  ov038
 *   GIMMICK43_CallLiftEvent  0x021F398C  thumb  ov043
 *   GIMMICK43_CallElevatorEvent  0x021F3A28  thumb  ov043
 *   GIMMICK44_CallEvent  0x021F3770  thumb  ov044
 *   GIMMICK43_SnapElevatorToTop  0x021F42A8  thumb  ov043
 *   GIMMICK44_SnapLiftToBottom  0x021F3970  thumb  ov044
 *   GIMMICK45_StartSecondarySwitchEvent  0x021F384C  thumb  ov045
 *   GIMMICK45_ReplacePlayerIfRequirementMet  0x021F38C4  thumb  ov045
 *   GIMMICK38_StartDoorEvent  0x021F3A88  thumb  ov038
 *   GIMMICK46_StartHopEvent  0x021F3B5C  thumb  ov046
 *   GIMMICK46_StartLeverEvent  0x021F3AD0  thumb  ov046
 *   GIMMICK46_StartRotateEvent  0x021F3B18  thumb  ov046
 */
#include "../arm9/script_vm_types.h"

struct ScrcmdWork;
struct GameSystem;

extern void *SCRCMD_WORK_GetScriptWork(struct ScrcmdWork *cmdWork);
extern u16 SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern void SCRIPT_SYS_CallEvent(void *scriptWork, void *event);
extern struct GameSystem *SCRCMD_WORK_GetGameSystem(struct ScrcmdWork *cmdWork);
extern u16 *SCRIPT_WORK_ReadWorkPointer(ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern void *GAMESYSTEM_GetFieldMap(struct GameSystem *gameSystem);
extern u16 VM_GetU16(ScriptVm *vm);
extern void *GIMMICK39_CreateSwitchEvent(struct GameSystem *gameSystem, u32 param);
extern void GIMMICK39_UnlockLaneFromScript(struct GameSystem *gameSystem, u32 value);
extern void GIMMICK39_TransferSound(struct GameSystem *gameSystem);
extern void GIMMICK40_SetFlag(void *fieldMap);
extern int GIMMICK40_GetFlag(void *fieldMap);
extern void *GIMMICK40_CreateEvent(struct GameSystem *gameSystem, u32 param);
extern void *GIMMICK42_CreateStateEvent(struct GameSystem *gameSystem, u8 param, u32 flag);
extern void *GIMMICK42_CreateOneShotEvent(struct GameSystem *gameSystem, u32 param);
extern void *GIMMICK39_UnlockLane(struct GameSystem *gameSystem, u16 param);
extern void *GIMMICK38_StartPlateEvent(struct GameSystem *gameSystem, int param);
extern void *GIMMICK38_StartScriptedEvent(struct GameSystem *gameSystem, int param);
extern void *GIMMICK43_CallLiftEvent(struct GameSystem *gameSystem, int param);
extern void *GIMMICK43_CallElevatorEvent(struct GameSystem *gameSystem, u32 flag);
extern void *GIMMICK44_CallEvent(struct GameSystem *gameSystem, u32 flag);
extern void GIMMICK43_SnapElevatorToTop(struct GameSystem *gameSystem);
extern void GIMMICK44_SnapLiftToBottom(struct GameSystem *gameSystem);
extern void *GIMMICK45_StartSecondarySwitchEvent(struct GameSystem *gameSystem, int param);
extern void GIMMICK45_ReplacePlayerIfRequirementMet(struct GameSystem *gameSystem, int param);
extern void *GIMMICK38_StartDoorEvent(struct GameSystem *gameSystem, int paramA, int paramB);
extern void *GIMMICK46_StartHopEvent(struct GameSystem *gameSystem, int param);
extern void *GIMMICK46_StartLeverEvent(struct GameSystem *gameSystem, int paramA, int paramB);
extern void *GIMMICK46_StartRotateEvent(struct GameSystem *gameSystem, u32 param);

int SCRCMD_GIMMICK39_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK39_SetState(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK39_TransferSound(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK40_SetFlag(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK40_GetFlag(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK40_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK42_CallEventWithFlag(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK42_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK42_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK39_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK38_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK38_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK43_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK43_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK44_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK43_Cleanup(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK44_Cleanup(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK45_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK42_CallSecondEventU16(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK45_SetState(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK38_CallCheckEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK46_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK46_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GIMMICK46_CallThirdEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);

/*
 * The handlers below start a field gimmick overlay event (ov038 to ov046,
 * one entry point each). Most read their parameter from the script, create
 * the event through the overlay and hand it to the script system; they
 * return 1 so the script waits. A null event means nothing to run, so the
 * script still waits one step.
 */

/* Script command: start the ov039 event for a parameter byte. */
int SCRCMD_GIMMICK39_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u8 param = VM_GetU16(vm);
    void *event = GIMMICK39_CreateSwitchEvent(gameSystem, param);

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: store a value byte in the ov039 gimmick state (slot 2). */
int SCRCMD_GIMMICK39_SetState(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u8 value;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    value = VM_GetU16(vm);
    GIMMICK39_UnlockLaneFromScript(gameSystem, value);
    return 0;
}

/* Script command: ov039 sound slot transfer (no arguments). */
int SCRCMD_GIMMICK39_TransferSound(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    GIMMICK39_TransferSound(SCRCMD_WORK_GetGameSystem(cmdWork));
    return 0;
}

/* Script command: set the ov040 gimmick flag of the current map (no arguments). */
int SCRCMD_GIMMICK40_SetFlag(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    SCRCMD_WORK_GetScriptWork(cmdWork);
    GIMMICK40_SetFlag(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork)));
    return 0;
}

/* Script command: write the ov040 gimmick flag of the current map to a script variable (0 or 1). */
int SCRCMD_GIMMICK40_GetFlag(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *fieldMap;
    u16 *result;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    fieldMap = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork));
    result = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    if (GIMMICK40_GetFlag(fieldMap) != 0) {
        *result = 1;
    } else {
        *result = 0;
    }
    return 0;
}

/* Script command: start the ov040 event for a parameter byte. */
int SCRCMD_GIMMICK40_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u8 param = VM_GetU16(vm);
    void *event = GIMMICK40_CreateEvent(gameSystem, param);

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov042 event for a parameter byte with its flag set. */
int SCRCMD_GIMMICK42_CallEventWithFlag(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u8 param = VM_GetU16(vm);
    u32 flag = 1;
    void *event = GIMMICK42_CreateStateEvent(gameSystem, param, flag);

    if (event == 0) {
        return flag;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return flag;
}

/* Same as SCRCMD_GIMMICK42_CallEventWithFlag with the flag clear. */
int SCRCMD_GIMMICK42_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u8 param = VM_GetU16(vm);
    void *event = GIMMICK42_CreateStateEvent(gameSystem, param, 0);

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov042 second event for a parameter byte. */
int SCRCMD_GIMMICK42_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u8 param = VM_GetU16(vm);
    void *event = GIMMICK42_CreateOneShotEvent(gameSystem, param);

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov039 second event for a script variable value. */
int SCRCMD_GIMMICK39_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = GIMMICK39_UnlockLane(gameSystem, *SCRIPT_WORK_ReadWorkPointer(vm, cmdWork));

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov038 event for a script variable value. */
int SCRCMD_GIMMICK38_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = GIMMICK38_StartPlateEvent(gameSystem, *SCRIPT_WORK_ReadWorkPointer(vm, cmdWork));

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov038 second event for an immediate value. */
int SCRCMD_GIMMICK38_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = GIMMICK38_StartScriptedEvent(gameSystem, VM_GetU16(vm));

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov043 event for an immediate value. */
int SCRCMD_GIMMICK43_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = GIMMICK43_CallLiftEvent(gameSystem, VM_GetU16(vm));

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov043 second event; the immediate value is reduced to a flag. */
int SCRCMD_GIMMICK43_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = GIMMICK43_CallElevatorEvent(gameSystem, VM_GetU16(vm) ? 1 : 0);

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov044 event; the immediate value is reduced to a flag. */
int SCRCMD_GIMMICK44_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = GIMMICK44_CallEvent(gameSystem, VM_GetU16(vm) ? 1 : 0);

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: ov043 cleanup (no arguments). */
int SCRCMD_GIMMICK43_Cleanup(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    GIMMICK43_SnapElevatorToTop(SCRCMD_WORK_GetGameSystem(cmdWork));
    return 0;
}

/* Script command: ov044 cleanup (no arguments). */
int SCRCMD_GIMMICK44_Cleanup(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    GIMMICK44_SnapLiftToBottom(SCRCMD_WORK_GetGameSystem(cmdWork));
    return 0;
}

/* Script command: start the ov045 event for an immediate value. */
int SCRCMD_GIMMICK45_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = GIMMICK45_StartSecondarySwitchEvent(gameSystem, VM_GetU16(vm));

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov042 second event for an immediate value. */
int SCRCMD_GIMMICK42_CallSecondEventU16(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = GIMMICK42_CreateOneShotEvent(gameSystem, VM_GetU16(vm));

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: ov045 state change for an immediate value. */
int SCRCMD_GIMMICK45_SetState(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    GIMMICK45_ReplacePlayerIfRequirementMet(SCRCMD_WORK_GetGameSystem(cmdWork), VM_GetU16(vm));
    return 0;
}

/* Script command: start the ov038 check event for two immediate values. */
int SCRCMD_GIMMICK38_CallCheckEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    int paramA = VM_GetU16(vm);
    int paramB = VM_GetU16(vm);
    void *event = GIMMICK38_StartDoorEvent(gameSystem, paramA, paramB);

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov046 event for an immediate value. */
int SCRCMD_GIMMICK46_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = GIMMICK46_StartHopEvent(gameSystem, VM_GetU16(vm));

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov046 second event for two script values. */
int SCRCMD_GIMMICK46_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    int paramA = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int paramB = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *event = GIMMICK46_StartLeverEvent(gameSystem, paramA, paramB);

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov046 third event for a script value. */
int SCRCMD_GIMMICK46_CallThirdEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = GIMMICK46_StartRotateEvent(gameSystem, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}
