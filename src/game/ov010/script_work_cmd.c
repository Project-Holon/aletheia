/*
 * file:     script_work_cmd.c
 * unit:     yes
 * function: SCRIPT_WORK_CompareValues, SCRIPT_WORK_CmdCompareRegs, SCRIPT_WORK_CmdCompareRegConst, SCRIPT_WORK_CmdCompareWorkConst, SCRIPT_WORK_CmdCompareWorks, SCRIPT_WORK_CmdPushConst, SCRIPT_WORK_CmdPushWorkValue, SCRIPT_WORK_CmdPopToWork, SCRIPT_WORK_CmdPopDiscard, SCRIPT_WORK_CmdAdd, SCRIPT_WORK_CmdSub, SCRIPT_WORK_CmdMul, SCRIPT_WORK_CmdDiv, SCRIPT_WORK_CmdPushEventFlag, SCRIPT_WORK_CmdCompareStack, SCRIPT_WORK_CmdChangeScript, SCRIPT_WORK_WaitChildScript, SCRIPT_WORK_CmdCallScript, SCRIPT_WORK_CmdEnd, SCRIPT_WORK_CmdJump, SCRIPT_WORK_CmdIfJump, SCRIPT_WORK_CmdIfCall, SCRIPT_WORK_CmdSetProcAction, SCRIPT_WORK_CmdGetContinueFlag, SCRIPT_WORK_CmdSetEventFlag, SCRIPT_WORK_CmdResetEventFlag, SCRIPT_WORK_CmdCheckEventFlag, SCRIPT_WORK_CmdAddWork, SCRIPT_WORK_CmdSubWork, SCRIPT_WORK_CmdMulWork, SCRIPT_WORK_CmdDivWork, SCRIPT_WORK_CmdModWork, SCRIPT_WORK_CmdAndWork, SCRIPT_WORK_CmdOrWork, SCRIPT_WORK_CmdLoadWorkConst, SCRIPT_WORK_CmdCopyWork, SCRIPT_WORK_CmdLoadWorkValue, SCRIPT_WORK_CmdCallFieldCommand, SCRIPT_WORK_CmdPopAllBgm, SCRIPT_WORK_CmdCallScriptEvent, SCRIPT_WORK_WaitKeyDecide, SCRIPT_WORK_CmdWaitKeyDecide, SCRIPT_WORK_WaitKeyAny, SCRIPT_WORK_CmdWaitKeyAny, SCRIPT_WORK_WaitReportSave, SCRIPT_WORK_CmdReportSave, SCRIPT_WORK_ReadWorkPointer, SCRIPT_WORK_ReadWorkValue, SCRIPT_WORK_GetPlayerZoneId
 * address:  0x0215932C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Continues script_work.c (script command handlers, VM_* calls).
 * script_work.c ends at 0x021592D8 and script_work_cmd_local.c (0x021592F0..0x0215930C)
 * sits between; this piece starts at 0x0215932C, so the three ranges are
 * contiguous and merge into script_work.c at cut time.
 *
 * symbols:
 *   VM_ReadU16   0x02011330  thumb
 *   VM_PushStack  0x0201137C  thumb
 *   VM_PopStack  0x02011398  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   SCRIPT_SYS_AddScript  0x021589A0  thumb  ov010
 *   SCRCMD_WORK_GetChildScriptIndex  0x0215AA4C  thumb  ov010
 *   SCRIPT_SYS_HasVm  0x021587E0  thumb  ov010
 *   SCRCMD_WORK_RestoreScriptState  0x0215AA34  thumb  ov010
 *   SCRCMD_WORK_SetChildScriptIndex  0x0215AA48  thumb  ov010
 *   SCRCMD_WORK_SaveScriptState  0x0215AA24  thumb  ov010
 *   SCRIPT_SYS_RunScriptNow  0x02158A34  thumb  ov010
 *   VM_SetWait  0x020113D0  thumb
 *   VM_End  0x02011290  thumb
 *   VM_GetU32  0x0201134C  thumb
 *   VM_Jump  0x020113B0  thumb
 *   d_021705DC     0x021705DC  data  ov010
 *   GAME_DATA_GetMoveModelSys   0x02012B38  thumb
 *   FIELD_STATUS_SetProcAction   0x02014474  thumb
 *   FIELD_STATUS_GetContinueFlag  0x02014460  thumb
 *   ZONEDATA_SetEventFlag  0x02014314  thumb
 *   ZONEDATA_ResetEventFlag  0x0201433C  thumb
 *   SCRCMD_FLDMMDL_PauseMmdls  0x021B1BB8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   SCRCMD_FLDMMDL_UnpauseAllMmdls  0x021B1BE8  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_GetPendingBgmStackDepth  0x020288C4  thumb
 *   FIELD_SOUND_SYSTEM_StartPopAllTask  0x0202972C  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_CreateCheckTask 0x02159204 thumb ov010
 *   KEY_GetTrg  0x020362DC  arm
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb
 *   GAME_DATA_IsSaving  0x02012E40  thumb
 *   GAME_DATA_SaveMain  0x02012DD0  thumb
 *   FIELD_SUBSCREEN_GetMode  0x021A0F90  thumb  ov021
 *   FIELD_SUBSCREEN_IsReportSaveAnimDone  0x021A153C  thumb  ov021
 *   FIELD_SUBSCREEN_StopReportSaveAnim  0x021A1548  thumb  ov021
 *   SCRIPT_WORK_GetReturnScriptId  0x021590FC  thumb  ov010
 *   FIELD_SAVEANIME_Stop  0x021D11D8  thumb
 *   FIELD_SAVEANIME_Delete  0x021D1194  thumb
 *   SCRIPT_WORK_SetReturnScriptId  0x021590F4  thumb  ov010
 *   FIELDMAP_GetHeapId  0x02188C84  thumb
 *   FIELD_SAVEANIME_Create  0x021D1164  thumb
 *   FIELD_SAVEANIME_Start  0x021D11B0  thumb
 *   FIELD_SUBSCREEN_PrepareReportSave  0x021A1524  thumb  ov021
 *   FIELD_SUBSCREEN_StartReportSaveAnim  0x021A1530  thumb  ov021
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   RECORD_AddOne  0x02008DF0  thumb
 *   GAME_DATA_SaveStart  0x02012DAC  thumb
 *   SCRIPT_WORK_GetWorkPtr   0x02158FE0  thumb  ov010
 *   SCRIPT_WORK_GetWorkValue   0x0215901C  thumb  ov010
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue   0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetCallMode  0x0215A5D4  thumb  ov010
 *   SCRCMD_WORK_GetCallParam  0x0215A5D8  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   VM_Call  0x020113B4  thumb  arm9
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "../types.h"

struct GameSystem;
struct GameData;
struct FieldMap;
struct FieldMapState;
struct FieldSoundSystem;
struct PlayerWork;
struct EventWork;
struct MoveModelSys;
struct TrainerRecord;
struct ScriptTask;
struct ScrcmdWork;
#include "../arm9/script_vm_types.h"
#include "script_work_types.h"

typedef struct ScrcmdWork ScrcmdWork;

/* Arm9 script VM primitives. */
extern u16 VM_ReadU16(ScriptVm *vm);
struct ScriptVm;
extern u32 VM_GetU32(ScriptVm *vm);
extern void VM_PushStack(ScriptVm *vm, u32 value);
extern u32 VM_PopStack(ScriptVm *vm);
extern struct ScriptVm *VM_End(ScriptVm *vm);
extern void VM_Jump(struct ScriptVm *vm, u8 *pc);
extern void VM_Call(struct ScriptVm *vm, u8 *pc);
extern void VM_SetWait(ScriptVm *vm, int (*waitFn)(ScriptVm *, ScrcmdWork *));

                                     
#include "../arm9/game_data.h"
#include "../arm9/zonedata.h"
struct FieldStatus;
#include "../arm9/field_status.h"
struct FieldStatus;
#include "../arm9/gamesystem.h"
#include "../arm9/field_sound_system.h"
struct GameEvent;
#include "../arm9/key.h"
#include "../arm9/record.h"
struct FieldSubscreen;

                                
#include "../ov021/fieldmap.h"
#include "../ov021/field_subscreen.h"
struct FieldSaveAnime;
#include "../ov021/field_saveanime.h"
#include "../ov021/scrcmd_fldmmdl.h"

