/*
 * file:     unit_021743B4.c
 * unit:     yes
 * function: INTRUDE_COMM_SendTally, INTRUDE_COMM_RecvBusyBegin, INTRUDE_COMM_SendBusyBegin, INTRUDE_COMM_RecvBusyEnd, INTRUDE_COMM_SendBusyEnd, INTRUDE_COMM_RecvPeerFlags, func_021744D0, INTRUDE_COMM_RecvSupportMode, func_0217456C, INTRUDE_COMM_RecvProfile, func_021745F8, INTRUDE_COMM_RecvPairMessage, INTRUDE_COMM_SendPairMessage, INTRUDE_COMM_RecvUnionInfoRequest, func_021746AC, INTRUDE_COMM_RecvUnionInfo, INTRUDE_COMM_SendUnionInfo, INTRUDE_COMM_RecvReturnResult, INTRUDE_COMM_SendReturnResult, INTRUDE_COMM_RecvReturnPending, INTRUDE_COMM_SendReturnPending, INTRUDE_COMM_RecvPageRequest, INTRUDE_COMM_SendPageRequest, INTRUDE_COMM_RecvSymbolPage, INTRUDE_COMM_SendSymbolPage, INTRUDE_COMM_RecvAreaNotice, INTRUDE_COMM_SendAreaNotice, func_02174978, INTRUDE_COMM_UpdateSeasonState, INTRUDE_COMM_UpdateMemberJoin, INTRUDE_COMM_UpdateMemberLeave, INTRUDE_COMM_UpdatePendingNotices, INTRUDE_COMM_UpdateUnionInfoAndReturnSlots, INTRUDE_COMM_UpdatePageRequests, INTRUDE_COMM_BuildSymbolPage, INTRUDE_COMM_UpdateQueuedRequest, func_02174E14, INTRUDE_COMM_RefreshSelfRecord, INTRUDE_COMM_ApplyPlayerBeacon, INTRUDE_COMM_StorePlayerRecord, func_02175004, INTRUDE_COMM_UpdatePlayerObject, INTRUDE_COMM_LookupZonePair, INTRUDE_COMM_CompareZonePair, INTRUDE_COMM_GetRelativeSlot, INTRUDE_COMM_AdjustRemotePosition, func_02175274, INTRUDE_COMM_UpdateSelfRecord, func_02175368, func_0217537C, func_0217538C, func_021753B8, INTRUDE_COMM_TryStartRequest, INTRUDE_COMM_SetRequestOpen, func_0217545C, INTRUDE_COMM_UpdateRequest, func_021754B4, INTRUDE_COMM_SetRequestResult, INTRUDE_COMM_SetRequestResultAccepted, func_02175514, func_0217553C, func_02175548, func_02175598, INTRUDE_COMM_HasConnectedPeers, INTRUDE_COMM_BuildLocalProfile, func_021756A4, INTRUDE_COMM_IsValidObjCode, func_021756D0, func_021756F0, func_02175710, func_0217574C, INTRUDE_COMM_InitSession, func_021757A8, INTRUDE_COMM_UpdateSession, INTRUDE_COMM_GetSessionElapsed, INTRUDE_COMM_GetSessionWaitRemaining, func_021758C8, INTRUDE_COMM_SetSessionEntrySendFlag, INTRUDE_COMM_SetSessionRequestSendFlag, INTRUDE_COMM_SetSessionResultSendFlag, INTRUDE_COMM_StoreSessionEntry, INTRUDE_COMM_StoreSessionRequest, INTRUDE_COMM_ClearSessionTicks, INTRUDE_COMM_AddSessionMember, INTRUDE_COMM_StartSessionTimer, func_02175A24, INTRUDE_COMM_UpdateSessionSends, INTRUDE_COMM_UpdateSessionResult, func_02175B14, func_02175B34, func_02175B4C, func_02175B8C, INTRUDE_COMM_SetSessionFinished, func_02175BBC, func_02175BCC, func_02175BE4
 * address:  0x021743B4
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
 *   func_02026478 0x02026478 thumb
 *   INTRUDE_COMM_IsLinked 0x021736D8 thumb ov011
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_0203D1E8 0x0203D1E8 arm
 *   NET_WHPIPE_SetBeaconStatus 0x021780FC thumb ov014
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02012F20  0x02012F20  thumb
 *   func_02012B38  0x02012B38  thumb
 *   FIELD_STATUS_GetSeasonDispFlag  0x02014484  thumb
 *   COMM_PLAYER_SUPPORT_GetMode  0x0202E7E0  thumb
 *   func_02012950  0x02012950  thumb
 *   COMM_PLAYER_SUPPORT_SetModeAndCurrent  0x0202E7C4  thumb
 *   func_02082D44  0x02082D44  arm
 *   GAME_COMM_PushPairMessage 0x020266AC thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_021583EC  0x021583EC  thumb ov010
 *   func_021861F4  0x021861F4  thumb ov020
 *   GAME_DATA_TakeUnionInfo  0x02012800  thumb
 *   GFL_NET_IsSendQueueEntryOfHandle  0x0203D578  arm
 *   func_0203D4D0  0x0203D4D0  arm
 *   func_02161FF0  0x02161FF0  thumb ov010
 *   func_02162008  0x02162008  thumb ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D9C  0x02013D9C  thumb
 *   func_0203D378  0x0203D378  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02012B4C  0x02012B4C  thumb
 *   INTRUDE_COMM_SendMemberCount  0x02173758  thumb  ov011
 *   INTRUDE_COMM_SendStatusRecord  0x02173828  thumb  ov011
 *   INTRUDE_CMD_SendProfile  0x02174374  thumb  ov011
 *   INTRUDE_COMM_SendPeerStatus  0x02173984  thumb  ov011
 *   func_02012E40  0x02012E40  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_0200BE84  0x0200BE84  thumb
 *   func_0203D1C0  0x0203D1C0  arm
 *   INTRUDE_COMM_SendRecordRequest  0x021737A8  thumb ov011
 *   INTRUDE_COMM_SendPeerLeft  0x021738E4  thumb ov011
 *   func_02173AE0  0x02173AE0  thumb ov011
 *   INTRUDE_COMM_SendNotice  0x02173B44  thumb ov011
 *   func_020127C4 0x020127C4 thumb
 *   func_02162024 0x02162024 thumb ov010
 *   func_02162038 0x02162038 thumb ov010
 *   func_0216202C 0x0216202C thumb ov010
 *   func_02162040 0x02162040 thumb ov010
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_0216749C  0x0216749C  thumb ov010
 *   func_021673C4  0x021673C4  thumb ov010
 *   func_021673A8  0x021673A8  thumb ov010
 *   func_02039338  0x02039338  arm
 *   INTRUDE_CMD_SendSaveSummary 0x02173CB0 thumb ov011
 *   func_02012944  0x02012944  thumb
 *   func_02008468  0x02008468  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_02008530  0x02008530  thumb
 *   func_02008494  0x02008494  thumb
 *   func_020127AC  0x020127AC  thumb
 *   GAME_DATA_SetSlotFlag  0x02012BA4  thumb
 *   GAME_COMM_PushPlayerMessage  0x020266D4  thumb
 *   GAME_COMM_UpdatePlayerStatus  0x020264B4  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   ZONEDATA_IsSameMatrixGroup  0x02013E90  thumb
 *   func_021677E4  0x021677E4  thumb  ov010
 *   func_02167810  0x02167810  thumb  ov010
 *   func_02167658  0x02167658  thumb  ov010
 *   func_021675D0  0x021675D0  thumb  ov010
 *   d_02176AA0  0x02176AA0  data ov011 a2
 *   func_02012B58 0x02012B58 thumb
 *   func_0216786C  0x0216786C  thumb ov010
 *   func_02012FB0  0x02012FB0  thumb
 *   sub_02082BCC  0x02082BCC  arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020120D8  0x020120D8  thumb
 *   func_02008550  0x02008550  thumb
 *   gIntrudeCommObjCodesMale   0x02176A90  data  ov011  a2
 *   gIntrudeCommObjCodesFemale   0x02176A98  data  ov011  a2
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200BF70  0x0200BF70  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02012FCC  0x02012FCC  thumb
 *   func_0200BFA4  0x0200BFA4  thumb
 *   func_0200BF94  0x0200BF94  thumb
 *   func_0200BF54  0x0200BF54  thumb
 *   gIntrudeCommValidObjCodes 0x02176B08 data ov011 a2
 *   gIntrudeCommValidProfileCodes 0x02176AD0 data ov011 a2
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B8C  0x02012B8C  thumb
 *   func_02161FEC  0x02161FEC  thumb  ov010
 *   INTRUDE_COMM_ResetMemberName 0x02175EE8 thumb ov011
 *   INTRUDE_COMM_PromoteRequestToResult  0x02175D34  thumb  ov011
 *   INTRUDE_COMM_SendProposalReplies  0x02176158  thumb  ov011
 *   INTRUDE_COMM_SendPendingReplies  0x02176194  thumb  ov011
 *   func_0203F4FC 0x0203F4FC arm
 *   INTRUDE_CMD_SendMemberEntry  0x02173DA0  thumb  ov011
 *   INTRUDE_CMD_SendGroupRecord  0x02173EEC  thumb  ov011
 *   INTRUDE_CMD_SendResultRecord  0x021741E8  thumb  ov011
 *   INTRUDE_CMD_SendRecordEcho  0x02173F74  thumb  ov011
 *   INTRUDE_CMD_SendEndNotice  0x021742EC  thumb  ov011
 *   INTRUDE_CMD_SendStartNotice  0x021742A8  thumb  ov011
 *   INTRUDE_CMD_SendMemberValue 0x02173FF4 thumb ov011
 *   func_02175DA8 0x02175DA8 thumb ov011
 */

