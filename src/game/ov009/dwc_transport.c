/*
 * file:     dwc_transport.c
 * unit:     yes
 * function: DWC_IsSendableReliable, DWCi_IsSendableReliable, DWC_SendReliable, DWCi_SendReliable, DWC_SendReliableBitmap, DWC_SendUnreliable, DWC_SetRecvBuffer, DWC_SetUserSendCallback, DWC_SetUserRecvCallback, DWC_SetUserRecvTimeoutCallback, DWCs_EncodeHeader, DWCs_DecodeHeader, DWCs_GetRequiredHeaderSize, DWC_SetRecvTimeoutTime, DWC_SetConnectionKeepAliveTime, DWC_GetConnectionKeepAliveTime, DWCi_InitTransport, DWCi_RecvCallback, DWCi_PingCallback, DWCi_TransportProcess, DWCi_ClearTransConnection, DWCi_ShutdownTransport, DWCi_ResetLastSomeDataRecvTimeByAid, DWCs_GetTransConnection, DWCs_GetSendState, DWCs_GetRecvState, DWCs_Send, DWCi_SendUnreliable, DWCs_HandleReliableMessage, DWCs_HandleUnreliableMessage, DWCs_RecvDataHeader, DWCs_RecvDataBody, DWCs_RecvSystemDataBody, DWCs_GetOutgoingBufferFreeSize, DWCs_UpdateConnectionKeepAliveTime
 * address:  0x02176DEC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_IsError          0x02059F38  arm
 *   DWC_IsValidAID         0x0216B94C  arm  ov009
 *   DWCi_IsValidAID        0x0216BC3C  arm  ov009
 *   DWCs_GetSendState          0x02177788  arm  ov009
 *   DWCs_GetOutgoingBufferFreeSize  0x02177E64  arm  ov009
 *   DWCs_GetRequiredHeaderSize      0x0217721C  arm  ov009
 *   DWCi_IsReliableQueueFree          0x02176BE4  arm  ov009
 *   DWCs_GetTransConnection  0x02177770  arm  ov009
 *   DWCs_EncodeHeader  0x021771B0  arm  ov009
 *   DWCs_Send  0x021777C0  arm  ov009
 *   DWCs_GetOutgoingBufferFreeSize  0x02177E64  arm  ov009
 *   gDwcTransInfo  0x021AB180  data
 *   DWC_GetMyAID                   0x0216B838  arm ov009
 *   DWC_GetMyAID   0x0216B838  arm ov009
 *   DWCi_SendUnreliable  0x02177848  arm  ov009
 *   DWCs_GetTransConnection  0x02177770 arm
 *   DWCs_GetRecvState        0x021777A4 arm
 *   strncpy      0x02094860 arm
 *   gDwcTransHeaderMagic   0x021A2344 data
 *   MI_CpuCopy8  0x02082D44 arm
 *   memcmp       0x020923F0 arm
 *   DWCi_NodeInfoList_GetCount  0x0217603C arm
 *   OS_GetTick   0x020870D0 arm
 *   MI_CpuFill8                    0x02082BCC arm
 *   DWC_SetConnectionKeepAliveTime 0x021772B8 arm
 *   DWCi_InitReliableQueue         0x02176B68 arm
 *   DWCs_UpdateConnectionKeepAliveTime  0x02177E88 arm
 *   DWCi_GetConnectionAID  0x0216BB54 arm
 *   DWC_GetAIDList                   0x0216b880  arm
 *   DWC_GetConnectionKeepAliveTime   0x021772dc  arm
 *   DWC_IsServerMyself               0x0216ba08  arm
 *   DWCi_IsServerChanging            0x02175efc  arm
 *   DWCi_IsBackupMine                0x021754fc  arm
 *   _ll_udiv                         0x0209c00c  arm
 *   DWCi_CloseConnectionHard         0x0216bea4  arm
 *   DWCi_SendServerPolling           0x0217576c  arm
 *   DWCi_GetServerOrSubServerAID     0x0216c800  arm
 *   DWCi_ProcessReliableQueue        0x02176c00  arm
 *   DWCs_GetSendState                0x02177788  arm
 *   DWCs_Send                        0x021777c0  arm
 *   DWCi_CleanupReliableQueue  0x02176B80  arm  ov009
 *   DWCi_GetGT2Connection  0x0216BAF4  arm  ov009
 *   DWCi_ProcessReliableQueue  0x02176C00  arm  ov009
 *   gt2Send        0x02195CC0  arm  ov009
 *   DWCi_InsertReliableQueue  0x02176CF8  arm  ov009
 *   DWCi_SetError  0x02059F54  arm
 *   DWCi_GetGT2Connection                  0x0216BAF4 arm
 *   DWCi_NodeInfoList_GetNodeInfoForIndex  0x0217637C arm
 *   DWC_Alloc                              0x0205A16C arm
 *   DWC_Free                               0x0205A1B0 arm
 *   gDwcTransForwardMagic                             0x021A2348 data
 *   strncmp                                     0x020949F4 arm
 *   DWCi_HandleGT2UnreliableMatchCommandMessage 0x02174E10 arm
 *   gDwcTransMatchMagic                                  0x021A234C data
 *   DWCi_ProcessMatchSynPacket  0x0216EC4C arm
 *   gt2GetOutgoingBufferFreeSpace     0x02195E50 arm
 */
