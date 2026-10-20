/*
 * file:     union_scene.c
 * unit:     yes
 * function: UNION_SCENE_CreateSubEvent, UNION_SCENE_SubEventMain, UNION_SCENE_RequestScene, UNION_SCENE_IsScenePending, UNION_SCENE_StepStartOv111Proc, UNION_SCENE_StepPokemonTrade, UNION_SCENE_StepGroupActivity, UNION_SCENE_StepWarpToZone96AtSeat, UNION_SCENE_StepWarpToZone97AtSeat, UNION_SCENE_StepWarpToZone1A6, UNION_SCENE_StepColosseumPartyEntry, UNION_SCENE_StepStartBattleSelect, UNION_SCENE_StepStartPmsInput
 * address:  0x0217413C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from union_main.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   UNION_SCENE_IsScenePending  0x02174268  thumb  ov012
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   UNION_APP_Delete  0x02183BE0  thumb  ov022
 *   GF_PANIC_Fail  0x02034714  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   UNION_MSG_CloseAllWindows  0x0217F074  thumb  ov019
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   sUnionSubEventTable     0x02175498  data   ov012  a4
 *   gUnionMainEmptyString 0x02175628 data ov012 a1
 *   FIELD_STATUS_CreateSubProcEvent 0x020146F8 thumb
 *   ov111_id 0x0000006F data a1
 *   gOv111ProcData 0x02172608 data a4
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   ov119_id       0x00000077  data   a1
 *   ov195_id       0x000000C3  data   a1
 *   gPokemonTradeProcData     0x021E7608  data   ov119  a4
 *   d_02208C40     0x02208C40  data   ov195  a4
 *   UNION_APP_Update  0x02183C3C  thumb  ov022
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   UNION_APP_Create  0x02183B60  thumb  ov022
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   UNION_COMMAND_SendAppQuitRequest  0x02173E1C  thumb  ov012
 *   UNION_APP_IsQuitAccepted  0x02183F84  thumb  ov022
 *   UNION_COMMAND_SendAppSettingRequest  0x02173EC8  thumb  ov012
 *   UNION_APP_HasMembers  0x0218401C  thumb  ov022
 *   UNION_APP_GetJoinedBits  0x021841A0  thumb  ov022
 *   UNION_COMMAND_SendAppJoinData  0x02173F90  thumb  ov012
 *   UNION_APP_IsAllEntriesReceived  0x0218402C  thumb  ov022
 *   UNION_COMMAND_SendAppLeaveData  0x02174084  thumb  ov012
 *   UNION_APP_AddSelfToJoined  0x021840AC  thumb  ov022
 *   UNION_COMM_SetGameKindByStatus  0x021736E0  thumb  ov012
 *   GFL_NET_SetAcceptConnection  0x0203D1E8  arm
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx  0x02029DF4  thumb
 *   GFL_USE_ChangeBgm  0x02005DA4  thumb
 *   GFL_USE_IsBgmFading  0x02005E50  thumb
 *   ov022_id       0x00000016  data   a1
 *   ov023_id       0x00000017  data   a1
 *   ov137_id       0x00000089  data   a1
 *   gOekakiProcData     0x02186B30  data   ov023  a4
 *   gGuru2ProcData     0x021E1A2C  data   ov137  a4
 *   EVENT_MAPCHANGE_CreateWarpEvent  0x02184D38  thumb  ov020
 *   PLIST_COMM_Update  0x021B6114  thumb  ov090
 *   PLIST_COMM_Start  0x021B6100  thumb  ov090
 *   PLIST_COMM_End  0x021B6108  thumb  ov090
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb
 *   POKEPARTY_Create  0x0201A920  thumb
 *   POKEPARTY_Copy  0x0201AC2C  thumb
 *   POKEPARTY_Init  0x0201A948  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   COLOSSEUM_ResetParties  0x02175240  thumb  ov012
 *   COLOSSEUM_SendParty  0x02174D98  thumb  ov012
 *   COLOSSEUM_AllPartiesReceived  0x02175214  thumb  ov012
 *   COLOSSEUM_SetupBattleInfo  0x02175280  thumb  ov012
 *   COLOSSEUM_ClearBattleInfo  0x0217534C  thumb  ov012
 *   IRC_BATTLE_TASK_Create  0x02157450  thumb
 *   GAME_DATA_GetWifiList  0x0201283C  thumb
 *   WIFILIST_FindFriendByStatus  0x02009D1C  thumb
 *   WIFILIST_AddFriendBattleRecord  0x02009BB8  thumb
 *   WIFILIST_SetFriendLastSeen  0x02009B80  thumb
 *   ov090_id       0x0000005A  data   a1
 *   ov091_id       0x0000005B  data   a1
 *   ov131_id       0x00000083  data   a1
 *   gPartyListProcData     0x021BED00  data   ov091  a4
 *   gPokeStatusProcData     0x021DC800  data   ov131  a4
 *   ov110_id 0x0000006E data a1
 *   gPmsInputProcData 0x021C39D4 data ov110 a4
 *   UNION_COMM_SetSituationParam 0x021734A8 thumb ov012
 */
