/*
 * file:     unit_02173CB0.c
 * unit:     yes
 * function: INTRUDE_CMD_SendSaveSummary, INTRUDE_CMD_RecvEntryIndex, func_02173D2C, INTRUDE_CMD_RecvMemberEntry, INTRUDE_CMD_SendMemberEntry, INTRUDE_CMD_RecvJoinRequest, INTRUDE_CMD_SendJoinRequest, INTRUDE_CMD_RecvJoinReply, INTRUDE_CMD_SendJoinReply, INTRUDE_CMD_RecvGroupRecord, INTRUDE_CMD_SendGroupRecord, INTRUDE_CMD_RecvRecordEcho, INTRUDE_CMD_SendRecordEcho, INTRUDE_CMD_RecvRecordAccept, func_02173FC0, INTRUDE_CMD_SendMemberValue, INTRUDE_CMD_RecvProposal, func_0217405C, INTRUDE_CMD_RecvProposalReply, INTRUDE_CMD_SendProposalReply, INTRUDE_CMD_RecvResultRecord, INTRUDE_CMD_SendResultRecord, INTRUDE_CMD_RecvReadyNotice, func_02174258, INTRUDE_CMD_RecvStartNotice, INTRUDE_CMD_SendStartNotice, INTRUDE_CMD_RecvEndNotice, INTRUDE_CMD_SendEndNotice, INTRUDE_CMD_RecvProfile, INTRUDE_CMD_SendProfile, INTRUDE_CMD_RecvTallyWord
 * address:  0x02173CB0
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
 *   func_02026478  0x02026478  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   INTRUDE_COMM_IsLinked  0x021736D8  thumb ov011
 *   INTRUDE_COMM_BuildLocalProfile  0x02175648  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D4D0  0x0203D4D0  arm
 *   func_0203D378 0x0203D378 arm
 *   INTRUDE_COMM_SetMemberEntry 0x02175F34 thumb ov011
 *   INTRUDE_COMM_SetSessionEntrySendFlag 0x02175914 thumb ov011
 *   func_0203D3A8  0x0203D3A8  arm
 *   INTRUDE_COMM_StoreSessionEntry  0x02175938  thumb ov011
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_020127AC  0x020127AC  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   INTRUDE_COMM_ReceiveJoinRequest  0x02176048  thumb ov011
 *   func_0203D1E8  0x0203D1E8  arm
 *   NET_WHPIPE_SetBeaconStatus  0x021780FC  thumb ov014
 *   INTRUDE_COMM_ClearJoinReply  0x02176200  thumb ov011
 *   INTRUDE_COMM_StoreJoinReply  0x021761C4  thumb ov011
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_020127A4 0x020127A4 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   INTRUDE_COMM_StoreSessionRequest 0x02175954 thumb ov011
 *   GFL_NET_IsSendQueueEntryOfHandle  0x0203D578  arm
 *   func_02175B34 0x02175B34 thumb ov011
 *   func_0203EFC8 0x0203EFC8 arm
 *   INTRUDE_COMM_ClearSessionTicks 0x021759B0 thumb ov011
 *   INTRUDE_COMM_AddSessionMember 0x021759C0 thumb ov011
 *   INTRUDE_COMM_StartSessionTimer 0x021759F8 thumb ov011
 *   INTRUDE_COMM_StoreResultRecord 0x02175C88 thumb ov011
 *   INTRUDE_COMM_ClearJoinStatus  0x02175D20  thumb ov011
 *   INTRUDE_COMM_SetSessionFinished  0x02175BAC  thumb ov011
 *   INTRUDE_COMM_SetJoinStatus  0x02175D2C  thumb ov011
 *   func_020127B8  0x020127B8  thumb
 *   func_02175DA8  0x02175DA8  thumb  ov011
 *   func_021763D8  0x021763D8  thumb  ov011
 *   INTRUDE_COMM_RecordResultOutcome  0x02175E30  thumb  ov011
 *   INTRUDE_COMM_CountOutcomes  0x02176424  thumb  ov011
 *   INTRUDE_COMM_SetResultRecord  0x02175D7C  thumb  ov011
 *   INTRUDE_COMM_SetSessionReadyBit  0x02175C04  thumb ov011
 *   INTRUDE_COMM_SetNoticeState  0x02175C58  thumb ov011
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef signed char s8;
typedef signed short s16;

struct NetHandle;
typedef struct NetHandle NetHandle;

#include "intrude_comm_types.h"

void *func_02026478(void *obj);
void *func_02012EBC(void *saveData);
u16 *func_0200BE48(void *sys);
int INTRUDE_COMM_IsLinked(void);
void INTRUDE_COMM_BuildLocalProfile(void *saveData, void *out);
extern NetHandle *func_020399A8(void);
u32 func_0203D4D0(NetHandle *handle, u32 sendMask, u32 command, u32 size, void *data, u32 f, u32 g, u32 h);
u32 func_0203D378(void);
void INTRUDE_COMM_SetMemberEntry(IntrudeCommSys *w, IntrudeSession *session, u32 netId, int entryIndex);
void INTRUDE_COMM_SetSessionEntrySendFlag(IntrudeSession *session, int entryIndex);
int func_0203D3A8(NetHandle *handle, u32 command, u32 size, void *data);
void INTRUDE_COMM_StoreSessionEntry(IntrudeSession *session, const u16 *profile, int memberId);
u32 func_0203D1A4(NetHandle *handle);
void *func_020127AC(void *saveData, u32 slot);
void func_02082D44(void *src, void *dst, int size);
u32 func_0203D3F8(NetHandle *handle, unsigned char sendId, u32 command, u32 size, void *data, u32 f, u32 g, u32 h);
int INTRUDE_COMM_ReceiveJoinRequest(IntrudeCommSys *w, IntrudeSession *session, void *request, int netId);
void func_0203D1E8(NetHandle *handle, void *arg);
void NET_WHPIPE_SetBeaconStatus(u8 value);
void INTRUDE_COMM_ClearJoinReply(IntrudeSession *session);
void INTRUDE_COMM_StoreJoinReply(IntrudeSession *session, void *data);
u32 func_0203D1C0(u32 netId);
void *func_020127A4(void *saveData);
unsigned short func_02012AC8(void *playerWork);
int INTRUDE_COMM_StoreSessionRequest(IntrudeCommSys *w, IntrudeSession *session, IntrudeMemberRecord *record);
int GFL_NET_IsSendQueueEntryOfHandle(NetHandle *handle, int command);
u8 *func_02175B34(IntrudeSession *session);
s32 func_0203EFC8(const u8 *a, const u8 *b, u32 size);
void INTRUDE_COMM_ClearSessionTicks(IntrudeSession *session);
void INTRUDE_COMM_AddSessionMember(IntrudeSession *session, u8 netId);
void INTRUDE_COMM_StartSessionTimer(IntrudeSession *session, int value);
int INTRUDE_COMM_StoreResultRecord(IntrudeSession *session, IntrudeMemberRecord *record, int netId);
void INTRUDE_COMM_ClearJoinStatus(IntrudeSession *session);
void INTRUDE_COMM_SetSessionFinished(IntrudeSession *session);
void INTRUDE_COMM_SetJoinStatus(IntrudeSession *session, int value);
extern void *func_020127B8(void *saveData);
extern int func_02175DA8(IntrudeSession *session);
extern void func_021763D8(void *saveSlot, u32 kind);
extern void INTRUDE_COMM_RecordResultOutcome(void *saveData, IntrudeCommSys *w, IntrudeResultRecord *record);
extern int INTRUDE_COMM_CountOutcomes(void *saveSlot, u8 *outExtraA, u8 *outExtraB);
extern void INTRUDE_COMM_SetResultRecord(IntrudeCommSys *w, IntrudeSession *session, void *record);
void INTRUDE_COMM_SetSessionReadyBit(IntrudeSession *session, int netId);
void INTRUDE_COMM_SetNoticeState(IntrudeSession *session, int value);
int INTRUDE_CMD_SendSaveSummary(IntrudeCommSys *w, int sendMask);
void INTRUDE_CMD_RecvEntryIndex(u32 netId, int size, int *entryIndex, IntrudeCommSys *w);
int func_02173D2C(int unused, int entryIndex);
void INTRUDE_CMD_RecvMemberEntry(int netId, int size, IntrudeMemberEntry *entry, IntrudeCommSys *w);
int INTRUDE_CMD_SendMemberEntry(int unused, IntrudeSession *session, int memberIndex);
void INTRUDE_CMD_RecvJoinRequest(int netId, int size, IntrudeJoinRequest *request, IntrudeCommSys *w);
int INTRUDE_CMD_SendJoinRequest(IntrudeCommSys *w, void *request);
void INTRUDE_CMD_RecvJoinReply(int netId, int size, void *reply, IntrudeCommSys *w);
int INTRUDE_CMD_SendJoinReply(int unused, void *reply, int netId);
void INTRUDE_CMD_RecvGroupRecord(int netId, int size, IntrudeMemberRecord *record, IntrudeCommSys *w);
int INTRUDE_CMD_SendGroupRecord(IntrudeCommSys *w, IntrudeSession *session);
void INTRUDE_CMD_RecvRecordEcho(int netId, int size, void *record, IntrudeCommSys *w);
int INTRUDE_CMD_SendRecordEcho(int unused, IntrudeSession *session);
void INTRUDE_CMD_RecvRecordAccept(int netId, int size, void *record, IntrudeCommSys *w);
int func_02173FC0(int unused, IntrudeSession *session);
void INTRUDE_CMD_RecvMemberValue(int netId, int size, int *value, IntrudeCommSys *w);
int INTRUDE_CMD_SendMemberValue(int unused, int value, int sendMask);
void INTRUDE_CMD_RecvProposal(int netId, int size, IntrudeMemberRecord *record, IntrudeCommSys *w);
int func_0217405C(IntrudeCommSys *w, IntrudeSession *session);
void INTRUDE_CMD_RecvProposalReply(int netId, int size, int *value, IntrudeCommSys *w);
int INTRUDE_CMD_SendProposalReply(int unused, int value, int netId, ...);
void INTRUDE_CMD_RecvResultRecord(int netId, int size, IntrudeResultRecord *record, IntrudeCommSys *w);
int INTRUDE_CMD_SendResultRecord(IntrudeCommSys *w, IntrudeSession *session);
void INTRUDE_CMD_RecvReadyNotice(int netId, int size, int unused, IntrudeCommSys *w);
int func_02174258(IntrudeCommSys *w);
void INTRUDE_CMD_RecvStartNotice(int netId, int size, int unused, IntrudeCommSys *w);
int INTRUDE_CMD_SendStartNotice(int sendMask);
void INTRUDE_CMD_RecvEndNotice(int netId, int size, int unused, IntrudeCommSys *w);
u32 INTRUDE_CMD_SendEndNotice(u32 sendMask);
void INTRUDE_CMD_RecvProfile(int netId, int size, void *profile, IntrudeCommSys *w);
int INTRUDE_CMD_SendProfile(IntrudeCommSys *w);

int INTRUDE_CMD_SendSaveSummary(IntrudeCommSys *w, int sendMask)
{
    void *saveData;
    int summary[4];

    saveData = func_02026478(w->gameComm);
    func_0200BE48(func_02012EBC(saveData));
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    INTRUDE_COMM_BuildLocalProfile(saveData, summary);
    return func_0203D4D0(func_020399A8(), (unsigned char)sendMask, 0x20D, 0x10, summary, 0, 0, 0);
}

/*
 * note: Two alignment bytes follow; existing pkt_ov011_02173D2C covers
 *       the next function's push at 02173D2C. No unit is created.
 */
