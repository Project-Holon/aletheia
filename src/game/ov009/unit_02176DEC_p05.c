/*
 * file:     unit_02176DEC_p05.c
 * unit:     yes
 * function: func_02177340, func_02177398, func_021773D8, func_021776A0, func_0217772C, func_02177748, func_02177770, func_02177788, func_021777A4
 * address:  0x02177340
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
 *   DWCs_UpdateConnectionKeepAliveTime  0x02177E88 arm
 *   DWCs_HandleReliableMessage          0x0217793C arm
 *   DWCs_HandleUnreliableMessage        0x02177A4C arm
 *   g_021AB180                          0x021AB180 data
 *   DWCi_GetConnectionAID  0x0216BB54 arm
 *   DWC_GetAIDList                   0x0216b880  arm
 *   OS_GetTick                       0x020870d0  arm
 *   DWC_GetConnectionKeepAliveTime   0x021772dc  arm
 *   DWC_IsServerMyself               0x0216ba08  arm
 *   DWCi_IsServerChanging            0x02175efc  arm
 *   DWCi_IsBackupMine                0x021754fc  arm
 *   DWC_GetMyAID                     0x0216b838  arm
 *   DWCs_GetTransConnection          0x02177770  arm
 *   _ll_udiv                         0x0209c00c  arm
 *   DWCi_CloseConnectionHard         0x0216bea4  arm
 *   DWCi_SendServerPolling           0x0217576c  arm
 *   DWCi_GetServerOrSubServerAID     0x0216c800  arm
 *   DWCi_ProcessReliableQueue        0x02176c00  arm
 *   DWC_IsValidAID                   0x0216b94c  arm
 *   DWCs_GetSendState                0x02177788  arm
 *   DWCs_GetOutgoingBufferFreeSize   0x02177e64  arm
 *   DWCs_Send                        0x021777c0  arm
 *   func_02176B80  0x02176B80  arm  ov009
 */
#define sTransInfo (*(struct DWCstTransportInfo **)g_021AB180)
typedef void (*DWCiPingCallback_t)(int latency, unsigned char aid, int arg);

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned long u32l;

typedef unsigned long long u64;

struct DWCstTransportConnection {
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
};

struct DWCstTransportInfo {
    struct DWCstTransportConnection connections[32];
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
};

extern void DWCs_UpdateConnectionKeepAliveTime(void *connection);
extern void DWCs_HandleReliableMessage(void *connection, unsigned char *message, int size);
extern void DWCs_HandleUnreliableMessage(void *connection, void *message, int size);
extern unsigned char DWCi_GetConnectionAID(void *connection);
extern int DWC_GetAIDList(unsigned char **aidList);
extern u64 OS_GetTick(void);
extern unsigned long DWC_GetConnectionKeepAliveTime(void);
extern int DWC_IsServerMyself(void);
extern int DWCi_IsServerChanging(void);
extern int DWCi_IsBackupMine(void);
extern unsigned char DWC_GetMyAID(void);
extern struct DWCstTransportConnection *DWCs_GetTransConnection(unsigned char aid);
extern u64 _ll_udiv(u64 a, u64 b);
extern int DWCi_CloseConnectionHard(unsigned char aid);
extern int DWCi_SendServerPolling(int immediate);
extern unsigned char DWCi_GetServerOrSubServerAID(void);
extern int DWCi_ProcessReliableQueue(void);
extern int DWC_IsValidAID(unsigned char aid);
extern int DWCs_GetSendState(unsigned char aid);
extern int DWCs_GetOutgoingBufferFreeSize(unsigned char aid);
extern void DWCs_Send(unsigned char aid, unsigned char *buffer, int size, int reliable);
extern void func_02176B80(char *p);
void DWCi_RecvCallback(void *connection, unsigned char *message, int size, int reliable);
void DWCi_PingCallback(void *connection, int latency);
void DWCi_TransportProcess(void);
void func_021776A0(int i);
void func_0217772C(void);
void func_02177748(int aid);
int func_02177770(int i);
unsigned char func_02177788(int i);
unsigned char func_021777A4(int i);
extern char g_021AB180[];


