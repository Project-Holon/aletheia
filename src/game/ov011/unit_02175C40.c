/*
 * file:     unit_02175C40.c
 * unit:     yes
 * function: INTRUDE_COMM_TakeNoticeState, INTRUDE_COMM_SetNoticeState, INTRUDE_COMM_FindFreeResultSlot, INTRUDE_COMM_StoreResultRecord, INTRUDE_COMM_GetJoinStatus, INTRUDE_COMM_ClearJoinStatus, INTRUDE_COMM_PromoteRequestToResult, INTRUDE_COMM_SetResultRecord, INTRUDE_COMM_HasResult, INTRUDE_COMM_GetRequestKind, INTRUDE_COMM_GetResultCount, INTRUDE_COMM_RecordResultOutcome, INTRUDE_COMM_HasResultReward, INTRUDE_COMM_IsResultConfirmed, INTRUDE_COMM_GetLeaveFlag, INTRUDE_COMM_ResetMemberName, INTRUDE_COMM_FillMemberName, INTRUDE_COMM_SetMemberEntry, INTRUDE_COMM_GetMemberNameNetId, INTRUDE_COMM_IsJoinRequestValid, INTRUDE_COMM_ReceiveJoinRequest, INTRUDE_COMM_SendProposalReplies, INTRUDE_COMM_SendPendingReplies, INTRUDE_COMM_StoreJoinReply, INTRUDE_COMM_TakeJoinReply, INTRUDE_COMM_ClearJoinReply, INTRUDE_COMM_IsRequestFromNetId, INTRUDE_COMM_GetRequesterNetId, INTRUDE_COMM_IsRequestFromSelf, INTRUDE_COMM_SetWordSetPlayerName, INTRUDE_COMM_SetWordSetMemberName, INTRUDE_COMM_SetWordSetRequest, INTRUDE_COMM_ResetOutcomes, INTRUDE_COMM_PickEntryForKind, INTRUDE_COMM_CountOutcomes, INTRUDE_COMM_PartyProcInit, INTRUDE_COMM_PartyProcMain
 * address:  0x02175C40
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
 *   func_0203EFC8  0x0203EFC8  arm
 *   INTRUDE_COMM_GetPartnerTallyValid 0x021756A4 thumb ov011
 *   INTRUDE_COMM_IsSessionActive 0x02175B14 thumb ov011
 *   func_02026478  0x02026478  thumb
 *   func_02012B58  0x02012B58  thumb
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02008530  0x02008530  thumb
 *   INTRUDE_COMM_NormalizeVersion  0x021584F4  thumb  ov010
 *   INTRUDE_COMM_GetSessionResult 0x02175BCC thumb ov011
 *   func_02082BCC 0x02082BCC arm
 *   GAME_DATA_GetMyStatusByNetId 0x021583EC thumb ov010
 *   func_020084F8 0x020084F8 thumb
 *   func_02008550 0x02008550 thumb
 *   GAME_DATA_GetBattleRecSlotByNetId  0x021583CC  thumb  ov010
 *   func_0200855C  0x0200855C  thumb
 *   INTRUDE_COMM_IsValidObjCode  0x021756B0  thumb  ov011
 *   INTRUDE_COMM_IsValidProfileCode  0x021756D0  thumb  ov011
 *   GFL_NET_SYSTEM_GetConnectNum  0x020392B8  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   INTRUDE_COMM_SetSessionRequestSendFlag  0x02175920  thumb  ov011
 *   func_0203F4FC  0x0203F4FC  arm
 *   INTRUDE_CMD_SendJoinReply 0x02173E6C thumb ov011
 *   memset 0x02082BCC arm
 *   INTRUDE_CMD_SendProposalReply  0x021740AC  thumb  ov011
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetStringN  0x02045994  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201EF40  0x0201EF40  thumb
 *   func_0201F184  0x0201F184  thumb
 *   gIntrudePickTable     0x02176C4C  data  ov011  a1
 *   func_020056EC  0x020056EC  thumb
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   PROCSYS_Create  0x02031324  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   POKE_TOOL_HealParty  0x0201BA34  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201A920  0x0201A920  thumb
 *   POKEPARTY_IsMemberBattleReady  0x0201AB34  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_02019CA0  0x02019CA0  thumb
 *   func_02034714  0x02034714  arm
 *   d_02177010     0x02177010  data  ov011  a1
 *   func_02012138  0x02012138  thumb
 *   PROCSYS_Main  0x02031330  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   BTL_SETUP_SetupCommSingle  0x02013790  thumb
 *   BTL_SETUP_SetParty  0x02013128  thumb
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GFL_NET_HANDLE_SetUserInfo  0x0203A424  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02034AC4  0x02034AC4  arm
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm
 *   PROCSYS_Push  0x02031348  arm
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   BTL_SETUP_FreeSlots  0x020130DC  thumb
 *   ov093_id       0x0000005D  data  a1
 *   d_021F03C4     0x021F03C4  data  ov093  a4
 *   d_021EFDAC     0x021EFDAC  data  ov093  a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed char s8;
typedef signed short s16;

#include "../arm9/net_types.h"

struct GameSystem;
struct GameComm;
struct Proc;
struct SaveData;
struct Strbuf;
struct U16Vec;
struct WordSet;
struct Party;
struct PartyMon;
struct MemberRecord;

#include "intrude_comm_types.h"

/* Row of the entry table (0xE0 rows). */
typedef struct IntrudePickRow {
    u8 kind;
    u8 minPoints;
    u8 level;
    u8 flags;
} IntrudePickRow;

