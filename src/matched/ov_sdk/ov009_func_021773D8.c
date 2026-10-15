/*
 * function: DWCi_TransportProcess
 * address:  0x021773D8
 * packet:   pkt_ov009_021773D8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_TransportProcess (libdwcmatch.TWL.HYB.a dwc_transport.o)
 *
 * The send block must reload the connection into a *distinct* pointer local
 * (conn2) rather than reusing transConnection, or the allocator puts the
 * pointer in r5 and the clamped size in r4 instead of r4/r5.  A second
 * same-typed local matters for 1.1p1 register allocation here.
 *
 * symbols:
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
 *   gDwcTransInfo                       0x021ab180  data
 */

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
extern char gDwcTransInfo[];

#define sTransInfo (*(struct DWCstTransportInfo **)gDwcTransInfo)

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
