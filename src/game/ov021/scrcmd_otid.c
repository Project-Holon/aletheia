/*
 * file:     scrcmd_otid.c
 * unit:     yes
 * function: SCRCMD_StartCountOtherOtIdsTask, SCRCMD_CountOtherOtIdsTaskMain, SCRCMD_CountPartyOtherOtIds, SCRCMD_CountBoxOtherOtIds, SCRCMD_CountBattleBoxOtherOtIds, SCRCMD_AddOtherOtId, SCRCMD_AddUniqueOtId, SCRCMD_StartSubProcOv057, SCRCMD_GetPlayerLocationValue
 * address:  0x021CF7DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Boundary audit (wave 16): cut from enceff.c at 021CF7DC (module prefix changes from ENCEFF_ to SCRCMD_; no shared statics with the ENCEFF code). Holds the other-OT-id count helpers and two small script commands (sub process of overlay 57, player location value) up to 021CFABF, where the INTRUDE_ module starts. No evidence for a border inside this run, so it stays one piece.
 *
 * symbols:
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb
 *   BOX_SAVEDATA_GetPokemonValue  0x020079BC  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   BATTLE_BOX_GetFromSave  0x0200BAC8  thumb
 *   BATTLE_BOX_GetMon  0x0200BBEC  thumb
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMapFunc  0x02188D24  thumb  ov021
 *   FIELD_SUBPROC_Start  0x021BB990  thumb  ov021
 *   abs_id_39      0x00000039  data
 *   d_021F3900     0x021F3900  data  ov057  a4
 *   PLAYER_LOCATION_GetData  0x02008854  thumb
 *   PLAYER_LOCATION_GetStepMessageCount  0x02008990  thumb
 */
#include "enceff_shared_types.h"
#include "scrcmd_otid_shared_types.h"

struct PokeParty;

struct PokemonParam;

struct BoxData;

struct BattleBoxSave;

struct PlayerLocation;

/* Pokemon data ids read through the party, box and battle box getters. */
enum {
    MON_DATA_OT_ID = 7,
    MON_DATA_IS_EGG = 0x4C,
    MON_DATA_HAS_SPECIES = 0xA9
};

enum {
    BOX_COUNT = 0x18,
    BOX_SLOT_COUNT = 30,
    BATTLE_BOX_SLOT_COUNT = 6
};

/* Distinct original-trainer ids found so far (0xCC bytes). */
#define OT_ID_LIST_MAX 50

typedef struct OtIdList {
    int count;
    int ids[OT_ID_LIST_MAX];
} OtIdList;

/* Work of the original-trainer count task (0xD8 bytes allocated). */
typedef struct OtCountTask {
    u32 playerId;       /* 0x00: own trainer id, never counted */
    int nextBox;        /* 0x04: next PC box to scan */
    u16 *result;        /* 0x08: script variable that receives the count */
    OtIdList list;      /* 0x0C */
} OtCountTask;

#include "../arm9/game_event.h"

#include "../ov010/scrcmd_work.h"



#include "../ov010/script_work_cmd.h"

#include "../ov010/script_sys.h"



#include "../arm9/gamesystem.h"


#include "../arm9/game_data.h"




#include "../arm9/mystatus.h"
struct Party;

#include "../arm9/pokeparty.h"


#include "../arm9/poke_tool.h"

#include "../arm9/box_savedata.h"

#include "../arm9/battle_box.h"
struct BoxMonGroup;
struct BoxMon;

struct BoxPokemon;

struct FieldSubprocTemplate;
struct FieldSubprocMgr;
struct FieldSubproc;

#include "fieldmap_func.h"
struct FieldmapFunc;

#include "fieldmap.h"
struct PlayerLocationData;

#include "../arm9/player_location.h"


extern char abs_id_39[];

extern char d_021F3900[];

int SCRCMD_StartCountOtherOtIdsTask(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_CountOtherOtIdsTaskMain(struct GameEvent *event, int *seq, OtCountTask *task);

int SCRCMD_CountPartyOtherOtIds(u32 playerId, struct GameData *gameData, OtIdList *list);

int SCRCMD_CountBoxOtherOtIds(u32 playerId, struct GameData *gameData, u32 box, OtIdList *list);

int SCRCMD_CountBattleBoxOtherOtIds(u32 playerId, struct GameData *gameData, u32 team, OtIdList *list);

int SCRCMD_AddOtherOtId(int playerId, int otId, OtIdList *list);

int SCRCMD_AddUniqueOtId(int otId, OtIdList *list);

int SCRCMD_StartSubProcOv057(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

int SCRCMD_GetPlayerLocationValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

/*
 * Script command: starts the task that counts the original trainers of
 * the player's Pokemon other than the player, and stores the count in a
 * script variable when the task ends.
 */
int SCRCMD_StartCountOtherOtIdsTask(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    struct GameData *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    struct GameEvent *taskEvent;
    struct MyStatus *myStatus;
    OtCountTask *task;

    taskEvent = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)SCRCMD_CountOtherOtIdsTaskMain, 0xd8);
    myStatus = GAME_DATA_GetMyStatus(gameData);
    task = GAME_EVENT_GetWork(taskEvent);
    task->playerId = MYSTATUS_GetId(myStatus);
    task->list.count = 0;
    task->nextBox = 0;
    task->result = resultVar;
    SCRIPT_SYS_CallEvent(scriptWork, taskEvent);
    return 1;
}

/*
 * Task body: scans the party, then two PC boxes per frame, then the battle
 * box. Ends when all are scanned or the list is full.
 */