#include "../sdk_fx.h"

#include "union_comm_types.h"
#include "../arm9/net_types.h"
#include "../ov006/event_wificlub_types.h"
#include "union_command_shared_types.h"

/* Work of the event that runs one union sub-event (12 bytes). */
typedef struct UnionSubEventWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    void *fieldMap;                 /* 0x04 */
    UnionRoomWork *work;            /* 0x08 */
} UnionSubEventWork;

/* One sub-event: its step function and the status shown while it runs. */
typedef int (*UnionSubEventFunc)(struct GameSystem *gameSystem, UnionRoomWork *work, void *fieldMap, int param, void *event, void **nextEvent, u8 *seq);

typedef struct UnionSubEventEntry {
    UnionSubEventFunc func;   /* 0x00 */
    u8 startStatus;           /* 0x04 UNION_STATUS_NONE keeps the status */
    u8 endStatus;             /* 0x05 */
    u8 pad06[2];
} UnionSubEventEntry;

#include "../arm9/net_err.h"

#include "../arm9/net.h"


extern int UNION_SCENE_IsScenePending(UnionRoomWork *work);

#include "../arm9/gamesystem.h"

#include "../ov022/union_app.h"

#include "../arm9/gf_panic.h"

#include "../arm9/game_data.h"

#include "../arm9/net_handle.h"

struct GameEvent;

#include "../arm9/game_event.h"
struct GameEvent;


#include "../ov019/union_msg.h"


#include "union_comm.h"

#include "union_command.h"




void *UNION_SCENE_CreateSubEvent(struct GameSystem *gameSystem, void *fieldMap, UnionRoomWork *work);

int UNION_SCENE_SubEventMain(void *event, int *seq, UnionSubEventWork *eventWork);

extern const UnionSubEventEntry sUnionSubEventTable[];

void *UNION_SCENE_CreateSubEvent(struct GameSystem *gameSystem, void *fieldMap, UnionRoomWork *work)
{
    void *event;
    UnionSubEventWork *eventWork;
    event = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)UNION_SCENE_SubEventMain, sizeof(UnionSubEventWork));
    eventWork = GAME_EVENT_GetWork(event);
    eventWork->gameSystem = gameSystem;
    eventWork->fieldMap = fieldMap;
    eventWork->work = work;
    work->subEvent.active = 1;
    return event;
}

int UNION_SCENE_SubEventMain(void *event, int *seq, UnionSubEventWork *eventWork)
{
    struct GameSystem *gameSystem;
    UnionRoomWork *work;
    UnionSubEvent *subEvent;
    void *nextEvent;
    int status;

    gameSystem = eventWork->gameSystem;
    work = eventWork->work;
    subEvent = &work->subEvent;
    nextEvent = 0;
    switch (*seq) {
    case 0:
        UNION_MSG_CloseAllWindows(work);
        status = sUnionSubEventTable[subEvent->id].startStatus;
        if (status != UNION_STATUS_NONE) {
            UNION_COMM_SetSituationParam(work, 4, status);
        }
        (*seq)++;
    case 1: {
        int result;
        result = sUnionSubEventTable[subEvent->id].func(gameSystem, work, eventWork->fieldMap, subEvent->param, event, &nextEvent, &subEvent->seq);
        if (nextEvent != 0) {
            GAME_EVENT_CallEvent(event, nextEvent);
        } else if (result == 1) {
            (*seq)++;
        }
        break;
    }
    case 2:
        status = sUnionSubEventTable[subEvent->id].endStatus;
        if (status != UNION_STATUS_NONE) {
            UNION_COMM_SetSituationParam(work, 4, status);
        }
        subEvent->id = 0;
        subEvent->param = 0;
        subEvent->seq = 0;
        subEvent->active = 0;
        return 1;
    }
    return 0;
}

