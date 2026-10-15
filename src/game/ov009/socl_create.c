/*
 * file:     socl_create.c
 * unit:     yes
 * function: func_0215D070, SOCLi_CreateSocketCallBack, SOCLi_StartupSocket, SOCLi_GetSizeSocket, SOCLi_GetSizeCommandPipe, SOCLi_InitSocket, SOCLi_InitSocketBuffer, SOCLi_InitCommandPipe
 * address:  0x0215D070
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   SOCLi_StartupSocket                0x0215d198 arm
 *   SOCLi_CreateCommandPacket          0x0215ce3c arm
 *   SOCLi_ExecCommandPacketInCtrlPipe  0x0215cfa8 arm
 *   SOCLiConfigPtr                     0x021a1cd8 data
 *   SOCLi_CreateSocketCallBack         0x0215d124 arm
 *   SOCLi_Resource                     0x021aa4ac data
 *   CPS_SocRegister  0x0215AA5C  arm  ov009
 *   CPS_SocDup  0x0215AB7C  arm  ov009
 *   CPS_SocUse  0x0215AB10  arm  ov009
 *   CPS_SocDatagramMode  0x0215AA88  arm  ov009
 *   CPS_SetUdpCallback  0x0215AB94  arm  ov009
 *   SOCLi_UdpRecvCallback  0x0215DF08  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   SOCLi_SocketRegister  0x0215F2DC  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   gSoclConfig  0x021A1CD8  data
 *   func_0215F0C8  0x0215F0C8  arm  ov009
 *   g_021AA44C  0x021AA44C  data
 *   OS_InitMessageQueue  0x02085D94  arm
 *   OS_InitMutex  0x02086004  arm
 *   OS_CreateThread  0x020853C0  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   SOCLi_CommandPacketHandler  0x0215CFC0  arm  ov009
 */
#include "socl_command_types.h"

struct SOCLSocketParam;
struct SOCLiCommandPacket;
struct CPSSoc;
struct SOCLSocket {
    unsigned char pad[0xac];
    short field_ac;
    signed char field_ae;
    signed char field_af;
};

struct SOCLiResource {
    unsigned long count0;
    unsigned long count4;
};

typedef struct {
	unsigned char pad0[0xa4];
	unsigned char *send_pipe;
	unsigned char pad1[4];
	short state;
	signed char flag_block;
	signed char flag_mode;
} Socket;

typedef struct {
	unsigned long pad0;
	Socket *socket;
} Cmd;

typedef struct {
	unsigned char a;
	unsigned char b;
	unsigned short send;
	unsigned short f4;
	unsigned short recv;
	unsigned short sendbuf;
	unsigned short rbuf1;
	unsigned short rbuf2;
	unsigned short cfg;
	unsigned char pipe1[4];
	unsigned char pipe2[4];
} Param;

typedef struct {
	unsigned short a;
	unsigned char b;
	unsigned char c;
} Param_0215D280;

typedef struct {
	unsigned long size;
	unsigned char *data;
} Buf;

typedef struct {
	signed char a;
	signed char b;
	unsigned short send;
	unsigned short f4;
	unsigned short recv;
	unsigned short sendbuf;
	unsigned short rbuf1;
	unsigned short rbuf2;
	unsigned short f0e;
	unsigned char pipe1[4];
	unsigned char pipe2[4];
} Param_0215D2A8;

typedef struct {
	char pad0[0xfc];
	unsigned short f0fc;
	char pad1[0xc];
	unsigned short f10a;
	int f10c;
	int f110;
} SendPipe;

typedef struct {
	char pad0[0xf8];
	Buf f0f8;
	char pad1[0x4];
	int f104;
	int f108;
	void *f10c;
} RecvPipe;

typedef struct Sock {
	char pad0[0x48];
	Buf b48;
	char pad3[4];
	Buf b54;
	Buf b5c;
	Buf b64;
	char pad1[0x34];
	void *pipe_send;
	void *pipe_recv;
	char pad2[0x6];
	signed char f_ae;
	signed char f_af;
} Sock;

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

extern struct SOCLiCommandPacket *SOCLi_CreateCommandPacket(int (*handler)(void *),
                                                            struct SOCLSocket *socket,
                                                            long flag);
extern int SOCLi_ExecCommandPacketInCtrlPipe(struct SOCLSocket *socket,
                                             struct SOCLiCommandPacket *command);
