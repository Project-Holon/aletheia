/*
 * file:     unit_02083644_p01.c
 * unit:     yes
 * function: func_02083644, func_02083704, func_020837B8, func_02083844, func_02083934
 * address:  0x02083644
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *   PXI_Init                       0x02088498  arm
 *   PXI_IsCallbackReady            0x020885EC  arm
 *   PXI_SetFifoRecvCallback        0x020885A0  arm
 *   MIi_CpuClearFast               0x02082AC0  arm
 *   OS_IsTickAvailable             0x02087058  arm
 *   OS_InitTick                    0x02086FE8  arm
 *   OS_IsAlarmAvailable            0x02087244  arm
 *   OS_InitAlarm                   0x02087208  arm
 *   OS_CreateAlarm                 0x02087254  arm
 *   NVRAMi_Callback                0x02084204  arm
 *   nvramInitialized               0x02150EA0  data
 *   nvramw                         0x02150EE0  data
 *   NVRAMi_IsInitialized           0x020841E8  arm
 *   NVRAMi_ReadDataBytes           0x020843B4  arm
 *   OS_WakeupThread                0x02085800  arm
 *   OS_InitMessageQueue            0x02085D94  arm
 *   NVRAMi_ReadAsync                0x02083704  arm
 *   OS_SleepThread                 0x020857B0  arm
 *   OS_Sleep                       0x02085A38  arm
 *   OS_ReceiveMessage              0x02085E50  arm
 *   OS_Terminate                   0x02088234  arm
 *   NVRAMi_SyncCallback            0x02084260  arm
 *   OSi_ThreadInfo                 0x02150FEC  data
 *   NVRAMi_WriteEnable             0x020842D8  arm
 */
typedef unsigned long u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned long long u64;

typedef int BOOL;

typedef u64 OSTick;

typedef void (*OSAlarmHandler)(void *);

typedef struct OSiAlarm {
    OSAlarmHandler handler;
    void *arg;
    u32 tag;
    OSTick fire;
    struct OSiAlarm *prev;
    struct OSiAlarm *next;
    OSTick period;
    OSTick start;
} OSAlarm;

typedef struct _OSThreadQueue {
    struct _OSThread *head;
    struct _OSThread *tail;
} OSThreadQueue;

typedef enum NVRAMResult {
    NVRAM_RESULT_SUCCESS = 0,
    NVRAM_RESULT_BUSY,
    NVRAM_RESULT_ILLEGAL_PARAMETER,
    NVRAM_RESULT_SEND_ERROR,
    NVRAM_RESULT_INVALID_COMMAND,
    NVRAM_RESULT_ILLEGAL_STATUS,
    NVRAM_RESULT_FATAL_ERROR,
    NVRAM_RESULT_UNKNOWN
} NVRAMResult;

typedef enum NVRAMLock {
    NVRAM_LOCK_OFF = 0,
    NVRAM_LOCK_READ,
    NVRAM_LOCK_WRITE,
    NVRAM_LOCK_VERIFY
} NVRAMLock;

typedef void (*NVRAMCallback)(NVRAMResult result, void *arg);

typedef struct NVRAMWork {
    NVRAMLock lock;
    NVRAMCallback callback;
    void *callbackArg;
    OSAlarm alarm;
    OSTick tick;
    u32 seq;
    u32 arg[3];
    OSThreadQueue queue;
} NVRAMWork;

typedef void *OSMessage;

typedef struct OSMessageQueue {
    OSThreadQueue queueSend;
    OSThreadQueue queueReceive;
    OSMessage *msgArray;
    long msgCount;
    long firstIndex;
    long usedCount;
} OSMessageQueue;

typedef struct OSThreadInfo {
    u16 isNeedRescheduling;
    u16 irqDepth;
    struct _OSThread *current;
} OSThreadInfo;

