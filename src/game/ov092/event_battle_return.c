/*
 * file:     event_battle_return.c
 * unit:     yes
 * function: EVENT_BATTLE_RETURN_Init, EVENT_BATTLE_RETURN_Exit, EVENT_BATTLE_RETURN_Main, EVENT_BATTLE_RETURN_FlagLeveledUpMembers, EVENT_BATTLE_RETURN_ApplyPickupAndHoneyGather, EVENT_BATTLE_RETURN_ApplyNaturalCure, EVENT_BATTLE_RETURN_ApplyBurmyForms, EVENT_BATTLE_RETURN_GetBurmyForm, EVENT_BATTLE_RETURN_RegisterShayminForms, EVENT_BATTLE_RETURN_ApplyHealBall
 * address:  0x021B95A0
 * region:   ov092
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * extent: code ends at 0x021B9D44; remaining handed extent is rodata.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   STRBUF_Create  0x020457B0  arm
 *   PROCSYS_Create  0x02031324  arm
 *   PROCSYS_Delete 0x0203133C arm
 *   STRBUF_Delete 0x02045808 arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   PROCSYS_Main 0x02031330 arm
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   GAME_DATA_GetBoxManager 0x0201293C thumb
 *   POKEPARTY_Copy 0x0201AC2C thumb
 *   POKERUS_TryInfectParty 0x0201B038 thumb
 *   POKERUS_SpreadParty 0x0201B170 thumb
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   MISC_AddMoney 0x0200C278 thumb
 *   MISC_SubMoney 0x0200C29C thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   MYSTATUS_NameToStrbuf 0x02008500 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetCapacity 0x0201AA14 thumb
 *   BOX_SAVEDATA_GetCurrentBox 0x02007698 thumb
 *   BOX_SAVEDATA_FindFreeSlot 0x020076D0 thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GAME_DATA_GetMyPlayerWork 0x020127A4 thumb
 *   GAME_DATA_GetPlayerZoneId 0x02012AC8 thumb
 *   ZONEDATA_GetPlaceNameId 0x02013E4C thumb
 *   SAVE_EVENT_Write 0x0202F190 thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled 0x0200CA38 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   ZUKAN_SAVE_IsCaught 0x0200CED4 thumb
 *   ZUKAN_SAVE_RegisterSeen 0x0200CFA0 thumb
 *   ZUKAN_SAVE_RegisterCaught 0x0200CDE0 thumb
 *   PROCSYS_Push 0x02031348 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MISC_GetBlock 0x0200C0F0 thumb
 *   NAMEIN_SETUP_CreateCaptureArgs 0x0216C0A4 thumb ov010
 *   NAMEIN_SETUP_IsCanceled 0x0216C0E4 thumb ov010
 *   NAMEIN_SETUP_CopyName 0x0216C0D4 thumb ov010
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   RECORD_AddOne 0x02008DF0 thumb
 *   NAMEIN_SETUP_FreeArgs 0x0216C0C0 thumb ov010
 *   POKEPARTY_Add 0x0201A98C thumb
 *   POKE_TOOL_CastToBoxParam 0x020185F0 thumb
 *   BOX_SAVEDATA_AddPokemon 0x020074D8 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   GAME_DATA_GetSeason 0x02012984 thumb
 *   SHINKA_CHECK_CheckEvolution 0x0201B2B0 thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   gCatchRegistrationProcData 0x0220BAB0 data a4 ov207
 *   data_021F5580 0x021F5580 data a4 ov194
 *   data_02208C40 0x02208C40 data a4 ov195
 *   ov207_id 0x000000CF data a1
 *   ov194_id 0x000000C2 data a1
 *   ov195_id 0x000000C3 data a1
 *   sSourceFileName 0x021B9DC0 data a1
 *   _u32_div_f 0x0209C2B0 arm
 *   sPickupRollThresholds 0x021B9D44 data a1
 *   sPickupCommonItems 0x021B9D6E data ov092 a2
 *   sPickupRareItems 0x021B9D58 data ov092 a2
 *   sHoneyGatherChance 0x021B9D4D data ov092 a1
 *   POKE_TOOL_SetStatusCondition  0x02017F9C  thumb
 *   FLDMMDL_ApplyBurmyFormForPlace  0x0216E62C  thumb  ov010
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb  arm9
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb  arm9
 *   GFL_USE_GetRandom  0x020056EC  thumb  arm9
 */