struct FieldMap;

struct PokemonParam;

struct WifiList;

/* Bits of ColosseumWork.battlePosition. */
#define BATTLE_POSITION_SIDE 1

#define BATTLE_POSITION_TEAM 2

/* Parameter block of the group activity overlays (oekaki ov023, guru2 ov137). */
typedef struct ActivityParam {
    struct UnionAppWork *unionApp;
    u8    pad04[0x10];
    int   result;       /* 0x14 */
} ActivityParam;

/* Parameter block of the status overlay (ov131), only the fields used here. */
typedef struct PokeStatusParam {
    struct Party *party;
    u32   options;
    struct GameData *gameData;
    u8    mode;             /* 0x0C */
    u8    page;             /* 0x0D */
    u8    partyCount;       /* 0x0E */
    u8    cursor;           /* 0x0F */
    u8    result;           /* 0x10 */
    u8    pad11[7];
    u32   trainerRecord;    /* 0x18 */
} PokeStatusParam;

/* Parameter and result block of the colosseum battle selection, 0x5C bytes. */
typedef struct BattleSelectParam {
    struct Party *party;
    u8    pad04[0xC];
    u16   messageId;        /* 0x10 */
    u8    battlePosition;   /* 0x12 */
    u8    pad13;
    struct Regulation *regulation;  /* 0x14 */
    u8    battleInfo[0x40]; /* 0x18 */
    u32   result;           /* 0x58 */
} BattleSelectParam;

/* Parameter block of the party list overlay (ov090/ov091). */
typedef struct PartyListParam {
    struct Party *party;
    u8    pad04[8];
    u32   options;          /* 0x0C */
    u8    pad10[0x2C];
    u32   cursor;           /* 0x3C */
    u32   resultKind;       /* 0x40 */
    u8    pad44[5];
    u8    selectedOrder[6]; /* 0x49: 1 based party slots chosen by the player */
    u8    pad4F[0x49];
    PokeStatusParam statusParam;    /* 0x98 */
    u8    padB4[0xC];
    BattleSelectParam *battleSelect;    /* 0xC0 */
} PartyListParam;

#include "../arm9/field_status.h"

#include "../ov021/event_fieldmap_control.h"







#include "../arm9/gf_overlay.h"


struct UnionAppStatusCopy;
struct UnionRoomWork;












#include "../arm9/field_sound_system.h"

#include "../arm9/gfl_use.h"


#include "../ov020/event_mapchange.h"
struct PartyListCommWork;

#include "../ov090/plist_comm.h"



#include "../arm9/pokeparty.h"

#include "../arm9/zukan_save.h"
struct ZukanSave;







#include "../arm9/gfl_heap_wrap.h"

#include "colosseum.h"


struct ColosseumBattleInfo;
struct ColosseumWork;

struct IrcBattleRequest;

#include "../ov010/irc_battle_task.h"
struct FieldState;


#include "../arm9/wifilist.h"




void UNION_SCENE_RequestScene(UnionRoomWork *unionRoom, int sceneId, int sceneParam);

int UNION_SCENE_StepStartOv111Proc(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int procWork, void *event, struct GameEvent **outEvent, u8 *step);

int UNION_SCENE_StepPokemonTrade(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, ClubTradeParam *tradeParam, void *event, struct GameEvent **outEvent, u8 *step);

int UNION_SCENE_StepGroupActivity(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int param, struct GameEvent *event, struct GameEvent **outEvent, u8 *step);

int UNION_SCENE_StepWarpToZone96AtSeat(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int param, void *event, struct GameEvent **outEvent, u8 *step);

