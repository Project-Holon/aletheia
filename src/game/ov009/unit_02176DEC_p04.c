/*
 * file:     unit_02176DEC_p04.c
 * unit:     yes
 * function: func_021770EC, func_02177138, func_02177160, func_02177188, func_021771B0, func_021771E0, func_0217721C, func_02177270, func_021772B8, func_021772DC, func_021772F8, func_02177340, func_02177398, func_021773D8, func_021776A0, func_0217772C, func_02177748, func_02177770, func_02177788, func_021777A4, func_021777C0, func_02177848, func_0217793C, func_02177A4C, func_02177C1C, func_02177CE4, DWCs_RecvSystemDataBody
 * address:  0x021770EC
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
 *   DWCs_GetTransConnection  0x02177770 arm
 *   DWCs_GetRecvState        0x021777A4 arm
 *   g_021AB180  0x021AB180  data
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
 *   DWC_GetMyAID                     0x0216b838  arm
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
 *   func_0216BAF4  0x0216BAF4  arm  ov009
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
 */
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

struct DWCstTransportHeader {
    unsigned long size;
    unsigned short type;
    unsigned short pad;
};

typedef void (*DWCiRecvCallback_t)(unsigned char aid, void *buffer, int size, int arg);

extern void *DWCs_GetTransConnection(unsigned char aid);
extern int DWCs_GetRecvState(unsigned char aid);
extern void strncpy(char *dst, const char *src, int n);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern int memcmp(const void *a, const void *b, unsigned int n);
extern int DWCi_NodeInfoList_GetCount(void);
extern unsigned long long OS_GetTick(void);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int DWC_SetConnectionKeepAliveTime(unsigned long time);
extern void DWCi_InitReliableQueue(void);
extern void DWCs_UpdateConnectionKeepAliveTime(void *connection);
extern unsigned char DWCi_GetConnectionAID(void *connection);
extern int DWC_GetAIDList(unsigned char **aidList);
extern unsigned long DWC_GetConnectionKeepAliveTime(void);
extern int DWC_IsServerMyself(void);
extern int DWCi_IsServerChanging(void);
extern int DWCi_IsBackupMine(void);
extern unsigned char DWC_GetMyAID(void);
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
extern int func_0216BAF4(int aid);
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
int DWC_SetRecvBuffer(unsigned char aid, void *recvBuffer, int size);
/* * Word at +0x700 of the block the module pointer holds, and the block again at * +0x710 of the second copy the pointer holds, or zero when there is no block. */ int func_02177138(int a, int b);
int func_02177160(int a, int b);
/* * Word at +0x708 of the block the module pointer holds, and the block again at * +0x718 of the second copy the pointer holds, or zero when there is no block. */ int func_02177188(int a, int b);
void DWCs_EncodeHeader(void *header, unsigned short type, int size);
unsigned short DWCs_DecodeHeader(void *message);
long DWCs_GetRequiredHeaderSize(unsigned short type);
int DWC_SetRecvTimeoutTime(unsigned char aid, unsigned long time);
/* * Sets the word at +0x724 of the state block when both are present. */ int func_021772B8(int v);
/* * Word at +0x724 of the block held at +0x0 of the module state object, zero when the block is unset. */ int func_021772DC(void);
void DWCi_InitTransport(char *info);
void DWCi_RecvCallback(void *connection, unsigned char *message, int size, int reliable);
void DWCi_PingCallback(void *connection, int latency);
void DWCi_TransportProcess(void);
/* * Zeroes the live fields of element `i` of the 0x38-byte array reached * through the global pointer at 0x021AB180. A null array is a no-op. */ void func_021776A0(int i);
/* * Clears the word at the state object, then tail calls its initialiser. */ void func_0217772C(void);
/* * DWCi_ResetLastSomeDataRecvTimeByAid: stamps the current tick into the aid's transport record. */ void func_02177748(int aid);
/* * Indexes the record array at +0x38 a record. */ int func_02177770(int i);
/* * Byte at +0x1c of the record the index selects. */ unsigned char func_02177788(int i);
/* * Byte at +0x1d of the record the index selects. */ unsigned char func_021777A4(int i);
/* * sdk: DWCs_Send (libdwcmatch.TWL.HYB.a dwc_transport.o) */ void func_021777C0(unsigned char aid, unsigned char *buffer, int size, int reliable);
void DWCi_SendUnreliable(unsigned char aidFrom, unsigned char aidTo, unsigned char *buffer, int size, int fromDWC_SendUnreliable);
void DWCs_HandleReliableMessage(void *connection, unsigned char *message, int size);
void DWCs_HandleUnreliableMessage(void *connection, void *message, int size);
void DWCs_RecvDataHeader(unsigned char aid, void *message, int size);
void DWCs_RecvDataBody(unsigned char aid, void *message, int size);
void DWCs_RecvSystemDataBody(unsigned char aid, void *message, int size);
extern char g_021AB180[];
extern char g_021A2344[];
extern char g_021A2348[];
extern char g_021A234C[];