extern int SOCLi_CreateSocketCallBack(void *arg);
extern void CPS_SocRegister(int v);
extern void CPS_SocDup(void *thread);
extern void CPS_SocUse(void);
extern void CPS_SocDatagramMode(void);
extern void CPS_SetUdpCallback(int (*callback)(unsigned char *, unsigned long, void *));
extern int SOCLi_UdpRecvCallback(unsigned char *data, unsigned long len, struct CPSSoc *soc);
extern unsigned long OS_DisableInterrupts(void);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void SOCLi_SocketRegister(int a);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern unsigned long func_0215F0C8(unsigned long size);
extern void OS_InitMessageQueue(OSMessageQueue *mq, OSMessage *msgArray, s32 msgCount);
extern void OS_InitMutex(OSMutex *mutex);
extern void OS_CreateThread(OSThread *thread, void (*func)(void *), void *arg, void *stack,
                            u32 stackSize, u32 prio);
extern void OS_WakeupThreadDirect(OSThread *thread);
extern void SOCLi_CommandPacketHandler(void *arg);
int SOCL_CreateSocket(struct SOCLSocketParam *param);
int SOCLi_CreateSocketCallBack(void *arg);
void *SOCLi_StartupSocket(void *param);
unsigned long SOCLi_GetSizeSocket(Param *param);
unsigned long SOCLi_GetSizeCommandPipe(Param_0215D280 *param);
unsigned char *SOCLi_InitSocket(Sock *socket, const Param_0215D2A8 *param);
unsigned char *SOCLi_InitSocketBuffer(unsigned char *ptr, Buf *buf, unsigned long size);
unsigned char *SOCLi_InitCommandPipe(unsigned char *ptr, SOCLSocketCommandPipe *pipe, const SOCLSocketThreadParam *param);
extern void *SOCLiConfigPtr;
extern struct SOCLiResource SOCLi_Resource;
extern SoclConfig *gSoclConfig;
extern Sock *g_021AA44C;




int SOCL_CreateSocket(struct SOCLSocketParam *param)
{
    struct SOCLSocket *socket;
    struct SOCLiCommandPacket *command;

    if (SOCLiConfigPtr == 0)
        return -0x27;
    socket = SOCLi_StartupSocket(param);
    if (socket == 0)
        return -0x31;
    command = SOCLi_CreateCommandPacket(SOCLi_CreateSocketCallBack, socket, 1);
    SOCLi_ExecCommandPacketInCtrlPipe(socket, command);
    {
        int flag = 0;

        if (socket != 0) {
            if (socket->field_ac & 1)
                flag = 1;
            else
                flag = 0;
        }
        if (flag != 0) {
            int b = (socket->field_af == 0 || socket->field_af == 4);

            if (b)
                SOCLi_Resource.count0++;
            else
                SOCLi_Resource.count4++;
        }
    }
    return (int)socket;
}




/*
 * sdk:      SOCLi_CreateSocketCallBack (libsoc.TWL.HYB.a(socl_create.o))
 */
int SOCLi_CreateSocketCallBack(void *arg)
{
	Socket *socket;
	unsigned char *send_pipe;

	socket = ((Cmd *)arg)->socket;
	CPS_SocRegister((int)socket);
	send_pipe = socket->send_pipe;
	switch (socket->flag_mode) {
	case 0:
	case 4:
		CPS_SocDup(send_pipe + 0x20);
		CPS_SocUse();
		break;
	case 1:
		CPS_SocUse();
		CPS_SocDatagramMode();
		CPS_SetUdpCallback((int (*)(unsigned char *, long unsigned int,  void *))SOCLi_UdpRecvCallback);
		break;
	case 2:
		CPS_SocDatagramMode();
		break;
	}
	socket->state = 1;
	return 0;
}




void *SOCLi_StartupSocket(void *param)
{
	void *socket;
	unsigned long enable;
	unsigned long size;

	size = SOCLi_GetSizeSocket(param);
	enable = OS_DisableInterrupts();
	socket = gSoclConfig->alloc(size);
	if (socket) {
		MI_CpuFill8(socket, 0, size);
		SOCLi_InitSocket((Sock *)socket, (const Param_0215D2A8 *)param);
		SOCLi_SocketRegister((int)socket);
	}
	OS_RestoreInterrupts(enable);
	return socket;
}




/*
 * sdk:      SOCLi_GetSizeSocket (libsoc.TWL.HYB.a(socl_create.o))
 */
unsigned long SOCLi_GetSizeSocket(Param *param)
{
	unsigned long size;

	size = 0xbc;
	if (param->send) {
		size += 0x114;
		size += func_0215F0C8(param->send);
		size += func_0215F0C8(param->sendbuf);
		size += SOCLi_GetSizeCommandPipe((Param_0215D280 *)param->pipe1);
	}
	if (param->recv) {
		size += 0x110;
		size += func_0215F0C8(param->recv);
		size += func_0215F0C8(param->rbuf1);
		size += func_0215F0C8(param->rbuf2);
		size += SOCLi_GetSizeCommandPipe((Param_0215D280 *)param->pipe2);
	}
	return size;
}




/*
 * sdk:      SOCLi_GetSizeCommandPipe (libsoc.TWL.HYB.a(socl_create.o))
 */
