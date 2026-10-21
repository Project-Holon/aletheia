/*
 * file:     socl_ssl.c
 * unit:     yes
 * function: SOCL_EnableSsl, SOCLi_ExecEnableSslCommand, SOCLi_EnableSslCallBack
 * address:  0x0215FC80
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
 *   SOCL_SocketIsInvalid  0x0215F3D0  arm  ov009
 *   SOCLi_CreateCommandPacket  0x0215CE3C  arm  ov009
 *   SOCLi_ExecCommandPacketInRecvPipe  0x0215CF88  arm  ov009
 *   OS_LockMutex  0x02086028  arm
 *   CPS_SetSsl  0x02162E94  arm  ov009
 *   OS_UnlockMutex  0x02086078  arm
 */
#include "socl_types.h"
#include "socl_command.h"
#include "cps_network.h"
#include "ssl.h"
#include "../arm9/os_mutex.h"

typedef struct {
	int pad0;
	struct SOCLSocket *socket;
	char pad1[8];
	void *con;
} Cmd;

#include "socl_list.h"
struct SOCLiCommandPacket;
extern struct SOCLiCommandPacket *SOCLi_CreateCommandPacket(int (*handler)(void *), struct SOCLSocket *socket, long flag);
int SOCLi_ExecEnableSslCommand(void *socket, void *con);
int SOCLi_EnableSslCallBack(void *arg);


static inline int isReady(struct SOCLSocket *s)
{
	return s->flag_mode == 0 || s->flag_mode == 4;
}


static inline int isOpen(struct SOCLSocket *s)
{
	int r = 0;
	if (s) r = (s->state & 1) ? 1 : 0;
	return r;
}


/*
 * sdk:      SOCL_EnableSsl (libsoc.TWL.HYB.a(socl_ssl.o))
 */
int SOCL_EnableSsl(int s, void *con)
{
	struct SOCLSocket *socket = (struct SOCLSocket *)s;

	if (SOCL_SocketIsInvalid(socket)) {
		return -28;
	}
	if (!isReady(socket)) {
		return -28;
	}
	if (!isOpen(socket)) {
		return -39;
	}
	if (socket->state & 2) {
		return -28;
	}
	return SOCLi_ExecEnableSslCommand(socket, con);
}


/*
 * sdk:      SOCLi_ExecEnableSslCommand (libsoc.TWL.HYB.a(socl_ssl.o))
 */
int SOCLi_ExecEnableSslCommand(void *socket, void *con)
{
	int *command;

	command = (int *)SOCLi_CreateCommandPacket(SOCLi_EnableSslCallBack, socket, 1);
	if (command == 0) {
		return -33;
	}
	command[4] = (sptr)con;
	return (int)SOCLi_ExecCommandPacketInRecvPipe((struct SOCLSocket *)socket, (struct SOCLiCommandPacket *)command);
}


/*
 * sdk:      SOCLi_EnableSslCallBack (libsoc.TWL.HYB.a(socl_ssl.o))
 */
int SOCLi_EnableSslCallBack(void *arg)
{
	Cmd *cpacket = (Cmd *)arg;
	struct SOCLSocket *socket = cpacket->socket;
	SOCLiSocketRecvCommandPipe *recv_pipe = socket->recv_pipe;
	CPSSoc *cpsoc = recv_pipe->cpsoc;

	OS_LockMutex((struct OSMutex *)recv_pipe->mutex);
	if (cpacket->con != 0) {
		cpsoc->con = (struct CPSSslConnection *)cpacket->con;
		CPS_SetSsl(1);
		socket->flag_mode = 4;
	} else {
		socket->flag_mode = 0;
		CPS_SetSsl(0);
		cpsoc->con = 0;
	}
	OS_UnlockMutex((struct OSMutex *)recv_pipe->mutex);
	return 0;
}