#include "dwc_match.h"
#ifdef __MWERKS__
/* The callers read the AID as an unmasked byte, so the original declaration returns a byte;
   dwc_main.c defines the function with an int return. */
#define DWCi_GetConnectionAID DWCi_GetConnectionAID_int
#include "dwc_main.h"
#undef DWCi_GetConnectionAID
extern unsigned char DWCi_GetConnectionAID(void *connection);
#else
#include "dwc_main.h"
#endif

#include "../types.h"

typedef struct {
    unsigned long size;
    unsigned short type;
    char magicStrings[2];
} TransHeader;

typedef struct {
    unsigned char *sendBuffer;
    unsigned char *recvBuffer;
    int recvBufferSize;
    int sendingSize;
    int recvingSize;
    int requestSendSize;
    int requestRecvSize;
    unsigned char sendState;
    unsigned char recvState;
    unsigned char lastRecvState;
    unsigned char pads[3];
    unsigned short lastRecvType;
    u64 previousRecvTick;
    unsigned long recvTimeoutTime;
    u64 lastSomeDataRecvTick;
} TransConn;

typedef struct TransInfo {
    TransConn connections[32];
    void (*sendCallback)(int, unsigned char, void *);
    void (*recvCallback)(unsigned char, unsigned char *, int, void *);
    void (*recvTimeoutCallback)(unsigned char, void *);
    void (*pingCallback)(int, unsigned char, void *);
    void *sendCallbackParam;
    void *recvCallbackParam;
    void *recvTimeoutCallbackParam;
    void *pingCallbackParam;
    unsigned short sendSplitMax;
    unsigned long connKeepAliveTime;
} TransInfo;

#include "../arm9/dwc_error.h"
extern int DWC_IsValidAID(unsigned char aid);
extern int DWCi_IsValidAID(unsigned char aid);
#include "../arm9/msl_string_str.h"
#include "../arm9/mi_memory.h"
#include "../arm9/msl_string_mem.h"
extern int DWCi_NodeInfoList_GetCount(void);
#include "../arm9/os_tick.h"
extern void DWCi_InitReliableQueue(void);
extern int DWC_GetAIDList(unsigned char **aidList);
extern int DWC_IsServerMyself(void);
extern int DWCi_IsServerChanging(void);
extern int DWCi_IsBackupMine(void);
extern unsigned char DWC_GetMyAID(void);
extern int DWCi_CloseConnectionHard(unsigned char aid);
extern int DWCi_SendServerPolling(int immediate);
extern unsigned char DWCi_GetServerOrSubServerAID(void);
#include "dwc_reliable.h"
#include "gt2main.h"
extern void *DWCi_GetGT2Connection(unsigned char aid);
#include "../arm9/dwc_memfunc.h"
extern void DWCi_HandleGT2UnreliableMatchCommandMessage(void *data, int len);
extern void DWCi_ProcessMatchSynPacket(unsigned char aid, unsigned short type, unsigned char *data);
extern TransInfo *gDwcTransInfo;
extern char gDwcTransHeaderMagic[];
extern char gDwcTransForwardMagic[];
extern char gDwcTransMatchMagic[];

