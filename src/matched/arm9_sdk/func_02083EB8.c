/*
 * function: NVRAMi_VerifyAsync
 * address:  0x02083EB8
 * packet:   pkt_02083EB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NVRAMi_VerifyAsync (libnvram.TWL.HYB.a nvram.o)
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

extern u8 nvramTemp[32];

u32 OS_DisableInterrupts(void);
u32 OS_RestoreInterrupts(u32 state);
BOOL NVRAMi_IsInitialized(void);
void DC_InvalidateRange(void *startAddr, u32 nBytes);
BOOL NVRAMi_ReadDataBytes(u32 address, u32 size, u8 *buf);
extern void OS_WakeupThread(OSThreadQueue *queue);

NVRAMResult NVRAMi_VerifyAsync(u32 address, u32 size, void *pData, NVRAMCallback callback, void *arg)
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