#define MON_PARAM_HELD_ITEM 6
#define MON_PARAM_ABILITY 0xa
#define MON_PARAM_NICKNAME 115
#define MON_PARAM_ORIGINAL_TRAINER_NAME 141
#define MON_PARAM_LEVEL 0x9e
#define MON_PARAM_SPECIES_OR_EGG 0xab
#define SPECIES_EGG 0x28a
#define SPECIES_SHAYMIN 0x1ec
#define ABILITY_NATURAL_CURE 0x1e
#define ABILITY_PICKUP 0x35
#define ABILITY_HONEY_GATHER 0x76
#define ITEM_HONEY 0x5e
#define EVENT_FLAG_BOX_NOTICE_SEEN 0x96d
#define RECORD_NICKNAMED_COUNT 30
#define MAX_NICKNAME_LENGTH 10
#define BGM_FADE_FRAMES 30
#define BURMY_FORM_ARCHIVE 0x98
#define LINE_OF_HEAP_ALLOC 0x1ca
#define MON_PARAM_HP 0xa0
#define MON_PARAM_MAX_HP 0xa1
#define BALL_HEAL 14
struct ProcObj;
struct ProcSys;
struct SubProcTable;
struct NameInArgs;
struct GameData;
struct PokeParty;
struct PokemonParam;
struct BoxPokemon;
struct BoxManager;
struct MyStatus;
struct MiscSave;
struct SaveControl;
struct ZukanSave;
struct EventWork;
struct PlayerWork;
struct RecordBlock;
struct Strbuf;
struct MsgBank;
#include "../types.h"

/*
 * The battle parameter object (BattleSetupParam, btl_setup_types.h) seen from
 * the result side. Its header names are inferred for offsets past 0x84; the
 * names here come from how this file reads the battle results, so the header
 * should take these (moneyDelta, outcome, capturedIndex, participated).
 */
struct BattleField {
    s32 bgType;
    s32 bgAttr;
    u8 weather;
    u8 season;
    u16 zoneId;
    u8 hour;
    u8 minute;
    u8 pad0e[2];
};

struct BattleReturnParam {
    u32 competitor;
    u8 pad04[4];
    struct BattleField field;
    u8 pad18[0xc];
    struct PokeParty *playerParty;
    struct PokeParty *opponentParty;
    u8 pad2c[0x5c];
    s32 moneyDelta;
    u32 outcome;
    u8 capturedIndex;
    u8 pad91[0x31];
    u8 participated[6];
};

/* Arguments of the event: the game data and the finished battle's parameters. */
struct EventBattleReturnArgs {
    struct GameData *gameData;
    struct BattleReturnParam *battleParam;
};

/* Arguments of the catch registration screen (overlay 207). */
struct CatchRegistrationArgs {
    u32 wasAlreadyCaught;
    struct PokemonParam *mon;
    u32 dexMode;
    struct Strbuf *boxFullMsg;
    struct BoxManager *boxManager;
    u32 boxNo;
    struct GameData *gameData;
    u32 wantsNickname;
};

/* Work of the step machine, allocated with the proc (0x4c bytes). */
struct EventBattleReturnWork {
    struct NameInArgs *nameInArgs;
    struct Strbuf *nameBuf;
    struct PokemonParam *caughtMon;
    struct CatchRegistrationArgs catchArgs;
    struct Strbuf *boxFullMsg;
    u32 boxNo;
    struct EvolutionRequest *evolutionRequest;
    u16 scanIndex;
    u16 levelUpMask;
    u16 heapId;
    u8 pad3e[2];
    struct ProcSys *procSys;
    u32 bgmSettled;
    u32 bgmFadeStarted;
};