void INTRUDE_CMD_RecvEntryIndex(u32 netId, int size, int *entryIndex, IntrudeCommSys *w)
{
    if (func_0203D378()) {
        INTRUDE_COMM_SetMemberEntry(w, &w->session, netId, *entryIndex);
        INTRUDE_COMM_SetSessionEntrySendFlag(&w->session, *entryIndex);
    }
}

int func_02173D2C(int unused, int entryIndex)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    return func_0203D3A8(func_020399A8(), 0x20E, 4, &entryIndex);
}

void INTRUDE_CMD_RecvMemberEntry(int netId, int size, IntrudeMemberEntry *entry, IntrudeCommSys *w)
{
    void *saveData;
    int memberId;

    saveData = func_02026478(w->gameComm);
    memberId = entry->member.netId;
    INTRUDE_COMM_StoreSessionEntry(&w->session, entry->name.chars, memberId);
    if (memberId != func_0203D1A4(func_020399A8())) {
        func_02082D44(entry, func_020127AC(saveData, memberId), 0x10);
    }
}

int INTRUDE_CMD_SendMemberEntry(int unused, IntrudeSession *session, int memberIndex)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    return func_0203D3F8(func_020399A8(), 0xFF, 0x20F, 0x28, &session->members[memberIndex], 0, 0, 1);
}

