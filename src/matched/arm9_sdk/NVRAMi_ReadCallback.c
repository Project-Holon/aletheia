/*
 * function: NVRAMi_ReadCallback
 * address:  0x020837B8
 * packet:   pkt_020837B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libnvram nvram.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Static in the vendor object: completion of an NVRAM read.  Maps the PXI
 * status and the SPI result byte to an NVRAMResult, releases the lock,
 * hands the result to the user callback and wakes waiting threads.
 *
 * symbols:
 *   OS_WakeupThread                  0x02085800  arm
 *   nvramw                           0x02150EE0  data
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

extern void OS_WakeupThread(OSThreadQueue *queue);

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