/* Script system and script work. */
#ifdef __MWERKS__
extern int SCRIPT_SYS_AddScript(ScriptWork *scriptWork, int zoneId, int scriptId); /* original prototype; the definition differs in pointer type, argument width */
#else
#include "script_sys.h"
#endif
#ifdef __MWERKS__
extern void SCRIPT_SYS_RunScriptNow(void *first, void *second, int scriptId, int callParam); /* original prototype; the definition differs in argument width */
#else
#endif
struct ScriptWork;
#include "script_work.h"

/* Command work accessors. */
#include "scrcmd_work.h"

/* Condition table of the conditional jump and call commands, [condition][compare flag]. */
extern u8 d_021705DC[][3];

int SCRIPT_WORK_CompareValues(unsigned int lhs, unsigned int rhs);
int SCRIPT_WORK_WaitChildScript(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_WaitKeyDecide(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_WaitKeyAny(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_WaitReportSave(ScriptVm *vm, ScrcmdWork *cmdWork);
u16 *SCRIPT_WORK_ReadWorkPointer(ScriptVm *vm, ScrcmdWork *cmdWork);
unsigned short SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRIPT_WORK_GetPlayerZoneId(ScrcmdWork *cmdWork);

int SCRIPT_WORK_CompareValues(unsigned int lhs, unsigned int rhs)
{
    if (lhs < rhs) return 0;
    if (lhs == rhs) return 1;
    return 2;
}

static inline int ReadByte(ScriptVm *vm)
{
    int value = *vm->pc;
    vm->pc++;
    return value;
}

/*
 * extent: two-byte zero alignment padding follows the 46-byte function.
 * lever: inline byte reader binds the load before incrementing the cursor;
 * a postincrement expression schedules the cursor store before the load.
 */
int SCRIPT_WORK_CmdCompareRegs(ScriptVm *vm)
{
    u8 lhs, rhs;
    lhs = vm->ring[ReadByte(vm)];
    rhs = vm->ring[ReadByte(vm)];
    vm->cmpFlag = SCRIPT_WORK_CompareValues(lhs, rhs);
    return 0;
}

int SCRIPT_WORK_CmdCompareRegConst(ScriptVm *vm)
{
    u8 lhs, rhs;
    lhs = vm->ring[ReadByte(vm)];
    rhs = ReadByte(vm);
    vm->cmpFlag = SCRIPT_WORK_CompareValues(lhs, rhs);
    return 0;
}

/*
 * Halfword out of the record the overlay looks up, classified through an
 * arm9 call, and the class byte stored back on the object.
 */
int SCRIPT_WORK_CmdCompareWorkConst(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 workValue = *SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);

    vm->cmpFlag = SCRIPT_WORK_CompareValues(workValue, VM_ReadU16(vm));

    return 0;
}

int SCRIPT_WORK_CmdCompareWorks(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *lhs = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    u16 *rhs = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    vm->cmpFlag = SCRIPT_WORK_CompareValues(*lhs, *rhs);
    return 0;
}

int SCRIPT_WORK_CmdPushConst(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VM_PushStack(vm, VM_ReadU16(vm));
    return 0;
}

int SCRIPT_WORK_CmdPushWorkValue(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VM_PushStack(vm, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

int SCRIPT_WORK_CmdPopToWork(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 value = VM_PopStack(vm);
    u16 *workPtr = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *workPtr = value;
    return 0;
}

int SCRIPT_WORK_CmdPopDiscard(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VM_PopStack(vm);
    return 0;
}

/*
 * One arm9 getter read twice, folded with '+', written back
 * through the arm9 setter.
 */
int SCRIPT_WORK_CmdAdd(ScriptVm *vm)
{
    int top = VM_PopStack(vm);
    int below = VM_PopStack(vm);

    VM_PushStack(vm, below + top);

    return 0;
}

/*
 * One arm9 getter read twice, folded with '-', written back
 * through the arm9 setter.
 */
int SCRIPT_WORK_CmdSub(ScriptVm *vm)
{
    int top = VM_PopStack(vm);
    VM_PushStack(vm, VM_PopStack(vm) - top);
    return 0;
}

/*
 * One arm9 getter read twice, folded with '*', written back
 * through the arm9 setter.
 */
int SCRIPT_WORK_CmdMul(ScriptVm *vm)
{
    int top = VM_PopStack(vm);
    int below = VM_PopStack(vm);
    VM_PushStack(vm, below * top);
    return 0;
}

int SCRIPT_WORK_CmdDiv(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 divisor = VM_PopStack(vm);
    u32 dividend = VM_PopStack(vm);
    VM_PushStack(vm, dividend / divisor);
    return 0;
}

int SCRIPT_WORK_CmdPushEventFlag(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    struct EventWork *eventWork = GAME_DATA_GetEventWork(gameData);
    u32 flagId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    VM_PushStack(vm, ZONEDATA_CheckEventFlag(eventWork, flagId));
    return 0;
}

int SCRIPT_WORK_CmdCompareStack(ScriptVm *vm)
{
    u32 top = VM_PopStack(vm);
    u32 below = VM_PopStack(vm);
    int result;
    switch (VM_ReadU16(vm)) {
    case 0: result = (below < top) ? 1 : 0; break;
    case 1: result = (below == top) ? 1 : 0; break;
    case 2: result = (below > top) ? 1 : 0; break;
    case 3: result = (below <= top) ? 1 : 0; break;
    case 4: result = (below >= top) ? 1 : 0; break;
    case 5: result = (below != top) ? 1 : 0; break;
    case 6: result = (below == 1 || top == 1) ? 1 : 0; break;
    case 7: result = (below == 1 && top == 1) ? 1 : 0; break;
    default: result = 0; break;
    }
    VM_PushStack(vm, result);
    return 0;
}

int SCRIPT_WORK_CmdChangeScript(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    int scriptId;

    SCRCMD_WORK_GetGameSystem(cmdWork);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    scriptId = VM_ReadU16(vm);
    SCRIPT_SYS_AddScript((void *)scriptWork, (s32)(SCRIPT_WORK_GetPlayerZoneId(cmdWork)), scriptId);
    return 1;
}

int SCRIPT_WORK_WaitChildScript(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    if (SCRIPT_SYS_HasVm(scriptWork, SCRCMD_WORK_GetChildScriptIndex(cmdWork)) == 0) {
        SCRCMD_WORK_RestoreScriptState(cmdWork);
        return 1;
    }
    return 0;
}

int SCRIPT_WORK_CmdCallScript(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    int scriptId = VM_ReadU16(vm);
    if (SCRCMD_WORK_GetCallMode(cmdWork) == 0) {
        SCRCMD_WORK_SetChildScriptIndex(cmdWork, SCRIPT_SYS_AddScript((void *)scriptWork, (s32)(SCRIPT_WORK_GetPlayerZoneId(cmdWork)), scriptId));
        SCRCMD_WORK_SaveScriptState(cmdWork);
        VM_SetWait(vm, SCRIPT_WORK_WaitChildScript);
        return 1;
    }
    SCRCMD_WORK_SaveScriptState(cmdWork);
    SCRIPT_SYS_RunScriptNow(gameSystem, scriptWork, (s32)scriptId, SCRCMD_WORK_GetCallParam(cmdWork));
    SCRCMD_WORK_RestoreScriptState(cmdWork);
    return 0;
}

int SCRIPT_WORK_CmdEnd(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    SCRCMD_WORK_GetScriptWork(cmdWork);
    VM_End(vm);
    return 1;
}

int SCRIPT_WORK_CmdJump(ScriptVm *vm)
{
    s32 offset = VM_GetU32(vm);
    VM_Jump(vm, (u8 *)vm->pc + offset);
    return 0;
}

int SCRIPT_WORK_CmdIfJump(ScriptVm *vm)
{
    u8 *pc = vm->pc;
    u8 condition = *pc;
    int offset;
    vm->pc = pc + 1;
    offset = VM_GetU32(vm);
    if (condition == 0xFF) {
        if (VM_PopStack(vm) == 1)
            goto end;
    } else {
        if (d_021705DC[condition][vm->cmpFlag] != 1)
            goto end;
    }
    VM_Jump(vm, (u8 *)(vm->pc + offset));
end:
    return 0;
}

/*
 * prototype: 020113B4's matched ARM9 unit copies the full-word second
 * input unchanged into +0x14; original caller supplies a cursor address.
 * Pointer declaration preserves that payload and matches the fixed flags.
 */
int SCRIPT_WORK_CmdIfCall(ScriptVm *vm)
{
    u8 *pc = vm->pc;
    u8 condition = *pc;
    int offset;
    vm->pc = pc + 1;
    offset = VM_GetU32(vm);
    if (d_021705DC[condition][vm->cmpFlag] == 1)
        VM_Call(vm, (u8 *)(vm->pc + offset));
    return 0;
}

/*
 * The record's arm9 handle and the caller's second argument are the two
 * operands of the arm9 pair call.
 */
int SCRIPT_WORK_CmdSetProcAction(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 action = VM_ReadU16(vm);
    FIELD_STATUS_SetProcAction((void *)(GAME_DATA_GetMoveModelSys(SCRCMD_WORK_GetGameData(cmdWork))), action);
    return 0;
}

int SCRIPT_WORK_CmdGetContinueFlag(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    struct MoveModelSys *moveModelSys = GAME_DATA_GetMoveModelSys(SCRCMD_WORK_GetGameData(cmdWork));
    *workPtr = FIELD_STATUS_GetContinueFlag((struct FieldStatus *)moveModelSys);
    return 0;
}

int SCRIPT_WORK_CmdSetEventFlag(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    struct EventWork *eventWork = GAME_DATA_GetEventWork(gameData);
    int flagId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    ZONEDATA_SetEventFlag(eventWork, flagId);
    return 0;
}

int SCRIPT_WORK_CmdResetEventFlag(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    struct EventWork *eventWork = GAME_DATA_GetEventWork(gameData);
    int flagId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    ZONEDATA_ResetEventFlag(eventWork, flagId);
    return 0;
}

int SCRIPT_WORK_CmdCheckEventFlag(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct EventWork *eventWork = GAME_DATA_GetEventWork(SCRCMD_WORK_GetGameData(cmdWork));
    u32 flagId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    u16 *workPtr = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *workPtr = ZONEDATA_CheckEventFlag(eventWork, flagId);
    return 0;
}

/*
 * extent: two bytes of zero alignment padding at 0x021597CA.
 */
int SCRIPT_WORK_CmdAddWork(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *workPtr = *workPtr + SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    return 0;
}

int SCRIPT_WORK_CmdSubWork(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    u32 value = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    *workPtr = *workPtr - value;
    return 0;
}

/*
 * extent: two bytes of zero alignment padding at 0x0215980A.
 */
int SCRIPT_WORK_CmdMulWork(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *workPtr = *workPtr * SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    return 0;
}

int SCRIPT_WORK_CmdDivWork(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    u32 divisor = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    *workPtr = *workPtr / divisor;
    return 0;
}

/*
 * extent: two bytes of zero alignment padding at 0x02159852.
 * prototype: named runtime helper has opaque combined scalar return;
 * the original and compiled helper arguments are numerator r0, divisor r1.
 * low word is original r0 output, high word is original r1 remainder.
 * The original admits zero divisors. Direct helper call preserves that
 * behavior without expressing undefined C remainder on a zero divisor.
 * Fixed-flag run 1 proves u64 return in r0/r1: high-word extraction emits
 * no shift, and strh r1 immediately follows the original helper call.
 */
int SCRIPT_WORK_CmdModWork(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    u32 divisor = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    *workPtr = *workPtr % divisor;
    return 0;
}

int SCRIPT_WORK_CmdAndWork(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    u32 value = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    *workPtr = value & *workPtr;
    return 0;
}

int SCRIPT_WORK_CmdOrWork(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    u32 value = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    *workPtr = value | *workPtr;
    return 0;
}

int SCRIPT_WORK_CmdLoadWorkConst(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *workPtr = VM_ReadU16(vm);
    return 0;
}

int SCRIPT_WORK_CmdCopyWork(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *dstPtr = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    u16 *srcPtr = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *dstPtr = *srcPtr;
    return 0;
}

int SCRIPT_WORK_CmdLoadWorkValue(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u16 *workPtr = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *workPtr = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    return 0;
}

/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into SCRCMD_FLDMMDL_PauseMmdls, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SCRIPT_WORK_CmdCallFieldCommand.c \
 *       --func SCRIPT_WORK_CmdCallFieldCommand --addr 0x021598E4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int SCRIPT_WORK_CmdCallFieldCommand(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    return SCRCMD_FLDMMDL_PauseMmdls(vm, cmdWork);
}

int SCRIPT_WORK_CmdPopAllBgm(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    int popped = 0;
    SCRCMD_FLDMMDL_UnpauseAllMmdls(cmdWork);
    if (FIELD_SOUND_SYSTEM_GetPendingBgmStackDepth(GAME_DATA_GetBgmInfo(gameData))) {
        SCRIPT_SYS_CallEvent(scriptWork, FIELD_SOUND_SYSTEM_StartPopAllTask(gameSystem, popped));
        popped = 1;
    }
    return popped;
}

/*
 * extent: two bytes of zero alignment padding at 0x0215995E.
 */
int SCRIPT_WORK_CmdCallScriptEvent(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct ScriptTask *task;
    SCRCMD_WORK_GetGameSystem(cmdWork);
    task = SCRIPT_WORK_CreateCheckTask((struct ScriptVm *)cmdWork);
    if (task == 0)
        return 1;
    SCRIPT_SYS_CallEvent(scriptWork, task);
    return 1;
}

int SCRIPT_WORK_WaitKeyDecide(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    if ((KEY_GetTrg() & 3) == 0)
        return 0;
    return 1;
}

int SCRIPT_WORK_CmdWaitKeyDecide(ScriptVm *vm)
{
    VM_SetWait(vm, SCRIPT_WORK_WaitKeyDecide);
    return 1;
}

int SCRIPT_WORK_WaitKeyAny(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    if ((KEY_GetTrg() & 0xf3) == 0)
        return 0;
    return 1;
}

int SCRIPT_WORK_CmdWaitKeyAny(ScriptVm *vm)
{
    VM_SetWait(vm, SCRIPT_WORK_WaitKeyAny);
    return 1;
}

int SCRIPT_WORK_WaitReportSave(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct FieldMapState *mapState;
    int done;
    mapState = (struct FieldMapState *)FIELDMAP_GetSubscreen(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork)));
    if (GAME_DATA_IsSaving(gameData) == 0) {
        done = 1;
        if (FIELD_SUBSCREEN_GetMode((struct FieldSubscreen *)mapState) == 7) {
            if (FIELD_SUBSCREEN_IsReportSaveAnimDone((struct FieldSubscreen *)mapState) == 0)
                done = 0;
        }
    } else {
        switch (GAME_DATA_SaveMain(gameData)) {
        case 0:
        case 1:
            done = 0;
            break;
        case 2:
            *SCRIPT_WORK_ReadWorkPointer(vm, cmdWork) = 1;
            done = 0;
            break;
        case 3:
            *SCRIPT_WORK_ReadWorkPointer(vm, cmdWork) = 0;
            done = 1;
            if (FIELD_SUBSCREEN_GetMode((struct FieldSubscreen *)mapState) == 7)
                FIELD_SUBSCREEN_StopReportSaveAnim((struct FieldSubscreen *)mapState);
            break;
        }
    }
    if (done == 1) {
        int effectHandle = SCRIPT_WORK_GetReturnScriptId(scriptWork);
        FIELD_SAVEANIME_Stop((struct FieldSaveAnime *)effectHandle);
        (struct FieldSaveAnime *)FIELD_SAVEANIME_Delete((struct FieldSaveAnime *)effectHandle);
        SCRIPT_WORK_SetReturnScriptId(scriptWork, 0);
    }
    return done;
}

int SCRIPT_WORK_CmdReportSave(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameData *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    int mapId; sptr effectHandle;
    struct FieldMap *fieldMap;
    struct FieldMapState *mapState;
    fieldMap = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork));
    mapId = FIELDMAP_GetHeapId(fieldMap);
    mapState = (struct FieldMapState *)FIELDMAP_GetSubscreen(fieldMap);
    effectHandle = (sptr)FIELD_SAVEANIME_Create(mapId, fieldMap);
    FIELD_SAVEANIME_Start((struct FieldSaveAnime *)effectHandle);
    if (FIELD_SUBSCREEN_GetMode((struct FieldSubscreen *)mapState) == 7) {
        FIELD_SUBSCREEN_PrepareReportSave((struct FieldSubscreen *)mapState);
        FIELD_SUBSCREEN_StartReportSaveAnim((struct FieldSubscreen *)mapState);
    }
    SCRIPT_WORK_SetReturnScriptId(scriptWork, effectHandle);
    RECORD_AddOne(GAME_DATA_GetTrainerRecord(gameData), 1);
    GAME_DATA_SaveStart(gameData);
    VM_SetWait(vm, SCRIPT_WORK_WaitReportSave);
    return 1;
}

/*
 * Two record lookups on the second argument and a classification of the
 * first, submitted as three arguments.
 */
u16 *SCRIPT_WORK_ReadWorkPointer(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    return SCRIPT_WORK_GetWorkPtr(SCRCMD_WORK_GetScriptWork(cmdWork), gameData, VM_ReadU16(vm));
}

/*
 * Same three-argument submission as its neighbour, aimed at the second
 * overlay handler.
 */
unsigned short SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    return SCRIPT_WORK_GetWorkValue(SCRCMD_WORK_GetScriptWork(cmdWork), gameData, VM_ReadU16(vm));
}

int SCRIPT_WORK_GetPlayerZoneId(ScrcmdWork *cmdWork)
{
    struct PlayerWork *player = GAME_DATA_GetMyPlayerWork(SCRCMD_WORK_GetGameData(cmdWork));
    return GAME_DATA_GetPlayerZoneId(player);
}
