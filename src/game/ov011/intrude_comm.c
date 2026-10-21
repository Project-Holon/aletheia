/*
 * file:     intrude_comm.c
 * unit:     yes
 * function: INTRUDE_COMM_Create, INTRUDE_COMM_StartSession, INTRUDE_COMM_MainStep, INTRUDE_COMM_Shutdown, INTRUDE_COMM_Destroy, INTRUDE_COMM_ScanCallback, INTRUDE_COMM_SyncPlayers, INTRUDE_COMM_SuspendPlayers, INTRUDE_COMM_OnSessionStarted, INTRUDE_COMM_OnSessionExit, INTRUDE_COMM_GetBeacon, INTRUDE_COMM_InitBeacon, INTRUDE_COMM_RefreshBeacon, INTRUDE_COMM_IsEqual, INTRUDE_COMM_RecvQuit, INTRUDE_COMM_Nop, INTRUDE_COMM_AgeFoundList, INTRUDE_COMM_GetStatusArea, INTRUDE_COMM_GetMemberRecord, INTRUDE_COMM_GetStatusRecord, INTRUDE_COMM_GetWorkArea, INTRUDE_COMM_IsLinked, INTRUDE_COMM_RecvShutdownRequest, INTRUDE_COMM_SendShutdownRequest, INTRUDE_COMM_RecvMemberCount, INTRUDE_COMM_SendMemberCount, INTRUDE_COMM_RecvRecordRequest, INTRUDE_COMM_SendRecordRequest, INTRUDE_COMM_RecvStatusRecord, INTRUDE_COMM_SendStatusRecord, INTRUDE_COMM_RecvPeerLeft, INTRUDE_COMM_SendPeerLeft, INTRUDE_COMM_RecvPeerStatus, INTRUDE_COMM_SendPeerStatus, INTRUDE_COMM_RecvTimeoutWarning, INTRUDE_COMM_SendTimeoutWarning, INTRUDE_COMM_RecvRequest, INTRUDE_COMM_SendRequest, INTRUDE_COMM_RecvReply, INTRUDE_COMM_SendReply, INTRUDE_COMM_RecvNotice, INTRUDE_COMM_SendNotice, INTRUDE_COMM_RecvAnswer, INTRUDE_COMM_SendAnswer, INTRUDE_COMM_RecvNoticeBytes, INTRUDE_COMM_SendNoticeBytes, INTRUDE_COMM_RecvReady, INTRUDE_COMM_SendReady, INTRUDE_COMM_RecvRemoteRecord, INTRUDE_CMD_SendSaveSummary, INTRUDE_CMD_RecvEntryIndex, INTRUDE_CMD_SendEntryIndex, INTRUDE_CMD_RecvMemberEntry, INTRUDE_CMD_SendMemberEntry, INTRUDE_CMD_RecvJoinRequest, INTRUDE_CMD_SendJoinRequest, INTRUDE_CMD_RecvJoinReply, INTRUDE_CMD_SendJoinReply, INTRUDE_CMD_RecvGroupRecord, INTRUDE_CMD_SendGroupRecord, INTRUDE_CMD_RecvRecordEcho, INTRUDE_CMD_SendRecordEcho, INTRUDE_CMD_RecvRecordAccept, INTRUDE_CMD_SendRecordAccept, INTRUDE_CMD_RecvMemberValue, INTRUDE_CMD_SendMemberValue, INTRUDE_CMD_RecvProposal, INTRUDE_CMD_SendProposal, INTRUDE_CMD_RecvProposalReply, INTRUDE_CMD_SendProposalReply, INTRUDE_CMD_RecvResultRecord, INTRUDE_CMD_SendResultRecord, INTRUDE_CMD_RecvReadyNotice, INTRUDE_CMD_SendReadyNotice, INTRUDE_CMD_RecvStartNotice, INTRUDE_CMD_SendStartNotice, INTRUDE_CMD_RecvEndNotice, INTRUDE_CMD_SendEndNotice, INTRUDE_CMD_RecvProfile, INTRUDE_CMD_SendProfile, INTRUDE_CMD_RecvTallyWord, INTRUDE_COMM_SendTally, INTRUDE_COMM_RecvBusyBegin, INTRUDE_COMM_SendBusyBegin, INTRUDE_COMM_RecvBusyEnd, INTRUDE_COMM_SendBusyEnd, INTRUDE_COMM_RecvPeerFlags, INTRUDE_COMM_SendPeerFlags, INTRUDE_COMM_RecvSupportMode, INTRUDE_COMM_SendSupportMode, INTRUDE_COMM_RecvProfile, INTRUDE_COMM_SendProfile, INTRUDE_COMM_RecvPairMessage, INTRUDE_COMM_SendPairMessage, INTRUDE_COMM_RecvUnionInfoRequest, INTRUDE_COMM_SendUnionInfoRequest, INTRUDE_COMM_RecvUnionInfo, INTRUDE_COMM_SendUnionInfo, INTRUDE_COMM_RecvReturnResult, INTRUDE_COMM_SendReturnResult, INTRUDE_COMM_RecvReturnPending, INTRUDE_COMM_SendReturnPending, INTRUDE_COMM_RecvPageRequest, INTRUDE_COMM_SendPageRequest, INTRUDE_COMM_RecvSymbolPage, INTRUDE_COMM_SendSymbolPage, INTRUDE_COMM_RecvAreaNotice, INTRUDE_COMM_SendAreaNotice, INTRUDE_COMM_UpdateRunning, INTRUDE_COMM_UpdateSeasonState, INTRUDE_COMM_UpdateMemberJoin, INTRUDE_COMM_UpdateMemberLeave, INTRUDE_COMM_UpdatePendingNotices, INTRUDE_COMM_UpdateUnionInfoAndReturnSlots, INTRUDE_COMM_UpdatePageRequests, INTRUDE_COMM_BuildSymbolPage, INTRUDE_COMM_SendSaveSummaryToReadyPeers, INTRUDE_COMM_SetState, INTRUDE_COMM_RefreshSelfRecord, INTRUDE_COMM_ApplyPlayerBeacon, INTRUDE_COMM_StorePlayerRecord, INTRUDE_COMM_UpdatePlayerObjects, INTRUDE_COMM_UpdatePlayerObject, INTRUDE_COMM_LookupZonePair, INTRUDE_COMM_CompareZonePair, INTRUDE_COMM_GetRelativeSlot, INTRUDE_COMM_AdjustRemotePosition, INTRUDE_COMM_AdjustAllRemotePositions, INTRUDE_COMM_UpdateSelfRecord, INTRUDE_COMM_ClearNotice, INTRUDE_COMM_GetNotice, INTRUDE_COMM_InitRequest, INTRUDE_COMM_NextRequestToken, INTRUDE_COMM_TryStartRequest, INTRUDE_COMM_SetRequestOpen, INTRUDE_COMM_ClearRequestOpen, INTRUDE_COMM_UpdateRequest, INTRUDE_COMM_GetActiveRequestTarget, INTRUDE_COMM_SetRequestResult, INTRUDE_COMM_SetRequestResultAccepted, INTRUDE_COMM_TakeRequestResult, INTRUDE_COMM_ClearRequestResult, INTRUDE_COMM_PickDefaultObjCode, INTRUDE_COMM_GetPlayerObjCode, INTRUDE_COMM_HasConnectedPeers, INTRUDE_COMM_BuildLocalProfile, INTRUDE_COMM_GetPartnerTallyValid, INTRUDE_COMM_IsValidObjCode, INTRUDE_COMM_IsValidProfileCode, INTRUDE_COMM_SetLock, INTRUDE_COMM_SetIntrudeId, INTRUDE_COMM_SetSuspended, INTRUDE_COMM_InitSession, INTRUDE_COMM_ClearSessionEntries, INTRUDE_COMM_UpdateSession, INTRUDE_COMM_GetSessionElapsed, INTRUDE_COMM_GetSessionWaitRemaining, INTRUDE_COMM_GetSessionRemaining, INTRUDE_COMM_SetSessionEntrySendFlag, INTRUDE_COMM_SetSessionRequestSendFlag, INTRUDE_COMM_SetSessionResultSendFlag, INTRUDE_COMM_StoreSessionEntry, INTRUDE_COMM_StoreSessionRequest, INTRUDE_COMM_ClearSessionTicks, INTRUDE_COMM_AddSessionMember, INTRUDE_COMM_StartSessionTimer, INTRUDE_COMM_IsSessionTimeLimitSet, INTRUDE_COMM_UpdateSessionSends, INTRUDE_COMM_UpdateSessionJoinNotices, INTRUDE_COMM_IsSessionActive, INTRUDE_COMM_GetActiveSessionRequest, INTRUDE_COMM_AcceptSession, INTRUDE_COMM_IsSessionAccepted, INTRUDE_COMM_SetSessionFinished, INTRUDE_COMM_IsSessionFinished, INTRUDE_COMM_GetSessionResult, INTRUDE_COMM_IsSessionAcceptedOrResultReady, INTRUDE_COMM_SetSessionReadyBit, INTRUDE_COMM_TakeNoticeState, INTRUDE_COMM_SetNoticeState, INTRUDE_COMM_FindFreeResultSlot, INTRUDE_COMM_StoreResultRecord, INTRUDE_COMM_GetJoinStatus, INTRUDE_COMM_ClearJoinStatus, INTRUDE_COMM_SetJoinStatus, INTRUDE_COMM_PromoteRequestToResult, INTRUDE_COMM_SetResultRecord, INTRUDE_COMM_HasResult, INTRUDE_COMM_GetRequestKind, INTRUDE_COMM_GetResultCount, INTRUDE_COMM_RecordResultOutcome, INTRUDE_COMM_HasResultReward, INTRUDE_COMM_IsResultConfirmed, INTRUDE_COMM_GetLeaveFlag, INTRUDE_COMM_ResetMemberName, INTRUDE_COMM_FillMemberName, INTRUDE_COMM_SetMemberEntry, INTRUDE_COMM_GetMemberNameNetId, INTRUDE_COMM_IsJoinRequestValid, INTRUDE_COMM_ReceiveJoinRequest, INTRUDE_COMM_SendProposalReplies, INTRUDE_COMM_SendPendingReplies, INTRUDE_COMM_StoreJoinReply, INTRUDE_COMM_TakeJoinReply, INTRUDE_COMM_ClearJoinReply, INTRUDE_COMM_IsRequestFromNetId, INTRUDE_COMM_GetRequesterNetId, INTRUDE_COMM_IsRequestFromSelf, INTRUDE_COMM_SetWordSetPlayerName, INTRUDE_COMM_SetWordSetMemberName, INTRUDE_COMM_SetWordSetRequest, INTRUDE_COMM_ResetOutcomes, INTRUDE_COMM_PickEntryForKind, INTRUDE_COMM_TallyOutcomesAndResetIfComplete, INTRUDE_COMM_PartyProcInit, INTRUDE_COMM_PartyProcMain, INTRUDE_LINK_ProcExit, INTRUDE_LINK_CreateEvent, INTRUDE_LINK_EventMain, INTRUDE_COMM_GetPartnerSlot, INTRUDE_COMM_GetMarkerPosForPartner, INTRUDE_COMM_RequestPartnerSymbolPage, INTRUDE_COMM_IsPartnerSymbolPageReceived, INTRUDE_COMM_GetPartnerSymbolPage, INTRUDE_COMM_SetPendingAreaNotice, INTRUDE_COMM_ConsumeAreaNoticeSeen
 * address:  0x02172BC0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   INTRUDE_COMM_HasUnlockFlags  0x02158590  thumb  ov010
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   str_02177000   0x02177000  data  ov011  a1
 *   COMM_PLAYER_Create  0x02167518  thumb  ov010
 *   EVENT_FIELD_PROCLINK_InitReturnSlotsWithAid  0x02161F54  thumb  ov010
 *   STRBUF_Create  0x020457B0  arm
 *   GAME_DATA_SetOwnNetId  0x02012B64  thumb
 *   GAME_DATA_SetIntrudeId  0x02012B8C  thumb
 *   GAME_DATA_SetEnterMode  0x02012B4C  thumb
 *   GAME_DATA_GetMyStatusPlayer  0x02012950  thumb
 *   MYSTATUS_Copy  0x02008494  thumb
 *   GAME_DATA_IsSaving  0x02012E40  thumb
 *   GFL_NET_StartSession  0x0203CBAC  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_NET_StartChangeoverParent  0x0203D10C  arm
 *   GFL_NET_ConnectMacAddressParent  0x0203CFF0  arm
 *   d_02177000     0x02177000  data  ov011
 *   d_021768C8     0x021768C8  data  a4
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   EVENT_FIELD_PROCLINK_RunReturnSlotsIfOffline  0x02161F74  thumb  ov010
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   DWCi_IsFold  0x02035390  arm
 *   UI_IsPowerConnected  0x020353B0  arm
 *   GFL_NET_SYSTEM_GetConnectNum  0x020392B8  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   GFL_NET_HANDLE_CheckNegotiation  0x02039ACC  arm
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_IsNegotiationDone  0x020399B8  arm
 *   GF_STANDARD_GetSecondsOfDay  0x0203F4FC  arm
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   GAMESYSTEM_IsFieldMapActive  0x02012114  thumb
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   GFL_NET_ERR_ResetState  0x0200FBA0  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   ZONEDATA_IsEntralink  0x02013D5C  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_IsReady  0x02188BE8  thumb  ov021
 *   EVENT_FIELD_PROCLINK_ClearReturnSlots  0x02161F68  thumb  ov010
 *   GAME_DATA_ClearUnionInfo  0x0201281C  thumb
 *   COMM_PLAYER_Delete  0x0216754C  thumb  ov010
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   GAME_COMM_SetCounter  0x02026480  thumb
 *   GAMESYSTEM_SetFieldMapState  0x02012124  thumb
 *   GAME_COMM_ClearInfoMessages  0x02026680  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   WIH_IsMatchingParent  0x0217873C  thumb  ov014
 *   NET_WHPIPE_CheckBeaconFlags  0x02177494  thumb  ov014
 *   NET_WHPIPE_GetEntryBeacon  0x02177BFC  thumb  ov014
 *   INTRUDE_COMM_IsListedId  0x02158570  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetPlayerName  0x02165C34  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetSex  0x02165D08  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetLanguage  0x02165C50  thumb  ov010
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   INTRUDE_FIELD_IsListedZone  0x0217C11C  thumb  ov018
 *   COMM_PLAYER_ClearPending  0x02167794  thumb  ov010
 *   COMM_PLAYER_Resume  0x021676E4  thumb  ov010
 *   COMM_PLAYER_CheckOccupy  0x021677E4  thumb  ov010
 *   COMM_PLAYER_SetPackage  0x02167848  thumb  ov010
 *   COMM_PLAYER_Suspend 0x02167688 thumb ov010
 *   WIH_SetBeaconFoundCallback  0x0217963C  thumb  ov014
 *   GFL_NET_SYSTEM_CheckError  0x02039414  arm
 *   NET_WHPIPE_PublishBeacon  0x0217778C  thumb  ov014
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   GFL_NET_IsSendQueueEntryOfHandle  0x0203D578  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   COMM_PLAYER_Del 0x02167658 thumb ov010
 *   GAME_COMM_UpdatePlayerStatus  0x020264B4  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   INTRUDE_GetFromSave  0x0200BE48  thumb
 *   GFL_NET_SendDataMask  0x0203D4D0  arm
 *   GAME_DATA_GetBattleRecSlot  0x020127AC  thumb
 *   GFL_NET_SetAcceptConnection  0x0203D1E8  arm
 *   NET_WHPIPE_SetBeaconStatus  0x021780FC  thumb ov014
 *   GFL_NET_IsConnectMember  0x0203D1C0  arm
 *   GF_STANDARD_CompareBytes 0x0203EFC8 arm
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   GAME_DATA_GetPmsWork  0x02012F20  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   FIELD_STATUS_GetSeasonDispFlag  0x02014484  thumb
 *   COMM_PLAYER_SUPPORT_GetMode  0x0202E7E0  thumb
 *   COMM_PLAYER_SUPPORT_SetModeAndCurrent  0x0202E7C4  thumb
 *   GAME_COMM_PushPairMessage 0x020266AC thumb
 *   GAME_DATA_GetUnionInfo  0x020127D0  thumb
 *   GAME_DATA_GetMyStatusByNetId  0x021583EC  thumb ov010
 *   FIELD_WFBC_DATA_LOCAL_Sanitize  0x021861F4  thumb ov020
 *   GAME_DATA_TakeUnionInfo  0x02012800  thumb
 *   EVENT_FIELD_PROCLINK_SetReturnSlotDefaultIfOffline  0x02161FF0  thumb ov010
 *   EVENT_FIELD_PROCLINK_SetReturnSlotIfOffline  0x02162008  thumb ov010
 *   ZONEDATA_IsZoneGroup118To120  0x02013D9C  thumb
 *   INTRUDE_AddLogEntry  0x0200BE84  thumb
 *   EVENT_FIELD_PROCLINK_GetReturnResultSlot 0x02162024 thumb ov010
 *   EVENT_FIELD_PROCLINK_ClearReturnResultSlot 0x02162038 thumb ov010
 *   EVENT_FIELD_PROCLINK_GetReturnPendingSlot 0x0216202C thumb ov010
 *   EVENT_FIELD_PROCLINK_ClearReturnPendingSlotThunk 0x02162040 thumb ov010
 *   SYMBOL_SAVE_GetBlock  0x0200E0B0  thumb
 *   SYMBOL_MAP_GetEntryPage  0x0216749C  thumb ov010
 *   SYMBOL_MAP_GetSymbolIndex  0x021673C4  thumb ov010
 *   SYMBOL_MAP_GetGroup  0x021673A8  thumb ov010
 *   MYSTATUS_GetSize  0x02008468  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   GAME_DATA_SetSlotFlag  0x02012BA4  thumb
 *   GAME_COMM_PushPlayerMessage  0x020266D4  thumb
 *   ZONEDATA_IsSameMatrixGroup  0x02013E90  thumb
 *   COMM_PLAYER_GetObjCode  0x02167810  thumb  ov010
 *   COMM_PLAYER_Add  0x021675D0  thumb  ov010
 *   gIntrudeCommZonePairs  0x02176AA0  data ov011 a2
 *   COMM_PLAYER_UpdateMyPackage  0x0216786C  thumb ov010
 *   GAME_DATA_GetSymbolMapFlag  0x02012FB0  thumb
 *   GAMESYSTEM_IsEventActive  0x020120D8  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   gIntrudeCommObjCodesMale   0x02176A90  data  ov011  a2
 *   gIntrudeCommObjCodesFemale   0x02176A98  data  ov011  a2
 *   INTRUDE_GetMissionClearCount  0x0200BF70  thumb
 *   GAME_DATA_GetPlayTime  0x02012FCC  thumb
 *   INTRUDE_UpdatePlaySeconds  0x0200BFA4  thumb
 *   INTRUDE_GetPlaySeconds  0x0200BF94  thumb
 *   INTRUDE_GetObtainedFlags  0x0200BF54  thumb
 *   gIntrudeCommValidObjCodes 0x02176B08 data ov011 a2
 *   gIntrudeCommValidProfileCodes 0x02176AD0 data ov011 a2
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   EVENT_FIELD_PROCLINK_SetReturnLinkId  0x02161FEC  thumb  ov010
 *   INTRUDE_COMM_NormalizeVersion  0x021584F4  thumb  ov010
 *   MYSTATUS_CopyNameChars 0x020084F8 thumb
 *   GAME_DATA_GetBattleRecSlotByNetId  0x021583CC  thumb  ov010
 *   MYSTATUS_GetRomCode  0x0200855C  thumb
 *   memset 0x02082BCC arm
 *   STRBUF_SetStringN  0x02045994  arm
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_SetSlotFromMsg36  0x0201EF40  thumb
 *   WORDSET_SetSlotFromMsgA0  0x0201F184  thumb
 *   gIntrudePickTable     0x02176C4C  data  ov011  a1
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   PROCSYS_Create  0x02031324  arm
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKE_TOOL_HealParty  0x0201BA34  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_Create  0x0201A920  thumb
 *   POKEPARTY_IsMemberBattleReady  0x0201AB34  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   POKE_TOOL_SetLevelAndRecalc  0x02019CA0  thumb
 *   GF_PANIC_Fail  0x02034714  arm
 *   d_02177010     0x02177010  data  ov011  a1
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   PROCSYS_Main  0x02031330  arm
 *   BTL_SETUP_SetupCommSingle  0x02013790  thumb
 *   BTL_SETUP_SetParty  0x02013128  thumb
 *   GFL_NET_HANDLE_SetUserInfo  0x0203A424  arm
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm
 *   PROCSYS_Push  0x02031348  arm
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   BTL_SETUP_FreeSlots  0x020130DC  thumb
 *   ov093_id       0x0000005D  data  a1
 *   d_021F03C4     0x021F03C4  data  ov093  a4
 *   d_021EFDAC     0x021EFDAC  data  ov093  a4
 *   PROCSYS_Delete 0x0203133C arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask  0x02029BCC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_Start  0x021CF498  thumb  ov021
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAME_EVENT_CallProc  0x02012444  thumb
 *   FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask  0x02029C00  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   sIntrudeLinkProcTable     0x02176FCC  data  ov011  a4
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   GAME_DATA_GetIntrudeId  0x02012B80  thumb
 *   sLinkMarkerPosTemplate     0x02176FD8  data  ov011  a4
 */
#include "../types.h"

#include "../version.h"
#include "../arm9/game_beacon_types.h"
#include "../arm9/net_types.h"
#include "intrude_comm_types.h"

