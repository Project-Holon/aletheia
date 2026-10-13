/*
 * file:     net_lower_data.c
 * unit:     yes
 * function: GFL_NET_LOWER_DATA_Init, GFL_NET_LOWER_DATA_Exit, GFL_NET_LOWER_DATA_SetSendData, GFL_NET_LOWER_DATA_CreatePostWork, GFL_NET_LOWER_DATA_DeletePostWork, GFL_NET_LOWER_DATA_GetPostBuffer, GFL_NET_LOWER_DATA_GetPostRecvSize, GFL_NET_LOWER_DATA_IsSendFinished, GFL_NET_LOWER_DATA_IsPostComplete, GFL_NET_LOWER_DATA_MainSend, GFL_NET_LOWER_DATA_SendChunk, GFL_NET_LOWER_DATA_GetPostEndAddress, GFL_NET_LOWER_DATA_RecvChunk, GFL_NET_LOWER_DATA_SendControl, GFL_NET_LOWER_DATA_RecvControl
 * address:  0x0203E5F8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by hand from net_lower_data_p01..p05 and the members GFL_NET_LOWER_DATA_IsSendFinished and
 * GFL_NET_LOWER_DATA_IsPostComplete, with one struct per object (NetLdataWork, NetLdataPostWork, GFLNetInitializeStruct).
 *
 * symbols:
 *   _pNetLdataWork      0x021469F4  data
 *   sSrcFileName      0x020A7D74  data
 *   sAssertWorkIsNull      0x020A7D88  data
 *   sAssertWorkNotNull      0x020A7DA0  data
 *   sAssertPostWorkIsNull      0x020A7DD8  data
 *   sAssertSendDataIsNull      0x020A7DB8  data
 *   sAssertPostWorkNotNull      0x020A7E00  data
 *   sMsgPostBufferTooSmall      0x020A7E28  data
 *   func_0203CD98   0x0203CD98  arm
 *   func_0203D798   0x0203D798  arm
 *   GFL_NET_SYSTEM_GetParentRingDataSize   0x02038D4C  arm
 *   GFL_NET_SYSTEM_GetChildRingDataSize   0x02038D30  arm
 *   func_020399A8   0x020399A8  arm
 *   func_0203D1A4   0x0203D1A4  arm
 *   func_02034734   0x02034734  arm
 */
struct GFLNetHandle;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

#include "net_types.h"

#define NET_LDATA_MAX_POST_WORK    8
#define NET_LDATA_NETID_SERVER     0xff
#define NET_LDATA_WORK_SIZE        0x48
/* Each post work is allocated with 0x48 bytes although only the first 0x14 are used. */
#define NET_LDATA_POST_WORK_SIZE   0x48
#define NET_LDATA_HEADER_SIZE      0x10
#define NET_LDATA_CMD_DATA         0xe
#define NET_LDATA_CMD_CONTROL      0xf

/* Control packet kinds (NetLdataCommand.kind). */
#define NET_LDATA_CTRL_START       0
#define NET_LDATA_CTRL_END         1
#define NET_LDATA_CTRL_ACK         2

/* Receive side of one sender: the buffer the sender's data is collected in. */
struct NetLdataPostWork {
    u32 buf;
    u32 bufSize;
    u32 totalSize;
    u32 recvSize;
    u8  complete : 1;
    u8  ownsBuf : 1;
};

/* The block _pNetLdataWork points to, NET_LDATA_WORK_SIZE bytes (send state plus one post work per sender). */
struct NetLdataWork {
    struct NetLdataPostWork *postWork[NET_LDATA_MAX_POST_WORK];
    u32 sendData;
    u32 sendSize;
    u8  sendTarget;
    u8  pad_29[3];
    u32 isParent;
    u32 sendFinished;
    u32 startPending;
    u32 ackMode;
    u32 sendArmed;
    u32 ackPending;
    u32 sentSize;
};

/* Control packet: the kind and the total size of the transfer. */
struct NetLdataCommand {
    u32 kind : 2;
    u32 size : 30;
};

