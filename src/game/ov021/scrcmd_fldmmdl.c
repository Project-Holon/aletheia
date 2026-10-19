/*
 * file:     scrcmd_fldmmdl.c
 * unit:     yes
 * function: SCRCMD_FLDMMDL_GetMmdlByScriptId, SCRCMD_FLDMMDL_StartMmdlAnime, SCRCMD_FLDMMDL_CheckAnimeTasksDone, SCRCMD_FLDMMDL_WaitAnimeTasks, SCRCMD_FLDMMDL_GetMmdlMoveCode, SCRCMD_FLDMMDL_ChangeMmdlMoveCode, SCRCMD_FLDMMDL_GetMmdlGridPos, SCRCMD_FLDMMDL_GetPlayerGridPos, SCRCMD_FLDMMDL_GetPlayerDir, SCRCMD_FLDMMDL_AddMmdl, SCRCMD_FLDMMDL_DeleteMmdl, SCRCMD_FLDMMDL_AddPartyFollowerMmdl, SCRCMD_FLDMMDL_InitMmdlGridPosition, SCRCMD_FLDMMDL_GetMmdlEventFlag, SCRCMD_FLDMMDL_GetMmdlParam, SCRCMD_FLDMMDL_SetMmdlZoneDeleteOff, SCRCMD_FLDMMDL_CheckMmdlPauseRelease, SCRCMD_FLDMMDL_PauseMmdlsReleaseActive, SCRCMD_FLDMMDL_PauseMmdls, SCRCMD_FLDMMDL_UnpauseAllMmdls, SCRCMD_FLDMMDL_TurnTargetMmdlToPlayer, SCRCMD_FLDMMDL_SearchMmdlAtGrid, SCRCMD_FLDMMDL_SearchMmdlInFrontOfPlayer, SCRCMD_FLDMMDL_CheckPlayerFormChangeDone, SCRCMD_FLDMMDL_StartPlayerFormChangeAndWait, SCRCMD_FLDMMDL_StartPlayerPosOffsetTween, SCRCMD_FLDMMDL_StartPlayerOffsetTaskAgain, SCRCMD_FLDMMDL_GetPlayerMmdl, SCRCMD_FLDMMDL_TurnPlayerToFrontEvent, SCRCMD_FLDMMDL_GetPlayerForm, SCRCMD_FLDMMDL_StartMmdlMoveToGrid, SCRCMD_FLDMMDL_CheckPlayerFormModel, SCRCMD_FLDMMDL_GetPlayerRailLocation, SCRCMD_FLDMMDL_GetMmdlRailLocation, SCRCMD_FLDMMDL_StartMmdlRailSlipDown, SCRCMD_FLDMMDL_SetPlayerRailLocation, SCRCMD_FLDMMDL_SetMmdlRailLocation, SCRCMD_FLDMMDL_StartMmdlSpinRise, SCRCMD_FLDMMDL_StartMmdlDropIn
 * address:  0x021B1668
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from scrcmd_screeneffects.c at 0x021B1668 (lane L135, map model (NPC) and field effect command handlers; original unknown).
 *
 * symbols:
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_ChangeMoveCode  0x0216E0E8  thumb  ov010
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   VM_ReadU16  0x02011330  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   VM_SetWait  0x020113D0  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   SCRIPT_WORK_GetTargetObj  0x02158F90  thumb  ov010
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLDMMDL_SysSearchMoveCode  0x0216DE54  thumb  ov010
 *   VM_GetU32  0x0201134C  thumb
 *   FLDMMDL_ACMD_ListCreate  0x02197D3C  thumb  ov021
 *   SCRCMD_WORK_AddAnimeTask  0x0215A6DC  thumb  ov010
 *   SCRCMD_WORK_CheckAnimeTasks  0x0215A6FC  thumb  ov010
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 *   FLDMMDL_GetRealObjCode  0x0216E3D0  thumb  ov010
 *   FLDMMDL_AddMmdlParam  0x0216CE6C  thumb  ov010
 *   FLDMMDL_OnMoveBitMovePause  0x0216DAF8  thumb  ov010
 *   FLDMMDL_DeleteMmdl  0x0216CF2C  thumb  ov010
 *   EVENTDATA_SYSTEM_GetNpcCount  0x02162744  thumb  ov010
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   EVENTDATA_SYSTEM_GetNpcHeaders  0x02162740  thumb  ov010
 *   FLDMMDL_AddMmdlHeaderById  0x0216CEE4  thumb  ov010
 *   FLDMMDL_InitGridPosition  0x0216E084  thumb  ov010
 *   FLDMMDL_GetEventFlag  0x0216D5B0  thumb  ov010
 *   FLDMMDL_GetParam  0x0216D63C  thumb  ov010
 *   FLDMMDL_SetStatusBitZoneDeleteOff  0x0216DB80  thumb  ov010
 *   FLDMMDL_CheckMoveBitMove  0x0216DA5C  thumb  ov010
 *   FLDMMDL_MOVE_FindFellow  0x0219BBA4  thumb  ov021
 *   gScrcmdFldmmdlPauseFlags     0x021EE71C  data  a1
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_OffMoveBitMovePause  0x0216DB04  thumb  ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   FLDMMDL_MOVE_GetDirTableValue  0x021642A4  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysSearchGridPosHeight  0x0216DDDC  thumb  ov010
 *   FIELD_PLAYER_SearchFrontMmdlHeight  0x021A32A8  thumb  ov021
 *   FIELD_PLAYER_StepFormChange  0x021A2F54  thumb  ov021
 *   FIELD_PLAYER_StartFormChange  0x021A2F48  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_TASK_CreateMmdlPosOffsetTween  0x021C78DC  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb  ov010
 *   EVENTDATA_SYSTEM_SearchPosEvent  0x021627C8  thumb  ov010
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   EVENT_FIELD_PROCLINK_CreateObjAnimEvent  0x021618A0  thumb  ov010
 *   gScrcmdFldmmdlFacingCodes     0x021D93FC  data   a2
 *   gScrcmdFldmmdlTurnRightAcmdList     0x021D9404  data   a4
 *   gScrcmdFldmmdlTurnLeftAcmdList     0x021D940C  data   a4
 *   gScrcmdFldmmdlTurnDownAcmdList     0x021D9414  data   a4
 *   gScrcmdFldmmdlTurnUpAcmdList     0x021D941C  data   a4
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb  ov021
 *   EVENT_FIELD_PROCLINK_CreateHopEvent  0x02161AC0  thumb  ov010
 *   FIELD_PLAYER_CheckFormModel  0x021A3238  thumb  ov021
 *   FLDMMDL_RAIL_GetRailWork  0x0219E348  thumb  ov021
 *   FIELD_RAIL_WORK_GetLocationParts  0x021B83FC  thumb  ov021
 *   RAIL_SLIPDOWN_Start  0x021C474C  thumb  ov021
 *   FIELD_RAIL_WORK_SetLineLocation  0x021B8484  thumb  ov021
 *   FIELD_RAIL_WORK_GetLocation  0x021B7DC0  thumb  ov021
 *   FLDMMDL_RAIL_SetLocation  0x0219E2C0  thumb  ov021
 *   FIELD_TASK_CreateMmdlDrawOffsetTween  0x021C7878  thumb  ov021
 *   FIELD_TASK_CreateMmdlSpinLinear  0x021C7220  thumb  ov021
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FIELD_TASK_CreatePlayerDrop  0x021C7684  thumb  ov021
 *   gScrcmdFldmmdlDropInDrawOffset     0x021D9424  data   a4
 */