int UNION_SCENE_StepWarpToZone97AtSeat(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int param, void *event, struct GameEvent **outEvent, u8 *step);

int UNION_SCENE_StepWarpToZone1A6(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int param, void *event, struct GameEvent **outEvent, u8 *step);

int UNION_SCENE_StepColosseumPartyEntry(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, PartyListParam *listParam, struct GameEvent *event, struct GameEvent **outEvent, u8 *step);

u32 UNION_SCENE_StepStartBattleSelect(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, BattleSelectParam *selectParam, void *event, struct GameEvent **outEvent, u8 *step);

int UNION_SCENE_StepStartPmsInput(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int procWork, void *event, struct GameEvent **outEvent, u8 *step);

extern const char gUnionMainEmptyString[];

extern u8 ov111_id[];

extern const int gOv111ProcData[];

extern char ov119_id[];

extern char ov195_id[];

extern u8 gPokemonTradeProcData[];

extern u8 d_02208C40[];

extern char ov022_id[];

extern char ov023_id[];

extern char ov137_id[];

extern u8 gOekakiProcData[];

extern u8 gGuru2ProcData[];

extern char ov090_id[];

extern char ov091_id[];

extern char ov131_id[];

extern u8 gPartyListProcData[];

extern u8 gPokeStatusProcData[];

extern u8 ov110_id[];

extern const int gPmsInputProcData[];

/* Records the scene to run next and its parameter block; only one scene may be pending. */
void UNION_SCENE_RequestScene(UnionRoomWork *unionRoom, int sceneId, int sceneParam)
{
    if (unionRoom->subEvent.id != 0 || unionRoom->subEvent.active != 0)
        GF_PANIC_Fail(gUnionMainEmptyString, 0, gUnionMainEmptyString);
    unionRoom->subEvent.id = sceneId;
    unionRoom->subEvent.param = sceneParam;
    unionRoom->subEvent.seq = 0;
}

/* Returns 1 while a scene is requested or running. */
int UNION_SCENE_IsScenePending(UnionRoomWork *unionRoom)
{
    if (unionRoom->subEvent.id == 0 && unionRoom->subEvent.active == 0)
        return 0;
    return 1;
}

/* Scene step: starts the ov111 sub process once, then reports done. */
int UNION_SCENE_StepStartOv111Proc(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int procWork, void *event, struct GameEvent **outEvent, u8 *step)
{
    if (*step == 0) {
        *outEvent = FIELD_STATUS_CreateSubProcEvent(gameSystem, fieldMap, (sptr)ov111_id, (void *)gOv111ProcData, (void *)procWork);
    } else {
        return 1;
    }
    (*step)++;
    return 0;
}

/*
 * Scene step of the Pokemon trade (8 steps), then the evolution demo if the
 * trade asks for one. Pooled small words 0x77/0xC3 are linker overlay ids
 * (ov119 trade, ov195 evolution) handed to GAMESYSTEM_CallProc with a table in
 * that overlay window, as in ov001 EVENT_GTSNEGO_Main.
 */
int UNION_SCENE_StepPokemonTrade(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, ClubTradeParam *tradeParam, void *event, struct GameEvent **outEvent, u8 *step)
{
    EvolutionRequest *request;

    switch (*step) {
    case 0:
        *outEvent = EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 0, 0);
        (*step)++;
        break;
    case 1:
        *outEvent = FIELD_STATUS_CreateFieldCloseEvent(gameSystem, fieldMap);
        (*step)++;
        break;
    case 2:
        GAMESYSTEM_CallProc(gameSystem, (uptr)ov119_id, gPokemonTradeProcData, tradeParam);
        (*step)++;
        break;
    case 3:
        if (GAMESYSTEM_GetProcStatus(gameSystem) != 0)
            break;
        if (tradeParam->result == 1)
            *step = 4;
        else
            *step = 6;
        break;
    case 4:
        request = tradeParam->evolutionRequest;
        request->gameData = tradeParam->gameData;
        request->party = tradeParam->party;
        request->targetSpecies = tradeParam->partyIndex;
        request->partySlot = 0;
        request->evolveCondition = tradeParam->evolveCondition;
        request->fromTrade = 1;
        request->fromField = 0;
        tradeParam->evolutionRequest = request;
        GAMESYSTEM_CallProc(gameSystem, (uptr)ov195_id, d_02208C40, request);
        (*step)++;
        break;
    case 5:
        if (GAMESYSTEM_GetProcStatus(gameSystem) != 0)
            break;
        if (GFL_NET_ERR_GetErrorLevel() != 0) {
            *step = 6;
        } else {
            tradeParam->result = 1;
            *step = 2;
        }
        break;
    case 6:
        *outEvent = FIELD_STATUS_CreateFieldOpenEvent(gameSystem);
        *step = 7;
        break;
    case 7:
        *outEvent = EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 0, 0, 1, 0, 0);
        *step = 8;
        break;
    default:
        return 1;
    }
    return 0;
}

