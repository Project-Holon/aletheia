/*
 * file:     socl_close.c
 * unit:     yes
 * function: SOCL_IsClosed, func_0215E7C8, SOCL_Close, SOCLi_CloseCallBack, SOCLi_CleanupSocket, SOCLi_FreeCommandPipe, SOCLi_TrashSocket
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
 *   SOCL_SocketIsInTrash  0x0215F404  arm  ov009
 *   OS_DisableInterrupts   0x02087988 arm
 *   SOCL_SocketIsInTrash   0x0215f404 arm
 *   OS_RestoreInterrupts   0x0208799c arm
 *   SOCL_SocketIsInvalid   0x0215f3d0 arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   SOCLi_SendCommandPacket  0x0215CEB0  arm  ov009
 *   func_0215CE3C  0x0215CE3C  arm  ov009
 *   SOCLi_SendCommandPacketToCtrlPipe  0x0215CEFC  arm  ov009
 *   SOCLi_Resource     0x021AA4AC  data
 *   OS_JoinThread  0x02085710  arm
 *   CPS_TcpShutdown  0x0215AD00  arm  ov009
 *   CPS_TcpClose  0x0215AD3C  arm  ov009
 *   CPS_SocRelease  0x0215AB5C  arm  ov009
 *   CPS_SocUnRegister  0x0215AA70  arm  ov009
 *   SOCLi_SocketUnregister  0x0215F31C  arm  ov009
 *   SOCLi_SocketRegisterTrash  0x0215F304  arm  ov009
 *   SOCLi_FreeCommandPipe  0x0215EB14  arm  ov009
 *   OS_WakeupThread  0x02085800  arm
 *   SOCLi_SocketUnregisterTrash  0x0215F3B8  arm  ov009
 *   gSoclConfig     0x021A1CD8  data
 *   OS_DisableScheduler  0x02085B30  arm
 *   func_02085E50  0x02085E50  arm
 *   func_02085DBC  0x02085DBC  arm
 *   SOCLi_FreeCommandPacket  0x0215CE7C  arm  ov009
 *   OS_EnableScheduler  0x02085B60  arm
 *   OS_RescheduleThread  0x020858BC  arm
 *   SOCLi_CleanupSocket  0x0215EA1C  arm  ov009
 *   SOCLiTrashList  0x021AA4B8  data
 */

#include "ov009_globals.h"
#include "socl_command_types.h"

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
extern int SOCL_SocketIsInTrash(int b);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern int SOCL_SocketIsInvalid(Socket * socket);
extern int SOCLi_SendCommandPacket(int a0, char *a1);
extern struct SOCLCommand *func_0215CE3C(int (*handler)(void *), Socket *socket, long flag);
extern void SOCLi_SendCommandPacketToCtrlPipe(int a, int b);
extern void OS_JoinThread(void *thread);
extern void CPS_TcpShutdown(void);
extern void CPS_TcpClose(void);
extern void CPS_SocRelease(void);
extern void CPS_SocUnRegister(void);
extern void SOCLi_SocketUnregister(int a);
extern void SOCLi_SocketRegisterTrash(int a);
/* * sdk: SOCL_IsClosed (libsoc.TWL.HYB.a(socl_close.o)) */ int SOCL_IsClosed(int s);
int SOCL_IsReleased(int s);
/* * sdk: SOCL_Close (libsoc.TWL.HYB.a(socl_close.o)) */ int SOCL_Close(int s);
int SOCLi_CloseCallBack(void *arg);
extern SoclResource SOCLi_Resource;
extern SoclConfig *gSoclConfig;
extern Socket *SOCLiTrashList;
typedef struct {
	unsigned long pad0[2];
	void *reply;
} Command;
extern void SOCLi_FreeCommandPipe(unsigned char *pipe);
extern void OS_WakeupThread(void *queue);
extern void SOCLi_SocketUnregisterTrash(int a);
extern unsigned long OS_DisableScheduler(void);
extern int func_02085E50(void *mq, void **msg, long flags);
extern int func_02085DBC(void *mq, void *msg, long flags);
extern void SOCLi_FreeCommandPacket(void *ptr);
extern unsigned long OS_EnableScheduler(void);
extern void OS_RescheduleThread(void);
void SOCLi_CleanupSocket(Socket *socket);
void SOCLi_TrashSocket(void);