struct GameData;
struct GameComm;
struct GameSystem;
struct CommPlayerWork;
struct STRBUF;
struct FieldMap;
struct MyPlayerWork;
struct MyStatus;
struct MyStatus;
struct FieldStatus;
struct Proc;
struct SaveData;
struct Strbuf;
struct WordSet;
struct Party;
struct PartyMon;

/* Parameter of the session procs: filled by the caller, read by every step. */
typedef struct IntrudeCommParam {
    void *gameSystem;       /* 0x00: GameSystem * */
    void *gameComm;         /* 0x04: GameComm * */
    u8    parentMac[6];     /* 0x08: MAC address of the parent to join */
    u8    isParent;         /* 0x0E: 1 = open the session, else join parentMac */
} IntrudeCommParam;

/* Record the wireless scan returns for one nearby player. */
typedef struct IntrudeScanRecord {
    u8 header[3];
    u8 inUse : 1;
    u8 excluded : 1;        /* skipped by the scan callback */
    u8 flags : 6;
    u32 trainerId;
    GameBeaconInfo info;
} IntrudeScanRecord;

/* Two zones that are one place in two worlds. */
typedef struct IntrudeZonePair {
    u16 zoneA;
    u16 zoneB;
    u16 spare;
} IntrudeZonePair;

/* Where a zone stands in the zone pair table. */
typedef struct IntrudeZonePairInfo {
    u16 zoneId;
    u8 side;        /* 0 zoneA, 1 zoneB */
    u8 pairIndex;   /* 0xFF when the zone is in no pair */
} IntrudeZonePairInfo;

/* Row of the entry table (0xE0 rows). */
typedef struct IntrudePickRow {
    u8 kind;
    u8 minPoints;
    u8 level;
    u8 flags;
} IntrudePickRow;

/* Parameter of the party proc. */
typedef struct IntrudePartyParam {
    struct GameSystem *gameSystem;
    u8 partnerNetId;
    u8 level;
    u8 maxCount;
} IntrudePartyParam;

/* Work of the party proc (0x100 bytes allocated). */
typedef struct IntrudePartyWork {
    u8 pad00[0xc];
    int memberLimit;            /* 0x0C */
    u8 pad10[0x8];
    u16 beaconSize;             /* 0x18 */
    u8 pad1A[0x7];
    u8 isParent;                /* 0x21 */
    u8 pad22[0x76 - 0x22];
    u16 timeoutFrames;          /* 0x76 */
    u8 pad78[0x84 - 0x78];
    u16 memberMask;             /* 0x84 */
    u8 pad86[0xF4 - 0x86];
    struct ProcSys *asyncTask;         /* 0xF4 */
    struct Party *party;        /* 0xF8 */
    int overlayLoaded;          /* 0xFC */
} IntrudePartyWork;

/* Reply to a join request (command 0x211), 0x38 bytes. */
typedef struct IntrudeJoinReply {
    u8 kind;                    /* 1 = accepted, the record follows */
    u8 pad01[3];
    IntrudeMemberRecord record;
} IntrudeJoinReply;

typedef VecFx32 LinkMarkerPos;

typedef struct { u8 value; u8 enabled; } LinkValueMessage;

#include "../sdk_fx.h"
#include "../arm9/game_comm.h"
#include "../ov010/intrude_comm_query.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../ov010/comm_player.h"
struct EventSlots;
#include "../ov010/event_field_proclink_return.h"
#include "../arm9/strbuf.h"
#ifdef __MWERKS__
extern void GAME_DATA_SetOwnNetId(struct GameData *gd, u32 value); /* original prototype; the definition differs in argument width */
#else
extern void GAME_DATA_SetOwnNetId(struct GameData*, u8);
#endif
extern void GAME_DATA_SetIntrudeId(struct GameData *gameData, u32 intrudeId);
extern void GAME_DATA_SetEnterMode(struct GameData *gameData, u8 enterMode);
extern struct MyStatus *GAME_DATA_GetMyStatusPlayer(struct GameData *gameData, u32 index);
#include "../arm9/mystatus.h"
extern u8 GAME_DATA_IsSaving(struct GameData *gd);
extern void GFL_NET_StartSession(GFLNetInitializeStruct *init, GFLNetUserFunc callback, void *work);
extern void GFL_NET_StartChangeoverParent(GFLNetUserFunc changeoverParam);
extern void GFL_NET_ConnectMacAddressParent(void *macAddress);
struct UnionInfo;
extern struct UnionInfo *GAME_DATA_GetSecondUnionInfo(struct GameData *gameData);
struct ProcLinkSys;
#include "../arm9/net_err.h"
#include "../arm9/ui.h"
#include "../arm9/net_system.h"
extern void GFL_NET_SetLoginOption(u8 loginOption);
#include "../arm9/net_handle.h"
extern u8 GAME_DATA_GetSeason(const struct GameData *gameData);
#include "../arm9/gf_standard.h"
extern int GAME_DATA_GetIntrudeCount(const struct GameData *gameData);
#include "../arm9/gamesystem.h"
extern u32 GFL_NET_IsParentAid(void);
extern int   GFL_NET_GetNegotiationNum(void);
extern int GFL_NET_IsSessionNull(void);
struct PlayerWork;
extern u16 GAME_DATA_GetPlayerZoneId(struct PlayerWork *player);
#include "../arm9/zonedata.h"
#include "../ov021/fieldmap.h"
extern void GAME_DATA_ClearUnionInfo(struct GameData *gameData);
extern u8 GAME_DATA_GetOwnNetId(const struct GameData *gameData);
#include "../ov014/wih.h"
struct WhPipeEntry;
#include "../ov014/net_whpipe.h"
struct GameBeaconInfo;
#include "../ov010/game_beacon_accessor.h"
#include "../ov018/intrude_field.h"
struct CommPlayerPackage;
extern int GFL_NET_SendToHandle(GFLNetHandle *handle, u32 command, u32 size, const void *data);
struct GFLNetHandle;
extern u8 GFL_NET_GetHandleNetID(GFLNetHandle *handle);
#include "../arm9/mi_memory.h"
struct SaveControl;
struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gd);
struct IntrudeSave;
#include "../arm9/intrude.h"
u32 GFL_NET_SendDataMask(GFLNetHandle *handle, u32 sendMask, u32 command, u32 size, const void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode);
void GFL_NET_SetAcceptConnection(void *unusedArg, void *eventArg);
u32 GFL_NET_IsConnectMember(u32 netId);
extern void *GAME_DATA_GetLastBattleRecSlot(struct GameData *gameData);
void *GAME_DATA_GetMoveModelSys(const struct GameData *p);
#include "../arm9/field_status.h"
struct CommPlayerSupport;
struct CommPlayerSupport *GAME_DATA_GetPmsWork(struct GameData *gameData);
#include "../arm9/comm_player_support.h"
u8 *GAME_DATA_GetUnionInfo(struct GameData *gameData, u32 index);
struct WfbcData;
#include "../ov020/field_wfbc_data_local.h"
void GAME_DATA_TakeUnionInfo(struct GameData *gameData, void *dst);
struct EventSlot;
struct PlayerWork *GAME_DATA_GetMyPlayerWork(struct GameData *p);
struct IntrudeLogEntry;
#include "../arm9/symbol_save.h"
struct Entry32;
struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gd);
#include "../arm9/config.h"
void *GAME_DATA_GetBattleRecSlot(struct GameData *p, unsigned int idx);
void GAME_DATA_SetSlotFlag(struct GameData *p, int i, u8 v);
#ifdef __MWERKS__
u8 GAME_DATA_GetSymbolMapFlag(struct GameData *gameData); /* original prototype; the definition differs in return type */
#else
extern s32 GAME_DATA_GetSymbolMapFlag(struct GameData*);
#endif
struct PlayTime;
extern struct PlayTime *GAME_DATA_GetPlayTime(struct GameData *gd);
struct BattleRecSlot;
extern void *memset(void *p, int value, unsigned int size);
#include "../arm9/wordset.h"
#include "../arm9/gfl_use.h"
#include "../arm9/procsys.h"
#ifdef __MWERKS__
extern u32 GFL_NET_SendData(struct GFLNetHandle *handle, u8 sendId, u32 command, u32 size, void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode); /* original prototype; the definition differs in argument width */
#else
extern u32 GFL_NET_SendData(struct GFLNetHandle*, u32, u32, u32, void*, u32, u32, u32);
#endif
extern int GFL_NET_Exit(GFLNetUserFunc exitCallback);
extern int GFL_NET_IsSendQueueEntryOfHandle(GFLNetHandle *handle, u32 command);
extern void *GAME_DATA_GetMyParty(struct GameData *gd);
#include "../arm9/poke_tool_ext.h"
#include "../arm9/pokeparty.h"
struct PokemonParam;
#include "../arm9/poke_tool.h"
#include "../arm9/gf_panic.h"
struct BattleSetupParam;
#include "../arm9/btl_setup.h"
#include "../arm9/gf_overlay.h"
#include "../arm9/net_command.h"
extern int GFL_NET_GetRunState(void);
#include "../arm9/field_sound_system.h"
struct EncEffWork;
struct EncEffWork;
#include "../ov021/enceff.h"
#include "../arm9/game_event.h"
#include "../ov021/event_fieldmap_control.h"
struct IntrudeCommSys;
extern u8 GAME_DATA_GetIntrudeId(const struct GameData *p);
IntrudeCommSys *INTRUDE_COMM_Create(void *proc, IntrudeCommParam *param);
int INTRUDE_COMM_StartSession(int *state, IntrudeCommParam *param, IntrudeCommSys *work);
void INTRUDE_COMM_MainStep(int *state, IntrudeCommParam *param, IntrudeCommSys *work);
int INTRUDE_COMM_Shutdown(int *state, IntrudeCommParam *param, IntrudeCommSys *work);
int INTRUDE_COMM_Destroy(int unused, void **proc, IntrudeCommSys *work);
void INTRUDE_COMM_ScanCallback(void *whPipe, IntrudeCommSys *work);
void INTRUDE_COMM_SyncPlayers(IntrudeCommSys *work, IntrudeCommSys *peerWork, int fieldObjectAddr);
void INTRUDE_COMM_SuspendPlayers(int arg, IntrudeCommSys *work);
void INTRUDE_COMM_OnSessionStarted(void *userArg);
void INTRUDE_COMM_OnSessionExit(void *userArg);
IntrudeBeacon *INTRUDE_COMM_GetBeacon(IntrudeCommSys *work);
void INTRUDE_COMM_InitBeacon(struct GameData *gameData, IntrudeBeacon *beacon, int maxConnect);
int INTRUDE_COMM_RefreshBeacon(struct GameData *gameData, IntrudeBeacon *beacon);
int INTRUDE_COMM_IsEqual(int left, int right);
void INTRUDE_COMM_RecvQuit(int netId, int size, IntrudeCommSys *work);
void INTRUDE_COMM_Nop(void);
void INTRUDE_COMM_AgeFoundList(IntrudeCommSys *work);
u8 *INTRUDE_COMM_GetStatusArea(int unused, IntrudeCommSys *work);
IntrudeMemberRecord *INTRUDE_COMM_GetMemberRecord(int index, IntrudeCommSys *work);
IntrudeStatusRecord *INTRUDE_COMM_GetStatusRecord(int index, IntrudeCommSys *work);
u8 *INTRUDE_COMM_GetWorkArea(int unused, IntrudeCommSys *work);
int INTRUDE_COMM_IsLinked(void);
void INTRUDE_COMM_RecvShutdownRequest(int netId, int size, int data, IntrudeCommSys *work, unsigned int handle);
int INTRUDE_COMM_SendShutdownRequest(IntrudeCommSys *work);
void INTRUDE_COMM_RecvMemberCount(unsigned int netId, int size, u8 *data, IntrudeCommSys *work);
int INTRUDE_COMM_SendMemberCount(IntrudeCommSys *work, int memberCount, ...);
void INTRUDE_COMM_RecvRecordRequest(int netId, int size, int data, IntrudeCommSys *work);
int INTRUDE_COMM_SendRecordRequest(void);
void INTRUDE_COMM_RecvStatusRecord(int netId, int size, IntrudeStatusRecord *record, IntrudeCommSys *work);
int INTRUDE_COMM_SendStatusRecord(IntrudeCommSys *work);
void INTRUDE_COMM_RecvPeerLeft(int senderNetId, int size, int *data, IntrudeCommSys *work, void *handle);
int INTRUDE_COMM_SendPeerLeft(IntrudeCommSys *work, int leavingNetId);
void INTRUDE_COMM_RecvPeerStatus(int netId, int size, const IntrudePeer *peer, IntrudeCommSys *work);
int INTRUDE_COMM_SendPeerStatus(IntrudeCommSys *work, const IntrudePeer *peer);
void INTRUDE_COMM_RecvTimeoutWarning(int netId, int size, int data, IntrudeCommSys *work);
int INTRUDE_COMM_SendTimeoutWarning(void);
void INTRUDE_COMM_RecvRequest(int netId, int size, IntrudeRequestMessage *request, IntrudeCommSys *work);
int INTRUDE_COMM_SendRequest(IntrudeCommSys *work, int destNetId, IntrudeMemberRecord *data, int type);
void INTRUDE_COMM_RecvReply(int netId, int size, u8 *reply, IntrudeCommSys *work);
int INTRUDE_COMM_SendReply(void *unused, int destNetId, int answer, int seq);
void INTRUDE_COMM_RecvNotice(int netId, int size, u8 *notice, IntrudeCommSys *work);
int INTRUDE_COMM_SendNotice(IntrudeCommSys *work, int destNetId, int value);
void INTRUDE_COMM_RecvAnswer(int netId, int size, u8 *data, IntrudeCommSys *work);
int INTRUDE_COMM_SendAnswer(int destNetId, int value);
void INTRUDE_COMM_RecvNoticeBytes(int netId, int size, const u8 *data, IntrudeCommSys *work);
int INTRUDE_COMM_SendNoticeBytes(int destNetId, int value);
void INTRUDE_COMM_RecvReady(int netId, int size, int data, IntrudeCommSys *work);
int INTRUDE_COMM_SendReady(struct IntrudeCommSys *unused, u8 destNetId);
void INTRUDE_COMM_RecvRemoteRecord(int netId, int size, IntrudeRemoteRecord *record, IntrudeCommSys *work);
int INTRUDE_CMD_SendSaveSummary(IntrudeCommSys *w, int sendMask);
void INTRUDE_CMD_RecvEntryIndex(u32 netId, int size, int *entryIndex, IntrudeCommSys *w);
int INTRUDE_CMD_SendEntryIndex(struct IntrudeCommSys *unused, int entryIndex);
void INTRUDE_CMD_RecvMemberEntry(int netId, int size, IntrudeMemberEntry *entry, IntrudeCommSys *w);
int INTRUDE_CMD_SendMemberEntry(void *unused, IntrudeSession *session, int memberIndex);
void INTRUDE_CMD_RecvJoinRequest(int netId, int size, IntrudeJoinRequest *request, IntrudeCommSys *w);
int INTRUDE_CMD_SendJoinRequest(IntrudeCommSys *w, void *request);
void INTRUDE_CMD_RecvJoinReply(int netId, int size, void *reply, IntrudeCommSys *w);
int INTRUDE_CMD_SendJoinReply(void *unused, void *reply, int netId);
void INTRUDE_CMD_RecvGroupRecord(int netId, int size, IntrudeMemberRecord *record, IntrudeCommSys *w);
int INTRUDE_CMD_SendGroupRecord(IntrudeCommSys *w, IntrudeSession *session);
void INTRUDE_CMD_RecvRecordEcho(int netId, int size, void *record, IntrudeCommSys *w);
int INTRUDE_CMD_SendRecordEcho(void *unused, IntrudeSession *session);
void INTRUDE_CMD_RecvRecordAccept(int netId, int size, void *record, IntrudeCommSys *w);
int INTRUDE_CMD_SendRecordAccept(int unused, IntrudeSession *session);
void INTRUDE_CMD_RecvMemberValue(int netId, int size, int *value, IntrudeCommSys *w);
int INTRUDE_CMD_SendMemberValue(void *unused, int value, int sendMask);
void INTRUDE_CMD_RecvProposal(int netId, int size, IntrudeMemberRecord *record, IntrudeCommSys *w);
int INTRUDE_CMD_SendProposal(IntrudeCommSys *w, IntrudeSession *session);
void INTRUDE_CMD_RecvProposalReply(int netId, int size, int *value, IntrudeCommSys *w);
int INTRUDE_CMD_SendProposalReply(int unused, int value, int netId, ...);
void INTRUDE_CMD_RecvResultRecord(int netId, int size, IntrudeResultRecord *record, IntrudeCommSys *w);
int INTRUDE_CMD_SendResultRecord(IntrudeCommSys *w, IntrudeSession *session);
void INTRUDE_CMD_RecvReadyNotice(int netId, int size, int unused, IntrudeCommSys *w);
int INTRUDE_CMD_SendReadyNotice(IntrudeCommSys *w);
void INTRUDE_CMD_RecvStartNotice(int netId, int size, int unused, IntrudeCommSys *w);
int INTRUDE_CMD_SendStartNotice(int sendMask);
void INTRUDE_CMD_RecvEndNotice(int netId, int size, int unused, IntrudeCommSys *w);
u32 INTRUDE_CMD_SendEndNotice(u32 sendMask);
void INTRUDE_CMD_RecvProfile(int netId, int size, void *profile, IntrudeCommSys *w);
int INTRUDE_CMD_SendProfile(IntrudeCommSys *w);
void INTRUDE_CMD_RecvTallyWord(int netId, int size, void *data, IntrudeCommSys *w);
int INTRUDE_COMM_SendTally(IntrudeCommSys *work);
void INTRUDE_COMM_RecvBusyBegin(int netId, int size, void *data, IntrudeCommSys *work);
u32 INTRUDE_COMM_SendBusyBegin(void);
void INTRUDE_COMM_RecvBusyEnd(int netId, int size, void *data, IntrudeCommSys *work);
u32 INTRUDE_COMM_SendBusyEnd(void);
void INTRUDE_COMM_RecvPeerFlags(int netId, int size, u8 *flags, IntrudeCommSys *work);
int INTRUDE_COMM_SendPeerFlags(struct IntrudeCommSys *unused, u8 netId, int flags, ...);
void INTRUDE_COMM_RecvSupportMode(int netId, int size, int *mode, IntrudeCommSys *work);
int INTRUDE_COMM_SendSupportMode(struct IntrudeCommSys *unused, u8 netId, int mode, ...);
void INTRUDE_COMM_RecvProfile(int netId, int size, void *profile, IntrudeCommSys *work);
int INTRUDE_COMM_SendProfile(u8 netId, const void *profile);
void INTRUDE_COMM_RecvPairMessage(int netId, int size, u8 *message, IntrudeCommSys *work);
int INTRUDE_COMM_SendPairMessage(int message, ...);
void INTRUDE_COMM_RecvUnionInfoRequest(int netId, int size, int data, IntrudeCommSys *work);
int INTRUDE_COMM_SendUnionInfoRequest(IntrudeCommSys *work, u8 netId);
void INTRUDE_COMM_RecvUnionInfo(int netId, int size, void *info, IntrudeCommSys *work);
int INTRUDE_COMM_SendUnionInfo(IntrudeCommSys *work, int netMask, void *info);
void INTRUDE_COMM_RecvReturnResult(int netId, int size, int result, IntrudeCommSys *work);
int INTRUDE_COMM_SendReturnResult(void *result, u8 netId);
void INTRUDE_COMM_RecvReturnPending(int netId, int size, int data, IntrudeCommSys *work);
int INTRUDE_COMM_SendReturnPending(const void *pending, u8 netId);
void INTRUDE_COMM_RecvPageRequest(int netId, int size, const IntrudePageRequest *request, IntrudeCommSys *work);
int INTRUDE_COMM_SendPageRequest(IntrudeCommSys *work, u8 netId, const void *request);
void INTRUDE_COMM_RecvSymbolPage(int netId, int size, IntrudeSymbolPage *page, IntrudeCommSys *work);
int INTRUDE_COMM_SendSymbolPage(IntrudeCommSys *work, u8 netId);
void INTRUDE_COMM_RecvAreaNotice(int netId, int size, int data, IntrudeCommSys *work);
u32 INTRUDE_COMM_SendAreaNotice(const void *notice);
void INTRUDE_COMM_UpdateRunning(IntrudeCommSys *work);
void INTRUDE_COMM_UpdateSeasonState(IntrudeCommSys *work);
void INTRUDE_COMM_UpdateMemberJoin(IntrudeCommSys *work);
void INTRUDE_COMM_UpdateMemberLeave(IntrudeCommSys *work);
void INTRUDE_COMM_UpdatePendingNotices(IntrudeCommSys *work);
void INTRUDE_COMM_UpdateUnionInfoAndReturnSlots(IntrudeCommSys *work);
void INTRUDE_COMM_UpdatePageRequests(IntrudeCommSys *work);
void INTRUDE_COMM_BuildSymbolPage(IntrudeCommSys *work, const IntrudePageRequest *request);
void INTRUDE_COMM_SendSaveSummaryToReadyPeers(IntrudeCommSys *work);
void INTRUDE_COMM_SetState(IntrudeCommSys *work, int state);
void INTRUDE_COMM_RefreshSelfRecord(IntrudeCommSys *work);
void INTRUDE_COMM_ApplyPlayerBeacon(IntrudeCommSys *work, int netId, IntrudeStatusRecord *record);
void INTRUDE_COMM_StorePlayerRecord(IntrudeCommSys *work, int netId, const IntrudePeer *src, int arg);
void INTRUDE_COMM_UpdatePlayerObjects(IntrudeCommSys *work);
void INTRUDE_COMM_UpdatePlayerObject(IntrudeCommSys *work, int netId);
int INTRUDE_COMM_LookupZonePair(u16 zoneId, IntrudeZonePairInfo *out);
int INTRUDE_COMM_CompareZonePair(IntrudeZonePairInfo *a, IntrudeZonePairInfo *b);
int INTRUDE_COMM_GetRelativeSlot(IntrudeCommSys *work, int netId);
void INTRUDE_COMM_AdjustRemotePosition(IntrudeCommSys *work, u16 zoneId, int selfX, IntrudePeer *peer);
void INTRUDE_COMM_AdjustAllRemotePositions(IntrudeCommSys *work, int selfX);
int INTRUDE_COMM_UpdateSelfRecord(IntrudeCommSys *work);
void INTRUDE_COMM_ClearNotice(IntrudeCommSys *work);
unsigned char *INTRUDE_COMM_GetNotice(IntrudeCommSys *work);
void INTRUDE_COMM_InitRequest(IntrudeCommSys *work, int target);
void INTRUDE_COMM_NextRequestToken(IntrudeCommSys *work);
int INTRUDE_COMM_TryStartRequest(IntrudeCommSys *work, int netId, u8 seq);
void INTRUDE_COMM_SetRequestOpen(IntrudeCommSys *work);
void INTRUDE_COMM_ClearRequestOpen(IntrudeCommSys *work);
void INTRUDE_COMM_UpdateRequest(IntrudeCommSys *work);
int INTRUDE_COMM_GetActiveRequestTarget(IntrudeCommSys *work, int *target);
void INTRUDE_COMM_SetRequestResult(IntrudeCommSys *work, int netId, int result, int seq);
void INTRUDE_COMM_SetRequestResultAccepted(IntrudeCommSys *work, int netId, int seq);
int INTRUDE_COMM_TakeRequestResult(IntrudeCommSys *work);
void INTRUDE_COMM_ClearRequestResult(IntrudeCommSys *work);
void INTRUDE_COMM_PickDefaultObjCode(u32 myStatus, u16 *objCode, u8 *form, u8 *sex);
u16 INTRUDE_COMM_GetPlayerObjCode(IntrudePeer *peer, u32 myStatus);
int INTRUDE_COMM_HasConnectedPeers(void);
void INTRUDE_COMM_BuildLocalProfile(void *saveData, IntrudeProfileData *profile);
u8 INTRUDE_COMM_GetPartnerTallyValid(IntrudeCommSys *work);
int INTRUDE_COMM_IsValidObjCode(int objCode);
int INTRUDE_COMM_IsValidProfileCode(u32 code);
void INTRUDE_COMM_SetLock(IntrudeCommSys *work, u32 value);
void INTRUDE_COMM_SetIntrudeId(IntrudeCommSys *work, u32 intrudeId);
void INTRUDE_COMM_SetSuspended(IntrudeCommSys *work, u32 value);
void INTRUDE_COMM_InitSession(IntrudeSession *session);
void INTRUDE_COMM_ClearSessionEntries(IntrudeSession *session);
void INTRUDE_COMM_UpdateSession(IntrudeCommSys *work, IntrudeSession *session);
int INTRUDE_COMM_GetSessionElapsed(IntrudeSession *session);
int INTRUDE_COMM_GetSessionWaitRemaining(IntrudeSession *session);
int INTRUDE_COMM_GetSessionRemaining(IntrudeSession *session);
void INTRUDE_COMM_SetSessionEntrySendFlag(IntrudeSession *session, int index);
void INTRUDE_COMM_SetSessionRequestSendFlag(IntrudeSession *session);
void INTRUDE_COMM_SetSessionResultSendFlag(IntrudeSession *session);
void INTRUDE_COMM_StoreSessionEntry(IntrudeSession *session, const u16 *src, int index);
int INTRUDE_COMM_StoreSessionRequest(void *unused, IntrudeSession *session, IntrudeMemberRecord *src);
void INTRUDE_COMM_ClearSessionTicks(IntrudeSession *session);
void INTRUDE_COMM_AddSessionMember(IntrudeSession *session, u8 netId);
void INTRUDE_COMM_StartSessionTimer(IntrudeSession *session, int seconds);
int INTRUDE_COMM_IsSessionTimeLimitSet(IntrudeSession *session);
void INTRUDE_COMM_UpdateSessionSends(IntrudeCommSys *work, IntrudeSession *session);
void INTRUDE_COMM_UpdateSessionJoinNotices(IntrudeCommSys *work, IntrudeSession *session);
int INTRUDE_COMM_IsSessionActive(IntrudeSession *session);
IntrudeMemberRecord *INTRUDE_COMM_GetActiveSessionRequest(IntrudeSession *session);
void INTRUDE_COMM_AcceptSession(IntrudeCommSys *work, IntrudeSession *session);
int INTRUDE_COMM_IsSessionAccepted(IntrudeSession *session);
void INTRUDE_COMM_SetSessionFinished(IntrudeSession *session);
int INTRUDE_COMM_IsSessionFinished(IntrudeSession *session);
IntrudeResultRecord *INTRUDE_COMM_GetSessionResult(IntrudeSession *session);
int INTRUDE_COMM_IsSessionAcceptedOrResultReady(IntrudeSession *session);
void INTRUDE_COMM_SetSessionReadyBit(IntrudeSession *session, u32 netId);
int INTRUDE_COMM_TakeNoticeState(IntrudeSession *session);
void INTRUDE_COMM_SetNoticeState(IntrudeSession *session, int noticeState);
int INTRUDE_COMM_FindFreeResultSlot(IntrudeSession *session, IntrudeMemberRecord *record, int netId);
int INTRUDE_COMM_StoreResultRecord(IntrudeSession *session, IntrudeMemberRecord *record, int netId);
int INTRUDE_COMM_GetJoinStatus(IntrudeCommSys *w, IntrudeSession *session);
void INTRUDE_COMM_ClearJoinStatus(IntrudeSession *session);
void INTRUDE_COMM_SetJoinStatus(IntrudeSession *session, int status);
void INTRUDE_COMM_PromoteRequestToResult(void *unused, IntrudeSession *session, u8 ownNetId);
void INTRUDE_COMM_SetResultRecord(void *unused, IntrudeSession *session, IntrudeResultRecord *result);
int INTRUDE_COMM_HasResult(IntrudeSession *session);
int INTRUDE_COMM_GetRequestKind(IntrudeSession *session);
int INTRUDE_COMM_GetResultCount(IntrudeCommSys *w, IntrudeSession *session);
void INTRUDE_COMM_RecordResultOutcome(void *saveData, IntrudeCommSys *w, IntrudeResultRecord *result);
int INTRUDE_COMM_HasResultReward(IntrudeCommSys *w, IntrudeSession *session);
int INTRUDE_COMM_IsResultConfirmed(IntrudeSession *session);
int INTRUDE_COMM_GetLeaveFlag(IntrudeSession *session);
void INTRUDE_COMM_ResetMemberName(IntrudeMemberName *name);
void INTRUDE_COMM_FillMemberName(IntrudeCommSys *w, IntrudeMemberName *name, u8 netId);
void INTRUDE_COMM_SetMemberEntry(IntrudeCommSys *w, IntrudeSession *session, u32 senderNetId, int memberIndex);
int INTRUDE_COMM_GetMemberNameNetId(IntrudeMemberName *name);
int INTRUDE_COMM_IsJoinRequestValid(IntrudeSession *session, IntrudeJoinRequest *request);
int INTRUDE_COMM_ReceiveJoinRequest(IntrudeCommSys *w, IntrudeSession *session, IntrudeJoinRequest *request, int senderNetId);
void INTRUDE_COMM_SendProposalReplies(IntrudeCommSys *w, IntrudeSession *session);
void INTRUDE_COMM_SendPendingReplies(IntrudeCommSys *w, IntrudeSession *session);
void INTRUDE_COMM_StoreJoinReply(IntrudeSession *session, IntrudeJoinReply *reply);
u8 INTRUDE_COMM_TakeJoinReply(IntrudeSession *session);
void INTRUDE_COMM_ClearJoinReply(IntrudeSession *session);
int INTRUDE_COMM_IsRequestFromNetId(IntrudeSession *session, int netId);
u8 INTRUDE_COMM_GetRequesterNetId(IntrudeCommSys *w, IntrudeSession *session);
int INTRUDE_COMM_IsRequestFromSelf(IntrudeCommSys *w);
void INTRUDE_COMM_SetWordSetPlayerName(struct WordSet *wordSet, u32 slot, const IntrudeNameChars *chars, u32 size, u16 heapId, u32 gender);
void INTRUDE_COMM_SetWordSetMemberName(struct WordSet *wordSet, u32 slot, IntrudeMemberName *name, u16 heapId);
void INTRUDE_COMM_SetWordSetRequest(const IntrudeRequestHead *head, IntrudeMemberName *name, struct WordSet *wordSet, u16 heapId);
void INTRUDE_COMM_ResetOutcomes(IntrudeSaveSlot *save);
void INTRUDE_COMM_PickEntryForKind(IntrudeSaveSlot *save, u32 kind);
int INTRUDE_COMM_TallyOutcomesAndResetIfComplete(IntrudeSaveSlot *save, u8 *doneAsFirst, u8 *doneAsSecond);
int INTRUDE_COMM_PartyProcInit(struct Proc *proc, int unused, IntrudePartyParam *param);
int INTRUDE_COMM_PartyProcMain(void *proc, int *state, IntrudePartyParam *param, IntrudePartyWork *work);
int INTRUDE_LINK_ProcExit(void *procWork, int unused1, int unused2, IntrudeLinkProc *linkProc);
struct GameEvent *INTRUDE_LINK_CreateEvent(struct GameSystem *gameSystem, void *procArg);
int INTRUDE_LINK_EventMain(struct GameEvent *event, u32 *state, IntrudeLinkEventWork *eventWork);
u8 INTRUDE_COMM_GetPartnerSlot(void *comm, void *gameData);
void INTRUDE_COMM_GetMarkerPosForPartner(struct GameComm *comm, struct GameData *gameData, LinkMarkerPos *outPos);
int INTRUDE_COMM_RequestPartnerSymbolPage(IntrudeCommSys *linkState, u8 value);
u32 INTRUDE_COMM_IsPartnerSymbolPageReceived(IntrudeCommSys *linkState);
u8 *INTRUDE_COMM_GetPartnerSymbolPage(IntrudeCommSys *linkState);
void INTRUDE_COMM_SetPendingAreaNotice(IntrudeCommSys *linkState, u8 value);
extern char  str_02177000[];
extern char d_02177000[];
extern const GFLNetInitializeStruct d_021768C8;
extern IntrudeZonePair gIntrudeCommZonePairs[8];
extern u16 gIntrudeCommObjCodesMale[];
extern u16 gIntrudeCommObjCodesFemale[];
extern const u16 gIntrudeCommValidObjCodes[];
extern u16 gIntrudeCommValidProfileCodes[];
extern IntrudePickRow gIntrudePickTable[];
extern u8 d_02177010[];
extern NetCommandEntry d_021F03C4[];
extern u8 ov093_id[];
extern char d_021EFDAC[];
extern char sIntrudeLinkProcTable[];
extern LinkMarkerPos sLinkMarkerPosTemplate;

