/*
 * file:     socl_close.c
 * unit:     yes
 * function: func_0215E794, func_0215E7C8, func_0215E84C, func_0215E980, func_0215EA1C, func_0215EB14, func_0215EBB4
 * address:  0x0215E794
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0215F3D0  0x0215F3D0  arm  ov009
 *   func_0215F404  0x0215F404  arm  ov009
 *   OS_DisableInterrupts   0x02087988 arm
 *   SOCL_SocketIsInTrash   0x0215f404 arm
 *   OS_RestoreInterrupts   0x0208799c arm
 *   SOCL_SocketIsInvalid   0x0215f3d0 arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_0215CEB0  0x0215CEB0  arm  ov009
 *   func_0215CE3C  0x0215CE3C  arm  ov009
 *   func_0215CEFC  0x0215CEFC  arm  ov009
 *   g_021AA4AC     0x021AA4AC  data
 *   OS_JoinThread  0x02085710  arm
 *   CPS_TcpShutdown  0x0215AD00  arm  ov009
 *   CPS_TcpClose  0x0215AD3C  arm  ov009
 *   CPS_SocRelease  0x0215AB5C  arm  ov009
 *   CPS_SocUnRegister  0x0215AA70  arm  ov009
 *   func_0215F31C  0x0215F31C  arm  ov009
 *   func_0215F304  0x0215F304  arm  ov009
 *   func_0215EB14  0x0215EB14  arm  ov009
 *   OS_WakeupThread  0x02085800  arm
 *   func_0215F3B8  0x0215F3B8  arm  ov009
 *   g_021A1CD8     0x021A1CD8  data
 *   OS_DisableScheduler  0x02085B30  arm
 *   func_02085E50  0x02085E50  arm
 *   func_02085DBC  0x02085DBC  arm
 *   func_0215CE7C  0x0215CE7C  arm  ov009
 *   OS_EnableScheduler  0x02085B60  arm
 *   OS_RescheduleThread  0x020858BC  arm
 *   func_0215EA1C  0x0215EA1C  arm  ov009
 *   g_021AA4B8  0x021AA4B8  data
 */

#include "../../matched/include/G_SOCLResource.h"
#include "../../matched/include/G_021A1CD8.h"

typedef struct UdpData UdpData;
struct UdpData {
	UdpData *next;
};

typedef struct {
	unsigned long a;
	UdpData *head;
	unsigned short size;
	unsigned short pad;
	unsigned long queue[2];
} UdpControl;

typedef struct {
	unsigned char pad0[0x100];
	UdpControl udpdata;
} RecvPipe;

typedef struct Socket {
	unsigned char pad0[0xa0];
	RecvPipe *recv_pipe;
	unsigned char *send_pipe;
	unsigned char pad1[4];
	short state;
	signed char flag_block;
	signed char flag_mode;
} Socket;

struct SOCLCommand {
	unsigned char pad[8];
	int field8;
};

typedef struct {
	unsigned long pad0;
	Socket *socket;
} Cmd;

extern int func_0215F3D0(void *s);
extern int func_0215F404(int b);
extern unsigned long OS_DisableInterrupts(void);
extern int SOCL_SocketIsInTrash(Socket * socket);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern int SOCL_SocketIsInvalid(Socket * socket);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern int func_0215CEB0(int a0, char *a1);
extern struct SOCLCommand *func_0215CE3C(int (*handler)(void *), Socket *socket, long flag);
extern void func_0215CEFC(int a, int b);
extern void OS_JoinThread(void *thread);
extern void CPS_TcpShutdown(void);
extern void CPS_TcpClose(void);
extern void CPS_SocRelease(void);
extern void CPS_SocUnRegister(void);
extern void func_0215F31C(int a);
extern void func_0215F304(int a);
/* * sdk: SOCL_IsClosed (libsoc.TWL.HYB.a(socl_close.o)) */ int func_0215E794(int s);
int SOCL_IsReleased(int s);
/* * sdk: SOCL_Close (libsoc.TWL.HYB.a(socl_close.o)) */ int func_0215E84C(int s);
int func_0215E980(void *arg);
extern struct SOCLResource g_021AA4AC;
extern struct G_021A1CD8 *g_021A1CD8;
extern Socket *g_021AA4B8;
typedef struct {
	unsigned long pad0[2];
	void *reply;
} Command;
extern void func_0215EB14(unsigned char *pipe);
extern void OS_WakeupThread(void *queue);
extern void func_0215F3B8(int a);
extern unsigned long OS_DisableScheduler(void);
extern int func_02085E50(void *mq, void **msg, long flags);
extern int func_02085DBC(void *mq, void *msg, long flags);
extern void func_0215CE7C(void *ptr);
extern unsigned long OS_EnableScheduler(void);
extern void OS_RescheduleThread(void);
void func_0215EA1C(Socket *socket);
void func_0215EBB4(void);



/*
 * sdk:      SOCL_IsClosed (libsoc.TWL.HYB.a(socl_close.o))
 */
int func_0215E794(int s)
{
	void *socket;

	if (s >= 0) {
		socket = (void *)s;
		if (func_0215F3D0(socket) != 0 && func_0215F404((int)socket) == 0)
			return 1;
	}
	return 0;
}