struct BigObj;
struct Rec44;
struct Sub02014444Obj;
struct Sub24;
struct SaveBlock;
struct Big;
struct Sub0200852CObj;
struct Rec1B0;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

#include "../arm9/net_types.h"
#include "intrude_comm_types.h"

typedef unsigned long long u64;

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

/* Profile data of this player (0x10 bytes), built for command 0x222. */
typedef struct IntrudeProfileData {
    u32 kind;
    u64 value;
    u8  extra[2];
    u8  valid;
} IntrudeProfileData;

u32 func_02026478(void *obj);
int INTRUDE_COMM_IsLinked(void);
GFLNetHandle *func_020399A8(void);
int func_0203D3A8(GFLNetHandle *handle, u32 command, u32 size, const void *data);
void func_0203D1E8(GFLNetHandle *handle, u32 enable);
void NET_WHPIPE_SetBeaconStatus(u8 value);
u32 func_0203D3F8(GFLNetHandle *handle, u32 sendId, u32 command, u32 size, const void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode);
u32 func_0203D1A4(GFLNetHandle *handle);
int func_02012F20(int a);
void *func_02012B38(const struct BigObj *p);
u8 FIELD_STATUS_GetSeasonDispFlag(struct Sub02014444Obj *o);
int COMM_PLAYER_SUPPORT_GetMode(int a);
struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
void COMM_PLAYER_SUPPORT_SetModeAndCurrent(int a, int b, int c);
void func_02082D44(const void *s, void *d, int n);
void GAME_COMM_PushPairMessage(u32 a, u32 b, u32 c);
u8 *func_020127D0(u8 *o, u32 idx);
int func_021583EC(void *a0, int a1);
void func_021861F4(u16 *p, int x);
void GAME_DATA_TakeUnionInfo(u8 *obj, void *dst);
int GFL_NET_IsSendQueueEntryOfHandle(GFLNetHandle *handle, int command);
u32 func_0203D4D0(GFLNetHandle *handle, u32 sendMask, u32 command, u32 size, const void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode);
void func_02161FF0(u8 *p, int v);
void func_02162008(u8 *p, u16 v);
void *func_020127A4(struct SaveBlock *p);
u16 func_02012AC8(const struct Rec44 *p);
unsigned int func_02013D9C(unsigned int id);
extern u32 func_0203D378(void);
extern int func_0203D1B4(void);
extern void func_02012B4C(struct BigObj *p, u8 v);
extern int INTRUDE_COMM_SendMemberCount(IntrudeCommSys *work, int count, ...);
extern int INTRUDE_COMM_SendStatusRecord(IntrudeCommSys *work);
extern int INTRUDE_CMD_SendProfile(IntrudeCommSys *work);
extern int INTRUDE_COMM_SendPeerStatus(IntrudeCommSys *work, int peer);
extern u8 func_02012E40(const u8 *o);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern void func_0200BE84(void *, u8 *);
u32 func_0203D1C0(u32 index);
int INTRUDE_COMM_SendRecordRequest(void);
int INTRUDE_COMM_SendPeerLeft(IntrudeCommSys *work, int netId);
int func_02173AE0(IntrudeCommSys *work, int netId, int result, int seq);
int INTRUDE_COMM_SendNotice(IntrudeCommSys *work, int netId, int seq);
unsigned char *func_020127C4(void *p);
int func_02162024(u8 *slots, int index, void *out);
void func_02162038(u8 *slots, int index);
int func_0216202C(u8 *slots, void *out, u8 *index);
void func_02162040(u8 *slots);
void *func_0200E0B0(void *p);
unsigned short func_0216749C(void *symbolMap, u32 *out, u32 cap, int page, u8 *count);
u8 func_021673C4(void *symbolMap);
u8 func_021673A8(void *symbolMap);
u16 func_02039338(void);
int INTRUDE_CMD_SendSaveSummary(IntrudeCommSys *work, int netMask);
u8 *func_02012944(void *p);
int func_02008468(void);
void *func_020127B8(void *p);
unsigned int func_02008530(const struct Sub0200852CObj *obj);
void func_02008494(const void *src, void *dst);
void *func_020127AC(struct SaveBlock *p, unsigned int idx);
void GAME_DATA_SetSlotFlag(struct BigObj *p, int i, u8 v);
void GAME_COMM_PushPlayerMessage(u32 a, u32 b);
void GAME_COMM_UpdatePlayerStatus(struct GameComm *gameComm, int netId, u16 zoneId, u8 intrudeId, u32 statusCode, int flag);
extern u32 func_02013D5C(u32 id);
extern u32 ZONEDATA_IsSameMatrixGroup(u32 a, u32 b);
extern int func_021677E4(struct CommPlayerWork *commPlayer, int netId);
extern u16 func_02167810(struct CommPlayerWork *commPlayer, int netId);
extern void func_02167658(struct CommPlayerWork *commPlayer, int netId);
extern void func_021675D0(struct CommPlayerWork *commPlayer, int netId, int objCode, IntrudePeer *peer);
extern u8 func_02012B58(const struct BigObj *p);
int func_0216786C(struct CommPlayerWork *commPlayer, IntrudePeer *peer);
u8 func_02012FB0(int a);
extern void sub_02082BCC(void *p, int c, unsigned int n);
extern void MI_CpuFill8(void *, u8, u32);
int func_020120D8(struct GameSystem *gameSystem);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_0200FB24(void);
extern u32 func_0200BF70(struct Rec1B0 *p);
extern int func_02012B70(const struct BigObj *p);
extern int func_02012FCC(int p0);
extern unsigned long long func_0200BFA4(u8 *p, void *q, u32 mode);
extern unsigned long long func_0200BF94(struct Rec1B0 *p);
extern void func_0200BF54(struct Rec1B0 *p, u8 *dest, u32 n);
extern void *func_020120F4(const struct GameSystem *gameSystem);
extern void func_02012B8C(struct BigObj *p, u32 v);
extern void func_02161FEC(u8 *slots, u16 intrudeId);
extern void INTRUDE_COMM_ResetMemberName(IntrudeMemberName *name);
extern void INTRUDE_COMM_PromoteRequestToResult(IntrudeCommSys *work, IntrudeSession *session, int netId);
extern void INTRUDE_COMM_SendProposalReplies(IntrudeCommSys *work, IntrudeSession *session);
extern void INTRUDE_COMM_SendPendingReplies(IntrudeCommSys *work, IntrudeSession *session);
extern u32 func_0203F4FC(void);
extern int INTRUDE_CMD_SendMemberEntry(IntrudeCommSys *work, IntrudeSession *session, int index);
extern int INTRUDE_CMD_SendGroupRecord(IntrudeCommSys *work, IntrudeSession *session);
extern int INTRUDE_CMD_SendResultRecord(IntrudeCommSys *work, IntrudeSession *session);
extern int INTRUDE_CMD_SendRecordEcho(IntrudeCommSys *work, IntrudeSession *session);
extern u32 INTRUDE_CMD_SendEndNotice(u32 a);
extern int INTRUDE_CMD_SendStartNotice(int a);
extern int INTRUDE_CMD_SendMemberValue(IntrudeCommSys *work, int remaining, int mask);
extern int func_02175DA8(IntrudeSession *session);
int INTRUDE_COMM_SendTally(IntrudeCommSys *work);
void INTRUDE_COMM_RecvBusyBegin(int netId, int size, void *data, IntrudeCommSys *work);
u32 INTRUDE_COMM_SendBusyBegin(void);
void INTRUDE_COMM_RecvBusyEnd(int netId, int size, void *data, IntrudeCommSys *work);
u32 INTRUDE_COMM_SendBusyEnd(void);
void INTRUDE_COMM_RecvPeerFlags(int netId, int size, u8 *flags, IntrudeCommSys *work);
int func_021744D0(int unused, int netId, int flags, ...);
void INTRUDE_COMM_RecvSupportMode(int netId, int size, int *mode, IntrudeCommSys *work);
int func_0217456C(int unused, int netId, int mode, ...);
void INTRUDE_COMM_RecvProfile(int netId, int size, void *profile, IntrudeCommSys *work);
int func_021745F8(u32 netId, const void *profile);
void INTRUDE_COMM_RecvPairMessage(int netId, int size, u8 *message, IntrudeCommSys *work);
int INTRUDE_COMM_SendPairMessage(int message, ...);
void INTRUDE_COMM_RecvUnionInfoRequest(int netId, int size, int data, IntrudeCommSys *work);
int func_021746AC(IntrudeCommSys *work, int netId);
void INTRUDE_COMM_RecvUnionInfo(int netId, int size, void *info, IntrudeCommSys *work);
int INTRUDE_COMM_SendUnionInfo(IntrudeCommSys *work, int netMask, void *info);
void INTRUDE_COMM_RecvReturnResult(int netId, int size, int result, IntrudeCommSys *work);
int INTRUDE_COMM_SendReturnResult(void *result, int netId);
void INTRUDE_COMM_RecvReturnPending(int netId, int size, int data, IntrudeCommSys *work);
int INTRUDE_COMM_SendReturnPending(const void *pending, int netId);
void INTRUDE_COMM_RecvPageRequest(int netId, int size, const IntrudePageRequest *request, IntrudeCommSys *work);
int INTRUDE_COMM_SendPageRequest(IntrudeCommSys *work, int netId, const void *request);
void INTRUDE_COMM_RecvSymbolPage(int netId, int size, IntrudeSymbolPage *page, IntrudeCommSys *work);
int INTRUDE_COMM_SendSymbolPage(IntrudeCommSys *work, int netId);
void INTRUDE_COMM_RecvAreaNotice(int netId, int size, int data, IntrudeCommSys *work);
u32 INTRUDE_COMM_SendAreaNotice(const void *notice);
void func_02174978(IntrudeCommSys *work);
void INTRUDE_COMM_UpdateSeasonState(IntrudeCommSys *work);
void INTRUDE_COMM_UpdateMemberJoin(IntrudeCommSys *work);
void INTRUDE_COMM_UpdateMemberLeave(IntrudeCommSys *work);
void INTRUDE_COMM_UpdatePendingNotices(IntrudeCommSys *work);
void INTRUDE_COMM_UpdateUnionInfoAndReturnSlots(IntrudeCommSys *work);
void INTRUDE_COMM_UpdatePageRequests(IntrudeCommSys *work);
void INTRUDE_COMM_BuildSymbolPage(IntrudeCommSys *work, const IntrudePageRequest *request);
void INTRUDE_COMM_UpdateQueuedRequest(IntrudeCommSys *work);
void func_02174E14(IntrudeCommSys *work, int state);
void INTRUDE_COMM_RefreshSelfRecord(IntrudeCommSys *work);
void INTRUDE_COMM_ApplyPlayerBeacon(IntrudeCommSys *work, int netId, IntrudeStatusRecord *record);
void INTRUDE_COMM_StorePlayerRecord(IntrudeCommSys *work, int netId, const IntrudePeer *src, int arg);
void func_02175004(IntrudeCommSys *work);
void INTRUDE_COMM_UpdatePlayerObject(IntrudeCommSys *work, int netId);
int INTRUDE_COMM_LookupZonePair(u16 zoneId, IntrudeZonePairInfo *out);
int INTRUDE_COMM_CompareZonePair(IntrudeZonePairInfo *a, IntrudeZonePairInfo *b);
int INTRUDE_COMM_GetRelativeSlot(IntrudeCommSys *work, int netId);
void INTRUDE_COMM_AdjustRemotePosition(IntrudeCommSys *work, u16 zoneId, int selfX, IntrudePeer *peer);
void func_02175274(IntrudeCommSys *work, int selfX);
int INTRUDE_COMM_UpdateSelfRecord(IntrudeCommSys *work);
void func_02175368(IntrudeCommSys *work);
unsigned char *func_0217537C(IntrudeCommSys *work);
void func_0217538C(IntrudeCommSys *work, int target);
void func_021753B8(IntrudeCommSys *work);
int INTRUDE_COMM_TryStartRequest(IntrudeCommSys *work, int netId, u8 seq);
void INTRUDE_COMM_SetRequestOpen(IntrudeCommSys *work);
void func_0217545C(IntrudeCommSys *work);
void INTRUDE_COMM_UpdateRequest(IntrudeCommSys *work);
int func_021754B4(IntrudeCommSys *work, int *target);
void INTRUDE_COMM_SetRequestResult(IntrudeCommSys *work, int netId, int result, int seq);
void INTRUDE_COMM_SetRequestResultAccepted(IntrudeCommSys *work, int netId, int seq);
int func_02175514(IntrudeCommSys *work);
void func_0217553C(IntrudeCommSys *work);
void func_02175548(u32 myStatus, u16 *objCode, u8 *form, u8 *sex);
u16 func_02175598(IntrudePeer *peer, u32 myStatus);
int INTRUDE_COMM_HasConnectedPeers(void);
void INTRUDE_COMM_BuildLocalProfile(void *saveData, IntrudeProfileData *profile);
u8 func_021756A4(IntrudeCommSys *work);
int INTRUDE_COMM_IsValidObjCode(int objCode);
int func_021756D0(u32 code);
void func_021756F0(IntrudeCommSys *work, u32 value);
void func_02175710(IntrudeCommSys *work, u32 intrudeId);
void func_0217574C(IntrudeCommSys *work, u32 value);
void INTRUDE_COMM_InitSession(IntrudeSession *session);
void func_021757A8(IntrudeSession *session);
void INTRUDE_COMM_UpdateSession(IntrudeCommSys *work, IntrudeSession *session);
int INTRUDE_COMM_GetSessionElapsed(IntrudeSession *session);
int INTRUDE_COMM_GetSessionWaitRemaining(IntrudeSession *session);
int func_021758C8(IntrudeSession *session);
void INTRUDE_COMM_SetSessionEntrySendFlag(IntrudeSession *session, int index);
void INTRUDE_COMM_SetSessionRequestSendFlag(IntrudeSession *session);
void INTRUDE_COMM_SetSessionResultSendFlag(IntrudeSession *session);
void INTRUDE_COMM_StoreSessionEntry(IntrudeSession *session, const u16 *src, int index);
int INTRUDE_COMM_StoreSessionRequest(void *unused, IntrudeSession *session, IntrudeMemberRecord *src);
void INTRUDE_COMM_ClearSessionTicks(IntrudeSession *session);
void INTRUDE_COMM_AddSessionMember(IntrudeSession *session, u8 netId);
void INTRUDE_COMM_StartSessionTimer(IntrudeSession *session, int seconds);
int func_02175A24(IntrudeSession *session);
void INTRUDE_COMM_UpdateSessionSends(IntrudeCommSys *work, IntrudeSession *session);
void INTRUDE_COMM_UpdateSessionResult(IntrudeCommSys *work, IntrudeSession *session);
int func_02175B14(IntrudeSession *session);
IntrudeMemberRecord *func_02175B34(IntrudeSession *session);
void func_02175B4C(IntrudeCommSys *work, IntrudeSession *session);
int func_02175B8C(IntrudeSession *session);
void INTRUDE_COMM_SetSessionFinished(IntrudeSession *session);
int func_02175BBC(IntrudeSession *session);
IntrudeResultRecord *func_02175BCC(IntrudeSession *session);
int func_02175BE4(IntrudeSession *session);
void INTRUDE_COMM_SetSessionReadyBit(IntrudeSession *session, u32 netId);
extern IntrudeZonePair d_02176AA0[8];
extern u16 gIntrudeCommObjCodesMale[];
extern u16 gIntrudeCommObjCodesFemale[];
extern const u16 gIntrudeCommValidObjCodes[];
extern u16 gIntrudeCommValidProfileCodes[];