IntrudeCommSys *INTRUDE_COMM_Create(void *proc, IntrudeCommParam *param)
{
    struct GameData *gameData;
    u8 *myStatus;
    u32 maxConnect;
    IntrudeCommSys *work;
    int i;
    u8 netId;

    gameData = GAME_COMM_GetGameData(param->gameComm);
    myStatus = (u8 *)GAME_DATA_GetMyStatus(gameData);
    maxConnect = 3;
    if (param->isParent == 1 && INTRUDE_COMM_HasUnlockFlags(gameData) == 0) {
        maxConnect = 2;
    }
    work = GFL_HEAP_Alloc(5, sizeof(IntrudeCommSys), 1, str_02177000, 0x9a);
    work->gameSystem = param->gameSystem;
    work->gameComm = param->gameComm;
    work->step = 1;
    work->commPlayer = COMM_PLAYER_Create(3, param->gameSystem, 5, 0);
    work->memberCount = 1;
    work->lastAreaIndex = 1;
    INTRUDE_COMM_InitRequest(work, 4);
    INTRUDE_COMM_InitSession(&work->session);
    INTRUDE_COMM_InitBeacon(gameData, &work->beacon, maxConnect);
    EVENT_FIELD_PROCLINK_InitReturnSlotsWithAid((struct EventSlots *)work->returnSlots);
    for (i = 0; i < 2; i++) {
        work->foundNames[i] = (struct STRBUF *)STRBUF_Create(8, 5);
    }
    GAME_DATA_SetOwnNetId(gameData, 0);
    GAME_DATA_SetIntrudeId(gameData, 0);
    GAME_DATA_SetEnterMode(gameData, 1);
    for (netId = 0; netId < 3; netId++) {
        MYSTATUS_Copy((struct MyStatus *)myStatus, GAME_DATA_GetMyStatusPlayer(gameData, netId));
    }
    return work;
}

/*
 * recoup 2026-10-05: the old draft (196 B, work as u8* with work[0x8fd]) failed on register
 * colours and a second pool load of 0x8fd. Typed parameters closed it to 192 B, all bytes equal:
 * param as a struct with the byte at 0x0E, work as a struct with the step byte at 0x8FD (written
 * work->step = 3 / 4 in each arm, no local), callee types from matched twins (GAME_COMM_GetGameData and
 * GFL_HEAP_Alloc return u32, GAME_DATA_IsSaving takes const u8 *). The only open item is the pool
 * word INTRUDE_COMM_OnSessionStarted: the leaf is filed at src/matched/ov/INTRUDE_COMM_OnSessionStarted.c (EXACT);
 * the integrator needs a shard for it, then this file is EXACT.
 */
int INTRUDE_COMM_StartSession(int *state, IntrudeCommParam *param, IntrudeCommSys *work)
{
    u8 *gameData;
    GFLNetInitializeStruct *init;

    gameData = (u8 *)GAME_COMM_GetGameData(param->gameComm);
    if (GAME_DATA_IsSaving((struct GameData *)gameData) == 1)
        return 0;
    switch (*state) {
    case 0:
        init = (GFLNetInitializeStruct *)GFL_HEAP_Alloc(0x8005, 0x70, 0, d_02177000, 0xcf);
        *init = d_021768C8;
        if (param->isParent == 1) {
            if (INTRUDE_COMM_HasUnlockFlags((struct GameData *)gameData) == 0)
                init->maxConnectNum = 2;
        }
        GFL_NET_StartSession(init, INTRUDE_COMM_OnSessionStarted, work);
        GFL_HEAP_Free(init);
        *state = *state + 1;
        break;
    case 1:
        if (work->step >= 2) {
            if (param->isParent == 1) {
                GFL_NET_StartChangeoverParent(0);
                work->step = 3;
            } else {
                GFL_NET_ConnectMacAddressParent(param->parentMac);
                work->step = 4;
            }
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * evidence: 0x02008494 is an unlabelled ARM9 thunk ("ldr r3, =MI_CpuCopy8; movs r2, #0x20; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov018 0x0217FDEC, ov021 0x021CD548, ov088 0x021BC32A and more), so the call
 * attests as `label`.
 */
void INTRUDE_COMM_MainStep(int *state, IntrudeCommParam *param, IntrudeCommSys *work)
{
    struct GameData *gameData;
    struct MyStatus *playerStatus;
    s32 startTime;
    s32 now;

    gameData = GAME_COMM_GetGameData(param->gameComm);
    if (work != 0 && work->step >= 7) {
        EVENT_FIELD_PROCLINK_RunReturnSlotsIfOffline((struct EventSlots *)work->returnSlots, (struct ProcLinkSys *)GAME_DATA_GetSecondUnionInfo(gameData), work->peerMask);
    }
    if (GFL_NET_ERR_GetErrorLevel() != 0 || work->quit == 1) {
        if (work->lock) {
            return;
        }
        work->step = 11;
        work->quit = 1;
        GAME_COMM_RequestExitNoCallback(work->gameComm);
        return;
    }
    if (DWCi_IsFold() == 1 && UI_IsPowerConnected() == 1 && work->lock == 0) {
        GAME_COMM_RequestExitNoCallback(work->gameComm);
        return;
    }
    if (work->step == 7 && work->shutdownRequested == 1) {
        GAME_COMM_RequestExitNoCallback(work->gameComm);
        return;
    }
    INTRUDE_COMM_RefreshBeacon(gameData, &work->beacon);
    INTRUDE_COMM_AgeFoundList(work);
    switch (*state) {
    case 0:
        if (GFL_NET_SYSTEM_GetConnectNum() > 1 && work->step < 5) {
            work->step = 5;
            GFL_NET_SetLoginOption(1);
        }
        if (work->step == 5) {
            if (GFL_NET_HANDLE_CheckNegotiation() == 1) {
                GAME_DATA_SetOwnNetId(gameData, GFL_NET_SYSTEM_GetCurrentAid());
                playerStatus = GAME_DATA_GetMyStatusPlayer(gameData, GFL_NET_SYSTEM_GetCurrentAid());
                MYSTATUS_Copy(GAME_DATA_GetMyStatus(gameData), playerStatus);
                INTRUDE_COMM_SetIntrudeId(work, GFL_NET_SYSTEM_GetCurrentAid());
                work->localPeer.statusCode = PM_VERSION_ID;
                work->localPeer.season = GAME_DATA_GetSeason(gameData);
                if (INTRUDE_COMM_HasUnlockFlags(gameData) == 0) {
                    work->localPeer.startFlag = 1;
                }
                GFL_NET_SetLoginOption(1);
                (*state)++;
            }
        } else if (work->step == 4) {
            work->waitFrames++;
            if (work->waitFrames > 600) {
                work->waitFrames = 0;
                GAME_COMM_RequestExitNoCallback(work->gameComm);
                return;
            }
        }
        break;
    case 1:
        if (GFL_NET_HANDLE_IsNegotiationDone(GFL_NET_HANDLE_GetCurrentHandle()) == 1) {
            work->step = 6;
            (*state)++;
        }
        break;
    case 2:
        EVENT_FIELD_PROCLINK_InitReturnSlotsWithAid((struct EventSlots *)work->returnSlots);
        INTRUDE_COMM_RefreshSelfRecord(work);
        INTRUDE_COMM_ApplyPlayerBeacon(work, GFL_NET_SYSTEM_GetCurrentAid(), &work->ownStatus);
        (*state)++;
        break;
    case 3:
        if (INTRUDE_COMM_SendStatusRecord(work) == 1) {
            work->step = 7;
            work->startTime = GF_STANDARD_GetSecondsOfDay();
            (*state)++;
        }
        break;
    case 4:
        if (GAME_DATA_GetIntrudeCount(gameData) == 0 && work->localPeer.season != GAME_DATA_GetSeason(gameData)
            && GAMESYSTEM_IsFieldMapActive(param->gameSystem) == 1) {
            GAME_COMM_RequestExitNoCallback(work->gameComm);
            return;
        }
        INTRUDE_COMM_UpdateRunning(work);
        if (INTRUDE_COMM_IsResultConfirmed(&work->session) == 1) {
            GAME_COMM_RequestExitNoCallback(work->gameComm);
            return;
        }
        if (GFL_NET_IsParentAid() == 1 && INTRUDE_COMM_IsSessionActive(&work->session) == 0) {
            startTime = work->startTime;
            now = GF_STANDARD_GetSecondsOfDay();
            if (now < startTime) {
                now += 86399;
            }
            now -= startTime;
            if (now >= 180) {
                GAME_COMM_RequestExitNoCallback(work->gameComm);
                return;
            }
            if (now > 170 && work->warned == 0 && INTRUDE_COMM_SendTimeoutWarning() == 1) {
                work->warned = 1;
            }
        } else if (work->lock == 0 && GFL_NET_IsParentAid() == 1
                   && INTRUDE_COMM_GetLeaveFlag(&work->session) == 1) {
            GAME_COMM_RequestExitNoCallback(work->gameComm);
        } else {
            work->warned = 0;
        }
        if (INTRUDE_COMM_HasConnectedPeers() == 0) {
            work->idleFrames++;
            if (work->idleFrames > 180) {
                GAME_COMM_RequestExitNoCallback(work->gameComm);
                return;
            }
        } else {
            work->idleFrames = 0;
        }
        break;
    }
}

int INTRUDE_COMM_Shutdown(int *state, IntrudeCommParam *param, IntrudeCommSys *work)
{
    if (GAME_DATA_IsSaving((struct GameData *)GAME_COMM_GetGameData(param->gameComm)) == 1) {
        return 0;
    }
    if (work->quit == 1 || GFL_NET_ERR_GetErrorLevel() != 0) {
        work->sessionEnded = 1;
        GFL_NET_Exit(INTRUDE_COMM_OnSessionExit);
        return 1;
    }
    switch (*state) {
    case 0:
        work->step = 9;
        if (GFL_NET_GetNegotiationNum() <= 1) {
            *state = 4;
        } else if (INTRUDE_COMM_SendShutdownRequest(work) == 1) {
            (*state)++;
        }
        break;
    case 1:
        work->waitFrames = 0;
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x14, 2);
        (*state)++;
        break;
    case 2:
        work->waitFrames++;
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x14, 2) == 1 || work->waitFrames > 300) {
            GFL_NET_SetLoginOption(0);
            (*state)++;
        }
        break;
    case 3:
        work->waitFrames++;
        if (GFL_NET_IsParentAid() == 1) {
            if (GFL_NET_GetNegotiationNum() <= 1 || work->waitFrames > 300) {
                (*state)++;
            }
        } else {
            (*state)++;
        }
        break;
    case 4:
        work->sessionEnded = 1;
        GFL_NET_Exit(INTRUDE_COMM_OnSessionExit);
        return 1;
    }
    return 0;
}

/*
 * 2026-10-05 (D8 lane19): re-verified, MATCH; unresolved relocations are arm9 0x02026680 and ov010 0x02161F68 (leaf witnesses in the note). Needs label seeds. Source is byte-correct; no C change possible.
 *
 * Byte-correct (416/416), 29 of 31 relocations resolved. The two
 * unresolved sites are leaves whose only caller image-wide is this
 * function (tu --suggest-split: not cuttable):
 *   +0076 EVENT_FIELD_PROCLINK_ClearReturnSlots (ov010, unlabelled 12-byte memset stub)
 *   +0168 GAME_COMM_ClearInfoMessages (arm9, unlabelled; the integrator's)
 * Because an arm9 leaf is among the blockers, the ov010 leaf is not filed.
 * Levers from the DIFF note (wave 82): the `b` to the next instruction at
 * +0x136 is the shared GAME_DATA_SetEnterMode(h, 1) call written in both arms of the
 * GAME_DATA_GetIntrudeCount(h) == 0 test (cross-jumped, see
 * docs/idioms/an-if-else-storing-to-one-target-keeps-the-empty-else-branch-to-next.md);
 * the register permutation disappeared once every callee took its matched
 * prototype (h a u32 cast at each call, me a u8, o a void ** parameter).
 *
 *   0x02026680 arm9 thumb, verified EXACT with
 *     `one --thumb --lang c99` (no --region):
 *     typedef unsigned char u8;
 *     typedef struct { u8 b0 : 1; u8 rest : 7; u8 pad[0xb]; } E;
 *     void GAME_COMM_ClearInfoMessages(u8 *p)
 *     {
 *         int i;
 *         for (i = 0; i < 6; i++) {
 *             ((E *)(p + 0x3f))[i].b0 = 0;
 *         }
 *         p[0x85] = 0;
 *         p[0x84] = 0;
 *     }
 *   0x02161F68 ov010 thumb (overlay leaf, not filed while the arm9 leaf
 *     blocks), verified EXACT with `one --thumb --region ov010 --lang c99`:
 */
int INTRUDE_COMM_Destroy(int unused, void **proc, IntrudeCommSys *work)
{
    struct GameComm *gameComm;
    int ok;
    uptr gameData;
    IntrudeResultRecord *palaceList;
    u8 myNetId;
    int i;

    gameComm = proc[1];
    gameData = (uptr)GAME_COMM_GetGameData(gameComm);
    ok = 0;
    if (GAME_DATA_IsSaving((struct GameData *)gameData) == 1) {
        return ok;
    }
    if (work->step == 10 || GFL_NET_IsSessionNull() == 1) {
        if (GAME_DATA_GetIntrudeCount((struct GameData *)gameData) == 0) {
            GFL_NET_ERR_ResetState();
            ok = 1;
        } else if (ZONEDATA_IsEntralink(GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork((struct GameData *)gameData))) == 1
                   && GAMESYSTEM_IsFieldMapActive(proc[0]) == 1
                   && FIELDMAP_IsReady(GAMESYSTEM_GetFieldMap(proc[0])) == 1) {
            ok = 1;
        }
    }
    if (ok == 1) {
        EVENT_FIELD_PROCLINK_ClearReturnSlots((struct EventSlots *)work->returnSlots);
        GAME_DATA_ClearUnionInfo((struct GameData *)gameData);
        COMM_PLAYER_Delete(proc[0], work->commPlayer);
        if (work->quit == 1 || GFL_NET_ERR_GetErrorLevel() != 0) {
            GAME_COMM_SetCounter(gameComm, 5);
        } else if (INTRUDE_COMM_HasResult(&work->session) == 1) {
            if (work->abortFlag == 1) {
                GAME_COMM_SetCounter(gameComm, 4);
            } else if (INTRUDE_COMM_HasResultReward(work, &work->session) == 1) {
                GAME_COMM_SetCounter(gameComm, 2);
            } else {
                palaceList = INTRUDE_COMM_GetSessionResult(&work->session);
                myNetId = GAME_DATA_GetOwnNetId((struct GameData *)gameData);
                for (i = 0; i < 3; i++) {
                    if (palaceList->partnerIds[i] != 4 && myNetId != palaceList->partnerIds[i]) {
                        break;
                    }
                }
                if (i < 3) {
                    GAME_COMM_SetCounter(gameComm, 3);
                } else {
                    GAME_COMM_SetCounter(gameComm, 4);
                }
            }
        } else if (work->peerMask > 1) {
            GAME_COMM_SetCounter(gameComm, 1);
        }
        if (GAME_DATA_GetIntrudeCount((struct GameData *)gameData) == 0) {
            GAME_DATA_SetOwnNetId((struct GameData *)gameData, 0);
            GAME_DATA_SetIntrudeId((struct GameData *)gameData, 0);
            GAME_DATA_SetEnterMode((struct GameData *)gameData, 1);
        } else {
            GAME_DATA_SetEnterMode((struct GameData *)gameData, 1);
        }
        if ((work->quit == 1 || GFL_NET_ERR_GetErrorLevel() != 0) && GAME_DATA_GetIntrudeCount((struct GameData *)gameData) == 1) {
            GAMESYSTEM_SetFieldMapState(proc[0], 1);
        }
        GAME_COMM_ClearInfoMessages(gameComm);
        for (i = 0; i < 2; i++) {
            STRBUF_Delete((struct Strbuf *)work->foundNames[i]);
        }
        GFL_HEAP_Free(work);
        GFL_HEAP_Free(proc);
        return 1;
    }
    return 0;
}