extern void func_02034714(const char *file, u32 line, const char *expr);
extern void func_02034734(const char *file, u32 line, const char *fmt, ...);
extern void *func_02030734(u32 heapId, u32 size, int clearFlag, const char *file, u16 line);
extern u32 func_020307B0(void *block);
extern int  func_0203CD98(void);
extern GFLNetInitializeStruct *func_0203D798(void);
extern int  GFL_NET_SYSTEM_GetParentRingDataSize(void);
extern int  GFL_NET_SYSTEM_GetChildRingDataSize(void);
extern struct GFLNetHandle *func_0203996C(s32 netId);
extern struct GFLNetHandle *func_020399A8(void);
extern u32 func_0203D1A4(struct GFLNetHandle *pNet);
extern u32 func_0203D4D0(struct GFLNetHandle *pNet, u32 sendTarget, u32 code, u32 size, u32 data, u32 bFast, u32 bRepeat, u32 bSendBuff);
extern char sSrcFileName[];
extern char sAssertWorkIsNull[];
extern char sAssertWorkNotNull[];
extern char sAssertSendDataIsNull[];
extern char sAssertPostWorkIsNull[];
extern char sAssertPostWorkNotNull[];
extern char sMsgPostBufferTooSmall[];
extern struct NetLdataWork *_pNetLdataWork;
void GFL_NET_LOWER_DATA_Init(int heapId, int ackMode);
void GFL_NET_LOWER_DATA_Exit(void);
void GFL_NET_LOWER_DATA_SetSendData(int sendData, int sendSize, int sendTarget, int isParent);
void GFL_NET_LOWER_DATA_CreatePostWork(u32 bufSize, int netId, u32 heapId, u32 buf);
void GFL_NET_LOWER_DATA_DeletePostWork(int netId);
int GFL_NET_LOWER_DATA_GetPostBuffer(unsigned int netId);
int GFL_NET_LOWER_DATA_GetPostRecvSize(unsigned int netId);
int GFL_NET_LOWER_DATA_IsSendFinished(void);
int GFL_NET_LOWER_DATA_IsPostComplete(unsigned int netId);
void GFL_NET_LOWER_DATA_MainSend(void);
u32 GFL_NET_LOWER_DATA_SendChunk(int size);
u32 GFL_NET_LOWER_DATA_GetPostEndAddress(u32 netId);
void GFL_NET_LOWER_DATA_RecvChunk(u32 netId, u32 size, u32 pData, u32 pWork, u32 pNetHandle);
int GFL_NET_LOWER_DATA_SendControl(int kind);
void GFL_NET_LOWER_DATA_RecvControl(u32 netId, u32 size, struct NetLdataCommand *pData, u32 pWork, u32 pNetHandle);


/* Allocate the work block and clear it. ackMode 1: the sender waits for an ack after each chunk. */
void GFL_NET_LOWER_DATA_Init(int heapId, int ackMode)
{
    u8 i;
    if (_pNetLdataWork != 0)
        func_02034714(sSrcFileName, 0x65, sAssertWorkIsNull);
    _pNetLdataWork = (struct NetLdataWork *)func_02030734(heapId, NET_LDATA_WORK_SIZE, 1, sSrcFileName, 0x67);
    _pNetLdataWork->sendData = 0;
    _pNetLdataWork->sendSize = 0;
    _pNetLdataWork->sentSize = 0;
    _pNetLdataWork->sendFinished = 0;
    _pNetLdataWork->startPending = 0;
    _pNetLdataWork->ackMode = ackMode;
    _pNetLdataWork->sendArmed = 1;
    _pNetLdataWork->ackPending = 0;
    for (i = 0; i < NET_LDATA_MAX_POST_WORK; i++)
        _pNetLdataWork->postWork[i] = 0;
}


/* Free every post work (and the buffers they own), then the work block. */
void GFL_NET_LOWER_DATA_Exit(void)
{
    u8 i;
    if (_pNetLdataWork == 0)
        func_02034714(sSrcFileName, 0x81, sAssertWorkNotNull);
    for (i = 0; i < NET_LDATA_MAX_POST_WORK; i++) {
        struct NetLdataPostWork *postWork = _pNetLdataWork->postWork[i];
        if (postWork == 0)
            continue;
        if (postWork->ownsBuf == 1)
            func_020307B0((void *)postWork->buf);
        func_020307B0(_pNetLdataWork->postWork[i]);
    }
    func_020307B0(_pNetLdataWork);
    _pNetLdataWork = 0;
}


