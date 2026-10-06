/*
 * file:     unit_02083644_p02.c
 * unit:     yes
 * function: func_020839E8, func_02083DC8
 * address:  0x020839E8
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
 *   g_02150EA0                 0x02150EA0  data
 *   nvramTemp                  0x02150EC0  data
 *   nvramw                     0x02150EE0  data
 *   NVRAMi_PageWrite           0x020844A8  arm
 *   NVRAMi_SoftwareReset       0x02084570  arm
 *   NVRAMi_WriteEnable         0x020842D8  arm
 *   NVRAMi_WriteDisable        0x02084304  arm
 *   NVRAMi_ReadStatusRegister  0x02084330  arm
 *   NVRAMi_AlarmHandler        0x02084288  arm
 *   OS_GetTick                 0x020870D0  arm
 *   OS_SetAlarm                0x0208738C  arm
 *   OS_WakeupThread            0x02085800  arm
 *   DC_InvalidateRange         0x020862B8  arm
 *   DC_StoreRange              0x020862D4  arm
 *   OS_InitMessageQueue            0x02085D94  arm
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *   NVRAMi_WriteAsync                0x02083934  arm
 *   OS_SleepThread                 0x020857B0  arm
 *   OS_Sleep                       0x02085A38  arm
 *   OS_ReceiveMessage              0x02085E50  arm
 *   OS_Terminate                   0x02088234  arm
 *   NVRAMi_SyncCallback            0x02084260  arm
 *   OSi_ThreadInfo                 0x02150FEC  data
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

typedef struct NVRAMWork_0 {
    NVRAMLock lock;
    NVRAMCallback callback;
    void *callbackArg;
    OSAlarm alarm;
    OSTick tick;
    u32 seq;
    volatile u32 arg[3];
    OSThreadQueue queue;
} NVRAMWork_0;

/* nvram.o .bss from 0x02150EA0: nvramInitialized at +0, nvramTemp (32-byte
   aligned) at +0x20.  A direct read or write of nvramTemp goes through this
   section base; taking its address uses the nvramTemp symbol. */
typedef struct NvramBss {
    u32 nvramInitialized;
    u8 pad04[0x1C];
    u32 nvramTemp[8];
} NvramBss;

typedef struct NVRAMWork_02083DC8 {
    NVRAMLock lock;
    NVRAMCallback callback;
    void *callbackArg;
    OSAlarm alarm;
    OSTick tick;
    u32 seq;
    u32 arg[3];
    OSThreadQueue queue;
} NVRAMWork_02083DC8;

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

extern BOOL NVRAMi_PageWrite(u32 address, u16 size, u8 *pData);
extern BOOL NVRAMi_SoftwareReset(void);
extern BOOL NVRAMi_WriteEnable(void);
extern BOOL NVRAMi_WriteDisable(void);
extern BOOL NVRAMi_ReadStatusRegister(u8 *pData);
extern void NVRAMi_AlarmHandler(void *arg);
extern OSTick OS_GetTick(void);
extern void OS_SetAlarm(OSAlarm *alarm, OSTick tick, OSAlarmHandler handler, void *arg);
extern void OS_WakeupThread(OSThreadQueue *queue);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
u32 OS_DisableInterrupts(void);
u32 OS_RestoreInterrupts(u32 state);
void OS_InitMessageQueue(OSMessageQueue *mq, OSMessage *msgArray, long msgCount);
BOOL OS_ReceiveMessage(OSMessageQueue *mq, OSMessage *msg, long flags);
void OS_SleepThread(OSThreadQueue *queue);
void OS_Sleep(u32 msec);
void OS_Terminate(void);
void NVRAMi_SyncCallback(NVRAMResult result, void *arg);
NVRAMResult NVRAMi_WriteAsync(u32 address, u32 size, void *pData, NVRAMCallback callback, void *arg);
void NVRAMi_WriteCallback(u32 data, BOOL err);
NVRAMResult func_02083DC8(u32 address, u32 size, void *pData);
extern NvramBss g_02150EA0;
extern u32 nvramTemp[8];
extern NVRAMWork_0 nvramw;
extern OSThreadInfo OSi_ThreadInfo;


#define NVRAM_RETRY_SPAN 0x20B


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
            if (*(u8 *)g_02150EA0.nvramTemp & 0x20) {
                if (NVRAMi_SoftwareReset() == 1) {
                    nvramw.seq = 4;
                    return;
                }
                nvramw.seq = 4;
                OS_SetAlarm(&nvramw.alarm, NVRAM_RETRY_SPAN, NVRAMi_AlarmHandler, (void *)4);
                return;
            }
            if (!(*(u8 *)g_02150EA0.nvramTemp & 0x01)) {
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
        if (NVRAMi_ReadStatusRegister((u8 *)nvramTemp) == 1) {
            nvramw.seq = 2;
            return;
        }
        nvramw.seq = 2;
        *(u8 *)g_02150EA0.nvramTemp = 1;
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
