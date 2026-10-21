/*
 * file:     event_battle.c
 * unit:     yes
 * function: EVENT_BATTLE_CallAndInvert, EVENT_BATTLE_ProcScriptedBattle, EVENT_BATTLE_CreateScriptedBattle, EVENT_BATTLE_CreateEncounterTask, EVENT_BATTLE_CreateResultOnlyTask, EVENT_BATTLE_CreateForcedWinTask, EVENT_BATTLE_CreateCatchTutorial, EVENT_BATTLE_CreateEncounterTaskWithMon, EVENT_BATTLE_ProcBattleTask, EVENT_BATTLE_GetBattleKindClass, EVENT_BATTLE_DispatchBattleKindNotify, EVENT_BATTLE_NotifyLeadSpecies, EVENT_BATTLE_NotifyBattleEnd, EVENT_BATTLE_AddBattleRecord, EVENT_BATTLE_IsResultSilent, EVENT_BATTLE_GetResultFlag, EVENT_BATTLE_IsTaskResultSilent, EVENT_BATTLE_FinishBattleTask, EVENT_BATTLE_InitTaskWork, EVENT_BATTLE_FreeBtlSetup, EVENT_BATTLE_IntegrityProbeA, EVENT_BATTLE_IntegrityProbeB, EVENT_BATTLE_IntegrityDecoyC
 * address:  0x0216E680
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from trcard_sys.c (it held four originals); __FILE__ anchors: event_battle.c 0x0216E95C, trcard_sys.c 0x0216F0AC, waza_oshie.c 0x0216F918.
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   BTL_SETUP_GetParty  0x0201313C  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   ENCEFF_SelectEffectAndBgm  0x021CF5D8  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAME_DATA_GetPmsWork  0x02012F20  thumb
 *   COMM_PLAYER_SUPPORT_Init  0x0202E79C  thumb
 *   GAME_DATA_GetLastBattleResult  0x02012A44  thumb
 *   SCRCMD_NETWORK_CreateCommProcEvent  0x0215F6E8  thumb  ov010
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   COMM_PLAYER_SUPPORT_HasSavedMode  0x0202E818  thumb
 *   EVENT_COMM_COMMON_CreateSupportMsgEvent  0x02181D8C  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   RECORD_AddOne  0x02008DF0  thumb
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   EFFECT_ENCOUNT_ConsumeSpot  0x021AAABC  thumb  ov021
 *   BTL_SETUP_Create  0x02013090  thumb
 *   FIELD_ENCOUNT_SetupTrainerBattle  0x021AA5CC  thumb  ov021
 *   BTL_SETUP_SetStatusFlag  0x02013144  thumb
 *   ENCEFF_SelectEffectAndBgmForTrainer  0x021CF748  thumb  ov021
 *   POKEPARTY_Create  0x0201A920  thumb
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   POKE_TOOL_SetupPartyParam  0x0201756C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   FIELD_ENCOUNT_SetFieldSituation  0x021AA304  thumb  ov021
 *   BTL_SETUP_SetupDemo  0x020135C0  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   d_02172B54     0x02172B54  data
 *   GAME_DATA_GetSaveBlock43  0x02012FD8  thumb
 *   MON_SNAPSHOT_IsFilled   0x0200E740  thumb
 *   GAME_EVENT_GetWork   0x020124E8  thumb
 *   MON_SNAPSHOT_GetSpeciesForSlot   0x0200E788  thumb
 *   MON_SNAPSHOT_GetLevel   0x0200E74C  thumb
 *   MON_SNAPSHOT_GetOtId   0x0200E7B4  thumb
 *   MON_SNAPSHOT_GetPersonalRnd   0x0200E7A4  thumb
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   MON_SNAPSHOT_HasAbility   0x0200E76C  thumb
 *   MON_SNAPSHOT_GetAbility   0x0200E780  thumb
 *   MON_SNAPSHOT_GetNickname   0x0200E7AC  thumb
 *   POKE_TOOL_ChangeSpecies  0x020178D8  thumb
 *   POKE_TOOL_SetDefaultMoves  0x02017FA8  thumb
 *   GAME_EVENT_CallProc  0x02012444  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   GAME_DATA_GetListCursor  0x02012F50  thumb
 *   FIELD_STATUS_SwapSeasonDispFlag  0x0201447C  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   FIELD_SOUND_SYSTEM_StartFadeOutAndResetTask  0x02029B28  thumb
 *   FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask  0x02029BCC  thumb
 *   FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask  0x02029C00  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   COMM_PLAYER_SUPPORT_StashMode  0x0202E80C  thumb
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   GAMESYSTEM_RandTwice  0x02011D34  thumb
 *   FLD_BTL_INST_TOOL_AddBattleTally  0x02168D30  thumb  ov010
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   OV230_CallSealedBody1  0x021882DC  arm  ov230d
 *   OV230_CallSealedBody3  0x02188354  arm  ov230d
 *   OV230_CallSealedBody4  0x02188390  arm  ov230d
 *   ENCEFF_Start  0x021CF498  thumb  ov021
 *   ov093_id       0x0000005D  data
 *   ov092_id       0x0000005C  data
 *   ov230_id       0x000000E6  data
 *   d_021EFDAC     0x021EFDAC  data  ov093
 *   d_021B9D94     0x021B9D94  data  ov092
 *   g_0214624C     0x0214624C  data
 *   TPOKE_DATA_GetRecordField   0x0202A230  thumb
 *   TPOKE_DATA_GetTrainerKind   0x0202A3FC  thumb
 *   d_021725C0     0x021725C0  data
 *   GAME_BEACON_SEARCH_SetBattlePokeStart  0x0216505C  thumb  ov010
 *   GAME_BEACON_SEARCH_SetBattlePokeWin  0x02165078  thumb  ov010
 *   GAME_BEACON_SEARCH_SetPokeEvent  0x021653F4  thumb  ov010
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_FindFirstNonEgg  0x0201AB18  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   GAME_BEACON_SEARCH_SetEventBattleNameC  0x021654AC  thumb  ov010
 *   GAME_BEACON_SEARCH_SetEventBattleNameA  0x02165424  thumb  ov010
 *   GAME_BEACON_SEARCH_SetEventBattleNameB  0x02165468  thumb  ov010
 *   GAME_BEACON_SEARCH_SetEventBattleNameD  0x021654F0  thumb  ov010
 *   STRBUF_Delete  0x02045808  arm
 *   d_021725D8  0x021725D8  data  ov010  a1
 *   d_021725B8     0x021725B8  data
 *   GAME_DATA_SetLastBattleResult 0x02012A4C thumb
 *   MOVE_POKEMON_HandleBattleResult 0x0215E5B0 thumb ov010
 *   GAME_DATA_GetMyPlayerWork 0x020127A4 thumb
 *   GAME_DATA_GetPlayerZoneId 0x02012AC8 thumb
 *   WEATHER_StoreZoneWeatherId 0x0202C83C thumb
 *   MIi_CpuClear32 0x02082A7C arm
 *   BTL_SETUP_Delete  0x020130B4  thumb
 *   GF_STANDARD_Rand  0x0203F0A8  arm
 *   _u32_div_f                   0x0209C2B0  arm
 */

