/*
 * file:     delivery_irc.c
 * unit:     yes
 * function: DELIVERY_IRC_SetStep, DELIVERY_IRC_SetStepAtLine, DELIVERY_IRC_StepIdle, DELIVERY_IRC_RecvCrc, DELIVERY_IRC_RecvRequest, DELIVERY_IRC_RecvNotFound, DELIVERY_IRC_GetRecvBuffer, DELIVERY_IRC_StepEnd, DELIVERY_IRC_StepFinish, DELIVERY_IRC_StepExitParent, DELIVERY_IRC_StepExitChild, DELIVERY_IRC_StepWaitEndSync, DELIVERY_IRC_StepStartEndSync, DELIVERY_IRC_StepSendData, DELIVERY_IRC_StepSendCrc, DELIVERY_IRC_StepSearchEntry, DELIVERY_IRC_StepSendRequest, DELIVERY_IRC_StepWaitConnect, DELIVERY_IRC_StepStartChangeover, DELIVERY_IRC_StepWaitInit, DELIVERY_IRC_Create, DELIVERY_IRC_StartNet, DELIVERY_IRC_Start, DELIVERY_IRC_GetResult, DELIVERY_IRC_Main, DELIVERY_IRC_Delete
 * address:  0x02157954
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from delivery_irc.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   GF_STANDARD_CalcCrc16  0x0203F1FC  arm
 *   GF_STANDARD_XorCrypt  0x0203F328  arm
 *   IRCNET_IsLinkAlive 0x02179D3C thumb ov015
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   IRCNET_SetTimeoutLimit  0x0217998C  thumb ov015
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   GFL_NET_StartChangeoverChild 0x0203D0DC arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_02172878 0x02172878 data a1
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   d_02172868 0x02172868 data a1
 *   d_02172808 0x02172808 data a1
 *   GFL_HEAP_Free  0x020307B0  arm
 */
#include "delivery_irc_shared_types.h"

struct Entry;

struct Link;

struct Req;

typedef struct DeliveryIrcEntry {
    u32 size;               /* 0x00 */
    void *data;             /* 0x04 */
    u32 id;                 /* 0x08 */
    u32 mask;               /* 0x0C */
} DeliveryIrcEntry;

typedef struct DeliveryIrcWork DeliveryIrcWork;

typedef void (*DeliveryIrcStepFunc)(DeliveryIrcWork *work);

/* 8-byte message (command +1): the parent's encryption key and data CRC */
typedef struct DeliveryIrcKeyMsg {
    u32 cryptKey;           /* 0x00 */
    u16 crc;                /* 0x04 */
} DeliveryIrcKeyMsg;

/* 8-byte message (command +2): the child asks for the gift with this id and mask */
typedef struct DeliveryIrcRequest {
    u32 id;                 /* 0x00 */
    u32 mask;               /* 0x04 */
} DeliveryIrcRequest;

/* 0x7C-byte parameter block copied in by DELIVERY_IRC_Create */
typedef struct DeliveryIrcParam {
    u32 netCommandBase;     /* 0x00: command id high byte and timing sync number */
    u16 reserved;           /* 0x04 */
    u16 heapId;             /* 0x06 */
    DeliveryIrcEntry entries[7]; /* 0x08 */
    u32 entryCount;         /* 0x78 */
} DeliveryIrcParam;

struct DeliveryIrcWork {
    DeliveryIrcParam param;     /* 0x000 */
    u8 recvBuffer[0x5E8];       /* 0x07C */
    DeliveryIrcEntry *sendEntry; /* 0x664 */
    u32 cryptKey;               /* 0x668 */
    int notFound;               /* 0x66C */
    u16 ackFlag;                /* 0x670 */
    u16 crc;                    /* 0x672 */
    u8 result;                  /* 0x674 */
    u8 isParent;                /* 0x675 */
    u8 found;                   /* 0x676 */
    u8 foundIndex;              /* 0x677 */
    DeliveryIrcStepFunc step;   /* 0x678 */
    DeliveryIrcRequest request; /* 0x67C */
};

extern int GFL_NET_GetRunState(void);

extern void MI_CpuCopy8(void *, void *, u32);

extern u16 GF_STANDARD_CalcCrc16(const u8 *src, u32 len);

