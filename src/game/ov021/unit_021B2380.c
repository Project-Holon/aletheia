/*
 * file:     unit_021B2380.c
 * unit:     yes
 * function: SCRCMD_FIELD_GIMMICK_CART_LANES_CallEvent, SCRCMD_FIELD_GIMMICK_CART_LANES_SetState, SCRCMD_FIELD_GIMMICK_CART_LANES_TransferSound, SCRCMD_FIELD_GIMMICK_FLAG_ANIME_SetFlag, SCRCMD_FIELD_GIMMICK_FLAG_ANIME_GetFlag, SCRCMD_FIELD_GIMMICK_FLAG_ANIME_CallEvent, SCRCMD_FIELD_GIMMICK_BUTTON_STATES_CallEventWithFlag, SCRCMD_FIELD_GIMMICK_BUTTON_STATES_CallEvent, SCRCMD_FIELD_GIMMICK_BUTTON_STATES_CallSecondEvent, SCRCMD_FIELD_GIMMICK_CART_LANES_CallSecondEvent, SCRCMD_FIELD_GIMMICK_PLATE_DOORS_CallEvent, SCRCMD_FIELD_GIMMICK_PLATE_DOORS_CallSecondEvent, SCRCMD_FIELD_GIMMICK_LIFT_ELEVATOR_CallEvent, SCRCMD_FIELD_GIMMICK_LIFT_ELEVATOR_CallSecondEvent, SCRCMD_FIELD_GIMMICK_LIFT_CallEvent, SCRCMD_FIELD_GIMMICK_LIFT_ELEVATOR_Cleanup, SCRCMD_FIELD_GIMMICK_LIFT_Cleanup, SCRCMD_FIELD_GIMMICK_SWITCH_TOGGLE_CallEvent, SCRCMD_FIELD_GIMMICK_BUTTON_STATES_CallSecondEventU16, SCRCMD_FIELD_GIMMICK_SWITCH_TOGGLE_SetState, SCRCMD_FIELD_GIMMICK_PLATE_DOORS_CallCheckEvent, SCRCMD_FIELD_GIMMICK_ROTATING_ROOM_CallEvent, SCRCMD_FIELD_GIMMICK_ROTATING_ROOM_CallSecondEvent, SCRCMD_FIELD_GIMMICK_ROTATING_ROOM_CallThirdEvent
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
 *   FIELD_GIMMICK_CART_LANES_CreateSwitchEvent  0x021F3E24  thumb  ov039
 *   FIELD_GIMMICK_CART_LANES_UnlockLaneFromScript  0x021F4134  thumb  ov039
 *   FIELD_GIMMICK_CART_LANES_TransferSound  0x021F3D74  thumb  ov039
 *   FIELD_GIMMICK_FLAG_ANIME_SetFlag  0x021F37A4  thumb  ov040
 *   FIELD_GIMMICK_FLAG_ANIME_GetFlag  0x021F37C8  thumb  ov040
 *   FIELD_GIMMICK_FLAG_ANIME_CreateEvent  0x021F37EC  thumb  ov040
 *   FIELD_GIMMICK_BUTTON_STATES_CreateStateEvent  0x021F3834  thumb
 *   FIELD_GIMMICK_BUTTON_STATES_CreateOneShotEvent  0x021F3888  thumb  ov042
 *   FIELD_GIMMICK_CART_LANES_UnlockLane  0x021F4184  thumb  ov039
 *   FIELD_GIMMICK_PLATE_DOORS_StartPlateEvent  0x021F41B0  thumb  ov038
 *   FIELD_GIMMICK_PLATE_DOORS_StartScriptedEvent  0x021F41DC  thumb  ov038
 *   FIELD_GIMMICK_LIFT_ELEVATOR_CallLiftEvent  0x021F398C  thumb  ov043
 *   FIELD_GIMMICK_LIFT_ELEVATOR_CallElevatorEvent  0x021F3A28  thumb  ov043
 *   FIELD_GIMMICK_LIFT_CallEvent  0x021F3770  thumb  ov044
 *   FIELD_GIMMICK_LIFT_ELEVATOR_SnapElevatorToTop  0x021F42A8  thumb  ov043
 *   FIELD_GIMMICK_LIFT_SnapLiftToBottom  0x021F3970  thumb  ov044
 *   FIELD_GIMMICK_SWITCH_TOGGLE_StartSecondarySwitchEvent  0x021F384C  thumb  ov045
 *   FIELD_GIMMICK_SWITCH_TOGGLE_ReplacePlayerIfRequirementMet  0x021F38C4  thumb  ov045
 *   FIELD_GIMMICK_PLATE_DOORS_StartDoorEvent  0x021F3A88  thumb  ov038
 *   FIELD_GIMMICK_ROTATING_ROOM_StartHopEvent  0x021F3B5C  thumb  ov046
 *   FIELD_GIMMICK_ROTATING_ROOM_StartLeverEvent  0x021F3AD0  thumb  ov046
 *   FIELD_GIMMICK_ROTATING_ROOM_StartRotateEvent  0x021F3B18  thumb  ov046
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
extern void *FIELD_GIMMICK_CART_LANES_CreateSwitchEvent(struct GameSystem *gameSystem, u32 param);
extern void FIELD_GIMMICK_CART_LANES_UnlockLaneFromScript(struct GameSystem *gameSystem, u32 value);
extern void FIELD_GIMMICK_CART_LANES_TransferSound(struct GameSystem *gameSystem);
extern void FIELD_GIMMICK_FLAG_ANIME_SetFlag(void *fieldMap);
extern int FIELD_GIMMICK_FLAG_ANIME_GetFlag(void *fieldMap);
extern void *FIELD_GIMMICK_FLAG_ANIME_CreateEvent(struct GameSystem *gameSystem, u32 param);
extern void *FIELD_GIMMICK_BUTTON_STATES_CreateStateEvent(struct GameSystem *gameSystem, u8 param, u32 flag);
extern void *FIELD_GIMMICK_BUTTON_STATES_CreateOneShotEvent(struct GameSystem *gameSystem, u32 param);
extern void *FIELD_GIMMICK_CART_LANES_UnlockLane(struct GameSystem *gameSystem, u16 param);
extern void *FIELD_GIMMICK_PLATE_DOORS_StartPlateEvent(struct GameSystem *gameSystem, int param);
extern void *FIELD_GIMMICK_PLATE_DOORS_StartScriptedEvent(struct GameSystem *gameSystem, int param);
extern void *FIELD_GIMMICK_LIFT_ELEVATOR_CallLiftEvent(struct GameSystem *gameSystem, int param);
extern void *FIELD_GIMMICK_LIFT_ELEVATOR_CallElevatorEvent(struct GameSystem *gameSystem, u32 flag);
extern void *FIELD_GIMMICK_LIFT_CallEvent(struct GameSystem *gameSystem, u32 flag);
extern void FIELD_GIMMICK_LIFT_ELEVATOR_SnapElevatorToTop(struct GameSystem *gameSystem);
extern void FIELD_GIMMICK_LIFT_SnapLiftToBottom(struct GameSystem *gameSystem);
extern void *FIELD_GIMMICK_SWITCH_TOGGLE_StartSecondarySwitchEvent(struct GameSystem *gameSystem, int param);
extern void FIELD_GIMMICK_SWITCH_TOGGLE_ReplacePlayerIfRequirementMet(struct GameSystem *gameSystem, int param);
extern void *FIELD_GIMMICK_PLATE_DOORS_StartDoorEvent(struct GameSystem *gameSystem, int paramA, int paramB);
extern void *FIELD_GIMMICK_ROTATING_ROOM_StartHopEvent(struct GameSystem *gameSystem, int param);
extern void *FIELD_GIMMICK_ROTATING_ROOM_StartLeverEvent(struct GameSystem *gameSystem, int paramA, int paramB);
extern void *FIELD_GIMMICK_ROTATING_ROOM_StartRotateEvent(struct GameSystem *gameSystem, u32 param);

int SCRCMD_FIELD_GIMMICK_CART_LANES_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_CART_LANES_SetState(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_CART_LANES_TransferSound(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_FLAG_ANIME_SetFlag(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_FLAG_ANIME_GetFlag(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_FLAG_ANIME_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_BUTTON_STATES_CallEventWithFlag(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_BUTTON_STATES_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_BUTTON_STATES_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_CART_LANES_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_PLATE_DOORS_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_PLATE_DOORS_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_LIFT_ELEVATOR_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_LIFT_ELEVATOR_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_LIFT_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_LIFT_ELEVATOR_Cleanup(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_LIFT_Cleanup(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_SWITCH_TOGGLE_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_BUTTON_STATES_CallSecondEventU16(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_SWITCH_TOGGLE_SetState(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_PLATE_DOORS_CallCheckEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_ROTATING_ROOM_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_ROTATING_ROOM_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FIELD_GIMMICK_ROTATING_ROOM_CallThirdEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork);

/*
 * The handlers below start a field gimmick overlay event (ov038 to ov046,
 * one entry point each). Most read their parameter from the script, create
 * the event through the overlay and hand it to the script system; they
 * return 1 so the script waits. A null event means nothing to run, so the
 * script still waits one step.
 */

