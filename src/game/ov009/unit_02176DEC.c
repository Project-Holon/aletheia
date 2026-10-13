/*
 * file:     unit_02176DEC.c
 * unit:     yes
 * function: func_02176DEC, func_02176DFC, func_02176E90, func_02176EB0, func_02176FD4, func_02177044, func_021770EC, func_02177138, func_02177160, func_02177188, func_021771B0, func_021771E0, func_0217721C, func_02177270, func_021772B8, func_021772DC, func_021772F8, func_02177340, func_02177398, func_021773D8, func_021776A0, func_0217772C, func_02177748, func_02177770, func_02177788, func_021777A4, func_021777C0, func_02177848, func_0217793C, func_02177A4C, func_02177C1C, func_02177CE4, DWCs_RecvSystemDataBody, func_02177E64, func_02177E88
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
 *   func_02059F38          0x02059F38  arm
 *   DWC_IsValidAID         0x0216B94C  arm  ov009
 *   DWCi_IsValidAID        0x0216BC3C  arm  ov009
 *   func_02177788          0x02177788  arm  ov009
 *   DWCs_GetOutgoingBufferFreeSize  0x02177E64  arm  ov009
 *   DWCs_GetRequiredHeaderSize      0x0217721C  arm  ov009
 *   func_02176BE4          0x02176BE4  arm  ov009
 *   func_02177770  0x02177770  arm  ov009
 *   func_021771B0  0x021771B0  arm  ov009
 *   func_021777C0  0x021777C0  arm  ov009
 *   func_02177E64  0x02177E64  arm  ov009
 *   g_021AB180  0x021AB180  data
 *   DWC_GetMyAID                   0x0216B838  arm ov009
 *   DWC_GetMyAID   0x0216B838  arm ov009
 *   DWCi_SendUnreliable  0x02177848  arm  ov009
 *   DWCs_GetTransConnection  0x02177770 arm
 *   DWCs_GetRecvState        0x021777A4 arm
 *   strncpy      0x02094860 arm
 *   g_021A2344   0x021A2344 data
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
 *   func_02176B80  0x02176B80  arm  ov009
 *   DWCi_GetGT2Connection  0x0216BAF4  arm  ov009
 *   func_02176C00  0x02176C00  arm  ov009
 *   gt2Send        0x02195CC0  arm  ov009
 *   func_02176CF8  0x02176CF8  arm  ov009
 *   DWCi_SetError  0x02059F54  arm
 *   DWCi_GetGT2Connection                  0x0216BAF4 arm
 *   DWCi_NodeInfoList_GetNodeInfoForIndex  0x0217637C arm
 *   DWC_Alloc                              0x0205A16C arm
 *   DWC_Free                               0x0205A1B0 arm
 *   g_021A2348                             0x021A2348 data
 *   strncmp                                     0x020949F4 arm
 *   DWCi_HandleGT2UnreliableMatchCommandMessage 0x02174E10 arm
 *   g_021A234C                                  0x021A234C data
 *   DWCi_ProcessMatchSynPacket  0x0216EC4C arm
 *   gt2GetOutgoingBufferFreeSpace     0x02195E50 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

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

extern int func_02059F38(void);
extern int DWC_IsValidAID(int aid);
extern int DWCi_IsValidAID(int aid);
extern void strncpy(char *dst, const char *src, int n);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern int memcmp(const void *a, const void *b, unsigned int n);
extern int DWCi_NodeInfoList_GetCount(void);
extern unsigned long long OS_GetTick(void);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void DWCi_InitReliableQueue(void);
extern unsigned char DWCi_GetConnectionAID(void *connection);
extern int DWC_GetAIDList(unsigned char **aidList);
extern int DWC_IsServerMyself(void);
extern int DWCi_IsServerChanging(void);
extern int DWCi_IsBackupMine(void);
extern unsigned char DWC_GetMyAID(void);
extern int DWCi_CloseConnectionHard(unsigned char aid);
extern int DWCi_SendServerPolling(int immediate);
extern unsigned char DWCi_GetServerOrSubServerAID(void);
extern int DWCi_ProcessReliableQueue(void);
extern int func_02176BE4(void);
extern void func_02176B80(TransInfo **p);
extern int func_02176C00(void);
extern int gt2Send(void *connection, unsigned char *buffer, int size, int reliable);
extern int func_02176CF8(void *connection, unsigned char *buffer, int size);
extern void DWCi_SetError(int kind, int code);
extern void *DWCi_GetGT2Connection(unsigned char aid);
extern char *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern void *DWC_Alloc(int name, unsigned long size);
extern void DWC_Free(int name, void *ptr, int flag);
extern int strncmp(const char *a, const char *b, unsigned int n);
extern void DWCi_HandleGT2UnreliableMatchCommandMessage(void *data, int len);
extern void DWCi_ProcessMatchSynPacket(unsigned char aid, unsigned short type, unsigned char *data);
extern int gt2GetOutgoingBufferFreeSpace(void *connection);
extern unsigned char DWC_GetMyAID(void);
extern TransInfo *g_021AB180;
extern char g_021A2344[];
extern char g_021A2348[];
extern char g_021A234C[];

int func_02176DEC(unsigned char a);
int func_02176DFC(unsigned char aid, unsigned short type);
int func_02176E90(unsigned char aid, void *buffer, int size);
int func_02176EB0(unsigned short type, unsigned char aid, void *buffer, int size);
unsigned long func_02176FD4(unsigned long bitmap, void *buffer, int size);
int func_02177044(unsigned char aid, void *buffer, int size);
int DWC_SetRecvBuffer(unsigned char aid, void *recvBuffer, int size);
int func_02177138(void (*cb)(int, unsigned char, void *), void *param);
int func_02177160(void (*cb)(unsigned char, unsigned char *, int, void *), void *param);
int func_02177188(void (*cb)(unsigned char, void *), void *param);
void func_021771B0(TransHeader *header, unsigned short type, int size);
unsigned short func_021771E0(void *message);
long func_0217721C(unsigned short type);
int DWC_SetRecvTimeoutTime(unsigned char aid, unsigned long time);
int func_021772B8(unsigned long v);
unsigned long func_021772DC(void);
void DWCi_InitTransport(TransInfo *info);
void DWCi_RecvCallback(void *connection, unsigned char *message, int size, int reliable);
void DWCi_PingCallback(void *connection, int latency);
void DWCi_TransportProcess(void);
void func_021776A0(int i);
void func_0217772C(void);
void func_02177748(int aid);
TransConn *func_02177770(int i);
unsigned char func_02177788(int i);
unsigned char func_021777A4(int i);
void func_021777C0(unsigned char aid, unsigned char *buffer, int size, int reliable);
void func_02177848(unsigned char aidFrom, unsigned char aidTo, unsigned char *buffer, int size, int fromDWC_SendUnreliable);
void func_0217793C(void *connection, unsigned char *message, int size);
void func_02177A4C(void *connection, void *message, int size);
void func_02177C1C(unsigned char aid, void *message, int size);
void func_02177CE4(unsigned char aid, void *message, int size);
void DWCs_RecvSystemDataBody(unsigned char aid, void *message, int size);
int func_02177E64(unsigned char aid);
void func_02177E88(void *connection);

/*
 * Tail call that supplies the second argument 1.
 */