u32 OS_DisableInterrupts(void);
u32 OS_RestoreInterrupts(u32 state);
void PXI_Init(void);
BOOL PXI_IsCallbackReady(int fifotag, int proc);
void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int tag, u32 data, BOOL err));
void MIi_CpuClearFast(u32 data, void *destp, u32 size);
BOOL OS_IsTickAvailable(void);
void OS_InitTick(void);
BOOL OS_IsAlarmAvailable(void);
void OS_InitAlarm(void);
void OS_CreateAlarm(OSAlarm *alarm);
void NVRAMi_Callback(int tag, u32 data, BOOL err);
BOOL NVRAMi_IsInitialized(void);
BOOL NVRAMi_ReadDataBytes(u32 address, u32 size, u8 *buf);
extern void OS_WakeupThread(OSThreadQueue *queue);
void OS_InitMessageQueue(OSMessageQueue *mq, OSMessage *msgArray, long msgCount);
BOOL OS_ReceiveMessage(OSMessageQueue *mq, OSMessage *msg, long flags);
void OS_SleepThread(OSThreadQueue *queue);
void OS_Sleep(u32 msec);
void OS_Terminate(void);
void NVRAMi_SyncCallback(NVRAMResult result, void *arg);
NVRAMResult NVRAMi_ReadAsync(u32 address, u32 size, void *pData, NVRAMCallback callback, void *arg);
BOOL NVRAMi_WriteEnable(void);
void func_02083644(void);
NVRAMResult func_02083704(u32 address, u32 size, void *pData, NVRAMCallback callback, void *arg);
void NVRAMi_ReadCallback(u32 data, BOOL err);
NVRAMResult func_02083844(u32 address, u32 size, void *pData);
NVRAMResult func_02083934(u32 address, u32 size, void *pData, NVRAMCallback callback, void *arg);
/* nvram.o .bss from 0x02150EA0: nvramInitialized at +0, nvramTemp (32-byte
   aligned) at +0x20.  A direct read or write of nvramTemp goes through this
   section base; taking its address uses the nvramTemp symbol. */
extern NVRAMWork nvramw;
extern u32 nvramInitialized;
extern OSThreadInfo OSi_ThreadInfo;


static inline void OS_InitThreadQueue(OSThreadQueue *queue)
{
    queue->head = queue->tail = 0;
}


/*
 * sdk:      NVRAMi_Init (libnvram.TWL.HYB.a nvram.o)
 */
void func_02083644(void)
{
    u32 e;

    e = OS_DisableInterrupts();
    if (nvramInitialized) {
        (void)OS_RestoreInterrupts(e);
        return;
    }
    nvramInitialized = 1;
    (void)OS_RestoreInterrupts(e);

    PXI_Init();
    while (!PXI_IsCallbackReady(4, 1)) {
    }
    PXI_SetFifoRecvCallback(4, NVRAMi_Callback);

    MIi_CpuClearFast(0, &nvramw, sizeof(nvramw));

    if (!OS_IsTickAvailable()) {
        OS_InitTick();
    }
    if (!OS_IsAlarmAvailable()) {
        OS_InitAlarm();
    }
    OS_CreateAlarm(&nvramw.alarm);
    OS_InitThreadQueue(&nvramw.queue);
    nvramInitialized = 2;
}


/*
 * sdk:      NVRAMi_ReadAsync (libnvram.TWL.HYB.a nvram.o)
 */
NVRAMResult func_02083704(u32 address, u32 size, void *pData, NVRAMCallback callback, void *arg)
{
    u32 e;

    if (!NVRAMi_IsInitialized()) {
        return NVRAM_RESULT_INVALID_COMMAND;
    }
    e = OS_DisableInterrupts();
    if (nvramw.lock != NVRAM_LOCK_OFF) {
        (void)OS_RestoreInterrupts(e);
        return NVRAM_RESULT_BUSY;
    }
    nvramw.lock = NVRAM_LOCK_READ;
    (void)OS_RestoreInterrupts(e);

    nvramw.callback = callback;
    nvramw.callbackArg = arg;
    nvramw.seq = 0;

    e = OS_DisableInterrupts();
    if (NVRAMi_ReadDataBytes(address, size, pData) == 1) {
        (void)OS_RestoreInterrupts(e);
        return NVRAM_RESULT_SUCCESS;
    }
    nvramw.lock = NVRAM_LOCK_OFF;
    (void)OS_RestoreInterrupts(e);
    OS_WakeupThread(&nvramw.queue);
    return NVRAM_RESULT_SEND_ERROR;
}