int DWC_IsSendableReliable(unsigned char a);
static int DWCi_IsSendableReliable(unsigned char aid, unsigned short type);
int DWC_SendReliable(unsigned char aid, void *buffer, int size);
int DWCi_SendReliable(unsigned short type, unsigned char aid, void *buffer, int size);
unsigned long DWC_SendReliableBitmap(unsigned long bitmap, void *buffer, int size);
int DWC_SendUnreliable(unsigned char aid, void *buffer, int size);
int DWC_SetRecvBuffer(unsigned char aid, void *recvBuffer, int size);
int DWC_SetUserSendCallback(void (*cb)(int, unsigned char, void *), void *param);
int DWC_SetUserRecvCallback(void (*cb)(unsigned char, unsigned char *, int, void *), void *param);
int DWC_SetUserRecvTimeoutCallback(void (*cb)(unsigned char, void *), void *param);
void DWCs_EncodeHeader(TransHeader *header, unsigned short type, int size);
unsigned short DWCs_DecodeHeader(void *message);
long DWCs_GetRequiredHeaderSize(unsigned short type);
int DWC_SetRecvTimeoutTime(unsigned char aid, unsigned long time);
int DWC_SetConnectionKeepAliveTime(unsigned long v);
unsigned long DWC_GetConnectionKeepAliveTime(void);
void DWCi_InitTransport(TransInfo *info);
void DWCi_RecvCallback(void *connection, unsigned char *message, int size, int reliable);
void DWCi_PingCallback(void *connection, int latency);
void DWCi_TransportProcess(void);
void DWCi_ClearTransConnection(int i);
void DWCi_ShutdownTransport(void);
void DWCi_ResetLastSomeDataRecvTimeByAid(int aid);
TransConn *DWCs_GetTransConnection(int i);
unsigned char DWCs_GetSendState(int i);
unsigned char DWCs_GetRecvState(int i);
void DWCs_Send(unsigned char aid, unsigned char *buffer, int size, int reliable);
void DWCi_SendUnreliable(unsigned char aidFrom, unsigned char aidTo, unsigned char *buffer, int size, int fromDWC_SendUnreliable);
void DWCs_HandleReliableMessage(void *connection, unsigned char *message, int size);
void DWCs_HandleUnreliableMessage(void *connection, void *message, int size);
void DWCs_RecvDataHeader(unsigned char aid, void *message, int size);
void DWCs_RecvDataBody(unsigned char aid, void *message, int size);
void DWCs_RecvSystemDataBody(unsigned char aid, void *message, int size);
int DWCs_GetOutgoingBufferFreeSize(unsigned char aid);
void DWCs_UpdateConnectionKeepAliveTime(void *connection);

/*
 * Tail call that supplies the second argument 1.
 */
int DWC_IsSendableReliable(unsigned char a)
{
    return DWCi_IsSendableReliable(a, 1);
}

/*
 * sdk:      DWCi_IsSendableReliable (libdwcmatch.TWL.HYB.a dwc_transport.o)
 */
static int DWCi_IsSendableReliable(unsigned char aid, unsigned short type)
{
    long freeSpace;

    if (DWCi_IsError() != 0 || (type == 1 && DWC_IsValidAID(aid) == 0))
        return 0;
    if (DWCi_IsValidAID(aid) == 0)
        return 0;
    if (DWCs_GetSendState(aid) == 1)
        return 0;
    freeSpace = DWCs_GetOutgoingBufferFreeSize(aid);
    if (freeSpace < DWCs_GetRequiredHeaderSize(type))
        return 0;
    return DWCi_IsReliableQueueFree() != 0;
}

/*
 * sdk:      DWC_SendReliable
 */
int DWC_SendReliable(unsigned char aid, void *buffer, int size)
{
    return DWCi_SendReliable(1, aid, buffer, size);
}