int func_02176DEC(unsigned char a)
{
    return func_02176DFC(a, 1);
}

/*
 * sdk:      DWCi_IsSendableReliable (libdwcmatch.TWL.HYB.a dwc_transport.o)
 */
int func_02176DFC(unsigned char aid, unsigned short type)
{
    long freeSpace;

    if (func_02059F38() != 0 || (type == 1 && DWC_IsValidAID(aid) == 0))
        return 0;
    if (DWCi_IsValidAID(aid) == 0)
        return 0;
    if (func_02177788(aid) == 1)
        return 0;
    freeSpace = func_02177E64(aid);
    if (freeSpace < func_0217721C(type))
        return 0;
    return func_02176BE4() != 0;
}

/*
 * sdk:      DWC_SendReliable
 */
int func_02176E90(unsigned char aid, void *buffer, int size)
{
    return func_02176EB0(1, aid, buffer, size);
}

int func_02176EB0(unsigned short type, unsigned char aid, void *buffer, int size)
{
    int freeSpace;
    int sendSize;
    TransHeader header;
    TransConn *transConnection;

    transConnection = func_02177770(aid);
    if (!func_02176DFC(aid, type))
        return 0;
    transConnection->sendState = 1;
    transConnection->sendBuffer = buffer;
    transConnection->sendingSize = 0;
    transConnection->requestSendSize = size;
    func_021771B0(&header, type, size);
    func_021777C0(aid, (unsigned char *)&header, 8, 1);
    sendSize = g_021AB180->sendSplitMax;
    if (size <= sendSize)
        sendSize = size;
    freeSpace = func_02177E64(aid);
    if (sendSize > freeSpace)
        return 1;
    func_021777C0(aid, buffer, sendSize, 1);
    transConnection->sendingSize += sendSize;
    freeSpace = transConnection->requestSendSize;
    if (transConnection->sendingSize == freeSpace) {
        transConnection->sendState = 0;
        transConnection->sendBuffer = 0;
        transConnection->sendingSize = 0;
        transConnection->requestSendSize = 0;
        if (g_021AB180->sendCallback && type == 1)
            g_021AB180->sendCallback(freeSpace, aid, g_021AB180->sendCallbackParam);
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
unsigned long func_02176FD4(unsigned long bitmap, void *buffer, int size)
{
    unsigned long aidbit;
    unsigned char aid;

    for (aid = 0; aid < 32; aid++) {
        aidbit = (aid != 0) ? (1 << aid) : 1;
        if ((bitmap & aidbit) == 0)
            continue;
        if (aid == DWC_GetMyAID())
            continue;
        if (func_02176E90(aid, buffer, size) == 0)
            bitmap &= ~aidbit;
    }
    return bitmap;
}

/*
 * sdk:      DWC_SendUnreliable (libdwcmatch.TWL.HYB.a dwc_transport.o)
 */
int func_02177044(unsigned char aid, void *buffer, int size)
{
    if (func_02059F38() != 0)
        return 0;
    if (DWC_IsValidAID(aid) == 0)
        return 0;
    if (size > 0x5B6)
        return 0;
    func_02177848(DWC_GetMyAID(), aid, buffer, size, 1);
    if (g_021AB180->sendCallback != 0)
        g_021AB180->sendCallback(size, aid, g_021AB180->sendCallbackParam);
    return 1;
}

int DWC_SetRecvBuffer(unsigned char aid, void *recvBuffer, int size)
{
    TransConn *connection = func_02177770(aid);

    if (func_021777A4(aid) == 2)
        return 0;
    connection->recvBuffer = recvBuffer;
    connection->recvBufferSize = size;
    connection->recvState = 1;
    connection->recvingSize = 0;
    connection->requestRecvSize = 0;
    return 1;
}

int func_02177138(void (*cb)(int, unsigned char, void *), void *param)
{
    TransInfo *p = g_021AB180;

    if (p == 0)
        return 0;
    p->sendCallback = cb;
    g_021AB180->sendCallbackParam = param;
    return 1;
}

int func_02177160(void (*cb)(unsigned char, unsigned char *, int, void *), void *param)
{
    TransInfo *p = g_021AB180;

    if (p == 0)
        return 0;
    p->recvCallback = cb;
    g_021AB180->recvCallbackParam = param;
    return 1;
}

int func_02177188(void (*cb)(unsigned char, void *), void *param)
{
    TransInfo *p = g_021AB180;

    if (p == 0)
        return 0;
    p->recvTimeoutCallback = cb;
    g_021AB180->recvTimeoutCallbackParam = param;
    return 1;
}

void func_021771B0(TransHeader *header, unsigned short type, int size)
{
    strncpy(header->magicStrings, g_021A2344, 2);
    header->type = type;
    header->size = size;
}

unsigned short func_021771E0(void *message)
{
    TransHeader header;

    MI_CpuCopy8(message, &header, 8);
    if (memcmp(header.magicStrings, g_021A2344, 2) == 0)
        return header.type;
    return 0;
}

long func_0217721C(unsigned short type)
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

    if (g_021AB180 == 0)
        return 0;
    g_021AB180->connections[aid].recvTimeoutTime = time;
    tick = OS_GetTick();
    g_021AB180->connections[aid].previousRecvTick = tick;
    return 1;
}

int func_021772B8(unsigned long v)
{
    TransInfo *p = g_021AB180;

    if (p == 0 || v == 0) {
        return 0;
    }
    p->connKeepAliveTime = v;
    return 1;
}

unsigned long func_021772DC(void)
{
    TransInfo *p = g_021AB180;

    return p != 0 ? p->connKeepAliveTime : 0;
}

void DWCi_InitTransport(TransInfo *info)
{
    g_021AB180 = info;
    MI_CpuFill8(info, 0, 0x728);
    g_021AB180->sendSplitMax = 0x5b9;
    func_021772B8(0x4e20);
    DWCi_InitReliableQueue();
}

void DWCi_RecvCallback(void *connection, unsigned char *message, int size, int reliable)
{
    if (g_021AB180 == 0 || message == 0 || size == 0)
        return;
    func_02177E88(connection);
    if (reliable)
        func_0217793C(connection, message, size);
    else
        func_02177A4C(connection, message, size);
}

void DWCi_PingCallback(void *connection, int latency)
{
    unsigned char aid;

    if (g_021AB180->pingCallback == 0)
        return;
    aid = DWCi_GetConnectionAID(connection);
    g_021AB180->pingCallback(latency, aid, g_021AB180->pingCallbackParam);
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

    if (g_021AB180 == 0)
        return;
    hostCount = DWC_GetAIDList(&aidList);
    tick = OS_GetTick();
    timeoutTime = func_021772DC();
    if (DWC_IsServerMyself() || (DWCi_IsServerChanging() && DWCi_IsBackupMine())) {
        for (i = 0; i < hostCount; i++) {
            aid = aidList[i];
            if (aid == DWC_GetMyAID())
                continue;
            transConnection = func_02177770(aid);
            if ((u32)(((tick - transConnection->lastSomeDataRecvTick) << 6) / 0x82ea) > timeoutTime) {
                DWCi_CloseConnectionHard(aid);
                DWCi_SendServerPolling(1);
            }
        }
    } else {
        aid = DWCi_GetServerOrSubServerAID();
        if (aid != 0xff && aid != DWC_GetMyAID()) {
            transConnection = func_02177770(aid);
            if ((u32)(((tick - transConnection->lastSomeDataRecvTick) << 6) / 0x82ea) > timeoutTime)
                DWCi_CloseConnectionHard(aid);
        }
    }
    for (i = 0; i < hostCount; i++) {
        aid2 = aidList[i];
        DWCi_ProcessReliableQueue();
        if (DWC_IsValidAID(aid2)) {
            tick = OS_GetTick();
            transConnection = func_02177770(aid2);
            if (g_021AB180->recvTimeoutCallback != 0 && transConnection->recvTimeoutTime != 0) {
                if ((u32)(((tick - transConnection->previousRecvTick) << 6) / 0x82ea) >
                    transConnection->recvTimeoutTime) {
                    g_021AB180->recvTimeoutCallback(aid2, g_021AB180->recvTimeoutCallbackParam);
                    transConnection->previousRecvTick = tick;
                }
            }
        }
        if (aid2 == DWC_GetMyAID())
            continue;
        if (func_02177788(aid2) != 1)
            continue;
        conn2 = func_02177770(aid2);
        sendSize = g_021AB180->sendSplitMax;
        restSize = conn2->requestSendSize - conn2->sendingSize;
        if (restSize <= sendSize)
            sendSize = restSize;
        freeSpace = func_02177E64(aid2);
        if (freeSpace < sendSize)
            continue;
        func_021777C0(aid2, conn2->sendBuffer + conn2->sendingSize, sendSize, 1);
        conn2->sendingSize += sendSize;
        if (conn2->sendingSize == conn2->requestSendSize) {
            long total = conn2->requestSendSize;
            conn2->sendState = 0;
            conn2->sendBuffer = 0;
            conn2->sendingSize = 0;
            conn2->requestSendSize = 0;
            if (g_021AB180->sendCallback != 0)
                g_021AB180->sendCallback(total, aid2, g_021AB180->sendCallbackParam);
        }
    }
}

/*
 * Zeroes the live fields of element `i` of the 0x38-byte array reached
 * through the global pointer at 0x021AB180.  A null array is a no-op.
 */
void func_021776A0(int i)
{
    if (g_021AB180 == 0)
        return;
    g_021AB180->connections[i].sendingSize = 0;
    g_021AB180->connections[i].recvingSize = 0;
    g_021AB180->connections[i].requestSendSize = 0;
    g_021AB180->connections[i].requestRecvSize = 0;
    g_021AB180->connections[i].sendState = 0;
    g_021AB180->connections[i].recvBuffer = 0;
    g_021AB180->connections[i].recvBufferSize = 0;
    g_021AB180->connections[i].recvState = 0;
    g_021AB180->connections[i].lastRecvType = 0;
}

/*
 * Clears the state pointer, then tail calls its initialiser.
 */
void func_0217772C(void)
{
    g_021AB180 = 0;
    func_02176B80(&g_021AB180);
}

/*
 * DWCi_ResetLastSomeDataRecvTimeByAid: stamps the current tick into the aid's transport record.
 */
void func_02177748(int aid)
{
    unsigned long long t = OS_GetTick();
    func_02177770(aid)->lastSomeDataRecvTick = t;
}

TransConn *func_02177770(int i)
{
    return &g_021AB180->connections[i];
}

unsigned char func_02177788(int i)
{
    return g_021AB180->connections[i].sendState;
}

unsigned char func_021777A4(int i)
{
    return g_021AB180->connections[i].recvState;
}

/*
 * sdk:      DWCs_Send (libdwcmatch.TWL.HYB.a dwc_transport.o)
 */
void func_021777C0(unsigned char aid, unsigned char *buffer, int size, int reliable)
{
    void *connection;
    int res;

    connection = DWCi_GetGT2Connection(aid);
    if (reliable != 0) {
        if (func_02176C00() != 0) {
            res = gt2Send(connection, buffer, size, reliable);
            if (res == 0)
                return;
        }
        if (func_02176CF8(connection, buffer, size) != 0)
            return;
        DWCi_SetError(6, -0x17D5E);
        return;
    }
    gt2Send(connection, buffer, size, reliable);
}

void func_02177848(unsigned char aidFrom, unsigned char aidTo, unsigned char *buffer,
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
            *(unsigned char *)(DWCi_NodeInfoList_GetNodeInfoForIndex(0) + 0x16));
        if (connection == 0)
            return;
        bNeedFoward = 1;
    }
    if (fromDWC_SendUnreliable == 1 && bNeedFoward == 1) {
        sendBuf = DWC_Alloc(4, size + 8);
        if (sendBuf == 0)
            return;
        strncpy((char *)sendBuf, g_021A2348, 3);
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

void func_0217793C(void *connection, unsigned char *message, int size)
{
    unsigned short type;
    unsigned char aid;

    aid = DWCi_GetConnectionAID(connection);
    if (aid == 0xff) {
        DWCi_SetError(6, 0xfffe8298);
        return;
    }
    switch (func_021777A4(aid)) {
    case 0:
        type = func_021771E0(message);
        if (type < 2 || type >= 5)
            return;
        func_02177C1C(aid, message, size);
        return;
    case 1:
        func_02177C1C(aid, message, size);
        return;
    case 2:
        func_02177CE4(aid, message, size);
        return;
    case 3:
        DWCs_RecvSystemDataBody(aid, message, size);
        return;
    case 4:
        g_021AB180->connections[aid].recvState = 1;
        g_021AB180->connections[aid].recvingSize = 0;
        g_021AB180->connections[aid].requestRecvSize = 0;
        return;
    default:
        DWCi_SetError(6, 0xfffe82b6);
        return;
    }
}

void func_02177A4C(void *connection, void *message, int size)
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
    if (size >= 0x14u && strncmp(message, g_021A234C, 4) == 0) {
        DWCi_HandleGT2UnreliableMatchCommandMessage(message, size);
        return;
    }
    if (size >= 8 && memcmp(message, g_021A2348, 3) == 0)
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
                        func_02177848(aidFrom, tempAid, message, size, 0);
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
    transConnection = &g_021AB180->connections[aidFrom];
    if (transConnection->recvBuffer == 0)
        return;
    if (transConnection->recvBufferSize < size)
        return;
    if (g_021AB180->recvCallback != 0) {
        g_021AB180->recvCallback(aidFrom, message, size, g_021AB180->recvCallbackParam);
    }
    if (g_021AB180->recvTimeoutCallback != 0 && transConnection->recvTimeoutTime != 0) {
        unsigned long long tick = OS_GetTick();
        transConnection->previousRecvTick = tick;
    }
}