/*
 * Addresses are Black-image addresses.
 */
void INTRUDE_COMM_ScanCallback(void *whPipe, IntrudeCommSys *work)
{
    u8 recordKind;
    IntrudeScanRecord *record;
    int i;

    if (work->foundCount >= 2) {
        return;
    }
    if (GFL_NET_GetNegotiationNum() > 1) {
        return;
    }
    if (work->quit == 1) {
        return;
    }
    if (GFL_NET_ERR_GetErrorLevel() != 0) {
        return;
    }
    if (WIH_IsMatchingParent(whPipe) == 0) {
        return;
    }
    if (NET_WHPIPE_CheckBeaconFlags(whPipe, ~0x10) == 0) {
        return;
    }
    record = (struct IntrudeScanRecord *)NET_WHPIPE_GetEntryBeacon(whPipe, &recordKind);
    if (recordKind != 3) {
        return;
    }
    if (record->excluded) {
        return;
    }
    for (i = 0; i < work->foundCount; i++) {
        if (record->trainerId == work->foundTrainerIds[i]) {
            return;
        }
    }
    if ((int)ZONEDATA_IsEntralink((u16)record->info.zoneId) == 1) {
        return;
    }
    if (INTRUDE_COMM_IsListedId(record->info.zoneId) == 0) {
        return;
    }
    GAME_BEACON_ACCESSOR_GetPlayerName(&record->info, (struct Strbuf *)work->foundNames[work->foundCount]);
    work->foundSex[work->foundCount] = GAME_BEACON_ACCESSOR_GetSex(&record->info);
    work->foundLanguage[work->foundCount] = GAME_BEACON_ACCESSOR_GetLanguage(&record->info);
    work->foundTrainerIds[work->foundCount] = record->trainerId;
    work->foundAge = 0;
    work->foundCount++;
}

void INTRUDE_COMM_SyncPlayers(IntrudeCommSys *work, IntrudeCommSys *peerWork, int fieldObjectAddr)
{
    struct GameData *gameData;
    int myNetId;
    int i;
    IntrudePlayerPackage package;

    if (peerWork == 0) {
        return;
    }
    gameData = GAME_COMM_GetGameData(work->gameComm);
    myNetId = GAME_DATA_GetOwnNetId(gameData);
    if (GAME_DATA_GetIntrudeCount(gameData) == 0) {
        if (INTRUDE_FIELD_IsListedZone(FIELDMAP_GetZoneId((struct FieldMap *)fieldObjectAddr)) == 1) {
            COMM_PLAYER_Resume(peerWork->commPlayer);
        } else {
            COMM_PLAYER_ClearPending(peerWork->commPlayer);
        }
    } else {
        COMM_PLAYER_Resume(peerWork->commPlayer);
    }
    for (i = 0; i < 3; i++) {
        if (i != myNetId && COMM_PLAYER_CheckOccupy(peerWork->commPlayer, i) == 1) {
            peerWork->peers[i].package.vanish = peerWork->peers[i].remoteVanish;
            package = peerWork->peers[i].package;
            package.vanish = 1;
            COMM_PLAYER_SetPackage(peerWork->commPlayer, i, (struct CommPlayerPackage *)(&package));
        }
    }
    for (i = 0; i < 3; i++) {
        if (i != myNetId && (peerWork->peerMask & (1 << i))) {
            int remoteVanish = peerWork->peers[i].remoteVanish;
            INTRUDE_COMM_StorePlayerRecord(peerWork, i, &peerWork->peers[i], 0);
            peerWork->peers[i].remoteVanish = remoteVanish;
        }
    }
}

/*
 * Extent contains followers 02173568, already-filed 02173580, and 0217358C;
 * the lead stays separate to preserve the existing follower file.
 */
void INTRUDE_COMM_SuspendPlayers(int arg, IntrudeCommSys *work)
{
    if (work != 0)
        COMM_PLAYER_Suspend(work->commPlayer);
}

void INTRUDE_COMM_OnSessionStarted(void *userArg)
{
    IntrudeCommSys *work = userArg;

    work->step = 2;
    WIH_SetBeaconFoundCallback((uptr)INTRUDE_COMM_ScanCallback);
}

/*
 * Callback leaf: sets the state byte at 0x8FD to 10.  It saves nothing, so
 * disasm.py left it as .word data; its only reference is the function
 * pointer INTRUDE_COMM_Shutdown hands to GFL_NET_Exit, which is why it is filed
 * here, to give that pool word a matched witness.
 */
void INTRUDE_COMM_OnSessionExit(void *userArg)
{
    IntrudeCommSys *work = userArg;

    work->step = 10;
}

IntrudeBeacon *INTRUDE_COMM_GetBeacon(IntrudeCommSys *work) { return &work->beacon; }

void INTRUDE_COMM_InitBeacon(struct GameData *gameData, IntrudeBeacon *beacon, int maxConnect)
{
    beacon->gameKind = 2;
    beacon->connectNum = GFL_NET_GetNegotiationNum();
    if (maxConnect != -1)
        beacon->maxConnect = maxConnect;
    beacon->hasNetError = GFL_NET_SYSTEM_CheckError();
    beacon->version = 1;
    MYSTATUS_Copy((struct MyStatus *)(GAME_DATA_GetMyStatus(gameData)), (struct MyStatus *)beacon->ownerStatus);
}

int INTRUDE_COMM_RefreshBeacon(struct GameData *gameData, IntrudeBeacon *beacon)
{
    if (beacon->connectNum != GFL_NET_GetNegotiationNum() || beacon->hasNetError != GFL_NET_SYSTEM_CheckError()) {
        INTRUDE_COMM_InitBeacon(gameData, beacon, -1);
        NET_WHPIPE_PublishBeacon();
        return 1;
    }
    return 0;
}

int INTRUDE_COMM_IsEqual(int left, int right)
{
    if (left == right)
        return 1;
    return 0;
}

void INTRUDE_COMM_RecvQuit(int netId, int size, IntrudeCommSys *work)
{
    work->quit = 1;
}

void INTRUDE_COMM_Nop(void)
{
}

void INTRUDE_COMM_AgeFoundList(IntrudeCommSys *work)
{
    int i;

    if (work->foundCount != 0) {
        work->foundAge = work->foundAge + 1;
        if (work->foundAge > 0x96) {
            for (i = 0; i < work->foundCount; i++)
                work->foundTrainerIds[i] = 0;
            work->foundAge = 0;
            work->foundCount = 0;
        }
    }
}

u8 *INTRUDE_COMM_GetStatusArea(int unused, IntrudeCommSys *work) { return work->statusArea; }

IntrudeMemberRecord *INTRUDE_COMM_GetMemberRecord(int index, IntrudeCommSys *work) { return &work->memberRecords[index]; }

IntrudeStatusRecord *INTRUDE_COMM_GetStatusRecord(int index, IntrudeCommSys *work) { return &work->statusRecords[index]; }

u8 *INTRUDE_COMM_GetWorkArea(int unused, IntrudeCommSys *work) { return work->workArea; }

int INTRUDE_COMM_IsLinked(void)
{
    return INTRUDE_COMM_HasConnectedPeers();
}

void INTRUDE_COMM_RecvShutdownRequest(int netId, int size, int data, IntrudeCommSys *work, unsigned int handle)
{
    work->shutdownRequested = 1;
}

/*
 * The fifth argument to 021736E0 is visibly written to the outgoing stack slot.
 */
int INTRUDE_COMM_SendShutdownRequest(IntrudeCommSys *work)
{
    unsigned int netId;
    if (INTRUDE_COMM_IsLinked() == 0) {
        netId = GFL_NET_SYSTEM_GetCurrentAid();
        INTRUDE_COMM_RecvShutdownRequest(netId, 0, 0, work, (uptr)GFL_NET_HANDLE_GetCurrentHandle());
        return 1;
    }
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x200, 0, 0);
}

/*
 * The loaded byte stays live as r1 into 02012B4C.
 */
void INTRUDE_COMM_RecvMemberCount(unsigned int netId, int size, u8 *data, IntrudeCommSys *work)
{
    struct GameData *gameData;
    unsigned int count;
    gameData = GAME_COMM_GetGameData(work->gameComm);
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) {
        count = *data;
        work->memberCount = count;
        GAME_DATA_SetEnterMode(gameData, count);
    }
}

/*
 * Handed as 0x0217375A; the function starts at the push {r0-r3} at 0x02173758.
 */
int INTRUDE_COMM_SendMemberCount(IntrudeCommSys *work, int memberCount, ...)
{
    if (INTRUDE_COMM_IsLinked() == 0)
        return 0;
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0xff, 0x201, 1, &memberCount, 1, 0, 0);
}

void INTRUDE_COMM_RecvRecordRequest(int netId, int size, int data, IntrudeCommSys *work) { work->resendRequested = 1; }

/*
 * Return-valued externs reflect r0 consumed after both forwarding calls.
 */
int INTRUDE_COMM_SendRecordRequest(void)
{
    if (INTRUDE_COMM_IsLinked() == 0)
        return 0;
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x202, 0, 0);
}

void INTRUDE_COMM_RecvStatusRecord(int netId, int size, IntrudeStatusRecord *record, IntrudeCommSys *work)
{
    sptr gameData;

    gameData = (sptr)GAME_COMM_GetGameData(work->gameComm);
    if (netId < work->memberCount) {
        INTRUDE_COMM_ApplyPlayerBeacon(work, netId, record);
        if (netId != GAME_DATA_GetOwnNetId((const struct GameData *)gameData) && GFL_NET_IsParentAid() == 0 && netId == 0 && record->peer.startFlag == 1)
            work->startFlag = 1;
    }
}

int INTRUDE_COMM_SendStatusRecord(IntrudeCommSys *work)
{
    int result;

    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    if (GFL_NET_IsSendQueueEntryOfHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x203) == 1) {
        return 0;
    }
    MI_CpuCopy8(&work->ownStatus, work->sendBuffer, 0x4C);
    result = GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0xFF, 0x203, 0x4C, work->sendBuffer, 0, 0, 1);
    if (result == 1) {
        work->resendRequested = 0;
        if (GFL_NET_IsParentAid() == 1) {
            work->memberCountDirty = 1;
            INTRUDE_COMM_SetSessionRequestSendFlag(&work->session);
            INTRUDE_COMM_SetSessionResultSendFlag(&work->session);
        }
    }
    return result;
}

/*
 * The index loaded from data remains live in r1 into 02167658.
 */
void INTRUDE_COMM_RecvPeerLeft(int senderNetId, int size, int *data, IntrudeCommSys *work, void *handle)
{
    int leavingNetId;
    u32 bit;
    u8 mask;
    leavingNetId = *data;
    bit = 1u << leavingNetId;
    mask = work->peerMask;
    if (mask & bit) {
        work->peerMask = mask ^ (u8)bit;
        COMM_PLAYER_Del(work->commPlayer, leavingNetId);
    }
}

int INTRUDE_COMM_SendPeerLeft(IntrudeCommSys *work, int leavingNetId)
{
    int selfNetId;

    if (INTRUDE_COMM_IsLinked() == 0) {
        selfNetId = GFL_NET_SYSTEM_GetCurrentAid();
        INTRUDE_COMM_RecvPeerLeft(selfNetId, 4, &leavingNetId, work, GFL_NET_HANDLE_GetCurrentHandle());
        return 1;
    }
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x204, 4, &leavingNetId);
}

void INTRUDE_COMM_RecvPeerStatus(int netId, int size, const IntrudePeer *peer, IntrudeCommSys *work)
{
    if (netId == GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) {
        GAME_COMM_UpdatePlayerStatus(work->gameComm, netId, peer->zoneId, peer->intrudeId, PM_VERSION_ID, 0);
    } else if ((work->peerMask & (1 << netId)) != 0) {
        INTRUDE_COMM_StorePlayerRecord(work, netId, peer, 0);
    }
}

int INTRUDE_COMM_SendPeerStatus(IntrudeCommSys *work, const IntrudePeer *peer)
{
    int result;

    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    result = GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0xFF, 0x205, 0x1C, (void *)peer, 0, 1, 0);
    if (result == 1) {
        work->peerStatusDirty = 0;
    }
    return result;
}

void INTRUDE_COMM_RecvTimeoutWarning(int netId, int size, int data, IntrudeCommSys *work)
{
    work->warned = 1;
}

int INTRUDE_COMM_SendTimeoutWarning(void)
{
    if (INTRUDE_COMM_IsLinked() == 0) return 1;
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x206, 0, 0);
}

void INTRUDE_COMM_RecvRequest(int netId, int size, IntrudeRequestMessage *request, IntrudeCommSys *work)
{
    if (INTRUDE_COMM_TryStartRequest(work, netId, request->seq) == 1) work->receivedRequest = *request;
}

int INTRUDE_COMM_SendRequest(IntrudeCommSys *work, int destNetId, IntrudeMemberRecord *data, int type)
{
    IntrudeRequestMessage message;
    int result;

    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    if (work->nextRequestSeq == 0) {
        work->nextRequestSeq++;
    }
    MI_CpuFill8(&message, 0, 0x38);
    message.type = type;
    message.data = *data;
    message.seq = work->nextRequestSeq;
    result = GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), destNetId, 0x207, 0x38, &message, 0, 0, 0);
    if (result == 1) {
        work->sentRequestSeq = work->nextRequestSeq;
        work->expectedReplySeq = work->nextRequestSeq;
    }
    return result;
}

void INTRUDE_COMM_RecvReply(int netId, int size, u8 *reply, IntrudeCommSys *work)
{
    u8 seq;
    seq = reply[1];
    if (seq == work->expectedReplySeq) INTRUDE_COMM_SetRequestResult(work, netId, reply[0], seq);
    else work->pendingReplies[netId] = seq;
}

int INTRUDE_COMM_SendReply(void *unused, int destNetId, int answer, int seq)
{
    unsigned char message[4];

    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    message[0] = answer;
    message[1] = seq;
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), destNetId, 0x208, 4, message, 0, 0, 0);
}

void INTRUDE_COMM_RecvNotice(int netId, int size, u8 *notice, IntrudeCommSys *work)
{
    if (work->requestTarget == netId && work->sentRequestSeq == notice[0]) INTRUDE_COMM_SetRequestResult(work, netId, 3, notice[0]);
}

int INTRUDE_COMM_SendNotice(IntrudeCommSys *work, int destNetId, int value)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), destNetId, 0x209, 1, &value, 0, 0, 0);
}

void INTRUDE_COMM_RecvAnswer(int netId, int size, u8 *data, IntrudeCommSys *work)
{
    INTRUDE_COMM_SetRequestResultAccepted(work, netId, *data);
}

int INTRUDE_COMM_SendAnswer(int destNetId, int value)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), destNetId, 0x20A, 1, &value, 0, 0, 0);
}

void INTRUDE_COMM_RecvNoticeBytes(int netId, int size, const u8 *data, IntrudeCommSys *work)
{
    work->notice.value[0] = data[0];
    work->notice.value[1] = data[1];
    work->notice.value[2] = data[2];
    work->notice.value[3] = data[3];
}

int INTRUDE_COMM_SendNoticeBytes(int destNetId, int value)
{
    unsigned char message[4];

    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    MI_CpuFill8(message, 0, 4);
    message[0] = 1;
    message[1] = value;
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), destNetId, 0x20B, 4, message, 0, 0, 0);
}

void INTRUDE_COMM_RecvReady(int netId, int size, int data, IntrudeCommSys *work) { work->readyMask |= (u8)(1 << netId); }

int INTRUDE_COMM_SendReady(struct IntrudeCommSys *unused, u8 destNetId)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), destNetId, 0x20C, 0, 0, 0, 0, 0);
}

void INTRUDE_COMM_RecvRemoteRecord(int netId, int size, IntrudeRemoteRecord *record, IntrudeCommSys *work)
{
    work->remoteRecord = *record;
}