struct GameSystem;
struct GameEvent;
struct GameEvent;
struct GameEvent;
struct GameEvent;
struct RecordBlock;
struct PokeParty;
struct PokemonParam;
struct TallyRecord;
struct Result;
struct FieldStatus;
struct Strbuf;
struct PlayerWork;
struct SaveData;
struct BattleEndCtx;
#include "../version.h"

#include "../types.h"
#ifdef __MWERKS__
#define POKE_TOOL_SetupPartyParamEx POKE_TOOL_SetupPartyParamEx_header
#endif
#include "../arm9/poke_tool.h"
#ifdef __MWERKS__
#undef POKE_TOOL_SetupPartyParamEx
#endif
#include "../arm9/btl_setup_types.h"

typedef struct ScriptedBattleArgs {
    void *gameSystem;           /* 0x00 */
    struct BattleSetupParam *btlSetup;   /* 0x04 */
    u32 returnImmediately;      /* 0x08 */
    u32 effectId;               /* 0x0C */
} ScriptedBattleArgs;

typedef struct BattleTask {
    void *gameSystem;       /* 0x00 */
    void *gameData;         /* 0x04 */
    struct BattleSetupParam *btlSetup;     /* 0x08 */
    void *procGameData;     /* 0x0C */
    struct BattleSetupParam *procBtlSetup; /* 0x10 */
    u32 isScripted;         /* 0x14 */
    u32 skipResultCheck;    /* 0x18 */
    u32 addTallies;         /* 0x1C */
    u32 keepBtlSetup;       /* 0x20 */
    u32 encounterEffect;    /* 0x24 */
} BattleTask;

typedef void (*BattleKindHandler)(u16 id);

typedef struct BattleEndCtx {
    u32 unused00;
    void *btlSetupObj;      /* 0x04 */
    struct BattleSetupParam *btlSetup;     /* 0x08 */
} BattleEndCtx;