void INTRUDE_CMD_RecvJoinRequest(int netId, int size, IntrudeJoinRequest *request, IntrudeCommSys *w)
{
    unsigned kind;

    if (func_0203D378()) {
        if (INTRUDE_COMM_ReceiveJoinRequest(w, &w->session, request, netId) == 1) {
            kind = request->head.kind;
            if (kind == 0 || kind == 3) {
                func_0203D1E8(func_020399A8(), 0);
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
    return func_0203D3A8(func_020399A8(), 0x210, 0x30, request);
}

void INTRUDE_CMD_RecvJoinReply(int netId, int size, void *reply, IntrudeCommSys *w)
{
    INTRUDE_COMM_StoreJoinReply(&w->session, reply);
}

int INTRUDE_CMD_SendJoinReply(int unused, void *reply, int netId)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    if (func_0203D1C0(netId & 0xFF) == 0) {
        return 1;
    }
    return func_0203D3F8(func_020399A8(), (unsigned char)netId, 0x211, 0x38, reply, 0, 0, 0);
}

void INTRUDE_CMD_RecvGroupRecord(int netId, int size, IntrudeMemberRecord *record, IntrudeCommSys *w)
{
    func_02012AC8(func_020127A4(func_02026478(w->gameComm)));
    if (INTRUDE_COMM_StoreSessionRequest(w, &w->session, record) == 1) w->entryReceived = 1;
}

int INTRUDE_CMD_SendGroupRecord(IntrudeCommSys *w, IntrudeSession *session)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    if (GFL_NET_IsSendQueueEntryOfHandle(func_020399A8(), 0x212) == 1) {
        return 0;
    }
    func_02082D44(&session->request, &w->recordCopy, 0x34);
    return func_0203D3F8(func_020399A8(), 0xFF, 0x212, 0x34, &w->recordCopy, 0, 0, 1);
}

void INTRUDE_CMD_RecvRecordEcho(int netId, int size, void *record, IntrudeCommSys *w)
{
    u8 *pending;
    pending = func_02175B34(&w->session);
    if (pending != 0 && func_0203EFC8(pending, record, 0x34) == 0) INTRUDE_COMM_ClearSessionTicks(&w->session);
}

/*
 * note: The matched void forwarder INTRUDE_COMM_IsLinked leaves r0 live and this
 *       caller tests it at 02173F7C. func_0203D3A8's final send result is
 *       returned in live r0 at 02173F94, so both externs return int here.
 */
int INTRUDE_CMD_SendRecordEcho(int unused, IntrudeSession *session)
{
    if (INTRUDE_COMM_IsLinked() == 0) return 0;
    return func_0203D3A8(func_020399A8(), 0x213, 0x34, &session->request);
}

void INTRUDE_CMD_RecvRecordAccept(int netId, int size, void *record, IntrudeCommSys *w)
{
    func_02175B34(&w->session);
    if (func_0203D378()) INTRUDE_COMM_AddSessionMember(&w->session, netId);
}

/*
 * note: Lead one run is EXACT*, followed by the root-claimed 02173FE4
 *       tail stub; tu verifies the complete 52-byte unit. INTRUDE_COMM_IsLinked's void forwarder
 *       leaves r0 live, tested at 02173FC8; func_0203D3A8's final send
 *       result is returned at 02173FE2. Follower loads a full word at
 *       02173FEA and forwards it without caller truncation.
 */
int func_02173FC0(int unused, IntrudeSession *session)
{
    if (INTRUDE_COMM_IsLinked() == 0) return 0;
    return func_0203D3A8(func_020399A8(), 0x214, 0x34, &session->request);
}

void INTRUDE_CMD_RecvMemberValue(int netId, int size, int *value, IntrudeCommSys *w)
{
    INTRUDE_COMM_StartSessionTimer(&w->session, *value);
}

int INTRUDE_CMD_SendMemberValue(int unused, int value, int sendMask)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    return func_0203D4D0(func_020399A8(), (unsigned char)sendMask, 0x215, 4, &value, 0, 0, 0);
}