int INTRUDE_CMD_SendSaveSummary(IntrudeCommSys *w, int sendMask)
{
    void *saveData;
    IntrudeProfileData summary;

    saveData = GAME_COMM_GetGameData(w->gameComm);
    INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(saveData));
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    INTRUDE_COMM_BuildLocalProfile(saveData, &summary);
    return GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), (unsigned char)sendMask, 0x20D, sizeof(IntrudeProfileData), &summary, 0, 0, 0);
}

/*
 * note: Two alignment bytes follow; existing pkt_ov011_02173D2C covers
 *       the next function's push at 02173D2C. No unit is created.
 */
void INTRUDE_CMD_RecvEntryIndex(u32 netId, int size, int *entryIndex, IntrudeCommSys *w)
{
    if (GFL_NET_IsParentAid()) {
        INTRUDE_COMM_SetMemberEntry(w, &w->session, netId, *entryIndex);
        INTRUDE_COMM_SetSessionEntrySendFlag(&w->session, *entryIndex);
    }
}

int INTRUDE_CMD_SendEntryIndex(struct IntrudeCommSys *unused, int entryIndex)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x20E, 4, &entryIndex);
}

void INTRUDE_CMD_RecvMemberEntry(int netId, int size, IntrudeMemberEntry *entry, IntrudeCommSys *w)
{
    void *saveData;
    int memberId;

    saveData = GAME_COMM_GetGameData(w->gameComm);
    memberId = entry->member.netId;
    INTRUDE_COMM_StoreSessionEntry(&w->session, entry->name.chars, memberId);
    if (memberId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) {
        MI_CpuCopy8(entry, GAME_DATA_GetBattleRecSlot(saveData, memberId), 0x10);
    }
}

int INTRUDE_CMD_SendMemberEntry(void *unused, IntrudeSession *session, int memberIndex)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0xFF, 0x20F, 0x28, &session->members[memberIndex], 0, 0, 1);
}

void INTRUDE_CMD_RecvJoinRequest(int netId, int size, IntrudeJoinRequest *request, IntrudeCommSys *w)
{
    unsigned kind;

    if (GFL_NET_IsParentAid()) {
        if (INTRUDE_COMM_ReceiveJoinRequest(w, &w->session, request, netId) == 1) {
            kind = request->head.kind;
            if (kind == 0 || kind == 3) {
                GFL_NET_SetAcceptConnection((GFL_NET_HANDLE_GetCurrentHandle()), 0);
                NET_WHPIPE_SetBeaconStatus(1);
                w->busyLock = 1;
            }
        }
    }
}

int INTRUDE_CMD_SendJoinRequest(IntrudeCommSys *w, void *request)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    INTRUDE_COMM_ClearJoinReply(&w->session);
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x210, 0x30, request);
}

void INTRUDE_CMD_RecvJoinReply(int netId, int size, void *reply, IntrudeCommSys *w)
{
    INTRUDE_COMM_StoreJoinReply(&w->session, reply);
}

int INTRUDE_CMD_SendJoinReply(void *unused, void *reply, int netId)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    if (GFL_NET_IsConnectMember(netId & 0xFF) == 0) {
        return 1;
    }
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), (unsigned char)netId, 0x211, 0x38, reply, 0, 0, 0);
}

void INTRUDE_CMD_RecvGroupRecord(int netId, int size, IntrudeMemberRecord *record, IntrudeCommSys *w)
{
    GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(GAME_COMM_GetGameData(w->gameComm)));
    if (INTRUDE_COMM_StoreSessionRequest(w, &w->session, record) == 1) w->entryReceived = 1;
}

int INTRUDE_CMD_SendGroupRecord(IntrudeCommSys *w, IntrudeSession *session)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    if (GFL_NET_IsSendQueueEntryOfHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x212) == 1) {
        return 0;
    }
    MI_CpuCopy8(&session->request, &w->recordCopy, 0x34);
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0xFF, 0x212, 0x34, &w->recordCopy, 0, 0, 1);
}

void INTRUDE_CMD_RecvRecordEcho(int netId, int size, void *record, IntrudeCommSys *w)
{
    IntrudeMemberRecord *pending;
    pending = INTRUDE_COMM_GetActiveSessionRequest(&w->session);
    if (pending != 0 && GF_STANDARD_CompareBytes((u8 *)pending, record, 0x34) == 0) INTRUDE_COMM_ClearSessionTicks(&w->session);
}

/*
 * note: The matched void forwarder INTRUDE_COMM_IsLinked leaves r0 live and this
 *       caller tests it at 02173F7C. GFL_NET_SendToHandle's final send result is
 *       returned in live r0 at 02173F94, so both externs return int here.
 */
int INTRUDE_CMD_SendRecordEcho(void *unused, IntrudeSession *session)
{
    if (INTRUDE_COMM_IsLinked() == 0) return 0;
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x213, 0x34, &session->request);
}

void INTRUDE_CMD_RecvRecordAccept(int netId, int size, void *record, IntrudeCommSys *w)
{
    INTRUDE_COMM_GetActiveSessionRequest(&w->session);
    if (GFL_NET_IsParentAid()) INTRUDE_COMM_AddSessionMember(&w->session, netId);
}

/*
 * note: Lead one run is EXACT*, followed by the root-claimed 02173FE4
 *       tail stub; tu verifies the complete 52-byte unit. INTRUDE_COMM_IsLinked's void forwarder
 *       leaves r0 live, tested at 02173FC8; GFL_NET_SendToHandle's final send
 *       result is returned at 02173FE2. Follower loads a full word at
 *       02173FEA and forwards it without caller truncation.
 */
int INTRUDE_CMD_SendRecordAccept(int unused, IntrudeSession *session)
{
    if (INTRUDE_COMM_IsLinked() == 0) return 0;
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x214, 0x34, &session->request);
}

void INTRUDE_CMD_RecvMemberValue(int netId, int size, int *value, IntrudeCommSys *w)
{
    INTRUDE_COMM_StartSessionTimer(&w->session, *value);
}

int INTRUDE_CMD_SendMemberValue(void *unused, int value, int sendMask)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    return GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), (unsigned char)sendMask, 0x215, 4, &value, 0, 0, 0);
}

void INTRUDE_CMD_RecvProposal(int netId, int size, IntrudeMemberRecord *record, IntrudeCommSys *w)
{
    if (GFL_NET_IsParentAid()) INTRUDE_COMM_StoreResultRecord(&w->session, record, netId);
}

int INTRUDE_CMD_SendProposal(IntrudeCommSys *w, IntrudeSession *session)
{
    int result;

    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    INTRUDE_COMM_ClearJoinStatus(&w->session);
    result = GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x216, 0x34, &session->request);
    if (result == 1) {
        INTRUDE_COMM_SetSessionFinished(&w->session);
    }
    return result;
}

void INTRUDE_CMD_RecvProposalReply(int netId, int size, int *value, IntrudeCommSys *w)
{
    INTRUDE_COMM_SetJoinStatus(&w->session, *value);
}

/*
 * Handed as 0x021740AE; the function starts at the push {r0-r3} at 0x021740AC.
 */
int INTRUDE_CMD_SendProposalReply(int unused, int value, int netId, ...)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    if ((int)GFL_NET_IsConnectMember((unsigned char)netId) == 0) {
        return 1;
    }
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), netId, 0x217, 4, &value, 0, 0, 0);
}

void INTRUDE_CMD_RecvResultRecord(int netId, int size, IntrudeResultRecord *record, IntrudeCommSys *w)
{
    IntrudeSaveSlot *saveSlot;
    int hasExtra;
    void *saveData;
    u8 extra[2];
    int tallyA;
    int tallyB;

    saveData = GAME_COMM_GetGameData(w->gameComm);
    saveSlot = GAME_DATA_GetLastBattleRecSlot(saveData);
    extra[1] = 0;
    hasExtra = 0;
    extra[0] = 0;
    tallyA = 0;
    tallyB = 0;
    if (record->record.netId == 4) {
        return;
    }
    if (INTRUDE_COMM_HasResult(&w->session) == 1) {
        return;
    }
    if (record->record.name.netId == GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) {
        if (record->confirmed == 1) {
            INTRUDE_COMM_PickEntryForKind(saveSlot, record->record.head.kind);
            w->resultUpdated = 1;
        } else {
            INTRUDE_COMM_RecordResultOutcome(saveData, w, record);
            w->resultUpdated = 1;
        }
        if (INTRUDE_COMM_TallyOutcomesAndResetIfComplete(saveSlot, &extra[1], &extra[0]) == 1) {
            hasExtra = 1;
            w->resultUpdated = 1;
        }
        if (record->record.requestFlag == 1) {
            tallyB = 1;
        } else {
            tallyA = 1;
        }
        if (hasExtra == 1) {
            tallyB += extra[0];
            tallyA += extra[1];
        }
        w->ownTally.countA = tallyA;
        w->ownTally.countB = tallyB;
        w->ownTally.valid = 1;
        w->tallyPending = 1;
    }
    INTRUDE_COMM_SetResultRecord(w, &w->session, record);
}

int INTRUDE_CMD_SendResultRecord(IntrudeCommSys *w, IntrudeSession *session)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    if (GFL_NET_IsSendQueueEntryOfHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x218) == 1) {
        return 0;
    }
    MI_CpuCopy8(&session->result, &w->resultCopy, 0x3c);
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0xff, 0x218, 0x3c, &w->resultCopy, 0, 0, 1);
}

void INTRUDE_CMD_RecvReadyNotice(int netId, int size, int unused, IntrudeCommSys *w)
{
    INTRUDE_COMM_SetSessionReadyBit(&w->session, netId);
}

int INTRUDE_CMD_SendReadyNotice(IntrudeCommSys *w)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    INTRUDE_COMM_SetNoticeState(&w->session, 0);
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0, 0x219, 0, 0, 0, 0, 0);
}

void INTRUDE_CMD_RecvStartNotice(int netId, int size, int unused, IntrudeCommSys *w)
{
    INTRUDE_COMM_SetNoticeState(&w->session, 1);
}

int INTRUDE_CMD_SendStartNotice(int sendMask)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x21a, 0, 0, 0, 0, 0);
}

void INTRUDE_CMD_RecvEndNotice(int netId, int size, int unused, IntrudeCommSys *w)
{
    INTRUDE_COMM_SetNoticeState(&w->session, 2);
}

/*
 * note: INTRUDE_COMM_IsLinked's matched void forwarder leaves r0 live and the
 *       caller tests r0 at 021742F6; its extern returns int here.
 */
u32 INTRUDE_CMD_SendEndNotice(u32 sendMask)
{
    if (INTRUDE_COMM_IsLinked() == 0) return 1;
    return GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), sendMask, 0x21b, 0, 0, 0, 0, 0);
}

void INTRUDE_CMD_RecvProfile(int netId, int size, void *profile, IntrudeCommSys *w)
{
    void *saveData;

    saveData = GAME_COMM_GetGameData(w->gameComm);
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle()) && (w->peerMask & (1 << netId))) {
        MI_CpuCopy8(profile, GAME_DATA_GetBattleRecSlot(saveData, netId), 0x10);
        if (netId == w->localPeer.intrudeId) {
            w->profileUpdated = 1;
        }
    }
}

int INTRUDE_CMD_SendProfile(IntrudeCommSys *w)
{
    void *profile;

    profile = GAME_DATA_GetLastBattleRecSlot(GAME_COMM_GetGameData(w->gameComm));
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x21c, 0x10, profile);
}

void INTRUDE_CMD_RecvTallyWord(int netId, int size, void *data, IntrudeCommSys *w)
{
    MI_CpuCopy8(data, &w->partnerTally, 4);
}

int INTRUDE_COMM_SendTally(IntrudeCommSys *work)
{
    GAME_COMM_GetGameData(work->gameComm);
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x21d, 4, &work->ownTally);
}

void INTRUDE_COMM_RecvBusyBegin(int netId, int size, void *data, IntrudeCommSys *work)
{
    work->busyCount++;
    if (work->busyLock == 0) {
        GFL_NET_SetAcceptConnection((GFL_NET_HANDLE_GetCurrentHandle()), 0);
        NET_WHPIPE_SetBeaconStatus(1);
    }
}

u32 INTRUDE_COMM_SendBusyBegin(void)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0, 0x21e, 0, 0, 0, 0, 0);
}

void INTRUDE_COMM_RecvBusyEnd(int netId, int size, void *data, IntrudeCommSys *work)
{
    work->busyCount--;
    if (work->busyCount == 0 && work->busyLock == 0) {
        GFL_NET_SetAcceptConnection((GFL_NET_HANDLE_GetCurrentHandle()), (void *)1);
        NET_WHPIPE_SetBeaconStatus(0);
    }
}

u32 INTRUDE_COMM_SendBusyEnd(void)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0, 0x21f, 0, 0, 0, 0, 0);
}

/*
 * extent: existing follower INTRUDE_COMM_SendPeerFlags.c stays separate.
 */
void INTRUDE_COMM_RecvPeerFlags(int netId, int size, u8 *flags, IntrudeCommSys *work)
{
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())) {
        work->peerFlags |= *flags;
    }
}

/*
 * Handed as 0x021744D2; the function starts at the push {r0-r3} at 0x021744D0.
 */
int INTRUDE_COMM_SendPeerFlags(struct IntrudeCommSys *unused, u8 netId, int flags, ...)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), netId, 0x220, 1, &flags, 0, 0, 0);
}

void INTRUDE_COMM_RecvSupportMode(int netId, int size, int *mode, IntrudeCommSys *work)
{
    struct GameData *gameData;
    struct CommPlayerSupport *support;
    int supportState;
    gameData = GAME_COMM_GetGameData(work->gameComm);
    support = GAME_DATA_GetPmsWork(gameData);
    if (work->peerMask & (1 << netId)) {
        if (FIELD_STATUS_GetSeasonDispFlag(GAME_DATA_GetMoveModelSys((const struct GameData *)gameData)) == 1) {
            supportState = COMM_PLAYER_SUPPORT_GetMode(support);
            if (supportState == 0 || supportState == 3) {
                COMM_PLAYER_SUPPORT_SetModeAndCurrent(support, *mode, GAME_DATA_GetMyStatusPlayer(gameData, netId));
            }
        }
    }
}

/*
 * Handed as 0x0217456E; the function starts at the push {r0-r3} at 0x0217456C.
 */
int INTRUDE_COMM_SendSupportMode(struct IntrudeCommSys *unused, u8 netId, int mode, ...)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), netId, 0x221, 4, &mode, 0, 0, 0);
}

void INTRUDE_COMM_RecvProfile(int netId, int size, void *profile, IntrudeCommSys *work)
{
    GAME_COMM_GetGameData(work->gameComm);
    if ((work->peerMask & (1 << netId)) && work->profilePending == 0) {
        MI_CpuCopy8(profile, &work->profile, 0x14);
        work->profilePending = 1;
    }
}

int INTRUDE_COMM_SendProfile(u8 netId, const void *profile)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), netId, 0x222, 0x14, (void *)profile, 0, 0, 0);
}

/*
 * extent: existing follower INTRUDE_COMM_SendPairMessage.c stays separate.
 */
void INTRUDE_COMM_RecvPairMessage(int netId, int size, u8 *message, IntrudeCommSys *work)
{
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle()) && (work->peerMask & (1 << netId))) {
        GAME_COMM_PushPairMessage((struct GameComm *)work->gameComm, netId, *message);
    }
}

/*
 * Handed as 0x02174662; the function starts at the push {r0-r3} at 0x02174660.
 */
int INTRUDE_COMM_SendPairMessage(int message, ...)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x223, 1, &message);
}

void INTRUDE_COMM_RecvUnionInfoRequest(int netId, int size, int data, IntrudeCommSys *work)
{
    work->unionInfoRequestMask |= (u8)(1 << netId);
}

int INTRUDE_COMM_SendUnionInfoRequest(IntrudeCommSys *work, u8 netId)
{
    int sent;
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    sent = GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), netId, 0x224, 0, 0, 0, 0, 0);
    if (sent == 1) {
        work->unionInfoReceived = 0;
    }
    return sent;
}

void INTRUDE_COMM_RecvUnionInfo(int netId, int size, void *info, IntrudeCommSys *work)
{
    struct GameData *gameData;
    sptr unionInfo;
    gameData = GAME_COMM_GetGameData(work->gameComm);
    unionInfo = (sptr)(struct GameData *)GAME_DATA_GetUnionInfo((struct GameData *)gameData, 0);
    FIELD_WFBC_DATA_LOCAL_Sanitize(info, GAME_DATA_GetMyStatusByNetId((void *)gameData, netId));
    MI_CpuCopy8(info, (void *)unionInfo, 0x1E8);
    GAME_DATA_TakeUnionInfo((struct GameData *)gameData, info);
    work->unionInfoReceived = 1;
}

int INTRUDE_COMM_SendUnionInfo(IntrudeCommSys *work, int netMask, void *info)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    if (GFL_NET_IsSendQueueEntryOfHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x225) == 1) {
        return 0;
    }
    MI_CpuCopy8(info, work->unionInfoBuffer, 0x1E8);
    return GFL_NET_SendDataMask(GFL_NET_HANDLE_GetCurrentHandle(), netMask & 0xFF, 0x225, 0x1E8, info, 0, 0, 1);
}

void INTRUDE_COMM_RecvReturnResult(int netId, int size, int result, IntrudeCommSys *work)
{
    EVENT_FIELD_PROCLINK_SetReturnSlotDefaultIfOffline((struct EventSlots *)work->returnSlots, (struct EventSlot *)result);
}

int INTRUDE_COMM_SendReturnResult(void *result, u8 netId)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), netId, 0x226, 8, result, 0, 0, 0);
}

void INTRUDE_COMM_RecvReturnPending(int netId, int size, int data, IntrudeCommSys *work)
{
    EVENT_FIELD_PROCLINK_SetReturnSlotIfOffline((struct EventSlots *)work->returnSlots, (u16)netId, (void *)data);
}

int INTRUDE_COMM_SendReturnPending(const void *pending, u8 netId)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), netId, 0x227, 8, (void *)pending, 0, 0, 0);
}

/*
 * Stores the page request of the sender (a 4-byte struct copy: both byte
 * pairs load before their stores).
 */
void INTRUDE_COMM_RecvPageRequest(int netId, int size, const IntrudePageRequest *request, IntrudeCommSys *work)
{
    work->pageRequests[netId] = *request;
}

int INTRUDE_COMM_SendPageRequest(IntrudeCommSys *work, u8 netId, const void *request)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    work->pageReceived = 0;
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), netId, 0x228, 4, (void *)request, 0, 0, 0);
}

void INTRUDE_COMM_RecvSymbolPage(int netId, int size, IntrudeSymbolPage *page, IntrudeCommSys *work)
{
    work->peerSymbolPage = *page;
    work->pageReceived = 1;
    work->areaNoticeSeen = 0;
}

int INTRUDE_COMM_SendSymbolPage(IntrudeCommSys *work, u8 netId)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), netId, 0x229, 0x54, &work->ownSymbolPage, 0, 0, 0);
}

void INTRUDE_COMM_RecvAreaNotice(int netId, int size, int data, IntrudeCommSys *work)
{
    struct GameData *gameData;
    gameData = GAME_COMM_GetGameData(work->gameComm);
    if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle()) && work->localPeer.intrudeId == netId) {
        if (ZONEDATA_IsZoneGroup118To120(GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork((struct GameData *)gameData))) != 0) {
            work->areaNoticeSeen = 1;
        }
    }
}

/*
 * lever: caller consumes the live r0 result of legacy void forwarders.
 */
u32 INTRUDE_COMM_SendAreaNotice(const void *notice)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x22a, 4, notice);
}

/*
 * Addresses are Black-image addresses.
 */
void INTRUDE_COMM_UpdateRunning(IntrudeCommSys *work)
{
    struct GameData *gameData;
    int connected;
    void *profileSys;
    gameData = GAME_COMM_GetGameData(work->gameComm);
    if (GFL_NET_IsParentAid() == 1) {
        connected = GFL_NET_GetNegotiationNum();
        if (connected > work->memberCount) {
            work->memberCount = connected;
            work->memberCountDirty = 1;
            GAME_DATA_SetEnterMode((struct GameData *)gameData, work->memberCount);
        }
    }
    if (work->memberCountDirty == 1 && INTRUDE_COMM_SendMemberCount(work, work->memberCount) == 1) {
        work->memberCountDirty = 0;
    }
    INTRUDE_COMM_UpdateSeasonState(work);
    INTRUDE_COMM_UpdateRequest(work);
    if (work->resendRequested == 1) {
        INTRUDE_COMM_RefreshSelfRecord(work);
        INTRUDE_COMM_SendStatusRecord(work);
    }
    INTRUDE_COMM_UpdateMemberJoin(work);
    INTRUDE_COMM_UpdateMemberLeave(work);
    INTRUDE_COMM_UpdatePendingNotices(work);
    if (work->tallyPending == 1 && INTRUDE_COMM_SendTally(work) == 1) {
        work->tallyPending = 0;
    }
    INTRUDE_COMM_UpdateSession(work, &work->session);
    if (work->resultUpdated == 1 && INTRUDE_CMD_SendProfile(work) == 1) {
        work->resultUpdated = 0;
    }
    INTRUDE_COMM_UpdateUnionInfoAndReturnSlots(work);
    INTRUDE_COMM_UpdatePageRequests(work);
    INTRUDE_COMM_SendSaveSummaryToReadyPeers(work);
    if (INTRUDE_COMM_UpdateSelfRecord(work) == 1) {
        work->peerStatusDirty = 1;
    }
    if (work->peerStatusDirty == 1 && work->suspended == 0 && INTRUDE_COMM_SendPeerStatus(work, &work->localPeer) == 1) {
        work->peerStatusDirty = 0;
    }
    if (GAME_DATA_IsSaving((struct GameData *)gameData) == 0 && work->profilePending == 1) {
        profileSys = INTRUDE_GetFromSave(GAME_DATA_GetSaveControl((struct GameData *)gameData));
        if (INTRUDE_COMM_IsValidProfileCode(work->profile.code) == 0) {
            work->profile.code = 0x11;
        }
        INTRUDE_AddLogEntry(profileSys, (struct IntrudeLogEntry *)&work->profile);
        work->profilePending = 0;
    }
}

