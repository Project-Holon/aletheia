/*
 * file:     unit_02173658.c
 * unit:     yes
 * function: INTRUDE_COMM_AgeFoundList, INTRUDE_COMM_GetStatusArea, INTRUDE_COMM_GetMemberRecord, INTRUDE_COMM_GetStatusRecord, INTRUDE_COMM_GetWorkArea, INTRUDE_COMM_IsLinked, func_021736E0, INTRUDE_COMM_SendShutdownRequest, INTRUDE_COMM_RecvMemberCount, INTRUDE_COMM_SendMemberCount, INTRUDE_COMM_RecvRecordRequest, INTRUDE_COMM_SendRecordRequest, INTRUDE_COMM_RecvStatusRecord, INTRUDE_COMM_SendStatusRecord, INTRUDE_COMM_RecvPeerLeft, INTRUDE_COMM_SendPeerLeft, INTRUDE_COMM_RecvPeerStatus, INTRUDE_COMM_SendPeerStatus, INTRUDE_COMM_RecvTimeoutWarning, INTRUDE_COMM_SendTimeoutWarning, func_02173A04, func_02173A2C, INTRUDE_COMM_RecvReply, func_02173AE0, INTRUDE_COMM_RecvNotice, INTRUDE_COMM_SendNotice, INTRUDE_COMM_RecvAnswer, func_02173B9C, INTRUDE_COMM_RecvNoticeBytes, func_02173C04, INTRUDE_COMM_RecvReady, func_02173C6C, INTRUDE_COMM_RecvRemoteRecord
 * address:  0x02173658
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
 *   INTRUDE_COMM_HasConnectedPeers  0x02175628  thumb
 *   func_02039338 0x02039338 arm
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02026478 0x02026478 thumb
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02012B4C 0x02012B4C thumb
 *   func_0203D3F8  0x0203D3F8  arm
 *   INTRUDE_COMM_ApplyPlayerBeacon  0x02174EAC  thumb  ov011
 *   func_02012B58  0x02012B58  thumb
 *   func_0203D378  0x0203D378  arm
 *   GFL_NET_IsSendQueueEntryOfHandle  0x0203D578  arm
 *   func_02082D44  0x02082D44  arm
 *   INTRUDE_COMM_SetSessionRequestSendFlag  0x02175920  thumb ov011
 *   INTRUDE_COMM_SetSessionResultSendFlag  0x0217592C  thumb ov011
 *   func_02167658 0x02167658 thumb ov010
 *   GAME_COMM_UpdatePlayerStatus  0x020264B4  thumb
 *   INTRUDE_COMM_StorePlayerRecord  0x02174F54  thumb ov011
 *   INTRUDE_COMM_TryStartRequest 0x021753D0 thumb ov011
 *   func_02082BCC  0x02082BCC  arm
 *   INTRUDE_COMM_SetRequestResult 0x021754E8 thumb ov011
 *   INTRUDE_COMM_SetRequestResultAccepted  0x02175508  thumb ov011
 */

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

#include "../arm9/net_types.h"
#include "intrude_comm_types.h"

struct GameData;
struct GameComm;