void DWCi_RecvCallback(void *connection, unsigned char *message, int size, int reliable)
{
    if (*(char **)g_021AB180 == 0 || message == 0 || size == 0)
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

    if (*(DWCiPingCallback_t *)(*(char **)g_021AB180 + 0x70c) == 0)
        return;
    aid = DWCi_GetConnectionAID(connection);
    (*(DWCiPingCallback_t *)(*(char **)g_021AB180 + 0x70c))(latency, aid,
        *(int *)(*(char **)g_021AB180 + 0x71c));
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
    struct DWCstTransportConnection *transConnection;
    struct DWCstTransportConnection *conn2;
    long sendSize;
    long restSize;
    long freeSpace;

    if (sTransInfo == 0)
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
            if (sTransInfo->recvTimeoutCallback != 0 && transConnection->recvTimeoutTime != 0) {
                if ((u32)(((tick - transConnection->previousRecvTick) << 6) / 0x82ea) >
                    transConnection->recvTimeoutTime) {
                    sTransInfo->recvTimeoutCallback(aid2, sTransInfo->recvTimeoutCallbackParam);
                    transConnection->previousRecvTick = tick;
                }
            }
        }
        if (aid2 == DWC_GetMyAID())
            continue;
        if (DWCs_GetSendState(aid2) != 1)
            continue;
        conn2 = DWCs_GetTransConnection(aid2);
        sendSize = sTransInfo->sendSplitMax;
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
            if (sTransInfo->sendCallback != 0)
                sTransInfo->sendCallback(total, aid2, sTransInfo->sendCallbackParam);
        }
    }
}


/*
 * Zeroes the live fields of element `i` of the 0x38-byte array reached
 * through the global pointer at 0x021AB180.  A null array is a no-op.
 */
void func_021776A0(int i)
{
    if (*(char **)g_021AB180 == 0)
        return;

    *(int *)(*(char **)g_021AB180 + i * 0x38 + 0x0c) = 0;
    *(int *)(*(char **)g_021AB180 + i * 0x38 + 0x10) = 0;
    *(int *)(*(char **)g_021AB180 + i * 0x38 + 0x14) = 0;
    *(int *)(*(char **)g_021AB180 + i * 0x38 + 0x18) = 0;
    *(char *)(*(char **)g_021AB180 + i * 0x38 + 0x1c) = 0;
    *(int *)(*(char **)g_021AB180 + i * 0x38 + 0x04) = 0;
    *(int *)(*(char **)g_021AB180 + i * 0x38 + 0x08) = 0;
    *(char *)(*(char **)g_021AB180 + i * 0x38 + 0x1d) = 0;
    *(short *)(*(char **)g_021AB180 + i * 0x38 + 0x22) = 0;
}


/*
 * Clears the word at the state object, then tail calls its initialiser.
 */
void func_0217772C(void)
{
    *(int *)g_021AB180 = 0;

    func_02176B80(g_021AB180);
}


/*
 * DWCi_ResetLastSomeDataRecvTimeByAid: stamps the current tick into the aid's transport record.
 */
void func_02177748(int aid)
{
    unsigned long long t = OS_GetTick();

    *(unsigned long long *)(func_02177770(aid) + 0x30) = t;
}


/*
 * Indexes the record array at +0x38 a record.
 */
int func_02177770(int i)
{
    return *(int *)g_021AB180 + i * 0x38;
}


/*
 * Byte at +0x1c of the record the index selects.
 */
unsigned char func_02177788(int i)
{
    return *(unsigned char *)(*(char **)g_021AB180 + i * 0x38 + 0x1c);
}


/*
 * Byte at +0x1d of the record the index selects.
 */
unsigned char func_021777A4(int i)
{
    return *(unsigned char *)(*(char **)g_021AB180 + i * 0x38 + 0x1d);
}