/* Save block that holds the entry picks; only the used fields. */
typedef struct IntrudeSaveSlot {
    u8 picks[6];                /* table row picked for each kind */
    u8 outcomes[6];             /* 0 open, 1 or 2 done */
    u16 pointsA;
    u16 pointsB;
} IntrudeSaveSlot;

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
    void *asyncTask;            /* 0xF4 */
    struct Party *party;        /* 0xF8 */
    int overlayLoaded;          /* 0xFC */
} IntrudePartyWork;

/* Reply to a join request (command 0x211), 0x38 bytes. */
typedef struct IntrudeJoinReply {
    u8 kind;                    /* 1 = accepted, the record follows */
    u8 pad01[3];
    IntrudeMemberRecord record;
} IntrudeJoinReply;

extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern u8 INTRUDE_COMM_GetPartnerTallyValid(IntrudeCommSys *w);
extern int INTRUDE_COMM_IsSessionActive(IntrudeSession *session);
extern void *func_02026478(struct GameComm *gameComm);
extern u8 func_02012B58(const struct SaveData *saveData);
extern IntrudeSaveSlot *GAME_DATA_GetLastBattleRecSlot(void *saveData);
extern struct MemberRecord *func_02012950(void *saveData, u32 index);
extern u32 func_02008530(const struct MemberRecord *record);
extern int INTRUDE_COMM_NormalizeVersion(int a0, int a1);
extern IntrudeResultRecord *INTRUDE_COMM_GetSessionResult(IntrudeSession *session);
extern void func_02082BCC(void *, int, int);
extern int GAME_DATA_GetMyStatusByNetId(void *saveData, int index);
extern u32 func_020084F8(void *record, void *dest, u32 count);
extern int func_02008550(const struct MemberRecord *);
extern int GAME_DATA_GetBattleRecSlotByNetId(void *saveData, int index);
extern u8 func_0200855C(const struct MemberRecord *record);
extern int INTRUDE_COMM_IsValidObjCode(int value);
extern int INTRUDE_COMM_IsValidProfileCode(u32 a);
extern u32 GFL_NET_SYSTEM_GetConnectNum(void);
extern int GFL_NET_GetNegotiationNum(void);
extern void INTRUDE_COMM_SetSessionRequestSendFlag(IntrudeSession *session);
extern u32 func_0203F4FC(void);
extern int INTRUDE_CMD_SendJoinReply(int a, int b, int c);
extern void *memset(void *p, int value, unsigned int size);
extern int INTRUDE_CMD_SendProposalReply(int a, int b, int c, ...);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, u32 len);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201F184(struct WordSet *p, u32 i, s32 v);
extern u32 func_020056EC(u32 a);
extern void *PROCSYS_AllocProcWork(struct Proc *proc, u32 size, u32 heap);
extern void *PROCSYS_Create(int heap);
extern void *func_020120F4(const struct GameSystem *p);
extern void *func_02012934(const void *p);
extern void POKE_TOOL_HealParty(void *p);
extern u32 func_0201AA18(void *p);
extern struct Party *func_0201A920(u32 heap);
extern u32 POKEPARTY_IsMemberBattleReady(void *p, u32 idx);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_02019CA0(void *p, u32 v);
extern void func_02034714(const char *file, u32 line, const char *expr);
extern u32 func_02012138(const struct GameSystem *a);
extern u32 PROCSYS_Main(void *a);
extern u32 func_0200FB24(void);
extern int GFL_NET_IsSessionNull(void);
extern GFLNetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void BTL_SETUP_SetupCommSingle(u32 work, void *h, GFLNetHandle *handle, u32 p3, u16 p4);
extern void BTL_SETUP_SetParty(void *p, void *src, int i);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void GFL_NET_HANDLE_SetUserInfo(GFLNetHandle *handle, int timingLow, int timingHigh, int netID);
extern u32 func_02039CB4(GFLNetHandle *handle, u32 lo, u32 hi);
extern int func_02034AC4(int id);
extern void GFL_NET_COMMAND_AddCommandTable(u32 groupKey, u32 commandList, u32 listNum, u32 userData);
extern void PROCSYS_Push(u32 task, int b, void *c, IntrudePartyWork *w);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32 groupKey);
extern void func_02034A5C(int handle);
extern void BTL_SETUP_FreeSlots(IntrudePartyWork *w);
int INTRUDE_COMM_TakeNoticeState(IntrudeSession *session);
void INTRUDE_COMM_SetNoticeState(IntrudeSession *session, int noticeState);
int INTRUDE_COMM_FindFreeResultSlot(IntrudeSession *session, IntrudeMemberRecord *record, int netId);
int INTRUDE_COMM_StoreResultRecord(IntrudeSession *session, IntrudeMemberRecord *record, int netId);
int INTRUDE_COMM_GetJoinStatus(IntrudeCommSys *w, IntrudeSession *session);
void INTRUDE_COMM_ClearJoinStatus(IntrudeSession *session);
void INTRUDE_COMM_SetJoinStatus(IntrudeSession *session, u8 status);
void INTRUDE_COMM_PromoteRequestToResult(void *unused, IntrudeSession *session);
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
int INTRUDE_COMM_CountOutcomes(IntrudeSaveSlot *save, u8 *doneAsFirst, u8 *doneAsSecond);
int INTRUDE_COMM_PartyProcInit(struct Proc *proc, int unused, IntrudePartyParam *param);
int INTRUDE_COMM_PartyProcMain(void *proc, int *state, IntrudePartyParam *param, IntrudePartyWork *work);
extern IntrudePickRow gIntrudePickTable[];
extern u8 d_02177010[];
extern char d_021F03C4[];
extern u8 ov093_id[];
extern char d_021EFDAC[];


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
    if (func_0203EFC8((const u8 *)&session->request, (const u8 *)record, 0x30) != 0) {
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

void INTRUDE_COMM_SetJoinStatus(IntrudeSession *session, u8 status)
{
    session->joinStatus = status;
}

void INTRUDE_COMM_PromoteRequestToResult(void *unused, IntrudeSession *session)
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

    saveData = func_02026478(w->gameComm);
    result = &w->session.result;
    if (result->confirmed == 1) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        if (result->partnerIds[i] == func_02012B58(saveData)) {
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
    struct MemberRecord *partner;

    save = GAME_DATA_GetLastBattleRecSlot(saveData);
    partner = func_02012950(saveData, result->partnerIds[0]);
    statusCode = w->peers[result->partnerIds[0]].statusCode;
    outcome = INTRUDE_COMM_NormalizeVersion((u8)statusCode, func_02008530(partner));
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
 * extent: alignment at 02175ED6 then existing filed leaf ov011_func_02175ED8.c.
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
 * .word data; filed for ov011 func_02172D70, whose only unresolved call
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
    func_02082BCC(name, 0, 0x14);
    name->netId = 4;
}

void INTRUDE_COMM_FillMemberName(IntrudeCommSys *w, IntrudeMemberName *name, u8 netId)
{
    int record;
    name->netId = netId;
    record = GAME_DATA_GetMyStatusByNetId(func_02026478(w->gameComm), name->netId);
    func_020084F8((void *)record, name, 8);
    name->gender = func_02008550((const struct MemberRecord *)record);
}

/*
 * note:     the unlabelled 2-instruction leaf at 0x02175FB4 (ldrb r0,[r0,#0x10]; bx lr) follows.
 */
void INTRUDE_COMM_SetMemberEntry(IntrudeCommSys *w, IntrudeSession *session, u32 senderNetId, int memberIndex)
{
    void *saveData;
    IntrudeMemberEntry *entry;
    IntrudeNameChars *name;
    int record;
    int gender;
    u8 genderFlag;

    saveData = func_02026478(w->gameComm);
    entry = &session->members[memberIndex];
    if (entry->filled != 1) {
        name = (IntrudeNameChars *)GAME_DATA_GetBattleRecSlotByNetId(saveData, memberIndex);
        record = GAME_DATA_GetMyStatusByNetId(saveData, memberIndex);
        gender = func_0200855C((const struct MemberRecord *)record);
        genderFlag = INTRUDE_COMM_NormalizeVersion(gender, func_02008530((const struct MemberRecord *)record)) == 0x15;
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

    func_02082BCC(&session->slots[senderNetId], 0, sizeof(IntrudeProposalSlot));
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
    session->startTick = func_0203F4FC();
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
            if (((u8 *)session)[0xe8 + offset] != 0) {
                if (INTRUDE_CMD_SendJoinReply((int)w, (int)(((u8 *)session + 0xe8) + offset), i) == 1) {
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
        if (session->replyToSend[i] != 0 && INTRUDE_CMD_SendProposalReply((int)w, session->replyToSend[i], i) == 1) {
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
        return (int)func_02012B58(func_02026478(w->gameComm));
    }
    return session->request.name.netId;
}

/*
 * extent: two alignment bytes at 0217627E.
 */
int INTRUDE_COMM_IsRequestFromSelf(IntrudeCommSys *w)
{
    if (INTRUDE_COMM_IsRequestFromNetId(&w->session, func_02012B58(func_02026478(w->gameComm))) == 1) return 1;
    return 0;
}

void INTRUDE_COMM_SetWordSetPlayerName(struct WordSet *wordSet, u32 slot, const IntrudeNameChars *chars, u32 size, u16 heapId, u32 gender)
{
    struct U16Vec *buffer;

    buffer = STRBUF_Create(size, heapId);
    STRBUF_SetStringN((struct Strbuf *)buffer, chars->chars, size);
    func_0201EE0C(wordSet, slot, buffer, gender, 1, 2);
    STRBUF_Delete(buffer);
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
        func_0201EFA4(wordSet, 1, head->param.x, 3, 0, 1);
        break;
    case 1:
        INTRUDE_COMM_SetWordSetMemberName(wordSet, 0, name, heapId);
        func_0201F184(wordSet, 1, head->param.x);
        break;
    case 2:
        INTRUDE_COMM_SetWordSetMemberName(wordSet, 0, name, heapId);
        func_0201F184(wordSet, 1, head->param.x);
        break;
    case 3: {
        const IntrudeParamPair *param = &head->param;
        INTRUDE_COMM_SetWordSetMemberName(wordSet, 0, name, heapId);
        func_0201EF40(wordSet, 1, param->x);
        func_0201EFA4(wordSet, 2, param->y, 5, 0, 1);
        break;
    }
    case 4:
        func_0201EF40(wordSet, 0, head->param.y);
        INTRUDE_COMM_SetWordSetMemberName(wordSet, 1, name, heapId);
        break;
    case 5:
        INTRUDE_COMM_SetWordSetMemberName(wordSet, 0, name, heapId);
        break;
    }
    func_0201EFA4(wordSet, 2, head->amount, 4, 0, 1);
    count = head->count;
    if (count > 20) {
        count = 1;
    }
    func_0201EFA4(wordSet, 3, count, 4, 0, 1);
}

/*
 * Zeroes the six bytes at +6 one at a time, and after each store lets
 * INTRUDE_COMM_PickEntryForKind fill p[key] for key 0..5.  Called from arm9 func_0200BDE4
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
        if (kind == pick->kind && pick->minPoints <= points && (pick->flags & 2)) {
            level = pick->level;
            if (level == 100 || level >= func_020056EC(0x65)) {
                save->picks[kind] = row;
                return;
            }
        }
    }
}

/* Count the outcomes of the six kinds; 1 once all are done (the picks are then redrawn). */
int INTRUDE_COMM_CountOutcomes(IntrudeSaveSlot *save, u8 *doneAsFirst, u8 *doneAsSecond)
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
    func_02082BCC(work, 0, 0x100);
    work->asyncTask = PROCSYS_Create(4);
    list = func_02012934(func_020120F4(param->gameSystem));
    POKE_TOOL_HealParty(list);
    memberCount = func_0201AA18(list);
    work->party = func_0201A920(4);
    for (i = 0; i < memberCount; i++) {
        if (count >= param->maxCount) {
            break;
        }
        if (POKEPARTY_IsMemberBattleReady(list, i) == 1) {
            func_0201A98C(work->party, func_0201AB28(list, i));
            func_02019CA0(func_0201AB28(work->party, count), param->level);
            count++;
        }
    }
    if (count <= 0) {
        /* both strings are the empty string at 02177010 */
        func_02034714((const char *)d_02177010, 0, (const char *)d_02177010);
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

    window = func_020120F4(param->gameSystem);
    func_02012138(param->gameSystem);
    busy = PROCSYS_Main(work->asyncTask);
    if (func_0200FB24() != 0 || GFL_NET_IsSessionNull() == 1) {
        if (*state > 0 && *state < 6) {
            *state = 7;
        }
    }
    switch (*state) {
    case 0:
        BTL_SETUP_SetupCommSingle((u32)work, window, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        BTL_SETUP_SetParty(work, work->party, 0);
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
        if (func_02039CB4(GFL_NET_HANDLE_GetCurrentHandle(), 0x15, 2) == 1) {
            func_02034AC4((int)ov093_id);
            work->overlayLoaded = 1;
            GFL_NET_COMMAND_AddCommandTable(0x100, (u32)d_021F03C4, 9, 0);
            (*state)++;
        }
        break;
    case 3:
        GFL_NET_HANDLE_SetUserInfo(GFL_NET_HANDLE_GetCurrentHandle(), 0x16, 2, (u16)((1 << param->partnerNetId) | (1 << GFL_NET_SYSTEM_GetCurrentAid())));
        (*state)++;
        break;
    case 4:
        if (func_02039CB4(GFL_NET_HANDLE_GetCurrentHandle(), 0x16, 2) == 1) {
            (*state)++;
        }
        break;
    case 5:
        PROCSYS_Push((u32)work->asyncTask, -1, d_021EFDAC, work);
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
            func_02034A5C((int)ov093_id);
        }
        BTL_SETUP_FreeSlots(work);
        return 1;
    }
    return 0;
}
