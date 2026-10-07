/*
 * file:     unit_0215E794_p01.c
 * unit:     yes
 * function: func_0215E794, func_0215E7C8, func_0215E84C
 * address:  0x0215E794
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
 *   func_0215F3D0  0x0215F3D0  arm  ov009
 *   func_0215F404  0x0215F404  arm  ov009
 *   OS_DisableInterrupts   0x02087988 arm
 *   SOCL_SocketIsInTrash   0x0215f404 arm
 *   OS_RestoreInterrupts   0x0208799c arm
 *   SOCL_SocketIsInvalid   0x0215f3d0 arm
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_0215CEB0  0x0215CEB0  arm  ov009
 *   func_0215CE3C  0x0215CE3C  arm  ov009
 *   func_0215CEFC  0x0215CEFC  arm  ov009
 *   g_021AA4AC     0x021AA4AC  data
 *   func_0215E980  0x0215E980  arm  ov009
 */
#include "../../matched/include/G_SOCLResource.h"

struct SOCLSocket_0215E7C8 {
    char pad[0xac];
    signed short flags;
};

struct SOCLCommand {
	unsigned char pad[8];
	int field8;
};

struct SOCLSocket_0215E84C {
	unsigned char pad[0xa4];
	void *send_pipe;
	int result;
	short state;
	signed char flag_block;
	signed char flag_mode;
};

extern int func_0215F3D0(void *s);
extern int func_0215F404(int b);
extern unsigned long OS_DisableInterrupts(void);
extern int SOCL_SocketIsInTrash(struct SOCLSocket_0215E7C8 * socket);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern int SOCL_SocketIsInvalid(struct SOCLSocket_0215E7C8 * socket);
extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);
extern int func_0215CEB0(int a0, char *a1);
extern struct SOCLCommand *func_0215CE3C(int (*handler)(void *), struct SOCLSocket_0215E84C *socket, long flag);
extern void func_0215CEFC(int a, int b);
extern int func_0215E980(void *arg);
int func_0215E794(int s);
int SOCL_IsReleased(int s);
int func_0215E84C(int s);
extern struct SOCLResource g_021AA4AC;


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
    struct SOCLSocket_0215E7C8 * socket;

    if (s <= 0)
        return 0;
    enable = OS_DisableInterrupts();
    socket = (struct SOCLSocket_0215E7C8 *)s;
    if (SOCL_SocketIsInTrash(socket)) {
        OS_RestoreInterrupts(enable);
        return 0;
    }
    if (SOCL_SocketIsInvalid(socket)) {
        OS_RestoreInterrupts(enable);
        return 1;
    }
    if (socket->flags & 0x10) {
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
	struct SOCLSocket_0215E84C *socket = (struct SOCLSocket_0215E84C *)s;
	struct SOCLCommand *command;
	int result = 0;
	unsigned long enable;

	if (s <= 0)
		return -0x1c;
	enable = func_02087988();
	if (func_0215F404((int)socket) != 0) {
		func_0208799C(enable);
		return -0x1a;
	}
	if (func_0215F3D0(socket) != 0) {
		func_0208799C(enable);
		return result;
	}
	{
		int flag = result;

		if (socket != 0)
			flag = (socket->state & 1) != 0;
		if (flag == 0) {
			func_0208799C(enable);
			return -0x27;
		}
	}
	if (socket->state & 0x10) {
		func_0208799C(enable);
		return -0x1a;
	}
	func_0208799C(enable);
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
