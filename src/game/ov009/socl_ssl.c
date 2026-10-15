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
 *   func_0215F3D0  0x0215F3D0  arm  ov009
 *   func_0215CE3C  0x0215CE3C  arm  ov009
 *   SOCLi_ExecCommandPacketInRecvPipe  0x0215CF88  arm  ov009
 *   OS_LockMutex  0x02086028  arm
 *   CPS_SetSsl  0x02162E94  arm  ov009
 *   func_02086078  0x02086078  arm
 */
typedef struct {
	char pad0[0xac];
	short state;
	signed char flag_block;
	signed char flag_mode;
} Sock_0215FC80;

typedef struct {
	char pad0[0xc];
	void *ssl;
} Cps;

typedef struct {
	char pad0[0xc4];
	Cps *cpsoc;
	char pad1[0x18];
	char mutex[1];
} Pipe;

typedef struct {
	char pad0[0xa0];
	Pipe *recv_pipe;
	char pad1[0xb];
	signed char flag_mode;
} Sock_0215FD40;

typedef struct {
	int pad0;
	Sock_0215FD40 *socket;
	char pad1[8];
	void *con;
} Cmd;

extern int func_0215F3D0(Sock_0215FC80 *socket);
extern void *func_0215CE3C(int (*handler)(void *), void *socket, long flag);
extern int SOCLi_ExecCommandPacketInRecvPipe(void *socket, void *command);
extern void OS_LockMutex(void *mutex);
extern void CPS_SetSsl(int mode);
extern void func_02086078(void *mutex);
int SOCL_EnableSsl(int s, void *con);
int SOCLi_ExecEnableSslCommand(void *socket, void *con);
int SOCLi_EnableSslCallBack(void *arg);


static inline int isReady(Sock_0215FC80 *s)
{
	return s->flag_mode == 0 || s->flag_mode == 4;
}


static inline int isOpen(Sock_0215FC80 *s)
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
	Sock_0215FC80 *socket = (Sock_0215FC80 *)s;

	if (func_0215F3D0(socket)) {
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

	command = func_0215CE3C(SOCLi_EnableSslCallBack, socket, 1);
	if (command == 0) {
		return -33;
	}
	command[4] = (int)con;
	return SOCLi_ExecCommandPacketInRecvPipe(socket, command);
}


/*
 * sdk:      SOCLi_EnableSslCallBack (libsoc.TWL.HYB.a(socl_ssl.o))
 */
int SOCLi_EnableSslCallBack(void *arg)
{
	Cmd *cpacket = (Cmd *)arg;
	Sock_0215FD40 *socket = cpacket->socket;
	Pipe *recv_pipe = socket->recv_pipe;
	Cps *cpsoc = recv_pipe->cpsoc;

	OS_LockMutex(recv_pipe->mutex);
	if (cpacket->con != 0) {
		cpsoc->ssl = cpacket->con;
		CPS_SetSsl(1);
		socket->flag_mode = 4;
	} else {
		socket->flag_mode = 0;
		CPS_SetSsl(0);
		cpsoc->ssl = 0;
	}
	func_02086078(recv_pipe->mutex);
	return 0;
}
