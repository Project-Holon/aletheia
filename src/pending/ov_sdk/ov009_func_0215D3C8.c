/*
 * function: func_0215D3C8
 * address:  0x0215D3C8
 * packet:   pkt_ov009_0215D3C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * w9_nm: 22 B: the object loads stacksize and prio (ldrh, ldrb) before the thread address add and the pool load; the compile defers the ldrb. Tried locals for both (u32, u16/u8, either order), a thread pointer local, swapped prototype order, u8 prio parameter: same 22 B.
 *
 * sdk:      SOCLi_InitCommandPipe (libsoc.TWL.HYB.a(socl_create.o))
 *
 * symbols:
 *   func_0215D280  0x0215D280  arm  ov009
 *   OS_InitMessageQueue  0x02085D94  arm
 *   OS_InitMutex  0x02086004  arm
 *   OS_CreateThread  0x020853C0  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   func_0215CFC0  0x0215CFC0  arm  ov009
 */

typedef struct {
	unsigned short stacksize;
	unsigned char prio;
	unsigned char qlen;
} Param;

typedef struct { char b[0xc0]; } Thread;
typedef struct { char b[0x1c]; } Mutex;
typedef struct { char b[0x20]; } Queue;

typedef struct {
	Queue queue;
	Thread thread;
	Mutex mutex;
} Pipe;

extern unsigned long func_0215D280(Param *param);
extern void OS_InitMessageQueue(Queue *mq, void **msgArray, long msgCount);
extern void OS_InitMutex(Mutex *mutex);
extern void OS_CreateThread(Thread *thread, void (*func)(void *), void *arg, void *stack, unsigned long stackSize, unsigned long prio);
extern void OS_WakeupThreadDirect(Thread *thread);
extern void func_0215CFC0(void *arg);

unsigned char *func_0215D3C8(unsigned char *ptr, Pipe *pipe, Param *param)
{
	unsigned char *stack_bottom;

	stack_bottom = ptr + func_0215D280(param);
	OS_InitMessageQueue(&pipe->queue, (void **)ptr, param->qlen);
	OS_InitMutex(&pipe->mutex);
	OS_CreateThread(&pipe->thread, func_0215CFC0, pipe, stack_bottom, param->stacksize, param->prio);
	OS_WakeupThreadDirect(&pipe->thread);
	return stack_bottom;
}