/* Script command: start the ov039 event for a parameter byte. */
int SCRCMD_FIELD_GIMMICK_CART_LANES_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u8 param = VM_GetU16(vm);
    void *event = FIELD_GIMMICK_CART_LANES_CreateSwitchEvent(gameSystem, param);

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: store a value byte in the ov039 gimmick state (slot 2). */
int SCRCMD_FIELD_GIMMICK_CART_LANES_SetState(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u8 value;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    value = VM_GetU16(vm);
    FIELD_GIMMICK_CART_LANES_UnlockLaneFromScript(gameSystem, value);
    return 0;
}

/* Script command: ov039 sound slot transfer (no arguments). */
int SCRCMD_FIELD_GIMMICK_CART_LANES_TransferSound(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    FIELD_GIMMICK_CART_LANES_TransferSound(SCRCMD_WORK_GetGameSystem(cmdWork));
    return 0;
}

/* Script command: set the ov040 gimmick flag of the current map (no arguments). */
int SCRCMD_FIELD_GIMMICK_FLAG_ANIME_SetFlag(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    SCRCMD_WORK_GetScriptWork(cmdWork);
    FIELD_GIMMICK_FLAG_ANIME_SetFlag(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork)));
    return 0;
}

/* Script command: write the ov040 gimmick flag of the current map to a script variable (0 or 1). */
int SCRCMD_FIELD_GIMMICK_FLAG_ANIME_GetFlag(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *fieldMap;
    u16 *result;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    fieldMap = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork));
    result = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    if (FIELD_GIMMICK_FLAG_ANIME_GetFlag(fieldMap) != 0) {
        *result = 1;
    } else {
        *result = 0;
    }
    return 0;
}

