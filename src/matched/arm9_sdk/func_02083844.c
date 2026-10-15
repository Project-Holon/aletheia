/*
 * function: NVRAMi_Read
 * address:  0x02083844
 * packet:   pkt_02083844
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NVRAMi_Read (libnvram.TWL.HYB.a nvram.o)
 *
 * symbols:
 *   OS_InitMessageQueue            0x02085D94  arm
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *   NVRAMi_ReadAsync                0x02083704  arm
 *   OS_SleepThread                 0x020857B0  arm
 *   OS_Sleep                       0x02085A38  arm
 *   OS_ReceiveMessage              0x02085E50  arm
 *   OS_Terminate                   0x02088234  arm
 *   NVRAMi_SyncCallback            0x02084260  arm
 *   OSi_ThreadInfo                 0x02150FEC  data
 *   nvramw                         0x02150EE0  data
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

/* nvram.o .bss from 0x02150EA0: nvramInitialized at +0, nvramTemp (32-byte
   aligned) at +0x20.  A direct read or write of nvramTemp goes through this
   section base; taking its address uses the nvramTemp symbol. */
extern NVRAMWork nvramw;

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

extern OSThreadInfo OSi_ThreadInfo;

u32 OS_DisableInterrupts(void);
u32 OS_RestoreInterrupts(u32 state);
void OS_InitMessageQueue(OSMessageQueue *mq, OSMessage *msgArray, long msgCount);
BOOL OS_ReceiveMessage(OSMessageQueue *mq, OSMessage *msg, long flags);
void OS_SleepThread(OSThreadQueue *queue);
void OS_Sleep(u32 msec);
void OS_Terminate(void);
void NVRAMi_SyncCallback(NVRAMResult result, void *arg);
NVRAMResult NVRAMi_ReadAsync(u32 address, u32 size, void *pData, NVRAMCallback callback, void *arg);

NVRAMResult NVRAMi_Read(u32 address, u32 size, void *pData)
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