void NVRAMi_ReadCallback(u32 data, BOOL err)
{
    NVRAMResult result;
    u16 pxiResult = (u16)(data & 0xFF);

    result = NVRAM_RESULT_UNKNOWN;
    if (!err && pxiResult == 0) {
        result = NVRAM_RESULT_SUCCESS;
    } else if (err == 1) {
        result = NVRAM_RESULT_SEND_ERROR;
    } else {
        switch (pxiResult) {
        case 2:
            result = NVRAM_RESULT_ILLEGAL_PARAMETER;
            break;
        case 3:
            result = NVRAM_RESULT_INVALID_COMMAND;
            break;
        case 4:
            result = NVRAM_RESULT_BUSY;
            break;
        }
    }

    nvramw.lock = NVRAM_LOCK_OFF;
    nvramw.seq = 0;
    if (nvramw.callback) {
        NVRAMCallback cb = nvramw.callback;
        nvramw.callback = 0;
        cb(result, nvramw.callbackArg);
    }
    OS_WakeupThread(&nvramw.queue);
}


/*
 * sdk:      NVRAMi_Read (libnvram.TWL.HYB.a nvram.o)
 */
NVRAMResult func_02083844(u32 address, u32 size, void *pData)
{
    NVRAMResult result;
    OSMessageQueue msgQ;
    OSMessage msg[1];
    u32 intr;

    if (!OSi_ThreadInfo.current) {
        return NVRAM_RESULT_INVALID_COMMAND;
    }
    OS_InitMessageQueue(&msgQ, msg, 1);
    while (1) {
        intr = OS_DisableInterrupts();
        result = NVRAMi_ReadAsync(address, size, pData, NVRAMi_SyncCallback, &msgQ);
        if (result == NVRAM_RESULT_BUSY) {
            OS_SleepThread(&nvramw.queue);
        } else if (result == NVRAM_RESULT_SEND_ERROR) {
            OS_Sleep(1);
        } else {
            (void)OS_RestoreInterrupts(intr);
            break;
        }
        (void)OS_RestoreInterrupts(intr);
    }
    if (result == NVRAM_RESULT_SUCCESS) {
        if (!OS_ReceiveMessage(&msgQ, (OSMessage *)&result, 1)) {
            OS_Terminate();
        }
    }
    return result;
}


/*
 * sdk:      NVRAMi_WriteAsync (libnvram.TWL.HYB.a nvram.o)
 */
NVRAMResult func_02083934(u32 address, u32 size, void *pData, NVRAMCallback callback, void *arg)
{
    u32 e;

    if (!NVRAMi_IsInitialized()) {
        return NVRAM_RESULT_INVALID_COMMAND;
    }
    e = OS_DisableInterrupts();
    if (nvramw.lock != NVRAM_LOCK_OFF) {
        (void)OS_RestoreInterrupts(e);
        return NVRAM_RESULT_BUSY;
    }
    nvramw.lock = NVRAM_LOCK_WRITE;
    (void)OS_RestoreInterrupts(e);

    nvramw.callback = callback;
    nvramw.callbackArg = arg;
    nvramw.arg[0] = address;
    nvramw.arg[1] = size;
    nvramw.arg[2] = (u32)pData;
    nvramw.seq = 0;

    e = OS_DisableInterrupts();
    if (NVRAMi_WriteEnable() == 1) {
        (void)OS_RestoreInterrupts(e);
        return NVRAM_RESULT_SUCCESS;
    }
    nvramw.lock = NVRAM_LOCK_OFF;
    (void)OS_RestoreInterrupts(e);
    OS_WakeupThread(&nvramw.queue);
    return NVRAM_RESULT_SEND_ERROR;
}