extern void GF_STANDARD_XorCrypt(u16 *p, u32 size, u32 seed);

extern int IRCNET_IsLinkAlive(void);

extern int GFL_NET_Exit(int);
struct GFLNetHandle;

extern struct GFLNetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);

extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct GFLNetHandle *handle, u32 timingLow, u32 timingHigh);

extern u32 GFL_NET_IsParentAid(void);

extern void IRCNET_SetTimeoutLimit(int);

extern void GFL_NET_HANDLE_SetTimingSyncRange(struct GFLNetHandle *handle, u32 timingLow, u32 timingHigh);

extern u32 GFL_NET_SendData(struct GFLNetHandle *handle, u32 sendId, u32 command, u32 size, void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode);

extern int GFL_NET_SendToHandle(struct GFLNetHandle *handle, u32 command, u32 size, void *data);

extern u32 GFL_USE_GetRandom(u32 range);

extern int GFL_NET_GetNegotiationNum(void);

extern void GFL_NET_StartChangeoverChild(u32 changeoverParam);

extern void *GFL_HEAP_Alloc(u32, u32, int, const char *, u16);

extern void GFL_NET_StartSession(struct Req *req, u32 transportArg, u32 userArg);

extern u32 GFL_HEAP_Free(void *block);

void DELIVERY_IRC_SetStep(DeliveryIrcWork *work, DeliveryIrcStepFunc step, int line);

void DELIVERY_IRC_SetStepAtLine(DeliveryIrcWork *work, DeliveryIrcStepFunc step, int line);

void DELIVERY_IRC_StepIdle(void);

void DELIVERY_IRC_RecvCrc(int netId, int size, const DeliveryIrcKeyMsg *msg, DeliveryIrcWork *work);

void DELIVERY_IRC_RecvRequest(int netId, int size, const DeliveryIrcRequest *msg, DeliveryIrcWork *work);

void DELIVERY_IRC_RecvNotFound(int netId, int size, const int *msg, DeliveryIrcWork *work);

u8 *DELIVERY_IRC_GetRecvBuffer(int netId, DeliveryIrcWork *work);

void DELIVERY_IRC_StepEnd(DeliveryIrcWork *work);

void DELIVERY_IRC_StepFinish(DeliveryIrcWork *work);

void DELIVERY_IRC_StepExitParent(DeliveryIrcWork *work);

void DELIVERY_IRC_StepExitChild(DeliveryIrcWork *work);

void DELIVERY_IRC_StepWaitEndSync(DeliveryIrcWork *work);

void DELIVERY_IRC_StepStartEndSync(DeliveryIrcWork *work);

void DELIVERY_IRC_StepSendData(DeliveryIrcWork *work);

void DELIVERY_IRC_StepSendCrc(DeliveryIrcWork *work);

void DELIVERY_IRC_StepSearchEntry(DeliveryIrcWork *work);

void DELIVERY_IRC_StepSendRequest(DeliveryIrcWork *work);

void DELIVERY_IRC_StepWaitConnect(DeliveryIrcWork *work);

void DELIVERY_IRC_StepStartChangeover(DeliveryIrcWork *work);

void DELIVERY_IRC_StepWaitInit(DeliveryIrcWork *work);

void *DELIVERY_IRC_Create(const DeliveryIrcParam *param);

int DELIVERY_IRC_StartNet(DeliveryIrcWork *work);

int DELIVERY_IRC_Start(DeliveryIrcWork *work);

unsigned char DELIVERY_IRC_GetResult(DeliveryIrcWork *work);

void DELIVERY_IRC_Main(DeliveryIrcWork *work);

int DELIVERY_IRC_Delete(DeliveryIrcWork *work);

extern const char d_02172878[];

extern u8 d_02172868[];

extern u8 d_02172808[];

/*
 * Unlabelled leaf setter (hidden in a .word run); filed as a helper because
 * its address is the witness for the tail-call thunk at 0x02157960.
 */
void DELIVERY_IRC_SetStep(DeliveryIrcWork *work, DeliveryIrcStepFunc step, int line)
{
    work->step = step;
}

void DELIVERY_IRC_SetStepAtLine(DeliveryIrcWork *work, DeliveryIrcStepFunc step, int line)
{
    DELIVERY_IRC_SetStep(work, step, line);
}

void DELIVERY_IRC_StepIdle(void) {}

