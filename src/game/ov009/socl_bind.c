/*
 * file:     socl_bind.c
 * unit:     yes
 * function: SOCL_Bind, SOCL_Connect, SOCLi_ExecBindCommand, SOCLi_BindCallBack
 * address:  0x0215D43C
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
 *   SOCL_SocketIsInvalid     0x0215f3d0 arm
 *   SOCL_SocketIsInvalid  0x0215F3D0  arm  ov009
 *   SOCLi_ExecBindCommand  0x0215D5F8  arm  ov009
 *   gCpsMyIp     0x021A82BC  data
 *   gCpsNetMask     0x021A827C  data
 *   gSoclBindConst     0x021A1CE0  data
 *   SOCLi_CreateCommandPacket           0x0215ce3c arm
 *   SOCLi_ExecCommandPacketInRecvPipe   0x0215cf88 arm
 *   SOCLi_BindCallBack                  0x0215d650 arm
 *   OS_LockMutex  0x02086028  arm
 *   OS_UnlockMutex  0x02086078  arm
 *   CPS_SocBind  0x0215AAB0  arm  ov009
 *   CPS_TcpConnect  0x0215AC60  arm  ov009
 */
#include "socl_types.h"
#include "socl_command.h"

/* the original reads and writes the state word as volatile */
#define SOCKET_STATE(s) (*(volatile short *)&(s)->state)

struct SOCLiCommandBind {
    int (*handler)(void *);
    struct SOCLSocket *socket;
    long response_queue;
    signed char pipeIndex;
    signed char blockFlag;
    unsigned char padE[2];
    unsigned short local_port;
    unsigned short remote_port;
    unsigned long remote_ip;
};

typedef struct {
	unsigned char pad0[0xe0];
	unsigned char mutex[0x18];
	unsigned long result;
} RecvPipe;

typedef struct {
	unsigned char pad0[0xa0];
	RecvPipe *recv_pipe;
	unsigned char pad1[8];
	volatile short flags;
} Socket;

typedef struct {
	unsigned long pad0;
	Socket *socket;
	unsigned long pad1;
	signed char type;
	unsigned char pad2[3];
	unsigned short local_port;
	unsigned short remote_port;
	unsigned long remote_ip;
} CmdBind;

#include "socl_list.h"
static int SOCLi_ExecBindCommand(struct SOCLSocket *socket);
extern struct SOCLiCommandPacket *SOCLi_CreateCommandPacket(int (*handler)(void *),
                                                            struct SOCLSocket *socket,
                                                            long flag);
extern int SOCLi_BindCallBack(void *arg);
#include "../sdk_os.h"

#include "../arm9/os_mutex.h"
#include "cps_network.h"
int SOCL_Bind(int s, unsigned short local_port);
int SOCL_Connect(int s, unsigned short remote_port, unsigned long remote_ip);
int SOCLi_BindCallBack(void *arg);
extern unsigned long gCpsMyIp;
extern unsigned long gCpsNetMask;
extern int gSoclBindConst;


int SOCL_Bind(sptr s, unsigned short local_port)
{
    struct SOCLSocket *socket = (struct SOCLSocket *)s;

    if (SOCL_SocketIsInvalid(socket))
        return -0x1c;
    {
        int flag = 0;

        if (socket != 0)
            flag = (SOCKET_STATE(socket) & 1) != 0;
        if (flag == 0)
            return -0x27;
    }
    if (SOCKET_STATE(socket) & 2)
        return -7;
    socket->local_port = local_port;
    if (socket->flag_mode != 1)
        return 0;
    return SOCLi_ExecBindCommand(socket);
}


/*
 * sdk:      SOCL_Connect (libsoc.TWL.HYB.a(socl_bind.o))
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
int SOCL_Connect(int s, unsigned short remote_port, unsigned long remote_ip)
{
	struct SOCLSocket *socket = (struct SOCLSocket *)s;

	if (SOCL_SocketIsInvalid(socket) != 0 || (SOCKET_STATE(socket) & 8))
		return -0x1c;
	{
		int flag = 0;

		if (socket != 0)
			flag = (SOCKET_STATE(socket) & 1) != 0;
		if (flag == 0)
			return -0x27;
	}
	{
		int mode = 1;

		if (socket->flag_mode != 0 && socket->flag_mode != 4)
			mode = 0;
		if (mode != 0) {
		int bcast;

		if ((remote_ip & 0xf0000000) == 0xe0000000)
			goto invalid;
		if ((gCpsNetMask & (gCpsMyIp ^ remote_ip)) != 0)
			bcast = remote_ip == 0xffffffff;
		else
			bcast = (~gCpsNetMask & remote_ip) == ~gCpsNetMask;
		if (bcast) {
invalid:
			return -0x1c;
		}
		if (SOCKET_STATE(socket) & 4) {
			if (socket->flag_block == 1)
				return -0x1e;
			return 0;
		}
		if (SOCKET_STATE(socket) & 2) {
			if (SOCKET_STATE(socket) & 0x40)
				return socket->result;
			return gSoclBindConst;
		}
		socket->remote_port = remote_port;
		socket->remote_ip = remote_ip;
		{
			int r = SOCLi_ExecBindCommand(socket);

			if (socket->flag_block == 1)
				return r;
			if (r >= 0)
				return -0x1a;
			return r;
		}
		}
	}
	socket->remote_port = remote_port;
	socket->remote_ip = remote_ip;
	return 0;
}


static int SOCLi_ExecBindCommand(struct SOCLSocket *socket)
{
    struct SOCLiCommandBind *command
        = (struct SOCLiCommandBind *)SOCLi_CreateCommandPacket(SOCLi_BindCallBack, socket, socket->flag_block);

    if (command == 0)
        return -0x21;
    command->local_port = socket->local_port;
    command->remote_port = socket->remote_port;
    command->remote_ip = socket->remote_ip;
    SOCKET_STATE(socket) |= 2;
    return SOCLi_ExecCommandPacketInRecvPipe(socket, (struct SOCLiCommandPacket *)command);
}


/*
 * sdk:      SOCLi_BindCallBack (libsoc.TWL.HYB.a(socl_bind.o))
 *
 * note:     the socket state word is spelled volatile: the only spelling found that
 *           keeps the per-arm ldrsh/strh (the vendor DWARF carries no volatile).
 */
int SOCLi_BindCallBack(void *arg)
{
	CmdBind *cpacket;
	Socket *socket;
	RecvPipe *recv_pipe;
	unsigned long retcode;

	cpacket = (CmdBind *)arg;
	socket = cpacket->socket;
	retcode = 0;
	recv_pipe = socket->recv_pipe;
	OS_LockMutex((struct OSMutex *)recv_pipe->mutex);
	CPS_SocBind(cpacket->local_port, cpacket->remote_port, cpacket->remote_ip);
	recv_pipe->result = retcode;
	if (cpacket->type == 0 || cpacket->type == 4) {
		retcode = CPS_TcpConnect();
	}
	OS_UnlockMutex((struct OSMutex *)recv_pipe->mutex);
	if (retcode != 0) {
		socket->flags |= 0x40;
		return -76;
	}
	socket->flags |= 4;
	return 0;
}