void func_02177C1C(unsigned char aid, void *message, int size)
{
    TransHeader header;
    TransConn *connection;
    unsigned short type;

    connection = &g_021AB180->connections[aid];
    connection->lastRecvState = func_021777A4(aid);
    type = func_021771E0(message);
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

void func_02177CE4(unsigned char aid, void *message, int size)
{
    TransConn *connection;
    int totalSize;

    connection = &g_021AB180->connections[aid];
    if (func_021777A4(aid) == 2) {
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
        if (g_021AB180->recvCallback != 0) {
            g_021AB180->recvCallback(aid, connection->recvBuffer, totalSize,
                g_021AB180->recvCallbackParam);
        }
    }
    if (g_021AB180->recvTimeoutCallback != 0 && connection->recvTimeoutTime != 0) {
        unsigned long long tick = OS_GetTick();
        connection->previousRecvTick = tick;
    }
}

void DWCs_RecvSystemDataBody(unsigned char aid, void *message, int size)
{
    TransConn *transConnection;
    void *alignedMessage;

    transConnection = func_02177770(aid);
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

int func_02177E64(unsigned char aid)
{
    int free = gt2GetOutgoingBufferFreeSpace(DWCi_GetGT2Connection(aid));

    free += 0xfffffdf9;
    if (free <= 0)
        free = 0;
    return free;
}

void func_02177E88(void *connection)
{
    unsigned char aid = DWCi_GetConnectionAID(connection);
    unsigned long long tick;

    if (aid >= 0x20)
        return;
    if (aid == DWC_GetMyAID())
        return;
    tick = OS_GetTick();
    func_02177770(aid)->lastSomeDataRecvTick = tick;
}