void DELIVERY_IRC_RecvCrc(int netId, int size, const DeliveryIrcKeyMsg *msg, DeliveryIrcWork *work)
{
    work->crc = msg->crc;
    work->cryptKey = msg->cryptKey;
}

void DELIVERY_IRC_RecvRequest(int netId, int size, const DeliveryIrcRequest *msg, DeliveryIrcWork *work)
{
    work->request = *msg;
}

void DELIVERY_IRC_RecvNotFound(int netId, int size, const int *msg, DeliveryIrcWork *work)
{
    work->notFound = *msg;
}

u8 *DELIVERY_IRC_GetRecvBuffer(int netId, DeliveryIrcWork *work)
{
    return work->recvBuffer;
}

/*
 * Unlabelled empty callback (bx lr) hidden in a .word run; witness for the
 * function pointer taken in DELIVERY_IRC_StepFinish.
 */
void DELIVERY_IRC_StepEnd(DeliveryIrcWork *work)
{
}

void DELIVERY_IRC_StepFinish(DeliveryIrcWork *work)
{
    if (GFL_NET_GetRunState() != 0)
        return;
    if (work->isParent == 0) {
        if (work->notFound == 1) {
            work->result = 3;
        } else {
            work->result = 1;
            MI_CpuCopy8(work->recvBuffer, work->param.entries[0].data, work->param.entries[0].size);
            if (work->crc != GF_STANDARD_CalcCrc16(work->param.entries[0].data, work->param.entries[0].size))
                work->result = 2;
            GF_STANDARD_XorCrypt(work->param.entries[0].data, work->param.entries[0].size, work->cryptKey);
        }
    } else {
        if (work->found == 1)
            work->result = 1;
        else
            work->result = 3;
    }
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepEnd, 0xF8);
}

void DELIVERY_IRC_StepExitParent(DeliveryIrcWork *work)
{
    if (IRCNET_IsLinkAlive())
        GFL_NET_Exit(0);
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepFinish, 0x102);
}

void DELIVERY_IRC_StepExitChild(DeliveryIrcWork *work)
{
    GFL_NET_Exit(0);
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepFinish, 0x10A);
}

void DELIVERY_IRC_StepWaitEndSync(DeliveryIrcWork *work)
{
    int k = 0x23;
    void *link = GFL_NET_HANDLE_GetCurrentHandle();

    if (GFL_NET_HANDLE_IsTimingSyncRange(link, 0x23, (u8)work->param.netCommandBase) != 0) {
        if (GFL_NET_IsParentAid() != 0) {
            k = 0x12C;
            IRCNET_SetTimeoutLimit(k);
            k -= 0x19;
            DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepExitParent, k);
            return;
        }
        k += 0xF3;
        DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepExitChild, k);
    }
}

void DELIVERY_IRC_StepStartEndSync(DeliveryIrcWork *work)
{
    int k = 0x23;
    GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), k, (u8)work->param.netCommandBase);
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepWaitEndSync, k + 0xFC);
}

void DELIVERY_IRC_StepSendData(DeliveryIrcWork *work)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, (u8)work->param.netCommandBase) == 0)
        return;
    if (work->isParent != 0) {
        if (work->found == 1) {
            DeliveryIrcEntry *entry = &work->param.entries[work->foundIndex];
            int k = 0xFF;
            if ((struct GFLNetHandle *)(void *)GFL_NET_SendData((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0xFF, (unsigned)(work->param.netCommandBase << 24) >> 16, entry->size, (void *)entry->data, 0, 0, 1) == 0)
                return;
            DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepStartEndSync, k + 0x2F);
            return;
        }
        DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepStartEndSync, 0x133);
        return;
    }
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepStartEndSync, 0x137);
}

void DELIVERY_IRC_StepSendCrc(DeliveryIrcWork *work)
{
    if (work->found == 1) {
        DeliveryIrcKeyMsg msg;
        DeliveryIrcEntry *entry = work->sendEntry;
        msg.crc = GF_STANDARD_CalcCrc16(entry->data, entry->size);
        msg.cryptKey = work->cryptKey;
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), (u16)((work->param.netCommandBase << 8) + 1), (u16)8, (void *)&msg) == 0)
            return;
        GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, (u8)work->param.netCommandBase);
        work->ackFlag = 0;
        DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepSendData, 0x152);
        return;
    }
    work->notFound = 1;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), (u16)((work->param.netCommandBase << 8) + 3), (u16)4, (void *)&work->notFound) == 0)
        return;
    GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, (u8)work->param.netCommandBase);
    work->ackFlag = 0;
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepSendData, 0x162);
}