/*
 * Scene step of a group activity (20 steps): loads the union app overlay,
 * syncs with the other players, then runs oekaki or guru2. Same family as
 * UNION_SCENE_StepPokemonTrade. Pooled small words 0x16/0x17/0x89 are linker overlay ids
 * (ov022/ov023/ov137).
 *
 * evidence: 0x02029DF4 is an unlabelled ARM9 thunk ("ldr r3, =FIELD_SOUND_SYSTEM_GetFieldBgmForZone;
 * bx r3"), seeded in layout/function_starts.txt from the bl sites in ov020
 * and ov021 (0x021AF018 and others), so +0x21E attests as `label`.
 * 0x02005DA4 is an 8-byte ARM9 wrapper ("push {r3, lr}; bl 0x02005F70;
 * pop {r3, pc}") between GFL_USE_CancelChangeAndPlayBgm's pop and GFL_USE_PlayFanfare; the bl at
 * +0x22C is its only reference in the image, so it is seeded from that site;
 * the wrapper is matched EXACT (src/matched/arm9/GFL_USE_ChangeBgm.c), so +0x22C
 * attests as `matched`.
 */
int UNION_SCENE_StepGroupActivity(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int param, struct GameEvent *event, struct GameEvent **outEvent, u8 *step)
{
    UnionSubEvent *scene = &unionRoom->subEvent;
    UnionMySituation *situation = &unionRoom->mySituation;
    ActivityParam *activityParam;
    int selection;

    if (GFL_NET_ERR_GetErrorLevel() != 0 && *step > 2 && *step <= 13)
        *step = 16;
    if (unionRoom->app != 0)
        UNION_APP_Update(unionRoom->app, unionRoom);

    switch (*step) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 0, 0));
        (*step)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldCloseEvent(gameSystem, fieldMap));
        (*step)++;
        break;
    case 2:
        GF_OVERLAY_Load((uptr)ov022_id);
        unionRoom->app = UNION_APP_Create(unionRoom, 3, 5, (struct UnionAppStatusCopy *)(GAME_DATA_GetMyStatus(unionRoom->parent->gameData)));
        if (situation->connect.serviceFlag == 1)
            *step = 5;
        else
            (*step)++;
        break;
    case 3:
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 9, 0x14);
        (*step)++;
        break;
    case 4:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 9, 0x14) == 1)
            *step = 7;
        break;
    case 5:
        if (UNION_COMMAND_SendAppQuitRequest() == 1)
            (*step)++;
        break;
    case 6:
        if (UNION_APP_IsQuitAccepted(unionRoom->app) == 1)
            *step = 7;
        break;
    case 7:
        if (UNION_COMMAND_SendAppSettingRequest() == 1)
            (*step)++;
        break;
    case 8:
        if (UNION_APP_HasMembers(unionRoom->app) == 1)
            (*step)++;
        break;
    case 9:
        selection = UNION_APP_GetJoinedBits(unionRoom->app);
        if (UNION_COMMAND_SendAppJoinData(selection, (const UnionAppData *)GAME_DATA_GetMyStatus(unionRoom->parent->gameData)) == 1)
            (*step)++;
        break;
    case 10:
        if (UNION_APP_IsAllEntriesReceived(unionRoom->app) == 1)
            (*step)++;
        break;
    case 11:
        if (situation->connect.serviceFlag == 1) {
            selection = UNION_APP_GetJoinedBits(unionRoom->app);
            if (UNION_COMMAND_SendAppLeaveData(selection, (const UnionAppData *)GAME_DATA_GetMyStatus(unionRoom->parent->gameData)) == 1) {
                UNION_APP_AddSelfToJoined(unionRoom->app);
                *step = 13;
            }
        } else {
            UNION_COMM_SetGameKindByStatus(situation->status);
            GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 10, 0x14);
            *step = 12;
        }
        break;
    case 12:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 10, 0x14) == 1) {
            GFL_NET_SetAcceptConnection((GFL_NET_HANDLE_GetCurrentHandle()), (void *)1);
            *step = 13;
        }
        break;
    case 13:
        GFL_NET_SetLoginOption(0);
        if (situation->status == 3) {
            activityParam = (ActivityParam *)scene->param;
            activityParam->unionApp = unionRoom->app;
            GAMESYSTEM_CallProc(gameSystem, (uptr)ov023_id, gOekakiProcData, activityParam);
        } else {
            activityParam = (ActivityParam *)scene->param;
            activityParam->unionApp = unionRoom->app;
            GAMESYSTEM_CallProc(gameSystem, (uptr)ov137_id, gGuru2ProcData, activityParam);
        }
        (*step)++;
        break;
    case 14:
        if (GAMESYSTEM_GetProcStatus(gameSystem) != 0)
            break;
        if (situation->status == 0x19) {
            if (((ActivityParam *)scene->param)->result == 1) {
                GFL_USE_ChangeBgm((u16)FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(unionRoom->parent->gameData, 0x1a6, GAME_DATA_GetSeason(unionRoom->parent->gameData)), 0xffff, 6, 0x3c);
                *step = 15;
            } else {
                *step = 16;
            }
        } else {
            *step = 16;
        }
        break;
    case 15:
        if (GFL_USE_IsBgmFading() == 0)
            *step = 16;
        break;
    case 16:
        if (unionRoom->app != 0) {
            UNION_APP_Delete(unionRoom->app);
            unionRoom->app = 0;
            GF_OVERLAY_Unload((sptr)ov022_id);
        }
        *step = 17;
        break;
    case 17:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*step)++;
        break;
    case 18:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 0, 0, 1, 0, 0));
        (*step)++;
        break;
    case 19:
    default:
        return 1;
    }
    return 0;
}