int DWCi_SendReliable(unsigned short type, unsigned char aid, void *buffer, int size)
{
    int freeSpace;
    int sendSize;
    TransHeader header;
    TransConn *transConnection;

    transConnection = DWCs_GetTransConnection(aid);
    if (!DWCi_IsSendableReliable(aid, type))
        return 0;
    transConnection->sendState = 1;
    transConnection->sendBuffer = buffer;
    transConnection->sendingSize = 0;
    transConnection->requestSendSize = size;
    DWCs_EncodeHeader(&header, type, size);
    DWCs_Send(aid, (unsigned char *)&header, 8, 1);
    sendSize = gDwcTransInfo->sendSplitMax;
    if (size <= sendSize)
        sendSize = size;
    freeSpace = DWCs_GetOutgoingBufferFreeSize(aid);
    if (sendSize > freeSpace)
        return 1;
    DWCs_Send(aid, buffer, sendSize, 1);
    transConnection->sendingSize += sendSize;
    freeSpace = transConnection->requestSendSize;
    if (transConnection->sendingSize == freeSpace) {
        transConnection->sendState = 0;
        transConnection->sendBuffer = 0;
        transConnection->sendingSize = 0;
        transConnection->requestSendSize = 0;
        if (gDwcTransInfo->sendCallback && type == 1)
            gDwcTransInfo->sendCallback(freeSpace, aid, gDwcTransInfo->sendCallbackParam);
    }
    return 1;
}

/*
 * sdk:      DWC_SendReliableBitmap (dwc_transport.o)
 *
 * Closed (w5_nm): the bit is the conditional expression
 * `(aid != 0) ? (1 << aid) : 1`, which keeps the two constant 1s in separate
 * registers (r7 for the zero case, r8 for the shift); the statement form with
 * a later `if (aid == 0) aidbit = 1;` shared one register.
 */
unsigned long DWC_SendReliableBitmap(unsigned long bitmap, void *buffer, int size)
{
    unsigned long aidbit;
    unsigned char aid;

    for (aid = 0; aid < 32; aid++) {
        aidbit = (aid != 0) ? (1 << aid) : 1;
        if ((bitmap & aidbit) == 0)
            continue;
        if (aid == DWC_GetMyAID())
            continue;
        if (DWC_SendReliable(aid, buffer, size) == 0)
            bitmap &= ~aidbit;
    }
    return bitmap;
}

/*
 * sdk:      DWC_SendUnreliable (libdwcmatch.TWL.HYB.a dwc_transport.o)
 */
int DWC_SendUnreliable(unsigned char aid, void *buffer, int size)
{
    if (DWCi_IsError() != 0)
        return 0;
    if (DWC_IsValidAID(aid) == 0)
        return 0;
    if (size > 0x5B6)
        return 0;
    DWCi_SendUnreliable(DWC_GetMyAID(), aid, buffer, size, 1);
    if (gDwcTransInfo->sendCallback != 0)
        gDwcTransInfo->sendCallback(size, aid, gDwcTransInfo->sendCallbackParam);
    return 1;
}

int DWC_SetRecvBuffer(unsigned char aid, void *recvBuffer, int size)
{
    TransConn *connection = DWCs_GetTransConnection(aid);

    if (DWCs_GetRecvState(aid) == 2)
        return 0;
    connection->recvBuffer = recvBuffer;
    connection->recvBufferSize = size;
    connection->recvState = 1;
    connection->recvingSize = 0;
    connection->requestRecvSize = 0;
    return 1;
}

int DWC_SetUserSendCallback(void (*cb)(int, unsigned char, void *), void *param)
{
    TransInfo *p = gDwcTransInfo;

    if (p == 0)
        return 0;
    p->sendCallback = cb;
    gDwcTransInfo->sendCallbackParam = param;
    return 1;
}

int DWC_SetUserRecvCallback(void (*cb)(unsigned char, unsigned char *, int, void *), void *param)
{
    TransInfo *p = gDwcTransInfo;

    if (p == 0)
        return 0;
    p->recvCallback = cb;
    gDwcTransInfo->recvCallbackParam = param;
    return 1;
}

int DWC_SetUserRecvTimeoutCallback(void (*cb)(unsigned char, void *), void *param)
{
    TransInfo *p = gDwcTransInfo;

    if (p == 0)
        return 0;
    p->recvTimeoutCallback = cb;
    gDwcTransInfo->recvTimeoutCallbackParam = param;
    return 1;
}

