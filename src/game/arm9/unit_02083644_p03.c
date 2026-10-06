/*
 * file:     unit_02083644_p03.c
 * unit:     yes
 * function: func_02083EB8, func_02083FA0, func_020840F8
 * address:  0x02083EB8
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
 *   NVRAMi_IsInitialized           0x020841E8  arm
 *   DC_InvalidateRange             0x020862B8  arm
 *   NVRAMi_ReadDataBytes           0x020843B4  arm
 *   OS_WakeupThread                0x02085800  arm
 *   nvramw                         0x02150EE0  data
 *   nvramTemp                      0x02150EC0  data
 *   NVRAMi_VerifyDataArray           0x020842A0  arm
 *   OS_InitMessageQueue            0x02085D94  arm
 *   NVRAMi_VerifyAsync                0x02083EB8  arm
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
BOOL NVRAMi_IsInitialized(void);
void DC_InvalidateRange(void *startAddr, u32 nBytes);
BOOL NVRAMi_ReadDataBytes(u32 address, u32 size, u8 *buf);
extern void OS_WakeupThread(OSThreadQueue *queue);
extern BOOL NVRAMi_VerifyDataArray(u8 *data0, u8 *data1, u32 size);
void OS_InitMessageQueue(OSMessageQueue *mq, OSMessage *msgArray, long msgCount);
BOOL OS_ReceiveMessage(OSMessageQueue *mq, OSMessage *msg, long flags);
void OS_SleepThread(OSThreadQueue *queue);
void OS_Sleep(u32 msec);
void OS_Terminate(void);
void NVRAMi_SyncCallback(NVRAMResult result, void *arg);
NVRAMResult NVRAMi_VerifyAsync(u32 address, u32 size, void *pData, NVRAMCallback callback, void *arg);
NVRAMResult func_02083EB8(u32 address, u32 size, void *pData, NVRAMCallback callback, void *arg);
void NVRAMi_VerifyCallback(u32 data, BOOL err);
NVRAMResult func_020840F8(u32 address, u32 size, void *pData);
/* nvram.o .bss from 0x02150EA0: nvramInitialized at +0, nvramTemp (32-byte
   aligned) at +0x20.  A direct read or write of nvramTemp goes through this
   section base; taking its address uses the nvramTemp symbol. */
extern NVRAMWork nvramw;
extern u8 nvramTemp[32];
extern OSThreadInfo OSi_ThreadInfo;


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


#define NVRAM_TEMP_SIZE 32


void NVRAMi_VerifyCallback(u32 data, BOOL err)
{
    NVRAMResult result;
    u16 pxiResult = (u16)(data & 0xFF);
    u16 tempSize;
    NVRAMCallback cb;

    result = NVRAM_RESULT_UNKNOWN;
    tempSize = (u16)((nvramw.arg[1] > NVRAM_TEMP_SIZE) ? NVRAM_TEMP_SIZE : nvramw.arg[1]);

    if (!err && pxiResult == 0) {
        if (!NVRAMi_VerifyDataArray((u8 *)nvramTemp, (u8 *)nvramw.arg[2], tempSize)) {
            result = NVRAM_RESULT_FATAL_ERROR;
        } else {
            nvramw.arg[0] += tempSize;
            nvramw.arg[1] -= tempSize;
            nvramw.arg[2] += tempSize;
            if (nvramw.arg[1] != 0) {
                DC_InvalidateRange(nvramTemp, NVRAM_TEMP_SIZE);
                if (NVRAMi_ReadDataBytes(nvramw.arg[0],
                                         (nvramw.arg[1] > NVRAM_TEMP_SIZE) ? NVRAM_TEMP_SIZE : nvramw.arg[1],
                                         (u8 *)nvramTemp) == 1) {
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
            if (NVRAMi_ReadDataBytes(nvramw.arg[0], tempSize, (u8 *)nvramTemp) == 1) {
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