/* Queue a transfer: the pump (GFL_NET_LOWER_DATA_MainSend) sends the start packet, the chunks, then the end packet. */
void GFL_NET_LOWER_DATA_SetSendData(int sendData, int sendSize, int sendTarget, int isParent)
{
    if (_pNetLdataWork == 0)
        func_02034714(sSrcFileName, 0x9f, sAssertWorkNotNull);
    if (_pNetLdataWork->sendData != 0)
        func_02034714(sSrcFileName, 0xa0, sAssertSendDataIsNull);
    _pNetLdataWork->sendData = sendData;
    _pNetLdataWork->sendSize = sendSize;
    _pNetLdataWork->sendTarget = (u8)sendTarget;
    _pNetLdataWork->isParent = isParent;
    _pNetLdataWork->sentSize = 0;
    _pNetLdataWork->startPending = 1;
    _pNetLdataWork->sendFinished = 0;
}


/* Create the post work of sender netId; buf (bufSize bytes) is supplied by the caller and not owned. */
void GFL_NET_LOWER_DATA_CreatePostWork(u32 bufSize, int netId, u32 heapId, u32 buf)
{
    if (_pNetLdataWork == 0)
        func_02034714(sSrcFileName, 0xcf, sAssertWorkNotNull);
    if (_pNetLdataWork->postWork[netId] != 0)
        func_02034714(sSrcFileName, 0xd0, sAssertPostWorkIsNull);
    _pNetLdataWork->postWork[netId] = (struct NetLdataPostWork *)func_02030734(heapId, NET_LDATA_POST_WORK_SIZE, 1, sSrcFileName, 0xd2);
    _pNetLdataWork->postWork[netId]->buf = buf;
    _pNetLdataWork->postWork[netId]->bufSize = bufSize;
    _pNetLdataWork->postWork[netId]->ownsBuf = 0;
}


void GFL_NET_LOWER_DATA_DeletePostWork(int netId)
{
    struct NetLdataPostWork *postWork;
    if (_pNetLdataWork == 0)
        func_02034714(sSrcFileName, 0xe2, sAssertWorkNotNull);
    if (_pNetLdataWork->postWork[netId] == 0)
        func_02034714(sSrcFileName, 0xe3, sAssertPostWorkNotNull);
    postWork = _pNetLdataWork->postWork[netId];
    if (postWork->ownsBuf == 1)
        func_020307B0((void *)postWork->buf);
    func_020307B0(_pNetLdataWork->postWork[netId]);
    _pNetLdataWork->postWork[netId] = 0;
}


/* Receive buffer of sender netId. */
int GFL_NET_LOWER_DATA_GetPostBuffer(unsigned int netId)
{
    if (_pNetLdataWork == 0)
        func_02034714(sSrcFileName, 0xf6, sAssertWorkNotNull);
    if (_pNetLdataWork->postWork[netId] == 0)
        func_02034714(sSrcFileName, 0xf7, sAssertPostWorkNotNull);
    return _pNetLdataWork->postWork[netId]->buf;
}

/* Number of bytes received so far from sender netId. */
int GFL_NET_LOWER_DATA_GetPostRecvSize(unsigned int netId)
{
    if (_pNetLdataWork == 0)
        func_02034714(sSrcFileName, 0x105, sAssertWorkNotNull);
    if (_pNetLdataWork->postWork[netId] == 0)
        func_02034714(sSrcFileName, 0x106, sAssertPostWorkNotNull);
    return _pNetLdataWork->postWork[netId]->recvSize;
}

/* 1 once the end packet of the queued transfer was sent. */
int GFL_NET_LOWER_DATA_IsSendFinished(void)
{
    if (_pNetLdataWork == 0)
        return 0;
    return _pNetLdataWork->sendFinished;
}

