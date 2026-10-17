/*
 * file:     union_main.c
 * unit:     yes
 * function: UNION_MAIN_StartComm, UNION_MAIN_UpdateField, UNION_MAIN_IsFieldReady, UNION_MAIN_FieldCreateCallback, UNION_MAIN_FieldDeleteCallback, UNION_MAIN_GetFieldRequest, UNION_MAIN_IsExitStarted, UNION_MAIN_SetAppealNo, UNION_MAIN_GetAppealNo, UNION_MAIN_IsIdle, UNION_COMMAND_GetRecvBuffer, UNION_COMMAND_RecvConnectSync, UNION_COMMAND_SendConnectSync, UNION_COMMAND_RecvPartnerSelectA, UNION_COMMAND_SendPartnerSelectA, UNION_COMMAND_RecvPartnerSelectB, UNION_COMMAND_SendPartnerSelectB, UNION_COMMAND_RecvPartnerMac, UNION_COMMAND_SendMyMac, UNION_COMMAND_RecvPartnerMode, UNION_COMMAND_SendPartnerMode, UNION_COMMAND_RecvMyStatus, UNION_COMMAND_SendMyStatus, UNION_COMMAND_RecvTrainerCard, UNION_COMMAND_SendTrainerCard, UNION_COMMAND_RecvColosseumEntry, UNION_COMMAND_RecvColosseumSetting, UNION_COMMAND_RecvColosseumCancel, UNION_COMMAND_SendColosseumCancel, UNION_COMMAND_RecvAppEntry, UNION_COMMAND_SendAppEntry, UNION_COMMAND_RecvAppEntryRefused, UNION_COMMAND_SendAppEntryRefused, UNION_COMMAND_RecvAppEntryAccepted, UNION_COMMAND_SendAppEntryAccepted, UNION_COMMAND_RecvAppQuitRequest, UNION_COMMAND_SendAppQuitRequest, UNION_COMMAND_RecvAppQuitAccept, UNION_COMMAND_SendAppQuitAccept, UNION_COMMAND_RecvAppQuitCancel, UNION_COMMAND_SendAppQuitCancel, UNION_COMMAND_RecvAppSetting, UNION_COMMAND_SendAppSetting, UNION_COMMAND_RecvAppJoinData, UNION_COMMAND_SendAppJoinData, UNION_COMMAND_RecvAppData, UNION_COMMAND_SendAppData, UNION_COMMAND_RecvAppLeaveData, UNION_COMMAND_SendAppLeaveData, UNION_COMMAND_RecvAppNotice, UNION_COMMAND_SendAppNotice, UNION_MAIN_CreateSubEvent, UNION_MAIN_SubEventMain, UNION_MAIN_RequestScene, UNION_MAIN_IsScenePending, UNION_MAIN_StepStartOv111Proc, UNION_MAIN_StepPokemonTrade, UNION_MAIN_StepGroupActivity, UNION_MAIN_StepPlayEffectAtSeat, UNION_MAIN_StepPlayEffectAtSeatLow, UNION_MAIN_StepPlayEffectAtFixedSpot, UNION_MAIN_StepColosseumPartyEntry, UNION_MAIN_StepStartBattleSelect, UNION_MAIN_StepStartPmsInput
 * address:  0x02173744
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from union_comm.c, unit_0217422C.c, colosseum.c, ov012_func_02175358.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   UNION_MAIN_IsScenePending  0x02174268  thumb  ov012
 *   MI_CpuCopy8       0x02082D44  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   UNION_APP_Delete  0x02183BE0  thumb  ov022
 *   COLOSSEUM_Delete  0x0217505C  thumb  ov012
 *   ICA_ANIME_GetField24  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   SAVEDATA_PanicFail  0x02034714  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_COMM_Start  0x020263D8  thumb
 *   GAME_BEACON_SEARCH_SetFieldEvent  0x021653C4  thumb  ov010
 *   sUnionMainAssertText     0x02175610  data   ov012  a1
 *   sUnionMainFile     0x02175614  data   ov012  a1
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   ICA_ANIME_GetField30  0x0201212C  thumb
 *   GAME_EVENT_IsRunning  0x020123C4  thumb
 *   UNION_ONESELF_RunPlayCategory  0x0217B840  thumb  ov019
 *   UNION_CHARA_ProcessBeaconUpdates  0x0217B75C  thumb  ov019
 *   UNION_CHARA_Main  0x0217B264  thumb  ov019
 *   ICA_ANIME_Check2114 0x02012114 thumb
 *   ICA_ANIME_GetField20 0x0201210C thumb
 *   FIELDMAP_IsReady 0x02188BE8 thumb ov021
 *   FIELDMAP_CTRL_GRID_SetBusy  0x021A2E44  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   ZONEDATA_IsZone1A6  0x02013CC8  thumb
 *   UNION_CHARA_RefreshParentMarks  0x0217B440  thumb  ov019
 *   COMM_PLAYER_Resume  0x021676E4  thumb  ov010
 *   COMM_PLAYER_Suspend  0x02167688  thumb  ov010
 *   sUnionCmdAssertText 0x02175624 data a1
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GAME_DATA_GetPlayerStatusById 0x02012950 thumb
 *   MYSTATUS_Copy 0x02008494 thumb
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   COMM_ENTRY_MENU_AddMember  0x021CD624  thumb  ov021
 *   UNION_APP_TryAcceptMember  0x02183BE8  thumb  ov022
 *   GFL_NET_SendDataMask  0x0203D4D0  arm
 *   UNION_APP_AddQuitRequest  0x02183F6C  thumb ov022
 *   UNION_APP_SetQuitAccepted  0x02183F7C  thumb ov022
 *   UNION_APP_AddSettingTarget  0x02183F88  thumb ov022
 *   UNION_APP_SetSetting  0x02183F98  thumb ov022
 *   UNION_APP_GetSettingSize 0x021840A8 thumb ov022
 *   UNION_APP_SetMemberEntry 0x02183FB8 thumb ov022
 *   UNION_APP_AddEntryTarget 0x02183FA8 thumb ov022
 *   UNION_APP_QueueJoinConfirm  0x02184060  thumb  ov022
 *   UNION_APP_OnMemberDropped 0x021840A4 thumb ov022
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
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   UNION_APP_Create  0x02183B60  thumb  ov022
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   UNION_COMMAND_SendAppQuitRequest  0x02173E1C  thumb  ov012
 *   UNION_APP_IsQuitAccepted  0x02183F84  thumb  ov022
 *   UNION_COMMAND_SendAppQuitCancel  0x02173EC8  thumb  ov012
 *   UNION_APP_HasMembers  0x0218401C  thumb  ov022
 *   UNION_APP_GetJoinedBits  0x021841A0  thumb  ov022
 *   UNION_COMMAND_SendAppJoinData  0x02173F90  thumb  ov012
 *   UNION_APP_IsAllEntriesReceived  0x0218402C  thumb  ov022
 *   UNION_COMMAND_SendAppLeaveData  0x02174084  thumb  ov012
 *   UNION_APP_AddSelfToJoined  0x021840AC  thumb  ov022
 *   UNION_COMM_SetGameKindByStatus  0x021736E0  thumb  ov012
 *   GFL_NET_NotifyUserEvent  0x0203D1E8  arm
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
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
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
 *   UNION_COMM_StartConnectSync 0x02172EDC thumb ov012
 *   UNION_COMM_SetSituationParam 0x021734A8 thumb ov012
 */
