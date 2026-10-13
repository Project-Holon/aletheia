/*
 * file:     union_comm.c
 * unit:     yes
 * function: UNION_COMM_Create, UNION_COMM_Delete, UNION_COMM_InitComm, UNION_COMM_InitWait, UNION_COMM_SessionStartCallback, UNION_COMM_Exit, UNION_COMM_ExitWait, UNION_COMM_ExitCallback, UNION_COMM_RequestRestart, UNION_COMM_RequestShutdown, UNION_COMM_RequestStart, UNION_COMM_IsResetting, UNION_COMM_UpdateReset, UNION_COMM_Update, UNION_COMM_StartConnectSync, UNION_COMM_UpdateConnectSync, UNION_COMM_SendEntryReplies, UNION_COMM_UpdateColosseum, UNION_COMM_UpdateBeaconScan, UNION_COMM_StoreBeacon, UNION_COMM_IsNotGroupMember, UNION_COMM_GetBeacon, UNION_COMM_BuildBeacon, UNION_COMM_GetBeaconSize, UNION_COMM_CompareBeacon, UNION_COMM_StateChangeCallback, UNION_COMM_ConnectEndCallback, UNION_COMM_ClearBeaconPcs, UNION_COMM_ReleaseWorks, UNION_COMM_SetSituationParam, UNION_COMM_InitSituation, UNION_COMM_ClearPartnerSelects, UNION_COMM_InitConnectInfo, UNION_COMM_AddMember, UNION_COMM_AddMemberFromBeaconPc, UNION_COMM_RemoveMember, UNION_COMM_RemoveMemberOfBeaconPc, UNION_COMM_InitChatLog, UNION_COMM_SetChatPms, UNION_COMM_SetChatType, UNION_COMM_SetGameKindByStatus, UNION_MAIN_StartComm, UNION_MAIN_UpdateField, UNION_MAIN_IsFieldReady, UNION_MAIN_FieldCreateCallback, UNION_MAIN_FieldDeleteCallback, UNION_MAIN_GetFieldRequest, UNION_MAIN_IsExitStarted, UNION_MAIN_SetAppealNo, UNION_MAIN_GetAppealNo, UNION_MAIN_IsIdle, UNION_COMMAND_GetRecvBuffer, UNION_COMMAND_RecvConnectSync, UNION_COMMAND_SendConnectSync, UNION_COMMAND_RecvPartnerSelectA, UNION_COMMAND_SendPartnerSelectA, UNION_COMMAND_RecvPartnerSelectB, UNION_COMMAND_SendPartnerSelectB, UNION_COMMAND_RecvPartnerMac, UNION_COMMAND_SendMyMac, UNION_COMMAND_RecvPartnerMode, UNION_COMMAND_SendPartnerMode, UNION_COMMAND_RecvMyStatus, UNION_COMMAND_SendMyStatus, UNION_COMMAND_RecvTrainerCard, UNION_COMMAND_SendTrainerCard, UNION_COMMAND_RecvColosseumEntry, UNION_COMMAND_RecvColosseumSetting, UNION_COMMAND_RecvColosseumCancel, UNION_COMMAND_SendColosseumCancel, UNION_COMMAND_RecvAppEntry, UNION_COMMAND_SendAppEntry, UNION_COMMAND_RecvAppEntryRefused, UNION_COMMAND_SendAppEntryRefused, UNION_COMMAND_SendAppEntryAccepted, UNION_COMMAND_RecvAppQuitRequest, UNION_COMMAND_SendAppQuitRequest, UNION_COMMAND_RecvAppQuitAccept, UNION_COMMAND_SendAppQuitAccept, UNION_COMMAND_RecvAppQuitCancel, UNION_COMMAND_SendAppQuitCancel, UNION_COMMAND_RecvAppSetting, UNION_COMMAND_SendAppSetting, UNION_COMMAND_RecvAppJoinData, UNION_COMMAND_SendAppJoinData, UNION_COMMAND_RecvAppData, UNION_COMMAND_SendAppData, UNION_COMMAND_RecvAppLeaveData, UNION_COMMAND_SendAppLeaveData, UNION_COMMAND_RecvAppNotice, UNION_COMMAND_SendAppNotice, func_0217413C, func_0217416C
 * address:  0x02172BC0
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   func_02030734  0x02030734  arm
 *   func_0200ADF0  0x0200ADF0  thumb
 *   sUnionCommFile   0x02175600  data  ov012  a1
 *   func_020307B0 0x020307B0 arm
 *   func_020306F0 0x020306F0 arm
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   sUnionNetInit 0x02175380 data ov012 a4
 *   GFL_NET_EndDeviceWrapper 0x0203D0FC arm
 *   GFL_NET_SetErrorCheckEnabled  0x0203D8C4  arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FBA0 0x0200FBA0 thumb
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   NET_WHPIPE_PublishBeacon  0x0217778C  thumb  ov014
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   func_02080D24  0x02080D24  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   UNION_MAIN_IsScenePending  0x02174268  thumb  ov012
 *   COMM_PLAYER_Update  0x02167590  thumb  ov010
 *   COMM_PLAYER_UpdateMyPackage  0x0216786C  thumb  ov010
 *   COLOSSEUM_SendPackage  0x02174C90  thumb  ov012
 *   COLOSSEUM_UpdateCommPlayers  0x0217FF78  thumb  ov019
 *   COLOSSEUM_FlushChoiceReplies  0x02175110  thumb  ov012
 *   COLOSSEUM_UpdateReadyState  0x02175144  thumb  ov012
 *   GFL_NET_GetScanResult 0x0203CF10 arm
 *   GFL_NET_GetScanResultMac 0x0203CF3C arm
 *   NET_WHPIPE_ReleaseEntry 0x02177BF4 thumb ov014
 *   memcmp            0x0203EFC8  arm
 *   MI_CpuCopy8       0x02082D44  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_020084F8  0x020084F8  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_02009CB0  0x02009CB0  thumb
 *   UNION_APP_IsClosed  0x021840C8  thumb  ov022
 *   UNION_APP_Delete  0x02183BE0  thumb  ov022
 *   COLOSSEUM_Delete  0x0217505C  thumb  ov012
 *   func_020056EC 0x020056EC thumb
 *   GFL_NET_SetGameKind  0x0203D5AC  arm
 *   func_02012138  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   func_02034714  0x02034714  arm
 *   func_02012944  0x02012944  thumb
 *   GAME_COMM_Start  0x020263D8  thumb
 *   GAME_BEACON_SEARCH_SetFieldEvent  0x021653C4  thumb  ov010
 *   sUnionMainAssertText     0x02175610  data   ov012  a1
 *   sUnionMainFile     0x02175614  data   ov012  a1
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   func_0201212C  0x0201212C  thumb
 *   GAME_EVENT_IsRunning  0x020123C4  thumb
 *   UNION_ONESELF_RunPlayCategory  0x0217B840  thumb  ov019
 *   UNION_CHARA_ProcessBeaconUpdates  0x0217B75C  thumb  ov019
 *   UNION_CHARA_Main  0x0217B264  thumb  ov019
 *   func_02012114 0x02012114 thumb
 *   func_0201210C 0x0201210C thumb
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
 *   func_02012950 0x02012950 thumb
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
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   UNION_MSG_CloseAllWindows  0x0217F074  thumb  ov019
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   sUnionSubEventTable     0x02175498  data   ov012  a4
 */
