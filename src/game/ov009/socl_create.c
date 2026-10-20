/*
 * file:     socl_create.c
 * unit:     yes
 * function: SOCL_CreateSocket, SOCLi_CreateSocketCallBack, SOCLi_StartupSocket, SOCLi_GetSizeSocket, SOCLi_GetSizeCommandPipe, SOCLi_InitSocket, SOCLi_InitSocketBuffer, SOCLi_InitCommandPipe
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
 *   SOCLi_RoundUp4  0x0215F0C8  arm  ov009
 *   SOCLiUDPSendSocket  0x021AA44C  data
 *   OS_InitMessageQueue  0x02085D94  arm
 *   OS_InitMutex  0x02086004  arm
 *   OS_CreateThread  0x020853C0  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   SOCLi_CommandPacketHandler  0x0215CFC0  arm  ov009
 */
#include "cps_network.h"
#include "socl_command_types.h"

struct SOCLSocketParam;
struct SOCLiCommandPacket;
struct CPSSoc;
#include "socl_types.h"

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
	signed char a;
	signed char b;
	unsigned short send;
	unsigned short sendLimit;
	unsigned short recv;
	unsigned short sendbuf;
	unsigned short rbuf1;
	unsigned short rbuf2;
	unsigned short cfg;
	unsigned char pipe1[4];
	unsigned char pipe2[4];
} Param;

typedef struct {
	unsigned long size;
	unsigned char *data;
} Buf;

/* SOCLiSocketRecvCommandPipe (socl.h): the 0xf8-byte command pipe, then the consume
 * state and the UDP data control block (in, out, size, size_max, waiting queue). */
typedef struct {
	char h[0xf8];
	long consumed;
	unsigned short consumedMin;
	signed char flagNoconsume;
	unsigned char padding;
	void *udpIn;
	void *udpOut;
	unsigned short udpSize;
	unsigned short udpSizeMax;
	void *udpWaitingHead;
	void *udpWaitingTail;
} RecvPipe;

/* SOCLiSocketSendCommandPipe (socl.h): the 0xf8-byte command pipe, then the ring
 * buffer (area, in, out, waiting queue) and exe_socket. */
typedef struct {
	char h[0xf8];
	Buf area;
	unsigned short in;
	unsigned short out;
	void *waitingHead;
	void *waitingTail;
	void *exeSocket;
} SendPipe;

typedef struct Sock {
	char pad0[0x48];
	Buf b48;
	char pad3[4];
	Buf b54;
	Buf b5c;
	Buf b64;
	char pad1[0x34];
	void *recv_pipe;
	void *send_pipe;
	char pad2[0x6];
	signed char f_ae;
	signed char f_af;
} Sock;

#include "../types.h"

#include "../sdk_os.h"

#include "../sdk_os_thread.h"

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

#include "socl_command.h"
extern int SOCLi_CreateSocketCallBack(void *arg);
extern void CPS_SocRegister(int v);
extern void CPS_SocDup(char *dst);
extern void CPS_SocUse(void);
extern void CPS_SocDatagramMode(void);
#include "socl_read.h"
#include "../arm9/os_system.h"
#include "../arm9/mi_memory.h"
#include "socl_list.h"
#include "socl_misc.h"
#include "../arm9/os_message.h"
#include "../arm9/os_mutex.h"
#include "../arm9/os_thread.h"
int SOCL_CreateSocket(struct SOCLSocketParam *param);
int SOCLi_CreateSocketCallBack(void *arg);
void *SOCLi_StartupSocket(void *param);
unsigned long SOCLi_GetSizeSocket(Param *param);
unsigned long SOCLi_GetSizeCommandPipe(SOCLSocketThreadParam *param);
unsigned char *SOCLi_InitSocket(Sock *socket, const Param *param);
unsigned char *SOCLi_InitSocketBuffer(unsigned char *ptr, Buf *buf, unsigned long size);
unsigned char *SOCLi_InitCommandPipe(unsigned char *ptr, SOCLSocketCommandPipe *pipe, const SOCLSocketThreadParam *param);
extern void *SOCLiConfigPtr;
extern struct SOCLiResource SOCLi_Resource;
extern SOCLConfig *gSoclConfig;
extern Sock *SOCLiUDPSendSocket;

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
    SOCLi_ExecCommandPacketInCtrlPipe((sptr)socket, (sptr)command);
    {
        int flag = 0;

        if (socket != 0) {
            if (socket->state & 1)
                flag = 1;
            else
                flag = 0;
        }
        if (flag != 0) {
            int b = (socket->flag_mode == 0 || socket->flag_mode == 4);

            if (b)
                SOCLi_Resource.count0++;
            else
                SOCLi_Resource.count4++;
        }
    }
    return (sptr)socket;
}

