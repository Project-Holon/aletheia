/*
 * file:     scrcmd_trialhouse.c
 * unit:     yes
 * function: SCRCMD_TRIALHOUSE_CreateWork, SCRCMD_TRIALHOUSE_FreeWork, SCRCMD_TRIALHOUSE_SetBattleMode, SCRCMD_TRIALHOUSE_StartPartySelect, SCRCMD_TRIALHOUSE_LoadRecord, SCRCMD_TRIALHOUSE_StartTrainerMessage, SCRCMD_TRIALHOUSE_StartBattle, SCRCMD_TRIALHOUSE_SetRecordSource, SCRCMD_TRIALHOUSE_SetRank, SCRCMD_TRIALHOUSE_GetRank, SCRCMD_TRIALHOUSE_StartDownload, SCRCMD_TRIALHOUSE_GetRankAndScore, SCRCMD_TRIALHOUSE_GetSaveState, SCRCMD_TRIALHOUSE_StartSaveEvent, SCRCMD_TRIALHOUSE_StartAward, SCRCMD_TRIALHOUSE_GetClearFlags
 * address:  0x0216A3F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from scrcmd_trialhouse.c by tools/splitfile.py.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAME_DATA_GetListCursor  0x02012F50  thumb
 *   TRIAL_HOUSE_CreateWork  0x021D096C  thumb
 *   TRIAL_HOUSE_DeleteWork   0x021D0A48  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   TRIAL_HOUSE_SetBattleMode  0x021D0A74  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   TRIAL_HOUSE_LoadTrainer  0x021D0AC0  thumb  ov021
 *   TRIAL_HOUSE_CreateTrainerMsgEvent  0x021D0BD8  thumb  ov021
 *   TRIAL_HOUSE_SetUseDeliveredTrainers  0x021D0AB8  thumb
 *   RECORD_GetFromSave 0x02008C58 thumb
 *   RECORD_SetTrialRank 0x02008E68 thumb
 *   RECORD_GetTrialRank  0x02008E78  thumb
 *   TRIAL_HOUSE_CreateDeliveryTask  0x021D0BE4  thumb  ov021
 *   TRIAL_HOUSE_ComputeScoreAndRank  0x021D0DB0  thumb  ov021
 *   TRIAL_HOUSE_GetDeliveryState  0x021D0FE0  thumb
 *   TRIAL_HOUSE_CreateSaveTask  0x021D0FE8  thumb  ov021
 *   TRIAL_HOUSE_GetRecordSlotsState  0x021D1028  thumb
 *   FLD_BTL_INST_TOOL_CreatePartySelectStepEvent  0x02168BF0  thumb  ov010
 *   FLD_BTL_INST_TOOL_CreateBattleEvent  0x02168CF4  thumb  ov010
 *   FLD_BTL_INST_TOOL_CreateTrialHouseAwardEvent  0x02168E5C  thumb  ov010
 */
#include "script_work_types.h"
#include "formchange_shaymin_shared_types.h"
#include "scrcmd_trialhouse_shared_types.h"

struct TrialHouseWork;

struct RecordBlock;

typedef struct TrialHouseWork TrialHouseWork;

/* ScriptWork, ScrcmdWork and game structure accessors. */
extern struct GameSystem *SCRCMD_WORK_GetGameSystem(ScrcmdWork *cmdWork);

extern ScriptWork *SCRCMD_WORK_GetScriptWork(ScrcmdWork *cmdWork);

extern u32 SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, ScrcmdWork *cmdWork);

extern u16 *SCRIPT_WORK_ReadWorkPointer(ScriptVm *vm, ScrcmdWork *cmdWork);

extern void SCRIPT_SYS_CallEvent(void *scriptWork, void *task);

extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);

extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);

extern unsigned int *GAME_DATA_GetListCursor(struct GameData *gameData);

/* Trial house (ov021 trial_house.c and ov010 fld_btl_inst_tool.c). */
extern TrialHouseWork *TRIAL_HOUSE_CreateWork(struct GameSystem *gameSystem);

extern void TRIAL_HOUSE_DeleteWork(struct GameSystem *gameSystem, TrialHouseWork **slot);

extern void TRIAL_HOUSE_SetBattleMode(TrialHouseWork *work, u32 mode);