/* One 0x24-byte record per battle background of the Burmy form table. */
struct BurmyFormRecord {
    u8 header[0x13];
    u8 formByAttr[0x11];
};

#include "../ov010/evolution_request_types.h"
#include "../arm9/gfl_heap.h"
struct Proc;
#include "../arm9/procsys.h"
#include "../arm9/strbuf.h"
#include "../ov010/fld_btl_inst_tool_shared_types.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/game_data.h"
#include "../arm9/zukan_save.h"
struct Party;
#include "../arm9/pokeparty.h"
#include "../arm9/pokerus.h"
#include "../arm9/beacon.h"
#include "../arm9/mystatus.h"
#include "../arm9/poke_tool.h"
#include "../arm9/box_savedata.h"
#include "../arm9/msgdata.h"
#include "../arm9/zonedata.h"
#include "../arm9/save_event.h"
#include "../ov010/namein_setup.h"
#include "../arm9/record.h"
#include "../arm9/gfl_use.h"
#ifdef __MWERKS__
#define SHINKA_CHECK_CheckEvolution SHINKA_CHECK_CheckEvolutionHeader
#endif
#include "../arm9/shinka_check.h"
#ifdef __MWERKS__
/* original prototypes: the DS code declares these with other argument or return types than the definitions */
#undef SHINKA_CHECK_CheckEvolution
extern u16 SHINKA_CHECK_CheckEvolution(struct Party *party, struct PokemonParam *mon, u32 mode, u32 zoneId, u8 season, u32 *method, u16 heapId);
#endif
#include "../ov010/fldmmdl_poslog.h"
#include "../arm9/arc_tool.h"
int EVENT_BATTLE_RETURN_Init(struct ProcObj *proc);
int EVENT_BATTLE_RETURN_Exit(struct ProcObj *proc, u32 seq, u32 pwk, struct EventBattleReturnWork *work);
int EVENT_BATTLE_RETURN_Main(struct ProcObj *proc, u32 *seq, struct EventBattleReturnArgs *args, struct EventBattleReturnWork *work);
void EVENT_BATTLE_RETURN_FlagLeveledUpMembers(struct EventBattleReturnWork *work, struct EventBattleReturnArgs *args);
void EVENT_BATTLE_RETURN_ApplyPickupAndHoneyGather(struct PokeParty *party);
void EVENT_BATTLE_RETURN_ApplyNaturalCure(struct PokeParty *party);
void EVENT_BATTLE_RETURN_ApplyBurmyForms(struct EventBattleReturnArgs *args, struct PokeParty *party, int burmyForm);
u32 EVENT_BATTLE_RETURN_GetBurmyForm(const struct BattleField *field, u16 heapId);
void EVENT_BATTLE_RETURN_RegisterShayminForms(struct EventBattleReturnArgs *args, struct PokeParty *party);
void EVENT_BATTLE_RETURN_ApplyHealBall(struct PokemonParam *mon);
/* Overlay ids of the sub-screens this step machine starts. */
extern const u8 ov207_id[], ov194_id[], ov195_id[];
extern const struct SubProcTable gCatchRegistrationProcData, data_021F5580, data_02208C40;
extern const u8 sSourceFileName[];
extern const u8 sPickupRollThresholds[];
extern const u16 sPickupCommonItems[];
extern const u16 sPickupRareItems[];
extern const u8 sHoneyGatherChance[];

/* Heap created for the whole after-battle processing; freed in the exit step. */
#define EVENT_BATTLE_RETURN_HEAP_ID 0x52

/* Parameter ids of the get/set party-value accessors. */
#define MON_PARAM_SPECIES 5

/* Values of BattleReturnParam.outcome that matter here. */
enum {
    BATTLE_OUTCOME_WIN = 1,
    BATTLE_OUTCOME_DRAW = 3,
    BATTLE_OUTCOME_CAUGHT = 5
};

/* Values of BattleReturnParam.competitor: 0 and 1 are wild and trainer fights. */
#define COMPETITOR_LAST_NORMAL 1