/*
 * levers: the RNG result is the third argument to GF_STANDARD_XorCrypt, kept live
 *   in r2 across its preceding store. The bound is read as p->n in the for
 *   condition rather than through n; expanding that one use changes the
 *   hoisted bound/far-word allocation from r7/r6 to the original r6/r7.
 */
void DELIVERY_IRC_StepSearchEntry(DeliveryIrcWork *work)
{
    DeliveryIrcEntry *entry;
    u32 i;
    unsigned long count;
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0x17, (u8)work->param.netCommandBase) == 0)
        return;
    if (work->isParent != 0) {
        entry = 0;
        work->found = 0;
        count = work->param.entryCount;
        for (i = 0; i < work->param.entryCount; i++) {
            entry = &work->param.entries[i];
            if (entry->id == work->request.id && (entry->mask & work->request.mask)) {
                work->foundIndex = i;
                work->found = 1;
                break;
            }
        }
        DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepSendCrc, 0x188);
        if (work->found == 1) {
            u32 key = GFL_USE_GetRandom(0);
            work->cryptKey = key;
            GF_STANDARD_XorCrypt(entry->data, entry->size, key);
            work->sendEntry = entry;
        }
        return;
    }
    GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, (u8)work->param.netCommandBase);
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepSendData, 0x193);
}

void DELIVERY_IRC_StepSendRequest(DeliveryIrcWork *work)
{
    if (work->isParent == 0) {
        work->request.id = work->param.entries[0].id;
        work->request.mask = work->param.entries[0].mask;
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), (u16)((work->param.netCommandBase << 8) + 2), (u16)8, (void *)&work->request) == 0)
            return;
        DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepSearchEntry, 0x1A2);
        return;
    }
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepSearchEntry, 0x1A6);
}

void DELIVERY_IRC_StepWaitConnect(DeliveryIrcWork *work)
{
    if (GFL_NET_GetNegotiationNum() > 1) {
        GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0x17, (u8)work->param.netCommandBase);
        DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepSendRequest, 0x1AF);
    }
}

void DELIVERY_IRC_StepStartChangeover(DeliveryIrcWork *work)
{
    GFL_NET_StartChangeoverChild(0);
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepWaitConnect, 0x1B7);
}

void DELIVERY_IRC_StepWaitInit(DeliveryIrcWork *work)
{
    if (GFL_NET_GetRunState() == 1)
        DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepStartChangeover, 0x1BE);
}

void *DELIVERY_IRC_Create(const DeliveryIrcParam *param)
{
    void *work = GFL_HEAP_Alloc(param->heapId, 0x684, 1, d_02172878, 0x1CD);
    MI_CpuCopy8((void *)param, work, 0x7C);
    return work;
}

int DELIVERY_IRC_StartNet(DeliveryIrcWork *work)
{
    if (GFL_NET_GetRunState() != 0)
        return 0;
    d_02172868[7] = work->param.netCommandBase;
    GFL_NET_StartSession((struct Req *)d_02172808, 0, (u32)work);
    return 1;
}

int DELIVERY_IRC_Start(DeliveryIrcWork *work)
{
    int started = DELIVERY_IRC_StartNet(work);
    work->isParent = 0;
    work->found = 0;
    work->foundIndex = 0;
    work->notFound = 0;
    DELIVERY_IRC_SetStepAtLine(work, DELIVERY_IRC_StepWaitInit, 0x231);
    return started;
}

/*
 * extent: Accessor ends at 02157E78, followed by labelled callback function.
 */
unsigned char DELIVERY_IRC_GetResult(DeliveryIrcWork *work)
{
    return work->result;
}

void DELIVERY_IRC_Main(DeliveryIrcWork *work)
{
    DeliveryIrcStepFunc step = work->step;
    if (step != 0)
        step(work);
}

int DELIVERY_IRC_Delete(DeliveryIrcWork *work)
{
    GFL_HEAP_Free(work);
    return GFL_NET_Exit(0);
}