int SCRCMD_CountOtherOtIdsTaskMain(struct GameEvent *event, int *seq, OtCountTask *task)
{
    OtIdList *list;
    int finished = 0;
    struct GameData *gameData;
    int i;

    gameData = GAMESYSTEM_GetGameData(GAME_EVENT_GetGameSystem(event));
    switch (*seq) {
    case 0:
        SCRCMD_CountPartyOtherOtIds(task->playerId, gameData, &task->list);
        (*seq)++;
        break;
    case 1: {
        int firstBox = task->nextBox;
        list = &task->list;
        for (i = finished; i < 2; i++) {
            SCRCMD_CountBoxOtherOtIds(task->playerId, gameData, firstBox + i, list);
            task->nextBox++;
            if (task->nextBox >= BOX_COUNT) {
                (*seq)++;
                break;
            }
        }
        break;
    }
    case 2:
        SCRCMD_CountBattleBoxOtherOtIds(task->playerId, gameData, finished, &task->list);
        finished = 1;
        break;
    }
    if (task->list.count >= OT_ID_LIST_MAX) {
        finished = 1;
    }
    if (finished) {
        *task->result = task->list.count;
        return 1;
    }
    return 0;
}

/* Adds the original trainers of the non-egg party Pokemon to the list. */
int SCRCMD_CountPartyOtherOtIds(u32 playerId, struct GameData *gameData, OtIdList *list)
{
    struct PokeParty *party = GAME_DATA_GetMyParty(gameData);
    int partyCount = POKEPARTY_GetCount((struct Party *)party);
    int added = 0;
    int i;

    for (i = 0; i < partyCount; i++) {
        struct PokemonParam *mon = POKEPARTY_GetMember((struct Party *)party, i);
        if (POKE_TOOL_GetPartyValue(mon, MON_DATA_IS_EGG, 0) == 0) {
            u32 otId = POKE_TOOL_GetPartyValue(mon, MON_DATA_OT_ID, 0);
            if (SCRCMD_AddOtherOtId(playerId, otId, list) != 0) {
                added++;
            }
        }
    }
    return added;
}

/* Adds the original trainers of the non-egg Pokemon of one PC box to the list. */
int SCRCMD_CountBoxOtherOtIds(u32 playerId, struct GameData *gameData, u32 box, OtIdList *list)
{
    struct BoxData *boxData = (struct BoxData *)GAME_DATA_GetBoxManager(gameData);
    int added = 0;
    int i;

    for (i = 0; i < BOX_SLOT_COUNT; i++) {
        if (BOX_SAVEDATA_GetPokemonValue((struct GameData *)boxData, box, i, MON_DATA_HAS_SPECIES, 0) != 0) {
            if (BOX_SAVEDATA_GetPokemonValue((struct GameData *)boxData, box, i, MON_DATA_IS_EGG, 0) == 0) {
                u32 otId = BOX_SAVEDATA_GetPokemonValue((struct GameData *)boxData, box, i, MON_DATA_OT_ID, 0);
                if (SCRCMD_AddOtherOtId(playerId, otId, list) != 0) {
                    added++;
                }
            }
        }
    }
    return added;
}

/* Adds the original trainers of one battle box team to the list. */
int SCRCMD_CountBattleBoxOtherOtIds(u32 playerId, struct GameData *gameData, u32 team, OtIdList *list)
{
    struct BattleBoxSave *battleBox;
    int i;
    int added;

    battleBox = BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(gameData));
    added = 0;
    for (i = 0; i < BATTLE_BOX_SLOT_COUNT; i++) {
        struct PokemonParam *mon = (struct PokemonParam *)BATTLE_BOX_GetMon((struct BoxMonGroup *)battleBox, team, i);
        if (POKE_TOOL_GetBoxValue((struct BoxPokemon *)mon, MON_DATA_HAS_SPECIES, 0) != 0) {
            u32 otId = POKE_TOOL_GetBoxValue((struct BoxPokemon *)mon, MON_DATA_OT_ID, 0);
            if (SCRCMD_AddOtherOtId(playerId, otId, list) != 0) {
                added++;
            }
        }
    }
    return added;
}

/* Adds an original trainer id to the list unless it is the player's own. */
int SCRCMD_AddOtherOtId(int playerId, int otId, OtIdList *list)
{
    int added = 0;

    if (playerId != otId) {
        added = SCRCMD_AddUniqueOtId(otId, list);
    }
    return added;
}

/* Adds an id to the list when it is not in there yet and the list has room. */
int SCRCMD_AddUniqueOtId(int otId, OtIdList *list)
{
    int i;

    if (list->count >= OT_ID_LIST_MAX) {
        return 0;
    }
    for (i = 0; i < list->count; i++) {
        if (otId == list->ids[i]) {
            return 0;
        }
    }
    list->ids[i] = otId;
    list->count++;
    return 1;
}

/*
 * Script command: starts the field sub process of overlay 57 with the map
 * function of the current field map. abs_id_39 is overlay id 57 (pool ABS32
 * 0x39); d_021F3900 is ov057 data.
 */
int SCRCMD_StartSubProcOv057(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct FieldMap *fieldMap;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    fieldMap = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork));
    FIELD_SUBPROC_Start((sptr)abs_id_39, (struct FieldSubprocMgr *)FIELDMAP_GetMapFunc(fieldMap), (struct FieldSubprocTemplate *)d_021F3900);
    return 0;
}

/* Script command: stores a value of the saved player location in a script variable. */
int SCRCMD_GetPlayerLocationValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct PlayerLocation *location;
    u16 *resultVar;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    location = (struct PlayerLocation *)PLAYER_LOCATION_GetData(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(cmdWork))));
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *resultVar = PLAYER_LOCATION_GetStepMessageCount((struct PlayerLocationData *)location);
    return 0;
}