typedef struct { int x, y, z; } VecFx32;

#include "union_comm_types.h"
#include "../arm9/net_types.h"
#include "../ov006/event_wificlub_types.h"


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

/* Payload of the union app commands 0x1411 and 0x1413 (0x28 bytes). */
typedef struct UnionAppData {
    int value[8];
} UnionAppData;

typedef struct UnionAppMessage {
    UnionAppData data;   /* 0x00 */
    u8 mac[8];           /* 0x20 */
} UnionAppMessage;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);

extern u32 GFL_NET_ERR_GetErrorLevel(void);

extern u32 GFL_NET_IsParentAid(void);

extern int GFL_NET_GetNegotiationNum(void);

extern void GFL_NET_SetLoginOption(u8 option);

extern int UNION_MAIN_IsScenePending(UnionRoomWork *work);

extern void MI_CpuCopy8(const void *src, void *dst, int size);

extern void MI_CpuFill8(void *dst, int value, int size);

extern void OS_GetMacAddress(void *mac);

extern struct GameData *ICA_ANIME_GetField1C(struct GameSystem *gameSystem);

extern void UNION_APP_Delete(struct UnionAppWork *app);

extern void COLOSSEUM_Delete(ColosseumWork *colosseum, struct GameSystem *gameSystem);

extern struct GameComm *ICA_ANIME_GetField24(struct GameSystem *gameSystem);

extern unsigned int GAME_COMM_GetKind(struct GameComm *gameComm);

extern void SAVEDATA_PanicFail(const char *expr, u32 line, const char *file);

extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gameData);

extern void GAME_COMM_Start(struct GameComm *gameComm, u32 kind, void *parentWork);

extern void GAME_BEACON_SEARCH_SetFieldEvent(void);

extern void *GAME_COMM_GetWork(struct GameComm *gameComm);

extern struct GameSystem *FIELDMAP_GetGameSystem(void *fieldMap);

extern u8 ICA_ANIME_GetField30(struct GameSystem *gameSystem);

extern int GAME_EVENT_IsRunning(struct GameSystem *gameSystem);

extern int UNION_ONESELF_RunPlayCategory(UnionRoomWork *work, void *fieldMap);

extern void UNION_CHARA_ProcessBeaconUpdates(UnionRoomWork *work);

extern void UNION_CHARA_Main(UnionRoomWork *work, struct GameData *gameData, void *fieldMap);

extern u32 ICA_ANIME_Check2114(struct GameSystem *gameSystem);

extern void *ICA_ANIME_GetField20(struct GameSystem *gameSystem);

extern int FIELDMAP_IsReady(void *fieldMap);

extern void FIELDMAP_CTRL_GRID_SetBusy(void *fieldMap, unsigned int enable);

extern u16 FIELDMAP_GetZoneId(void *fieldMap);

extern u32 ZONEDATA_IsZone1A6(u32 zoneId);

extern void UNION_CHARA_RefreshParentMarks(UnionRoomWork *work, struct GameData *gameData, void *fieldMap);

extern void COMM_PLAYER_Resume(void *commPlayer);

extern void COMM_PLAYER_Suspend(void *commPlayer);

extern GFLNetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);

extern int GFL_NET_SendToHandle(GFLNetHandle *handle, u32 command, u32 size, const void *data);

extern u32 GFL_NET_GetHandleNetID(GFLNetHandle *handle);

extern struct MyStatus *GAME_DATA_GetPlayerStatusById(struct GameData *gameData, u32 index);

extern void MYSTATUS_Copy(const void *src, struct MyStatus *dst);

extern int MYSTATUS_GetSize(void);

extern u32 GFL_NET_SendData(GFLNetHandle *handle, u32 sendId, u32 command, u32 size, const void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode);

extern void COMM_ENTRY_MENU_AddMember(void *entryMenu, int netId, struct MyStatus *myStatus, u32 modeFlag, const void *mac);

extern int UNION_APP_TryAcceptMember(struct UnionAppWork *app, int netId);

extern u32 GFL_NET_SendDataMask(GFLNetHandle *handle, u32 sendMask, u32 command, u32 size, const void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode);

extern void UNION_APP_AddQuitRequest(struct UnionAppWork *app, u8 netId);

extern void UNION_APP_SetQuitAccepted(struct UnionAppWork *app);

extern void UNION_APP_AddSettingTarget(struct UnionAppWork *app, u8 netId);

extern void UNION_APP_SetSetting(struct UnionAppWork *app, const void *value);

extern u32 UNION_APP_GetSettingSize(GFLNetHandle *handle);