extern void TRIAL_HOUSE_SetUseDeliveredTrainers(TrialHouseWork *work, int value);

extern u16 TRIAL_HOUSE_LoadTrainer(struct GameSystem *gameSystem, struct TrialHouseWork *work, u32 index);

extern struct GameEvent *TRIAL_HOUSE_CreateTrainerMsgEvent(struct GameSystem *gameSystem, TrialHouseWork *work, u32 index, u32 mmdlId);

extern struct GameEvent *TRIAL_HOUSE_CreateDeliveryTask(struct GameSystem *gameSystem, TrialHouseWork *work, u16 *outValue);

extern void TRIAL_HOUSE_ComputeScoreAndRank(struct GameSystem *gameSystem, TrialHouseWork *work, u16 *outRank, u16 *outScore);

extern int TRIAL_HOUSE_GetDeliveryState(struct GameSystem *unused, struct TrialHouseWork *work);

extern struct GameEvent *TRIAL_HOUSE_CreateSaveTask(struct GameSystem *gameSystem, struct TrialHouseWork *unused, int mode);

extern int TRIAL_HOUSE_GetRecordSlotsState(struct GameSystem *gameSystem);

extern struct RecordBlock *RECORD_GetFromSave(struct SaveControl *saveControl);

extern void RECORD_SetTrialRank(struct RecordBlock *record, u8 rank);

extern u8 RECORD_GetTrialRank(struct RecordBlock *record);
struct BtlInstBattleRequest;

extern struct GameEvent *FLD_BTL_INST_TOOL_CreatePartySelectStepEvent(struct GameSystem *gameSystem, struct BtlInstBattleRequest *request, int regulationId, int useTempParty, unsigned short *resultOk);
struct BtlInstBattleRequest;

extern struct GameEvent *FLD_BTL_INST_TOOL_CreateBattleEvent(struct GameSystem *gameSystem, struct BtlInstBattleRequest *request);

extern struct GameEvent *FLD_BTL_INST_TOOL_CreateTrialHouseAwardEvent(struct GameSystem *gameSystem, int hasSecondEntry, int fadeOutBgm);