int INTRUDE_COMM_SendTally(IntrudeCommSys *work)
{
    func_02026478(work->gameComm);
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return func_0203D3A8(func_020399A8(), 0x21d, 4, &work->ownTally);
}




void INTRUDE_COMM_RecvBusyBegin(int netId, int size, void *data, IntrudeCommSys *work)
{
    work->busyCount++;
    if (work->busyLock == 0) {
        func_0203D1E8(func_020399A8(), 0);
        NET_WHPIPE_SetBeaconStatus(1);
    }
}




u32 INTRUDE_COMM_SendBusyBegin(void)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return func_0203D3F8(func_020399A8(), 0, 0x21e, 0, 0, 0, 0, 0);
}




void INTRUDE_COMM_RecvBusyEnd(int netId, int size, void *data, IntrudeCommSys *work)
{
    work->busyCount--;
    if (work->busyCount == 0 && work->busyLock == 0) {
        func_0203D1E8(func_020399A8(), 1);
        NET_WHPIPE_SetBeaconStatus(0);
    }
}




u32 INTRUDE_COMM_SendBusyEnd(void)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return func_0203D3F8(func_020399A8(), 0, 0x21f, 0, 0, 0, 0, 0);
}




/*
 * extent: existing follower ov011_func_021744D0.c stays separate.
 */