/* Scene step: plays field effect 0x96 above the seat of the local player, then reports done. */
int UNION_SCENE_StepWarpToZone96AtSeat(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int param, void *event, struct GameEvent **outEvent, u8 *step)
{
    VecFx32 pos;
    int result = 0;

    if (*step == 0) {
        pos.x = (GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle()) * 16 + 0x58) << 12;
        pos.y = 0;
        pos.z = 0x98000;
        *outEvent = EVENT_MAPCHANGE_CreateWarpEvent(gameSystem, fieldMap, 0x96, &pos, 0, 0);
    } else {
        return 1;
    }
    (*step)++;
    return result;
}

/* Scene step: plays field effect 0x97 at the seat of the local player, then reports done. */
int UNION_SCENE_StepWarpToZone97AtSeat(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int param, void *event, struct GameEvent **outEvent, u8 *step)
{
    VecFx32 pos;
    int zero;

    if (*step == 0) {
        pos.x = (GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle()) * 16 + 0x58) << 12;
        zero = 0;
        pos.y = zero;
        pos.z = 0x26 << 14;
        *outEvent = EVENT_MAPCHANGE_CreateWarpEvent(gameSystem, fieldMap, 0x97, &pos, zero, zero);
    } else {
        return 1;
    }
    *step = *step + 1;
    return zero;
}

/* Scene step: plays field effect 0x1A6 at a fixed spot, then reports done. */
int UNION_SCENE_StepWarpToZone1A6(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int param, void *event, struct GameEvent **outEvent, u8 *step)
{
    VecFx32 pos;
    int zero;

    if (*step == 0) {
        pos.x = 0x2e << 14;
        zero = 0;
        pos.y = zero;
        pos.z = 0x3a << 14;
        *outEvent = EVENT_MAPCHANGE_CreateWarpEvent(gameSystem, fieldMap, 0x1A6, &pos, zero, zero);
    } else {
        return 1;
    }
    *step = *step + 1;
    return zero;
}

