/*
 * file:     unit_02083644.c
 * unit:     yes
 * function: func_02083644, func_02083704, func_020837B8, func_02083844, func_02083934, func_020839E8, func_02083DC8, func_02083EB8, func_02083FA0, func_020840F8, func_020841E8, func_02084204, func_02084260, func_02084288, func_020842A0, func_020842D8, func_02084304, func_02084330, func_020843B4, func_020844A8, func_02084570
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
 *   nvramw                         0x02150EE0  data
 *   OS_WakeupThread                0x02085800  arm
 *   OS_InitMessageQueue            0x02085D94  arm
 *   NVRAMi_ReadAsync                0x02083704  arm
 *   OS_SleepThread                 0x020857B0  arm
 *   OS_Sleep                       0x02085A38  arm
 *   OS_ReceiveMessage              0x02085E50  arm
 *   OS_Terminate                   0x02088234  arm
 *   NVRAMi_SyncCallback            0x02084260  arm
 *   OSi_ThreadInfo                 0x02150FEC  data
 *   g_02150EA0                 0x02150EA0  data
 *   nvramTemp                  0x02150EC0  data
 *   OS_GetTick                 0x020870D0  arm
 *   OS_SetAlarm                0x0208738C  arm
 *   DC_InvalidateRange         0x020862B8  arm
 *   DC_StoreRange              0x020862D4  arm
 *   NVRAMi_WriteAsync                0x02083934  arm
 *   NVRAMi_VerifyAsync                0x02083EB8  arm
 *   OS_SendMessage                 0x02085DBC  arm
 *   PXI_SendWordByFifo  0x02088610  arm
 */
#define NVRAM_RETRY_SPAN 0x20B
#define NVRAM_TEMP_SIZE 32
struct OSMessageQueue;
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

typedef struct NVRAMWork_02083644 {
    NVRAMLock lock;
    NVRAMCallback callback;
    void *callbackArg;
    OSAlarm alarm;
    OSTick tick;
    u32 seq;
    volatile u32 arg[3];
    OSThreadQueue queue;
} NVRAMWork_02083644;

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

/* nvram.o .bss from 0x02150EA0: nvramInitialized at +0, nvramTemp (32-byte
   aligned) at +0x20.  A direct read or write of nvramTemp goes through this
   section base; taking its address uses the nvramTemp symbol. */
typedef struct NvramBss {
    u32 nvramInitialized;
    u8 pad04[0x1C];
    u8 nvramTemp[32];
} NvramBss;

typedef struct NVRAMWork_02083EB8 {
    NVRAMLock lock;
    NVRAMCallback callback;
    void *callbackArg;
    OSAlarm alarm;
    OSTick tick;
    u32 seq;
    u32 arg[3];
    OSThreadQueue queue;
} NVRAMWork_02083EB8;

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
extern void OS_WakeupThread(OSThreadQueue *queue);
void OS_InitMessageQueue(OSMessageQueue *mq, OSMessage *msgArray, long msgCount);
BOOL OS_ReceiveMessage(OSMessageQueue *mq, OSMessage *msg, long flags);
void OS_SleepThread(OSThreadQueue *queue);
void OS_Sleep(u32 msec);
void OS_Terminate(void);
void NVRAMi_SyncCallback(NVRAMResult result, void *arg);
NVRAMResult NVRAMi_ReadAsync(u32 address, u32 size, void *pData, NVRAMCallback callback, void *arg);
extern OSTick OS_GetTick(void);
extern void OS_SetAlarm(OSAlarm *alarm, OSTick tick, OSAlarmHandler handler, void *arg);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
NVRAMResult NVRAMi_WriteAsync(u32 address, u32 size, void *pData, NVRAMCallback callback, void *arg);
NVRAMResult NVRAMi_VerifyAsync(u32 address, u32 size, void *pData, NVRAMCallback callback, void *arg);
int OS_SendMessage(struct OSMessageQueue *mq, void *msg, long flags);
extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);
void func_02083644(void);
NVRAMResult func_02083704(u32 address, u32 size, void *pData, NVRAMCallback callback, void *arg);
void NVRAMi_ReadCallback(u32 data, BOOL err);
NVRAMResult func_02083844(u32 address, u32 size, void *pData);
NVRAMResult func_02083934(u32 address, u32 size, void *pData, NVRAMCallback callback, void *arg);
void NVRAMi_WriteCallback(u32 data, BOOL err);
NVRAMResult func_02083DC8(u32 address, u32 size, void *pData);
NVRAMResult func_02083EB8(u32 address, u32 size, void *pData, NVRAMCallback callback, void *arg);
void NVRAMi_VerifyCallback(u32 data, BOOL err);
NVRAMResult func_020840F8(u32 address, u32 size, void *pData);
BOOL NVRAMi_IsInitialized(void);
void NVRAMi_Callback(int tag, u32 data, BOOL err);
void func_02084260(int result, void *arg);
void NVRAMi_AlarmHandler(void *arg);
BOOL NVRAMi_VerifyDataArray(u8 *data0, u8 *data1, u32 size);
BOOL NVRAMi_WriteEnable(void);
BOOL NVRAMi_WriteDisable(void);
BOOL NVRAMi_ReadStatusRegister(u8 *pData);
BOOL NVRAMi_ReadDataBytes(u32 address, u32 size, u8 *pData);
BOOL NVRAMi_PageWrite(u32 address, u16 size, u8 *pData);
BOOL NVRAMi_SoftwareReset(void);
extern NVRAMWork_02083644 nvramw;
extern OSThreadInfo OSi_ThreadInfo;
extern NvramBss g_02150EA0;
extern u8 nvramTemp[32];




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
    if (g_02150EA0.nvramInitialized) {
        (void)OS_RestoreInterrupts(e);
        return;
    }
    g_02150EA0.nvramInitialized = 1;
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
    g_02150EA0.nvramInitialized = 2;
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