struct GameData;
#include "../ov011/intrude_comm_types.h"
#include "../arm9/gamesystem.h"
struct BattleSetupParam;
#include "../arm9/btl_setup.h"
struct Party;
extern struct PokemonParam *POKEPARTY_GetMember(struct Party *party, u32 pos);
struct FieldMap;
#include "../ov021/enceff.h"
#include "../arm9/game_data.h"
struct CommPlayerSupport;
#include "../arm9/comm_player_support.h"
typedef int Bool;
#include "scrcmd_network.h"
#include "../ov021/event_fieldmap_control.h"
#include "../ov018/event_comm_common.h"
#include "../arm9/record.h"
struct FieldEncount;
#include "../ov021/fieldmap.h"
#include "../ov021/effect_encount.h"
#include "../ov021/field_encount.h"
#ifdef __MWERKS__
extern struct Party *POKEPARTY_Create(u16 heap); /* original prototype; the definition differs in argument width */
#else
extern struct Party*POKEPARTY_Create(u32);
#endif
#include "../arm9/gfl_heap_wrap.h"
extern u32 POKEPARTY_Add(struct Party *party, struct PokemonParam *member);
struct FieldSituation;
#include "../arm9/mon_snapshot_savedata.h"
#ifdef __MWERKS__
extern void POKE_TOOL_SetupPartyParamEx(struct PokemonParam *pp, u16 species, u32 level, u64 otId, u32 ivs, u64 personality); /* original prototype; the definition differs in argument width */
#else
#endif
#include "../arm9/field_status.h"
#include "../arm9/field_sound_system.h"
#include "../arm9/gf_overlay.h"
struct TcbTask;
#include "../arm9/gfl_use.h"
struct BattleSetupParam;
struct BtlInstRecord;
#include "fld_btl_inst_tool.h"
struct EncEffWork;
#include "../ov230/sealed_call_stubs_a.h"
struct EncEffWork;
#include "../arm9/tpoke_data.h"
#include "game_beacon_set.h"
extern u32 POKEPARTY_FindFirstNonEgg(struct Party *party);
#include "../arm9/strbuf.h"
struct BattleResultWork;
#include "move_pokemon.h"
struct Ctx;
#include "../arm9/zone_weather.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gf_standard.h"
#include "../arm9/game_event.h"
int EVENT_BATTLE_CallAndInvert(void (*fn)(void));
int EVENT_BATTLE_ProcScriptedBattle(void *evt, u32 *state, ScriptedBattleArgs *args);
struct GameEvent *EVENT_BATTLE_CreateScriptedBattle(struct GameSystem *gameSystem, struct FieldMap *battleSrc, struct BattleSetupParam *btlSetup, int returnImmediately, int effectId);
struct GameEvent *EVENT_BATTLE_CreateEncounterTask(struct GameSystem *gameSystem, struct FieldMap *battleSrc, int battleMode, int battleFlags, int battleKind, int fieldEffect, int options);
struct GameEvent *EVENT_BATTLE_CreateResultOnlyTask(struct GameSystem *gameSystem, struct FieldMap *battleSrc, struct BattleSetupParam *btlSetup);
struct GameEvent *EVENT_BATTLE_CreateForcedWinTask(struct GameSystem *gameSystem, struct FieldMap *battleSrc, struct BattleSetupParam *btlSetup);
struct GameEvent *EVENT_BATTLE_CreateCatchTutorial(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 heapId);
struct GameEvent *EVENT_BATTLE_CreateEncounterTaskWithMon(struct GameSystem *gameSystem, struct FieldMap *battleSrc, u32 battleMode, u32 battleFlags, u32 battleKind, u32 fieldEffect, u32 options, u32 entryIndex);
int EVENT_BATTLE_ProcBattleTask(void *evt, u32 *state, BattleTask *work);
int EVENT_BATTLE_GetBattleKindClass(u32 trainerId);
void EVENT_BATTLE_DispatchBattleKindNotify(u16 id, int col);
void EVENT_BATTLE_NotifyLeadSpecies(void *btlSetup, int which);
void EVENT_BATTLE_NotifyBattleEnd(BattleEndCtx *ctx);
void EVENT_BATTLE_AddBattleRecord(BattleTask *task);
int EVENT_BATTLE_IsResultSilent(int outcome, int mode);
u8 EVENT_BATTLE_GetResultFlag(int kindId);
int EVENT_BATTLE_IsTaskResultSilent(BattleTask *task);
void EVENT_BATTLE_FinishBattleTask(BattleTask *task, void *gameSystem);
void EVENT_BATTLE_InitTaskWork(BattleTask *task, void *gameSystem, void *btlSetup);
void EVENT_BATTLE_FreeBtlSetup(BattleTask *task);
int EVENT_BATTLE_IntegrityProbeA(int unused);
int EVENT_BATTLE_IntegrityProbeB(int unused);
int EVENT_BATTLE_IntegrityDecoyC(int unused);
extern const char d_02172B54[];
extern u8 ov093_id[];
extern u8 ov092_id[];
extern u8 ov230_id[];
extern u8 d_021EFDAC[];
extern u8 d_021B9D94[];
extern u32 g_0214624C;
extern const BattleKindHandler d_021725C0[][2];
extern u8 d_021725D8[][5];
extern u8 d_021725B8[];

int EVENT_BATTLE_CallAndInvert(void (*fn)(void))
{
    if (fn != 0)
        fn();
    return ~(uptr)fn;
}

/*
 * Four-state proc that pushes the tutorial capture battleTask (EVENT_BATTLE_ProcBattleTask)
 * for the opponent's first Pokemon and then the result screens.
 * Byte-correct first draft (ENCEFF_SelectEffectAndBgm's species is a u32 here: no
 * truncation at the call).
 * Blocker (MATCH): two arm9 Thumb callees have no func_ label and no
 * matched file: 0x0201313C (`return btlSetup->party[side]`, 8 bytes) and
 * 0x0202E818 (16 bytes). Seeds for the arm9 lane.
 *
 * 2026-10-05: byte-identical; the two wildcards resolve once shards exist for arm9 BTL_SETUP_GetParty (matched file exists, no shard) and COMM_PLAYER_SUPPORT_HasSavedMode (new matched/arm9 file, EXACT, this lane).
 */
int EVENT_BATTLE_ProcScriptedBattle(void *event, u32 *state, ScriptedBattleArgs *args)
{
    void *gameSystem = args->gameSystem;
    void *gameData = GAMESYSTEM_GetGameData(gameSystem);
    void *taskEvent;
    BattleTask *work;
    u32 species;
    u32 hasWildOpponent;

    switch (*state) {
    case 0:
        taskEvent = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)EVENT_BATTLE_ProcBattleTask, 0x28);
        work = GAME_EVENT_GetWork(taskEvent);
        EVENT_BATTLE_InitTaskWork(work, gameSystem, args->btlSetup);
        hasWildOpponent = 1;
        work->isScripted = 1;
        species = POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(BTL_SETUP_GetParty((struct BattleSetupParam *)args->btlSetup, 1), 0), 5, 0);
        {
            void *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);

            if (args->btlSetup->rule != 1)
                hasWildOpponent = 0;
            ENCEFF_SelectEffectAndBgm(species, args->effectId, hasWildOpponent, fieldMap, &work->encounterEffect, &work->btlSetup->bgmBattle);
        }
        GAME_EVENT_CallEvent(event, taskEvent);
        (*state)++;
        break;
    case 1:
        if (args->returnImmediately == 1) {
            COMM_PLAYER_SUPPORT_Init(GAME_DATA_GetPmsWork((struct GameData *)gameData));
            return 1;
        }
        if (EVENT_BATTLE_IsResultSilent(GAME_DATA_GetLastBattleResult(gameData), 0) == 1) {
            COMM_PLAYER_SUPPORT_Init(GAME_DATA_GetPmsWork((struct GameData *)gameData));
            GAME_EVENT_ChangeEvent(event, SCRCMD_NETWORK_CreateCommProcEvent(gameSystem));
        } else {
            GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem), 0, 0, 1, 0, 0));
        }
        (*state)++;
        break;
    case 2:
        if (COMM_PLAYER_SUPPORT_HasSavedMode(GAME_DATA_GetPmsWork((struct GameData *)gameData)) == 1)
            GAME_EVENT_CallEvent(event, EVENT_COMM_COMMON_CreateSupportMsgEvent(gameSystem, 4));
        (*state)++;
        break;
    case 3:
        COMM_PLAYER_SUPPORT_Init(GAME_DATA_GetPmsWork((struct GameData *)gameData));
        return 1;
    }
    return 0;
}