/*
 * Levers that closed the match: case 16 and default share one `return 1`
 * placed before case 17 so the tails cross-jump onto case 15 and case 17;
 * IRC_BATTLE_TASK_Create takes fieldMap (not unionRoom) in r1; the byte argument goes
 * through `u8 *activity` declared at function top (as in
 * UNION_SCENE_StepStartBattleSelect), which loads the base before the pool
 * offset.
 *
 * Scene step of the colosseum party entry (18 steps): the player picks the
 * party members (ov090/ov091 party list, ov131 status), the party is sent to
 * the other players, then the battle selection runs and the results are
 * written to the Wi-Fi list.
 */
int UNION_SCENE_StepColosseumPartyEntry(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, PartyListParam *listParam, struct GameEvent *event, struct GameEvent **outEvent, u8 *step)
{
    u8 *activity = &unionRoom->mySituation.status;
    ColosseumWork *colosseum = unionRoom->colosseum;
    PokeStatusParam *statusParam = &listParam->statusParam;
    BattleSelectParam *selectParam = listParam->battleSelect;
    u32 myNetId = GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle());
    struct Party *party;
    struct Party *tmpParty;
    int i;
    struct WifiList *wifiList;
    int playerCount;
    u32 side;
    u32 friendIndex;

    if (*step > 2 && *step < 7)
        PLIST_COMM_Update((struct PartyListCommWork *)listParam);

    switch (*step) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 0, 0));
        (*step)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldCloseEvent(gameSystem, fieldMap));
        (*step)++;
        break;
    case 2:
        GF_OVERLAY_Load((sptr)ov090_id);
        PLIST_COMM_Start((struct PartyListCommWork *)listParam);
        (*step)++;
        break;
    case 3:
        GAMESYSTEM_CallProc(gameSystem, (uptr)ov091_id, gPartyListProcData, listParam);
        (*step)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(gameSystem) != 0)
            break;
        if (listParam->resultKind == 1)
            *step = 5;
        else
            *step = 7;
        break;
    case 5:
        statusParam->party = listParam->party;
        statusParam->options = listParam->options;
        statusParam->gameData = GAMESYSTEM_GetGameData(gameSystem);
        statusParam->mode = 1;
        statusParam->partyCount = POKEPARTY_GetCount(listParam->party);
        statusParam->page = 0;
        statusParam->cursor = listParam->cursor;
        statusParam->result = 0;
        statusParam->trainerRecord = ZUKAN_SAVE_IsNationalDexEnabled(ZUKAN_SAVE_GetFromGameData(statusParam->gameData));
        GAMESYSTEM_CallProc(gameSystem, (uptr)ov131_id, gPokeStatusProcData, statusParam);
        (*step)++;
        break;
    case 6:
        if (GAMESYSTEM_GetProcStatus(gameSystem) != 0)
            break;
        listParam->cursor = statusParam->cursor;
        *step = 3;
        break;
    case 7:
        PLIST_COMM_End(listParam);
        GF_OVERLAY_Unload((sptr)ov090_id);
        *step = 8;
        break;
    case 8:
        if (GFL_NET_ERR_GetErrorLevel() != 0) {
            *step = 0x11;
            break;
        }
        if (listParam->resultKind != 0)
            GF_PANIC_Fail(gUnionMainEmptyString, 0, gUnionMainEmptyString);
        if (listParam->cursor != 6)
            GF_PANIC_Fail(gUnionMainEmptyString, 0, gUnionMainEmptyString);
        party = colosseum->party[myNetId];
        tmpParty = POKEPARTY_Create(0x41);
        POKEPARTY_Copy(party, tmpParty);
        POKEPARTY_Init(party);
        for (i = 0; i < 6; i++) {
            if (listParam->selectedOrder[i] == 0)
                break;
            POKEPARTY_Add(party, POKEPARTY_GetMember(tmpParty, listParam->selectedOrder[i] - 1));
        }
        GFL_HEAP_Free(tmpParty);
        COLOSSEUM_ResetParties(colosseum, 1);
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x16, 0x14);
        (*step)++;
        break;
    case 9:
        if (GFL_NET_ERR_GetErrorLevel() != 0) {
            *step = 0x11;
            break;
        }
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x16, 0x14) == 1)
            (*step)++;
        break;
    case 10:
        if (GFL_NET_ERR_GetErrorLevel() != 0) {
            *step = 0x11;
            break;
        }
        if (COLOSSEUM_SendParty(colosseum->party[myNetId]) == 1)
            (*step)++;
        break;
    case 11:
        if (GFL_NET_ERR_GetErrorLevel() != 0) {
            *step = 0x11;
            break;
        }
        if (COLOSSEUM_AllPartiesReceived(colosseum) == 1)
            (*step)++;
        break;
    case 12:
        selectParam->party = colosseum->party[myNetId];
        selectParam->battlePosition = colosseum->battlePosition[myNetId];
        selectParam->regulation = unionRoom->regulation;
        if (myNetId == 0 || (colosseum->battlePosition[0] & BATTLE_POSITION_TEAM) == (colosseum->battlePosition[myNetId] & BATTLE_POSITION_TEAM))
            selectParam->messageId = 0x48B;
        else
            selectParam->messageId = 0x48C;
        COLOSSEUM_SetupBattleInfo(colosseum, gameSystem, (struct ColosseumBattleInfo *)selectParam->battleInfo, 0x41);
        *outEvent = IRC_BATTLE_TASK_Create(gameSystem, fieldMap, activity[0], (struct IrcBattleRequest *)selectParam);
        (*step)++;
        break;
    case 13:
        if (GFL_NET_ERR_GetErrorLevel() == 0) {
            wifiList = (struct WifiList *)GAME_DATA_GetWifiList(GAMESYSTEM_GetGameData(gameSystem));
            playerCount = GFL_NET_GetNegotiationNum();
            side = colosseum->battlePosition[myNetId] & BATTLE_POSITION_SIDE;
            for (i = 0; i < playerCount; i++) {
                if (i == myNetId)
                    continue;
                if (WIFILIST_FindFriendByStatus(wifiList, (struct MyStatus *)colosseum->player[i].myStatus, &friendIndex) != 1)
                    continue;
                if (side == (colosseum->battlePosition[i] & BATTLE_POSITION_SIDE)) {
                    WIFILIST_SetFriendLastSeen(wifiList, friendIndex);
                    continue;
                }
                switch (selectParam->result) {
                case 0:
                    WIFILIST_AddFriendBattleRecord(wifiList, friendIndex, 1, 0, 0);
                    break;
                case 1:
                    WIFILIST_AddFriendBattleRecord(wifiList, friendIndex, 0, 1, 0);
                    break;
                case 2:
                    WIFILIST_SetFriendLastSeen(wifiList, friendIndex);
                    break;
                }
            }
        }
        COLOSSEUM_ClearBattleInfo((struct ColosseumBattleInfo *)selectParam->battleInfo);
        *step = 0x10;
        break;
    case 14:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*step)++;
        break;
    case 15:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 0, 0, 1, 0, 0));
        (*step)++;
        break;
    case 16:
    default:
        return 1;
    case 17:
        *step = 0xE;
        break;
    }
    return 0;
}

/* Scene step: starts the colosseum battle selection once, then reports done. */
u32 UNION_SCENE_StepStartBattleSelect(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, BattleSelectParam *selectParam, void *event, struct GameEvent **outEvent, u8 *step)
{
    u8 *activity = &unionRoom->mySituation.status;
    if (*step == 0) {
        *outEvent = IRC_BATTLE_TASK_Create(gameSystem, fieldMap, activity[0], (struct IrcBattleRequest *)selectParam);
    } else {
        return 1;
    }
    (*step)++;
    return 0;
}

/* Scene step: starts the PMS word input overlay (ov110) once, then reports done. */
int UNION_SCENE_StepStartPmsInput(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int procWork, void *event, struct GameEvent **outEvent, u8 *step)
{
    if (*step == 0) {
        *outEvent = FIELD_STATUS_CreateSubProcEvent(gameSystem, fieldMap, (sptr)ov110_id, (void *)gPmsInputProcData, (void *)procWork);
    } else {
        return 1;
    }
    (*step)++;
    return 0;
}