/*
 * sdk:      SOCLi_CreateSocketCallBack (libsoc.TWL.HYB.a(socl_create.o))
 */
int SOCLi_CreateSocketCallBack(void *arg)
{
	Socket *socket;
	unsigned char *send_pipe;

	socket = ((Cmd *)arg)->socket;
	CPS_SocRegister((sptr)socket);
	send_pipe = socket->send_pipe;
	switch (socket->flag_mode) {
	case 0:
	case 4:
		CPS_SocDup((char *)(send_pipe + 0x20));
		CPS_SocUse();
		break;
	case 1:
		CPS_SocUse();
		CPS_SocDatagramMode();
		CPS_SetUdpCallback((int (*)(unsigned char *, unsigned long, struct CPSSoc *))SOCLi_UdpRecvCallback);
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
		SOCLi_InitSocket((Sock *)socket, (const Param *)param);
		SOCLi_SocketRegister(socket);
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
		size += SOCLi_RoundUp4(param->send);
		size += SOCLi_RoundUp4(param->sendbuf);
		size += SOCLi_GetSizeCommandPipe((SOCLSocketThreadParam *)param->pipe1);
	}
	if (param->recv) {
		size += 0x110;
		size += SOCLi_RoundUp4(param->recv);
		size += SOCLi_RoundUp4(param->rbuf1);
		size += SOCLi_RoundUp4(param->rbuf2);
		size += SOCLi_GetSizeCommandPipe((SOCLSocketThreadParam *)param->pipe2);
	}
	return size;
}

/*
 * sdk:      SOCLi_GetSizeCommandPipe (libsoc.TWL.HYB.a(socl_create.o))
 */
unsigned long SOCLi_GetSizeCommandPipe(SOCLSocketThreadParam *param)
{
	unsigned long size;

	size = SOCLi_RoundUp4(param->msgCount << 2);
	size += SOCLi_RoundUp4(param->stackSize);
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
 * The last byte is a struct offset, not code: `rpipe->udpSizeMax` is at +0x10a, so
 * the run between the u16 at +0xfc and it is 0xc bytes, not 0xa. The 0xf8
 * command pipe behind that header is the one
 * src/matched/ov_sdk/SOCLi_InitCommandPipe.c already pins (queue +0x00,
 * thread +0x20, mutex +0xe0), which is why +0x10c and +0x110 land on the two
 * word stores that follow.
 *
 * sdk:      SOCLi_InitSocket (libsoc.TWL.HYB.a(socl_create.o))
 */
unsigned char *SOCLi_InitSocket(Sock *socket, const Param *param)
{
	unsigned char *ptr = (unsigned char *)socket + 0xbc;

	socket->f_af = param->a;
	socket->f_ae = param->b;
	if (param->send) {
		RecvPipe *rpipe;

		rpipe = (RecvPipe *)ptr;
		socket->recv_pipe = ptr;
		rpipe->consumedMin = param->sendLimit;
		ptr = SOCLi_InitCommandPipe(ptr + 0x114, (SOCLSocketCommandPipe *)rpipe, (const SOCLSocketThreadParam *)param->pipe1);
		ptr = SOCLi_InitSocketBuffer(ptr, &socket->b48, param->send);
		ptr = SOCLi_InitSocketBuffer(ptr, &socket->b5c, param->sendbuf);
		rpipe->udpSizeMax = param->cfg;
		rpipe->udpWaitingTail = 0;
		rpipe->udpWaitingHead = 0;
	}
	if (param->recv == 0) {
		socket->send_pipe = SOCLiUDPSendSocket->send_pipe;
	} else {
		SendPipe *spipe;

		socket->send_pipe = ptr;
		spipe = (SendPipe *)ptr;
		spipe->exeSocket = socket;
		ptr = SOCLi_InitCommandPipe(ptr + 0x110, (SOCLSocketCommandPipe *)spipe, (const SOCLSocketThreadParam *)param->pipe2);
		ptr = SOCLi_InitSocketBuffer(ptr, &socket->b54, param->recv);
		ptr = SOCLi_InitSocketBuffer(ptr, &socket->b64, param->rbuf1);
		ptr = SOCLi_InitSocketBuffer(ptr, &spipe->area, param->rbuf2);
		spipe->waitingTail = 0;
		spipe->waitingHead = 0;
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
	return ptr + SOCLi_RoundUp4(size);
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

	stack_bottom = ptr + SOCLi_GetSizeCommandPipe((SOCLSocketThreadParam *)param);
	OS_InitMessageQueue(&pipe->queue, (OSMessage *)ptr, param->msgCount);
	OS_InitMutex(&pipe->mutex);
	OS_CreateThread(&pipe->thread, SOCLi_CommandPacketHandler, pipe, stack_bottom, param->stackSize, param->prio);
	OS_WakeupThreadDirect(&pipe->thread);
	return stack_bottom;
}