void DWCs_EncodeHeader(TransHeader *header, unsigned short type, int size)
{
    strncpy(header->magicStrings, gDwcTransHeaderMagic, 2);
    header->type = type;
    header->size = size;
}

unsigned short DWCs_DecodeHeader(void *message)
{
    TransHeader header;

    MI_CpuCopy8(message, &header, 8);
    if (memcmp((unsigned char *)header.magicStrings, (unsigned char *)gDwcTransHeaderMagic, 2) == 0)
        return header.type;
    return 0;
}

long DWCs_GetRequiredHeaderSize(unsigned short type)
{
    int clientCount;

    switch (type) {
    case 2:
        return 0x24;
    case 3:
        return 0x0c;
    case 4:
        clientCount = DWCi_NodeInfoList_GetCount();
        return (clientCount - 1 == 0) ? 0x10 : (clientCount - 1) * 0x18 + 0x10;
    default:
        return 8;
    }
}

int DWC_SetRecvTimeoutTime(unsigned char aid, unsigned long time)
{
    unsigned long long tick;

    if (gDwcTransInfo == 0)
        return 0;
    gDwcTransInfo->connections[aid].recvTimeoutTime = time;
    tick = OS_GetTick();
    gDwcTransInfo->connections[aid].previousRecvTick = tick;
    return 1;
}

int DWC_SetConnectionKeepAliveTime(unsigned long v)
{
    TransInfo *p = gDwcTransInfo;

    if (p == 0 || v == 0) {
        return 0;
    }
    p->connKeepAliveTime = v;
    return 1;
}

unsigned long DWC_GetConnectionKeepAliveTime(void)
{
    TransInfo *p = gDwcTransInfo;

    return p != 0 ? p->connKeepAliveTime : 0;
}

void DWCi_InitTransport(TransInfo *info)
{
    gDwcTransInfo = info;
    MI_CpuFill8(info, 0, 0x728);
    gDwcTransInfo->sendSplitMax = 0x5b9;
    DWC_SetConnectionKeepAliveTime(0x4e20);
    DWCi_InitReliableQueue();
}

void DWCi_RecvCallback(void *connection, unsigned char *message, int size, int reliable)
{
    if (gDwcTransInfo == 0 || message == 0 || size == 0)
        return;
    DWCs_UpdateConnectionKeepAliveTime(connection);
    if (reliable)
        DWCs_HandleReliableMessage(connection, message, size);
    else
        DWCs_HandleUnreliableMessage(connection, message, size);
}

void DWCi_PingCallback(void *connection, int latency)
{
    unsigned char aid;

    if (gDwcTransInfo->pingCallback == 0)
        return;
    aid = DWCi_GetConnectionAID(connection);
    gDwcTransInfo->pingCallback(latency, aid, gDwcTransInfo->pingCallbackParam);
}