/*
 * Allocates a 0x10-byte battleTask record (handler EVENT_BATTLE_ProcScriptedBattle) and fills it
 * from the arguments.
 */
struct GameEvent *EVENT_BATTLE_CreateScriptedBattle(struct GameSystem *gameSystem, struct FieldMap *battleSrc, struct BattleSetupParam *btlSetup, int returnImmediately, int effectId)
{
    struct GameEvent *taskEvent;
    ScriptedBattleArgs *args;

    taskEvent = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)EVENT_BATTLE_ProcScriptedBattle, 0x10);
    args = GAME_EVENT_GetWork(taskEvent);
    args->gameSystem = gameSystem;
    args->btlSetup = btlSetup;
    args->returnImmediately = returnImmediately;
    args->effectId = effectId;
    EVENT_BATTLE_NotifyLeadSpecies(btlSetup, 0);
    RECORD_AddOne(GAME_DATA_GetTrainerRecord(GAMESYSTEM_GetGameData(gameSystem)), 5);
    EFFECT_ENCOUNT_ConsumeSpot(FIELDMAP_GetEncount(battleSrc));
    return taskEvent;
}

struct GameEvent *EVENT_BATTLE_CreateEncounterTask(struct GameSystem *gameSystem, struct FieldMap *battleSrc, int battleMode, int battleFlags, int battleKind, int fieldEffect, int options)
{
    struct GameEvent *taskEvent;
    BattleTask *task;
    sptr battleObj;
    sptr records;
    sptr btlSetup;

    taskEvent = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)EVENT_BATTLE_ProcBattleTask, 0x28);
    task = GAME_EVENT_GetWork(taskEvent);
    battleObj = (sptr)FIELDMAP_GetEncount(battleSrc);
    records = (sptr)GAME_DATA_GetTrainerRecord(GAMESYSTEM_GetGameData(gameSystem));
    btlSetup = (sptr)BTL_SETUP_Create(4);
    FIELD_ENCOUNT_SetupTrainerBattle((struct FieldEncount *)battleObj, (void *)btlSetup, (unsigned int)battleMode, (unsigned int)battleFlags, (unsigned int)battleKind, fieldEffect, 4);
    EVENT_BATTLE_DispatchBattleKindNotify(battleKind, 0);
    RECORD_AddOne((struct RecordBlock *)records, 6);
    RECORD_AddOne((struct RecordBlock *)records, 0x56);
    EVENT_BATTLE_InitTaskWork(task, gameSystem, (void *)btlSetup);
    task->isScripted = 1;
    if (options & 1) {
        BTL_SETUP_SetStatusFlag((struct BattleSetupParam *)btlSetup, 0x100);
        task->skipResultCheck = 1;
    }
    ENCEFF_SelectEffectAndBgmForTrainer(battleKind, battleSrc, (int *)&task->encounterEffect, &task->btlSetup->bgmBattle);
    EFFECT_ENCOUNT_ConsumeSpot(FIELDMAP_GetEncount(battleSrc));
    return taskEvent;
}

struct GameEvent *EVENT_BATTLE_CreateResultOnlyTask(struct GameSystem *gameSystem, struct FieldMap *battleSrc, struct BattleSetupParam *btlSetup)
{
    struct GameEvent *taskEvent;
    BattleTask *task;

    taskEvent = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)EVENT_BATTLE_ProcBattleTask, 0x28);
    task = GAME_EVENT_GetWork(taskEvent);
    EVENT_BATTLE_InitTaskWork(task, gameSystem, btlSetup);
    task->isScripted = 0;
    task->skipResultCheck = 1;
    task->keepBtlSetup = 1;
    task->encounterEffect = 9;
    EFFECT_ENCOUNT_ConsumeSpot(FIELDMAP_GetEncount(battleSrc));
    return taskEvent;
}

struct GameEvent *EVENT_BATTLE_CreateForcedWinTask(struct GameSystem *gameSystem, struct FieldMap *battleSrc, struct BattleSetupParam *btlSetup)
{
    struct GameEvent *taskEvent;
    BattleTask *task;

    taskEvent = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)EVENT_BATTLE_ProcBattleTask, 0x28);
    task = GAME_EVENT_GetWork(taskEvent);
    EVENT_BATTLE_InitTaskWork(task, gameSystem, btlSetup);
    task->isScripted = 0;
    task->addTallies = 1;
    task->skipResultCheck = 1;
    task->encounterEffect = 9;
    task->btlSetup->bgmBattle = 0x46b;
    EFFECT_ENCOUNT_ConsumeSpot(FIELDMAP_GetEncount(battleSrc));
    return taskEvent;
}