#define sTransInfo (*(struct DWCstTransportInfo **)g_021AB180)







int DWC_SetRecvBuffer(unsigned char aid, void *recvBuffer, int size)
{
    char *connection = DWCs_GetTransConnection(aid);

    if (DWCs_GetRecvState(aid) == 2)
        return 0;
    *(void **)(connection + 4) = recvBuffer;
    *(int *)(connection + 8) = size;
    *(char *)(connection + 0x1d) = 1;
    *(int *)(connection + 0x10) = 0;
    *(int *)(connection + 0x18) = 0;
    return 1;
}







/*
 * Word at +0x700 of the block the module pointer holds, and the block again at
 * +0x710 of the second copy the pointer holds, or zero when there is no block.
 */
int func_02177138(int a, int b)
{
    int *p = *(int **)g_021AB180;

    if (p == 0)
        return 0;
    *(int *)((char *)p + 0x700) = a;
    *(int *)((char *)*(int **)g_021AB180 + 0x710) = b;
    return 1;
}







int func_02177160(int a, int b)
{
    int *p = *(int **)g_021AB180;

    if (p == 0)
        return 0;
    *(int *)((char *)p + 0x704) = a;
    *(int *)((char *)*(int **)g_021AB180 + 0x714) = b;
    return 1;
}







/*
 * Word at +0x708 of the block the module pointer holds, and the block again at
 * +0x718 of the second copy the pointer holds, or zero when there is no block.
 */
int func_02177188(int a, int b)
{
    int *p = *(int **)g_021AB180;

    if (p == 0)
        return 0;
    *(int *)((char *)p + 0x708) = a;
    *(int *)((char *)*(int **)g_021AB180 + 0x718) = b;
    return 1;
}







void DWCs_EncodeHeader(void *header, unsigned short type, int size)
{
    char *h = header;

    strncpy(h + 6, g_021A2344, 2);
    *(unsigned short *)(h + 4) = type;
    *(int *)h = size;
}







unsigned short DWCs_DecodeHeader(void *message)
{
    char header[8];

    MI_CpuCopy8(message, header, 8);
    if (memcmp(header + 6, g_021A2344, 2) == 0)
        return *(unsigned short *)(header + 4);
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

    if (*(char **)g_021AB180 == 0)
        return 0;
    *(unsigned long *)(*(char **)g_021AB180 + aid * 0x38 + 0x2c) = time;
    tick = OS_GetTick();
    *(unsigned long long *)(*(char **)g_021AB180 + aid * 0x38 + 0x24) = tick;
    return 1;
}







/*
 * Sets the word at +0x724 of the state block when both are present.
 */
int func_021772B8(int v)
{
    char *p = *(char **)g_021AB180;

    if (p == 0 || v == 0) {
        return 0;
    }

    *(int *)(p + 0x724) = v;

    return 1;
}







/*
 * Word at +0x724 of the block held at +0x0 of the module state object, zero when the block is unset.
 */
int func_021772DC(void)
{
    int *p = *(int **)g_021AB180;

    return p != 0 ? *(int *)((char *)p + 0x724) : 0;
}







void DWCi_InitTransport(char *info)
{
    *(char **)g_021AB180 = info;
    MI_CpuFill8(info, 0, 0x728);
    *(unsigned short *)(*(char **)g_021AB180 + 0x720) = 0x5b9;
    DWC_SetConnectionKeepAliveTime(0x4e20);
    DWCi_InitReliableQueue();
}






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



#undef sTransInfo


#undef sTransInfo

#undef sTransInfo
#define sTransInfo (*(char **)g_021AB180)





/*
 * sdk:      DWCs_Send (libdwcmatch.TWL.HYB.a dwc_transport.o)
 */