static inline u32 MinU32(u32 a, u32 b)
{
    return (a < b) ? a : b;
}




void NVRAMi_WriteCallback(u32 data, BOOL err)
{
    NVRAMResult result;
    u16 pxiResult = (u16)(data & 0xFF);
    u16 tempSize;
    NVRAMCallback cb;

    result = NVRAM_RESULT_UNKNOWN;
    tempSize = (u16)(0x100 - (nvramw.arg[0] & 0xFF));
    tempSize = (u16)MinU32(nvramw.arg[1], tempSize);

    switch (nvramw.seq) {
    case 0:
        if (!err && pxiResult == 0) {
            if (NVRAMi_PageWrite(nvramw.arg[0], tempSize, (u8 *)nvramw.arg[2]) == 1) {
                nvramw.seq = 1;
                return;
            }
            result = NVRAM_RESULT_SEND_ERROR;
        } else if (err == 1) {
            result = NVRAM_RESULT_SEND_ERROR;
        } else if (pxiResult == 4) {
            result = NVRAM_RESULT_BUSY;
        }
        break;

    case 1:
        if (!err && pxiResult == 0) {
            nvramw.arg[0] += tempSize;
            nvramw.arg[1] -= tempSize;
            nvramw.arg[2] += tempSize;
            nvramw.tick = OS_GetTick();
            nvramw.seq = 5;
            OS_SetAlarm(&nvramw.alarm, NVRAM_RETRY_SPAN, NVRAMi_AlarmHandler, 0);
            return;
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
                if (NVRAMi_PageWrite(nvramw.arg[0], tempSize, (u8 *)nvramw.arg[2]) == 1) {
                    return;
                }
                result = NVRAM_RESULT_SEND_ERROR;
                break;
            }
        }
        break;

    case 2:
        if (!err && pxiResult == 0) {
            if (g_02150EA0.nvramTemp[0] & 0x20) {
                if (NVRAMi_SoftwareReset() == 1) {
                    nvramw.seq = 4;
                    return;
                }
                nvramw.seq = 4;
                OS_SetAlarm(&nvramw.alarm, NVRAM_RETRY_SPAN, NVRAMi_AlarmHandler, (void *)4);
                return;
            }
            if (!(g_02150EA0.nvramTemp[0] & 0x01)) {
                if (tempSize) {
                    if (NVRAMi_WriteEnable() == 1) {
                        nvramw.seq = 0;
                        return;
                    }
                    result = NVRAM_RESULT_SEND_ERROR;
                    break;
                }
                if (NVRAMi_WriteDisable() == 1) {
                    nvramw.seq = 3;
                    return;
                }
                nvramw.seq = 3;
                OS_SetAlarm(&nvramw.alarm, NVRAM_RETRY_SPAN, NVRAMi_AlarmHandler, (void *)4);
                return;
            }
        } else if (!err && pxiResult != 4) {
            break;
        }
        nvramw.seq = 5;
        OS_SetAlarm(&nvramw.alarm, NVRAM_RETRY_SPAN, NVRAMi_AlarmHandler, 0);
        return;

    case 3:
        if (!err && pxiResult == 0) {
            result = NVRAM_RESULT_SUCCESS;
        } else if (err || pxiResult == 4) {
            if (NVRAMi_WriteDisable() == 1) {
                return;
            }
            nvramw.seq = 3;
            OS_SetAlarm(&nvramw.alarm, NVRAM_RETRY_SPAN, NVRAMi_AlarmHandler, (void *)4);
            return;
        }
        break;

    case 4:
        if (!err && pxiResult == 0) {
            result = NVRAM_RESULT_ILLEGAL_STATUS;
        } else if (err || pxiResult == 4) {
            if (NVRAMi_SoftwareReset() == 1) {
                return;
            }
            nvramw.seq = 4;
            OS_SetAlarm(&nvramw.alarm, NVRAM_RETRY_SPAN, NVRAMi_AlarmHandler, (void *)4);
            return;
        }
        break;

    case 5:
        DC_InvalidateRange(nvramTemp, 32);
        if (NVRAMi_ReadStatusRegister(nvramTemp) == 1) {
            nvramw.seq = 2;
            return;
        }
        nvramw.seq = 2;
        g_02150EA0.nvramTemp[0] = 1;
        DC_StoreRange(nvramTemp, 32);
        OS_SetAlarm(&nvramw.alarm, NVRAM_RETRY_SPAN, NVRAMi_AlarmHandler, 0);
        return;
    }

    nvramw.lock = NVRAM_LOCK_OFF;
    nvramw.seq = 0;
    if (nvramw.callback) {
        cb = nvramw.callback;
        nvramw.callback = 0;
        cb(result, nvramw.callbackArg);
    }
    OS_WakeupThread(&nvramw.queue);
}