void INTRUDE_COMM_UpdateSeasonState(IntrudeCommSys *work)
{
    int mode;
    mode = FIELD_STATUS_GetSeasonDispFlag((struct FieldStatus *)GAME_DATA_GetMoveModelSys((const struct GameData *)GAME_COMM_GetGameData(work->gameComm)));
    switch (mode) {
    case 0:
        if (work->localPeer.state == 2) {
            INTRUDE_COMM_SetState(work, 0);
        }
        break;
    case 1:
        if (work->localPeer.state == 0) {
            INTRUDE_COMM_SetState(work, 2);
        }
        break;
    }
}

void INTRUDE_COMM_UpdateMemberJoin(IntrudeCommSys *work)
{
    int i;
    if (work->joinRetryWait != 0) {
        work->joinRetryWait--;
        return;
    }
    for (i = 0; i < work->memberCount; i++) {
        if ((int)GFL_NET_IsConnectMember((unsigned char)i) == 1 && !(work->peerMask & (1 << i))) {
            INTRUDE_COMM_SendRecordRequest();
            work->joinRetryWait = 30;
            return;
        }
    }
}

void INTRUDE_COMM_UpdateMemberLeave(IntrudeCommSys *work)
{
    int i;
    if (GFL_NET_IsParentAid() != 0) {
        for (i = 0; i < work->memberCount; i++) {
            if ((int)GFL_NET_IsConnectMember((unsigned char)i) == 0 && (work->peerMask & (1 << i))) {
                INTRUDE_COMM_SendPeerLeft(work, i);
            }
        }
    }
}

void INTRUDE_COMM_UpdatePendingNotices(IntrudeCommSys *work)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (work->busyReplies[i] != 0) {
            if ((int)GFL_NET_IsConnectMember((unsigned char)i) == 1) {
                if (INTRUDE_COMM_SendReply(work, i, 2, work->busyReplies[i]) == 1) {
                    work->busyReplies[i] = 0;
                }
            } else {
                work->busyReplies[i] = 0;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (work->pendingReplies[i] != 0) {
            if ((int)GFL_NET_IsConnectMember((unsigned char)i) == 1) {
                if (INTRUDE_COMM_SendNotice(work, i, work->pendingReplies[i]) == 1) {
                    work->pendingReplies[i] = 0;
                }
            } else {
                work->pendingReplies[i] = 0;
            }
        }
    }
}

/*
 * GAME_COMM_GetGameData returns the argument consumed by GAME_DATA_GetSecondUnionInfo.
 */
void INTRUDE_COMM_UpdateUnionInfoAndReturnSlots(IntrudeCommSys *work)
{
    int result[2];
    int pending[2];
    unsigned char i;
    struct GameData *gameData;
    gameData = GAME_COMM_GetGameData(work->gameComm);
    if (work->unionInfoRequestMask != 0) {
        if (INTRUDE_COMM_SendUnionInfo(work, work->unionInfoRequestMask, (void *)GAME_DATA_GetSecondUnionInfo((void *)gameData)) == 1) {
            work->unionInfoRequestMask = 0;
        }
    }
    for (i = 0; i < 3; i++) {
        if (EVENT_FIELD_PROCLINK_GetReturnResultSlot((struct EventSlots *)work->returnSlots, i, (struct EventSlot *)result) == 1) {
            if (INTRUDE_COMM_SendReturnResult(result, i) == 1) {
                EVENT_FIELD_PROCLINK_ClearReturnResultSlot((struct EventSlots *)work->returnSlots, i);
            }
        }
    }
    if (EVENT_FIELD_PROCLINK_GetReturnPendingSlot((struct EventSlots *)work->returnSlots, (struct EventSlot *)pending, &i) == 1) {
        if (INTRUDE_COMM_SendReturnPending(pending, i) == 1) {
            EVENT_FIELD_PROCLINK_ClearReturnPendingSlotThunk((struct EventSlots *)work->returnSlots);
        }
    }
}

/*
 * The guard's ldrb lands in r1 because GAME_COMM_GetGameData's result is live in r0:
 * it is GAME_DATA_GetSecondUnionInfo's argument (the r0 at that call is never re-set).
 */
void INTRUDE_COMM_UpdatePageRequests(IntrudeCommSys *work)
{
    unsigned char i;
    IntrudePageRequest *requests;
    struct GameData *gameData;
    gameData = GAME_COMM_GetGameData(work->gameComm);
    if (work->unionInfoRequestMask != 0) {
        if (INTRUDE_COMM_SendUnionInfo(work, work->unionInfoRequestMask, (void *)GAME_DATA_GetSecondUnionInfo((void *)gameData)) == 1) {
            work->unionInfoRequestMask = 0;
        }
    }
    requests = work->pageRequests;
    for (i = 0; i < 3; i++) {
        if (work->pageRequests[i].pending == 1) {
            INTRUDE_COMM_BuildSymbolPage(work, &requests[i]);
            if (INTRUDE_COMM_SendSymbolPage(work, i) == 1) {
                work->pageRequests[i].pending = 0;
            }
        }
    }
    if (work->areaNoticePending == 1) {
        if (INTRUDE_COMM_SendAreaNotice(&work->areaNoticeValue) == 1) {
            work->areaNoticePending = 0;
        }
    }
}

void INTRUDE_COMM_BuildSymbolPage(IntrudeCommSys *work, const IntrudePageRequest *request)
{
    IntrudeSymbolPage *page;
    void *symbolMap;
    int netId;
    u8 count[4];
    page = &work->ownSymbolPage;
    symbolMap = SYMBOL_SAVE_GetBlock(GAME_DATA_GetSaveControl((struct GameData *)GAME_COMM_GetGameData(work->gameComm)));
    SYMBOL_MAP_GetEntryPage((struct Entry32 *)symbolMap, (struct Entry32 *)page->entries, 0x14, request->page, count);
    page->count = count[0];
    page->levelSmall = SYMBOL_MAP_GetSymbolIndex(symbolMap);
    page->levelLarge = SYMBOL_MAP_GetGroup(symbolMap);
    netId = GFL_NET_SYSTEM_GetCurrentAid();
    page->netId = netId;
    page->page = request->page;
}

void INTRUDE_COMM_SendSaveSummaryToReadyPeers(IntrudeCommSys *work)
{
    if (work->readyMask != 0) {
        if (INTRUDE_CMD_SendSaveSummary(work, work->readyMask) == 1) {
            work->readyMask = 0;
        }
    }
}

void INTRUDE_COMM_SetState(IntrudeCommSys *work, int state)
{
    work->localPeer.state = (u16)state;
    work->peerStatusDirty = 1;
}

/*
 * Compares the 3-bit intrudeId with 0x80, which is never true: kept as in
 * the original.
 */
void INTRUDE_COMM_RefreshSelfRecord(IntrudeCommSys *work)
{
    struct GameData *gameData;
    gameData = GAME_COMM_GetGameData(work->gameComm);
    MI_CpuCopy8(GAME_DATA_GetMyStatus((void *)gameData), work->ownStatus.myStatus, MYSTATUS_GetSize());
    MI_CpuCopy8(GAME_DATA_GetLastBattleRecSlot((void *)gameData), work->ownStatus.battleRecSlot, 0x10);
    INTRUDE_COMM_UpdateSelfRecord(work);
    if (work->localPeer.intrudeId == 0x80) {
        INTRUDE_COMM_SetIntrudeId(work, GFL_NET_SYSTEM_GetCurrentAid());
    }
    work->ownStatus.peer = work->localPeer;
}

void INTRUDE_COMM_ApplyPlayerBeacon(IntrudeCommSys *work, int netId, IntrudeStatusRecord *record)
{
    int myStatus;
    struct GameData *gameData;
    sptr status;
    int changed;
    gameData = GAME_COMM_GetGameData(work->gameComm);
    changed = 0;
    status = (sptr)GAME_DATA_GetMyStatusPlayer(gameData, netId);
    if (work->peerMask & (1 << netId)) {
        myStatus = MYSTATUS_GetId((const struct MyStatus *)status);
        if (myStatus == MYSTATUS_GetId((const struct MyStatus *)record->myStatus)) {
            goto skip;
        }
    }
    changed = 1;
skip:
    MYSTATUS_Copy((struct MyStatus *)record->myStatus, (void *)status);
    MI_CpuCopy8(record->battleRecSlot, GAME_DATA_GetBattleRecSlot((struct GameData *)gameData, netId), 0x10);
    GAME_DATA_SetSlotFlag((struct GameData *)gameData, netId, record->peer.season);
    INTRUDE_COMM_StorePlayerRecord(work, netId, &record->peer, 1);
    work->peerMask |= (u8)(1 << netId);
    if (changed == 1 && netId != GFL_NET_SYSTEM_GetCurrentAid()) {
        GAME_COMM_PushPlayerMessage((struct GameComm *)work->gameComm, netId);
    }
}

void INTRUDE_COMM_StorePlayerRecord(IntrudeCommSys *work, int netId, const IntrudePeer *src, int arg)
{
    IntrudePeer *peer;
    u32 vanish;
    peer = &work->peers[netId];
    vanish = peer->package.vanish;
    MI_CpuCopy8(src, peer, 0x1C);
    peer->package.vanish = vanish;
    peer->remoteVanish = (u8)src->package.vanish;
    if (src->package.vanish == 1) {
        peer->package.vanish = 1;
    }
    GAME_COMM_UpdatePlayerStatus(work->gameComm, netId, peer->zoneId, (u8)peer->intrudeId, peer->statusCode, arg);
    if (netId != GFL_NET_SYSTEM_GetCurrentAid()) {
        work->packages[netId] = peer->package;
        INTRUDE_COMM_AdjustRemotePosition(work, work->localPeer.zoneId, work->localPeer.package.pos.x, peer);
    }
    work->dirtyPeerMask |= (u8)(1 << netId);
}

void INTRUDE_COMM_UpdatePlayerObjects(IntrudeCommSys *work)
{
    u8 i;
    if (GAME_DATA_IsSaving((struct GameData *)GAME_COMM_GetGameData(work->gameComm)) == 1) {
        return;
    }
    if (work->suspended == 1) {
        return;
    }
    for (i = 0; i < 3; i++) {
        if (work->dirtyPeerMask & (1 << i)) {
            INTRUDE_COMM_UpdatePlayerObject(work, i);
            work->dirtyPeerMask ^= (u8)(1 << i);
        }
    }
}

/* Returns 1 when the peer has to be hidden from this player's field. */
static inline int ShouldHidePeer(IntrudePeer *peer, IntrudePeer *self)
{
    if (peer->remoteVanish == 1) {
        return 1;
    }
    if (peer->package.dir != 0 && peer->package.dir != 1) {
        return 1;
    }
    if (ZONEDATA_IsEntralink(peer->zoneId) == 1 && ZONEDATA_IsEntralink(self->zoneId) == 1) {
        return 0;
    }
    if (peer->intrudeId == self->intrudeId) {
        if (ZONEDATA_IsZoneGroup118To120(peer->zoneId) == 1 && ZONEDATA_IsZoneGroup118To120(self->zoneId) == 1) {
            if (peer->symbolMapFlag == self->symbolMapFlag) {
                return 0;
            }
            return 1;
        }
        if (ZONEDATA_IsSameMatrixGroup(self->zoneId, peer->zoneId) == 1) {
            return 0;
        }
        return 1;
    }
    return 1;
}

void INTRUDE_COMM_UpdatePlayerObject(IntrudeCommSys *work, int netId)
{
    IntrudePeer *peer;
    int objCode;
    peer = &work->peers[netId];
    if (netId != GFL_NET_SYSTEM_GetCurrentAid()) {
        IntrudePeer *self = &work->localPeer;
        peer->package.vanish = ShouldHidePeer(peer, self);
    }
    if (COMM_PLAYER_CheckOccupy(work->commPlayer, netId) == 1) {
        objCode = INTRUDE_COMM_GetPlayerObjCode(peer, (uptr)GAME_DATA_GetMyStatusByNetId((void *)GAME_COMM_GetGameData(work->gameComm), netId));
        if (objCode != COMM_PLAYER_GetObjCode(work->commPlayer, netId)) {
            COMM_PLAYER_Del(work->commPlayer, netId);
            if (peer->objCode != 0) {
                COMM_PLAYER_Add(work->commPlayer, netId, objCode, (struct CommPlayerPackage *)peer);
            }
        }
    }
}

int INTRUDE_COMM_LookupZonePair(u16 zoneId, IntrudeZonePairInfo *out)
{
    int i;
    u8 side;
    out->zoneId = zoneId;
    for (i = 0; i < 8; i++) {
        if (zoneId == gIntrudeCommZonePairs[i].zoneA) {
            side = 0;
        } else if (zoneId == gIntrudeCommZonePairs[i].zoneB) {
            side = 1;
        } else {
            continue;
        }
        out->side = side;
        out->pairIndex = i;
        return 1;
    }
    out->pairIndex = 0xff;
    return 0;
}

int INTRUDE_COMM_CompareZonePair(IntrudeZonePairInfo *a, IntrudeZonePairInfo *b)
{
    if (a->zoneId == b->zoneId) return 0;
    if (a->side != b->side && a->pairIndex == b->pairIndex) return 1;
    return 2;
}

int INTRUDE_COMM_GetRelativeSlot(IntrudeCommSys *work, int netId)
{
    int slot;
    if (netId >= work->memberCount) return 0;
    slot = netId - GAME_DATA_GetOwnNetId((const struct GameData *)GAME_COMM_GetGameData(work->gameComm));
    if (slot < 0) slot += work->memberCount;
    return slot;
}

void INTRUDE_COMM_AdjustRemotePosition(IntrudeCommSys *work, u16 zoneId, int selfX, IntrudePeer *peer)
{
    IntrudeZonePairInfo selfPair;
    IntrudeZonePairInfo peerPair;
    int relation;
    int x;
    int slot;
    int count;
    INTRUDE_COMM_LookupZonePair(zoneId, &selfPair);
    INTRUDE_COMM_LookupZonePair(peer->zoneId, &peerPair);
    relation = INTRUDE_COMM_CompareZonePair(&selfPair, &peerPair);
    switch (relation) {
    case 1:
        break;
    case 2:
        break;
    case 0:
        if (ZONEDATA_IsEntralink(zoneId) != 0) {
            x = peer->package.pos.x % 0x400000;
            slot = INTRUDE_COMM_GetRelativeSlot(work, peer->intrudeId);
            count = work->memberCount;
            if (slot == count - 1 && x > 0x200000 && selfX < 0x200000) {
                peer->package.pos.x = x - 0x400000;
            } else if (slot == 0 && x < 0x200000 && selfX > (count << 22) - 0x200000) {
                peer->package.pos.x = x + (count << 22);
            } else {
                peer->package.pos.x = x + (slot << 22);
            }
        }
        break;
    }
}

void INTRUDE_COMM_AdjustAllRemotePositions(IntrudeCommSys *work, int selfX)
{
    IntrudePeer *peers;
    IntrudePeer *self;
    int ownNetId;
    int i;
    IntrudePeer *peer;
    ownNetId = GAME_DATA_GetOwnNetId((const struct GameData *)GAME_COMM_GetGameData(work->gameComm));
    self = &work->localPeer;
    i = 0;
    peers = work->peers;
    for (; i < 3; i++) {
        if ((work->peerMask & (1 << i)) && i != ownNetId) {
            peer = &peers[i];
            peer->package.pos = work->packages[i].pos;
            INTRUDE_COMM_AdjustRemotePosition(work, self->zoneId, selfX, peer);
        }
    }
}

int INTRUDE_COMM_UpdateSelfRecord(IntrudeCommSys *work)
{
    struct GameData *gameData;
    int zoneId;
    int changed;
    int lidClosed;
    IntrudePeer *self;
    gameData = GAME_COMM_GetGameData(work->gameComm);
    zoneId = GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork((struct GameData *)gameData));
    self = &work->localPeer;
    changed = COMM_PLAYER_UpdateMyPackage(work->commPlayer, (struct CommPlayerPackage *)self);
    if (self->zoneId != zoneId) {
        self->zoneId = zoneId;
        changed = 1;
    }
    if (self->symbolMapFlag != GAME_DATA_GetSymbolMapFlag(gameData)) {
        self->symbolMapFlag = GAME_DATA_GetSymbolMapFlag(gameData);
        changed = 1;
    }
    lidClosed = (*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15;
    if (self->lidClosed != lidClosed) {
        self->lidClosed = lidClosed;
        changed = 1;
    }
    return changed;
}

/*
 * Unlabelled Thumb leaf, seeded so that ov018 EVENT_COMM_COMMON_ExitCommonWork has a witness:
 * clears the notice bytes.
 */
void INTRUDE_COMM_ClearNotice(IntrudeCommSys *work)
{
    MI_CpuFill8(&work->notice, 0, 4);
}

/*
 * Unlabelled Thumb leaf, the follower of INTRUDE_COMM_ClearNotice: returns the notice
 * bytes when the first one is 1, else null. Labelled so that
 * INTRUDE_COMM_ClearNotice's extent ends at its own pool.
 */
unsigned char *INTRUDE_COMM_GetNotice(IntrudeCommSys *work)
{
    if (work->notice.value[0] == 1) {
        return work->notice.value;
    }
    return 0;
}

/*
 * extent: two zero alignment bytes at 0x021753B6 precede the owned 021753B8 function.
 */
void INTRUDE_COMM_InitRequest(IntrudeCommSys *work, int target)
{
    MI_CpuFill8(&work->requestTarget, 0, 8);
    work->requestTarget = target;
    work->replyFrom = 4;
    work->sentRequestSeq = 0;
    INTRUDE_COMM_NextRequestToken(work);
}

void INTRUDE_COMM_NextRequestToken(IntrudeCommSys *work)
{
    work->nextRequestSeq++;
    work->expectedReplySeq = work->nextRequestSeq;
}

int INTRUDE_COMM_TryStartRequest(IntrudeCommSys *work, int netId, u8 seq)
{
    if (!(work->peerMask & (1 << netId))) {
        work->busyReplies[netId] = seq;
        return 0;
    }
    if (work->localPeer.state == 0) {
        if (work->requestTarget == 4 && work->sentRequestSeq == 0 && GAMESYSTEM_IsEventActive(work->gameSystem) == 0) {
            work->requestTarget = netId;
            work->requestActive = 1;
            work->sentRequestSeq = seq;
            work->expectedReplySeq = seq;
            INTRUDE_COMM_SetRequestOpen(work);
            return 1;
        }
        work->busyReplies[netId] = seq;
    } else {
        work->busyReplies[netId] = seq;
    }
    return 0;
}

void INTRUDE_COMM_SetRequestOpen(IntrudeCommSys *work)
{
    work->requestOpen = 1;
}

/*
 * lever: bitfield clear emits bics; byte mask emits ands with 0xEF.
 */
void INTRUDE_COMM_ClearRequestOpen(IntrudeCommSys *work)
{
    work->requestOpen = 0;
}

void INTRUDE_COMM_UpdateRequest(IntrudeCommSys *work)
{
    u8 target[4];
    u8 *replies;
    int netId;
    if (INTRUDE_COMM_GetActiveRequestTarget(work, (int *)target) == 1 && GAMESYSTEM_IsEventActive(work->gameSystem) == 1) {
        replies = work->busyReplies;
        netId = work->requestTarget;
        if (replies[netId] == 0) {
            replies[netId] = work->sentRequestSeq;
        }
        INTRUDE_COMM_InitRequest(work, 4);
        INTRUDE_COMM_ClearRequestOpen(work);
    }
}

int INTRUDE_COMM_GetActiveRequestTarget(IntrudeCommSys *work, int *target)
{
    int netId;
    if (work == 0 || work->commPlayer == 0) return 0;
    netId = work->requestTarget;
    if (netId != 4 && work->requestOpen == 1) {
        *target = netId;
        return 1;
    }
    return 0;
}

void INTRUDE_COMM_SetRequestResult(IntrudeCommSys *work, int netId, int result, int seq)
{
    if (work->requestTarget == netId && work->sentRequestSeq == seq) {
        work->replyFrom = netId;
        work->replyResult = result;
    }
}

void INTRUDE_COMM_SetRequestResultAccepted(IntrudeCommSys *work, int netId, int seq)
{
    INTRUDE_COMM_SetRequestResult(work, netId, 3, seq);
}

/*
 * note:     unlabelled leaf (push {r3,r4}, no lr); callers EVENT_COMM_COMMON_BattleRequestEventMain and
 *           EVENT_COMM_COMMON_BattleAnswerEventMain in ov018. Its follower 0x0217553C is also an
 *           unlabelled leaf.
 */
int INTRUDE_COMM_TakeRequestResult(IntrudeCommSys *work)
{
    int result;
    if (work->replyFrom != 4) {
        result = work->replyResult;
        if (result != 0) {
            work->replyResult = 0;
            return result;
        }
    }
    return 0;
}

/*
 * Unlabelled leaf (no lr save): clears the reply result.
 */