int INTRUDE_COMM_HasConnectedPeers(void);
extern u16 func_02039338(void);
extern GFLNetHandle *func_020399A8(void);
extern int func_0203D3A8(GFLNetHandle *handle, u32 command, u32 size, const void *data);
extern struct GameData *func_02026478(struct GameComm *gameComm);
extern unsigned int func_0203D1A4(GFLNetHandle *handle);
extern void func_02012B4C(struct GameData *gameData, u8 enterMode);
extern u32 func_0203D3F8(GFLNetHandle *handle, u32 sendId, u32 command, u32 size, const void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode);
extern void INTRUDE_COMM_ApplyPlayerBeacon(u8 *work, int netId, u8 *record);
extern u8 func_02012B58(const struct GameData *gameData);
extern u32 func_0203D378(void);
int GFL_NET_IsSendQueueEntryOfHandle(GFLNetHandle *handle, int command);
void func_02082D44(const void *src, void *dst, int size);
void INTRUDE_COMM_SetSessionRequestSendFlag(void *session);
void INTRUDE_COMM_SetSessionResultSendFlag(void *session);
extern void func_02167658(struct CommPlayerWork *commPlayer, int netId);
void GAME_COMM_UpdatePlayerStatus(struct GameComm *gameComm, int netId, u16 zoneId, u8 intrudeId, u32 fieldStatus, int quiet);
void INTRUDE_COMM_StorePlayerRecord(u8 *work, int netId, const IntrudePeer *peer, int arg);
int INTRUDE_COMM_TryStartRequest(IntrudeCommSys *work, int netId, u8 seq);
void func_02082BCC(void *dst, int value, int size);
void INTRUDE_COMM_SetRequestResult(IntrudeCommSys *work, int netId, int answer, int seq);
void INTRUDE_COMM_SetRequestResultAccepted(IntrudeCommSys *work, int netId, int value);
void INTRUDE_COMM_AgeFoundList(IntrudeCommSys *work);
u8 *INTRUDE_COMM_GetStatusArea(int unused, IntrudeCommSys *work);
IntrudeMemberRecord *INTRUDE_COMM_GetMemberRecord(int index, IntrudeCommSys *work);
IntrudeStatusRecord *INTRUDE_COMM_GetStatusRecord(int index, IntrudeCommSys *work);
u8 *INTRUDE_COMM_GetWorkArea(int unused, IntrudeCommSys *work);
int INTRUDE_COMM_IsLinked(void);
void func_021736E0(int netId, int size, int data, IntrudeCommSys *work, unsigned int handle);
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
void func_02173A04(int netId, int size, IntrudeRequestMessage *request, IntrudeCommSys *work);
int func_02173A2C(IntrudeCommSys *work, int destNetId, IntrudeMemberRecord *data, int type);
void INTRUDE_COMM_RecvReply(int netId, int size, u8 *reply, IntrudeCommSys *work);
int func_02173AE0(int unused, int destNetId, int answer, int seq);
void INTRUDE_COMM_RecvNotice(int netId, int size, u8 *notice, IntrudeCommSys *work);
int INTRUDE_COMM_SendNotice(IntrudeCommSys *work, int destNetId, int value);
void INTRUDE_COMM_RecvAnswer(int netId, int size, u8 *data, IntrudeCommSys *work);
int func_02173B9C(int destNetId, int value);
void INTRUDE_COMM_RecvNoticeBytes(int netId, int size, const u8 *data, IntrudeCommSys *work);
int func_02173C04(int destNetId, int value);
void INTRUDE_COMM_RecvReady(int netId, int size, int data, IntrudeCommSys *work);
int func_02173C6C(int unused, int destNetId);




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




void func_021736E0(int netId, int size, int data, IntrudeCommSys *work, unsigned int handle)
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
        netId = func_02039338();
        func_021736E0(netId, 0, 0, work, (unsigned int)func_020399A8());
        return 1;
    }
    return func_0203D3A8(func_020399A8(), 0x200, 0, 0);
}




/*
 * The loaded byte stays live as r1 into 02012B4C.
 */
void INTRUDE_COMM_RecvMemberCount(unsigned int netId, int size, u8 *data, IntrudeCommSys *work)
{
    struct GameData *gameData;
    unsigned int count;
    gameData = func_02026478(work->gameComm);
    if (netId != func_0203D1A4(func_020399A8())) {
        count = *data;
        work->memberCount = count;
        func_02012B4C(gameData, count);
    }
}




/*
 * Handed as 0x0217375A; the function starts at the push {r0-r3} at 0x02173758.
 */
int INTRUDE_COMM_SendMemberCount(IntrudeCommSys *work, int memberCount, ...)
{
    if (INTRUDE_COMM_IsLinked() == 0)
        return 0;
    return func_0203D3F8(func_020399A8(), 0xff, 0x201, 1, &memberCount, 1, 0, 0);
}


void INTRUDE_COMM_RecvRecordRequest(int netId, int size, int data, IntrudeCommSys *work) { work->resendRequested = 1; }





/*
 * Return-valued externs reflect r0 consumed after both forwarding calls.
 */
int INTRUDE_COMM_SendRecordRequest(void)
{
    if (INTRUDE_COMM_IsLinked() == 0)
        return 0;
    return func_0203D3A8(func_020399A8(), 0x202, 0, 0);
}






void INTRUDE_COMM_RecvStatusRecord(int netId, int size, IntrudeStatusRecord *record, IntrudeCommSys *work)
{
    int gameData;

    gameData = (int)func_02026478(work->gameComm);
    if (netId < work->memberCount) {
        INTRUDE_COMM_ApplyPlayerBeacon((u8 *)work, netId, (u8 *)record);
        if (netId != func_02012B58((const struct GameData *)gameData) && func_0203D378() == 0 && netId == 0 && record->peer.startFlag == 1)
            work->startFlag = 1;
    }
}