extern void UNION_APP_SetMemberEntry(struct UnionAppWork *app, UnionRoomWork *work, u8 netId, const void *data);

extern void UNION_APP_AddEntryTarget(struct UnionAppWork *app, u8 netId);

extern void UNION_APP_QueueJoinConfirm(struct UnionAppWork *app, int netId);

extern void UNION_APP_OnMemberDropped(struct UnionAppWork *app, u8 value);

extern void *GAME_EVENT_Create(struct GameSystem *gameSystem, void *parentEvent, int (*eventFunc)(void *event, int *seq, UnionSubEventWork *eventWork), u32 workSize);

extern void *GAME_EVENT_GetWork(void *event);

extern void UNION_MSG_CloseAllWindows(UnionRoomWork *work);

extern void GAME_EVENT_CallEvent(void *event, void *nextEvent);

void UNION_COMM_StartConnectSync(UnionRoomWork *work);

void UNION_COMM_SetSituationParam(UnionRoomWork *work, u32 id, u32 value);

void UNION_MAIN_StartComm(struct GameSystem *gameSystem);

void UNION_MAIN_UpdateField(struct GameComm *gameComm, void *fieldMap);

int UNION_MAIN_IsFieldReady(UnionRoomWork *work);

void UNION_MAIN_FieldCreateCallback(void *gameSystem, UnionRoomWork *work, void *fieldMap);

void UNION_MAIN_FieldDeleteCallback(void *gameSystem, UnionRoomWork *work);

int UNION_MAIN_GetFieldRequest(UnionRoomWork *work);

int UNION_MAIN_IsExitStarted(UnionRoomWork *work);

void UNION_MAIN_SetAppealNo(UnionRoomWork *work, int appealNo);

u8 UNION_MAIN_GetAppealNo(UnionRoomWork *work);

int UNION_MAIN_IsIdle(struct GameSystem *gameSystem);

u8 *UNION_COMMAND_GetRecvBuffer(int netId, UnionRoomWork *work, int size);

void UNION_COMMAND_RecvConnectSync(int netId, int size, const void *data, UnionRoomWork *work);

int UNION_COMMAND_SendConnectSync(void);

void UNION_COMMAND_RecvPartnerSelectA(u32 netId, int size, const u32 *data, UnionRoomWork *work);

int UNION_COMMAND_SendPartnerSelectA(int select);

void UNION_COMMAND_RecvPartnerSelectB(u32 netId, int size, const u32 *data, UnionRoomWork *work);

int UNION_COMMAND_SendPartnerSelectB(int select);

void UNION_COMMAND_RecvPartnerMac(u32 netId, int size, const void *data, UnionRoomWork *work);

int UNION_COMMAND_SendMyMac(void);

void UNION_COMMAND_RecvPartnerMode(u32 netId, int size, const u32 *data, UnionRoomWork *work);

int UNION_COMMAND_SendPartnerMode(int mode);

void UNION_COMMAND_RecvMyStatus(u32 netId, int size, const void *data, UnionRoomWork *work);

int UNION_COMMAND_SendMyStatus(UnionRoomWork *work);

void UNION_COMMAND_RecvTrainerCard(u32 netId, u32 size, const void *data, UnionRoomWork *work);

u32 UNION_COMMAND_SendTrainerCard(UnionRoomWork *work);

void UNION_COMMAND_RecvColosseumEntry(int netId, int size, const ColosseumPlayer *player, UnionRoomWork *work);

void UNION_COMMAND_RecvColosseumSetting(int netId, int size, const u32 *value, UnionRoomWork *work);

void UNION_COMMAND_RecvColosseumCancel(int netId, int size, const void *data, UnionRoomWork *work);

int UNION_COMMAND_SendColosseumCancel(void);

void UNION_COMMAND_RecvAppEntry(int netId, int size, const void *data, UnionRoomWork *work);

u32 UNION_COMMAND_SendAppEntry(UnionRoomWork *work);

void UNION_COMMAND_RecvAppEntryRefused(int netId, int size, const void *data, UnionRoomWork *work);

int UNION_COMMAND_SendAppEntryRefused(u32 sendMask);

void UNION_COMMAND_RecvAppEntryAccepted(int netId, int size, const void *data, UnionRoomWork *work);

int UNION_COMMAND_SendAppEntryAccepted(int sendMask);

void UNION_COMMAND_RecvAppQuitRequest(int netId, int size, const void *data, UnionRoomWork *work);

u32 UNION_COMMAND_SendAppQuitRequest(void);

void UNION_COMMAND_RecvAppQuitAccept(int netId, int size, const void *data, UnionRoomWork *work);

u32 UNION_COMMAND_SendAppQuitAccept(u32 sendMask);

void UNION_COMMAND_RecvAppQuitCancel(int netId, int size, const void *data, UnionRoomWork *work);

int UNION_COMMAND_SendAppQuitCancel(void);

void UNION_COMMAND_RecvAppSetting(int netId, int size, const void *value, UnionRoomWork *work);

u32 UNION_COMMAND_SendAppSetting(const void *data, u32 sendMask);

void UNION_COMMAND_RecvAppJoinData(int netId, int size, const void *data, UnionRoomWork *work);

int UNION_COMMAND_SendAppJoinData(u8 sendMask, const UnionAppData *src);

void UNION_COMMAND_RecvAppData(int netId, int size, const void *data, UnionRoomWork *work);

u32 UNION_COMMAND_SendAppData(u32 sendMask, const UnionAppMessage *message);

void UNION_COMMAND_RecvAppLeaveData(int netId, int size, const void *data, UnionRoomWork *work);

int UNION_COMMAND_SendAppLeaveData(u8 sendMask, const UnionAppData *src);

void UNION_COMMAND_RecvAppNotice(int netId, int size, const u8 *data, UnionRoomWork *work);

void UNION_COMMAND_SendAppNotice(u32 sendMask, u8 value);

void *UNION_MAIN_CreateSubEvent(struct GameSystem *gameSystem, void *fieldMap, UnionRoomWork *work);