/*
 * sdk:      NVRAMi_Write (libnvram.TWL.HYB.a nvram.o)
 *
 * Catalogued as NVRAMi_Read. It calls NVRAMi_WriteAsync (0x02083934), so it is NVRAMi_Write,
 * the 240-byte nvram.o symbol of that name; the three sync wrappers
 * share one DWARF shape.
 */
NVRAMResult func_02083DC8(u32 address, u32 size, void *pData)
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
        result = NVRAMi_WriteAsync(address, size, pData, NVRAMi_SyncCallback, &msgQ);
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
 * sdk:      NVRAMi_VerifyAsync (libnvram.TWL.HYB.a nvram.o)
 */
NVRAMResult func_02083EB8(u32 address, u32 size, void *pData, NVRAMCallback callback, void *arg)
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
    nvramw.lock = NVRAM_LOCK_VERIFY;
    (void)OS_RestoreInterrupts(e);

    nvramw.callback = callback;
    nvramw.callbackArg = arg;
    nvramw.arg[0] = address;
    nvramw.arg[1] = size;
    nvramw.arg[2] = (u32)pData;
    nvramw.seq = 0;

    DC_InvalidateRange(nvramTemp, 32);
    e = OS_DisableInterrupts();
    if (NVRAMi_ReadDataBytes(address, (size > 32) ? 32 : size, nvramTemp) == 1) {
        (void)OS_RestoreInterrupts(e);
        return NVRAM_RESULT_SUCCESS;
    }
    nvramw.lock = NVRAM_LOCK_OFF;
    (void)OS_RestoreInterrupts(e);
    OS_WakeupThread(&nvramw.queue);
    return NVRAM_RESULT_SEND_ERROR;
}




void NVRAMi_VerifyCallback(u32 data, BOOL err)
{
    NVRAMResult result;
    u16 pxiResult = (u16)(data & 0xFF);
    u16 tempSize;
    NVRAMCallback cb;

    result = NVRAM_RESULT_UNKNOWN;
    u32 remain = nvramw.arg[1];
    tempSize = (u16)((remain > NVRAM_TEMP_SIZE) ? NVRAM_TEMP_SIZE : remain);

    if (!err && pxiResult == 0) {
        if (!NVRAMi_VerifyDataArray(nvramTemp, (u8 *)nvramw.arg[2], tempSize)) {
            result = NVRAM_RESULT_FATAL_ERROR;
        } else {
            nvramw.arg[0] += tempSize;
            remain = nvramw.arg[1] - tempSize;
            nvramw.arg[1] = remain;
            nvramw.arg[2] += tempSize;
            if (remain != 0) {
                DC_InvalidateRange(nvramTemp, NVRAM_TEMP_SIZE);
                remain = nvramw.arg[1];
                if (NVRAMi_ReadDataBytes(nvramw.arg[0],
                                         (remain > NVRAM_TEMP_SIZE) ? NVRAM_TEMP_SIZE : remain,
                                         nvramTemp) == 1) {
                    return;
                }
                result = NVRAM_RESULT_SEND_ERROR;
            } else {
                result = NVRAM_RESULT_SUCCESS;
            }
        }
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
            DC_InvalidateRange(nvramTemp, NVRAM_TEMP_SIZE);
            if (NVRAMi_ReadDataBytes(nvramw.arg[0], tempSize, nvramTemp) == 1) {
                return;
            }
            result = NVRAM_RESULT_SEND_ERROR;
            break;
        }
    }

    nvramw.lock = NVRAM_LOCK_OFF;
    nvramw.seq = 0;
    if (nvramw.callback) {
        cb = nvramw.callback;
        nvramw.callback = 0;
        cb(result, nvramw.callbackArg);
    }
    OS_WakeupThread(&nvramw.queue);
}