/* Step machine init: heap, work, name buffer and sub-proc system. */
int EVENT_BATTLE_RETURN_Init(struct ProcObj *proc)
{
    struct EventBattleReturnWork *work;

    GFL_HEAP_CreateChildHeap(1, EVENT_BATTLE_RETURN_HEAP_ID, 0x1000);
    work = PROCSYS_AllocProcWork((struct Proc *)proc, 0x4c, EVENT_BATTLE_RETURN_HEAP_ID);
    work->nameBuf = STRBUF_Create(0x20, EVENT_BATTLE_RETURN_HEAP_ID);
    work->nameInArgs = 0;
    work->caughtMon = 0;
    work->boxFullMsg = 0;
    work->boxNo = 0;
    work->evolutionRequest = 0;
    work->heapId = EVENT_BATTLE_RETURN_HEAP_ID;
    work->procSys = PROCSYS_Create(work->heapId);
    work->bgmSettled = 0;
    work->bgmFadeStarted = 0;
    return 1;
}

/* Step machine exit: frees the sub-proc system, both strings, the work and the heap. */
int EVENT_BATTLE_RETURN_Exit(struct ProcObj *proc, u32 seq, u32 pwk, struct EventBattleReturnWork *work)
{
    PROCSYS_Delete(work->procSys);
    if (work->boxFullMsg) STRBUF_Delete(work->boxFullMsg);
    STRBUF_Delete(work->nameBuf);
    PROCSYS_FreeProcWork((struct Proc *)proc);
    GFL_HEAP_DeleteChecked(EVENT_BATTLE_RETURN_HEAP_ID);
    return 1;
}

/*
 * Step machine main. Steps: 0 applies the battle results to the party and, for
 * a caught Pokemon, starts the catch registration screen; 1 starts the
 * nickname screen if the player wants one; 2 stores the nickname; 3 puts the
 * caught Pokemon into the party or a box; 4 scans the members that gained a
 * level for an evolution; 5 waits for the evolution screen; 6 ends.
 *
 * note: 2026-10-05 matched. Loader order (context, id, descriptor, argument). Closing forms: case 1, 2 and 5 are
 *   `if (busy != 1) { body; break; } return 0;` (return block after the body); `ok = 0; if (f == 1) ok = 1;`;
 *   `if (flag) x = 0; else x = 1;`; `case 6: default: return 1;`; the case 4 tail `r68 = 1; break;` written in
 *   the guarded arm and again after it (cross-jumped copy leaves the b stub); species and slot as u16 locals,
 *   box/bslot declared first; the source record pointer s is not const. Case 4 mask and slot use a two-field view.
 */