#include "fieldmap_types.h"
#include "fldmmdl_rail_types.h"
#include "../ov010/fldmmdl_types.h"
#include "../ov010/script_work_types.h"

#include "../types.h"

typedef struct ScrcmdWork ScrcmdWork;
typedef struct GameData GameData;
typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
typedef struct EventDataSystem EventDataSystem;
typedef struct EventWork EventWork;
typedef struct EventRec EventRec;
typedef struct PlayerWork PlayerWork;
typedef struct FieldPlayer FieldPlayer;
typedef struct FieldTask FieldTask;
typedef struct FieldTaskManager FieldTaskManager;
typedef struct RailWork RailWork;
typedef struct AnimeTask AnimeTask;

/* Bits of the pause flags: models released from the script pause that the wait function pauses again. */
#define FLDMMDL_PAUSE_FLAG_PLAYER        0x01
#define FLDMMDL_PAUSE_FLAG_MOVE_CODE_30  0x02
#define FLDMMDL_PAUSE_FLAG_TARGET        0x04
#define FLDMMDL_PAUSE_FLAG_PARTNER       0x08

extern MmdlSys *SCRCMD_WORK_GetOccupyInfo(ScrcmdWork *cmdWork);
extern ScriptWork *SCRCMD_WORK_GetScriptWork(ScrcmdWork *cmdWork);
extern GameSystem *SCRCMD_WORK_GetGameSystem(ScrcmdWork *cmdWork);
extern GameData *SCRCMD_WORK_GetGameData(ScrcmdWork *cmdWork);
extern ScriptFieldParam *SCRIPT_WORK_ResetFieldParam(ScriptWork *scriptWork);
struct ScriptWork;
extern void *SCRIPT_WORK_GetTargetObj(ScriptWork *scriptWork);
extern void SCRIPT_SYS_CallEvent(void *scriptWork, void *task);
struct ScriptVm;
extern unsigned int SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, ScrcmdWork *cmdWork);
extern u16 *SCRIPT_WORK_ReadWorkPointer(ScriptVm *vm, ScrcmdWork *cmdWork);
extern void SCRCMD_WORK_AddAnimeTask(ScrcmdWork *cmdWork, AnimeTask *animeTask);
extern u32 SCRCMD_WORK_CheckAnimeTasks(ScrcmdWork *cmdWork);
extern u16 VM_ReadU16(ScriptVm *vm);
extern u32 VM_GetU32(ScriptVm *vm);
extern void VM_SetWait(ScriptVm *vm, int (*waitFunc)(ScriptVm *vm, ScrcmdWork *cmdWork));
extern void *GAMESYSTEM_GetFieldMap(GameSystem *gameSystem);
extern void *GAME_DATA_GetEventData(const GameData *gameData);
extern void *GAME_DATA_GetEventWork(const GameData *gameData);
extern PlayerWork *GAME_DATA_GetMyPlayerWork(const GameData *gameData);
extern u16 GAME_DATA_GetPlayerZoneId(const PlayerWork *playerWork);
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);
extern int FLDMMDL_GetGridNowX(Mmdl *mmdl);
extern int FLDMMDL_GetGridNowZ(Mmdl *mmdl);
extern u16 FLDMMDL_GetDirDisp(Mmdl *mmdl);
extern int FLDMMDL_CheckEndAcmd(Mmdl *mmdl);
extern void FLDMMDL_ChangeMoveCode(Mmdl *mmdl, int moveCode);
extern u16 FLDMMDL_GetObjId(Mmdl *mmdl);
extern u16 FLDMMDL_GetMoveCode(Mmdl *mmdl);
extern u32 FLDMMDL_GetRealObjCode(void *evWork, u32 objCode);
extern Mmdl *FLDMMDL_AddMmdlParam(MmdlSys *sys, s16 gridX, s16 gridZ, int dir, int objId, int objCode, int moveCode, int zoneId);
struct MmdlHeader;
struct MmdlSys;
struct Mmdl;
extern Mmdl *FLDMMDL_AddMmdlHeaderById(struct MmdlSys *sys, struct MmdlHeader *header, s32 zoneId, s32 count, void *evWork, u32 objId);
extern void FLDMMDL_OnMoveBitMovePause(Mmdl *mmdl);
extern void FLDMMDL_DeleteMmdl(Mmdl *mmdl);
extern void FLDMMDL_InitGridPosition(Mmdl *mmdl, s16 gridX, s16 gridY, s16 gridZ, u32 dir);
extern u16 FLDMMDL_GetEventFlag(Mmdl *mmdl);
extern int FLDMMDL_GetParam(Mmdl *mmdl, int no);
extern void FLDMMDL_SetStatusBitZoneDeleteOff(Mmdl *mmdl, int flag);
extern int FLDMMDL_CheckMoveBitMove(Mmdl *mmdl);
extern void FLDMMDL_SysPauseMove(MmdlSys *sys);
extern void FLDMMDL_OffMoveBitMovePause(Mmdl *mmdl);
extern void FLDMMDL_SysResumeMove(MmdlSys *sys);
extern void FLDMMDL_SetDirDispCheckPause(Mmdl *mmdl, int dir);
extern void FLDMMDL_SetDrawStatus(Mmdl *mmdl, u16 drawStatus);
extern Mmdl *FLDMMDL_SysSearchGridPosHeight(MmdlSys *sys, u32 gridX, u32 gridZ, s32 posY, s32 range, u32 flag);
extern Mmdl *FLDMMDL_SysSearchMoveCode(MmdlSys *sys, u32 moveCode);
extern Mmdl *FLDMMDL_SysSearchObjId(MmdlSys *sys, u32 objId);
extern Mmdl *FLDMMDL_SysSearchPlayer(MmdlSys *sys);
struct MmdlVec;
extern void FLDMMDL_GetPos(struct Mmdl *mmdl, struct MmdlVec *out);
extern void FLDMMDL_SetPos(struct Mmdl *mmdl, struct MmdlVec *pos);
extern void FLDMMDL_SetDrawOffset(struct Mmdl *mmdl, struct MmdlVec *offset);
extern int FLDMMDL_MOVE_GetMapHeight(Mmdl *mmdl, VecFx32 *pos, int *outHeight);
extern u16 FLDMMDL_MOVE_GetDirTableValue(int index);
extern u16 EVENTDATA_SYSTEM_GetNpcCount(EventDataSystem *eventData);
extern unsigned int EVENTDATA_SYSTEM_GetNpcHeaders(EventDataSystem *eventData);
extern EventRec *EVENTDATA_SYSTEM_SearchPosEvent(struct EventDataSystem *system, void *eventWork, int *pos, int mode);
extern GameEvent *EVENT_FIELD_PROCLINK_CreateObjAnimEvent(struct GameSystem *gameSystem, void *source, int fieldObjectId, char *animName);
extern GameEvent *EVENT_FIELD_PROCLINK_CreateHopEvent(struct GameSystem *gameSystem, void *object, VecFx32 *start, VecFx32 *target);
extern u16 FIELDMAP_GetZoneId(FieldMap *fieldMap);
extern MmdlSys *FIELDMAP_GetMmdlSys(FieldMap *fieldMap);
extern FieldPlayer *FIELDMAP_GetFieldPlayer(FieldMap *fieldMap);
extern FieldTaskManager *FIELDMAP_GetTaskManager(FieldMap *fieldMap);
extern AnimeTask *FLDMMDL_ACMD_ListCreate(Mmdl *mmdl, const void *acmdList);
extern Mmdl *FLDMMDL_MOVE_FindFellow(Mmdl *mmdl);
extern RailWork *FLDMMDL_RAIL_GetRailWork(Mmdl *mmdl);
extern void FLDMMDL_RAIL_SetLocation(Mmdl *mmdl, RailLocation *location);
extern Mmdl *FIELD_PLAYER_GetMmdl(FieldPlayer *player);
extern void FIELD_PLAYER_GetPos(FieldPlayer *player, VecFx32 *outPos);
extern void FIELD_PLAYER_StartFormChange(FieldPlayer *player, u32 code);
extern int FIELD_PLAYER_StepFormChange(FieldPlayer *player);
extern u16 FIELD_PLAYER_GetDirDisp(FieldPlayer *player);
extern u32 FIELD_PLAYER_GetFormCode(FieldPlayer *player);
extern int FIELD_PLAYER_CheckFormModel(FieldPlayer *player);
extern Mmdl *FIELD_PLAYER_SearchFrontMmdlHeight(FieldPlayer *player, u32 limit);
extern void FIELD_RAIL_WORK_GetLocationParts(RailWork *work, u16 *outRailIndex, u16 *outLineGrid, u16 *outWidthGrid);
extern void FIELD_RAIL_WORK_SetLineLocation(RailWork *work, u32 railIndex, u32 lineGrid, int widthPos);
extern void FIELD_RAIL_WORK_GetLocation(RailWork *work, RailLocation *outLocation);
extern void *RAIL_SLIPDOWN_Start(void *a, unsigned int b, unsigned int c);
extern FieldTask *FIELD_TASK_CreateMmdlPosOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset, Mmdl *mmdl);
extern FieldTask *FIELD_TASK_CreateMmdlDrawOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset, Mmdl *mmdl);
extern FieldTask *FIELD_TASK_CreateMmdlSpinLinear(FieldMap *fieldMap, u16 frames, int spins, Mmdl *mmdl);
extern FieldTask *FIELD_TASK_CreatePlayerDrop(FieldMap *fieldMap, Mmdl *mmdl, int frames, int height);
extern void FIELD_TASK_MANAGER_AddTask(FieldTaskManager *manager, FieldTask *task, FieldTask *prerequisite);