void DWCi_TransportProcess(void)
{
    unsigned char *aidList;
    long hostCount;
    long i;
    unsigned long timeoutTime;
    unsigned char aid;
    u64 tick;
    unsigned char aid2;
    TransConn *transConnection;
    TransConn *conn2;
    long sendSize;
    long restSize;
    long freeSpace;

    if (gDwcTransInfo == 0)
        return;
    hostCount = DWC_GetAIDList(&aidList);
    tick = OS_GetTick();
    timeoutTime = DWC_GetConnectionKeepAliveTime();
    if (DWC_IsServerMyself() || (DWCi_IsServerChanging() && DWCi_IsBackupMine())) {
        for (i = 0; i < hostCount; i++) {
            aid = aidList[i];
            if (aid == DWC_GetMyAID())
                continue;
            transConnection = DWCs_GetTransConnection(aid);
            if ((u32)(((tick - transConnection->lastSomeDataRecvTick) << 6) / 0x82ea) > timeoutTime) {
                DWCi_CloseConnectionHard(aid);
                DWCi_SendServerPolling(1);
            }
        }
    } else {
        aid = DWCi_GetServerOrSubServerAID();
        if (aid != 0xff && aid != DWC_GetMyAID()) {
            transConnection = DWCs_GetTransConnection(aid);
            if ((u32)(((tick - transConnection->lastSomeDataRecvTick) << 6) / 0x82ea) > timeoutTime)
                DWCi_CloseConnectionHard(aid);
        }
    }
    for (i = 0; i < hostCount; i++) {
        aid2 = aidList[i];
        DWCi_ProcessReliableQueue();
        if (DWC_IsValidAID(aid2)) {
            tick = OS_GetTick();
            transConnection = DWCs_GetTransConnection(aid2);
            if (gDwcTransInfo->recvTimeoutCallback != 0 && transConnection->recvTimeoutTime != 0) {
                if ((u32)(((tick - transConnection->previousRecvTick) << 6) / 0x82ea) >
                    transConnection->recvTimeoutTime) {
                    gDwcTransInfo->recvTimeoutCallback(aid2, gDwcTransInfo->recvTimeoutCallbackParam);
                    transConnection->previousRecvTick = tick;
                }
            }
        }
        if (aid2 == DWC_GetMyAID())
            continue;
        if (DWCs_GetSendState(aid2) != 1)
            continue;
        conn2 = DWCs_GetTransConnection(aid2);
        sendSize = gDwcTransInfo->sendSplitMax;
        restSize = conn2->requestSendSize - conn2->sendingSize;
        if (restSize <= sendSize)
            sendSize = restSize;
        freeSpace = DWCs_GetOutgoingBufferFreeSize(aid2);
        if (freeSpace < sendSize)
            continue;
        DWCs_Send(aid2, conn2->sendBuffer + conn2->sendingSize, sendSize, 1);
        conn2->sendingSize += sendSize;
        if (conn2->sendingSize == conn2->requestSendSize) {
            long total = conn2->requestSendSize;
            conn2->sendState = 0;
            conn2->sendBuffer = 0;
            conn2->sendingSize = 0;
            conn2->requestSendSize = 0;
            if (gDwcTransInfo->sendCallback != 0)
                gDwcTransInfo->sendCallback(total, aid2, gDwcTransInfo->sendCallbackParam);
        }
    }
}

/*
 * Zeroes the live fields of element `i` of the 0x38-byte array reached
 * through the global pointer at 0x021AB180.  A null array is a no-op.
 */
void DWCi_ClearTransConnection(int i)
{
    if (gDwcTransInfo == 0)
        return;
    gDwcTransInfo->connections[i].sendingSize = 0;
    gDwcTransInfo->connections[i].recvingSize = 0;
    gDwcTransInfo->connections[i].requestSendSize = 0;
    gDwcTransInfo->connections[i].requestRecvSize = 0;
    gDwcTransInfo->connections[i].sendState = 0;
    gDwcTransInfo->connections[i].recvBuffer = 0;
    gDwcTransInfo->connections[i].recvBufferSize = 0;
    gDwcTransInfo->connections[i].recvState = 0;
    gDwcTransInfo->connections[i].lastRecvType = 0;
}

/*
 * Clears the state pointer, then tail calls its initialiser.
 */
void DWCi_ShutdownTransport(void)
{
    gDwcTransInfo = 0;
    DWCi_CleanupReliableQueue((char *)(&gDwcTransInfo));
}

/*
 * DWCi_ResetLastSomeDataRecvTimeByAid: stamps the current tick into the aid's transport record.
 */
void DWCi_ResetLastSomeDataRecvTimeByAid(int aid)
{
    unsigned long long t = OS_GetTick();
    DWCs_GetTransConnection(aid)->lastSomeDataRecvTick = t;
}

TransConn *DWCs_GetTransConnection(int i)
{
    return &gDwcTransInfo->connections[i];
}

unsigned char DWCs_GetSendState(int i)
{
    return gDwcTransInfo->connections[i].sendState;
}

unsigned char DWCs_GetRecvState(int i)
{
    return gDwcTransInfo->connections[i].recvState;
}

/*
 * sdk:      DWCs_Send (libdwcmatch.TWL.HYB.a dwc_transport.o)
 */
void DWCs_Send(unsigned char aid, unsigned char *buffer, int size, int reliable)
{
    void *connection;
    int res;

    connection = DWCi_GetGT2Connection(aid);
    if (reliable != 0) {
        if (DWCi_ProcessReliableQueue() != 0) {
            res = gt2Send(connection, buffer, size, reliable);
            if (res == 0)
                return;
        }
        if (DWCi_InsertReliableQueue(connection, buffer, size) != 0)
            return;
        DWCi_SetError(6, -0x17D5E);
        return;
    }
    gt2Send(connection, buffer, size, reliable);
}