/*
 * Set up the scripted catching-tutorial battle (Minccino Lv7 against
 * Patrat Lv2) and push EVENT_BATTLE_ProcBattleTask as its battleTask. First draft.
 */
struct GameEvent *EVENT_BATTLE_CreateCatchTutorial(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 heapId)
{
    struct FieldSituation location;
    u16 tempHeapId;
    struct GameData *gameData;
    struct BattleSetupParam *btlSetup;
    struct Party *playerParty;
    struct Party *opponentParty;
    struct PokemonParam *pokemon;
    struct GameEvent *battleTask;
    BattleTask *work;

    tempHeapId = (heapId & 0x7FFF) | 0x8000;
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    btlSetup = BTL_SETUP_Create(heapId);
    playerParty = POKEPARTY_Create(tempHeapId);
    opponentParty = POKEPARTY_Create(tempHeapId);
    pokemon = GFL_HEAP_Alloc(tempHeapId, POKE_TOOL_GetPartyParamSize(), 1, d_02172B54, 0x1DA);
    POKE_TOOL_SetupPartyParam(pokemon, 572, 7, 0);
    POKE_TOOL_SetPartyValue(pokemon, 0x36, 1);
    POKE_TOOL_SetPartyValue(pokemon, 0x37, 45);
    POKE_TOOL_SetPartyValue(pokemon, 0x38, 0);
    POKE_TOOL_SetPartyValue(pokemon, 0x39, 0);
    POKEPARTY_Add(playerParty, pokemon);
    POKE_TOOL_SetupPartyParam(pokemon, 504, 2, 0);
    POKE_TOOL_SetPartyValue(pokemon, 0x36, 33);
    POKE_TOOL_SetPartyValue(pokemon, 0x37, 43);
    POKE_TOOL_SetPartyValue(pokemon, 0x38, 0);
    POKE_TOOL_SetPartyValue(pokemon, 0x39, 0);
    POKEPARTY_Add(opponentParty, pokemon);
    FIELD_ENCOUNT_SetFieldSituation(&location, gameData, fieldMap);
    location.bgAttr = 5;
    location.bgType = 0;
    BTL_SETUP_SetupDemo(btlSetup, gameData, playerParty, opponentParty, &location, heapId);
    GFL_HEAP_Free(pokemon);
    GFL_HEAP_Free(opponentParty);
    GFL_HEAP_Free(playerParty);
    battleTask = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)EVENT_BATTLE_ProcBattleTask, 0x28);
    work = GAME_EVENT_GetWork(battleTask);
    EVENT_BATTLE_InitTaskWork(work, gameSystem, btlSetup);
    work->isScripted = 1;
    ENCEFF_SelectEffectAndBgm(504, 5, 0, fieldMap, &work->encounterEffect, &work->btlSetup->bgmBattle);
    work->encounterEffect = 0;
    return battleTask;
}

/*
 * Every concrete byte matches; the one wildcard is the bl to 0x02012FD8, an
 * unlabelled 12-byte arm9 Thumb leaf (ldr r0,[r0]; tail call
 * SAVE_CONTROL_GetBlock(r0, 0x43)) with no label, no shard and so no witness.
 * as `void *GAME_DATA_GetSaveBlock43(void **p) { return SAVE_CONTROL_GetBlock(*p, 0x43); }`
 * (symbols: SAVE_CONTROL_GetBlock 0x020071CC thumb), which is outside an overlay
 * lane's write set; once it has a shard this file should verify EXACT.
 *
 * The level argument to POKE_TOOL_SetupPartyParamEx is passed untruncated here, so its
 * extern takes u32 level rather than the u16 other callers declare.
 */
struct GameEvent *EVENT_BATTLE_CreateEncounterTaskWithMon(struct GameSystem *gameSystem, struct FieldMap *battleSrc, u32 battleMode, u32 battleFlags, u32 battleKind, u32 fieldEffect, u32 options, u32 entryIndex)
{
    void *giftData;
    struct GameEvent *task;
    void *mon;
    u32 oldSpecies;
    u32 species;
    u32 level;
    u32 id;
    u32 rnd;

    giftData = GAME_DATA_GetSaveBlock43(GAMESYSTEM_GetGameData(gameSystem));
    task = EVENT_BATTLE_CreateEncounterTask(gameSystem, battleSrc, battleMode, battleFlags, battleKind, fieldEffect, options);
    if (MON_SNAPSHOT_IsFilled(giftData, entryIndex) != 0) {
        mon = POKEPARTY_GetMember(*(void **)(*(u8 **)((u8 *)GAME_EVENT_GetWork(task) + 8) + 0x28), 0);
        oldSpecies = POKE_TOOL_GetPartyValue(mon, 5, 0);
        species = MON_SNAPSHOT_GetSpeciesForSlot(giftData, entryIndex, PM_VERSION_ID);
        level = MON_SNAPSHOT_GetLevel(giftData, entryIndex);
        id = MON_SNAPSHOT_GetOtId(giftData, entryIndex);
        rnd = MON_SNAPSHOT_GetPersonalRnd(giftData, entryIndex);
        POKE_TOOL_SetupPartyParamEx(mon, species, level, id, -1, rnd);
        if (MON_SNAPSHOT_HasAbility(giftData, entryIndex) != 0) {
            POKE_TOOL_SetPartyValue(mon, 10, MON_SNAPSHOT_GetAbility(giftData, entryIndex));
        }
        POKE_TOOL_SetPartyValue(mon, 0x74, (uptr)MON_SNAPSHOT_GetNickname(giftData, entryIndex));
        POKE_TOOL_ChangeSpecies(mon, (u16)oldSpecies);
        POKE_TOOL_SetDefaultMoves(mon);
    }
    return task;
}