int UNION_MAIN_SubEventMain(void *event, int *seq, UnionSubEventWork *eventWork);

extern char sUnionMainAssertText[];

extern char sUnionMainFile[];

extern const char sUnionCmdAssertText[];

extern const UnionSubEventEntry sUnionSubEventTable[];

/* ---- union_main.c ---- */
void UNION_MAIN_StartComm(struct GameSystem *gameSystem)
{
    struct GameComm *gameComm;
    struct GameData *gameData;
    UnionParentWork *parent;

    gameComm = ICA_ANIME_GetField24(gameSystem);
    gameData = ICA_ANIME_GetField1C(gameSystem);
    if (GAME_COMM_GetKind(gameComm) != 0) {
        SAVEDATA_PanicFail(sUnionMainAssertText, 0, sUnionMainAssertText);
    }
    parent = GFL_HEAP_Alloc(5, sizeof(UnionParentWork), 1, sUnionMainFile, 0x37);
    parent->myStatus = GAME_DATA_GetMyStatus(gameData);
    parent->gameComm = gameComm;
    parent->gameData = gameData;
    parent->gameSystem = gameSystem;
    GAME_COMM_Start(gameComm, 3, parent);
    GAME_BEACON_SEARCH_SetFieldEvent();
}

void UNION_MAIN_UpdateField(struct GameComm *gameComm, void *fieldMap)
{
    UnionRoomWork *work;
    u8 status;

    if (GAME_COMM_GetKind(gameComm) != 3) {
        return;
    }
    work = GAME_COMM_GetWork(gameComm);
    if (work == 0) {
        SAVEDATA_PanicFail(sUnionMainAssertText, 0, sUnionMainAssertText);
    }
    if (ICA_ANIME_GetField30(FIELDMAP_GetGameSystem(fieldMap)) == 1) {
        return;
    }
    if (GAME_EVENT_IsRunning(work->parent->gameSystem) == 1) {
        return;
    }
    if (UNION_MAIN_IsFieldReady(work) != 1) {
        return;
    }
    status = work->mySituation.status;
    if (status >= 4 && status <= 0x17) {
        if (UNION_MAIN_IsScenePending(work) != 0) {
            return;
        }
        UNION_ONESELF_RunPlayCategory(work, fieldMap);
        return;
    }
    if (status != 0 && status != 1) {
        return;
    }
    if (UNION_MAIN_IsScenePending(work) != 0) {
        return;
    }
    UNION_CHARA_ProcessBeaconUpdates(work);
    UNION_ONESELF_RunPlayCategory(work, fieldMap);
    UNION_CHARA_Main(work, work->parent->gameData, fieldMap);
}

int UNION_MAIN_IsFieldReady(UnionRoomWork *work)
{
    if (work->fieldActive == 1 && ICA_ANIME_Check2114(work->parent->gameSystem) == 1
        && FIELDMAP_IsReady(ICA_ANIME_GetField20(work->parent->gameSystem)) == 1)
        return 1;
    return 0;
}

void UNION_MAIN_FieldCreateCallback(void *gameSystem, UnionRoomWork *work, void *fieldMap)
{
    ColosseumWork *colosseum;

    colosseum = work->colosseum;
    work->fieldActive = 1;
    if (work->fieldBusy == 1) {
        FIELDMAP_CTRL_GRID_SetBusy(fieldMap, 1);
    }
    if (ZONEDATA_IsZone1A6(FIELDMAP_GetZoneId(fieldMap)) == 1) {
        UNION_CHARA_RefreshParentMarks(work, ICA_ANIME_GetField1C(work->parent->gameSystem), fieldMap);
    }
    if (colosseum != 0 && colosseum->startFlag == 1) {
        COMM_PLAYER_Resume(colosseum->commPlayer);
    }
}

void UNION_MAIN_FieldDeleteCallback(void *gameSystem, UnionRoomWork *work)
{
    ColosseumWork *colosseum;

    colosseum = work->colosseum;
    if (colosseum != 0) {
        if (colosseum->exitRequested == 1) {
            COLOSSEUM_Delete(colosseum, work->parent->gameSystem);
            work->colosseum = 0;
        } else if (colosseum->startFlag == 1) {
            COMM_PLAYER_Suspend(colosseum->commPlayer);
        }
    }
    work->fieldActive = 0;
}

int UNION_MAIN_GetFieldRequest(UnionRoomWork *work)
{
    return work->fieldRequest;
}

int UNION_MAIN_IsExitStarted(UnionRoomWork *work)
{
    return work->exitStarted;
}

void UNION_MAIN_SetAppealNo(UnionRoomWork *work, int appealNo)
{
    work->mySituation.appealNo = appealNo;
}

u8 UNION_MAIN_GetAppealNo(UnionRoomWork *work)
{
    return work->mySituation.appealNo;
}

int UNION_MAIN_IsIdle(struct GameSystem *gameSystem)
{
    UnionRoomWork *work = GAME_COMM_GetWork(ICA_ANIME_GetField24(gameSystem));
    if (work == 0) return 0;
    if ((work->mySituation.playCategory == 0
         || work->mySituation.playCategory == UNION_PLAY_CATEGORY_COLOSSEUM)
        && work->fieldBusy == 0) return 1;
    return 0;
}

/* ---- union command table (net commands 0x1400 to 0x1414) ---- */
u8 *UNION_COMMAND_GetRecvBuffer(int netId, UnionRoomWork *work, int size)
{
    if (size > UNION_RECV_BUFFER_SIZE) SAVEDATA_PanicFail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
    return work->recvBuffer[netId];
}

void UNION_COMMAND_RecvConnectSync(int netId, int size, const void *data, UnionRoomWork *work)
{
    UNION_COMM_StartConnectSync(work);
    work->mySituation.connect.syncReadyBits |= (u8)(1 << netId);
}

int UNION_COMMAND_SendConnectSync(void)
{
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x1400, 0, 0);
}

