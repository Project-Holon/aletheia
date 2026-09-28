/*
 * function: func_02083644
 * address:  0x02083644
 * packet:   pkt_02083644
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NVRAMi_Init (libnvram.TWL.HYB.a nvram.o)
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

extern u32 nvramInitialized;

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

static inline void OS_InitThreadQueue(OSThreadQueue *queue)
{
    queue->head = queue->tail = 0;
}

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