/*
 * Union room communication.  Three original files share this unit:
 * union_comm.c (0x02172BC0, the GFL_NET session, beacons and the
 * connection state), union_main.c (0x02173744, the field hooks) and the
 * union command table (0x02173984, net commands 0x1400 to 0x1414).
 * func_0217413C and func_0217416C (the sub-event runner) look like the
 * start of the sub-event file that unit_0217422C.c continues.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef signed int s32;

#include "../arm9/net_types.h"
typedef struct { s32 x, y, z; } VecFx32;
#include "union_comm_types.h"

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

extern void GFL_HEAP_CreateChildHeap(u32 parentHeapId, u32 heapId, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern struct Regulation *func_0200ADF0(u32 heapId);
extern u32 func_020307B0(void *memory);
extern void func_020306F0(u32 heapId);
extern void GFL_NET_StartSession(const GFLNetInitializeStruct *init, void (*startCallback)(UnionRoomWork *work), UnionRoomWork *work);
extern void GFL_NET_EndDeviceWrapper(int flag);
extern void GFL_NET_SetErrorCheckEnabled(u32 enable);
extern int GFL_NET_Exit(void (*exitCallback)(UnionRoomWork *work));
extern u32 func_0200FB24(void);
extern void func_0200FBA0(void);
extern int GFL_NET_GetRunState(void);
extern void NET_WHPIPE_PublishBeacon(void);
extern u32 GFL_NET_IsParentAid(void);
extern int func_02080D24(u8 bits);
extern int GFL_NET_GetNegotiationNum(void);
extern void GFL_NET_SetLoginOption(u8 option);
extern int UNION_MAIN_IsScenePending(UnionRoomWork *work);
extern void COMM_PLAYER_Update(struct GameSystem *gameSystem, void *commPlayer);
extern int COMM_PLAYER_UpdateMyPackage(void *commPlayer, CommPlayerPackage *package);
extern u32 COLOSSEUM_SendPackage(const CommPlayerPackage *package);
extern void COLOSSEUM_UpdateCommPlayers(ColosseumWork *colosseum);
extern void COLOSSEUM_FlushChoiceReplies(ColosseumWork *colosseum);
extern void COLOSSEUM_UpdateReadyState(ColosseumWork *colosseum);
extern UnionBeacon *GFL_NET_GetScanResult(int index);
extern const u8 *GFL_NET_GetScanResultMac(int index);
extern void NET_WHPIPE_ReleaseEntry(u32 index);
extern int memcmp(const void *lhs, const void *rhs, int size);
extern void MI_CpuCopy8(const void *src, void *dst, int size);
extern void MI_CpuFill8(void *dst, int value, int size);
extern void func_02087C6C(void *mac);
extern u32 func_020084F8(const struct MyStatus *status, u16 *dest, u32 size);
extern u8 func_02008554(const struct MyStatus *status);
extern u32 func_02008550(const struct MyStatus *status);
extern u32 func_02008530(const struct MyStatus *status);
extern u8 func_0200856C(const struct MyStatus *status);
extern u8 func_02008570(const struct MyStatus *status);
extern struct GameData *func_020120F4(struct GameSystem *gameSystem);
extern struct WifiList *func_0201283C(struct GameData *gameData);
extern int func_02009CB0(struct WifiList *wifiList, u8 *friendKey);
extern int UNION_APP_IsClosed(struct UnionAppWork *app);
extern void UNION_APP_Delete(struct UnionAppWork *app);
extern void COLOSSEUM_Delete(ColosseumWork *colosseum, struct GameSystem *gameSystem);
extern u32 func_020056EC(u32 range);
extern void GFL_NET_SetGameKind(int gameKind, int option);
extern struct GameComm *func_02012138(struct GameSystem *gameSystem);
extern unsigned int GAME_COMM_GetKind(struct GameComm *gameComm);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern struct MyStatus *func_02012944(struct GameData *gameData);
extern void GAME_COMM_Start(struct GameComm *gameComm, u32 kind, void *parentWork);
extern void GAME_BEACON_SEARCH_SetFieldEvent(void);
extern void *GAME_COMM_GetWork(struct GameComm *gameComm);
extern struct GameSystem *FIELDMAP_GetGameSystem(void *fieldMap);
extern u8 func_0201212C(struct GameSystem *gameSystem);
extern int GAME_EVENT_IsRunning(struct GameSystem *gameSystem);
extern int UNION_ONESELF_RunPlayCategory(UnionRoomWork *work, void *fieldMap);
extern void UNION_CHARA_ProcessBeaconUpdates(UnionRoomWork *work);
extern void UNION_CHARA_Main(UnionRoomWork *work, struct GameData *gameData, void *fieldMap);
extern u32 func_02012114(struct GameSystem *gameSystem);
extern void *func_0201210C(struct GameSystem *gameSystem);
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
extern struct MyStatus *func_02012950(struct GameData *gameData, u32 index);
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
extern void *func_020122C0(struct GameSystem *gameSystem, void *parentEvent, int (*eventFunc)(void *event, int *seq, UnionSubEventWork *eventWork), u32 workSize);
extern void *func_020124E8(void *event);
extern void UNION_MSG_CloseAllWindows(UnionRoomWork *work);
extern void GAME_EVENT_CallEvent(void *event, void *nextEvent);
UnionRoomWork *UNION_COMM_Create(UnionParentWork *parent);
void UNION_COMM_Delete(UnionParentWork *parent, UnionRoomWork *work);
UnionRoomWork *UNION_COMM_InitComm(int *seq, UnionParentWork *parent);
int UNION_COMM_InitWait(int *seq, UnionParentWork *parent, UnionRoomWork *work);
void UNION_COMM_SessionStartCallback(UnionRoomWork *work);
int UNION_COMM_Exit(int *seq, UnionParentWork *parent, UnionRoomWork *work);
int UNION_COMM_ExitWait(int *seq, UnionParentWork *parent, UnionRoomWork *work);
void UNION_COMM_ExitCallback(UnionRoomWork *work);
void UNION_COMM_RequestRestart(UnionRoomWork *work);
void UNION_COMM_RequestShutdown(UnionRoomWork *work);
void UNION_COMM_RequestStart(UnionRoomWork *work);
int UNION_COMM_IsResetting(UnionRoomWork *work);
int UNION_COMM_UpdateReset(UnionRoomWork *work);
void UNION_COMM_Update(int *seq, UnionParentWork *parent, UnionRoomWork *work);
void UNION_COMM_StartConnectSync(UnionRoomWork *work);
void UNION_COMM_UpdateConnectSync(UnionRoomWork *work);
void UNION_COMM_SendEntryReplies(UnionRoomWork *work);
void UNION_COMM_UpdateColosseum(UnionRoomWork *work);
void UNION_COMM_UpdateBeaconScan(UnionRoomWork *work);
int UNION_COMM_StoreBeacon(UnionRoomWork *work, const UnionBeacon *beacon, const u8 *mac);
int UNION_COMM_IsNotGroupMember(UnionRoomWork *work, const UnionBeacon *beacon, const u8 *mac);
UnionBeacon *UNION_COMM_GetBeacon(UnionRoomWork *work);
void UNION_COMM_BuildBeacon(UnionRoomWork *work, UnionBeacon *beacon);
int UNION_COMM_GetBeaconSize(void);
int UNION_COMM_CompareBeacon(u32 myServiceId, u32 beaconServiceId, UnionRoomWork *work);
void UNION_COMM_StateChangeCallback(void);
void UNION_COMM_ConnectEndCallback(void);
void UNION_COMM_ClearBeaconPcs(UnionRoomWork *work);
void UNION_COMM_ReleaseWorks(UnionRoomWork *work);
void UNION_COMM_SetSituationParam(UnionRoomWork *work, u32 id, u32 value);
void UNION_COMM_InitSituation(UnionRoomWork *work);
void UNION_COMM_ClearPartnerSelects(UnionConnectInfo *connect);
void UNION_COMM_InitConnectInfo(UnionRoomWork *work, UnionConnectInfo *connect);
int UNION_COMM_AddMember(UnionConnectInfo *connect, const u8 *mac, u8 trainerView, u8 sex);
int UNION_COMM_AddMemberFromBeaconPc(UnionConnectInfo *connect, const UnionBeaconPc *pc);
void UNION_COMM_RemoveMember(UnionConnectInfo *connect, const u8 *mac);
void UNION_COMM_RemoveMemberOfBeaconPc(UnionConnectInfo *connect, const UnionBeaconPc *pc);
void UNION_COMM_InitChatLog(UnionChatLog *log);
void UNION_COMM_SetChatPms(UnionRoomWork *work, const UnionPmsData *pms);
void UNION_COMM_SetChatType(UnionRoomWork *work, int chatType);
void UNION_COMM_SetGameKindByStatus(u32 status);
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
void UNION_COMMAND_SendAppJoinData(u32 sendMask, const UnionAppData *src);
void UNION_COMMAND_RecvAppData(int netId, int size, const void *data, UnionRoomWork *work);
u32 UNION_COMMAND_SendAppData(u32 sendMask, const UnionAppMessage *message);
void UNION_COMMAND_RecvAppLeaveData(int netId, int size, const void *data, UnionRoomWork *work);
void UNION_COMMAND_SendAppLeaveData(u32 sendMask, const UnionAppData *src);
void UNION_COMMAND_RecvAppNotice(int netId, int size, const u8 *data, UnionRoomWork *work);
void UNION_COMMAND_SendAppNotice(u32 sendMask, u8 value);
void *func_0217413C(struct GameSystem *gameSystem, void *fieldMap, UnionRoomWork *work);
int func_0217416C(void *event, int *seq, UnionSubEventWork *eventWork);
extern char sUnionCommFile[];
extern const GFLNetInitializeStruct sUnionNetInit;
extern char sUnionMainAssertText[];
extern char sUnionMainFile[];
extern const char sUnionCmdAssertText[];
extern const UnionSubEventEntry sUnionSubEventTable[];

UnionRoomWork *UNION_COMM_Create(UnionParentWork *parent)
{
    UnionRoomWork *work;

    GFL_HEAP_CreateChildHeap(4, UNION_HEAP_ID, 0x8a00);
    work = func_02030734(UNION_HEAP_ID, sizeof(UnionRoomWork), 1, sUnionCommFile, 0x89);
    work->parent = parent;
    UNION_COMM_InitSituation(work);
    work->mySituation.chatUpdated = 1;
    UNION_COMM_InitChatLog(&work->chatLog);
    work->regulation = func_0200ADF0(UNION_HEAP_ID);
    work->fieldActive = 1;
    return work;
}

void UNION_COMM_Delete(UnionParentWork *parent, UnionRoomWork *work)
{
    if (work->regulation != 0) func_020307B0(work->regulation);
    UNION_COMM_ReleaseWorks(work);
    func_020307B0(work);
    func_020306F0(UNION_HEAP_ID);
    func_020307B0(parent);
}

UnionRoomWork *UNION_COMM_InitComm(int *seq, UnionParentWork *parent)
{
    UnionRoomWork *work;

    work = UNION_COMM_Create(parent);
    work->commState = 1;
    GFL_NET_StartSession(&sUnionNetInit, UNION_COMM_SessionStartCallback, work);
    return work;
}

int UNION_COMM_InitWait(int *seq, UnionParentWork *parent, UnionRoomWork *work)
{
    if (work->commState >= 2) {
        work->commState = 3;
        GFL_NET_EndDeviceWrapper(0);
        return 1;
    }
    return 0;
}

void UNION_COMM_SessionStartCallback(UnionRoomWork *work)
{
    work->commState = 2;
    GFL_NET_SetErrorCheckEnabled(0);
}

int UNION_COMM_Exit(int *seq, UnionParentWork *parent, UnionRoomWork *work)
{
    work->exitStarted = 1;
    if (work->commState < 3) return 0;
    work->commState = 4;
    if (GFL_NET_Exit(UNION_COMM_ExitCallback) == 0) UNION_COMM_ExitCallback(work);
    return 1;
}

int UNION_COMM_ExitWait(int *seq, UnionParentWork *parent, UnionRoomWork *work)
{
    if (work->commState == 5) {
        UNION_COMM_Delete(parent, work);
        if (func_0200FB24() != 0) func_0200FBA0();
        return 1;
    }
    return 0;
}

void UNION_COMM_ExitCallback(UnionRoomWork *work) { work->commState = 5; }

void UNION_COMM_RequestRestart(UnionRoomWork *work)
{
    if (work->resetSeq == 0) {
        work->resetSeq = 1;
        work->resetMode = 0;
    }
}

void UNION_COMM_RequestShutdown(UnionRoomWork *work)
{
    if (work->resetSeq == 0) {
        work->resetSeq = 1;
        work->resetMode = 1;
    }
}

void UNION_COMM_RequestStart(UnionRoomWork *work)
{
    if (work->resetSeq == 0) {
        work->resetSeq = 1;
        work->resetMode = 2;
    }
}

int UNION_COMM_IsResetting(UnionRoomWork *work)
{
    if (work->resetSeq != 0)
        return 1;
    return 0;
}

int UNION_COMM_UpdateReset(UnionRoomWork *work)
{
    switch (work->resetSeq) {
    case 0:
        if (work->resetMode == 1) {
            return 1;
        }
        return 0;
    case 1:
        switch (work->resetMode) {
        case 0:
        case 1:
            work->resetSeq = 2;
            break;
        case 2:
            work->resetSeq = 4;
            break;
        default:
            work->resetSeq = 0;
            break;
        }
        break;
    case 2:
        work->commState = 4;
        if (GFL_NET_Exit(UNION_COMM_ExitCallback) == 0) {
            UNION_COMM_ExitCallback(work);
        }
        work->resetSeq++;
        break;
    case 3:
        if (work->commState == 5) {
            if (work->resetMode == 1) {
                work->resetSeq = 0;
            } else {
                work->resetSeq++;
            }
        }
        break;
    case 4:
        work->commState = 1;
        GFL_NET_StartSession(&sUnionNetInit, UNION_COMM_SessionStartCallback, work);
        work->resetSeq++;
        break;
    case 5:
        if (work->commState >= 2) {
            work->commState = 3;
            GFL_NET_EndDeviceWrapper(0);
            work->resetSeq = 0;
        }
        break;
    }
    return 1;
}

void UNION_COMM_Update(int *seq, UnionParentWork *parent, UnionRoomWork *work)
{
    if (UNION_COMM_UpdateReset(work) == 1) {
        return;
    }
    if (GFL_NET_GetRunState() == 0) {
        return;
    }
    if (work->beaconChanged == 1) {
        NET_WHPIPE_PublishBeacon();
        work->beaconChanged = 0;
    }
    UNION_COMM_UpdateBeaconScan(work);
    UNION_COMM_UpdateColosseum(work);
    UNION_COMM_SendEntryReplies(work);
    UNION_COMM_UpdateConnectSync(work);
    if (func_0200FB24() != 0 && GFL_NET_IsParentAid() == 1 && work->colosseum != 0
        && work->colosseum->startFlag == 1
        && work->mySituation.playCategory == UNION_PLAY_CATEGORY_COLOSSEUM
        && work->colosseum->leaveSent == 0) {
        UNION_COMM_RequestShutdown(work);
        work->colosseum->leaveSent = 1;
    }
}

void UNION_COMM_StartConnectSync(UnionRoomWork *work) { work->mySituation.connect.syncActive = 1; }

void UNION_COMM_UpdateConnectSync(UnionRoomWork *work)
{
    UnionMySituation *situation = &work->mySituation;
    if (situation->connect.syncActive == 0) {
        return;
    }
    if (func_0200FB24() != 0) {
        return;
    }
    switch (situation->connect.syncStep) {
    case 0:
        if (UNION_COMMAND_SendConnectSync() == 1) {
            situation->connect.syncStep++;
        }
        break;
    case 1:
        if (func_02080D24(situation->connect.syncReadyBits) >= GFL_NET_GetNegotiationNum()) {
            GFL_NET_SetLoginOption(0);
            situation->connect.syncStep++;
        }
        break;
    case 2:
        if (GFL_NET_IsParentAid() == 1) {
            if (GFL_NET_GetNegotiationNum() <= 1) {
                UNION_COMM_RequestShutdown(work);
                situation->connect.syncStep++;
            }
        } else {
            UNION_COMM_RequestShutdown(work);
            situation->connect.syncStep++;
        }
        break;
    }
}

void UNION_COMM_SendEntryReplies(UnionRoomWork *work)
{
    if (GFL_NET_GetNegotiationNum() > 1) {
        if (work->entryRefuseBits != 0 && UNION_COMMAND_SendAppEntryRefused(work->entryRefuseBits) == 1) {
            work->entryRefuseBits = 0;
        }
        if (work->entryAcceptBits != 0 && UNION_COMMAND_SendAppEntryAccepted(work->entryAcceptBits) == 1) {
            work->entryAcceptBits = 0;
        }
    } else {
        work->entryRefuseBits = 0;
        work->entryAcceptBits = 0;
    }
}

void UNION_COMM_UpdateColosseum(UnionRoomWork *work)
{
    if (work->colosseum != 0 && work->colosseum->startFlag) {
        if (UNION_MAIN_IsFieldReady(work) == 1) {
            if (UNION_MAIN_IsScenePending(work) == 0) {
                COMM_PLAYER_Update(work->parent->gameSystem, work->colosseum->commPlayer);
                if (work->colosseum->packageChanged == 0) {
                    if (COMM_PLAYER_UpdateMyPackage(work->colosseum->commPlayer, &work->colosseum->myPackage) == 1) {
                        work->colosseum->packageChanged = 1;
                    }
                }
                if (work->colosseum->packageChanged == 1) {
                    if (COLOSSEUM_SendPackage(&work->colosseum->myPackage) == 1) {
                        work->colosseum->packageChanged = 0;
                    }
                }
            }
            COLOSSEUM_UpdateCommPlayers(work->colosseum);
        }
        COLOSSEUM_FlushChoiceReplies(work->colosseum);
        COLOSSEUM_UpdateReadyState(work->colosseum);
    }
}

void UNION_COMM_UpdateBeaconScan(UnionRoomWork *work)
{
    int i;
    UnionBeacon *beacon;
    const u8 *mac;

    for (i = 0; i < UNION_BEACON_PC_MAX; i++) {
        beacon = GFL_NET_GetScanResult(i);
        if (beacon) {
            mac = GFL_NET_GetScanResultMac(i);
            if (mac) UNION_COMM_StoreBeacon(work, beacon, mac);
            NET_WHPIPE_ReleaseEntry(i);
        }
    }
}

int UNION_COMM_StoreBeacon(UnionRoomWork *work, const UnionBeacon *beacon, const u8 *mac)
{
    int i;
    UnionBeaconPc *pcs;
    pcs = work->beaconPc;
    if (beacon->valid != 1)
        return 0;
    for (i = 0; i < UNION_BEACON_PC_MAX; i++) {
        UnionBeaconPc *pc = &pcs[i];
        if (pc->beacon.valid == 1 && memcmp(mac, pc->mac, 6) == 0) {
            MI_CpuCopy8(beacon, pc, sizeof(UnionBeacon));
            if (pcs[i].updateState != 1)
                pcs[i].updateState = 2;
            pcs[i].life = UNION_BEACON_PC_LIFE;
            return 1;
        }
    }
    if (UNION_COMM_IsNotGroupMember(work, beacon, mac) == 0)
        return 0;
    for (i = 0; i < UNION_BEACON_PC_MAX; i++) {
        if (pcs[i].beacon.valid != 1) {
            u8 *dst = (u8 *)&pcs[i];
            MI_CpuCopy8(beacon, dst, sizeof(UnionBeacon));
            dst += sizeof(UnionBeacon);
            MI_CpuCopy8(mac, dst, 6);
            pcs[i].index = i;
            pcs[i].updateState = 1;
            pcs[i].life = UNION_BEACON_PC_LIFE;
            return 1;
        }
    }
    return 0;
}

int UNION_COMM_IsNotGroupMember(UnionRoomWork *work, const UnionBeacon *beacon, const u8 *mac)
{
    int i;
    UnionBeaconPc *pc;
    int j;
    pc = work->beaconPc;
    for (i = 0; i < UNION_BEACON_PC_MAX; i++, pc++) {
        if (pc->beacon.valid == 1) {
            for (j = 0; j < UNION_MEMBER_MAX; j++) {
                if (pc->beacon.group.member[j].valid == 1 && memcmp(mac, pc->beacon.group.member[j].mac, 6) == 0) {
                    if (pc->life != 0) {
                        pc->life = 1;
                    }
                    return 0;
                }
            }
        }
    }
    return 1;
}

UnionBeacon *UNION_COMM_GetBeacon(UnionRoomWork *work) { UNION_COMM_BuildBeacon(work, &work->myBeacon); return &work->myBeacon; }

void UNION_COMM_BuildBeacon(UnionRoomWork *work, UnionBeacon *beacon)
{
    UnionMySituation *situation = &work->mySituation;
    MI_CpuFill8(beacon, 0, sizeof(UnionBeacon));
    if (situation->connect.connectPc != 0) {
        if (GFL_NET_IsParentAid() == 1)
            func_02087C6C(beacon->mac);
        else
            MI_CpuCopy8(situation->connect.connectPc->mac, beacon->mac, 6);
    } else if (situation->connect.talkPc != 0) {
        MI_CpuCopy8(situation->connect.talkPc->mac, beacon->mac, 6);
    }
    beacon->connectNum = GFL_NET_GetNegotiationNum();
    beacon->pmVersion = UNION_PM_VERSION;
    beacon->language = UNION_LANGUAGE;
    beacon->playCategory = situation->playCategory;
    beacon->appealNo = situation->appealNo;
    beacon->status = situation->status;
    func_020084F8(work->parent->myStatus, beacon->name, 8);
    beacon->trainerView = func_02008554(work->parent->myStatus);
    beacon->sex = func_02008550(work->parent->myStatus);
    beacon->trainerId = func_02008530(work->parent->myStatus);
    beacon->chatType = situation->chatType;
    beacon->chatPms = situation->chatPms;
    beacon->chatCount = situation->chatCount;
    beacon->nation = func_0200856C(work->parent->myStatus);
    beacon->area = func_02008570(work->parent->myStatus);
    beacon->group = situation->connect.group;
    func_02009CB0(func_0201283C(func_020120F4(work->parent->gameSystem)), beacon->friendKey);
    if (work->app != 0)
        beacon->appActive = UNION_APP_IsClosed(work->app);
    else
        beacon->appActive = 0;
    beacon->valid = 1;
    work->beaconChanged = 1;
}

int UNION_COMM_GetBeaconSize(void) { return sizeof(UnionBeacon); }

int UNION_COMM_CompareBeacon(u32 myServiceId, u32 beaconServiceId, UnionRoomWork *work)
{
    if (work->mySituation.connect.serviceLocked == 1) {
        if (myServiceId == 0x14 || beaconServiceId == 0x14)
            return 0;
        if (myServiceId == beaconServiceId)
            return 1;
        return 0;
    }
    if (beaconServiceId >= 0x14 && beaconServiceId <= 0x1b)
        return 1;
    return 0;
}

void UNION_COMM_StateChangeCallback(void) {}

void UNION_COMM_ConnectEndCallback(void) {}

void UNION_COMM_ClearBeaconPcs(UnionRoomWork *work)
{
    MI_CpuFill8(work->beaconPc, 0, sizeof(work->beaconPc));
}

void UNION_COMM_ReleaseWorks(UnionRoomWork *work)
{
    work->partnerCard = 0;
    if (work->myTrainerCard != 0) {
        func_020307B0(work->myTrainerCard);
        work->myTrainerCard = 0;
    }
    if (work->recvTrainerCard != 0) {
        func_020307B0(work->recvTrainerCard);
        work->recvTrainerCard = 0;
    }
    if (work->partySelectParam != 0) {
        func_020307B0(work->partySelectParam);
        work->partySelectParam = 0;
    }
    if (work->partySelect != 0) {
        func_020307B0(work->partySelect);
        work->partySelect = 0;
    }
    if (work->app != 0) {
        UNION_APP_Delete(work->app);
        work->app = 0;
    }
    if (work->colosseum != 0) {
        COLOSSEUM_Delete(work->colosseum, work->parent->gameSystem);
        work->colosseum = 0;
    }
}

void UNION_COMM_SetSituationParam(UnionRoomWork *work, u32 id, u32 value)
{
    UnionMySituation *situation;
    situation = &work->mySituation;
    switch (id) {
    case 0:
        situation->connect.talkParam = (UnionBeacon *)value;
        return;
    case 1:
        situation->connect.talkPc = (UnionBeaconPc *)value;
        return;
    case 2:
        situation->connect.connectParam = (UnionBeaconPc *)value;
        return;
    case 3:
        situation->connect.connectPc = (UnionBeaconPc *)value;
        return;
    case 4:
        situation->status = value;
    }
}

void UNION_COMM_InitSituation(UnionRoomWork *work)
{
    UnionMySituation *situation;
    situation = &work->mySituation;
    MI_CpuFill8(situation, 0, sizeof(UnionMySituation));
    situation->chatCount = func_020056EC(0xffff);
    situation->chatType = 1;
    situation->playCategory = 2;
    UNION_COMM_InitConnectInfo(work, &situation->connect);
}

void UNION_COMM_ClearPartnerSelects(UnionConnectInfo *connect)
{
    connect->partnerSelectA = 0xff;
    connect->partnerSelectC = 0xff;
    connect->partnerSelectB = 0xff;
}

void UNION_COMM_InitConnectInfo(UnionRoomWork *work, UnionConnectInfo *connect)
{
    UnionMember *self;
    MI_CpuFill8(connect, 0, sizeof(UnionConnectInfo));
    UNION_COMM_ClearPartnerSelects(connect);
    self = &connect->group.member[0];
    func_02087C6C(self->mac);
    self->trainerView = func_02008554(work->parent->myStatus);
    self->sex = func_02008550(work->parent->myStatus);
    self->valid = 1;
    connect->requestId = 0xFFFF;
}

int UNION_COMM_AddMember(UnionConnectInfo *connect, const u8 *mac, u8 trainerView, u8 sex)
{
    int j;
    UnionMember *member;
    int i;
    UnionMember *slot;
    i = 0;
    member = connect->group.member;
    for (; i < UNION_MEMBER_MAX; i++) {
        if (member[i].valid == 1 && memcmp(mac, member[i].mac, 6) == 0) {
            return i;
        }
    }
    for (j = 0; j < UNION_MEMBER_MAX; j++) {
        slot = connect->group.member + j;
        if (slot->valid == 0) {
            MI_CpuCopy8(mac, slot->mac, 6);
            slot->trainerView = trainerView;
            slot->sex = sex;
            slot->valid = 1;
            return j;
        }
    }
    return 0;
}

int UNION_COMM_AddMemberFromBeaconPc(UnionConnectInfo *connect, const UnionBeaconPc *pc) { return UNION_COMM_AddMember(connect, pc->mac, pc->beacon.trainerView, pc->beacon.sex); }

void UNION_COMM_RemoveMember(UnionConnectInfo *connect, const u8 *mac)
{
    int i;
    UnionMember *member;
    i = 0;
    member = connect->group.member;
    for (; i < UNION_MEMBER_MAX; i++) {
        if (member[i].valid == 1 && memcmp(mac, member[i].mac, 6) == 0) {
            MI_CpuFill8(&member[i], 0, sizeof(UnionMember));
            return;
        }
    }
}

void UNION_COMM_RemoveMemberOfBeaconPc(UnionConnectInfo *connect, const UnionBeaconPc *pc)
{
    UNION_COMM_RemoveMember(connect, pc->mac);
}

void UNION_COMM_InitChatLog(UnionChatLog *log)
{
    int i;
    int empty;

    MI_CpuFill8(log, 0, sizeof(UnionChatLog));
    for (i = 0; i < UNION_CHAT_LOG_MAX; i++) {
        MI_CpuFill8(log->entry[i].senderMac, 0xff, 6);
    }
    empty = -1;
    log->newestIndex = empty;
    log->scrollIndex = empty;
    log->drawnIndex = empty;
}

void UNION_COMM_SetChatPms(UnionRoomWork *work, const UnionPmsData *pms)
{
    UnionMySituation *situation = &work->mySituation;
    situation->chatPms = *pms;
    situation->chatType = 0;
    situation->chatCount++;
    situation->chatUpdated = 1;
}

void UNION_COMM_SetChatType(UnionRoomWork *work, int chatType)
{
    UnionMySituation *situation = &work->mySituation;
    situation->chatType = chatType;
    situation->chatCount++;
    situation->chatUpdated = 1;
}

void UNION_COMM_SetGameKindByStatus(u32 status)
{
    switch (status) {
    case 0x14:
        GFL_NET_SetGameKind(0x17, 5);
        break;
    case 0x15:
        GFL_NET_SetGameKind(0x18, 5);
        break;
    case 0x16:
        GFL_NET_SetGameKind(0x19, 5);
        break;
    case 0x17:
        GFL_NET_SetGameKind(0x1a, 5);
        break;
    case 3:
        GFL_NET_SetGameKind(0x16, 5);
        break;
    case 0x19:
        GFL_NET_SetGameKind(0x1b, 5);
        break;
    }
}

/* ---- union_main.c ---- */