void DWCi_SendUnreliable(unsigned char aidFrom, unsigned char aidTo, unsigned char *buffer,
    int size, int fromDWC_SendUnreliable)
{
    void *connection;
    int bNeedFoward = 0;
    unsigned char *sendBuf;

    connection = DWCi_GetGT2Connection(aidTo);
    if (connection == 0) {
        if (DWC_IsServerMyself())
            return;
        connection = DWCi_GetGT2Connection(
            *((unsigned char *)DWCi_NodeInfoList_GetNodeInfoForIndex(0) + 0x16));
        if (connection == 0)
            return;
        bNeedFoward = 1;
    }
    if (fromDWC_SendUnreliable == 1 && bNeedFoward == 1) {
        sendBuf = DWC_Alloc(4, size + 8);
        if (sendBuf == 0)
            return;
        strncpy((char *)sendBuf, gDwcTransForwardMagic, 3);
        sendBuf[3] = aidFrom;
        *(unsigned long *)(sendBuf + 4) = 1 << aidTo;
        MI_CpuCopy8(buffer, sendBuf + 8, size);
        gt2Send(connection, sendBuf, size + 8, 0);
        if (sendBuf == 0)
            return;
        DWC_Free(4, sendBuf, 0);
    } else {
        gt2Send(connection, buffer, size, 0);
    }
}

void DWCs_HandleReliableMessage(void *connection, unsigned char *message, int size)
{
    unsigned short type;
    unsigned char aid;

    aid = DWCi_GetConnectionAID(connection);
    if (aid == 0xff) {
        DWCi_SetError(6, 0xfffe8298);
        return;
    }
    switch (DWCs_GetRecvState(aid)) {
    case 0:
        type = DWCs_DecodeHeader(message);
        if (type < 2 || type >= 5)
            return;
        DWCs_RecvDataHeader(aid, message, size);
        return;
    case 1:
        DWCs_RecvDataHeader(aid, message, size);
        return;
    case 2:
        DWCs_RecvDataBody(aid, message, size);
        return;
    case 3:
        DWCs_RecvSystemDataBody(aid, message, size);
        return;
    case 4:
        gDwcTransInfo->connections[aid].recvState = 1;
        gDwcTransInfo->connections[aid].recvingSize = 0;
        gDwcTransInfo->connections[aid].requestRecvSize = 0;
        return;
    default:
        DWCi_SetError(6, 0xfffe82b6);
        return;
    }
}

void DWCs_HandleUnreliableMessage(void *connection, void *message, int size)
{
    unsigned char aidFrom;
    unsigned char aid;
    int toMeAvailable;
    unsigned char tempAid;
    int headerAvailable;
    unsigned long aidToBitmap;
    TransConn *transConnection;

    aidFrom = DWCi_GetConnectionAID(connection);
    headerAvailable = 0;
    toMeAvailable = 0;
    if (aidFrom == 0xff) {
        DWCi_SetError(6, 0xfffe8298);
        return;
    }
    if (size >= 0x14u && strncmp(message, gDwcTransMatchMagic, 4) == 0) {
        DWCi_HandleGT2UnreliableMatchCommandMessage(message, size);
        return;
    }
    if (size >= 8 && memcmp((unsigned char *)message, (unsigned char *)gDwcTransForwardMagic, 3) == 0)
        headerAvailable = 1;
    if (headerAvailable == 1) {
        aidFrom = ((unsigned char *)message)[3];
        MI_CpuCopy8((char *)message + 4, &aidToBitmap, 4);
        if (!DWC_IsServerMyself()) {
            aid = DWC_GetMyAID();
            toMeAvailable = 1;
            if (!(aidToBitmap & (1 << aid)))
                return;
        } else {
            for (tempAid = 0; tempAid < 32; tempAid++) {
                if (aidToBitmap & (1 << tempAid)) {
                    if (tempAid == DWC_GetMyAID())
                        toMeAvailable = 1;
                    else
                        DWCi_SendUnreliable(aidFrom, tempAid, message, size, 0);
                }
            }
        }
        if (toMeAvailable == 0)
            return;
    }
    if (headerAvailable == 1) {
        message = (char *)message + 8;
        size -= 8;
    }
    transConnection = &gDwcTransInfo->connections[aidFrom];
    if (transConnection->recvBuffer == 0)
        return;
    if (transConnection->recvBufferSize < size)
        return;
    if (gDwcTransInfo->recvCallback != 0) {
        gDwcTransInfo->recvCallback(aidFrom, message, size, gDwcTransInfo->recvCallbackParam);
    }
    if (gDwcTransInfo->recvTimeoutCallback != 0 && transConnection->recvTimeoutTime != 0) {
        unsigned long long tick = OS_GetTick();
        transConnection->previousRecvTick = tick;
    }
}