void INTRUDE_COMM_RecvPeerFlags(int netId, int size, u8 *flags, IntrudeCommSys *work)
{
    if (netId != func_0203D1A4(func_020399A8())) {
        work->peerFlags |= *flags;
    }
}




/*
 * Handed as 0x021744D2; the function starts at the push {r0-r3} at 0x021744D0.
 */
int func_021744D0(int unused, int netId, int flags, ...)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    return func_0203D3F8(func_020399A8(), netId, 0x220, 1, &flags, 0, 0, 0);
}




void INTRUDE_COMM_RecvSupportMode(int netId, int size, int *mode, IntrudeCommSys *work)
{
    int gameData;
    int support;
    int supportState;
    gameData = func_02026478(work->gameComm);
    support = func_02012F20(gameData);
    if (work->peerMask & (1 << netId)) {
        if (FIELD_STATUS_GetSeasonDispFlag(func_02012B38((const struct BigObj *)gameData)) == 1) {
            supportState = COMM_PLAYER_SUPPORT_GetMode(support);
            if (supportState == 0 || supportState == 3) {
                COMM_PLAYER_SUPPORT_SetModeAndCurrent(support, *mode, (int)func_02012950((struct Sub24 *)gameData, netId));
            }
        }
    }
}




/*
 * Handed as 0x0217456E; the function starts at the push {r0-r3} at 0x0217456C.
 */