unsigned long SOCLi_GetSizeCommandPipe(Param_0215D280 *param)
{
	unsigned long size;

	size = func_0215F0C8(param->c << 2);
	size += func_0215F0C8(param->a);
	return size;
}




/*
 * Two things close the 99 B of register-allocation diff this file carried
 * while it sat at MATCH with all eight relocations already resolved.
 *
 * `const` on the second parameter is the whole of the first 98. The object
 * issues `ldrh r1,[r6,#2]` (param->send) as the *second* instruction of the
 * function, above both `strb` stores into `socket->f_af`/`f_ae`, and sinks
 * `add r5,r7,#0xbc` below them. Without the qualifier mwcc treats the two
 * pointers as possibly aliasing, keeps the load where the source order puts
 * it, and then colours the whole function one register down: r5 = param,
 * r6 = socket, r4 = ptr, r7 = rpipe, against the object's r6 = param,
 * r7 = socket, r5 = ptr, r4 = pipe. The qualifier is what lets the load
 * hoist, and the hoist is what fixes the colouring -- same shape as
 * docs/idioms/a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md.
 * The callee's third parameter has to be spelled `const void *` for the same
 * reason: `param->pipe1` and `param->pipe2` are four-byte arrays, and passing
 * them to a `void *` is the error that first shows the qualifier is real.
 *
 * The last byte is a struct offset, not code: `spipe->f10a` is at +0x10a, so
 * the run between the u16 at +0xfc and it is 0xc bytes, not 0xa. The 0xf8
 * command pipe behind that header is the one
 * src/matched/ov_sdk/ov009_func_0215D3C8.c already pins (queue +0x00,
 * thread +0x20, mutex +0xe0), which is why +0x10c and +0x110 land on the two
 * word stores that follow.
 *
 * sdk:      SOCLi_InitSocket (libsoc.TWL.HYB.a(socl_create.o))
 */
unsigned char *SOCLi_InitSocket(Sock *socket, const Param_0215D2A8 *param)
{
	unsigned char *ptr = (unsigned char *)socket + 0xbc;

	socket->f_af = param->a;
	socket->f_ae = param->b;
	if (param->send) {
		SendPipe *spipe;

		spipe = (SendPipe *)ptr;
		socket->pipe_send = ptr;
		spipe->f0fc = param->f4;
		ptr = SOCLi_InitCommandPipe(ptr + 0x114, (SOCLSocketCommandPipe *)spipe, (const SOCLSocketThreadParam *)param->pipe1);
		ptr = SOCLi_InitSocketBuffer(ptr, &socket->b48, param->send);
		ptr = SOCLi_InitSocketBuffer(ptr, &socket->b5c, param->sendbuf);
		spipe->f10a = param->f0e;
		spipe->f110 = 0;
		spipe->f10c = 0;
	}
	if (param->recv == 0) {
		socket->pipe_recv = g_021AA44C->pipe_recv;
	} else {
		RecvPipe *rpipe;

		socket->pipe_recv = ptr;
		rpipe = (RecvPipe *)ptr;
		rpipe->f10c = socket;
		ptr = SOCLi_InitCommandPipe(ptr + 0x110, (SOCLSocketCommandPipe *)rpipe, (const SOCLSocketThreadParam *)param->pipe2);
		ptr = SOCLi_InitSocketBuffer(ptr, &socket->b54, param->recv);
		ptr = SOCLi_InitSocketBuffer(ptr, &socket->b64, param->rbuf1);
		ptr = SOCLi_InitSocketBuffer(ptr, &rpipe->f0f8, param->rbuf2);
		rpipe->f108 = 0;
		rpipe->f104 = 0;
	}
	return ptr;
}



/*
 * sdk:      SOCLi_InitSocketBuffer (libsoc.TWL.HYB.a(socl_create.o))
 */
unsigned char *SOCLi_InitSocketBuffer(unsigned char *ptr, Buf *buf, unsigned long size)
{
	buf->data = size ? ptr : 0;
	buf->size = size;
	return ptr + func_0215F0C8(size);
}



/*
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
 */
unsigned char *SOCLi_InitCommandPipe(unsigned char *ptr, SOCLSocketCommandPipe *pipe,
                             const SOCLSocketThreadParam *param)
{
	unsigned char *stack_bottom;

	stack_bottom = ptr + SOCLi_GetSizeCommandPipe((Param_0215D280 *)param);
	OS_InitMessageQueue(&pipe->queue, (OSMessage *)ptr, param->msgCount);
	OS_InitMutex(&pipe->mutex);
	OS_CreateThread(&pipe->thread, SOCLi_CommandPacketHandler, pipe, stack_bottom, param->stackSize, param->prio);
	OS_WakeupThreadDirect(&pipe->thread);
	return stack_bottom;
}