int SCRCMD_TRIALHOUSE_CreateWork(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_TRIALHOUSE_FreeWork(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_TRIALHOUSE_SetBattleMode(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_TRIALHOUSE_StartPartySelect(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_TRIALHOUSE_LoadRecord(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_TRIALHOUSE_StartTrainerMessage(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_TRIALHOUSE_StartBattle(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_TRIALHOUSE_SetRecordSource(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_TRIALHOUSE_SetRank(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_TRIALHOUSE_GetRank(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_TRIALHOUSE_StartDownload(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_TRIALHOUSE_GetRankAndScore(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_TRIALHOUSE_GetSaveState(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_TRIALHOUSE_StartSaveEvent(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_TRIALHOUSE_StartAward(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_TRIALHOUSE_GetClearFlags(ScriptVm *vm, ScrcmdWork *cmdWork);

/* Trial house script command: creates the trial house work once. */
int SCRCMD_TRIALHOUSE_CreateWork(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    TrialHouseWork **slot = (struct TrialHouseWork **)GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData(gameSystem));

    if (*slot == 0) {
        *slot = TRIAL_HOUSE_CreateWork(gameSystem);
    }
    return 0;
}

/* Trial house script command: frees the trial house work. */
int SCRCMD_TRIALHOUSE_FreeWork(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);

    TRIAL_HOUSE_DeleteWork(gameSystem, (struct TrialHouseWork **)GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData(gameSystem)));
    return 0;
}

/* Trial house script command: sets the battle mode (party size) from a script value. */
int SCRCMD_TRIALHOUSE_SetBattleMode(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;
    u32 mode;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = (struct TrialHouseWork **)GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData(gameSystem));
    mode = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    TRIAL_HOUSE_SetBattleMode(*slot, mode);
    return 0;
}

int SCRCMD_TRIALHOUSE_StartPartySelect(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;
    int regulationId;
    int useTempParty;
    u16 *resultOk;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = (struct TrialHouseWork **)GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData(gameSystem));
    regulationId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    useTempParty = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    resultOk = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    SCRIPT_SYS_CallEvent(scriptWork, FLD_BTL_INST_TOOL_CreatePartySelectStepEvent(gameSystem, (struct BtlInstBattleRequest *)(*slot), regulationId, useTempParty, resultOk));
    return 1;
}

int SCRCMD_TRIALHOUSE_LoadRecord(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;
    int index;
    u16 *outValue;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = (struct TrialHouseWork **)GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData(gameSystem));
    index = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    outValue = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *outValue = TRIAL_HOUSE_LoadTrainer(gameSystem, *slot, index);
    return 0;
}

int SCRCMD_TRIALHOUSE_StartTrainerMessage(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;
    int index;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = (struct TrialHouseWork **)GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData(gameSystem));
    index = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRIPT_SYS_CallEvent(scriptWork, TRIAL_HOUSE_CreateTrainerMsgEvent(gameSystem, *slot, index, SCRIPT_WORK_ReadWorkValue(vm, cmdWork)));
    return 1;
}

int SCRCMD_TRIALHOUSE_StartBattle(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = (struct TrialHouseWork **)GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData(gameSystem));
    SCRIPT_SYS_CallEvent(scriptWork, FLD_BTL_INST_TOOL_CreateBattleEvent(gameSystem, (struct BtlInstBattleRequest *)(*slot)));
    return 1;
}

int SCRCMD_TRIALHOUSE_SetRecordSource(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = (struct TrialHouseWork **)GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData(gameSystem));
    TRIAL_HOUSE_SetUseDeliveredTrainers(*slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

/* Trial house script command: sets the trial house rank byte of the save from a script value. */
int SCRCMD_TRIALHOUSE_SetRank(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameData *gameData;
    u32 rank;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameData = GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(cmdWork));
    rank = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    RECORD_SetTrialRank(RECORD_GetFromSave(GAME_DATA_GetSaveControl(gameData)), rank);
    return 0;
}

/* Trial house script command: stores the trial house rank byte of the save in a script work. */
int SCRCMD_TRIALHOUSE_GetRank(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    u16 *outRank;
    struct SaveControl *saveControl;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    outRank = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    saveControl = GAME_DATA_GetSaveControl(gameData);
    *outRank = RECORD_GetTrialRank(RECORD_GetFromSave(saveControl));
    return 0;
}

int SCRCMD_TRIALHOUSE_StartDownload(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = (struct TrialHouseWork **)GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData(gameSystem));
    SCRIPT_SYS_CallEvent(scriptWork, TRIAL_HOUSE_CreateDeliveryTask(gameSystem, *slot, SCRIPT_WORK_ReadWorkPointer(vm, cmdWork)));
    return 1;
}

int SCRCMD_TRIALHOUSE_GetRankAndScore(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;
    u16 *outRank;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = (struct TrialHouseWork **)GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData(gameSystem));
    outRank = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    TRIAL_HOUSE_ComputeScoreAndRank(gameSystem, *slot, outRank, SCRIPT_WORK_ReadWorkPointer(vm, cmdWork));
    return 0;
}

int SCRCMD_TRIALHOUSE_GetSaveState(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;
    u16 *outValue;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = (struct TrialHouseWork **)GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData(gameSystem));
    outValue = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *outValue = TRIAL_HOUSE_GetDeliveryState(gameSystem, *slot);
    return 0;
}

int SCRCMD_TRIALHOUSE_StartSaveEvent(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = (struct TrialHouseWork **)GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData(gameSystem));
    SCRIPT_SYS_CallEvent(scriptWork, TRIAL_HOUSE_CreateSaveTask(gameSystem, (*slot), SCRIPT_WORK_ReadWorkValue(vm, cmdWork)));
    return 1;
}

int SCRCMD_TRIALHOUSE_StartAward(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    int hasSecondEntry;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData(gameSystem));
    hasSecondEntry = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRIPT_SYS_CallEvent(scriptWork, FLD_BTL_INST_TOOL_CreateTrialHouseAwardEvent(gameSystem, hasSecondEntry, SCRIPT_WORK_ReadWorkValue(vm, cmdWork)));
    return 1;
}

int SCRCMD_TRIALHOUSE_GetClearFlags(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u16 *outValue;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    outValue = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *outValue = TRIAL_HOUSE_GetRecordSlotsState(gameSystem);
    return 0;
}