int EVENT_BATTLE_RETURN_Main(struct ProcObj *proc, u32 *seq, struct EventBattleReturnArgs *args, struct EventBattleReturnWork *work)
{
    u32 busy;
    struct PokeParty *party;
    int box, boxSlot;
    u32 method;
    struct PokemonParam *mon;
    struct MyStatus *myStatus;
    struct ZukanSave *zukan;
    struct BoxManager *boxManager;
    struct MsgBank *msgBank;
    struct MiscSave *miscSave;
    int moneyDelta, partyCount, msgIndex;
    int isNewSpecies, wantsNickname;
    unsigned long dexMode;
    u16 species;
    u16 slot;
    struct EvolutionRequest *evolutionRequest;
    busy = PROCSYS_Main(work->procSys);
    if (busy == 1) return 0;
    switch (*seq) {
    case 0:
        party = GAME_DATA_GetMyParty(args->gameData);
        myStatus = GAME_DATA_GetMyStatus(args->gameData);
        zukan = ZUKAN_SAVE_GetFromGameData(args->gameData);
        boxManager = (struct BoxManager *)GAME_DATA_GetBoxManager(args->gameData);
        work->scanIndex = 0;
        work->levelUpMask = 0;
        if (args->battleParam->competitor <= COMPETITOR_LAST_NORMAL) {
            EVENT_BATTLE_RETURN_FlagLeveledUpMembers(work, args);
            POKEPARTY_Copy((struct Party *)args->battleParam->playerParty, (struct Party *)party);
            POKERUS_TryInfectParty((struct Party *)party);
            POKERUS_SpreadParty((struct Party *)party);
            if (args->battleParam->outcome == BATTLE_OUTCOME_WIN) EVENT_BATTLE_RETURN_ApplyPickupAndHoneyGather(party);
            EVENT_BATTLE_RETURN_ApplyBurmyForms(args, party, EVENT_BATTLE_RETURN_GetBurmyForm(&args->battleParam->field, work->heapId));
            EVENT_BATTLE_RETURN_RegisterShayminForms(args, party);
            moneyDelta = args->battleParam->moneyDelta;
            if (moneyDelta > 0) MISC_AddMoney(GAME_DATA_GetMiscSave(args->gameData), moneyDelta);
            else if (moneyDelta < 0) MISC_SubMoney(GAME_DATA_GetMiscSave(args->gameData), -moneyDelta);
        }
        EVENT_BATTLE_RETURN_ApplyNaturalCure(party);
        if (args->battleParam->outcome == BATTLE_OUTCOME_CAUGHT) {
            work->caughtMon = POKEPARTY_GetMember((struct Party *)args->battleParam->opponentParty, args->battleParam->capturedIndex);
            MYSTATUS_NameToStrbuf((u16 *)myStatus, work->nameBuf);
            POKE_TOOL_SetPartyValue(work->caughtMon, MON_PARAM_ORIGINAL_TRAINER_NAME, (uptr)work->nameBuf);
            partyCount = (int)POKEPARTY_GetCount((struct Party *)party);
            if (partyCount >= (int)POKEPARTY_GetCapacity((struct Party *)party)) {
                box = BOX_SAVEDATA_GetCurrentBox((struct GameData *)boxManager); boxSlot = 0;
                BOX_SAVEDATA_FindFreeSlot((struct GameData *)boxManager, &box, &boxSlot);
                work->boxNo = box;
                msgBank = MSGDATA_CreateFromArchive(0, 2, 234, EVENT_BATTLE_RETURN_HEAP_ID);
                msgIndex = ZONEDATA_CheckEventFlag(GAME_DATA_GetEventWork(args->gameData), EVENT_FLAG_BOX_NOTICE_SEEN) ? 177 : 176;
                work->boxFullMsg = MSGDATA_AllocString(msgBank, msgIndex);
                MSGDATA_Delete(msgBank);
            }
            SAVE_EVENT_Write(work->caughtMon, 0, myStatus, ZONEDATA_GetPlaceNameId(GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(args->gameData))), work->heapId);
            isNewSpecies = 0;
            dexMode = ZUKAN_SAVE_IsNationalDexEnabled(zukan);
            if (ZUKAN_SAVE_IsCaught(zukan, POKE_TOOL_GetPartyValue(work->caughtMon, MON_PARAM_SPECIES, 0)) == 0) isNewSpecies = 1;
            ZUKAN_SAVE_RegisterSeen(zukan, work->caughtMon);
            ZUKAN_SAVE_RegisterCaught(zukan, work->caughtMon);
            work->catchArgs.dexMode = dexMode;
            work->catchArgs.mon = work->caughtMon;
            work->catchArgs.boxFullMsg = work->boxFullMsg;
            work->catchArgs.boxManager = boxManager;
            work->catchArgs.boxNo = work->boxNo;
            work->catchArgs.gameData = args->gameData;
            if (isNewSpecies) work->catchArgs.wasAlreadyCaught = 0; else work->catchArgs.wasAlreadyCaught = 1;
            PROCSYS_Push((ProcSys *)work->procSys, (uptr)ov207_id, (const ProcData *)&gCatchRegistrationProcData, (void *)&work->catchArgs);
            ++*seq;
        } else *seq = 4;
        break;
    case 1:
        if (busy != 1) {
        boxManager = (struct BoxManager *)GAME_DATA_GetBoxManager(args->gameData);
        wantsNickname = 0;
        if (work->catchArgs.wantsNickname == 1) wantsNickname = 1;
        if (wantsNickname) {
            miscSave = MISC_GetBlock(GAME_DATA_GetSaveControl(args->gameData));
            work->nameInArgs = NAMEIN_SETUP_CreateCaptureArgs(work->heapId, work->caughtMon, MAX_NICKNAME_LENGTH, 0, work->boxFullMsg, boxManager, work->boxNo, miscSave);
            PROCSYS_Push((ProcSys *)work->procSys, (uptr)ov194_id, (const ProcData *)&data_021F5580, (void *)work->nameInArgs);
            ++*seq;
        } else *seq = 3;
        break;
        }
        return 0;
    case 2:
        if (busy != 1) {
        if (!NAMEIN_SETUP_IsCanceled(work->nameInArgs)) {
            NAMEIN_SETUP_CopyName(work->nameInArgs, work->nameBuf);
            POKE_TOOL_SetPartyValue(work->caughtMon, MON_PARAM_NICKNAME, (uptr)work->nameBuf);
            RECORD_AddOne(GAME_DATA_GetTrainerRecord(args->gameData), RECORD_NICKNAMED_COUNT);
        }
        NAMEIN_SETUP_FreeArgs(work->nameInArgs);
        work->nameInArgs = 0;
        ++*seq;
        break;
        }
        return 0;
    case 3:
        party = GAME_DATA_GetMyParty(args->gameData);
        EVENT_BATTLE_RETURN_ApplyHealBall(work->caughtMon);
        if (!work->boxFullMsg) POKEPARTY_Add((struct Party *)party, work->caughtMon);
        else {
            boxManager = (struct BoxManager *)GAME_DATA_GetBoxManager(args->gameData);
            BOX_SAVEDATA_AddPokemon((struct GameData *)boxManager, (struct BoxPokemon *)POKE_TOOL_CastToBoxParam(work->caughtMon));
        }
        ++*seq;
        break;
    case 4: {
        struct PokeParty *scanParty;
        if (!work->bgmSettled) {
            if (args->battleParam->outcome == BATTLE_OUTCOME_CAUGHT && work->levelUpMask) {
                if (!work->bgmFadeStarted) { GFL_USE_FadeOutBgm(BGM_FADE_FRAMES); work->bgmFadeStarted = 1; break; }
                if (GFL_USE_IsBgmFading()) break;
                GFL_USE_CancelChangeAndStopBgm();
                work->bgmSettled = 1;
                break;
            }
            work->bgmSettled = 1;
            break;
        }
        if (work->levelUpMask) {
            species = 0;
            scanParty = GAME_DATA_GetMyParty(args->gameData);
            *seq = 6;
            while (work->levelUpMask) {
                if (work->levelUpMask & 1) {
                    mon = POKEPARTY_GetMember((struct Party *)scanParty, work->scanIndex);
                    species = SHINKA_CHECK_CheckEvolution((struct Party *)scanParty, mon, 0, args->battleParam->field.zoneId, GAME_DATA_GetSeason(args->gameData), &method, work->heapId);
                    slot = work->scanIndex;
                }
                work->levelUpMask = work->levelUpMask >> 1;
                work->scanIndex++;
                if (species) {
                    evolutionRequest = GFL_HEAP_Alloc(work->heapId, 20, 0, (const char *)sSourceFileName, LINE_OF_HEAP_ALLOC);
                    evolutionRequest->gameData = args->gameData; evolutionRequest->party = scanParty; evolutionRequest->targetSpecies = species; evolutionRequest->partySlot = slot; evolutionRequest->evolveCondition = method; evolutionRequest->fromTrade = 0; evolutionRequest->fromField = 1;
                    work->evolutionRequest = evolutionRequest;
                    PROCSYS_Push((ProcSys *)work->procSys, (uptr)ov195_id, (const ProcData *)&data_02208C40, (void *)evolutionRequest);
                    *seq = 5;
                    break;
                }
            }
        } else *seq = 6;
        break;
    }
    case 5:
        if (busy != 1) {
        GFL_HEAP_Free(work->evolutionRequest);
        work->evolutionRequest = 0;
        if (work->levelUpMask) *seq = 4;
        else ++*seq;
        break;
        }
        return 0;
    case 6:
    default:
        return 1;
    }
    return 0;
}