int func_0217456C(int unused, int netId, int mode, ...)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    return func_0203D3F8(func_020399A8(), netId, 0x221, 4, &mode, 0, 0, 0);
}




void INTRUDE_COMM_RecvProfile(int netId, int size, void *profile, IntrudeCommSys *work)
{
    func_02026478(work->gameComm);
    if ((work->peerMask & (1 << netId)) && work->profilePending == 0) {
        func_02082D44(profile, &work->profile, 0x14);
        work->profilePending = 1;
    }
}




int func_021745F8(u32 netId, const void *profile)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return func_0203D3F8(func_020399A8(), netId, 0x222, 0x14, profile, 0, 0, 0);
}




/*
 * extent: existing follower ov011_func_02174660.c stays separate.
 */
void INTRUDE_COMM_RecvPairMessage(int netId, int size, u8 *message, IntrudeCommSys *work)
{
    if (netId != func_0203D1A4(func_020399A8()) && (work->peerMask & (1 << netId))) {
        GAME_COMM_PushPairMessage((u32)work->gameComm, netId, *message);
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
    return func_0203D3A8(func_020399A8(), 0x223, 1, &message);
}




void INTRUDE_COMM_RecvUnionInfoRequest(int netId, int size, int data, IntrudeCommSys *work)
{
    work->unionInfoRequestMask |= (u8)(1 << netId);
}




int func_021746AC(IntrudeCommSys *work, int netId)
{
    int sent;
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    sent = func_0203D3F8(func_020399A8(), netId, 0x224, 0, 0, 0, 0, 0);
    if (sent == 1) {
        work->unionInfoReceived = 0;
    }
    return sent;
}




void INTRUDE_COMM_RecvUnionInfo(int netId, int size, void *info, IntrudeCommSys *work)
{
    int gameData;
    int unionInfo;
    gameData = func_02026478(work->gameComm);
    unionInfo = (int)func_020127D0((u8 *)gameData, 0);
    func_021861F4(info, func_021583EC((void *)gameData, netId));
    func_02082D44(info, (void *)unionInfo, 0x1E8);
    GAME_DATA_TakeUnionInfo((u8 *)gameData, info);
    work->unionInfoReceived = 1;
}




int INTRUDE_COMM_SendUnionInfo(IntrudeCommSys *work, int netMask, void *info)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    if (GFL_NET_IsSendQueueEntryOfHandle(func_020399A8(), 0x225) == 1) {
        return 0;
    }
    func_02082D44(info, work->unionInfoBuffer, 0x1E8);
    return func_0203D4D0(func_020399A8(), netMask & 0xFF, 0x225, 0x1E8, info, 0, 0, 1);
}




void INTRUDE_COMM_RecvReturnResult(int netId, int size, int result, IntrudeCommSys *work)
{
    func_02161FF0(work->returnSlots, result);
}




int INTRUDE_COMM_SendReturnResult(void *result, int netId)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return func_0203D3F8(func_020399A8(), netId, 0x226, 8, result, 0, 0, 0);
}




void INTRUDE_COMM_RecvReturnPending(int netId, int size, int data, IntrudeCommSys *work)
{
    func_02162008(work->returnSlots, (u16)netId);
}




int INTRUDE_COMM_SendReturnPending(const void *pending, int netId)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return func_0203D3F8(func_020399A8(), netId, 0x227, 8, pending, 0, 0, 0);
}




/*
 * Stores the page request of the sender (a 4-byte struct copy: both byte
 * pairs load before their stores).
 */
void INTRUDE_COMM_RecvPageRequest(int netId, int size, const IntrudePageRequest *request, IntrudeCommSys *work)
{
    work->pageRequests[netId] = *request;
}




int INTRUDE_COMM_SendPageRequest(IntrudeCommSys *work, int netId, const void *request)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    work->pageReceived = 0;
    return func_0203D3F8(func_020399A8(), netId, 0x228, 4, request, 0, 0, 0);
}




void INTRUDE_COMM_RecvSymbolPage(int netId, int size, IntrudeSymbolPage *page, IntrudeCommSys *work)
{
    work->peerSymbolPage = *page;
    work->pageReceived = 1;
    work->areaNoticeSeen = 0;
}




int INTRUDE_COMM_SendSymbolPage(IntrudeCommSys *work, int netId)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return func_0203D3F8(func_020399A8(), netId, 0x229, 0x54, &work->ownSymbolPage, 0, 0, 0);
}