/* Script command: start the ov040 event for a parameter byte. */
int SCRCMD_FIELD_GIMMICK_FLAG_ANIME_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u8 param = VM_GetU16(vm);
    void *event = FIELD_GIMMICK_FLAG_ANIME_CreateEvent(gameSystem, param);

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov042 event for a parameter byte with its flag set. */
int SCRCMD_FIELD_GIMMICK_BUTTON_STATES_CallEventWithFlag(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u8 param = VM_GetU16(vm);
    u32 flag = 1;
    void *event = FIELD_GIMMICK_BUTTON_STATES_CreateStateEvent(gameSystem, param, flag);

    if (event == 0) {
        return flag;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return flag;
}

/* Same as SCRCMD_FIELD_GIMMICK_BUTTON_STATES_CallEventWithFlag with the flag clear. */
int SCRCMD_FIELD_GIMMICK_BUTTON_STATES_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u8 param = VM_GetU16(vm);
    void *event = FIELD_GIMMICK_BUTTON_STATES_CreateStateEvent(gameSystem, param, 0);

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov042 second event for a parameter byte. */
int SCRCMD_FIELD_GIMMICK_BUTTON_STATES_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u8 param = VM_GetU16(vm);
    void *event = FIELD_GIMMICK_BUTTON_STATES_CreateOneShotEvent(gameSystem, param);

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov039 second event for a script variable value. */
int SCRCMD_FIELD_GIMMICK_CART_LANES_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = FIELD_GIMMICK_CART_LANES_UnlockLane(gameSystem, *SCRIPT_WORK_ReadWorkPointer(vm, cmdWork));

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov038 event for a script variable value. */
int SCRCMD_FIELD_GIMMICK_PLATE_DOORS_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = FIELD_GIMMICK_PLATE_DOORS_StartPlateEvent(gameSystem, *SCRIPT_WORK_ReadWorkPointer(vm, cmdWork));

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov038 second event for an immediate value. */
int SCRCMD_FIELD_GIMMICK_PLATE_DOORS_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = FIELD_GIMMICK_PLATE_DOORS_StartScriptedEvent(gameSystem, VM_GetU16(vm));

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov043 event for an immediate value. */
int SCRCMD_FIELD_GIMMICK_LIFT_ELEVATOR_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = FIELD_GIMMICK_LIFT_ELEVATOR_CallLiftEvent(gameSystem, VM_GetU16(vm));

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov043 second event; the immediate value is reduced to a flag. */
int SCRCMD_FIELD_GIMMICK_LIFT_ELEVATOR_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = FIELD_GIMMICK_LIFT_ELEVATOR_CallElevatorEvent(gameSystem, VM_GetU16(vm) ? 1 : 0);

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov044 event; the immediate value is reduced to a flag. */
int SCRCMD_FIELD_GIMMICK_LIFT_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = FIELD_GIMMICK_LIFT_CallEvent(gameSystem, VM_GetU16(vm) ? 1 : 0);

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: ov043 cleanup (no arguments). */
int SCRCMD_FIELD_GIMMICK_LIFT_ELEVATOR_Cleanup(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    FIELD_GIMMICK_LIFT_ELEVATOR_SnapElevatorToTop(SCRCMD_WORK_GetGameSystem(cmdWork));
    return 0;
}

/* Script command: ov044 cleanup (no arguments). */
int SCRCMD_FIELD_GIMMICK_LIFT_Cleanup(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    FIELD_GIMMICK_LIFT_SnapLiftToBottom(SCRCMD_WORK_GetGameSystem(cmdWork));
    return 0;
}

/* Script command: start the ov045 event for an immediate value. */
int SCRCMD_FIELD_GIMMICK_SWITCH_TOGGLE_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = FIELD_GIMMICK_SWITCH_TOGGLE_StartSecondarySwitchEvent(gameSystem, VM_GetU16(vm));

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov042 second event for an immediate value. */
int SCRCMD_FIELD_GIMMICK_BUTTON_STATES_CallSecondEventU16(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = FIELD_GIMMICK_BUTTON_STATES_CreateOneShotEvent(gameSystem, VM_GetU16(vm));

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: ov045 state change for an immediate value. */
int SCRCMD_FIELD_GIMMICK_SWITCH_TOGGLE_SetState(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    FIELD_GIMMICK_SWITCH_TOGGLE_ReplacePlayerIfRequirementMet(SCRCMD_WORK_GetGameSystem(cmdWork), VM_GetU16(vm));
    return 0;
}

/* Script command: start the ov038 check event for two immediate values. */
int SCRCMD_FIELD_GIMMICK_PLATE_DOORS_CallCheckEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    int paramA = VM_GetU16(vm);
    int paramB = VM_GetU16(vm);
    void *event = FIELD_GIMMICK_PLATE_DOORS_StartDoorEvent(gameSystem, paramA, paramB);

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov046 event for an immediate value. */
int SCRCMD_FIELD_GIMMICK_ROTATING_ROOM_CallEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = FIELD_GIMMICK_ROTATING_ROOM_StartHopEvent(gameSystem, VM_GetU16(vm));

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov046 second event for two script values. */
int SCRCMD_FIELD_GIMMICK_ROTATING_ROOM_CallSecondEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    int paramA = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int paramB = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    void *event = FIELD_GIMMICK_ROTATING_ROOM_StartLeverEvent(gameSystem, paramA, paramB);

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: start the ov046 third event for a script value. */
int SCRCMD_FIELD_GIMMICK_ROTATING_ROOM_CallThirdEvent(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    void *event = FIELD_GIMMICK_ROTATING_ROOM_StartRotateEvent(gameSystem, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}