void func_021777C0(unsigned char aid, unsigned char *buffer, int size, int reliable)
{
    void *connection;
    int res;

    connection = (void *)func_0216BAF4(aid);
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
        *(char *)(sTransInfo + aid * 0x38 + 0x1d) = 1;
        *(int *)(sTransInfo + aid * 0x38 + 0x10) = 0;
        *(int *)(sTransInfo + aid * 0x38 + 0x18) = 0;
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
    char *transConnection;

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
    transConnection = sTransInfo + aidFrom * 0x38;
    if (*(int *)(transConnection + 4) == 0)
        return;
    if (*(int *)(transConnection + 8) < size)
        return;
    if (*(void **)(sTransInfo + 0x704) != 0) {
        ((void (*)(unsigned char, void *, int, int))*(void **)(sTransInfo + 0x704))(
            aidFrom, message, size, *(int *)(sTransInfo + 0x714));
    }
    if (*(int *)(sTransInfo + 0x708) != 0 && *(int *)(transConnection + 0x2c) != 0) {
        unsigned long long tick = OS_GetTick();
        *(unsigned long long *)(transConnection + 0x24) = tick;
    }
}




void DWCs_RecvDataHeader(unsigned char aid, void *message, int size)
{
    struct DWCstTransportHeader header;
    char *connection;
    unsigned short type;

    connection = *(char **)g_021AB180 + aid * 0x38;
    *(char *)(connection + 0x1e) = DWCs_GetRecvState(aid);
    type = DWCs_DecodeHeader(message);
    switch (type) {
    case 1:
        if (size != 8)
            return;
        MI_CpuCopy8(message, &header, 8);
        {
            unsigned long s = header.size;

            header.size = s;
            *(int *)(connection + 0x18) = s;
        }
        *(int *)(connection + 0x10) = 0;
        if (*(int *)(connection + 4) != 0 &&
            *(int *)(connection + 8) >= *(int *)(connection + 0x18))
            *(char *)(connection + 0x1d) = 2;
        else
            *(char *)(connection + 0x1d) = 4;
        break;
    case 2:
    case 3:
    case 4:
        *(char *)(connection + 0x1d) = 3;
        break;
    }
    *(unsigned short *)(connection + 0x22) = type;
}




void DWCs_RecvDataBody(unsigned char aid, void *message, int size)
{
    char *connection;
    int totalSize;

    connection = *(char **)g_021AB180 + aid * 0x38;
    if (DWCs_GetRecvState(aid) == 2) {
        if (*(int *)(connection + 0x10) + size > *(int *)(connection + 8)) {
            DWCi_SetError(6, 0xfffe82ac);
            return;
        }
        MI_CpuCopy8(message, *(char **)(connection + 4) + *(int *)(connection + 0x10),
            size);
    }
    *(int *)(connection + 0x10) += size;
    totalSize = *(int *)(connection + 0x18);
    if (*(int *)(connection + 0x10) == totalSize) {
        *(char *)(connection + 0x1d) = 1;
        *(int *)(connection + 0x10) = 0;
        *(int *)(connection + 0x18) = 0;
        if (*(DWCiRecvCallback_t *)(*(char **)g_021AB180 + 0x704) != 0) {
            (*(DWCiRecvCallback_t *)(*(char **)g_021AB180 + 0x704))(aid,
                *(void **)(connection + 4), totalSize,
                *(int *)(*(char **)g_021AB180 + 0x714));
        }
    }
    if (*(int *)(*(char **)g_021AB180 + 0x708) != 0 &&
        *(int *)(connection + 0x2c) != 0) {
        unsigned long long tick = OS_GetTick();

        *(unsigned long long *)(connection + 0x24) = tick;
    }
}


void DWCs_RecvSystemDataBody(unsigned char aid, void *message, int size)
{
    unsigned char *transConnection;
    void *alignedMessage;

    transConnection = DWCs_GetTransConnection(aid);
    transConnection[0x1d] = transConnection[0x1e];
    switch (*(unsigned short *)(transConnection + 0x22)) {
    case 2:
    case 3:
    case 4:
        alignedMessage = DWC_Alloc(4, size);
        if (alignedMessage == 0) {
            DWCi_SetError(9, 0xfffe8517);
            return;
        }
        MI_CpuCopy8(message, alignedMessage, size);
        DWCi_ProcessMatchSynPacket(aid, *(unsigned short *)(transConnection + 0x22),
            alignedMessage);
        DWC_Free(4, alignedMessage, 0);
        break;
    }
}