/* Sets bit i of levelUpMask for each member whose level is higher after the battle. */
void EVENT_BATTLE_RETURN_FlagLeveledUpMembers(struct EventBattleReturnWork *work, struct EventBattleReturnArgs *args)
{
    struct BattleReturnParam *battleParam = args->battleParam;
    struct PokeParty *partyBefore;
    int count;
    int i;
    u16 *mask;

    if (battleParam->outcome == BATTLE_OUTCOME_WIN || battleParam->outcome == BATTLE_OUTCOME_DRAW || battleParam->outcome == BATTLE_OUTCOME_CAUGHT) {
        switch (battleParam->competitor) {
        case 0:
        case 1:
            partyBefore = GAME_DATA_GetMyParty(args->gameData);
            count = POKEPARTY_GetCount((struct Party *)partyBefore);
            i = 0;
            if (count > 0) {
                mask = &work->levelUpMask;
                do {
                    struct PokemonParam *monBefore = POKEPARTY_GetMember((struct Party *)partyBefore, i);
                    struct PokemonParam *monAfter = POKEPARTY_GetMember((struct Party *)args->battleParam->playerParty, i);
                    u32 levelBefore = POKE_TOOL_GetPartyValue(monBefore, MON_PARAM_LEVEL, 0);
                    u32 levelAfter = POKE_TOOL_GetPartyValue(monAfter, MON_PARAM_LEVEL, 0);
                    if (levelBefore < levelAfter) {
                        *mask |= (u16)(1 << i);
                    }
                    i++;
                } while (i < count);
            }
            break;
        }
    }
}

