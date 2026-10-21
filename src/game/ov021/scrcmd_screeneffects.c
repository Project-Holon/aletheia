/*
 * file:     scrcmd_screeneffects.c
 * unit:     yes
 * function: SCRCMD_SCREENEFFECTS_StartBrightnessChange, SCRCMD_SCREENEFFECTS_CheckBrightnessDone, SCRCMD_SCREENEFFECTS_CheckScriptEffectDone, SCRCMD_SCREENEFFECTS_StartFieldFadeIn, SCRCMD_SCREENEFFECTS_FadeInSlow, SCRCMD_SCREENEFFECTS_FadeInSlowAgain, SCRCMD_SCREENEFFECTS_FadeOutSlow, SCRCMD_SCREENEFFECTS_FadeInSlowAltScreens, SCRCMD_SCREENEFFECTS_FadeOutSlowAltScreens, SCRCMD_SCREENEFFECTS_FadeInFast, SCRCMD_SCREENEFFECTS_FadeOutFast, SCRCMD_SCREENEFFECTS_FadeInFastAltScreens, SCRCMD_SCREENEFFECTS_FadeOutFastAltScreens, SCRCMD_SCREENEFFECTS_WaitBrightness, SCRCMD_SCREENEFFECTS_WaitScriptEffect, SCRCMD_SCREENEFFECTS_StartRecoveryPartyEvent, SCRCMD_SCREENEFFECTS_StartRecoveryBallsEvent, SCRCMD_SCREENEFFECTS_StartDoorOpen, SCRCMD_SCREENEFFECTS_StartDoorSetOpen, SCRCMD_SCREENEFFECTS_StartDoorClose, SCRCMD_SCREENEFFECTS_GetBuildModelMgr, SCRCMD_SCREENEFFECTS_FindBuildModelEntry, SCRCMD_SCREENEFFECTS_PlayBuildModelAnimPair, SCRCMD_SCREENEFFECTS_PlayBuildModelAnimTwo, SCRCMD_SCREENEFFECTS_SwapBuildModelId, SCRCMD_SCREENEFFECTS_SetBuildModelIndex, SCRCMD_SCREENEFFECTS_CreateBuildModelNode, SCRCMD_SCREENEFFECTS_DeleteBuildModelNode, SCRCMD_SCREENEFFECTS_PlayBuildModelNodeSlotWithSe, SCRCMD_SCREENEFFECTS_PlayBuildModelNodeSlotMode2, SCRCMD_SCREENEFFECTS_PlayBuildModelNodeCurrentMode3, SCRCMD_SCREENEFFECTS_WaitBuildModelNodeAnim, SCRCMD_SCREENEFFECTS_CheckBuildModelNodeAnimDone, SCRCMD_SCREENEFFECTS_CreateFadeTask, SCRCMD_SCREENEFFECTS_StepFadeTask, SCRCMD_SCREENEFFECTS_ShowPlaceName
 * address:  0x021B2830
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from scrcmd_screeneffects.c at 0x021B2830 (lane L135, __FILE__ anchor scrcmd_screeneffects.c at 021B2EBC; brightness, fade and screen effect commands).
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   VM_ReadU16  0x02011330  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   VM_SetWait  0x020113D0  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   FIELDMAP_GetScriptEffectBusy  0x02189A24  thumb  ov021
 *   SCRIPT_WORK_GetEvent  0x02158F50  thumb  ov010
 *   EVENT_RECOVERY_CreatePartyEvent  0x021C0AA0  thumb  ov021
 *   EVENT_RECOVERY_CreateBallsEvent  0x021C0820  thumb  ov021
 *   FIELD_DOOR_ANIME_StartOpen  0x021C978C  thumb  ov021
 *   FIELD_DOOR_ANIME_StartSetOpen  0x021C9828  thumb  ov021
 *   FIELD_DOOR_ANIME_StartClose  0x021C98F4  thumb  ov021
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_GetBuildModel  0x0218DC6C  thumb  ov021
 *   FIELD_BUILDMODEL_GetFirstEntryNearPos  0x0218C654  thumb  ov021
 *   FIELD_BUILDMODEL_PlayEntryAnim  0x0218C69C  thumb  ov021
 *   FIELD_BUILDMODEL_SwapEntryModelId  0x0218C54C  thumb  ov021
 *   FIELD_BUILDMODEL_GetModelIndexOut  0x0218C574  thumb  ov021
 *   FIELD_BUILDMODEL_CreateNodeNearPos  0x0218C7D8  thumb  ov021
 *   FIELD_BUILDMODEL_GetNodeHandle  0x0218BACC  thumb  ov021
 *   FIELD_BUILDMODEL_GetNodeByHandle  0x0218BA98  thumb  ov021
 *   FIELD_BUILDMODEL_DeleteNode  0x0218C860  thumb
 *   FIELD_BUILDMODEL_PlayNodeSlot  0x0218C88C  thumb  ov021
 *   FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry  0x0218C990  thumb  ov021
 *   FIELD_BUILDMODEL_PlayNodeCurrentSlot  0x0218C89C  thumb  ov021
 *   gScrcmdScreeneffectsNodeHandle     0x021EE720  data  a2
 *   FIELD_BUILDMODEL_TryOpenNodeCurrentSlot  0x0218C8D8  thumb  ov021
 *   FIELD_BUILDMODEL_IsNodeSeBusy  0x0218C9A4  thumb  ov021
 *   FIELDMAP_GetTcblSys  0x02188D30  thumb  ov021
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   TCB_AddTask  0x02030DA8  arm
 *   FIELDMAP_SetScriptEffectBusy  0x02189A1C  thumb  ov021
 *   d_021DE14C     0x021DE14C  data  a4
 *   BG_SYS_GetMainVisiblePlanes 0x02043658 arm
 *   FIELDMAP_SetBgMode 0x02188DA0 thumb ov021
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   FIELDMAP_ResetBgAffineShowMsg 0x02188DB0 thumb ov021
 *   TCB_DeleteTask 0x02030EAC arm
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_PLACE_NAME_ForceShowForZone  0x021BC5A0  thumb  ov021
 */

