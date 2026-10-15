/*
 * function: SOCL_Close
 * address:  0x0215E84C
 * packet:   pkt_ov009_0215E84C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_Close (libsoc.TWL.HYB.a(socl_close.o))
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   SOCL_SocketIsInTrash  0x0215F404  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_0215F3D0  0x0215F3D0  arm  ov009
 *   SOCLi_SendCommandPacket  0x0215CEB0  arm  ov009
 *   func_0215CE3C  0x0215CE3C  arm  ov009
 *   SOCLi_SendCommandPacketToCtrlPipe  0x0215CEFC  arm  ov009
 *   SOCLi_Resource     0x021AA4AC  data
 *   SOCLi_CloseCallBack  0x0215E980  arm  ov009
 */

#include "../include/G_SOCLResource.h"

struct SOCLCommand {
	unsigned char pad[8];
	int field8;
};

struct SOCLSocket {
	unsigned char pad[0xa4];
	void *send_pipe;
	int result;
	short state;
	signed char flag_block;
	signed char flag_mode;
};

extern struct SOCLResource SOCLi_Resource;

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern int SOCL_SocketIsInTrash(int b);
extern int func_0215F3D0(struct SOCLSocket *socket);
extern int SOCLi_SendCommandPacket(int a0, char *a1);
extern struct SOCLCommand *func_0215CE3C(int (*handler)(void *), struct SOCLSocket *socket, long flag);
extern void SOCLi_SendCommandPacketToCtrlPipe(int a, int b);
extern int SOCLi_CloseCallBack(void *arg);

int SOCL_Close(int s)
{
	struct SOCLSocket *socket = (struct SOCLSocket *)s;
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
			SOCLi_Resource.b--;
		} else {
			SOCLi_SendCommandPacket((int)socket->send_pipe, 0);
			SOCLi_Resource.a--;
		}
	}
	command = func_0215CE3C(SOCLi_CloseCallBack, socket, 1);
	command->field8 = result;
	SOCLi_SendCommandPacketToCtrlPipe((int)socket, (int)command);
	return result;
}