void INTRUDE_CMD_RecvProposal(int netId, int size, IntrudeMemberRecord *record, IntrudeCommSys *w)
{
    if (func_0203D378()) INTRUDE_COMM_StoreResultRecord(&w->session, record, netId);
}

int func_0217405C(IntrudeCommSys *w, IntrudeSession *session)
{
    int result;

    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    INTRUDE_COMM_ClearJoinStatus(&w->session);
    result = func_0203D3A8(func_020399A8(), 0x216, 0x34, &session->request);
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
    if ((int)func_0203D1C0((unsigned char)netId) == 0) {
        return 1;
    }
    return func_0203D3F8(func_020399A8(), netId, 0x217, 4, &value, 0, 0, 0);
}

void INTRUDE_CMD_RecvResultRecord(int netId, int size, IntrudeResultRecord *record, IntrudeCommSys *w)
{
    u8 *saveSlot;
    int hasExtra;
    void *saveData;
    u8 extra[2];
    int tallyA;
    int tallyB;

    saveData = func_02026478(w->gameComm);
    saveSlot = func_020127B8(saveData);
    extra[1] = 0;
    hasExtra = 0;
    extra[0] = 0;
    tallyA = 0;
    tallyB = 0;
    if (record->record.netId == 4) {
        return;
    }
    if (func_02175DA8(&w->session) == 1) {
        return;
    }
    if (record->record.name.netId == func_0203D1A4(func_020399A8())) {
        if (record->confirmed == 1) {
            func_021763D8(saveSlot, record->record.head.kind);
            w->resultUpdated = 1;
        } else {
            INTRUDE_COMM_RecordResultOutcome(saveData, w, record);
            w->resultUpdated = 1;
        }
        if (INTRUDE_COMM_CountOutcomes(saveSlot, &extra[1], &extra[0]) == 1) {
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
    if (GFL_NET_IsSendQueueEntryOfHandle(func_020399A8(), 0x218) == 1) {
        return 0;
    }
    func_02082D44(&session->result, &w->resultCopy, 0x3c);
    return func_0203D3F8(func_020399A8(), 0xff, 0x218, 0x3c, &w->resultCopy, 0, 0, 1);
}

void INTRUDE_CMD_RecvReadyNotice(int netId, int size, int unused, IntrudeCommSys *w)
{
    INTRUDE_COMM_SetSessionReadyBit(&w->session, netId);
}

int func_02174258(IntrudeCommSys *w)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    INTRUDE_COMM_SetNoticeState(&w->session, 0);
    return func_0203D3F8(func_020399A8(), 0, 0x219, 0, 0, 0, 0, 0);
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
    return func_0203D4D0(func_020399A8(), sendMask, 0x21a, 0, 0, 0, 0, 0);
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
    return func_0203D4D0(func_020399A8(), sendMask, 0x21b, 0, 0, 0, 0, 0);
}

void INTRUDE_CMD_RecvProfile(int netId, int size, void *profile, IntrudeCommSys *w)
{
    void *saveData;

    saveData = func_02026478(w->gameComm);
    if (netId != func_0203D1A4(func_020399A8()) && (w->peerMask & (1 << netId))) {
        func_02082D44(profile, func_020127AC(saveData, netId), 0x10);
        if (netId == w->localPeer.intrudeId) {
            w->profileUpdated = 1;
        }
    }
}

int INTRUDE_CMD_SendProfile(IntrudeCommSys *w)
{
    void *profile;

    profile = func_020127B8(func_02026478(w->gameComm));
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    return func_0203D3A8(func_020399A8(), 0x21c, 0x10, profile);
}

void INTRUDE_CMD_RecvTallyWord(int netId, int size, void *data, IntrudeCommSys *w)
{
    func_02082D44(data, &w->partnerTally, 4);
}