void UNION_COMMAND_RecvPartnerSelectA(u32 netId, int size, const u32 *data, UnionRoomWork *work)
{
    UnionMySituation *situation = &work->mySituation;
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) situation->connect.partnerSelectA = *data;
}

int UNION_COMMAND_SendPartnerSelectA(int select)
{
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x1401, 4, &select);
}

void UNION_COMMAND_RecvPartnerSelectB(u32 netId, int size, const u32 *data, UnionRoomWork *work)
{
    UnionMySituation *situation = &work->mySituation;
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) situation->connect.partnerSelectB = *data;
}

int UNION_COMMAND_SendPartnerSelectB(int select)
{
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x1402, 4, &select);
}

void UNION_COMMAND_RecvPartnerMac(u32 netId, int size, const void *data, UnionRoomWork *work)
{
    UnionMySituation *situation = &work->mySituation;
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) MI_CpuCopy8(data, &situation->connect.partnerMac, sizeof(UnionMacPacket));
}

int UNION_COMMAND_SendMyMac(void)
{
    UnionMacPacket packet;
    MI_CpuFill8(&packet, 0, sizeof(UnionMacPacket));
    OS_GetMacAddress(packet.mac);
    packet.enabled = 1;
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x1403, sizeof(UnionMacPacket), &packet);
}

void UNION_COMMAND_RecvPartnerMode(u32 netId, int size, const u32 *data, UnionRoomWork *work)
{
    UnionMySituation *situation = &work->mySituation;
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) situation->connect.partnerMode = (u8)*data;
}

int UNION_COMMAND_SendPartnerMode(int mode)
{
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x1404, 4, &mode);
}

void UNION_COMMAND_RecvMyStatus(u32 netId, int size, const void *data, UnionRoomWork *work)
{
    MYSTATUS_Copy(data, GAME_DATA_GetPlayerStatusById(work->parent->gameData, netId));
    work->mySituation.connect.myStatusRecvBits |= (u8)(1 << netId);
}

int UNION_COMMAND_SendMyStatus(UnionRoomWork *work)
{
    GFLNetHandle *handle;
    int size;
    handle = GFL_NET_HANDLE_GetCurrentHandle();
    size = MYSTATUS_GetSize();
    return GFL_NET_SendToHandle(handle, (u16)0x1405, (u16)size, GAME_DATA_GetMyStatus(work->parent->gameData));
}

/* stand-in: the plain path work->mySituation.connect.trainerCardReceived
 * folds the two offsets into one add of 0x288D and changes the bytes; the
 * enum-typed offset keeps the add of 0x2830 and the +0x5D store apart. */
void UNION_COMMAND_RecvTrainerCard(u32 netId, u32 size, const void *data, UnionRoomWork *work)
{
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) {
        enum { SITUATION_OFFSET = 0x2830 } offset = SITUATION_OFFSET;
        UnionMySituation *situation = (UnionMySituation *)((u8 *)work + offset);
        situation->connect.trainerCardReceived = 1;
        MI_CpuCopy8(data, work->recvTrainerCard, size);
    }
}

u32 UNION_COMMAND_SendTrainerCard(UnionRoomWork *work)
{
    if (work->myTrainerCard == 0) {
        SAVEDATA_PanicFail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
    }
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0xff, 0x1406, 0x678, work->myTrainerCard, 1, 0, 1);
}

void UNION_COMMAND_RecvColosseumEntry(int netId, int size, const ColosseumPlayer *player, UnionRoomWork *work)
{
    ColosseumWork *colosseum;
    struct GameData *gameData;
    u32 macBuffer[2];
    colosseum = work->colosseum;
    gameData = ICA_ANIME_GetField1C(work->parent->gameSystem);
    if (colosseum == 0 || colosseum->commPlayer == 0 || colosseum->entryMenu == 0) {
        SAVEDATA_PanicFail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
        return;
    }
    OS_GetMacAddress(macBuffer);
    COMM_ENTRY_MENU_AddMember(colosseum->entryMenu, netId, GAME_DATA_GetMyStatus(gameData), player->modeFlag, macBuffer);
}

void UNION_COMMAND_RecvColosseumSetting(int netId, int size, const u32 *value, UnionRoomWork *work)
{
    ColosseumWork *colosseum;
    colosseum = work->colosseum;
    if (colosseum == 0) {
        SAVEDATA_PanicFail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
        return;
    }
    colosseum->parentSetting = *value;
}

void UNION_COMMAND_RecvColosseumCancel(int netId, int size, const void *data, UnionRoomWork *work)
{
    ColosseumWork *colosseum;
    colosseum = work->colosseum;
    if (colosseum == 0) {
        SAVEDATA_PanicFail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
        return;
    }
    colosseum->entryCancelled = 1;
}

int UNION_COMMAND_SendColosseumCancel(void)
{
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x1409, 0, 0);
}

void UNION_COMMAND_RecvAppEntry(int netId, int size, const void *data, UnionRoomWork *work)
{
    if (work->app == 0) {
        SAVEDATA_PanicFail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
        work->entryRefuseBits |= (u8)(1 << netId);
        return;
    }
    if (UNION_APP_TryAcceptMember(work->app, (u8)netId) == 1) {
        work->entryAcceptBits |= (u8)(1 << netId);
        return;
    }
    work->entryRefuseBits |= (u8)(1 << netId);
}

u32 UNION_COMMAND_SendAppEntry(UnionRoomWork *work)
{
    work->entryResult = 0;
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0, 0x140A, MYSTATUS_GetSize(),
                  GAME_DATA_GetMyStatus(work->parent->gameData), 1, 0, 0);
}

void UNION_COMMAND_RecvAppEntryRefused(int netId, int size, const void *data, UnionRoomWork *work) { work->entryResult = 2; }

int UNION_COMMAND_SendAppEntryRefused(u32 sendMask)
{
    return GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x140B, 0, 0, 1, 0, 0);
}

void UNION_COMMAND_RecvAppEntryAccepted(int netId, int size, const void *data, UnionRoomWork *work)
{
    work->entryResult = 1;
}