void UNION_MAIN_StartComm(struct GameSystem *gameSystem)
{
    struct GameComm *gameComm;
    struct GameData *gameData;
    UnionParentWork *parent;

    gameComm = func_02012138(gameSystem);
    gameData = func_020120F4(gameSystem);
    if (GAME_COMM_GetKind(gameComm) != 0) {
        func_02034714(sUnionMainAssertText, 0, sUnionMainAssertText);
    }
    parent = func_02030734(5, sizeof(UnionParentWork), 1, sUnionMainFile, 0x37);
    parent->myStatus = func_02012944(gameData);
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
        func_02034714(sUnionMainAssertText, 0, sUnionMainAssertText);
    }
    if (func_0201212C(FIELDMAP_GetGameSystem(fieldMap)) == 1) {
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
    if (work->fieldActive == 1 && func_02012114(work->parent->gameSystem) == 1
        && FIELDMAP_IsReady(func_0201210C(work->parent->gameSystem)) == 1)
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
        UNION_CHARA_RefreshParentMarks(work, func_020120F4(work->parent->gameSystem), fieldMap);
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
    UnionRoomWork *work = GAME_COMM_GetWork(func_02012138(gameSystem));
    if (work == 0) return 0;
    if ((work->mySituation.playCategory == 0
         || work->mySituation.playCategory == UNION_PLAY_CATEGORY_COLOSSEUM)
        && work->fieldBusy == 0) return 1;
    return 0;
}