/*
 * lever:    case 1's argument-less `bl FIELDMAP_GetEncEff` takes proc (the
 *           GAMESYSTEM_GetFieldMap result) as its hidden r0 argument: the matched
 *           ov021 definition is int FIELDMAP_GetEncEff(unsigned char *p). That
 *           keeps proc in r0 through the dispatch, the index in r1 and the
 *           r2 copy of proc for cases 2 and 10 (457 -> 2 bytes). The ov230
 *           probe calls resolve with the `ov230d` token, prototypes copied
 *           from the matched twin src/matched/arm9/GAMESYSTEM_ProcInit.c.
 * residue:  case 7 zeroes its spilled `ok` (sp+0xC) through r2 in the image
 *           (`movs r2,#0; str r2,[sp,#0xc]` at 0x0216ECCC), r0 in the compile.
 *           No change from ok as u32, u8, enum, function-scope, passed as the
 *           seed, or with start/end locals ahead of it; permuter 300 found
 *           nothing (baseline agrees, DIFF 2/612).
 *           unlabelled: `ldr r1,[r0]; str r1,[r0,#8]; movs r1,#0; str
 *           r1,[r0]; bx lr`, verified C not filed: arm9 is the integrator's);
 *           0x0216EFDC (ov010 unlabelled tail-call leaf, not filed while an
 *           arm9 leaf blocks); ov093_id/ov092_id pooled ids passed to
 *           GAME_EVENT_CallProc, which is not in OVERLAY_ID_CONSUMERS;
 *           d_021EFDAC/d_021B9D94 (proc data of ov093/ov092) unwitnessed.
 * prototype conflicts (parked, matched callees not edited):
 *           EVENT_BATTLE_FreeBtlSetup (ov010 0x0216F054, src/matched/ov/EVENT_BATTLE_FreeBtlSetup.c)
 *           is defined int(int a0, int a1) but a1 is overwritten before any
 *           read (`ldr r1,[r0,#0x20]` at 0x0216F054); the three call sites
 *           here set only r0 (`adds r0, r5, #0; bl`). GAME_DATA_GetPmsWork (arm9,
 *           src/matched/arm9/GAME_DATA_GetPmsWork.c) is defined int(int p0..p3) and
 *           reads only p0; both sites here set only r0 (`ldr r0,[sp,#0x10];
 *           bl`). The C below declares both with one parameter.
 * runs:     4 iteration + checks (2 + 2 + 1) + permuter 300; one cleanup run.
 * checks:   1 every callee re-derived from its matched definition: FIELDMAP_GetEncEff takes the live proc in r0 (fixed), F054/2F20 definitions over-declare (conflict above); 2 twin GAMESYSTEM_ProcInit gives the ov230d probe tokens and prototypes (resolved 3 sites), u32 start local no change; 3 ok as u32 / enum no change; 4 u8 flag idiom (a-narrow-flag-local-is-spilled) no change, zero-register idioms read; 5 idioms re-listed, nothing new applies
 * note:     2026-10-05 wave P19 lane 6 recoup: byte-correct (612/612, 0 bytes off).
 *           Lever: case 7 writes ok in both arms (`if (probe == ~f) ok = 1; else ok = 0;`
 *           with `int ok;` uninitialised), which moves the spilled zero to r2 (was r0,
 *           2 bytes). Tried before it: six per-function pragmas (lifetimes 14 B, the rest
 *           2 B), function-scope ok, ok as the probe seed or a separate zero local, probe
 *           result in a local (3 B), ternary sum (258 B). Data words resolve with
 *           `data ov093` / `data ov092` tokens. Leaf witnesses filed:
 *           src/matched/arm9/COMM_PLAYER_SUPPORT_StashMode.c and src/matched/ov/EVENT_BATTLE_IsTaskResultSilent.c (both
 *           EXACT c99 and c); the three unresolved call sites resolve once the integrator
 *           refreshes the manifest. Callee arity conflicts (matched definitions
 *           over-declare, callers pass less): EVENT_BATTLE_FreeBtlSetup and GAME_DATA_GetPmsWork.
 */