/* Pickup and Honey Gather: members holding nothing may find an item after the battle. */
void EVENT_BATTLE_RETURN_ApplyPickupAndHoneyGather(struct PokeParty *party)
{
    int i;
    struct PokemonParam *mon;
    u16 species,item;
    int ability;
    int roll;
    int j;
    u8 levelTier;
    int levelCeil;
    int chanceIndex;
    for (i=0;i<(int)POKEPARTY_GetCount((struct Party *)party);i++) {
        mon = POKEPARTY_GetMember((struct Party *)party,i);
        species = POKE_TOOL_GetPartyValue(mon,MON_PARAM_SPECIES_OR_EGG,0);
        item = POKE_TOOL_GetPartyValue(mon,MON_PARAM_HELD_ITEM,0);
        ability = (u8)POKE_TOOL_GetPartyValue(mon,MON_PARAM_ABILITY,0);
        if (ability == ABILITY_PICKUP && species != 0 && species != SPECIES_EGG && item == 0 && GFL_USE_GetRandom(10) == 0) {
            roll = GFL_USE_GetRandom(100);
            levelTier = (POKE_TOOL_GetPartyValue(mon,MON_PARAM_LEVEL,0)-1)/10u;
            if (levelTier >= 10) levelTier=9;
            for (j=0;j<9;j++) {
                if (sPickupRollThresholds[j] > roll) {
                    POKE_TOOL_SetPartyValue(mon,MON_PARAM_HELD_ITEM,sPickupCommonItems[levelTier+j]);
                    break;
                } else if (roll >= 98 && roll <= 99) {
                    POKE_TOOL_SetPartyValue(mon,MON_PARAM_HELD_ITEM,sPickupRareItems[levelTier+(99-roll)]);
                    break;
                }
            }
        }
        if (ability == ABILITY_HONEY_GATHER && species != 0 && species != SPECIES_EGG && item == 0) {
            chanceIndex=0;
            levelCeil=10;
            ability=(u8)POKE_TOOL_GetPartyValue(mon,MON_PARAM_LEVEL,0);
            while (levelCeil < ability) {
                levelCeil+=10;
                chanceIndex++;
            }
            if (GFL_USE_GetRandom(100) < sHoneyGatherChance[chanceIndex]) POKE_TOOL_SetPartyValue(mon,MON_PARAM_HELD_ITEM,ITEM_HONEY);
        }
    }
}