/* ---- union command table (net commands 0x1400 to 0x1414) ---- */

u8 *UNION_COMMAND_GetRecvBuffer(int netId, UnionRoomWork *work, int size)
{
    if (size > UNION_RECV_BUFFER_SIZE) func_02034714(sUnionCmdAssertText, 0, sUnionCmdAssertText);
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
    func_02087C6C(packet.mac);
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
    MYSTATUS_Copy(data, func_02012950(work->parent->gameData, netId));
    work->mySituation.connect.myStatusRecvBits |= (u8)(1 << netId);
}

int UNION_COMMAND_SendMyStatus(UnionRoomWork *work)
{
    GFLNetHandle *handle;
    int size;
    handle = GFL_NET_HANDLE_GetCurrentHandle();
    size = MYSTATUS_GetSize();
    return GFL_NET_SendToHandle(handle, (u16)0x1405, (u16)size, func_02012944(work->parent->gameData));
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
        func_02034714(sUnionCmdAssertText, 0, sUnionCmdAssertText);
    }
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0xff, 0x1406, 0x678, work->myTrainerCard, 1, 0, 1);
}

void UNION_COMMAND_RecvColosseumEntry(int netId, int size, const ColosseumPlayer *player, UnionRoomWork *work)
{
    ColosseumWork *colosseum;
    struct GameData *gameData;
    u32 macBuffer[2];
    colosseum = work->colosseum;
    gameData = func_020120F4(work->parent->gameSystem);
    if (colosseum == 0 || colosseum->commPlayer == 0 || colosseum->entryMenu == 0) {
        func_02034714(sUnionCmdAssertText, 0, sUnionCmdAssertText);
        return;
    }
    func_02087C6C(macBuffer);
    COMM_ENTRY_MENU_AddMember(colosseum->entryMenu, netId, func_02012944(gameData), player->modeFlag, macBuffer);
}

