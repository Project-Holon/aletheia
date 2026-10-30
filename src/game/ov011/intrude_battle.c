/*
 * file:     intrude_battle.c
 * unit:     yes
 * function: INTRUDE_COMM_PartyProcInit, INTRUDE_COMM_PartyProcMain, INTRUDE_LINK_ProcExit, INTRUDE_LINK_CreateEvent, INTRUDE_LINK_EventMain, INTRUDE_COMM_GetPartnerSlot, INTRUDE_COMM_GetMarkerPosForPartner, INTRUDE_COMM_RequestPartnerSymbolPage, INTRUDE_COMM_IsPartnerSymbolPageReceived, INTRUDE_COMM_GetPartnerSymbolPage, INTRUDE_COMM_SetPendingAreaNotice, INTRUDE_COMM_ConsumeAreaNoticeSeen
 * address:  0x02176454
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
 *   INTRUDE_COMM_SendPageRequest  0x02174854  thumb  ov011
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
extern void GAME_DATA_SetOwnNetId(struct GameData *gd, u32 value);
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
#if LANGUAGE == LANGUAGE_JAPANESE
extern const char str_ja_02176E70[];
extern const char str_ja_02176E84[];
#endif
struct IntrudeCommSys;
extern u8 GAME_DATA_GetIntrudeId(const struct GameData *p);
IntrudeCommSys *INTRUDE_COMM_Create(void *proc, IntrudeCommParam *param);
int INTRUDE_COMM_StartSession(int *state, IntrudeCommParam *param, IntrudeCommSys *work);
void INTRUDE_COMM_MainStep(int *state, IntrudeCommParam *param, IntrudeCommSys *work);
int INTRUDE_COMM_Shutdown(int *state, IntrudeCommParam *param, IntrudeCommSys *work);
int INTRUDE_COMM_Destroy(int unused, void **proc, IntrudeCommSys *work);
void INTRUDE_COMM_ScanCallback(void *whPipe, void *workArg, u16 linkLevel);
void INTRUDE_COMM_SyncPlayers(IntrudeCommSys *work, IntrudeCommSys *peerWork, struct FieldMap *fieldObjectAddr);
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
void INTRUDE_COMM_RecvShutdownRequest(int netId, int size, int data, IntrudeCommSys *work, void *handle);
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
int INTRUDE_CMD_SendProposalReply(IntrudeCommSys *unused, int value, int netId, ...);
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
void INTRUDE_COMM_RecvReturnResult(int netId, int size, void *result, IntrudeCommSys *work);
int INTRUDE_COMM_SendReturnResult(void *result, u8 netId);
void INTRUDE_COMM_RecvReturnPending(int netId, int size, void *data, IntrudeCommSys *work);
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
void INTRUDE_COMM_PickDefaultObjCode(struct MyStatus *myStatus, u16 *objCode, u8 *form, u8 *sex);
u16 INTRUDE_COMM_GetPlayerObjCode(IntrudePeer *peer, struct MyStatus *myStatus);
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
int INTRUDE_LINK_EventMain(struct GameEvent *event, int *state, void *work);
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


/*
 * The 32-byte follower at 021756F0 already has its own matched shard.
 * A ternary loop condition preserves the branch to the bottom test.
 */
#if LANGUAGE == LANGUAGE_JAPANESE
#if LANGUAGE == LANGUAGE_JAPANESE
#define INTRUDE_PROFILE_CODE_COUNT 0x1c
#else
#define INTRUDE_PROFILE_CODE_COUNT 0xa2
#endif
#else
#define INTRUDE_PROFILE_CODE_COUNT 0x1c
#endif


int INTRUDE_COMM_PartyProcInit(struct Proc *proc, int unused, IntrudePartyParam *param)
{
    IntrudePartyWork *work;
    int memberCount;
    void *list;
    int i;
    int count;

    count = 0;
    work = PROCSYS_AllocProcWork(proc, sizeof(*work), 4);
    MI_CpuFill8(work, 0, sizeof(*work));
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
        GF_PANIC_Fail(PM_LANG_JA((const char *)d_02177010, str_ja_02176E70), PM_SRC_LINE(0, 0x76), PM_LANG_JA((const char *)d_02177010, str_ja_02176E84));
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
        BTL_SETUP_SetupCommSingle((struct BattleSetupParam *)work, window, (GFL_NET_HANDLE_GetCurrentHandle()), 1, 4);
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
    event = GAME_EVENT_Create(gameSystem, 0, INTRUDE_LINK_EventMain, sizeof(IntrudeLinkEventWork));
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
int INTRUDE_LINK_EventMain(struct GameEvent *event, int *state, void *workPtr)
{
    IntrudeLinkEventWork *eventWork = workPtr;
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
