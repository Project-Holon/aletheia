/*
 * file:     aes_core.c
 * unit:     yes
 * function: PxiCallback, WaitResult, AESi_Init, AESi_SeedRand, AESi_RandUnit, AESi_CalcMac
 * address:  0x02707310
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libaes.TWL.HYB.a aes_core.o
 *
 * symbols:
 *   data_02735A9C_msg  0x02735A9C  data twl a2
 *   data_02735A9C  0x02735A9C  data twl a2
 *   data_02735AAC  0x02735AAC  data twl a2
 *   AESi_PxiSendCmd  0x02707A94  arm
 *   AESi_PxiSendResult  0x02707ACC  arm
 *   AESi_InitLock  0x02707AEC  arm
 *   AESi_Unlock  0x02707BDC  arm
 *   AESi_FlushRange  0x02707C2C  arm
 *   AESi_InvalidateRange  0x02707C48  arm
 *   PXI_Init  0x02088498  arm  arm9
 *   PXI_IsCallbackReady  0x020885EC  arm  arm9
 *   OS_InitMessageQueue  0x02085D94  arm  arm9
 *   PXI_SetFifoRecvCallback  0x020885A0  arm  arm9
 */
typedef unsigned int u32;
typedef unsigned short u16;

typedef struct OSEvent OSEvent;

typedef struct {
    u32 msg[1];
    OSEvent *arg;
    void (*callback)(u32, OSEvent *);
    u32 ready;
} Slot;

typedef struct {
    u32 head[3];
    u32 pad;
    u32 data;
    u32 length;
    u32 zero;
    u32 kind;
    u32 mac;
} Request;

extern Slot data_02735A9C;
/* Message buffer at the same address as data_02735A9C.msg: AESi_Init has two
   pool entries for 0x02735A9C (one for the ready flag, one for this argument),
   so the original referenced two distinct symbols there. */
extern u32 data_02735A9C_msg[1];
extern u32 data_02735AAC[];
struct OSMessageQueue;
extern int OS_SendMessage(struct OSMessageQueue *mq, void *msg, int flags);
extern int OS_ReceiveMessage(struct OSMessageQueue *mq, void **msg, int flags);
extern void OS_InitMessageQueue(struct OSMessageQueue *mq, void **msgArray, int msgCount);
extern void PXI_SetFifoRecvCallback(int fifotag, void (*cb)(u32, u32, u32));
extern int PXI_IsCallbackReady(int fifotag, int proc);
extern void PXI_Init(void);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void AESi_PxiSendCmd(unsigned int command, unsigned char *buf, unsigned int len);
extern void AESi_PxiSendResult(u32 a, u32 b);
extern void AESi_InitLock(void);
extern int AESi_TryLock(void);
extern void AESi_Unlock(void);
extern void AESi_FlushRange(void *addr, unsigned int size);
extern void AESi_InvalidateRange(void *addr, unsigned int size);

void PxiCallback(u32 tag, u32 data, u32 err);
u32 WaitResult(void);
void AESi_Init(void);
u32 AESi_SeedRand(u32 *a);
u32 AESi_RandUnit(u32 buf, ...);
u32 AESi_CalcMac(u32 src, u32 data, u32 length, u32 mac, void (*callback)(u32, OSEvent *), OSEvent *arg);

void PxiCallback(u32 tag, u32 data, u32 err) {
    u32 type;
    if (err != 0) {
        return;
    }
    type = (data & 0x1e00000) >> 21;
    data = (u16)data;
    switch (type) {
    case 6:
        if (data_02735A9C.callback != 0) {
            data_02735A9C.callback(data, data_02735A9C.arg);
        }
        AESi_Unlock();
        break;
    case 7:
        OS_SendMessage((struct OSMessageQueue *)data_02735AAC, (void *)data, 0);
        break;
    default:
        AESi_PxiSendResult(7, 6);
        break;
    }
}

u32 WaitResult(void) {
    u32 msg;
    OS_ReceiveMessage((struct OSMessageQueue *)data_02735AAC, (void **)(&msg), 1);
    return msg;
}

void AESi_Init(void) {
    if (data_02735A9C.ready != 0) {
        return;
    }
    OS_InitMessageQueue((struct OSMessageQueue *)data_02735AAC, (void **)data_02735A9C_msg, 1);
    AESi_InitLock();
    PXI_Init();
    PXI_SetFifoRecvCallback(0x13, PxiCallback);
    while (PXI_IsCallbackReady(0x13, 1) == 0) {
    }
    data_02735A9C.ready = 1;
}

u32 AESi_SeedRand(u32 *seed) {
    u32 result;
    if (AESi_TryLock() == 0) {
        return 4;
    }
    AESi_PxiSendCmd(1, (void *)seed, 0x14);
    result = WaitResult();
    AESi_Unlock();
    return result;
}

u32 AESi_RandUnit(u32 buf, ...) {
    u32 result;
    if (AESi_TryLock() == 0) {
        return 4;
    }
    AESi_InvalidateRange((void *)buf, 0x10);
    AESi_PxiSendCmd(2, (unsigned char *)(&buf), 4);
    result = WaitResult();
    AESi_Unlock();
    return result;
}

u32 AESi_CalcMac(u32 src, u32 data, u32 length, u32 mac, void (*callback)(u32, OSEvent *), OSEvent *arg) {
    Request req;
    if (AESi_TryLock() == 0) {
        return 4;
    }
    data_02735A9C.callback = callback;
    data_02735A9C.arg = arg;
    MI_CpuCopy8((void *)src, &req, 0xc);
    req.data = data;
    req.length = length;
    req.zero = 0;
    req.kind = 7;
    req.mac = mac;
    AESi_FlushRange((void *)data, length);
    AESi_InvalidateRange((void *)mac, 0x10);
    AESi_PxiSendCmd(9, (unsigned char *)(&req), 0x24);
    return 1;
}