int EVENT_BATTLE_ProcBattleTask(void *event, u32 *state, BattleTask *work)
{
    void *gameSystem = work->gameSystem;
    void *gameData = work->gameData;
    void *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    u32 integritySum = 0x013A1AB5;

    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(gameSystem, work->btlSetup->bgmBattle));
        (*state)++;
        break;
    case 1:
        ENCEFF_Start((void *)FIELDMAP_GetEncEff(fieldMap), (struct GameEvent *)event, (int)work->encounterEffect);
        (*state)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, (void *)FIELD_STATUS_CreateFieldCloseEvent((struct GameSystem *)gameSystem, (struct FieldMap *)fieldMap));
        (*state)++;
        break;
    case 3:
        FIELD_STATUS_SwapSeasonDispFlag(GAME_DATA_GetMoveModelSys(gameData), 1);
        COMM_PLAYER_SUPPORT_Init(GAME_DATA_GetPmsWork((struct GameData *)gameData));
        GAME_EVENT_CallProc(event, (uptr)ov093_id, (void *)d_021EFDAC, (void *)work->btlSetup);
        (*state)++;
        break;
    case 4:
        work->procBtlSetup = work->btlSetup;
        work->procGameData = gameData;
        GAME_EVENT_CallProc(event, (uptr)ov092_id, (void *)d_021B9D94, (void *)&work->procGameData);
        (*state)++;
        break;
    case 5:
        GF_OVERLAY_Load((sptr)ov230_id);
        FIELD_STATUS_SwapSeasonDispFlag(GAME_DATA_GetMoveModelSys(gameData), 0);
        COMM_PLAYER_SUPPORT_StashMode(GAME_DATA_GetPmsWork((struct GameData *)gameData));
        (*state)++;
        break;
    case 6: {
        int probeOk = 0;

        if (OV230_CallSealedBody1((void (*)(void))EVENT_BATTLE_CallAndInvert, (void (*)(void))EVENT_BATTLE_IntegrityProbeA, 0) == ~(uptr)EVENT_BATTLE_IntegrityProbeA)
            probeOk = 1;
        integritySum += probeOk ? 0 : 0x3D1;
        EVENT_BATTLE_FinishBattleTask(work, gameData);
        if (work->addTallies != 0)
            FLD_BTL_INST_TOOL_AddBattleTally(*(void **)GAME_DATA_GetListCursor(gameData), (struct BattleSetupParam *)work->btlSetup);
        (*state)++;
        probeOk = 0;
        if (OV230_CallSealedBody3((void (*)(void))EVENT_BATTLE_CallAndInvert, (void (*)(void))EVENT_BATTLE_IntegrityProbeB, 0) == ~(uptr)EVENT_BATTLE_IntegrityProbeB)
            probeOk = 1;
        integritySum += probeOk ? 0 : 0x5D1;
        break;
    }
    case 7: {
        int probeOk;

        if (OV230_CallSealedBody4((void (*)(void))EVENT_BATTLE_CallAndInvert, (void (*)(void))EVENT_BATTLE_IntegrityDecoyC, 0) == ~(uptr)EVENT_BATTLE_IntegrityDecoyC)
            probeOk = 1;
        else
            probeOk = 0;
        integritySum += probeOk * 0x9D;
        if (work->skipResultCheck == 0 && EVENT_BATTLE_IsTaskResultSilent(work) == 1)
            GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartFadeOutAndResetTask(gameSystem, 0x1E));
        else
            GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(gameSystem));
        GF_OVERLAY_Unload((sptr)ov230_id);
        (*state)++;
        break;
    }
    case 8:
        if (work->skipResultCheck == 0 && EVENT_BATTLE_IsTaskResultSilent(work) == 1) {
            if (work->isScripted == 1) {
                EVENT_BATTLE_FreeBtlSetup(work);
                return 1;
            }
            EVENT_BATTLE_FreeBtlSetup(work);
            GAME_EVENT_ChangeEvent(event, SCRCMD_NETWORK_CreateCommProcEvent(gameSystem));
            return 0;
        }
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*state)++;
        break;
    case 9:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(gameSystem));
        (*state)++;
        break;
    case 10:
        if (work->isScripted == 0)
            GAME_EVENT_CallEvent(event, (void *)(sptr)EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, (void *)((sptr)fieldMap), 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 11:
        EVENT_BATTLE_FreeBtlSetup(work);
        return 1;
    }
    if (integritySum % 0x1933 != 0) {
        GFL_USE_AddMainTask((TcbFunc)GAMESYSTEM_RandTwice, 0, 0x7F);
        g_0214624C++;
    }
    return 0;
}

/*
 * Mode word out of the overlay call decides between zero, one and two;
 * two of the modes are refused outright.
 */
int EVENT_BATTLE_GetBattleKindClass(u32 trainerId)
{
    int r = 1;
    int v;

    v = TPOKE_DATA_GetTrainerKind(TPOKE_DATA_GetRecordField((void *)(uptr)trainerId, 1));

    if (v == 0xC || v == 9)
        return 0;
    if (v != 2)
        r = 2;

    return r;
}

/*
 * Dispatches through the two-column handler table d_021725C0, row chosen
 * by EVENT_BATTLE_GetBattleKindClass's classification of `id`.
 */
void EVENT_BATTLE_DispatchBattleKindNotify(u16 id, int col)
{
    d_021725C0[EVENT_BATTLE_GetBattleKindClass(id)][col](id);
}

/*
 * Reports the species of the first party member to one of three
 * notifiers.
 *
 * MATCH, first draft (2026-09-28 tree_ov010_4): the one wildcard is arm9
 * 0x0201313C, an unlabelled Thumb leaf (`lsls r1, #2; adds r0, r1;
 * ldr r0, [r0, #0x24]; bx lr`) inside the listing's ARM data run.
 *
 * 2026-10-05: byte-identical; the wildcard is arm9 BTL_SETUP_GetParty (matched file exists, no shard yet); integrator shard resolves it.
 */
void EVENT_BATTLE_NotifyLeadSpecies(void *btlSetup, int which)
{
    u16 species;

    species = POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(BTL_SETUP_GetParty(btlSetup, 1), 0), 5, 0);
    switch (which) {
    case 0:
        GAME_BEACON_SEARCH_SetBattlePokeStart(species);
        break;
    case 1:
        GAME_BEACON_SEARCH_SetBattlePokeWin(species);
        break;
    case 2:
        GAME_BEACON_SEARCH_SetPokeEvent(species);
        break;
    }
}

/*
 * After a battle: unless the outcome is 0 or 2, reports the lead party
 * member's state (fainted, at half HP or less, a move out of PP, a status
 * condition) by name, then reports the species depending on the mode and
 * outcome.
 */