int UNION_COMMAND_SendAppEntryAccepted(int sendMask)
{
    return GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x140C, 0, 0, 1, 0, 0);
}

/* The second null test is dead code, but the bytes have its branch. */
void UNION_COMMAND_RecvAppQuitRequest(int netId, int size, const void *data, UnionRoomWork *work)
{
    struct UnionAppWork *app;
    if (GFL_NET_IsParentAid() != 0) {
        app = work->app;
        if (app == 0) {
            if (app == 0) {
                SAVEDATA_PanicFail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
                return;
            }
        } else {
            UNION_APP_AddQuitRequest(app, (u8)netId);
        }
    }
}

u32 UNION_COMMAND_SendAppQuitRequest(void)
{
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0, 0x140D, 0, 0, 1, 0, 0);
}

void UNION_COMMAND_RecvAppQuitAccept(int netId, int size, const void *data, UnionRoomWork *work)
{
    struct UnionAppWork *app;
    app = work->app;
    if (app == 0) {
        if (app == 0) {
            SAVEDATA_PanicFail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
            return;
        }
    } else {
        UNION_APP_SetQuitAccepted(app);
    }
}

u32 UNION_COMMAND_SendAppQuitAccept(u32 sendMask)
{
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x140E, 0, 0, 1, 0, 0);
}

void UNION_COMMAND_RecvAppQuitCancel(int netId, int size, const void *data, UnionRoomWork *work)
{
    struct UnionAppWork *app;
    if (GFL_NET_IsParentAid() != 0) {
        app = work->app;
        if (app == 0) {
            if (app == 0) {
                SAVEDATA_PanicFail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
                return;
            }
        } else {
            UNION_APP_AddSettingTarget(app, (u8)netId);
        }
    }
}

int UNION_COMMAND_SendAppQuitCancel(void)
{
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0, 0x140F, 0, 0, 1, 0, 0);
}

void UNION_COMMAND_RecvAppSetting(int netId, int size, const void *value, UnionRoomWork *work)
{
    struct UnionAppWork *app;
    if (GFL_NET_IsParentAid() != 1) {
        app = work->app;
        if (app == 0) {
            SAVEDATA_PanicFail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
            return;
        }
        UNION_APP_SetSetting(app, value);
    }
}

u32 UNION_COMMAND_SendAppSetting(const void *data, u32 sendMask)
{
    GFLNetHandle *handle;
    u32 size;
    handle = GFL_NET_HANDLE_GetCurrentHandle();
    size = UNION_APP_GetSettingSize(handle);
    return GFL_NET_SendDataMask(handle, sendMask, 0x1410, size, data, 1, 0, 0);
}

void UNION_COMMAND_RecvAppJoinData(int netId, int size, const void *data, UnionRoomWork *work)
{
    if (work->app == 0) {
        SAVEDATA_PanicFail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
        return;
    }
    UNION_APP_SetMemberEntry(work->app, work, netId, data);
    UNION_APP_AddEntryTarget(work->app, netId);
}

int UNION_COMMAND_SendAppJoinData(u8 sendMask, const UnionAppData *src)
{
    UnionAppMessage message;
    MI_CpuFill8(&message, 0, sizeof(UnionAppMessage));
    message.data = *src;
    OS_GetMacAddress(message.mac);
    return GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x1411, sizeof(UnionAppMessage), &message, 1, 0, 0);
}

void UNION_COMMAND_RecvAppData(int netId, int size, const void *data, UnionRoomWork *work)
{
    if (work->app == 0) {
        SAVEDATA_PanicFail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
        return;
    }
    UNION_APP_SetMemberEntry(work->app, work, netId, data);
}

u32 UNION_COMMAND_SendAppData(u32 sendMask, const UnionAppMessage *message)
{
    return GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x1412, sizeof(UnionAppMessage), message, 1, 0, 0);
}

void UNION_COMMAND_RecvAppLeaveData(int netId, int size, const void *data, UnionRoomWork *work)
{
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) {
        if (work->app == 0) {
            SAVEDATA_PanicFail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
            return;
        }
        UNION_APP_SetMemberEntry(work->app, work, (u8)netId, data);
        UNION_APP_QueueJoinConfirm(work->app, (u8)netId);
    }
}

int UNION_COMMAND_SendAppLeaveData(u8 sendMask, const UnionAppData *src)
{
    UnionAppMessage message;
    MI_CpuFill8(&message, 0, sizeof(UnionAppMessage));
    message.data = *src;
    OS_GetMacAddress(message.mac);
    return GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x1413, sizeof(UnionAppMessage), &message, 1, 0, 0);
}

void UNION_COMMAND_RecvAppNotice(int netId, int size, const u8 *data, UnionRoomWork *work)
{
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) {
        if (work->app == 0) {
            SAVEDATA_PanicFail(sUnionCmdAssertText, 0, sUnionCmdAssertText);
            return;
        }
        UNION_APP_OnMemberDropped(work->app, *data);
    }
}

void UNION_COMMAND_SendAppNotice(u32 sendMask, u8 value)
{
    GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x1414, 1, &value, 1, 0, 0);
}

void *UNION_MAIN_CreateSubEvent(struct GameSystem *gameSystem, void *fieldMap, UnionRoomWork *work)
{
    void *event;
    UnionSubEventWork *eventWork;
    event = GAME_EVENT_Create(gameSystem, 0, UNION_MAIN_SubEventMain, sizeof(UnionSubEventWork));
    eventWork = GAME_EVENT_GetWork(event);
    eventWork->gameSystem = gameSystem;
    eventWork->fieldMap = fieldMap;
    eventWork->work = work;
    work->subEvent.active = 1;
    return event;
}

int UNION_MAIN_SubEventMain(void *event, int *seq, UnionSubEventWork *eventWork)
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

extern struct GameEvent *FIELD_STATUS_CreateSubProcEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int overlayId, int procData, int procWork);

extern struct GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeOut(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int sel, int arg);

extern struct GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeIn(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int sel, int arg, int flag, u8 flagA, u8 flagB);