#include "fieldmap_types.h"

#include "../types.h"

struct ScriptVm;
struct ScrcmdWork;
struct ScriptWork;
struct GameSystem;
struct GameData;
struct FieldMap;
struct FieldPlayer;
struct TcbTask;
struct BuildModelMgr;
struct BuildModelEntry;
struct BuildModelNode;

/* Work of the fade task (0x18 bytes); the step is the task state. */
typedef struct FadeEffectTask {
    struct GameSystem *gameSystem;  /* 0x00 */
    struct FieldMap *fieldMap;      /* 0x04 */
    u32 screenSelect;               /* 0x08: 0 fades with mask 3, else mask 12 */
    u32 skipWait;                   /* 0x0C: 1 ends the task right after the fade starts */
    u32 kind;                       /* 0x10: 0 slow in, 1 slow out, 2 fast in, 3 fast out */
    u32 step;                       /* 0x14 */
} FadeEffectTask;

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/gamesystem.h"
#include "../ov010/scrcmd_work.h"
#include "../ov010/script_work_cmd.h"
#include "../ov010/script_sys.h"
struct GameEvent;
#include "event_fieldmap_control.h"
#include "fieldmap.h"
extern u16 VM_ReadU16(struct ScriptVm *vm);
extern void VM_SetWait(struct ScriptVm *vm, int (*waitFunc)(struct ScriptVm *vm, struct ScrcmdWork *cmdWork));
#include "../arm9/game_data.h"
#include "../arm9/gfl_use.h"
#include "../arm9/fade.h"
#include "../ov010/script_work.h"
#include "event_recovery.h"
#include "field_door_anime.h"
struct FieldG3dMapper;
struct BuildModelMan;
#include "field_g3d_mapper.h"
struct BuildModelMan;
#include "field_buildmodel.h"
struct BuildModelSearchArgs;
struct TcbSystem;
struct TcbSystem;
struct TcbTask;
#include "../arm9/bg_sys.h"
#include "../arm9/tcb_list.h"
struct FieldPlaceName;
#include "field_place_name.h"
extern u16 gScrcmdScreeneffectsNodeHandle;
extern u8 d_021DE14C;
int SCRCMD_SCREENEFFECTS_StartBrightnessChange(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_CheckBrightnessDone(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_CheckScriptEffectDone(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_StartFieldFadeIn(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_FadeInSlow(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_FadeInSlowAgain(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_FadeOutSlow(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_FadeInSlowAltScreens(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_FadeOutSlowAltScreens(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_FadeInFast(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_FadeOutFast(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_FadeInFastAltScreens(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_FadeOutFastAltScreens(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_WaitBrightness(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_WaitScriptEffect(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_StartRecoveryPartyEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_StartRecoveryBallsEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_StartDoorOpen(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_StartDoorSetOpen(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_StartDoorClose(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
struct BuildModelMgr *SCRCMD_SCREENEFFECTS_GetBuildModelMgr(struct ScrcmdWork *cmdWork);
struct BuildModelEntry *SCRCMD_SCREENEFFECTS_FindBuildModelEntry(struct BuildModelMgr *mgr, int modelId, int x, int z);
int SCRCMD_SCREENEFFECTS_PlayBuildModelAnimPair(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_PlayBuildModelAnimTwo(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_SwapBuildModelId(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_SetBuildModelIndex(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_CreateBuildModelNode(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_DeleteBuildModelNode(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_PlayBuildModelNodeSlotWithSe(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_PlayBuildModelNodeSlotMode2(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_PlayBuildModelNodeCurrentMode3(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_WaitBuildModelNodeAnim(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SCREENEFFECTS_CheckBuildModelNodeAnimDone(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
void SCRCMD_SCREENEFFECTS_CreateFadeTask(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 kind, u32 screenSelect, u32 skipWait);
void SCRCMD_SCREENEFFECTS_StepFadeTask(struct TcbTask *tcb, FadeEffectTask *task);
int SCRCMD_SCREENEFFECTS_ShowPlaceName(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

/* Script command: change the screen brightness (mask, start level, end level, speed). */
int SCRCMD_SCREENEFFECTS_StartBrightnessChange(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 screenMask = VM_ReadU16(vm);
    u32 startLevel = VM_ReadU16(vm);
    u32 endLevel = VM_ReadU16(vm);
    u32 speed = VM_ReadU16(vm);

    FADE_Start(screenMask, startLevel, endLevel, speed);
    return 0;
}

/* Wait function: finished once the brightness change is no longer active. */
int SCRCMD_SCREENEFFECTS_CheckBrightnessDone(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    if (FADE_IsActive() != 1) {
        return 1;
    }
    return 0;
}

/* Wait function: finished once the field map no longer reports a running script effect. */
int SCRCMD_SCREENEFFECTS_CheckScriptEffectDone(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    if (FIELDMAP_GetScriptEffectBusy(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))) != 1) {
        return 1;
    }
    return 0;
}

/*
 * Script command: start the field fade-in event for the current season.
 *
 * EVENT_FIELDMAP_CONTROL_StartFadeIn reads its last two stack arguments with ldrb, so they are
 * u8 parameters: the narrowing then happens once at the call, scheduled
 * the way the original has it. A (u8) cast at the call site or a u8 local
 * feeding int parameters schedules the zero store after the shift pair.
 * Addresses are Black-image addresses.
 */
int SCRCMD_SCREENEFFECTS_StartFieldFadeIn(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct FieldMap *fieldMap;
    u32 season;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    season = GAME_DATA_GetSeason(gameData);
    SCRIPT_SYS_CallEvent(scriptWork, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 3, 0, 0, season, season));
    return 0;
}

/* Script command: slow fade in. */
int SCRCMD_SCREENEFFECTS_FadeInSlow(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    SCRCMD_SCREENEFFECTS_CreateFadeTask(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem), 0, 0, 0);
    return 0;
}

/* Script command: slow fade in (a second opcode with the same arguments as the one above). */
int SCRCMD_SCREENEFFECTS_FadeInSlowAgain(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    SCRCMD_SCREENEFFECTS_CreateFadeTask(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem), 0, 0, 0);
    return 0;
}

/* Script command: slow fade out. */
int SCRCMD_SCREENEFFECTS_FadeOutSlow(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    SCRCMD_SCREENEFFECTS_CreateFadeTask(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem), 1, 0, 0);
    return 0;
}

/* Script command: slow fade in on the second screen mask. */
int SCRCMD_SCREENEFFECTS_FadeInSlowAltScreens(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    SCRCMD_SCREENEFFECTS_CreateFadeTask(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem), 0, 1, 0);
    return 0;
}

/* Script command: slow fade out on the second screen mask. */
int SCRCMD_SCREENEFFECTS_FadeOutSlowAltScreens(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    SCRCMD_SCREENEFFECTS_CreateFadeTask(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem), 1, 1, 0);
    return 0;
}

/* Script command: fast fade in. */
int SCRCMD_SCREENEFFECTS_FadeInFast(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    SCRCMD_SCREENEFFECTS_CreateFadeTask(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem), 2, 0, 0);
    return 0;
}

/* Script command: fast fade out. */
int SCRCMD_SCREENEFFECTS_FadeOutFast(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    SCRCMD_SCREENEFFECTS_CreateFadeTask(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem), 3, 0, 0);
    return 0;
}

/* Script command: fast fade in on the second screen mask. */
int SCRCMD_SCREENEFFECTS_FadeInFastAltScreens(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    SCRCMD_SCREENEFFECTS_CreateFadeTask(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem), 2, 1, 0);
    return 0;
}

/* Script command: fast fade out on the second screen mask. */
int SCRCMD_SCREENEFFECTS_FadeOutFastAltScreens(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    SCRCMD_SCREENEFFECTS_CreateFadeTask(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem), 3, 1, 0);
    return 0;
}

/* Script command: wait until the brightness change has ended. */
int SCRCMD_SCREENEFFECTS_WaitBrightness(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    VM_SetWait(vm, SCRCMD_SCREENEFFECTS_CheckBrightnessDone);
    return 1;
}

/* Script command: wait until the running script effect has ended. */
int SCRCMD_SCREENEFFECTS_WaitScriptEffect(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    VM_SetWait(vm, SCRCMD_SCREENEFFECTS_CheckScriptEffectDone);
    return 1;
}

/* Script command: start a map effect event on the script's event. */
int SCRCMD_SCREENEFFECTS_StartRecoveryPartyEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);

    SCRIPT_SYS_CallEvent(scriptWork, EVENT_RECOVERY_CreatePartyEvent(gameSystem, SCRIPT_WORK_GetEvent(scriptWork)));
    return 1;
}

/* Script command: start a map effect event that takes one script argument. */
int SCRCMD_SCREENEFFECTS_StartRecoveryBallsEvent(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    int param = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    FIELDMAP_GetFieldPlayer(GAMESYSTEM_GetFieldMap(gameSystem));
    SCRIPT_SYS_CallEvent(scriptWork, EVENT_RECOVERY_CreateBallsEvent(gameSystem, SCRIPT_WORK_GetEvent(scriptWork), (unsigned char)param));
    return 1;
}

/* Script command: start the door open animation. */
int SCRCMD_SCREENEFFECTS_StartDoorOpen(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);

    SCRIPT_SYS_CallEvent((void *)scriptWork, FIELD_DOOR_ANIME_StartOpen(SCRIPT_WORK_GetEvent(scriptWork), gameSystem, fieldMap));
    return 1;
}

/* Script command: start the door "set open" animation (door shown open without playing it). */
int SCRCMD_SCREENEFFECTS_StartDoorSetOpen(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);

    SCRIPT_SYS_CallEvent((void *)scriptWork, FIELD_DOOR_ANIME_StartSetOpen(SCRIPT_WORK_GetEvent(scriptWork), gameSystem, fieldMap));
    return 1;
}

/* Script command: start the door close animation (door id from the script). */
int SCRCMD_SCREENEFFECTS_StartDoorClose(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    int doorId = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    SCRIPT_SYS_CallEvent((void *)scriptWork, FIELD_DOOR_ANIME_StartClose(SCRIPT_WORK_GetEvent(scriptWork), gameSystem, fieldMap, doorId));
    return 1;
}

/* Returns the build model manager of the current field map. */
struct BuildModelMgr *SCRCMD_SCREENEFFECTS_GetBuildModelMgr(struct ScrcmdWork *cmdWork)
{
    return (struct BuildModelMgr *)FIELD_G3D_MAPPER_GetBuildModel(FIELDMAP_GetG3dMapper(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))));
}

/*
 * Finds the build model entry of a model id near a tile position (x and z
 * are whole units, shifted into fx32).
 * Leaf filed for lane S20 (blocker of 021B2C08 and friends).
 *
 * Addresses are Black-image addresses.
 */
struct BuildModelEntry *SCRCMD_SCREENEFFECTS_FindBuildModelEntry(struct BuildModelMgr *mgr, int modelId, int x, int z)
{
    VecFx32 pos;

    pos.x = x << 16;
    pos.y = 0;
    pos.z = z << 16;
    return FIELD_BUILDMODEL_GetFirstEntryNearPos((struct BuildModelMan *)mgr, modelId, &pos);
}

/* Script command: play the two animations (1 and 3) of the build model at a position. */
int SCRCMD_SCREENEFFECTS_PlayBuildModelAnimPair(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int modelId = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int x = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int z = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    struct BuildModelMgr *mgr = SCRCMD_SCREENEFFECTS_GetBuildModelMgr(cmdWork);
    struct BuildModelEntry *entry = SCRCMD_SCREENEFFECTS_FindBuildModelEntry(mgr, modelId, x, z);

    if (entry) {
        FIELD_BUILDMODEL_PlayEntryAnim((struct BuildModelMan *)mgr, entry, 0, 1);
        FIELD_BUILDMODEL_PlayEntryAnim((struct BuildModelMan *)mgr, entry, 0, 3);
    }
    return 0;
}

/* Script command: play animation 2 of the build model at a position. */
int SCRCMD_SCREENEFFECTS_PlayBuildModelAnimTwo(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int modelId = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int x = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int z = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    struct BuildModelMgr *mgr = SCRCMD_SCREENEFFECTS_GetBuildModelMgr(cmdWork);
    struct BuildModelEntry *entry = SCRCMD_SCREENEFFECTS_FindBuildModelEntry(mgr, modelId, x, z);

    if (entry) {
        FIELD_BUILDMODEL_PlayEntryAnim((struct BuildModelMan *)mgr, entry, 0, 2);
    }
    return 0;
}

/* Script command: swap the model id of the build model at a position. */
int SCRCMD_SCREENEFFECTS_SwapBuildModelId(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int modelId = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int x = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int z = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int newModelId = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    struct BuildModelEntry *entry = SCRCMD_SCREENEFFECTS_FindBuildModelEntry(SCRCMD_SCREENEFFECTS_GetBuildModelMgr(cmdWork), modelId, x, z);

    if (entry) {
        FIELD_BUILDMODEL_SwapEntryModelId(entry, newModelId);
    }
    return 0;
}

/* Script command: set the model index of the build model at a position. */
int SCRCMD_SCREENEFFECTS_SetBuildModelIndex(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int modelId = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int x = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int z = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int modelIndex = (int)SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    struct BuildModelMgr *mgr = SCRCMD_SCREENEFFECTS_GetBuildModelMgr(cmdWork);
    struct BuildModelEntry *entry = SCRCMD_SCREENEFFECTS_FindBuildModelEntry(mgr, modelId, x, z);

    if (entry) {
        FIELD_BUILDMODEL_GetModelIndexOut((struct BuildModelMan *)mgr, (struct BuildModelSearchArgs *)entry, modelIndex);
    }
    return 0;
}

/* Script command: create a build model node at a position; its handle goes to a script variable. */
int SCRCMD_SCREENEFFECTS_CreateBuildModelNode(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    unsigned short *handleOut = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    int modelId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int x = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int z = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    struct BuildModelMgr *mgr;
    VecFx32 pos;

    mgr = (struct BuildModelMgr *)FIELD_G3D_MAPPER_GetBuildModel(FIELDMAP_GetG3dMapper(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))));
    pos.x = x << 16;
    pos.y = 0;
    pos.z = z << 16;
    *handleOut = FIELD_BUILDMODEL_GetNodeHandle((struct BuildModelMan *)mgr, FIELD_BUILDMODEL_CreateNodeNearPos((struct BuildModelMan *)mgr, modelId, &pos));
    return 0;
}

/* Script command: delete the build model node of a handle. */
int SCRCMD_SCREENEFFECTS_DeleteBuildModelNode(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 handle = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    struct BuildModelNode *node = FIELD_BUILDMODEL_GetNodeByHandle((struct BuildModelMan *)(SCRCMD_SCREENEFFECTS_GetBuildModelMgr(cmdWork)), handle);

    if (node != 0) {
        FIELD_BUILDMODEL_DeleteNode(node);
    }
    return 0;
}

/* Script command: play a slot of a build model node and the sound effect its kind entry names. */
int SCRCMD_SCREENEFFECTS_PlayBuildModelNodeSlotWithSe(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    unsigned short seNo;
    int handle = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    int slot = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    struct BuildModelNode *node = FIELD_BUILDMODEL_GetNodeByHandle((struct BuildModelMan *)(SCRCMD_SCREENEFFECTS_GetBuildModelMgr(cmdWork)), handle);

    if (node) {
        FIELD_BUILDMODEL_PlayNodeSlot(node, slot, 0);
        if (FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry(node, &seNo)) {
            GFL_USE_PlaySeDefaultVolume(seNo);
        }
    }
    return 0;
}

/* Script command: play a slot of a build model node (mode 2). */
int SCRCMD_SCREENEFFECTS_PlayBuildModelNodeSlotMode2(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 handle = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    u32 slot = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    struct BuildModelNode *node = FIELD_BUILDMODEL_GetNodeByHandle((struct BuildModelMan *)(SCRCMD_SCREENEFFECTS_GetBuildModelMgr(cmdWork)), handle);

    if (node != 0) {
        FIELD_BUILDMODEL_PlayNodeSlot(node, slot, 2);
    }
    return 0;
}

/* Script command: play the current slot of a build model node (mode 3). */
int SCRCMD_SCREENEFFECTS_PlayBuildModelNodeCurrentMode3(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 handle = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    struct BuildModelNode *node = FIELD_BUILDMODEL_GetNodeByHandle((struct BuildModelMan *)(SCRCMD_SCREENEFFECTS_GetBuildModelMgr(cmdWork)), handle);

    if (node != 0) {
        FIELD_BUILDMODEL_PlayNodeCurrentSlot(node, 3);
    }
    return 0;
}

/* Script command: remember a node handle and wait until that node's animation has ended. */
int SCRCMD_SCREENEFFECTS_WaitBuildModelNodeAnim(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    gScrcmdScreeneffectsNodeHandle = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    VM_SetWait(vm, SCRCMD_SCREENEFFECTS_CheckBuildModelNodeAnimDone);
    return 1;
}

/* Wait function of the command above. */
int SCRCMD_SCREENEFFECTS_CheckBuildModelNodeAnimDone(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct BuildModelNode *node = FIELD_BUILDMODEL_GetNodeByHandle((struct BuildModelMan *)(SCRCMD_SCREENEFFECTS_GetBuildModelMgr(cmdWork)), gScrcmdScreeneffectsNodeHandle);

    if (node == 0) {
        return 1;
    }
    if (FIELD_BUILDMODEL_TryOpenNodeCurrentSlot(node) == 0) {
        return 0;
    }
    if (FIELD_BUILDMODEL_IsNodeSeBusy(node) == 0) {
        return 1;
    }
    return 0;
}

/* Creates the fade task: kind 0 slow in, 1 slow out, 2 fast in, 3 fast out. */
void SCRCMD_SCREENEFFECTS_CreateFadeTask(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 kind, u32 screenSelect, u32 skipWait)
{
    struct TcbSystem *tcbSys = FIELDMAP_GetTcblSys(fieldMap);
    FadeEffectTask *task = GFL_HEAP_Alloc(4, 0x18, 1, (const char *)&d_021DE14C, 0x369);

    TCB_AddTask(tcbSys, (TcbFunc)SCRCMD_SCREENEFFECTS_StepFadeTask, task, 0);
    FIELDMAP_SetScriptEffectBusy(fieldMap, 1);
    task->step = 0;
    task->gameSystem = gameSystem;
    task->fieldMap = fieldMap;
    task->screenSelect = screenSelect;
    task->skipWait = skipWait;
    task->kind = kind;
}

/* Fade task step: step 0 starts the brightness change, step 1 waits for it and frees the task. */
void SCRCMD_SCREENEFFECTS_StepFadeTask(struct TcbTask *tcb, FadeEffectTask *task)
{
    int speed;
    int startLevel;
    int endLevel;
    int screenMask;
    int done;
    unsigned int visiblePlanes;

    switch (task->step) {
    case 0:
        if (task->kind <= 1) {
            speed = -1;
        } else {
            speed = 4;
        }
        if (task->kind == 0 || task->kind == 2) {
            startLevel = 16;
            endLevel = 0;
            visiblePlanes = BG_SYS_GetMainVisiblePlanes();
            FIELDMAP_SetBgMode();
            BG_SYS_SetMainVisiblePlanes(visiblePlanes);
            FIELDMAP_ResetBgAffineShowMsg(task->fieldMap);
        } else {
            startLevel = 0;
            endLevel = 16;
        }
        if (task->screenSelect == 0) {
            screenMask = 3;
        } else {
            screenMask = 12;
        }
        FADE_Start(screenMask, startLevel, endLevel, speed);
        task->step = task->step + 1;
        break;
    case 1:
        done = 0;
        if (task->skipWait == 1) {
            done = 1;
        }
        if (FADE_IsActive() == 0) {
            done = 1;
        }
        if (done) {
            FIELDMAP_SetScriptEffectBusy(task->fieldMap, 0);
            TCB_DeleteTask((struct TcbTask *)tcb);
            GFL_HEAP_Free(task);
        }
        break;
    }
}

/* Script command: force the place name banner of the current zone to show. */
int SCRCMD_SCREENEFFECTS_ShowPlaceName(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork));
    void *placeName = FIELDMAP_GetPlaceName(fieldMap);

    FIELD_PLACE_NAME_ForceShowForZone(placeName, FIELDMAP_GetZoneId(fieldMap));
    return 0;
}