void EVENT_BATTLE_NotifyBattleEnd(BattleEndCtx *ctx)
{
    struct BattleSetupParam *setup;
    void *playerParty;
    void *leadMon;
    void *nameBuf;
    u16 curHp;
    u16 maxHp;
    int moveIndex;

    setup = ctx->btlSetup;
    playerParty = GAME_DATA_GetMyParty(ctx->btlSetupObj);
    leadMon = POKEPARTY_GetMember(playerParty, POKEPARTY_FindFirstNonEgg(playerParty));
    if (setup->outcome != 0 && setup->outcome != 2) {
        nameBuf = STRBUF_Create(12, 0x8004);
        POKE_TOOL_GetPartyValue(leadMon, 0x73, (uptr)nameBuf);
        curHp = POKE_TOOL_GetPartyValue(leadMon, 0xA0, 0);
        maxHp = POKE_TOOL_GetPartyValue(leadMon, 0xA1, 0);
        if (curHp == 0)
            GAME_BEACON_SEARCH_SetEventBattleNameC(nameBuf);
        else if (curHp * 2 <= maxHp)
            GAME_BEACON_SEARCH_SetEventBattleNameA(nameBuf);
        for (moveIndex = 0; moveIndex < 4; moveIndex++) {
            if (POKE_TOOL_GetPartyValue(leadMon, 0x36 + moveIndex, 0) != 0 && POKE_TOOL_GetPartyValue(leadMon, 0x3A + moveIndex, 0) == 0) {
                GAME_BEACON_SEARCH_SetEventBattleNameB(nameBuf);
                break;
            }
        }
        if (POKE_TOOL_GetPartyValue(leadMon, 0x9D, 0) != 0)
            GAME_BEACON_SEARCH_SetEventBattleNameD(nameBuf);
        STRBUF_Delete(nameBuf);
    }
    switch (setup->competitor) {
    case 0:
        if (setup->outcome == 3)
            EVENT_BATTLE_NotifyLeadSpecies(setup, 2);
        else if (setup->outcome == 1)
            EVENT_BATTLE_NotifyLeadSpecies(setup, 1);
        break;
    case 1:
        if (setup->outcome == 1)
            EVENT_BATTLE_DispatchBattleKindNotify(setup->trainerData[1]->trainerId, 1);
        break;
    }
}

void EVENT_BATTLE_AddBattleRecord(BattleTask *task)
{
    struct BattleSetupParam *btlSetup = task->btlSetup;
    void *gameData = GAMESYSTEM_GetGameData(task->gameSystem);
    struct RecordBlock *records = (struct RecordBlock *)GAME_DATA_GetTrainerRecord(gameData);

    if (btlSetup->competitor == 0 && btlSetup->outcome == 4)
        RECORD_AddOne(records, 0x4f);
}

int EVENT_BATTLE_IsResultSilent(int outcome, int mode)
{
    if (mode == 4)
        return 0;
    if (d_021725D8[outcome][mode] == 0)
        return 1;
    return 0;
}

/*
 * Unlabelled leaf, blocker of ov021 SCRCMD_PROC_FLD_StoreByteValue: byte table lookup, 0xFF maps to 1.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u8 EVENT_BATTLE_GetResultFlag(int kindId)
{
    u8 flag = d_021725B8[kindId];

    if (flag == 0xff) {
        flag = 1;
    }
    return flag;
}

/*
 * note:     2026-10-05 wave P19 lane 6: tiny unlabelled tail-call leaf filed as
 *           the witness for the calls in ov010 EVENT_BATTLE_ProcBattleTask. Reads the info
 *           block at w[2] and tail-calls EVENT_BATTLE_IsResultSilent(info[0x8c / 4], info[0]).
 */
int EVENT_BATTLE_IsTaskResultSilent(BattleTask *task)
{
    struct BattleSetupParam *btlSetup = task->btlSetup;
    return EVENT_BATTLE_IsResultSilent(btlSetup->outcome, btlSetup->competitor);
}

/*
 * WEATHER_StoreZoneWeatherId's body consumes only r0/r1, forwarding those to
 * ISS_SWITCH_GetSubscreenMode; original supplies no new r2/r3. Legacy trailing
 * arguments are omitted. GAME_DATA_GetPlayerZoneId consumes the preceding result.
 */
void EVENT_BATTLE_FinishBattleTask(BattleTask *task, void *gameSystem)
{
    GAME_DATA_SetLastBattleResult(gameSystem, task->btlSetup->outcome);
    MOVE_POKEMON_HandleBattleResult(gameSystem, (struct BattleResultWork *)task->btlSetup);
    EVENT_BATTLE_NotifyBattleEnd((struct BattleEndCtx *)task);
    EVENT_BATTLE_AddBattleRecord(task);
    WEATHER_StoreZoneWeatherId(task->gameSystem, GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(gameSystem)));
}

void EVENT_BATTLE_InitTaskWork(BattleTask *task, void *gameSystem, void *btlSetup)
{
    int zero = 0;

    MIi_CpuClear32(0, task, 40);
    task->gameSystem = gameSystem;
    task->gameData = GAMESYSTEM_GetGameData(gameSystem);
    task->btlSetup = btlSetup;
    task->isScripted = zero;
    task->skipResultCheck = zero;
    task->addTallies = zero;
}

void EVENT_BATTLE_FreeBtlSetup(BattleTask *task)
{
    if (task->keepBtlSetup == 0)
        BTL_SETUP_Delete(task->btlSetup);
}

int EVENT_BATTLE_IntegrityProbeA(int unused)
{
    GF_STANDARD_Rand();
    return GF_STANDARD_Rand();
}

int EVENT_BATTLE_IntegrityProbeB(int unused)
{
    GF_STANDARD_Rand();
    return GF_STANDARD_Rand();
}

int EVENT_BATTLE_IntegrityDecoyC(int unused)
{
    GF_STANDARD_Rand();
    return GF_STANDARD_Rand();
}
