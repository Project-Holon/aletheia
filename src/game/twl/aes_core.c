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
    u32 a1;
    u32 a2;
    u32 zero;
    u32 kind;
    u32 a3;
} Request;

extern Slot data_02735A9C;
/* Message buffer at the same address as data_02735A9C.msg: AESi_Init has two
   pool entries for 0x02735A9C (one for the ready flag, one for this argument),
   so the original referenced two distinct symbols there. */
extern u32 data_02735A9C_msg[1];
extern u32 data_02735AAC[];
extern void OS_SendMessage(u32 *q, u32 msg, u32 flags);
extern u32 OS_ReceiveMessage(u32 *q, u32 *msg, u32 flags);
extern void func_02085D94(u32 *q, u32 *buf, u32 count);
extern void func_020885A0(u32 tag, void (*cb)(u32, u32, u32));
extern u32 func_020885EC(u32 tag, u32 arg);
extern void func_02088498(void);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void AESi_PxiSendCmd(u32 cmd, void *data, u32 size);
extern void AESi_PxiSendResult(u32 a, u32 b);
extern void AESi_InitLock(void);
extern u32 AESi_TryLock(void);
extern void AESi_Unlock(void);
extern void AESi_FlushRange(u32 a, u32 b);
extern void AESi_InvalidateRange(u32 addr, u32 size);

void PxiCallback(u32 tag, u32 data, u32 err);
u32 WaitResult(void);
void AESi_Init(void);
u32 AESi_SeedRand(u32 a);
u32 AESi_RandUnit(u32 buf, ...);
u32 AESi_CalcMac(u32 src, u32 a1, u32 a2, u32 a3, void (*callback)(u32, OSEvent *), OSEvent *arg);

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
        OS_SendMessage(data_02735AAC, data, 0);
        break;
    default:
        AESi_PxiSendResult(7, 6);
        break;
    }
}

u32 WaitResult(void) {
    u32 msg;
    OS_ReceiveMessage(data_02735AAC, &msg, 1);
    return msg;
}

void AESi_Init(void) {
    if (data_02735A9C.ready != 0) {
        return;
    }
    func_02085D94(data_02735AAC, data_02735A9C_msg, 1);
    AESi_InitLock();
    func_02088498();
    func_020885A0(0x13, PxiCallback);
    while (func_020885EC(0x13, 1) == 0) {
    }
    data_02735A9C.ready = 1;
}

u32 AESi_SeedRand(u32 a) {
    u32 result;
    if (AESi_TryLock() == 0) {
        return 4;
    }
    AESi_PxiSendCmd(1, (void *)a, 0x14);
    result = WaitResult();
    AESi_Unlock();
    return result;
}

u32 AESi_RandUnit(u32 buf, ...) {
    u32 result;
    if (AESi_TryLock() == 0) {
        return 4;
    }
    AESi_InvalidateRange(buf, 0x10);
    AESi_PxiSendCmd(2, &buf, 4);
    result = WaitResult();
    AESi_Unlock();
    return result;
}

u32 AESi_CalcMac(u32 src, u32 a1, u32 a2, u32 a3, void (*callback)(u32, OSEvent *), OSEvent *arg) {
    Request req;
    if (AESi_TryLock() == 0) {
        return 4;
    }
    data_02735A9C.callback = callback;
    data_02735A9C.arg = arg;
    MI_CpuCopy8((void *)src, &req, 0xc);
    req.a1 = a1;
    req.a2 = a2;
    req.zero = 0;
    req.kind = 7;
    req.a3 = a3;
    AESi_FlushRange(a1, a2);
    AESi_InvalidateRange(a3, 0x10);
    AESi_PxiSendCmd(9, &req, 0x24);
    return 1;
}