void INTRUDE_COMM_ClearRequestResult(IntrudeCommSys *work)
{
    work->replyResult = 0;
}

void INTRUDE_COMM_PickDefaultObjCode(u32 myStatus, u16 *objCode, u8 *form, u8 *sex)
{
    u32 trainerId;
    u32 index;
    int female;
    trainerId = MYSTATUS_GetId((const struct MyStatus *)myStatus);
    female = MYSTATUS_GetSex((const struct MyStatus *)myStatus);
    index = ((trainerId >> 16) + (u16)trainerId) & 3;
    if (female == 0) {
        *objCode = gIntrudeCommObjCodesMale[index];
        *form = 3;
        *sex = 0;
    } else {
        *objCode = gIntrudeCommObjCodesFemale[index];
        *form = 4;
        *sex = 1;
    }
}

u16 INTRUDE_COMM_GetPlayerObjCode(IntrudePeer *peer, u32 myStatus)
{
    struct { u8 sex; u8 form; u16 objCode; } pick;
    u16 objCode;
    objCode = peer->objCode;
    if (objCode == 0) {
        if (peer->package.dir == 1) {
            pick.objCode = (MYSTATUS_GetSex((const struct MyStatus *)myStatus) == 0) ? 2 : 5;
        } else {
            pick.objCode = (MYSTATUS_GetSex((const struct MyStatus *)myStatus) == 0) ? 1 : 4;
        }
    } else if (objCode == 0xFFFF) {
        INTRUDE_COMM_PickDefaultObjCode(myStatus, &pick.objCode, &pick.form, &pick.sex);
    } else {
        pick.objCode = objCode;
        if (INTRUDE_COMM_IsValidObjCode(pick.objCode) == 0) {
            pick.objCode = (MYSTATUS_GetSex((const struct MyStatus *)myStatus) == 0) ? 10 : 14;
        }
    }
    if ((pick.objCode >= 0xdf && pick.objCode < 0x1000) || pick.objCode >= 0x1236) {
        pick.objCode = 10;
    }
    return pick.objCode;
}

/*
 * extent: two zero alignment bytes at 0x02175646 precede existing 02175648 code.
 */
int INTRUDE_COMM_HasConnectedPeers(void)
{
    if (GFL_NET_ERR_GetErrorLevel() != 0) return 0;
    if (GFL_NET_GetNegotiationNum() > 1) return 1;
    return 0;
}

void INTRUDE_COMM_BuildLocalProfile(void *saveData, IntrudeProfileData *profile)
{
    void *profileSys;
    profileSys = INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(saveData));
    MI_CpuFill8(profile, 0, 0x10);
    profile->kind = INTRUDE_GetMissionClearCount(profileSys);
    if (GAME_DATA_GetIntrudeCount(saveData) == 1) {
        profile->value = INTRUDE_UpdatePlaySeconds(profileSys, (void *)GAME_DATA_GetPlayTime((struct GameData *)saveData), 2);
    } else {
        profile->value = INTRUDE_GetPlaySeconds(profileSys);
    }
    INTRUDE_GetObtainedFlags(profileSys, profile->extra, 2);
    profile->valid = 1;
}

u8 INTRUDE_COMM_GetPartnerTallyValid(IntrudeCommSys *work)
{
    return work->partnerTally.valid;
}

/*
 * A ternary loop condition keeps the unrotated entry branch.
 */
int INTRUDE_COMM_IsValidObjCode(int objCode)
{
    unsigned int i;
    for (i = 0; (i < 162) ? 1 : 0; i++) if (objCode == gIntrudeCommValidObjCodes[i]) return 1;
    return 0;
}

/*
 * The 32-byte follower at 021756F0 already has its own matched shard.
 * A ternary loop condition preserves the branch to the bottom test.
 */
int INTRUDE_COMM_IsValidProfileCode(u32 code)
{
    u32 i;
    for (i = 0; (i < 0x1c) ? 1 : 0; i++) {
        if (code == gIntrudeCommValidProfileCodes[i]) {
            return 1;
        }
    }
    return 0;
}

/*
 * Unlabelled leaf: sets the lock bit from the low bit of value.
 */
void INTRUDE_COMM_SetLock(IntrudeCommSys *work, u32 value)
{
    work->lock = (u8)value;
}

/*
 * INTRUDE_COMM_SetSuspended is an unlabelled leaf (the suspended bit).
 */
void INTRUDE_COMM_SetIntrudeId(IntrudeCommSys *work, u32 intrudeId)
{
    void *gameData;
    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    work->localPeer.intrudeId = intrudeId;
    GAME_DATA_SetIntrudeId(gameData, intrudeId);
    EVENT_FIELD_PROCLINK_SetReturnLinkId((struct EventSlots *)work->returnSlots, (u8)intrudeId);
}

void INTRUDE_COMM_SetSuspended(IntrudeCommSys *work, u32 value)
{
    work->suspended = (u8)value;
}

void INTRUDE_COMM_InitSession(IntrudeSession *session)
{
    int i;
    MI_CpuFill8(session, 0, 0x1A8);
    session->request.netId = 4;
    INTRUDE_COMM_ResetMemberName(&session->request.name);
    session->result.record.netId = 4;
    for (i = 0; i < 3; i++) session->result.partnerIds[i] = 4;
    INTRUDE_COMM_ClearSessionEntries(session);
}

/*
 * extent: two zero alignment bytes at 0x021757C2 precede existing 021757C4 code.
 */
void INTRUDE_COMM_ClearSessionEntries(IntrudeSession *session)
{
    int i;
    for (i = 0; i < 3; i++) session->members[i].filled = 0;
}

void INTRUDE_COMM_UpdateSession(IntrudeCommSys *work, IntrudeSession *session)
{
    struct GameData *gameData;

    if (GFL_NET_IsParentAid() == 1 && INTRUDE_COMM_IsSessionActive(session) == 1) {
        if (session->result.record.netId == 4) {
            if (session->request.ticksLeft != 0) {
                if (session->resultReported == 0 && INTRUDE_COMM_GetSessionElapsed(session) > session->request.ticksLeft) {
                    session->resultReported = 1;
                }
            } else if (session->timeLimitSet == 1 && INTRUDE_COMM_GetSessionElapsed(session) > session->request.amount) {
                gameData = GAME_COMM_GetGameData(work->gameComm);
                if (session->result.confirmed == 0) {
                    INTRUDE_COMM_PromoteRequestToResult(work, session, GAME_DATA_GetOwnNetId((const struct GameData *)gameData));
                }
            }
        } else if (session->timeLimitSet == 1 && INTRUDE_COMM_GetSessionElapsed(session) > session->request.amount) {
            session->leaveFlag = 1;
        }
    }
    INTRUDE_COMM_SendProposalReplies(work, session);
    INTRUDE_COMM_SendPendingReplies(work, session);
    INTRUDE_COMM_UpdateSessionSends(work, session);
    INTRUDE_COMM_UpdateSessionJoinNotices(work, session);
}

int INTRUDE_COMM_GetSessionElapsed(IntrudeSession *session)
{
    u32 now = GF_STANDARD_GetSecondsOfDay();
    u32 start = session->startTick;
    if (now < start) now += 86400;
    return now - start;
}

int INTRUDE_COMM_GetSessionWaitRemaining(IntrudeSession *session)
{
    int limit = session->request.amount;
    int remaining = limit - INTRUDE_COMM_GetSessionElapsed(session);
    if (remaining < 0) remaining = 0;
    return remaining;
}

int INTRUDE_COMM_GetSessionRemaining(IntrudeSession *session)
{
    int ticks;
    int remaining;

    if (INTRUDE_COMM_IsSessionActive(session) == 1 && session->result.record.netId == 4) {
        ticks = session->request.ticksLeft;
        if (ticks != 0 || session->timeLimitSet == 0) {
            remaining = ticks - INTRUDE_COMM_GetSessionElapsed(session);
        } else {
            remaining = INTRUDE_COMM_GetSessionWaitRemaining(session);
        }
        if (remaining < 0) {
            return 0;
        }
        return remaining;
    }
    return 0;
}

/*
 * Three one-byte flag setters.
 */
void INTRUDE_COMM_SetSessionEntrySendFlag(IntrudeSession *session, int index)
{
    session->entrySendPending[index] = 1;
}

void INTRUDE_COMM_SetSessionRequestSendFlag(IntrudeSession *session)
{
    session->requestSendPending = 1;
}

void INTRUDE_COMM_SetSessionResultSendFlag(IntrudeSession *session)
{
    session->resultChanged = 1;
}

/* Copies a received member entry (as 20 halfwords) into a free slot. */
void INTRUDE_COMM_StoreSessionEntry(IntrudeSession *session, const u16 *src, int index)
{
    u16 *dst = session->members[index].name.chars;
    unsigned n;
    if (session->members[index].filled != 1) {
        n = 20;
        do { *dst++ = *src++; } while (--n);
    }
}

int INTRUDE_COMM_StoreSessionRequest(void *unused, IntrudeSession *session, IntrudeMemberRecord *src)
{
    IntrudeMemberRecord *dst;
    int received;

    dst = &session->request;
    received = 0;
    if (src->head.count > 0x14 || src->head.amount > 0xb4) {
        return 0;
    }
    if (session->requestReceived == 0 && src->netId != 4) {
        received = 1;
        session->requestReceived = received;
    }
    if (dst->netId != 4) {
        return received;
    }
    *dst = *src;
    return received;
}

void INTRUDE_COMM_ClearSessionTicks(IntrudeSession *session)
{
    IntrudeMemberRecord *request = INTRUDE_COMM_GetActiveSessionRequest(session);
    if (request != 0) request->ticksLeft = 0;
}

static inline void MarkJoined(IntrudeSession *session, u8 bit)
{
    session->joinedMask |= bit;
    session->joinNoticeMask |= bit;
}

/*
 * lever: u8 mask conversion through MarkJoined inline preserves the original
 * field load before the truncation finishes; open-coded byte locals differ.
 */
void INTRUDE_COMM_AddSessionMember(IntrudeSession *session, u8 netId)
{
    if (session->joinedMask == 0) session->startTick = GF_STANDARD_GetSecondsOfDay();
    MarkJoined(session, 1 << netId);
}

/*
 * extent: follower 0x02175A24 already filed separately.
 */
void INTRUDE_COMM_StartSessionTimer(IntrudeSession *session, int seconds)
{
    session->timeLimitSet = 1;
    session->request.amount = seconds;
    if (GFL_NET_IsParentAid() == 0) session->startTick = GF_STANDARD_GetSecondsOfDay();
}

/*
 * Unlabelled leaf (sole blocker of ov018 INTRUDE_FIELD_EventOfferInfo).
 */
int INTRUDE_COMM_IsSessionTimeLimitSet(IntrudeSession *session)
{
    return session->timeLimitSet;
}

void INTRUDE_COMM_UpdateSessionSends(IntrudeCommSys *work, IntrudeSession *session)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (session->entrySendPending[i] == 1 && INTRUDE_CMD_SendMemberEntry(work, session, i) == 1) {
            session->entrySendPending[i] = 0;
        }
    }
    if (session->requestSendPending == 1 && INTRUDE_CMD_SendGroupRecord(work, session) == 1) {
        session->requestSendPending = 0;
    }
    if (session->resultChanged == 1 && INTRUDE_CMD_SendResultRecord(work, session) == 1) {
        session->resultChanged = 0;
    }
    if (session->resultReported == 1 && INTRUDE_CMD_SendRecordEcho(work, session) == 1) {
        session->resultReported = 2;
    }
    if (session->readyBits[0] != 0 && INTRUDE_CMD_SendEndNotice(session->readyBits[0]) == 1) {
        session->readyBits[0] = 0;
    }
    if (session->readyBits[1] != 0 && INTRUDE_CMD_SendStartNotice(session->readyBits[1]) == 1) {
        session->readyBits[1] = 0;
    }
}

/*
 * prototype: INTRUDE_CMD_SendMemberValue trailing input omitted: full matched body neither
 * reads nor forwards d; original caller supplies no r3 value.
 */
void INTRUDE_COMM_UpdateSessionJoinNotices(IntrudeCommSys *work, IntrudeSession *session)
{
    u8 mask = session->joinNoticeMask;
    if (mask != 0) {
        if (INTRUDE_CMD_SendMemberValue(work, INTRUDE_COMM_GetSessionWaitRemaining(session), mask) == 1) session->joinNoticeMask = 0;
    }
}

int INTRUDE_COMM_IsSessionActive(IntrudeSession *session)
{
    if (session->request.netId == 4 || session->requestReceived == 0) return 0;
    return 1;
}

/*
 * extent: two zero alignment bytes follow the compiled return.
 */
IntrudeMemberRecord *INTRUDE_COMM_GetActiveSessionRequest(IntrudeSession *session)
{
    IntrudeMemberRecord *request;
    if (INTRUDE_COMM_IsSessionActive(session) == 0) request = 0;
    else request = &session->request;
    return request;
}

void INTRUDE_COMM_AcceptSession(IntrudeCommSys *work, IntrudeSession *session)
{
    if (INTRUDE_COMM_IsSessionActive(session) == 1) {
        session->accepted = 1;
        session->finished = 0;
        work->localPeer.eventJoined = 1;
        work->peerStatusDirty = 1;
    }
}

int INTRUDE_COMM_IsSessionAccepted(IntrudeSession *session)
{
    if (INTRUDE_COMM_IsSessionActive(session) == 1) return session->accepted;
    return 0;
}

/*
 * extent: follower 0x02175BBC already filed separately.
 */
void INTRUDE_COMM_SetSessionFinished(IntrudeSession *session)
{
    session->finished = 1;
}

/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as the sole blocker of ov018 INTRUDE_FIELD_TryStartOfferEvent.
 */
int INTRUDE_COMM_IsSessionFinished(IntrudeSession *session)
{
    return session->finished;
}

IntrudeResultRecord *INTRUDE_COMM_GetSessionResult(IntrudeSession *session)
{
    IntrudeResultRecord *result;
    if (INTRUDE_COMM_HasResult(session) == 0) result = 0;
    else result = &session->result;
    return result;
}

/*
 * INTRUDE_COMM_SetSessionReadyBit is an unlabelled leaf (sets one ready bit).
 */
int INTRUDE_COMM_IsSessionAcceptedOrResultReady(IntrudeSession *session)
{
    if (INTRUDE_COMM_IsSessionAccepted(session) == 1 || INTRUDE_COMM_GetSessionResult(session) != 0) {
        return 1;
    }
    return 0;
}

void INTRUDE_COMM_SetSessionReadyBit(IntrudeSession *session, u32 netId)
{
    if (session->result.partnerIds[0] == 4) {
        session->readyBits[0] |= (u8)(1 << netId);
    } else {
        session->readyBits[1] |= (u8)(1 << netId);
    }
}

/* Return the notice state (0 none, 1 start, 2 end) and clear it. */
int INTRUDE_COMM_TakeNoticeState(IntrudeSession *session)
{
    int noticeState;
    noticeState = session->noticeState;
    INTRUDE_COMM_SetNoticeState(session, 0);
    return noticeState;
}

void INTRUDE_COMM_SetNoticeState(IntrudeSession *session, int noticeState)
{
    session->noticeState = noticeState;
}

/* Slot for a new result record: 0 when the result is free (partner 0 is 4), 3 when full. */
int INTRUDE_COMM_FindFreeResultSlot(IntrudeSession *session, IntrudeMemberRecord *record, int netId)
{
    if (session->result.partnerIds[0] == 4) return 0;
    return 3;
}

int INTRUDE_COMM_StoreResultRecord(IntrudeSession *session, IntrudeMemberRecord *record, int netId)
{
    IntrudeResultRecord *result;
    int slot;

    result = &session->result;
    if (GF_STANDARD_CompareBytes((u8 *)&session->request, (u8 *)record, 0x30) != 0) {
        session->replyToSend[netId] = 2;
        return 0;
    }
    slot = INTRUDE_COMM_FindFreeResultSlot(session, record, netId);
    if (slot == 3) {
        session->replyToSend[netId] = 2;
        return 0;
    }
    result->record = *record;
    result->partnerIds[slot] = netId;
    session->replyToSend[netId] = 1;
    session->resultChanged = 1;
    return 1;
}

/*
 * extent: Two alignment bytes at 02175D1E before D20.
 * note: Outer non-one guard returns the original byte, including values beyond boolean.
 */
int INTRUDE_COMM_GetJoinStatus(IntrudeCommSys *w, IntrudeSession *session)
{
    int status;
    status = session->joinStatus;
    if (status == 1) {
        if (INTRUDE_COMM_HasResult(session) == 1 && INTRUDE_COMM_GetPartnerTallyValid(w) == 1) return 1;
        return 0;
    }
    return status;
}

/*
 * extent: store-return follower at 02175D2C, claimed by root for this unit.
 */
void INTRUDE_COMM_ClearJoinStatus(IntrudeSession *session)
{
    session->joinStatus = 0;
}

void INTRUDE_COMM_SetJoinStatus(IntrudeSession *session, int status)
{
    session->joinStatus = status;
}

void INTRUDE_COMM_PromoteRequestToResult(void *unused, IntrudeSession *session, u8 ownNetId)
{
    IntrudeMemberRecord *request;
    IntrudeResultRecord *result;

    request = &session->request;
    result = &session->result;
    if (request->netId != 4 && result->record.netId == 4) {
        result->record = *request;
        result->confirmed = 1;
        session->resultChanged = 1;
        session->resultReported = 0;
    }
}

void INTRUDE_COMM_SetResultRecord(void *unused, IntrudeSession *session, IntrudeResultRecord *result)
{
    session->result = *result;
    session->hasResult = 1;
}

int INTRUDE_COMM_HasResult(IntrudeSession *session)
{
    IntrudeResultRecord *result;
    result = &session->result;
    if (session->hasResult == 1 && result->record.netId != 4) return 1;
    return 0;
}

/* Kind of the current request, or 6 when there is none. */
int INTRUDE_COMM_GetRequestKind(IntrudeSession *session)
{
    if (INTRUDE_COMM_IsSessionActive(session) == 0) return 6;
    return session->request.head.kind;
}

int INTRUDE_COMM_GetResultCount(IntrudeCommSys *w, IntrudeSession *session)
{
    IntrudeResultRecord *result;
    void *saveData;
    int i;

    saveData = GAME_COMM_GetGameData(w->gameComm);
    result = &w->session.result;
    if (result->confirmed == 1) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        if (result->partnerIds[i] == GAME_DATA_GetOwnNetId(saveData)) {
            u32 count = result->record.head.count;
            if (count > 0x14) {
                return 1;
            }
            return count;
        }
    }
    return 0;
}

void INTRUDE_COMM_RecordResultOutcome(void *saveData, IntrudeCommSys *w, IntrudeResultRecord *result)
{
    IntrudeSaveSlot *save;
    u32 statusCode;
    int outcome;
    struct MyStatus *partner;

    save = GAME_DATA_GetLastBattleRecSlot(saveData);
    partner = GAME_DATA_GetMyStatusPlayer(saveData, result->partnerIds[0]);
    statusCode = w->peers[result->partnerIds[0]].statusCode;
    outcome = INTRUDE_COMM_NormalizeVersion((u8)statusCode, MYSTATUS_GetId(partner));
    if (outcome == 0x14) {
        save->outcomes[result->record.head.kind] = 1;
    } else if (outcome == 0x15) {
        save->outcomes[result->record.head.kind] = 2;
    }
}

/*
 * interface: DE4 source declares one argument; original E90 visibly sets r1, preserved here.
 */
int INTRUDE_COMM_HasResultReward(IntrudeCommSys *w, IntrudeSession *session)
{
    if (INTRUDE_COMM_HasResult(session) == 0) return 0;
    if (INTRUDE_COMM_GetResultCount(w, session) > 0) return 1;
    return 0;
}

/*
 * extent: alignment at 02175ED6 then existing filed leaf INTRUDE_COMM_GetLeaveFlag.c.
 * interface: BCC matched caller returns int; body returns original object +0xac or null.
 */
int INTRUDE_COMM_IsResultConfirmed(IntrudeSession *session)
{
    IntrudeResultRecord *result;
    result = INTRUDE_COMM_GetSessionResult(session);
    if (result == 0) return 0;
    if (result->confirmed == 1) return 1;
    return 0;
}

/*
 * Flag getter: bit 4 of the byte at 0x1A5 (the lsls #27 / lsrs #31 pair is
 * a one-bit bitfield read).  A leaf with no lr save, so disasm.py left it as
 * .word data; filed for ov011 INTRUDE_COMM_MainStep, whose only unresolved call
 * site besides arm9 0x02008494 it was.
 */
int INTRUDE_COMM_GetLeaveFlag(IntrudeSession *session)
{
    return session->leaveFlag;
}

/*
 * extent: Two alignment bytes at 02175EFA before EFC.
 */
void INTRUDE_COMM_ResetMemberName(IntrudeMemberName *name)
{
    MI_CpuFill8(name, 0, 0x14);
    name->netId = 4;
}

void INTRUDE_COMM_FillMemberName(IntrudeCommSys *w, IntrudeMemberName *name, u8 netId)
{
    sptr record;
    name->netId = netId;
    record = (sptr)GAME_DATA_GetMyStatusByNetId(GAME_COMM_GetGameData(w->gameComm), name->netId);
    MYSTATUS_CopyNameChars((u16 *)record, (u16 *)name, 8);
    name->gender = MYSTATUS_GetSex((const struct MyStatus *)record);
}

/*
 * note:     the unlabelled 2-instruction leaf at 0x02175FB4 (ldrb r0,[r0,#0x10]; bx lr) follows.
 */
