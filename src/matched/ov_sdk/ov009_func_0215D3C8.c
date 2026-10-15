/*
 * function: SOCLi_InitCommandPipe
 * address:  0x0215D3C8
 * packet:   pkt_ov009_0215D3C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * w9_nm's 22 B closed: the object issues `ldrb r1,[param,#2]` (the prio, one of
 * OS_CreateThread's two stack arguments) *above* the outgoing-argument store
 * `str r2,[sp]`, and without the qualifier mwcc sinks it below the store and
 * through ip. `const` on the read-only third parameter is the whole fix: the
 * store to the argument area can no longer alias the load, so the load hoists.
 * See docs/idioms/a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md
 * (its second shape, outgoing args 5 and 6). Nothing else changes: the same
 * body without `const` is 22 B out, and locals, casts, statement orders and
 * the callee prototype are all 22 B.
 *
 * The layouts below are the ones the two adds confirm: the message queue sits
 * at +0, the thread at +0x20 and the mutex at +0xe0, so sizeof(OSMessageQueue)
 * = 0x20 and sizeof(OSThread) = 0xc0. Both are the definitions already proven
 * in src/matched/arm9_sdk/OS_InitMessageQueue.c and OS_CreateThread.c, not fresh
 * guesses. The four-byte thread param is fixed independently by
 * SOCLi_GetSizeCommandPipe (SOCLi_GetSizeCommandPipe: +0 is the stack size, +2 a priority
 * byte, +3 the message count) and by SOCLi_GetSizeSocket (pipe1/pipe2 are 4 bytes).
 *
 * sdk:      SOCLi_InitCommandPipe (libsoc.TWL.HYB.a(socl_create.o))
 *
 * symbols:
 *   SOCLi_GetSizeCommandPipe  0x0215D280  arm  ov009
 *   OS_InitMessageQueue  0x02085D94  arm
 *   OS_InitMutex  0x02086004  arm
 *   OS_CreateThread  0x020853C0  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   SOCLi_CommandPacketHandler  0x0215CFC0  arm  ov009
 */

typedef unsigned long long u64;
typedef unsigned long u32;
typedef long s32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct CPContext {
	u8 opaque[0x1C];
} CPContext;

typedef struct OSContext {
	u32 cpsr;
	u32 r[13];
	u32 sp;
	u32 lr;
	u32 pc_plus4;
	u32 sp_svc;
	CPContext cp_context;
} OSContext;

typedef enum OSThreadState {
	OS_THREAD_STATE_WAITING = 0,
	OS_THREAD_STATE_READY = 1,
	OS_THREAD_STATE_TERMINATED = 2
} OSThreadState;

typedef struct _OSThread OSThread;
typedef struct OSMutex OSMutex;
typedef struct OSiAlarm OSAlarm;

typedef struct _OSThreadQueue {
	OSThread *head;
	OSThread *tail;
} OSThreadQueue;

typedef struct _OSThreadLink {
	OSThread *prev;
	OSThread *next;
} OSThreadLink;

typedef struct _OSMutexQueue {
	OSMutex *head;
	OSMutex *tail;
} OSMutexQueue;

typedef struct _OSMutexLink {
	OSMutex *next;
	OSMutex *prev;
} OSMutexLink;

typedef void (*OSAlarmHandler)(void *arg);

struct OSiAlarm {
	OSAlarmHandler handler;
	void *arg;
	u32 tag;
	u64 fire;
	OSAlarm *prev;
	OSAlarm *next;
	u64 period;
	u64 start;
};

struct OSMutex {
	OSThreadQueue queue;
	OSThread *thread;
	s32 count;
	OSMutexLink link;
};

struct _OSThread {
	OSContext context;
	OSThreadState state;
	OSThread *next;
	u32 id;
	u32 priority;
	void *profiler;
	OSThreadQueue *queue;
	OSThreadLink link;
	OSMutex *mutex;
	OSMutexQueue mutexQueue;
	u32 stackTop;
	u32 stackBottom;
	u32 stackWarningOffset;
	OSThreadQueue joinQueue;
	void *specific[3];
	OSAlarm *alarmForSleep;
	void (*destructor)(void *);
	void *userParameter;
	int systemErrno;
};

typedef void *OSMessage;

typedef struct OSMessageQueue {
	OSThreadQueue queueSend;
	OSThreadQueue queueReceive;
	OSMessage *msgArray;
	s32 msgCount;
	s32 firstIndex;
	s32 usedCount;
} OSMessageQueue;

typedef struct {
	u16 stackSize;
	u8 prio;
	u8 msgCount;
} SOCLSocketThreadParam;

typedef struct {
	OSMessageQueue queue;
	OSThread thread;
	OSMutex mutex;
} SOCLSocketCommandPipe;

extern u32 SOCLi_GetSizeCommandPipe(const SOCLSocketThreadParam *param);
extern void OS_InitMessageQueue(OSMessageQueue *mq, OSMessage *msgArray, s32 msgCount);
extern void OS_InitMutex(OSMutex *mutex);
extern void OS_CreateThread(OSThread *thread, void (*func)(void *), void *arg, void *stack,
                            u32 stackSize, u32 prio);
extern void OS_WakeupThreadDirect(OSThread *thread);
extern void SOCLi_CommandPacketHandler(void *arg);

unsigned char *SOCLi_InitCommandPipe(unsigned char *ptr, SOCLSocketCommandPipe *pipe,
                             const SOCLSocketThreadParam *param)
{
	unsigned char *stack_bottom;

	stack_bottom = ptr + SOCLi_GetSizeCommandPipe(param);
	OS_InitMessageQueue(&pipe->queue, (OSMessage *)ptr, param->msgCount);
	OS_InitMutex(&pipe->mutex);
	OS_CreateThread(&pipe->thread, SOCLi_CommandPacketHandler, pipe, stack_bottom, param->stackSize, param->prio);
	OS_WakeupThreadDirect(&pipe->thread);
	return stack_bottom;
}