extern struct GameEvent *FIELD_STATUS_CreateFieldCloseEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);

extern void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, void *procData, void *procWork);

extern u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem);

extern struct GameEvent *FIELD_STATUS_CreateFieldOpenEvent(struct GameSystem *gameSystem);

extern void UNION_APP_Update(struct UnionAppWork *app, UnionRoomWork *unionRoom);

extern int   GF_OVERLAY_Load(signed int overlayId);

extern void  GF_OVERLAY_Unload(int overlayId);

extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gameData);

extern struct UnionAppWork *UNION_APP_Create(UnionRoomWork *unionRoom, int heapId, int kind, struct MyStatus *myStatus);

extern void GFL_NET_HANDLE_SetTimingSyncRange(GFLNetHandle *handle, unsigned int timingNo, unsigned int syncRange);

extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(GFLNetHandle *handle, unsigned int timingNo, unsigned int syncRange);

extern u8 UNION_APP_IsQuitAccepted(struct UnionAppWork *app);

extern int UNION_APP_HasMembers(struct UnionAppWork *app);

extern unsigned char UNION_APP_GetJoinedBits(struct UnionAppWork *app);

extern int UNION_APP_IsAllEntriesReceived(struct UnionAppWork *app);

extern void UNION_APP_AddSelfToJoined(struct UnionAppWork *app);

extern void UNION_COMM_SetGameKindByStatus(unsigned int activity);

extern void GFL_NET_NotifyUserEvent(GFLNetHandle *handle, int enable);

extern u8 GAME_DATA_GetSeason(const struct GameData *gameData);

extern unsigned int FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(struct GameData *gameData, unsigned int zoneId, unsigned int season);

extern void GFL_USE_ChangeBgm(unsigned int bgmNo, unsigned short fadeFrames, int arg3, int arg4);

extern int   GFL_USE_IsBgmFading(void);

extern struct GameEvent *EVENT_MAPCHANGE_CreateWarpEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int effectId, const VecFx32 *pos, u16 dir, int arg);

extern void PLIST_COMM_Update(PartyListParam *listParam);

extern void PLIST_COMM_Start(PartyListParam *listParam);

extern void PLIST_COMM_End(PartyListParam *listParam);

extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);

extern u32   POKEPARTY_GetCount(struct Party *party);

extern void *ZUKAN_SAVE_GetFromGameData(struct GameData *gameData);

extern u32 ZUKAN_SAVE_IsNationalDexEnabled(void *a);

extern struct Party *POKEPARTY_Create(u32 heapId);

extern void POKEPARTY_Copy(const struct Party *src, struct Party *dst);

extern void POKEPARTY_Init(struct Party *party);

extern struct PokemonParam *POKEPARTY_GetMember(struct Party *party, u32 index);

extern u32 POKEPARTY_Add(struct Party *party, const struct PokemonParam *pokemon);

extern u32 GFL_HEAP_Free(void *p);

extern void COLOSSEUM_ResetParties(ColosseumWork *colosseum, int arg);

extern u32 COLOSSEUM_SendParty(struct Party *party);

extern int COLOSSEUM_AllPartiesReceived(ColosseumWork *colosseum);

extern void COLOSSEUM_SetupBattleInfo(ColosseumWork *colosseum, struct GameSystem *gameSystem, u8 *battleInfo, int heapId);

extern struct GameEvent *IRC_BATTLE_TASK_Create(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u8 activity, BattleSelectParam *param);

extern struct WifiList *GAME_DATA_GetWifiList(const struct GameData *gameData);

extern int WIFILIST_FindFriendByStatus(struct WifiList *wifiList, struct MyStatus *myStatus, u32 *outIndex);

extern void WIFILIST_AddFriendBattleRecord(struct WifiList *wifiList, int index, int a, int b, int c);

extern void WIFILIST_SetFriendLastSeen(struct WifiList *wifiList, int index);

extern void  COLOSSEUM_ClearBattleInfo(u8 *battleInfo);

void UNION_MAIN_RequestScene(UnionRoomWork *unionRoom, int sceneId, int sceneParam);

int UNION_MAIN_StepStartOv111Proc(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int procWork, void *event, struct GameEvent **outEvent, u8 *step);

int UNION_MAIN_StepPokemonTrade(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, ClubTradeParam *tradeParam, void *event, struct GameEvent **outEvent, u8 *step);

int UNION_MAIN_StepGroupActivity(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int param, struct GameEvent *event, struct GameEvent **outEvent, u8 *step);

int UNION_MAIN_StepPlayEffectAtSeat(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int param, void *event, struct GameEvent **outEvent, u8 *step);

int UNION_MAIN_StepPlayEffectAtSeatLow(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int param, void *event, struct GameEvent **outEvent, u8 *step);

int UNION_MAIN_StepPlayEffectAtFixedSpot(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int param, void *event, struct GameEvent **outEvent, u8 *step);

int UNION_MAIN_StepColosseumPartyEntry(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, PartyListParam *listParam, struct GameEvent *event, struct GameEvent **outEvent, u8 *step);

u32 UNION_MAIN_StepStartBattleSelect(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, BattleSelectParam *selectParam, void *event, struct GameEvent **outEvent, u8 *step);

int UNION_MAIN_StepStartPmsInput(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int procWork, void *event, struct GameEvent **outEvent, u8 *step);

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
void UNION_MAIN_RequestScene(UnionRoomWork *unionRoom, int sceneId, int sceneParam)
{
    if (unionRoom->subEvent.id != 0 || unionRoom->subEvent.active != 0)
        SAVEDATA_PanicFail(gUnionMainEmptyString, 0, gUnionMainEmptyString);
    unionRoom->subEvent.id = sceneId;
    unionRoom->subEvent.param = sceneParam;
    unionRoom->subEvent.seq = 0;
}

/* Returns 1 while a scene is requested or running. */
int UNION_MAIN_IsScenePending(UnionRoomWork *unionRoom)
{
    if (unionRoom->subEvent.id == 0 && unionRoom->subEvent.active == 0)
        return 0;
    return 1;
}