void INTRUDE_COMM_SetMemberEntry(IntrudeCommSys *w, IntrudeSession *session, u32 senderNetId, int memberIndex)
{
    void *saveData;
    IntrudeMemberEntry *entry;
    IntrudeNameChars *name;
    sptr record;
    int gender;
    u8 genderFlag;

    saveData = GAME_COMM_GetGameData(w->gameComm);
    entry = &session->members[memberIndex];
    if (entry->filled != 1) {
        name = (IntrudeNameChars *)GAME_DATA_GetBattleRecSlotByNetId(saveData, memberIndex);
        record = (sptr)GAME_DATA_GetMyStatusByNetId(saveData, memberIndex);
        gender = MYSTATUS_GetRomCode((const struct MyStatus *)record);
        genderFlag = INTRUDE_COMM_NormalizeVersion(gender, MYSTATUS_GetId((const struct MyStatus *)record)) == 0x15;
        entry->name = *name;
        entry->gender = genderFlag;
        entry->senderNetId = senderNetId;
        INTRUDE_COMM_FillMemberName(w, &entry->member, memberIndex);
        entry->filled = 1;
    }
}

int INTRUDE_COMM_GetMemberNameNetId(IntrudeMemberName *name)
{
    return name->netId;
}

/* Check every field of a join request against its limits. */
int INTRUDE_COMM_IsJoinRequestValid(IntrudeSession *session, IntrudeJoinRequest *request)
{
    IntrudeRequestHead *head = &request->head;
    int i;

    if (head->kind >= 6 || head->count > 0x14 || head->amount > 0xb4 || head->areaIndex >= 0x2e
        || head->pointIndex >= 0x53) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        if (head->grades[i] >= 5) return 0;
        if (INTRUDE_COMM_IsValidObjCode(head->ids[i]) == 0) return 0;
    }
    for (i = 0; i < 2; i++) {
        if (head->kind == 3) {
            if (INTRUDE_COMM_IsValidProfileCode(head->param.x) == 0) return 0;
        } else if (head->kind == 4) {
            if (INTRUDE_COMM_IsValidProfileCode(head->param.y) == 0) return 0;
        }
    }
    return 1;
}

int INTRUDE_COMM_ReceiveJoinRequest(IntrudeCommSys *w, IntrudeSession *session, IntrudeJoinRequest *request, int senderNetId)
{
    IntrudeMemberRecord *pending = &session->request;

    MI_CpuFill8(&session->slots[senderNetId], 0, sizeof(IntrudeProposalSlot));
    if (INTRUDE_COMM_IsSessionActive(&w->session) == 1) {
        session->slots[senderNetId].state = 2;
        return 0;
    }
    if (INTRUDE_COMM_IsJoinRequestValid(&w->session, request) == 0) {
        session->slots[senderNetId].state = 2;
        return 0;
    }
    if (request->head.kind == 0 || request->head.kind == 3) {
        if (GFL_NET_SYSTEM_GetConnectNum() != 2 || GFL_NET_GetNegotiationNum() != 2) {
            session->slots[senderNetId].state = 4;
            return 0;
        }
    }
    pending->head = request->head;
    pending->name = request->name;
    pending->netId = senderNetId;
    pending->nameNetId = request->name.netId;
    pending->requestFlag = request->requestFlag;
    pending->ticksLeft = 10;
    pending->amount = request->head.amount;
    session->slots[senderNetId].record = *pending;
    session->slots[senderNetId].state = 1;
    INTRUDE_COMM_SetSessionRequestSendFlag(session);
    session->startTick = GF_STANDARD_GetSecondsOfDay();
    session->resultReported = 0;
    return 1;
}

/*
 * Lever: split the offset arithmetic and the memset pointer calculation.
 * Once-300 permuter found this semantically unchanged spelling at candidate 74.
 * The three-iteration bound proves i stays 0..2; all call inputs are explicit.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`offset = i;` before `offset = i;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
void INTRUDE_COMM_SendProposalReplies(IntrudeCommSys *w, IntrudeSession *session)
{
    unsigned int offset;
    int i;
    u8 *slots;
    for (i = 0; i < 3; i++) {
        do {
            offset = i;
            offset = offset * sizeof(IntrudeProposalSlot);
            if (session->slots[i].state != 0) {
                if (INTRUDE_CMD_SendJoinReply(w, (u8 *)session + 0xe8 + offset, i) == 1) {
                    slots = (u8 *)session + 0xe8;
                    slots = slots + offset;
                    memset(slots, 0, 0x38);
                }
            }
        } while (0);
    }
}

/*
 * note:     an unlabelled leaf follows the pool word, at 0x021761C4.
 */
void INTRUDE_COMM_SendPendingReplies(IntrudeCommSys *w, IntrudeSession *session)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (session->replyToSend[i] != 0 && INTRUDE_CMD_SendProposalReply((sptr)w, session->replyToSend[i], i) == 1) {
            session->replyToSend[i] = 0;
        }
    }
}

void INTRUDE_COMM_StoreJoinReply(IntrudeSession *session, IntrudeJoinReply *reply)
{
    u8 kind = reply->kind;
    session->joinReply = kind;
    if (kind == 1)
        session->request = reply->record;
}

/* Return the join reply kind and clear it. */
u8 INTRUDE_COMM_TakeJoinReply(IntrudeSession *session)
{
    u8 kind;
    kind = session->joinReply;
    INTRUDE_COMM_ClearJoinReply(session);
    return kind;
}

void INTRUDE_COMM_ClearJoinReply(IntrudeSession *session)
{
    session->joinReply = 0;
}

/*
 * extent: two alignment bytes at 0217622E.
 */
int INTRUDE_COMM_IsRequestFromNetId(IntrudeSession *session, int netId)
{
    if (INTRUDE_COMM_IsSessionActive(session) == 0) return 0;
    if (session->request.name.netId == netId) return 1;
    return 0;
}

/*
 * extent: two alignment bytes at 02176256.
 * interface: original +0x1A/+0x1C narrows the full-width call result;
 * the callee's filed u8 return removes this pair (r2: DIFF 9 bytes).
 */
u8 INTRUDE_COMM_GetRequesterNetId(IntrudeCommSys *w, IntrudeSession *session)
{
    if (INTRUDE_COMM_IsSessionActive(session) == 0) {
        return (int)GAME_DATA_GetOwnNetId(GAME_COMM_GetGameData(w->gameComm));
    }
    return session->request.name.netId;
}

/*
 * extent: two alignment bytes at 0217627E.
 */
int INTRUDE_COMM_IsRequestFromSelf(IntrudeCommSys *w)
{
    if (INTRUDE_COMM_IsRequestFromNetId(&w->session, GAME_DATA_GetOwnNetId(GAME_COMM_GetGameData(w->gameComm))) == 1) return 1;
    return 0;
}

void INTRUDE_COMM_SetWordSetPlayerName(struct WordSet *wordSet, u32 slot, const IntrudeNameChars *chars, u32 size, u16 heapId, u32 gender)
{
    struct STRBUF *buffer;

    buffer = (struct STRBUF *)STRBUF_Create(size, heapId);
    STRBUF_SetStringN((struct Strbuf *)buffer, chars->chars, size);
    WORDSET_SetSlotTag(wordSet, slot, (struct Strbuf *)buffer, gender, 1, 2);
    STRBUF_Delete((struct Strbuf *)buffer);
}

void INTRUDE_COMM_SetWordSetMemberName(struct WordSet *wordSet, u32 slot, IntrudeMemberName *name, u16 heapId)
{
    INTRUDE_COMM_SetWordSetPlayerName(wordSet, slot, &name->name, 8, heapId, name->gender);
}

void INTRUDE_COMM_SetWordSetRequest(const IntrudeRequestHead *head, IntrudeMemberName *name, struct WordSet *wordSet, u16 heapId)
{
    int count;

    switch (head->kind) {
    case 0:
        INTRUDE_COMM_SetWordSetMemberName(wordSet, 0, name, heapId);
        WORDSET_SetSlotNumber(wordSet, 1, head->param.x, 3, 0, 1);
        break;
    case 1:
        INTRUDE_COMM_SetWordSetMemberName(wordSet, 0, name, heapId);
        WORDSET_SetSlotFromMsgA0(wordSet, 1, head->param.x);
        break;
    case 2:
        INTRUDE_COMM_SetWordSetMemberName(wordSet, 0, name, heapId);
        WORDSET_SetSlotFromMsgA0(wordSet, 1, head->param.x);
        break;
    case 3: {
        const IntrudeParamPair *param = &head->param;
        INTRUDE_COMM_SetWordSetMemberName(wordSet, 0, name, heapId);
        WORDSET_SetSlotFromMsg36(wordSet, 1, param->x);
        WORDSET_SetSlotNumber(wordSet, 2, param->y, 5, 0, 1);
        break;
    }
    case 4:
        WORDSET_SetSlotFromMsg36(wordSet, 0, head->param.y);
        INTRUDE_COMM_SetWordSetMemberName(wordSet, 1, name, heapId);
        break;
    case 5:
        INTRUDE_COMM_SetWordSetMemberName(wordSet, 0, name, heapId);
        break;
    }
    WORDSET_SetSlotNumber(wordSet, 2, head->amount, 4, 0, 1);
    count = head->count;
    if (count > 20) {
        count = 1;
    }
    WORDSET_SetSlotNumber(wordSet, 3, count, 4, 0, 1);
}

/*
 * Zeroes the six bytes at +6 one at a time, and after each store lets
 * INTRUDE_COMM_PickEntryForKind fill p[key] for key 0..5.  Called from arm9 INTRUDE_InitOccupy
 * (bl at 0x0200BDF2) and from ov011 at 0x0217644C.
 */
void INTRUDE_COMM_ResetOutcomes(IntrudeSaveSlot *save)
{
    int kind;

    for (kind = 0; kind < 6; kind++) {
        save->outcomes[kind] = 0;
        INTRUDE_COMM_PickEntryForKind(save, kind);
    }
}

/* Pick the table row for one kind: the first row of that kind that the points allow. */
void INTRUDE_COMM_PickEntryForKind(IntrudeSaveSlot *save, u32 kind)
{
    int points;
    u32 row;
    u32 level;

    points = save->pointsA + save->pointsB;
    for (row = 0; row < 0xe0; row++) {
        IntrudePickRow *pick = &gIntrudePickTable[row];
        if (kind == pick->kind && pick->minPoints <= points && (pick->flags & PM_VERSION_BIT)) {
            level = pick->level;
            if (level == 100 || level >= GFL_USE_GetRandom(0x65)) {
                save->picks[kind] = row;
                return;
            }
        }
    }
}

/* Count the outcomes of the six kinds; 1 once all are done (the picks are then redrawn). */
int INTRUDE_COMM_TallyOutcomesAndResetIfComplete(IntrudeSaveSlot *save, u8 *doneAsFirst, u8 *doneAsSecond)
{
    int kind;
    for (kind = 0; kind < 6; kind++) {
        if (save->outcomes[kind] == 0) return 0;
        if (save->outcomes[kind] == 1) (*doneAsFirst)++;
        else (*doneAsSecond)++;
    }
    INTRUDE_COMM_ResetOutcomes(save);
    return 1;
}

int INTRUDE_COMM_PartyProcInit(struct Proc *proc, int unused, IntrudePartyParam *param)
{
    IntrudePartyWork *work;
    int memberCount;
    void *list;
    int i;
    int count;

    count = 0;
    work = PROCSYS_AllocProcWork(proc, 0x100, 4);
    MI_CpuFill8(work, 0, 0x100);
    work->asyncTask = PROCSYS_Create(4);
    list = GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData(param->gameSystem));
    POKE_TOOL_HealParty(list);
    memberCount = POKEPARTY_GetCount(list);
    work->party = POKEPARTY_Create(4);
    for (i = 0; i < memberCount; i++) {
        if (count >= param->maxCount) {
            break;
        }
        if (POKEPARTY_IsMemberBattleReady(list, i) == 1) {
            POKEPARTY_Add(work->party, POKEPARTY_GetMember(list, i));
            POKE_TOOL_SetLevelAndRecalc(POKEPARTY_GetMember(work->party, count), param->level);
            count++;
        }
    }
    if (count <= 0) {
        /* both strings are the empty string at 02177010 */
        GF_PANIC_Fail((const char *)d_02177010, 0, (const char *)d_02177010);
    }
    return 1;
}

/*
 * note:     loads overlay 93 (id 0x5D) in state 2 and passes two ov093-resident
 *           data addresses; they carry an ov093 token for that reason.
 */
int INTRUDE_COMM_PartyProcMain(void *proc, int *state, IntrudePartyParam *param, IntrudePartyWork *work)
{
    void *window;
    int busy;

    window = GAMESYSTEM_GetGameData(param->gameSystem);
    GAMESYSTEM_GetGameComm(param->gameSystem);
    busy = PROCSYS_Main(work->asyncTask);
    if (GFL_NET_ERR_GetErrorLevel() != 0 || GFL_NET_IsSessionNull() == 1) {
        if (*state > 0 && *state < 6) {
            *state = 7;
        }
    }
    switch (*state) {
    case 0:
        BTL_SETUP_SetupCommSingle((struct BattleSetupParam *)work, window, (uptr)(GFL_NET_HANDLE_GetCurrentHandle()), 1, 4);
        BTL_SETUP_SetParty((struct BattleSetupParam *)work, work->party, 0);
        if (GFL_NET_SYSTEM_GetCurrentAid() < param->partnerNetId) {
            work->isParent = 0;
        } else {
            work->isParent = 1;
        }
        work->memberLimit = 15;
        work->beaconSize = 0x490;
        work->memberMask = (1 << param->partnerNetId) | (1 << GFL_NET_SYSTEM_GetCurrentAid());
        work->timeoutFrames = 30;
        (*state)++;
        break;
    case 1:
        GFL_NET_HANDLE_SetUserInfo(GFL_NET_HANDLE_GetCurrentHandle(), 0x15, 2, (u16)((1 << param->partnerNetId) | (1 << GFL_NET_SYSTEM_GetCurrentAid())));
        (*state)++;
        break;
    case 2:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x15, 2) == 1) {
            GF_OVERLAY_Load((sptr)ov093_id);
            work->overlayLoaded = 1;
            GFL_NET_COMMAND_AddCommandTable(0x100, d_021F03C4, 9, 0);
            (*state)++;
        }
        break;
    case 3:
        GFL_NET_HANDLE_SetUserInfo(GFL_NET_HANDLE_GetCurrentHandle(), 0x16, 2, (u16)((1 << param->partnerNetId) | (1 << GFL_NET_SYSTEM_GetCurrentAid())));
        (*state)++;
        break;
    case 4:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x16, 2) == 1) {
            (*state)++;
        }
        break;
    case 5:
        PROCSYS_Push(work->asyncTask, -1, (const ProcData *)d_021EFDAC, work);
        (*state)++;
        break;
    case 6:
        if (busy == 0) {
            (*state)++;
        }
        break;
    case 7:
        if (work->overlayLoaded == 1) {
            if (GFL_NET_GetRunState() == 1) {
                GFL_NET_COMMAND_DeleteCommandTable(0x100);
            }
            GF_OVERLAY_Unload((sptr)ov093_id);
        }
        BTL_SETUP_FreeSlots((struct BattleSetupParam *)work);
        return 1;
    }
    return 0;
}

/*
 * extent: two alignment bytes at 021766CA.
 * Exit callback of the link proc (init 02176454, main 02176504, table 02176FCC):
 * deletes the sub proc system, frees the party list and the proc work.
 */
int INTRUDE_LINK_ProcExit(void *procWork, int unused1, int unused2, IntrudeLinkProc *linkProc)
{
    PROCSYS_Delete(linkProc->subProcSys);
    GFL_HEAP_Free(linkProc->partyList);
    PROCSYS_FreeProcWork(procWork);
    return 1;
}

/* Creates the game event step that runs the link proc and stores its two arguments. */
struct GameEvent *INTRUDE_LINK_CreateEvent(struct GameSystem *gameSystem, void *procArg)
{
    struct GameEvent *event;
    IntrudeLinkEventWork *eventWork;
    event = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)INTRUDE_LINK_EventMain, sizeof(IntrudeLinkEventWork));
    eventWork = GAME_EVENT_GetWork(event);
    eventWork->procArg = procArg;
    eventWork->gameSystem = gameSystem;
    return event;
}

/*
 * Lever: case 1 forwards GAMESYSTEM_GetFieldMap's live r0 result into
 * FIELDMAP_GetEncEff(unsigned char *); the matched body reads p + 0x13C.
 * Steps: 0 fade BGM out, 1 field transition, 2 close field, 3 run the link proc,
 * 4 pop BGM fade, 5 open field, 6 wait for sound request, 7 return to field menu.
 */
int INTRUDE_LINK_EventMain(struct GameEvent *event, u32 *state, IntrudeLinkEventWork *eventWork)
{
    struct FieldMap *fieldMap;

    fieldMap = GAMESYSTEM_GetFieldMap(eventWork->gameSystem);
    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(eventWork->gameSystem, 0x490));
        (*state)++;
        break;
    case 1:
        ENCEFF_Start((struct EncEffWork *)FIELDMAP_GetEncEff((struct FieldMap *)fieldMap), (struct GameEvent *)event, 5);
        (*state)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldCloseEvent(eventWork->gameSystem, fieldMap));
        (*state)++;
        break;
    case 3:
        GAME_EVENT_CallProc(event, -1, sIntrudeLinkProcTable, eventWork->procArg);
        (*state)++;
        break;
    case 4:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(eventWork->gameSystem));
        (*state)++;
        break;
    case 5:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(eventWork->gameSystem));
        (*state)++;
        break;
    case 6:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(eventWork->gameSystem));
        (*state)++;
        break;
    case 7:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(eventWork->gameSystem, fieldMap, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    default:
        return 1;
    }
    return 0;
}

/* Returns the link slot of the partner record, or 4 when the record is the local player's. */
u8 INTRUDE_COMM_GetPartnerSlot(void *comm, void *gameData)
{
    u8 localSlot;
    u8 remoteSlot;
    IntrudeCommSys *link;

    localSlot = (int)GAME_DATA_GetOwnNetId(gameData);
    link = (IntrudeCommSys *)INTRUDE_COMM_GetWorkIfRunning((struct GameComm *)comm);
    if (GFL_NET_ERR_GetErrorLevel()) {
        remoteSlot = (int)GAME_DATA_GetIntrudeId(gameData);
        if (remoteSlot == localSlot) {
            return 4;
        }
        return remoteSlot;
    }
    if (link != 0) {
        if (link->localPeer.intrudeId == localSlot) {
            return 4;
        }
        return link->localPeer.intrudeId;
    }
    return 4;
}

/* Writes the marker position template, shifted by the slot distance to the partner (wrapped by player count). */
void INTRUDE_COMM_GetMarkerPosForPartner(struct GameComm *comm, struct GameData *gameData, LinkMarkerPos *outPos)
{
    IntrudeCommSys *link;
    int slotDistance;

    link = (IntrudeCommSys *)INTRUDE_COMM_GetWorkIfRunning((struct GameComm *)comm);
    if (link == 0 || link->localPeer.intrudeId == GAME_DATA_GetOwnNetId(gameData)) {
        slotDistance = 0;
    } else {
        slotDistance = link->localPeer.intrudeId - GAME_DATA_GetOwnNetId(gameData);
        if (slotDistance < 0) {
            slotDistance += link->memberCount;
        }
    }
    *outPos = sLinkMarkerPosTemplate;
    outPos->x += slotDistance << 22;
}

/*
 * extent: followers 02176870 and 02176880 already filed separately.
 * Sends the value to the partner (network command 0x228) tagged as enabled.
 */
int INTRUDE_COMM_RequestPartnerSymbolPage(IntrudeCommSys *linkState, u8 value)
{
    LinkValueMessage message;
    message.value = value;
    message.enabled = 1;
    return INTRUDE_COMM_SendPageRequest(linkState, (u8)linkState->localPeer.intrudeId, &message);
}

/* Returns the pageReceived flag. */
u32 INTRUDE_COMM_IsPartnerSymbolPageReceived(IntrudeCommSys *linkState)
{
    return linkState->pageReceived;
}

/*
 * Returns the received partner record (+0x82C).
 * Filed as the sole blocker of SYMBOL_MAP_GetSelection (ov010).
 */
u8 *INTRUDE_COMM_GetPartnerSymbolPage(IntrudeCommSys *linkState)
{
    return (u8 *)&linkState->peerSymbolPage;
}

/*
 * Stores the value to send and arms the retry flag (areaNoticeValue/areaNoticePending).
 * Recursive MATCH unblocker: callee of SCRCMD_SYMBOL_SendEntryFlag (ov010) at +0032. The
 * address is Thumb code in ov011 (ARM/data in the overlapping ov009), so the
 * matched shard makes that site attest as `matched`.
 */
void INTRUDE_COMM_SetPendingAreaNotice(IntrudeCommSys *linkState, u8 value)
{
    linkState->areaNoticeValue = value;
    linkState->areaNoticePending = 1;
}

/*
 * Consumes the areaNoticeSeen flag (set by the partner's zone report);
 * returns 1 when it was set and the zone is in the special zone group.
 */
int INTRUDE_COMM_ConsumeAreaNoticeSeen(IntrudeCommSys *linkState, int zoneId)
{
    int wasPending = linkState->areaNoticeSeen;
    linkState->areaNoticeSeen = 0;
    if (wasPending == 1) {
        if (ZONEDATA_IsZoneGroup118To120(zoneId) == 1)
            return 1;
    }
    return 0;
}