void INTRUDE_COMM_RecvAreaNotice(int netId, int size, int data, IntrudeCommSys *work)
{
    int gameData;
    gameData = func_02026478(work->gameComm);
    if (netId != func_0203D1A4(func_020399A8()) && work->localPeer.intrudeId == netId) {
        if (func_02013D9C(func_02012AC8(func_020127A4((struct SaveBlock *)gameData))) != 0) {
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
    return func_0203D3A8(func_020399A8(), 0x22a, 4, notice);
}




/*
 * Addresses are Black-image addresses.
 */
void func_02174978(IntrudeCommSys *work)
{
    int gameData;
    int connected;
    void *profileSys;
    gameData = func_02026478(work->gameComm);
    if (func_0203D378() == 1) {
        connected = func_0203D1B4();
        if (connected > work->memberCount) {
            work->memberCount = connected;
            work->memberCountDirty = 1;
            func_02012B4C((struct BigObj *)gameData, work->memberCount);
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
    INTRUDE_COMM_UpdateQueuedRequest(work);
    if (INTRUDE_COMM_UpdateSelfRecord(work) == 1) {
        work->peerStatusDirty = 1;
    }
    if (work->peerStatusDirty == 1 && work->suspended == 0 && INTRUDE_COMM_SendPeerStatus(work, (int)&work->localPeer) == 1) {
        work->peerStatusDirty = 0;
    }
    if (func_02012E40((const u8 *)gameData) == 0 && work->profilePending == 1) {
        profileSys = func_0200BE48(func_02012EBC((struct Big *)gameData));
        if (func_021756D0(work->profile.code) == 0) {
            work->profile.code = 0x11;
        }
        func_0200BE84(profileSys, (u8 *)&work->profile);
        work->profilePending = 0;
    }
}




void INTRUDE_COMM_UpdateSeasonState(IntrudeCommSys *work)
{
    int mode;
    mode = FIELD_STATUS_GetSeasonDispFlag((struct Sub02014444Obj *)func_02012B38((const struct BigObj *)func_02026478(work->gameComm)));
    switch (mode) {
    case 0:
        if (work->localPeer.state == 2) {
            func_02174E14(work, 0);
        }
        break;
    case 1:
        if (work->localPeer.state == 0) {
            func_02174E14(work, 2);
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
        if ((int)func_0203D1C0((unsigned char)i) == 1 && !(work->peerMask & (1 << i))) {
            INTRUDE_COMM_SendRecordRequest();
            work->joinRetryWait = 30;
            return;
        }
    }
}




void INTRUDE_COMM_UpdateMemberLeave(IntrudeCommSys *work)
{
    int i;
    if (func_0203D378() != 0) {
        for (i = 0; i < work->memberCount; i++) {
            if ((int)func_0203D1C0((unsigned char)i) == 0 && (work->peerMask & (1 << i))) {
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
            if ((int)func_0203D1C0((unsigned char)i) == 1) {
                if (func_02173AE0(work, i, 2, work->busyReplies[i]) == 1) {
                    work->busyReplies[i] = 0;
                }
            } else {
                work->busyReplies[i] = 0;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (work->pendingReplies[i] != 0) {
            if ((int)func_0203D1C0((unsigned char)i) == 1) {
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
 * func_02026478 returns the argument consumed by func_020127C4.
 */
void INTRUDE_COMM_UpdateUnionInfoAndReturnSlots(IntrudeCommSys *work)
{
    int result[2];
    int pending[2];
    unsigned char i;
    int gameData;
    gameData = func_02026478(work->gameComm);
    if (work->unionInfoRequestMask != 0) {
        if (INTRUDE_COMM_SendUnionInfo(work, work->unionInfoRequestMask, (void *)func_020127C4((void *)gameData)) == 1) {
            work->unionInfoRequestMask = 0;
        }
    }
    for (i = 0; i < 3; i++) {
        if (func_02162024(work->returnSlots, i, result) == 1) {
            if (INTRUDE_COMM_SendReturnResult(result, i) == 1) {
                func_02162038(work->returnSlots, i);
            }
        }
    }
    if (func_0216202C(work->returnSlots, pending, &i) == 1) {
        if (INTRUDE_COMM_SendReturnPending(pending, i) == 1) {
            func_02162040(work->returnSlots);
        }
    }
}




/*
 * The guard's ldrb lands in r1 because func_02026478's result is live in r0:
 * it is func_020127C4's argument (the r0 at that call is never re-set).
 */
void INTRUDE_COMM_UpdatePageRequests(IntrudeCommSys *work)
{
    unsigned char i;
    IntrudePageRequest *requests;
    int gameData;
    gameData = func_02026478(work->gameComm);
    if (work->unionInfoRequestMask != 0) {
        if (INTRUDE_COMM_SendUnionInfo(work, work->unionInfoRequestMask, (void *)func_020127C4((void *)gameData)) == 1) {
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
    symbolMap = func_0200E0B0(func_02012EBC((struct Big *)func_02026478(work->gameComm)));
    func_0216749C(symbolMap, page->entries, 0x14, request->page, count);
    page->count = count[0];
    page->levelSmall = func_021673C4(symbolMap);
    page->levelLarge = func_021673A8(symbolMap);
    netId = func_02039338();
    page->netId = netId;
    page->page = request->page;
}




void INTRUDE_COMM_UpdateQueuedRequest(IntrudeCommSys *work)
{
    if (work->readyMask != 0) {
        if (INTRUDE_CMD_SendSaveSummary(work, work->readyMask) == 1) {
            work->readyMask = 0;
        }
    }
}




void func_02174E14(IntrudeCommSys *work, int state)
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
    int gameData;
    gameData = func_02026478(work->gameComm);
    func_02082D44(func_02012944((void *)gameData), work->ownMyStatus, func_02008468());
    func_02082D44(func_020127B8((void *)gameData), work->lastBattleRecSlot, 0x10);
    INTRUDE_COMM_UpdateSelfRecord(work);
    if (work->localPeer.intrudeId == 0x80) {
        func_02175710(work, func_02039338());
    }
    work->selfSnapshot = work->localPeer;
}




void INTRUDE_COMM_ApplyPlayerBeacon(IntrudeCommSys *work, int netId, IntrudeStatusRecord *record)
{
    int myStatus;
    int gameData;
    int status;
    int changed;
    gameData = func_02026478(work->gameComm);
    changed = 0;
    status = (int)func_02012950((struct Sub24 *)gameData, netId);
    if (work->peerMask & (1 << netId)) {
        myStatus = func_02008530((const struct Sub0200852CObj *)status);
        if (myStatus == func_02008530((const struct Sub0200852CObj *)record->myStatus)) {
            goto skip;
        }
    }
    changed = 1;
skip:
    func_02008494(record->myStatus, (void *)status);
    func_02082D44(record->battleRecSlot, func_020127AC((struct SaveBlock *)gameData, netId), 0x10);
    GAME_DATA_SetSlotFlag((struct BigObj *)gameData, netId, record->peer.season);
    INTRUDE_COMM_StorePlayerRecord(work, netId, &record->peer, 1);
    work->peerMask |= (u8)(1 << netId);
    if (changed == 1 && netId != func_02039338()) {
        GAME_COMM_PushPlayerMessage((u32)work->gameComm, netId);
    }
}




void INTRUDE_COMM_StorePlayerRecord(IntrudeCommSys *work, int netId, const IntrudePeer *src, int arg)
{
    IntrudePeer *peer;
    u32 vanish;
    peer = &work->peers[netId];
    vanish = peer->package.vanish;
    func_02082D44(src, peer, 0x1C);
    peer->package.vanish = vanish;
    peer->remoteVanish = (u8)src->package.vanish;
    if (src->package.vanish == 1) {
        peer->package.vanish = 1;
    }
    GAME_COMM_UpdatePlayerStatus(work->gameComm, netId, peer->zoneId, (u8)peer->intrudeId, peer->statusCode, arg);
    if (netId != func_02039338()) {
        work->packages[netId] = peer->package;
        INTRUDE_COMM_AdjustRemotePosition(work, work->localPeer.zoneId, work->localPeer.package.pos.x, peer);
    }
    work->dirtyPeerMask |= (u8)(1 << netId);
}




void func_02175004(IntrudeCommSys *work)
{
    u8 i;
    if (func_02012E40((const u8 *)func_02026478(work->gameComm)) == 1) {
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
    if (func_02013D5C(peer->zoneId) == 1 && func_02013D5C(self->zoneId) == 1) {
        return 0;
    }
    if (peer->intrudeId == self->intrudeId) {
        if (func_02013D9C(peer->zoneId) == 1 && func_02013D9C(self->zoneId) == 1) {
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
    if (netId != func_02039338()) {
        IntrudePeer *self = &work->localPeer;
        peer->package.vanish = ShouldHidePeer(peer, self);
    }
    if (func_021677E4(work->commPlayer, netId) == 1) {
        objCode = func_02175598(peer, func_021583EC((void *)func_02026478(work->gameComm), netId));
        if (objCode != func_02167810(work->commPlayer, netId)) {
            func_02167658(work->commPlayer, netId);
            if (peer->objCode != 0) {
                func_021675D0(work->commPlayer, netId, objCode, peer);
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
        if (zoneId == d_02176AA0[i].zoneA) {
            side = 0;
        } else if (zoneId == d_02176AA0[i].zoneB) {
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
    slot = netId - func_02012B58((const struct BigObj *)func_02026478(work->gameComm));
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
        if (func_02013D5C(zoneId) != 0) {
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




void func_02175274(IntrudeCommSys *work, int selfX)
{
    IntrudePeer *peers;
    IntrudePeer *self;
    int ownNetId;
    int i;
    IntrudePeer *peer;
    ownNetId = func_02012B58((const struct BigObj *)func_02026478(work->gameComm));
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
    int gameData;
    int zoneId;
    int changed;
    int lidClosed;
    IntrudePeer *self;
    gameData = func_02026478(work->gameComm);
    zoneId = func_02012AC8(func_020127A4((struct SaveBlock *)gameData));
    self = &work->localPeer;
    changed = func_0216786C(work->commPlayer, self);
    if (self->zoneId != zoneId) {
        self->zoneId = zoneId;
        changed = 1;
    }
    if (self->symbolMapFlag != func_02012FB0(gameData)) {
        self->symbolMapFlag = func_02012FB0(gameData);
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
 * Unlabelled Thumb leaf, seeded so that ov018 func_0217FE38 has a witness:
 * clears the notice bytes.
 */
void func_02175368(IntrudeCommSys *work)
{
    sub_02082BCC(&work->notice, 0, 4);
}




/*
 * Unlabelled Thumb leaf, the follower of func_02175368: returns the notice
 * bytes when the first one is 1, else null. Labelled so that
 * func_02175368's extent ends at its own pool.
 */
unsigned char *func_0217537C(IntrudeCommSys *work)
{
    if (work->notice.value[0] == 1) {
        return work->notice.value;
    }
    return 0;
}




/*
 * extent: two zero alignment bytes at 0x021753B6 precede the owned 021753B8 function.
 */
void func_0217538C(IntrudeCommSys *work, int target)
{
    MI_CpuFill8(&work->requestTarget, 0, 8);
    work->requestTarget = target;
    work->replyFrom = 4;
    work->sentRequestSeq = 0;
    func_021753B8(work);
}




void func_021753B8(IntrudeCommSys *work)
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
        if (work->requestTarget == 4 && work->sentRequestSeq == 0 && func_020120D8(work->gameSystem) == 0) {
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
void func_0217545C(IntrudeCommSys *work)
{
    work->requestOpen = 0;
}




void INTRUDE_COMM_UpdateRequest(IntrudeCommSys *work)
{
    u8 target[4];
    u8 *replies;
    int netId;
    if (func_021754B4(work, (int *)target) == 1 && func_020120D8(work->gameSystem) == 1) {
        replies = work->busyReplies;
        netId = work->requestTarget;
        if (replies[netId] == 0) {
            replies[netId] = work->sentRequestSeq;
        }
        func_0217538C(work, 4);
        func_0217545C(work);
    }
}




int func_021754B4(IntrudeCommSys *work, int *target)
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
 * note:     unlabelled leaf (push {r3,r4}, no lr); callers func_0218123C and
 *           func_02181584 in ov018. Its follower 0x0217553C is also an
 *           unlabelled leaf.
 */
int func_02175514(IntrudeCommSys *work)
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
void func_0217553C(IntrudeCommSys *work)
{
    work->replyResult = 0;
}




void func_02175548(u32 myStatus, u16 *objCode, u8 *form, u8 *sex)
{
    u32 trainerId;
    u32 index;
    int female;
    trainerId = func_02008530((const struct Sub0200852CObj *)myStatus);
    female = func_02008550((const struct Sub0200852CObj *)myStatus);
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




u16 func_02175598(IntrudePeer *peer, u32 myStatus)
{
    struct { u8 sex; u8 form; u16 objCode; } pick;
    u16 objCode;
    objCode = peer->objCode;
    if (objCode == 0) {
        if (peer->package.dir == 1) {
            pick.objCode = (func_02008550((const struct Sub0200852CObj *)myStatus) == 0) ? 2 : 5;
        } else {
            pick.objCode = (func_02008550((const struct Sub0200852CObj *)myStatus) == 0) ? 1 : 4;
        }
    } else if (objCode == 0xFFFF) {
        func_02175548(myStatus, &pick.objCode, &pick.form, &pick.sex);
    } else {
        pick.objCode = objCode;
        if (INTRUDE_COMM_IsValidObjCode(pick.objCode) == 0) {
            pick.objCode = (func_02008550((const struct Sub0200852CObj *)myStatus) == 0) ? 10 : 14;
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
    if (func_0200FB24() != 0) return 0;
    if (func_0203D1B4() > 1) return 1;
    return 0;
}




void INTRUDE_COMM_BuildLocalProfile(void *saveData, IntrudeProfileData *profile)
{
    void *profileSys;
    profileSys = func_0200BE48(func_02012EBC(saveData));
    MI_CpuFill8(profile, 0, 0x10);
    profile->kind = func_0200BF70(profileSys);
    if (func_02012B70(saveData) == 1) {
        profile->value = func_0200BFA4(profileSys, (void *)func_02012FCC((int)saveData), 2);
    } else {
        profile->value = func_0200BF94(profileSys);
    }
    func_0200BF54(profileSys, profile->extra, 2);
    profile->valid = 1;
}




u8 func_021756A4(IntrudeCommSys *work)
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
int func_021756D0(u32 code)
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
void func_021756F0(IntrudeCommSys *work, u32 value)
{
    work->lock = (u8)value;
}




/*
 * func_0217574C is an unlabelled leaf (the suspended bit).
 */
void func_02175710(IntrudeCommSys *work, u32 intrudeId)
{
    void *gameData;
    gameData = func_020120F4(work->gameSystem);
    work->localPeer.intrudeId = intrudeId;
    func_02012B8C(gameData, intrudeId);
    func_02161FEC(work->returnSlots, (u8)intrudeId);
}




void func_0217574C(IntrudeCommSys *work, u32 value)
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
    func_021757A8(session);
}




/*
 * extent: two zero alignment bytes at 0x021757C2 precede existing 021757C4 code.
 */
void func_021757A8(IntrudeSession *session)
{
    int i;
    for (i = 0; i < 3; i++) session->members[i].filled = 0;
}




void INTRUDE_COMM_UpdateSession(IntrudeCommSys *work, IntrudeSession *session)
{
    int gameData;

    if (func_0203D378() == 1 && func_02175B14(session) == 1) {
        if (session->result.record.netId == 4) {
            if (session->request.ticksLeft != 0) {
                if (session->resultReported == 0 && INTRUDE_COMM_GetSessionElapsed(session) > session->request.ticksLeft) {
                    session->resultReported = 1;
                }
            } else if (session->timeLimitSet == 1 && INTRUDE_COMM_GetSessionElapsed(session) > session->request.amount) {
                gameData = func_02026478(work->gameComm);
                if (session->result.confirmed == 0) {
                    INTRUDE_COMM_PromoteRequestToResult(work, session, func_02012B58((const struct BigObj *)gameData));
                }
            }
        } else if (session->timeLimitSet == 1 && INTRUDE_COMM_GetSessionElapsed(session) > session->request.amount) {
            session->leaveFlag = 1;
        }
    }
    INTRUDE_COMM_SendProposalReplies(work, session);
    INTRUDE_COMM_SendPendingReplies(work, session);
    INTRUDE_COMM_UpdateSessionSends(work, session);
    INTRUDE_COMM_UpdateSessionResult(work, session);
}




int INTRUDE_COMM_GetSessionElapsed(IntrudeSession *session)
{
    u32 now = func_0203F4FC();
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




int func_021758C8(IntrudeSession *session)
{
    int ticks;
    int remaining;

    if (func_02175B14(session) == 1 && session->result.record.netId == 4) {
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
    IntrudeMemberRecord *request = func_02175B34(session);
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
    if (session->joinedMask == 0) session->startTick = func_0203F4FC();
    MarkJoined(session, 1 << netId);
}




/*
 * extent: follower 0x02175A24 already filed separately.
 */
void INTRUDE_COMM_StartSessionTimer(IntrudeSession *session, int seconds)
{
    session->timeLimitSet = 1;
    session->request.amount = seconds;
    if (func_0203D378() == 0) session->startTick = func_0203F4FC();
}




/*
 * Unlabelled leaf (sole blocker of ov018 func_0217C4D0).
 */
int func_02175A24(IntrudeSession *session)
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
void INTRUDE_COMM_UpdateSessionResult(IntrudeCommSys *work, IntrudeSession *session)
{
    u8 mask = session->joinNoticeMask;
    if (mask != 0) {
        if (INTRUDE_CMD_SendMemberValue(work, INTRUDE_COMM_GetSessionWaitRemaining(session), mask) == 1) session->joinNoticeMask = 0;
    }
}




int func_02175B14(IntrudeSession *session)
{
    if (session->request.netId == 4 || session->requestReceived == 0) return 0;
    return 1;
}




/*
 * extent: two zero alignment bytes follow the compiled return.
 */
IntrudeMemberRecord *func_02175B34(IntrudeSession *session)
{
    IntrudeMemberRecord *request;
    if (func_02175B14(session) == 0) request = 0;
    else request = &session->request;
    return request;
}




void func_02175B4C(IntrudeCommSys *work, IntrudeSession *session)
{
    if (func_02175B14(session) == 1) {
        session->accepted = 1;
        session->finished = 0;
        work->localPeer.eventJoined = 1;
        work->peerStatusDirty = 1;
    }
}




int func_02175B8C(IntrudeSession *session)
{
    if (func_02175B14(session) == 1) return session->accepted;
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
 * filed as the sole blocker of ov018 func_0217BDE0.
 */
int func_02175BBC(IntrudeSession *session)
{
    return session->finished;
}




IntrudeResultRecord *func_02175BCC(IntrudeSession *session)
{
    IntrudeResultRecord *result;
    if (func_02175DA8(session) == 0) result = 0;
    else result = &session->result;
    return result;
}




/*
 * INTRUDE_COMM_SetSessionReadyBit is an unlabelled leaf (sets one ready bit).
 */
int func_02175BE4(IntrudeSession *session)
{
    if (func_02175B8C(session) == 1 || func_02175BCC(session) != 0) {
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