void UNION_COMMAND_RecvColosseumSetting(int netId, int size, const u32 *value, UnionRoomWork *work)
{
    ColosseumWork *colosseum;
    colosseum = work->colosseum;
    if (colosseum == 0) {
        func_02034714(sUnionCmdAssertText, 0, sUnionCmdAssertText);
        return;
    }
    colosseum->parentSetting = *value;
}

void UNION_COMMAND_RecvColosseumCancel(int netId, int size, const void *data, UnionRoomWork *work)
{
    ColosseumWork *colosseum;
    colosseum = work->colosseum;
    if (colosseum == 0) {
        func_02034714(sUnionCmdAssertText, 0, sUnionCmdAssertText);
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
        func_02034714(sUnionCmdAssertText, 0, sUnionCmdAssertText);
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
                  func_02012944(work->parent->gameData), 1, 0, 0);
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
                func_02034714(sUnionCmdAssertText, 0, sUnionCmdAssertText);
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
            func_02034714(sUnionCmdAssertText, 0, sUnionCmdAssertText);
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
                func_02034714(sUnionCmdAssertText, 0, sUnionCmdAssertText);
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
            func_02034714(sUnionCmdAssertText, 0, sUnionCmdAssertText);
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
        func_02034714(sUnionCmdAssertText, 0, sUnionCmdAssertText);
        return;
    }
    UNION_APP_SetMemberEntry(work->app, work, netId, data);
    UNION_APP_AddEntryTarget(work->app, netId);
}