int INTRUDE_COMM_SendStatusRecord(IntrudeCommSys *work)
{
    int result;

    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    if (GFL_NET_IsSendQueueEntryOfHandle(func_020399A8(), 0x203) == 1) {
        return 0;
    }
    func_02082D44(work->ownMyStatus, work->sendBuffer, 0x4C);
    result = func_0203D3F8(func_020399A8(), 0xFF, 0x203, 0x4C, work->sendBuffer, 0, 0, 1);
    if (result == 1) {
        work->resendRequested = 0;
        if (func_0203D378() == 1) {
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
        func_02167658(work->commPlayer, leavingNetId);
    }
}






int INTRUDE_COMM_SendPeerLeft(IntrudeCommSys *work, int leavingNetId)
{
    int selfNetId;

    if (INTRUDE_COMM_IsLinked() == 0) {
        selfNetId = func_02039338();
        INTRUDE_COMM_RecvPeerLeft(selfNetId, 4, &leavingNetId, work, func_020399A8());
        return 1;
    }
    return func_0203D3A8(func_020399A8(), 0x204, 4, &leavingNetId);
}




void INTRUDE_COMM_RecvPeerStatus(int netId, int size, const IntrudePeer *peer, IntrudeCommSys *work)
{
    if (netId == func_0203D1A4(func_020399A8())) {
        GAME_COMM_UpdatePlayerStatus(work->gameComm, netId, peer->zoneId, peer->intrudeId, 0x15, 0);
    } else if ((work->peerMask & (1 << netId)) != 0) {
        INTRUDE_COMM_StorePlayerRecord((u8 *)work, netId, peer, 0);
    }
}



int INTRUDE_COMM_SendPeerStatus(IntrudeCommSys *work, const IntrudePeer *peer)
{
    int result;

    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    result = func_0203D3F8(func_020399A8(), 0xFF, 0x205, 0x1C, peer, 0, 1, 0);
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
    return func_0203D3A8(func_020399A8(), 0x206, 0, 0);
}





void func_02173A04(int netId, int size, IntrudeRequestMessage *request, IntrudeCommSys *work)
{
    if (INTRUDE_COMM_TryStartRequest(work, netId, request->seq) == 1) work->receivedRequest = *request;
}





int func_02173A2C(IntrudeCommSys *work, int destNetId, IntrudeMemberRecord *data, int type)
{
    IntrudeRequestMessage message;
    int result;

    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    if (work->nextRequestSeq == 0) {
        work->nextRequestSeq++;
    }
    func_02082BCC(&message, 0, 0x38);
    message.type = type;
    message.data = *data;
    message.seq = work->nextRequestSeq;
    result = func_0203D3F8(func_020399A8(), (unsigned char)destNetId, 0x207, 0x38, &message, 0, 0, 0);
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




int func_02173AE0(int unused, int destNetId, int answer, int seq)
{
    unsigned char message[4];

    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    message[0] = answer;
    message[1] = seq;
    return func_0203D3F8(func_020399A8(), (unsigned char)destNetId, 0x208, 4, message, 0, 0, 0);
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
    return func_0203D3F8(func_020399A8(), (unsigned char)destNetId, 0x209, 1, &value, 0, 0, 0);
}


void INTRUDE_COMM_RecvAnswer(int netId, int size, u8 *data, IntrudeCommSys *work)
{
    INTRUDE_COMM_SetRequestResultAccepted(work, netId, *data);
}



int func_02173B9C(int destNetId, int value)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    return func_0203D3F8(func_020399A8(), (unsigned char)destNetId, 0x20A, 1, &value, 0, 0, 0);
}


/*
 * sdk:      DWCi_CheckDWCServer (dwc_match.o)
 */
void INTRUDE_COMM_RecvNoticeBytes(int netId, int size, const u8 *data, IntrudeCommSys *work)
{
    work->notice.value[0] = data[0];
    work->notice.value[1] = data[1];
    work->notice.value[2] = data[2];
    work->notice.value[3] = data[3];
}



int func_02173C04(int destNetId, int value)
{
    unsigned char message[4];

    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    func_02082BCC(message, 0, 4);
    message[0] = 1;
    message[1] = value;
    return func_0203D3F8(func_020399A8(), (unsigned char)destNetId, 0x20B, 4, message, 0, 0, 0);
}


void INTRUDE_COMM_RecvReady(int netId, int size, int data, IntrudeCommSys *work) { work->readyMask |= (u8)(1 << netId); }


int func_02173C6C(int unused, int destNetId)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return func_0203D3F8(func_020399A8(), destNetId, 0x20C, 0, 0, 0, 0, 0);
}


void INTRUDE_COMM_RecvRemoteRecord(int netId, int size, IntrudeRemoteRecord *record, IntrudeCommSys *work)
{
    work->remoteRecord = *record;
}