/* 1 once the transfer from sender netId is complete. */
int GFL_NET_LOWER_DATA_IsPostComplete(unsigned int netId)
{
    struct NetLdataPostWork *postWork;
    if (_pNetLdataWork == 0 || (postWork = _pNetLdataWork->postWork[netId]) == 0)
        return 0;
    return postWork->complete;
}


/*
 * Per-frame send pump over the work block: while a transfer is queued
 * (sendData set) and the link is in state 1, either send the pending start
 * packet (startPending), or, while sentSize is below sendSize and sending is
 * armed, send as many bytes as the link window allows (parentSendSize or
 * childSendSize minus the in-flight count, less a 0x10 byte header, clamped
 * to what remains) through GFL_NET_LOWER_DATA_SendChunk, or, once everything is sent, send
 * the end packet once. Then send a pending ack (ackPending).
 */
void GFL_NET_LOWER_DATA_MainSend(void)
{
    GFLNetInitializeStruct *netInit;
    int chunkSize;

    if (_pNetLdataWork == 0 || _pNetLdataWork->sendData == 0) {
        return;
    }
    if (func_0203CD98() != 1) {
        return;
    }
    if (_pNetLdataWork->startPending == 1) {
        if (GFL_NET_LOWER_DATA_SendControl(NET_LDATA_CTRL_START) == 1) {
            _pNetLdataWork->startPending = 0;
        }
    } else if (_pNetLdataWork->sentSize < _pNetLdataWork->sendSize) {
        if (_pNetLdataWork->sendArmed == 1) {
            netInit = func_0203D798();
            if (_pNetLdataWork->isParent == 1) {
                chunkSize = netInit->parentSendSize - GFL_NET_SYSTEM_GetParentRingDataSize();
            } else {
                chunkSize = netInit->childSendSize - GFL_NET_SYSTEM_GetChildRingDataSize();
            }
            chunkSize -= NET_LDATA_HEADER_SIZE;
            if (chunkSize > 0x10) {
                if (_pNetLdataWork->sentSize + chunkSize > _pNetLdataWork->sendSize) {
                    chunkSize = _pNetLdataWork->sendSize - _pNetLdataWork->sentSize;
                }
                if (GFL_NET_LOWER_DATA_SendChunk(chunkSize) == 1) {
                    _pNetLdataWork->sentSize += chunkSize;
                    if (_pNetLdataWork->ackMode == 1) {
                        _pNetLdataWork->sendArmed = 0;
                    }
                }
            }
        }
    } else if (_pNetLdataWork->sendFinished == 0) {
        if (GFL_NET_LOWER_DATA_SendControl(NET_LDATA_CTRL_END) == 1) {
            _pNetLdataWork->sendFinished = 1;
            _pNetLdataWork->sendData = 0;
        }
    }
    if (_pNetLdataWork->ackPending == 1) {
        if (GFL_NET_LOWER_DATA_SendControl(NET_LDATA_CTRL_ACK) == 1) {
            _pNetLdataWork->ackPending = 0;
        }
    }
}

/* Send the next size bytes of the queued data as one data packet. */
u32 GFL_NET_LOWER_DATA_SendChunk(int size)
{
    int isParent = _pNetLdataWork->isParent;
    int sendData = _pNetLdataWork->sendData;
    int sentSize = _pNetLdataWork->sentSize;
    int dataAddr = sendData + sentSize;
    struct GFLNetHandle *handle;
    if (isParent == 1)
        handle = func_0203996C(NET_LDATA_NETID_SERVER);
    else
        handle = func_020399A8();
    return func_0203D4D0(handle, _pNetLdataWork->sendTarget, NET_LDATA_CMD_DATA, size, dataAddr, 0, 1, 1);
}


/*
 * End address (buffer plus received size) of sender netId's post work (0xff
 * means 0), re-checked after func_0203D798; 0 when the work block or the post
 * work is missing. The first guard is a wrapping positive test whose failure
 * falls through to the single trailing return 0.
 */