void UNION_COMMAND_SendAppJoinData(u32 sendMask, const UnionAppData *src)
{
    UnionAppMessage message;
    MI_CpuFill8(&message, 0, sizeof(UnionAppMessage));
    message.data = *src;
    func_02087C6C(message.mac);
    GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x1411, sizeof(UnionAppMessage), &message, 1, 0, 0);
}

void UNION_COMMAND_RecvAppData(int netId, int size, const void *data, UnionRoomWork *work)
{
    if (work->app == 0) {
        func_02034714(sUnionCmdAssertText, 0, sUnionCmdAssertText);
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
            func_02034714(sUnionCmdAssertText, 0, sUnionCmdAssertText);
            return;
        }
        UNION_APP_SetMemberEntry(work->app, work, (u8)netId, data);
        UNION_APP_QueueJoinConfirm(work->app, (u8)netId);
    }
}

void UNION_COMMAND_SendAppLeaveData(u32 sendMask, const UnionAppData *src)
{
    UnionAppMessage message;
    MI_CpuFill8(&message, 0, sizeof(UnionAppMessage));
    message.data = *src;
    func_02087C6C(message.mac);
    GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x1413, sizeof(UnionAppMessage), &message, 1, 0, 0);
}

void UNION_COMMAND_RecvAppNotice(int netId, int size, const u8 *data, UnionRoomWork *work)
{
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) {
        if (work->app == 0) {
            func_02034714(sUnionCmdAssertText, 0, sUnionCmdAssertText);
            return;
        }
        UNION_APP_OnMemberDropped(work->app, *data);
    }
}

void UNION_COMMAND_SendAppNotice(u32 sendMask, u8 value)
{
    GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x1414, 1, &value, 1, 0, 0);
}

void *func_0217413C(struct GameSystem *gameSystem, void *fieldMap, UnionRoomWork *work)
{
    void *event;
    UnionSubEventWork *eventWork;
    event = func_020122C0(gameSystem, 0, func_0217416C, sizeof(UnionSubEventWork));
    eventWork = func_020124E8(event);
    eventWork->gameSystem = gameSystem;
    eventWork->fieldMap = fieldMap;
    eventWork->work = work;
    work->subEvent.active = 1;
    return event;
}

int func_0217416C(void *event, int *seq, UnionSubEventWork *eventWork)
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