/*
 * sdk:      NVRAMi_Verify (libnvram.TWL.HYB.a nvram.o)
 *
 * Catalogued as NVRAMi_Read. It calls NVRAMi_VerifyAsync (0x02083EB8), so it is NVRAMi_Verify,
 * the 240-byte nvram.o symbol of that name; the three sync wrappers
 * share one DWARF shape.
 */
NVRAMResult func_020840F8(u32 address, u32 size, void *pData)
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
        result = NVRAMi_VerifyAsync(address, size, pData, NVRAMi_SyncCallback, &msgQ);
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




BOOL NVRAMi_IsInitialized(void)
{
    return g_02150EA0.nvramInitialized == 2;
}




void NVRAMi_Callback(int tag, u32 data, BOOL err)
{
    switch (nvramw.lock) {
    case NVRAM_LOCK_READ:
        NVRAMi_ReadCallback(data, err);
        break;
    case NVRAM_LOCK_WRITE:
        NVRAMi_WriteCallback(data, err);
        break;
    case NVRAM_LOCK_VERIFY:
        NVRAMi_VerifyCallback(data, err);
        break;
    }
}




/*
 * sdk:      NVRAMi_SyncCallback (libnvram.TWL.HYB.a nvram.o)
 */
void func_02084260(int result, void *arg)
{
    if (!OS_SendMessage((struct OSMessageQueue *)arg, (void *)result, 0)) {
        OS_Terminate();
    }
}




void NVRAMi_AlarmHandler(void *arg)
{
    NVRAMi_Callback(4, (u32)arg, 0);
}




BOOL NVRAMi_VerifyDataArray(u8 *data0, u8 *data1, u32 size)
{
    u32 i;

    for (i = 0; i < size; i++) {
        if (data0[i] != data1[i]) {
            return 0;
        }
    }
    return 1;
}




BOOL NVRAMi_WriteEnable(void)
{
    if (0 > PXI_SendWordByFifo(4, 0x03002000, 0)) {
        return 0;
    }
    return 1;
}




BOOL NVRAMi_WriteDisable(void)
{
    if (0 > PXI_SendWordByFifo(4, 0x03002100, 0)) {
        return 0;
    }
    return 1;
}




BOOL NVRAMi_ReadStatusRegister(u8 *pData)
{
    if (0 > PXI_SendWordByFifo(4, 0x02002200 | ((u32)pData >> 24), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00010000 | (((u32)pData >> 8) & 0x0000FFFF), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x01000000 | 0x00020000 | (((u32)pData << 8) & 0x0000FF00), 0)) {
        return 0;
    }
    return 1;
}




BOOL NVRAMi_ReadDataBytes(u32 address, u32 size, u8 *pData)
{
    if (0 > PXI_SendWordByFifo(4, 0x02000000 | 0x2300 | ((address >> 16) & 0x000000FF), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00010000 | (address & 0x0000FFFF), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00020000 | (size >> 16), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00030000 | (size & 0x0000FFFF), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00040000 | ((u32)pData >> 16), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x01000000 | 0x00050000 | ((u32)pData & 0x0000FFFF), 0)) {
        return 0;
    }
    return 1;
}




BOOL NVRAMi_PageWrite(u32 address, u16 size, u8 *pData)
{
    if (0 > PXI_SendWordByFifo(4, 0x02000000 | 0x2500 | ((address >> 16) & 0x000000FF), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00010000 | (address & 0x0000FFFF), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00020000 | size, 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00030000 | ((u32)pData >> 16), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x01000000 | 0x00040000 | ((u32)pData & 0x0000FFFF), 0)) {
        return 0;
    }
    return 1;
}




BOOL NVRAMi_SoftwareReset(void)
{
    if (0 > PXI_SendWordByFifo(4, 0x03002D00, 0)) {
        return 0;
    }
    return 1;
}