/*
 * sdk:      SOCL_IsClosed (libsoc.TWL.HYB.a(socl_close.o))
 */
int SOCL_IsClosed(int s)
{
	void *socket;

	if (s >= 0) {
		socket = (void *)s;
		if (func_0215F3D0(socket) != 0 && SOCL_SocketIsInTrash((int)socket) == 0)
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
    if (SOCL_SocketIsInTrash((int)socket)) {
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
int SOCL_Close(int s)
{
	Socket *socket = (Socket *)s;
	struct SOCLCommand *command;
	int result = 0;
	unsigned long enable;

	if (s <= 0)
		return -0x1c;
	enable = OS_DisableInterrupts();
	if (SOCL_SocketIsInTrash((int)socket) != 0) {
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
			SOCLi_Resource.datagramCount--;
		} else {
			SOCLi_SendCommandPacket((int)socket->send_pipe, 0);
			SOCLi_Resource.streamCount--;
		}
	}
	command = func_0215CE3C(SOCLi_CloseCallBack, socket, 1);
	command->field8 = result;
	SOCLi_SendCommandPacketToCtrlPipe((int)socket, (int)command);
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
int SOCLi_CloseCallBack(void *arg)
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
	SOCLi_SendCommandPacket((int)(socket->flag_mode == 2 ? socket->send_pipe : (unsigned char *)socket->recv_pipe), 0);
	enable = OS_DisableInterrupts();
	SOCLi_SocketUnregister((int)socket);
	SOCLi_SocketRegisterTrash((int)socket);
	OS_RestoreInterrupts(enable);
	socket->state |= 0x20;
	return 0;
}


/*
 * sdk:      SOCLi_CleanupSocket (libsoc.TWL.HYB.a(socl_close.o))
 */
void SOCLi_CleanupSocket(Socket *socket)
{
	UdpData *udpdata_next;
	UdpData *udpdata;
	unsigned long enable;

	if (socket == 0) {
		return;
	}
	socket->state = 0;
	if (IsStream(socket)) {
		SOCLi_FreeCommandPipe(socket->send_pipe);
		SOCLi_FreeCommandPipe((unsigned char *)socket->recv_pipe);
	} else if (socket->flag_mode == 1) {
		udpdata = socket->recv_pipe->udpdata.head;
		while (udpdata) {
			udpdata_next = udpdata->next;
			gSoclConfig->free(udpdata);
			udpdata = udpdata_next;
		}
		socket->recv_pipe->udpdata.size = 0;
		socket->recv_pipe->udpdata.a = 0;
		socket->recv_pipe->udpdata.head = 0;
		OS_WakeupThread(socket->recv_pipe->udpdata.queue);
		SOCLi_FreeCommandPipe((unsigned char *)socket->recv_pipe);
	} else if (socket->flag_mode == 2) {
		SOCLi_FreeCommandPipe(socket->send_pipe);
	}
	enable = OS_DisableInterrupts();
	SOCLi_SocketUnregister((int)socket);
	SOCLi_SocketUnregisterTrash((int)socket);
	gSoclConfig->free(socket);
	OS_RestoreInterrupts(enable);
}


/*
 * sdk:      SOCLi_FreeCommandPipe (libsoc.TWL.HYB.a(socl_close.o))
 */
void SOCLi_FreeCommandPipe(unsigned char *pipe)
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
			SOCLi_FreeCommandPacket(command);
		}
	}
	OS_EnableScheduler();
	OS_RescheduleThread();
	OS_RestoreInterrupts(enable);
}


/*
 * sdk:      SOCLi_TrashSocket (libsoc.TWL.HYB.a(socl_close.o))
 */
void SOCLi_TrashSocket(void)
{
	unsigned long enable;

	enable = OS_DisableInterrupts();
	while (SOCLiTrashList != 0)
		SOCLi_CleanupSocket(SOCLiTrashList);
	OS_RestoreInterrupts(enable);
}