u32 GFL_NET_LOWER_DATA_GetPostEndAddress(u32 netId)
{
    struct NetLdataPostWork *postWork;
    if (netId == NET_LDATA_NETID_SERVER) {
        netId = 0;
    }
    if (_pNetLdataWork != 0 && _pNetLdataWork->postWork[netId] != 0) {
        func_0203D798();
        if (_pNetLdataWork == 0 || _pNetLdataWork->postWork[netId] == 0) {
            return 0;
        }
        postWork = _pNetLdataWork->postWork[netId];
        return postWork->buf + postWork->recvSize;
    }
    return 0;
}


/*
 * Data packet callback: add size to the received count of sender netId (0xff
 * folds to slot 0). The global is re-read after every call because each
 * callee may publish a new work block.
 */
void GFL_NET_LOWER_DATA_RecvChunk(u32 netId, u32 size, u32 pData, u32 pWork, u32 pNetHandle)
{
    GFLNetInitializeStruct *netInit;
    struct NetLdataPostWork *postWork;

    if (netId == NET_LDATA_NETID_SERVER) {
        netId = 0;
    }
    if (_pNetLdataWork == 0 || _pNetLdataWork->postWork[netId] == 0) {
        return;
    }

    netInit = func_0203D798();

    if (_pNetLdataWork == 0 || _pNetLdataWork->postWork[netId] == 0) {
        return;
    }

    if ((u32)func_020399A8() != pNetHandle && netInit->bMPMode == 0) {
        return;
    }

    postWork = _pNetLdataWork->postWork[netId];
    postWork->recvSize += size;

    if (_pNetLdataWork->ackMode != 1) {
        return;
    }

    if (netId != func_0203D1A4(func_020399A8())) {
        _pNetLdataWork->ackPending = 1;
    }
}

/* Send a control packet (kind NET_LDATA_CTRL_*) carrying the total size. */
int GFL_NET_LOWER_DATA_SendControl(int kind)
{
    struct NetLdataCommand header;
    struct GFLNetHandle *handle;
    if (_pNetLdataWork->isParent == 1)
        handle = func_0203996C(NET_LDATA_NETID_SERVER);
    else
        handle = func_020399A8();
    header.kind = kind;
    header.size = _pNetLdataWork->sendSize;
    return func_0203D4D0(handle, _pNetLdataWork->sendTarget, NET_LDATA_CMD_CONTROL, 4, (u32)(&header), 0, 1, 0);
}


/*
 * Control packet callback: start (set up the post work of sender netId for
 * a transfer of pData->size bytes), end (mark the post work complete when all
 * bytes arrived) or ack (re-arm the sender).
 */
void GFL_NET_LOWER_DATA_RecvControl(u32 netId, u32 size, struct NetLdataCommand *pData, u32 pWork, u32 pNetHandle)
{
    GFLNetInitializeStruct *netInit;

    if (netId == NET_LDATA_NETID_SERVER) {
        netId = 0;
    }
    if (_pNetLdataWork == 0 || _pNetLdataWork->postWork[netId] == 0) {
        return;
    }

    netInit = func_0203D798();
    if (_pNetLdataWork == 0 || _pNetLdataWork->postWork[netId] == 0) {
        return;
    }

    if (pNetHandle != (u32)func_020399A8()) {
        if (netInit->bMPMode == 0) {
            return;
        }
    }

    switch (pData->kind) {
    case NET_LDATA_CTRL_START:
        if (_pNetLdataWork->postWork[netId]->bufSize < pData->size) {
            func_02034734(sSrcFileName, 543, sMsgPostBufferTooSmall, _pNetLdataWork->postWork[netId]->bufSize, pData->size);
        }
        _pNetLdataWork->postWork[netId]->totalSize = pData->size;
        _pNetLdataWork->postWork[netId]->recvSize = 0;
        _pNetLdataWork->postWork[netId]->complete = 0;
        break;

    case NET_LDATA_CTRL_END:
        if (_pNetLdataWork->postWork[netId]->recvSize == _pNetLdataWork->postWork[netId]->totalSize) {
            _pNetLdataWork->postWork[netId]->complete = 1;
        }
        break;

    case NET_LDATA_CTRL_ACK:
        if (netId != func_0203D1A4(func_020399A8())) {
            _pNetLdataWork->sendArmed = 1;
        }
        break;
    }
}