/* Four player facing codes, tried in order by the turn-to-event command. */
typedef struct FacingCodes {
    u16 codes[4];
} FacingCodes;

extern u8 gScrcmdFldmmdlPauseFlags;           /* pause flags */
extern FacingCodes gScrcmdFldmmdlFacingCodes;  /* facing codes */
extern u8 gScrcmdFldmmdlTurnRightAcmdList[];         /* acmd list: turn right */
extern u8 gScrcmdFldmmdlTurnLeftAcmdList[];         /* acmd list: turn left */
extern u8 gScrcmdFldmmdlTurnDownAcmdList[];         /* acmd list: turn down */
extern u8 gScrcmdFldmmdlTurnUpAcmdList[];         /* acmd list: turn up */
extern const VecFx32 gScrcmdFldmmdlDropInDrawOffset; /* draw offset of a dropped-in model */

Mmdl *SCRCMD_FLDMMDL_GetMmdlByScriptId(ScrcmdWork *cmdWork, u32 objId);
int SCRCMD_FLDMMDL_StartMmdlAnime(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_CheckAnimeTasksDone(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_WaitAnimeTasks(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_GetMmdlMoveCode(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_ChangeMmdlMoveCode(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_GetMmdlGridPos(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_GetPlayerGridPos(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_GetPlayerDir(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_AddMmdl(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_DeleteMmdl(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_AddPartyFollowerMmdl(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_InitMmdlGridPosition(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_GetMmdlEventFlag(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_GetMmdlParam(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_SetMmdlZoneDeleteOff(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_CheckMmdlPauseRelease(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_PauseMmdlsReleaseActive(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_PauseMmdls(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_FLDMMDL_UnpauseAllMmdls(ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_TurnTargetMmdlToPlayer(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_SearchMmdlAtGrid(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_SearchMmdlInFrontOfPlayer(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_CheckPlayerFormChangeDone(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_StartPlayerFormChangeAndWait(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_StartPlayerPosOffsetTween(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_StartPlayerOffsetTaskAgain(ScriptVm *vm, ScrcmdWork *cmdWork);
Mmdl *SCRCMD_FLDMMDL_GetPlayerMmdl(ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_TurnPlayerToFrontEvent(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_GetPlayerForm(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_StartMmdlMoveToGrid(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_CheckPlayerFormModel(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_GetPlayerRailLocation(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_GetMmdlRailLocation(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_StartMmdlRailSlipDown(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_SetPlayerRailLocation(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_SetMmdlRailLocation(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_StartMmdlSpinRise(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_FLDMMDL_StartMmdlDropIn(ScriptVm *vm, ScrcmdWork *cmdWork);

/*
 * Finds the model a script names: 0xF2 is the model with move code 0x30.
 * For 0xF1 (talk target) the original returns the result variable unset.
 */
Mmdl *SCRCMD_FLDMMDL_GetMmdlByScriptId(ScrcmdWork *cmdWork, u32 objId)
{
    MmdlSys *mmdlSys;
    Mmdl *mmdl;

    mmdlSys = SCRCMD_WORK_GetOccupyInfo(cmdWork);
    if (objId == 0xf2) {
        mmdl = FLDMMDL_SysSearchMoveCode(mmdlSys, 0x30);
    } else if (objId == 0xf1) {
        SCRCMD_WORK_GetScriptWork(cmdWork);
    } else {
        mmdl = FLDMMDL_SysSearchObjId(mmdlSys, objId);
    }
    return mmdl;
}

/* Script command: run a movement command list on a model (list at a script offset). */
int SCRCMD_FLDMMDL_StartMmdlAnime(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    int objId;
    int listOffset;
    Mmdl *mmdl;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    listOffset = VM_GetU32(vm);
    mmdl = SCRCMD_FLDMMDL_GetMmdlByScriptId(cmdWork, objId);
    if (mmdl == 0) {
        return 0;
    }
    SCRCMD_WORK_AddAnimeTask(cmdWork, FLDMMDL_ACMD_ListCreate(mmdl, vm->pc + listOffset));
    return 0;
}

/* Wait function: ends when every running movement command list is done. */
int SCRCMD_FLDMMDL_CheckAnimeTasksDone(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    if (SCRCMD_WORK_CheckAnimeTasks(cmdWork) == 0) {
        return 1;
    }
    return 0;
}

/* Script command: wait for the running movement command lists. */
int SCRCMD_FLDMMDL_WaitAnimeTasks(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VM_SetWait(vm, SCRCMD_FLDMMDL_CheckAnimeTasksDone);
    return 1;
}

/* Script command: read the move code of a model into a script variable. */
int SCRCMD_FLDMMDL_GetMmdlMoveCode(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    MmdlSys *mmdlSys = SCRCMD_WORK_GetOccupyInfo(cmdWork);
    u16 *moveCodeVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);

    *moveCodeVar = 0;
    *moveCodeVar = FLDMMDL_GetMoveCode(FLDMMDL_SysSearchObjId(mmdlSys, SCRIPT_WORK_ReadWorkValue(vm, cmdWork)));
    return 0;
}

/* Script command: change the move code of a model. */
int SCRCMD_FLDMMDL_ChangeMmdlMoveCode(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    MmdlSys *mmdlSys = SCRCMD_WORK_GetOccupyInfo(cmdWork);
    u32 objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    u32 moveCode = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    FLDMMDL_ChangeMoveCode(FLDMMDL_SysSearchObjId(mmdlSys, objId), moveCode);
    return 0;
}

/* Script command: read the grid position of a model into two script variables. */
int SCRCMD_FLDMMDL_GetMmdlGridPos(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    MmdlSys *mmdlSys;
    Mmdl *mmdl;
    u16 *gridXVar;
    u16 *gridZVar;

    mmdlSys = SCRCMD_WORK_GetOccupyInfo(cmdWork);
    mmdl = FLDMMDL_SysSearchObjId(mmdlSys, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    gridXVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    gridZVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *gridXVar = FLDMMDL_GetGridNowX(mmdl);
    *gridZVar = FLDMMDL_GetGridNowZ(mmdl);
    return 0;
}

/* Script command: read the grid position of the player into two script variables. */
int SCRCMD_FLDMMDL_GetPlayerGridPos(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    Mmdl *playerMmdl;
    u16 *gridXVar;
    u16 *gridZVar;

    playerMmdl = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork))->fieldSystem));
    gridXVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    gridZVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *gridXVar = FLDMMDL_GetGridNowX(playerMmdl);
    *gridZVar = FLDMMDL_GetGridNowZ(playerMmdl);
    return 0;
}

/* Script command: read the displayed direction of the player into a script variable. */
int SCRCMD_FLDMMDL_GetPlayerDir(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    Mmdl *playerMmdl = SCRCMD_FLDMMDL_GetPlayerMmdl(cmdWork);
    u16 *dirVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);

    *dirVar = FLDMMDL_GetDirDisp(playerMmdl);
    return 0;
}

/* Script command: add a model at a grid position (object id, sprite, move code from the script). */
int SCRCMD_FLDMMDL_AddMmdl(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptFieldParam *fieldParam;
    int gridX;
    int gridZ;
    int dir;
    int objId;
    int spriteId;
    int moveCode;
    int zoneId;
    MmdlSys *mmdlSys;
    int objCode;
    Mmdl *mmdl;

    fieldParam = SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork));
    gridX = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    gridZ = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    dir = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    spriteId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    moveCode = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    zoneId = FIELDMAP_GetZoneId(fieldParam->fieldSystem);
    mmdlSys = SCRCMD_WORK_GetOccupyInfo(cmdWork);
    objCode = FLDMMDL_GetRealObjCode(GAME_DATA_GetEventWork(SCRCMD_WORK_GetGameData(cmdWork)), spriteId);
    mmdl = FLDMMDL_AddMmdlParam(mmdlSys, gridX, gridZ, dir, objId, objCode, moveCode, zoneId);
    if (mmdl != 0) {
        FLDMMDL_OnMoveBitMovePause(mmdl);
    }
    return 0;
}

/* Script command: delete a model. */
int SCRCMD_FLDMMDL_DeleteMmdl(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    MmdlSys *mmdlSys = SCRCMD_WORK_GetOccupyInfo(cmdWork);
    Mmdl *mmdl = FLDMMDL_SysSearchObjId(mmdlSys, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));

    if (mmdl != 0) {
        FLDMMDL_DeleteMmdl(mmdl);
    }
    return 0;
}

/* Script command: add the model of the party follower (header from the event data). */
int SCRCMD_FLDMMDL_AddPartyFollowerMmdl(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameData *gameData;
    MmdlSys *mmdlSys;
    EventDataSystem *eventData;
    int count;
    int zoneId;
    int objId;
    EventWork *eventWork;
    Mmdl *mmdl;

    mmdlSys = SCRCMD_WORK_GetOccupyInfo(cmdWork);
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    eventData = GAME_DATA_GetEventData(gameData);
    count = EVENTDATA_SYSTEM_GetNpcCount(eventData);
    zoneId = GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(gameData));
    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    if (count != 0) {
        eventWork = GAME_DATA_GetEventWork(gameData);
        mmdl = FLDMMDL_AddMmdlHeaderById(mmdlSys, (struct MmdlHeader *)EVENTDATA_SYSTEM_GetNpcHeaders(eventData), zoneId, count, eventWork, objId);
        if (mmdl != 0) {
            FLDMMDL_OnMoveBitMovePause(mmdl);
        }
    }
    return 0;
}

/* Script command: set the grid position and direction of a model. */
int SCRCMD_FLDMMDL_InitMmdlGridPosition(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    int objId;
    s16 gridX;
    s16 gridY;
    s16 gridZ;
    int dir;
    Mmdl *mmdl;

    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    gridX = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    gridY = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    gridZ = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    dir = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    mmdl = FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetOccupyInfo(cmdWork), objId);
    if (mmdl) {
        FLDMMDL_InitGridPosition(mmdl, gridX, gridY, gridZ, dir);
    }
    return 0;
}

/* Script command: read the event flag of a model into a script variable. */
int SCRCMD_FLDMMDL_GetMmdlEventFlag(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    u16 *eventFlagVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    Mmdl *mmdl = FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetOccupyInfo(cmdWork), objId);

    if (mmdl != 0) {
        *eventFlagVar = FLDMMDL_GetEventFlag(mmdl);
    }
    return 0;
}

/* Script command: read parameter 0..2 of a model into a script variable. */
int SCRCMD_FLDMMDL_GetMmdlParam(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    int objId;
    unsigned int paramIndex;
    u16 *paramVar;
    Mmdl *mmdl;

    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    paramIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    paramVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    mmdl = FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetOccupyInfo(cmdWork), objId);
    if (paramIndex <= 2 && mmdl != 0) {
        *paramVar = FLDMMDL_GetParam(mmdl, paramIndex);
    }
    return 0;
}

/* Script command: keep a model when the zone changes. */
int SCRCMD_FLDMMDL_SetMmdlZoneDeleteOff(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    Mmdl *mmdl = FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetOccupyInfo(cmdWork), objId);

    if (mmdl != 0) {
        FLDMMDL_SetStatusBitZoneDeleteOff(mmdl, 1);
    }
    return 0;
}

/* Wait function: pauses again each model released by the pause command once it is idle. */
int SCRCMD_FLDMMDL_CheckMmdlPauseRelease(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    Mmdl *targetMmdl;
    Mmdl *playerMmdl;
    Mmdl *moveCode30Mmdl;
    Mmdl *partnerMmdl;
    MmdlSys *mmdlSys;

    targetMmdl = SCRIPT_WORK_GetTargetObj(SCRCMD_WORK_GetScriptWork(cmdWork));
    playerMmdl = SCRCMD_FLDMMDL_GetPlayerMmdl(cmdWork);
    mmdlSys = SCRCMD_WORK_GetOccupyInfo(cmdWork);
    if (gScrcmdFldmmdlPauseFlags & FLDMMDL_PAUSE_FLAG_PLAYER) {
        if (FLDMMDL_CheckEndAcmd(playerMmdl) == 1) {
            FLDMMDL_OnMoveBitMovePause(playerMmdl);
            gScrcmdFldmmdlPauseFlags &= ~FLDMMDL_PAUSE_FLAG_PLAYER;
        }
    }
    if (gScrcmdFldmmdlPauseFlags & FLDMMDL_PAUSE_FLAG_TARGET) {
        if (FLDMMDL_CheckMoveBitMove(targetMmdl) == 0) {
            FLDMMDL_OnMoveBitMovePause(targetMmdl);
            gScrcmdFldmmdlPauseFlags &= ~FLDMMDL_PAUSE_FLAG_TARGET;
        }
    }
    if (gScrcmdFldmmdlPauseFlags & FLDMMDL_PAUSE_FLAG_MOVE_CODE_30) {
        moveCode30Mmdl = FLDMMDL_SysSearchMoveCode(mmdlSys, 0x30);
        if (FLDMMDL_CheckMoveBitMove(moveCode30Mmdl) == 0) {
            FLDMMDL_OnMoveBitMovePause(moveCode30Mmdl);
            gScrcmdFldmmdlPauseFlags &= ~FLDMMDL_PAUSE_FLAG_MOVE_CODE_30;
        }
    }
    if (gScrcmdFldmmdlPauseFlags & FLDMMDL_PAUSE_FLAG_PARTNER) {
        partnerMmdl = FLDMMDL_MOVE_FindFellow(targetMmdl);
        if (partnerMmdl == 0) {
            gScrcmdFldmmdlPauseFlags &= ~FLDMMDL_PAUSE_FLAG_PARTNER;
        } else if (FLDMMDL_CheckMoveBitMove(partnerMmdl) == 0) {
            FLDMMDL_OnMoveBitMovePause(partnerMmdl);
            gScrcmdFldmmdlPauseFlags &= ~FLDMMDL_PAUSE_FLAG_PARTNER;
        }
    }
    if (gScrcmdFldmmdlPauseFlags == 0) {
        return 1;
    }
    return 0;
}

/* Pauses all models, then releases the player, the talk target and its partner so they can finish moving; waits for them. */
int SCRCMD_FLDMMDL_PauseMmdlsReleaseActive(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    MmdlSys *mmdlSys;
    Mmdl *targetMmdl;
    Mmdl *playerMmdl;
    Mmdl *partnerMmdl;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    mmdlSys = SCRCMD_WORK_GetOccupyInfo(cmdWork);
    targetMmdl = SCRIPT_WORK_GetTargetObj(scriptWork);
    playerMmdl = SCRCMD_FLDMMDL_GetPlayerMmdl(cmdWork);
    FLDMMDL_SysSearchMoveCode(mmdlSys, 0x30);
    partnerMmdl = FLDMMDL_MOVE_FindFellow(targetMmdl);
    gScrcmdFldmmdlPauseFlags = 0;
    FLDMMDL_SysPauseMove(mmdlSys);
    if (FLDMMDL_CheckEndAcmd(playerMmdl) == 0) {
        gScrcmdFldmmdlPauseFlags |= FLDMMDL_PAUSE_FLAG_PLAYER;
        FLDMMDL_OffMoveBitMovePause(playerMmdl);
    }
    if (targetMmdl != 0) {
        if (FLDMMDL_CheckMoveBitMove(targetMmdl) == 1) {
            gScrcmdFldmmdlPauseFlags |= FLDMMDL_PAUSE_FLAG_TARGET;
            FLDMMDL_OffMoveBitMovePause(targetMmdl);
        }
    }
    if (partnerMmdl != 0) {
        if (FLDMMDL_CheckMoveBitMove(partnerMmdl) == 1) {
            gScrcmdFldmmdlPauseFlags |= FLDMMDL_PAUSE_FLAG_PARTNER;
            FLDMMDL_OffMoveBitMovePause(partnerMmdl);
        }
    }
    VM_SetWait(vm, SCRCMD_FLDMMDL_CheckMmdlPauseRelease);
    return 1;
}

/* Script command: pause all models (without a talk target), or pause them and wait for the released ones. */
int SCRCMD_FLDMMDL_PauseMmdls(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    if (SCRIPT_WORK_GetTargetObj(SCRCMD_WORK_GetScriptWork(cmdWork)) == 0) {
        FLDMMDL_SysPauseMove(SCRCMD_WORK_GetOccupyInfo(cmdWork));
    } else {
        return SCRCMD_FLDMMDL_PauseMmdlsReleaseActive(vm, cmdWork);
    }
    return 0;
}

/* Called by the script work code: releases the pause of all models. */
void SCRCMD_FLDMMDL_UnpauseAllMmdls(ScrcmdWork *cmdWork)
{
    FLDMMDL_SysResumeMove(SCRCMD_WORK_GetOccupyInfo(cmdWork));
}

/* Script command: turn the talk target to face the player. */
int SCRCMD_FLDMMDL_TurnTargetMmdlToPlayer(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    u32 dir = FLDMMDL_MOVE_GetDirTableValue(FLDMMDL_GetDirDisp(SCRCMD_FLDMMDL_GetPlayerMmdl(cmdWork)));
    Mmdl *targetMmdl = SCRIPT_WORK_GetTargetObj(scriptWork);

    if (targetMmdl != 0) {
        FLDMMDL_SetDirDispCheckPause(targetMmdl, dir);
        FLDMMDL_SetDrawStatus(targetMmdl, 0);
    }
    return 0;
}

/* Script command: look for a model at a grid position; sets a found flag and its object id. */
int SCRCMD_FLDMMDL_SearchMmdlAtGrid(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    FieldMap *fieldMap;
    u16 *objIdVar;
    u16 *foundVar;
    int gridX;
    int posY;
    int gridZ;
    Mmdl *mmdl;

    fieldMap = SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork))->fieldSystem;
    objIdVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    foundVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    gridX = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    posY = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    gridZ = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    mmdl = FLDMMDL_SysSearchGridPosHeight(FIELDMAP_GetMmdlSys(fieldMap), (s16)gridX, (s16)gridZ, posY << 16, 0x8000, 0);
    if (mmdl) {
        *foundVar = 1;
        *objIdVar = FLDMMDL_GetObjId(mmdl);
    } else {
        *foundVar = 0;
    }
    return 0;
}

/* Script command: look for the model in front of the player; sets a found flag and its object id. */
int SCRCMD_FLDMMDL_SearchMmdlInFrontOfPlayer(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    FieldPlayer *player;
    u16 *objIdVar;
    u16 *foundVar;
    Mmdl *mmdl;

    player = FIELDMAP_GetFieldPlayer(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork)));
    objIdVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    foundVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    mmdl = FIELD_PLAYER_SearchFrontMmdlHeight(player, 0x8000);
    if (mmdl != 0) {
        *foundVar = 1;
        *objIdVar = FLDMMDL_GetObjId(mmdl);
    } else {
        *foundVar = 0;
    }
    return 0;
}

/* Wait function: ends when the player animation is done. */
int SCRCMD_FLDMMDL_CheckPlayerFormChangeDone(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    if (FIELD_PLAYER_StepFormChange(FIELDMAP_GetFieldPlayer(SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork))->fieldSystem)) == 1) {
        return 1;
    }
    return 0;
}

/* Script command: start a player animation (code from the script) and wait for it. */
int SCRCMD_FLDMMDL_StartPlayerFormChangeAndWait(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptFieldParam *fieldParam;
    u32 animeCode;
    FieldPlayer *player;

    fieldParam = SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork));
    animeCode = VM_ReadU16(vm);
    player = FIELDMAP_GetFieldPlayer(fieldParam->fieldSystem);
    FIELD_PLAYER_StartFormChange(player, animeCode);
    if (FIELD_PLAYER_StepFormChange(player) == 1)
        return 0;
    VM_SetWait(vm, SCRCMD_FLDMMDL_CheckPlayerFormChangeDone);
    return 1;
}

/* Script command: move the player model by a vertical offset over a number of frames (sign and direction from the script). */
int SCRCMD_FLDMMDL_StartPlayerPosOffsetTween(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VecFx32 offset;
    FieldMap *fieldMap;
    FieldTaskManager *taskManager;
    int negate;
    int height;
    int frames;
    int down;
    Mmdl *playerMmdl;

    fieldMap = SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork))->fieldSystem;
    taskManager = FIELDMAP_GetTaskManager(fieldMap);
    negate = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    frames = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    height = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    down = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    if (negate != 0)
        frames = -frames;
    if (down == 0) {
        offset.x = 0;
        offset.y = -height << 12;
        offset.z = 0;
    } else {
        offset.x = 0;
        offset.y = height << 12;
        offset.z = 0;
    }
    playerMmdl = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
    FIELD_TASK_MANAGER_AddTask(taskManager, FIELD_TASK_CreateMmdlPosOffsetTween(fieldMap, frames, &offset, playerMmdl), 0);
    return 0;
}

/* Second script command with the same body as the previous one. */
int SCRCMD_FLDMMDL_StartPlayerOffsetTaskAgain(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VecFx32 offset;
    FieldMap *fieldMap;
    FieldTaskManager *taskManager;
    int negate;
    int height;
    int frames;
    int down;
    Mmdl *playerMmdl;

    fieldMap = SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork))->fieldSystem;
    taskManager = FIELDMAP_GetTaskManager(fieldMap);
    negate = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    frames = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    height = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    down = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    if (negate != 0)
        frames = -frames;
    if (down == 0) {
        offset.x = 0;
        offset.y = -height << 12;
        offset.z = 0;
    } else {
        offset.x = 0;
        offset.y = height << 12;
        offset.z = 0;
    }
    playerMmdl = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
    FIELD_TASK_MANAGER_AddTask(taskManager, FIELD_TASK_CreateMmdlPosOffsetTween(fieldMap, frames, &offset, playerMmdl), 0);
    return 0;
}

/* Returns the player model. */
Mmdl *SCRCMD_FLDMMDL_GetPlayerMmdl(ScrcmdWork *cmdWork)
{
    return FLDMMDL_SysSearchPlayer(SCRCMD_WORK_GetOccupyInfo(cmdWork));
}

/* Script command: when an event waits in front of the player, turn the player toward it unless already facing it. */
int SCRCMD_FLDMMDL_TurnPlayerToFrontEvent(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    FieldMap *fieldMap;
    GameData *gameData;
    GameSystem *gameSystem;
    FacingCodes facingCodes;
    int i;
    EventDataSystem *eventData;
    EventWork *eventWork;
    FieldPlayer *player;
    VecFx32 pos;
    int facing;
    int found;
    int playerFacing;
    u8 *turnList;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    fieldMap = SCRIPT_WORK_ResetFieldParam(scriptWork)->fieldSystem;
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    facingCodes = gScrcmdFldmmdlFacingCodes;
    eventData = GAME_DATA_GetEventData(gameData);
    eventWork = GAME_DATA_GetEventWork(gameData);
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    FIELD_PLAYER_GetPos(player, &pos);
    for (i = 0; i < 4; i++) {
        facing = facingCodes.codes[i];
        if (EVENTDATA_SYSTEM_SearchPosEvent(eventData, eventWork, (int *)(&pos), facing) != 0) {
            found = facing;
            break;
        }
    }
    playerFacing = FIELD_PLAYER_GetDirDisp(player);
    if (playerFacing != found) {
        if (found == 0) {
            turnList = gScrcmdFldmmdlTurnUpAcmdList;
        } else if (found == 1) {
            turnList = gScrcmdFldmmdlTurnDownAcmdList;
        } else if (found == 2) {
            turnList = gScrcmdFldmmdlTurnLeftAcmdList;
        } else if (found == 3) {
            turnList = gScrcmdFldmmdlTurnRightAcmdList;
        } else {
            return 0;
        }
        SCRIPT_SYS_CallEvent(scriptWork, EVENT_FIELD_PROCLINK_CreateObjAnimEvent(gameSystem, fieldMap, 0xff, (char *)turnList));
        return 1;
    }
    return 0;
}

/*
 * Script command: read the player move form (0..3) into a script variable.
 * Each arm stores its constant through the variable itself; cross-jumping merges the
 * stores, leaving cases 2 and 3 branching onto case 1's branch.
 */
int SCRCMD_FLDMMDL_GetPlayerForm(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    FieldPlayer *player = FIELDMAP_GetFieldPlayer(SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork))->fieldSystem);
    u16 *formVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);

    switch (FIELD_PLAYER_GetFormCode(player)) {
    case 0:
        *formVar = 0;
        break;
    case 1:
        *formVar = 1;
        break;
    case 2:
        *formVar = 2;
        break;
    case 3:
        *formVar = 3;
        break;
    default:
        *formVar = 0;
        break;
    }
    return 0;
}

/* Script command: move a model to the centre of a grid cell by an event; waits for it. */
int SCRCMD_FLDMMDL_StartMmdlMoveToGrid(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VecFx32 start;
    VecFx32 target;
    ScriptWork *scriptWork;
    int objId;
    int gridX;
    int gridY;
    int gridZ;
    MmdlSys *mmdlSys;
    GameSystem *gameSystem;
    Mmdl *mmdl;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    gridX = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    gridY = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    gridZ = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    mmdlSys = SCRCMD_WORK_GetOccupyInfo(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    mmdl = FLDMMDL_SysSearchObjId(mmdlSys, objId);
    FLDMMDL_GetPos(mmdl, (struct MmdlVec *)(&start));
    target.x = (gridX << 16) + 0x8000;
    target.y = gridY << 16;
    target.z = (gridZ << 16) + 0x8000;
    SCRIPT_SYS_CallEvent(scriptWork, EVENT_FIELD_PROCLINK_CreateHopEvent(gameSystem, mmdl, &start, &target));
    return 1;
}

/* Script command: read whether the player form is drawn with a model into a script variable. */
int SCRCMD_FLDMMDL_CheckPlayerFormModel(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    FieldPlayer *player = FIELDMAP_GetFieldPlayer(SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork))->fieldSystem);
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);

    *resultVar = FIELD_PLAYER_CheckFormModel(player);
    return 0;
}

/* Script command: read the rail location of the player into three script variables. */
int SCRCMD_FLDMMDL_GetPlayerRailLocation(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    Mmdl *playerMmdl;
    u16 *railIndexVar;
    u16 *lineGridVar;
    u16 *widthGridVar;

    playerMmdl = SCRCMD_FLDMMDL_GetPlayerMmdl(cmdWork);
    railIndexVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    lineGridVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    widthGridVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    FIELD_RAIL_WORK_GetLocationParts(FLDMMDL_RAIL_GetRailWork(playerMmdl), railIndexVar, lineGridVar, widthGridVar);
    return 0;
}

/* Script command: read the rail location of a model into three script variables. */
int SCRCMD_FLDMMDL_GetMmdlRailLocation(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    Mmdl *mmdl;
    u16 *railIndexVar;
    u16 *lineGridVar;
    u16 *widthGridVar;

    mmdl = FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetOccupyInfo(cmdWork), SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    railIndexVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    lineGridVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    widthGridVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    FIELD_RAIL_WORK_GetLocationParts(FLDMMDL_RAIL_GetRailWork(mmdl), railIndexVar, lineGridVar, widthGridVar);
    return 0;
}

/* Script command: start the rail slip-down event for a model; waits for it. */
int SCRCMD_FLDMMDL_StartMmdlRailSlipDown(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    GameEvent *event;
    MmdlSys *mmdlSys;
    Mmdl *mmdl;
    GameSystem *gameSystem;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    mmdlSys = SCRCMD_WORK_GetOccupyInfo(cmdWork);
    mmdl = FLDMMDL_SysSearchObjId(mmdlSys, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    event = RAIL_SLIPDOWN_Start(gameSystem, (unsigned int)(SCRIPT_WORK_ResetFieldParam(scriptWork)->fieldSystem), (unsigned int)mmdl);
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Script command: put the player on a rail location. */
int SCRCMD_FLDMMDL_SetPlayerRailLocation(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    RailLocation location;
    Mmdl *playerMmdl;
    RailWork *railWork;
    u32 railIndex;
    u32 lineGrid;
    u32 widthPos;

    playerMmdl = SCRCMD_FLDMMDL_GetPlayerMmdl(cmdWork);
    railIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    lineGrid = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    widthPos = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    railWork = FLDMMDL_RAIL_GetRailWork(playerMmdl);
    FIELD_RAIL_WORK_SetLineLocation(railWork, railIndex, lineGrid, widthPos);
    FIELD_RAIL_WORK_GetLocation(railWork, &location);
    FLDMMDL_RAIL_SetLocation(playerMmdl, &location);
    return 0;
}

/* Script command: put a model on a rail location. */
int SCRCMD_FLDMMDL_SetMmdlRailLocation(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    RailLocation location;
    Mmdl *mmdl;
    RailWork *railWork;
    u32 railIndex;
    u32 lineGrid;
    u32 widthPos;

    mmdl = FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetOccupyInfo(cmdWork), SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    railIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    lineGrid = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    widthPos = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    railWork = FLDMMDL_RAIL_GetRailWork(mmdl);
    FIELD_RAIL_WORK_SetLineLocation(railWork, railIndex, lineGrid, widthPos);
    FIELD_RAIL_WORK_GetLocation(railWork, &location);
    FLDMMDL_RAIL_SetLocation(mmdl, &location);
    return 0;
}

/* Script command: make a model spin and rise (sound effect 0x676). */
int SCRCMD_FLDMMDL_StartMmdlSpinRise(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VecFx32 riseOffset;
    ScriptWork *scriptWork;
    u32 objId;
    Mmdl *mmdl;
    FieldMap *fieldMap;
    FieldTaskManager *taskManager;
    FieldTask *riseTask;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    mmdl = FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetOccupyInfo(cmdWork), objId);
    fieldMap = SCRIPT_WORK_ResetFieldParam(scriptWork)->fieldSystem;
    taskManager = FIELDMAP_GetTaskManager(fieldMap);
    GFL_USE_PlaySeDefaultVolume(0x676);
    riseOffset.x = 0;
    riseOffset.y = 0x96 << 12;
    riseOffset.z = 0;
    riseTask = FIELD_TASK_CreateMmdlDrawOffsetTween(fieldMap, 0x18, &riseOffset, mmdl);
    FIELD_TASK_MANAGER_AddTask(taskManager, FIELD_TASK_CreateMmdlSpinLinear(fieldMap, 0x18, 3, mmdl), 0);
    FIELD_TASK_MANAGER_AddTask(taskManager, riseTask, 0);
    return 0;
}

/* Script command: place a model on the ground at a grid cell, then drop it in from above. */
int SCRCMD_FLDMMDL_StartMmdlDropIn(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VecFx32 pos;
    VecFx32 dropOffset;
    int groundHeight;
    int objId;
    int gridX;
    int gridZ;
    int dir;
    Mmdl *mmdl;
    FieldMap *fieldMap;
    FieldTaskManager *taskManager;
    ScriptWork *scriptWork;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    gridX = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    gridZ = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    dir = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    mmdl = FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetOccupyInfo(cmdWork), objId);
    fieldMap = SCRIPT_WORK_ResetFieldParam(scriptWork)->fieldSystem;
    taskManager = FIELDMAP_GetTaskManager(fieldMap);
    if (mmdl == 0) {
        return 0;
    }
    groundHeight = 0;
    pos.x = (gridX << 16) + 0x8000;
    pos.y = 0xFA000;
    pos.z = (gridZ << 16) + 0x8000;
    FLDMMDL_MOVE_GetMapHeight(mmdl, &pos, &groundHeight);
    pos.y = groundHeight;
    FLDMMDL_InitGridPosition(mmdl, gridX, (pos.y >> 4) / 0x1000, gridZ, dir);
    FLDMMDL_SetPos(mmdl, (struct MmdlVec *)(&pos));
    dropOffset = gScrcmdFldmmdlDropInDrawOffset;
    FLDMMDL_SetDrawOffset(mmdl, (struct MmdlVec *)(&dropOffset));
    FIELD_TASK_MANAGER_AddTask(taskManager, FIELD_TASK_CreatePlayerDrop(fieldMap, mmdl, 0x28, 0xfa), 0);
    return 0;
}