void DWCs_RecvDataHeader(unsigned char aid, void *message, int size)
{
    TransHeader header;
    TransConn *connection;
    unsigned short type;

    connection = &gDwcTransInfo->connections[aid];
    connection->lastRecvState = DWCs_GetRecvState(aid);
    type = DWCs_DecodeHeader(message);
    switch (type) {
    case 1:
        if (size != 8)
            return;
        MI_CpuCopy8(message, &header, 8);
        {
            unsigned long s = header.size;
            header.size = s;
            connection->requestRecvSize = s;
        }
        connection->recvingSize = 0;
        if (connection->recvBuffer != 0 &&
            connection->recvBufferSize >= connection->requestRecvSize)
            connection->recvState = 2;
        else
            connection->recvState = 4;
        break;
    case 2:
    case 3:
    case 4:
        connection->recvState = 3;
        break;
    }
    connection->lastRecvType = type;
}

void DWCs_RecvDataBody(unsigned char aid, void *message, int size)
{
    TransConn *connection;
    int totalSize;

    connection = &gDwcTransInfo->connections[aid];
    if (DWCs_GetRecvState(aid) == 2) {
        if (connection->recvingSize + size > connection->recvBufferSize) {
            DWCi_SetError(6, 0xfffe82ac);
            return;
        }
        MI_CpuCopy8(message, connection->recvBuffer + connection->recvingSize, size);
    }
    connection->recvingSize += size;
    totalSize = connection->requestRecvSize;
    if (connection->recvingSize == totalSize) {
        connection->recvState = 1;
        connection->recvingSize = 0;
        connection->requestRecvSize = 0;
        if (gDwcTransInfo->recvCallback != 0) {
            gDwcTransInfo->recvCallback(aid, connection->recvBuffer, totalSize,
                gDwcTransInfo->recvCallbackParam);
        }
    }
    if (gDwcTransInfo->recvTimeoutCallback != 0 && connection->recvTimeoutTime != 0) {
        unsigned long long tick = OS_GetTick();
        connection->previousRecvTick = tick;
    }
}

void DWCs_RecvSystemDataBody(unsigned char aid, void *message, int size)
{
    TransConn *transConnection;
    void *alignedMessage;

    transConnection = DWCs_GetTransConnection(aid);
    transConnection->recvState = transConnection->lastRecvState;
    switch (transConnection->lastRecvType) {
    case 2:
    case 3:
    case 4:
        alignedMessage = DWC_Alloc(4, size);
        if (alignedMessage == 0) {
            DWCi_SetError(9, 0xfffe8517);
            return;
        }
        MI_CpuCopy8(message, alignedMessage, size);
        DWCi_ProcessMatchSynPacket(aid, transConnection->lastRecvType, alignedMessage);
        DWC_Free(4, alignedMessage, 0);
        break;
    }
}

int DWCs_GetOutgoingBufferFreeSize(unsigned char aid)
{
    int free = gt2GetOutgoingBufferFreeSpace(DWCi_GetGT2Connection(aid));

    free += 0xfffffdf9;
    if (free <= 0)
        free = 0;
    return free;
}

void DWCs_UpdateConnectionKeepAliveTime(void *connection)
{
    unsigned char aid = DWCi_GetConnectionAID(connection);
    unsigned long long tick;

    if (aid >= 0x20)
        return;
    if (aid == DWC_GetMyAID())
        return;
    tick = OS_GetTick();
    DWCs_GetTransConnection(aid)->lastSomeDataRecvTick = tick;
}