/* Scene step: starts the ov111 sub process once, then reports done. */
int UNION_MAIN_StepStartOv111Proc(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int procWork, void *event, struct GameEvent **outEvent, u8 *step)
{
    if (*step == 0) {
        *outEvent = FIELD_STATUS_CreateSubProcEvent(gameSystem, fieldMap, (int)ov111_id, (int)gOv111ProcData, procWork);
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
 * that overlay window, as in ov001 func_021542C0.
 */
int UNION_MAIN_StepPokemonTrade(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, ClubTradeParam *tradeParam, void *event, struct GameEvent **outEvent, u8 *step)
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
        GAMESYSTEM_CallProc(gameSystem, (u32)ov119_id, gPokemonTradeProcData, tradeParam);
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
        request->partyIndex = tradeParam->partyIndex;
        request->reserved = 0;
        request->evolveCondition = tradeParam->evolveCondition;
        request->fromTrade = 1;
        request->reserved2 = 0;
        tradeParam->evolutionRequest = request;
        GAMESYSTEM_CallProc(gameSystem, (u32)ov195_id, d_02208C40, request);
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
 * UNION_MAIN_StepPokemonTrade. Pooled small words 0x16/0x17/0x89 are linker overlay ids
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
int UNION_MAIN_StepGroupActivity(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int param, struct GameEvent *event, struct GameEvent **outEvent, u8 *step)
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
        GF_OVERLAY_Load((u32)ov022_id);
        unionRoom->app = UNION_APP_Create(unionRoom, 3, 5, GAME_DATA_GetMyStatus(unionRoom->parent->gameData));
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
        if (UNION_COMMAND_SendAppQuitCancel() == 1)
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
            GFL_NET_NotifyUserEvent(GFL_NET_HANDLE_GetCurrentHandle(), 1);
            *step = 13;
        }
        break;
    case 13:
        GFL_NET_SetLoginOption(0);
        if (situation->status == 3) {
            activityParam = (ActivityParam *)scene->param;
            activityParam->unionApp = unionRoom->app;
            GAMESYSTEM_CallProc(gameSystem, (u32)ov023_id, gOekakiProcData, activityParam);
        } else {
            activityParam = (ActivityParam *)scene->param;
            activityParam->unionApp = unionRoom->app;
            GAMESYSTEM_CallProc(gameSystem, (u32)ov137_id, gGuru2ProcData, activityParam);
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
            GF_OVERLAY_Unload((int)ov022_id);
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
int UNION_MAIN_StepPlayEffectAtSeat(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int param, void *event, struct GameEvent **outEvent, u8 *step)
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
int UNION_MAIN_StepPlayEffectAtSeatLow(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int param, void *event, struct GameEvent **outEvent, u8 *step)
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
int UNION_MAIN_StepPlayEffectAtFixedSpot(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int param, void *event, struct GameEvent **outEvent, u8 *step)
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
 * UNION_MAIN_StepStartBattleSelect), which loads the base before the pool
 * offset.
 *
 * Scene step of the colosseum party entry (18 steps): the player picks the
 * party members (ov090/ov091 party list, ov131 status), the party is sent to
 * the other players, then the battle selection runs and the results are
 * written to the Wi-Fi list.
 */
int UNION_MAIN_StepColosseumPartyEntry(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, PartyListParam *listParam, struct GameEvent *event, struct GameEvent **outEvent, u8 *step)
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
        PLIST_COMM_Update(listParam);

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
        GF_OVERLAY_Load((int)ov090_id);
        PLIST_COMM_Start(listParam);
        (*step)++;
        break;
    case 3:
        GAMESYSTEM_CallProc(gameSystem, (u32)ov091_id, gPartyListProcData, listParam);
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
        GAMESYSTEM_CallProc(gameSystem, (u32)ov131_id, gPokeStatusProcData, statusParam);
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
        GF_OVERLAY_Unload((int)ov090_id);
        *step = 8;
        break;
    case 8:
        if (GFL_NET_ERR_GetErrorLevel() != 0) {
            *step = 0x11;
            break;
        }
        if (listParam->resultKind != 0)
            SAVEDATA_PanicFail(gUnionMainEmptyString, 0, gUnionMainEmptyString);
        if (listParam->cursor != 6)
            SAVEDATA_PanicFail(gUnionMainEmptyString, 0, gUnionMainEmptyString);
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
        COLOSSEUM_SetupBattleInfo(colosseum, gameSystem, selectParam->battleInfo, 0x41);
        *outEvent = IRC_BATTLE_TASK_Create(gameSystem, fieldMap, activity[0], selectParam);
        (*step)++;
        break;
    case 13:
        if (GFL_NET_ERR_GetErrorLevel() == 0) {
            wifiList = GAME_DATA_GetWifiList(GAMESYSTEM_GetGameData(gameSystem));
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
        COLOSSEUM_ClearBattleInfo(selectParam->battleInfo);
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
u32 UNION_MAIN_StepStartBattleSelect(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, BattleSelectParam *selectParam, void *event, struct GameEvent **outEvent, u8 *step)
{
    u8 *activity = &unionRoom->mySituation.status;
    if (*step == 0) {
        *outEvent = IRC_BATTLE_TASK_Create(gameSystem, fieldMap, activity[0], selectParam);
    } else {
        return 1;
    }
    (*step)++;
    return 0;
}

/* Scene step: starts the PMS word input overlay (ov110) once, then reports done. */
int UNION_MAIN_StepStartPmsInput(struct GameSystem *gameSystem, UnionRoomWork *unionRoom, struct FieldMap *fieldMap, int procWork, void *event, struct GameEvent **outEvent, u8 *step)
{
    if (*step == 0) {
        *outEvent = FIELD_STATUS_CreateSubProcEvent(gameSystem, fieldMap, (int)ov110_id, (int)gPmsInputProcData, procWork);
    } else {
        return 1;
    }
    (*step)++;
    return 0;
}