int SOCL_IsReleased(int s)
{
    unsigned long enable;
    Socket * socket;

    if (s <= 0)
        return 0;
    enable = OS_DisableInterrupts();
    socket = (Socket *)s;
    if (SOCL_SocketIsInTrash(socket)) {
        OS_RestoreInterrupts(enable);
        return 0;
    }
    if (SOCL_SocketIsInvalid(socket)) {
        OS_RestoreInterrupts(enable);
        return 1;
    }
    if (socket->state & 0x10) {
        OS_RestoreInterrupts(enable);
        return 0;
    }
    OS_RestoreInterrupts(enable);
    return 1;
}



/*
 * sdk:      SOCL_Close (libsoc.TWL.HYB.a(socl_close.o))
 */
int func_0215E84C(int s)
{
	Socket *socket = (Socket *)s;
	struct SOCLCommand *command;
	int result = 0;
	unsigned long enable;

	if (s <= 0)
		return -0x1c;
	enable = OS_DisableInterrupts();
	if (func_0215F404((int)socket) != 0) {
		OS_RestoreInterrupts(enable);
		return -0x1a;
	}
	if (func_0215F3D0(socket) != 0) {
		OS_RestoreInterrupts(enable);
		return result;
	}
	{
		int flag = result;

		if (socket != 0)
			flag = (socket->state & 1) != 0;
		if (flag == 0) {
			OS_RestoreInterrupts(enable);
			return -0x27;
		}
	}
	if (socket->state & 0x10) {
		OS_RestoreInterrupts(enable);
		return -0x1a;
	}
	OS_RestoreInterrupts(enable);
	socket->state |= 0x18;
	{
		int mode = 1;

		if (socket->flag_mode != 0 && socket->flag_mode != 4)
			mode = 0;
		if (mode == 0) {
			g_021AA4AC.b--;
		} else {
			func_0215CEB0((int)socket->send_pipe, 0);
			g_021AA4AC.a--;
		}
	}
	command = func_0215CE3C(func_0215E980, socket, 1);
	command->field8 = result;
	func_0215CEFC((int)socket, (int)command);
	return result;
}


static inline int IsStream(Socket *socket)
{
	int r = 1;
	if (socket->flag_mode != 0 && socket->flag_mode != 4) {
		r = 0;
	}
	return r;
}


/*
 * sdk:      SOCLi_CloseCallBack (libsoc.TWL.HYB.a(socl_close.o))
 */
int func_0215E980(void *arg)
{
	unsigned long enable;
	Socket *socket;

	socket = ((Cmd *)arg)->socket;
	if (IsStream(socket)) {
		OS_JoinThread(socket->send_pipe + 0x20);
		CPS_TcpShutdown();
		CPS_TcpClose();
		CPS_SocRelease();
	}
	CPS_SocUnRegister();
	socket->state &= ~6;
	func_0215CEB0((int)(socket->flag_mode == 2 ? socket->send_pipe : (unsigned char *)socket->recv_pipe), 0);
	enable = OS_DisableInterrupts();
	func_0215F31C((int)socket);
	func_0215F304((int)socket);
	OS_RestoreInterrupts(enable);
	socket->state |= 0x20;
	return 0;
}


/*
 * sdk:      SOCLi_CleanupSocket (libsoc.TWL.HYB.a(socl_close.o))
 */
void func_0215EA1C(Socket *socket)
{
	UdpData *udpdata_next;
	UdpData *udpdata;
	unsigned long enable;

	if (socket == 0) {
		return;
	}
	socket->state = 0;
	if (IsStream(socket)) {
		func_0215EB14(socket->send_pipe);
		func_0215EB14((unsigned char *)socket->recv_pipe);
	} else if (socket->flag_mode == 1) {
		udpdata = socket->recv_pipe->udpdata.head;
		while (udpdata) {
			udpdata_next = udpdata->next;
			g_021A1CD8->free(udpdata);
			udpdata = udpdata_next;
		}
		socket->recv_pipe->udpdata.size = 0;
		socket->recv_pipe->udpdata.a = 0;
		socket->recv_pipe->udpdata.head = 0;
		OS_WakeupThread(socket->recv_pipe->udpdata.queue);
		func_0215EB14((unsigned char *)socket->recv_pipe);
	} else if (socket->flag_mode == 2) {
		func_0215EB14(socket->send_pipe);
	}
	enable = OS_DisableInterrupts();
	func_0215F31C((int)socket);
	func_0215F3B8((int)socket);
	g_021A1CD8->free(socket);
	OS_RestoreInterrupts(enable);
}


/*
 * sdk:      SOCLi_FreeCommandPipe (libsoc.TWL.HYB.a(socl_close.o))
 */
void func_0215EB14(unsigned char *pipe)
{
	unsigned long enable;
	Command *command;

	if (pipe == 0) {
		return;
	}
	OS_JoinThread(pipe + 0x20);
	enable = OS_DisableInterrupts();
	OS_DisableScheduler();
	while (func_02085E50(pipe, (void **)&command, 0)) {
		if (command != 0) {
			if (command->reply != 0) {
				func_02085DBC(command->reply, (void *)-11, 0);
			}
			func_0215CE7C(command);
		}
	}
	OS_EnableScheduler();
	OS_RescheduleThread();
	OS_RestoreInterrupts(enable);
}


/*
 * sdk:      SOCLi_TrashSocket (libsoc.TWL.HYB.a(socl_close.o))
 */
void func_0215EBB4(void)
{
	unsigned long enable;

	enable = OS_DisableInterrupts();
	while (g_021AA4B8 != 0)
		func_0215EA1C(g_021AA4B8);
	OS_RestoreInterrupts(enable);
}