/* Natural Cure: clears the status of every member that has the ability. */
void EVENT_BATTLE_RETURN_ApplyNaturalCure(struct PokeParty *party)
{
    int i;
    struct PokemonParam *mon;
    u16 species;
    u8 ability;

    for (i = 0; i < (int)POKEPARTY_GetCount((struct Party *)party); i++) {
        mon = POKEPARTY_GetMember((struct Party *)party, i);
        species = POKE_TOOL_GetPartyValue(mon, MON_PARAM_SPECIES_OR_EGG, 0);
        ability = POKE_TOOL_GetPartyValue(mon, MON_PARAM_ABILITY, 0);
        if (ability == ABILITY_NATURAL_CURE && species != 0 && species != SPECIES_EGG) {
            POKE_TOOL_SetStatusCondition(mon, 0);
        }
    }
}

/* Applies the Burmy form for the battle background to every member that took part. */
void EVENT_BATTLE_RETURN_ApplyBurmyForms(struct EventBattleReturnArgs *args, struct PokeParty *party, int burmyForm)
{
    int i;

    if (args->battleParam->competitor - 2 > 1) {
        for (i = 0; i < (int)POKEPARTY_GetCount((struct Party *)party); i++) {
            if (args->battleParam->participated[i] != 0) {
                FLDMMDL_ApplyBurmyFormForPlace(args->gameData, POKEPARTY_GetMember((struct Party *)party, i), burmyForm);
            }
        }
    }
}

/* Reads the Burmy form of a battle background from its archive table. */
u32 EVENT_BATTLE_RETURN_GetBurmyForm(const struct BattleField *field, u16 heapId)
{
    struct BurmyFormRecord *table;
    u32 form;
    struct BurmyFormRecord *record;
    table = ARC_TOOL_LoadMember(BURMY_FORM_ARCHIVE, 0, heapId);
    record = &table[field->bgType];
    form = record->formByAttr[field->bgAttr];
    GFL_HEAP_Free(table);
    return form;
}

/* Registers the form of each participating Shaymin in the Pokedex. */
void EVENT_BATTLE_RETURN_RegisterShayminForms(struct EventBattleReturnArgs *args, struct PokeParty *party)
{
    int i;
    struct PokemonParam *mon;
    u32 competitor;

    competitor = args->battleParam->competitor;
    switch (competitor) {
    case 0:
    case 1:
        for (i = 0; i < (int)POKEPARTY_GetCount((struct Party *)party); i++) {
            if (args->battleParam->participated[i] != 0) {
                mon = POKEPARTY_GetMember((struct Party *)party, i);
                if (POKE_TOOL_GetPartyValue(mon, MON_PARAM_SPECIES, 0) == SPECIES_SHAYMIN) {
                    ZUKAN_SAVE_RegisterSeen(ZUKAN_SAVE_GetFromGameData(args->gameData), mon);
                }
            }
        }
        break;
    }
}

/* Parameter ids of the get/set party-value accessors. */
#define MON_PARAM_BALL 0x98

/* A Pokemon caught in a Heal Ball is healed: full HP and no status. */
void EVENT_BATTLE_RETURN_ApplyHealBall(struct PokemonParam *mon)
{
    u32 prevState;
    prevState = POKE_TOOL_DecodePartyParam(mon);
    if (POKE_TOOL_GetPartyValue(mon, MON_PARAM_BALL, 0) == BALL_HEAL) {
        POKE_TOOL_SetPartyValue(mon, MON_PARAM_HP, POKE_TOOL_GetPartyValue(mon, MON_PARAM_MAX_HP, 0));
        POKE_TOOL_SetStatusCondition(mon, 0);
    }
    POKE_TOOL_EncodePartyParam(mon, prevState);
}
