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
 *   func_0215CE3C  0x0215CE3C  arm  ov009
 *   SOCLi_ExecCommandPacketInRecvPipe  0x0215CF88  arm  ov009
 *   OS_LockMutex  0x02086028  arm
 *   CPS_SetSsl  0x02162E94  arm  ov009
 *   OS_UnlockMutex  0x02086078  arm
 */
struct SOCLSocket {
	unsigned char pad0[0xa0];
	struct SOCLRecvPipe *recvPipe;	/* 0xa0 */
	unsigned char pad1[0x8];
	short state;			/* 0xac */
	signed char flagBlock;		/* 0xae */
	signed char flagMode;		/* 0xaf */
};

typedef struct {
	char pad0[0xc];
	void *ssl;
} Cps;

typedef struct SOCLRecvPipe {
	char pad0[0xc4];
	Cps *cpsoc;
	char pad1[0x18];
	char mutex[1];
} SOCLRecvPipe;

typedef struct {
	int pad0;
	struct SOCLSocket *socket;
	char pad1[8];
	void *con;
} Cmd;

extern int SOCL_SocketIsInvalid(struct SOCLSocket *socket);
extern void *func_0215CE3C(int (*handler)(void *), void *socket, long flag);
extern int SOCLi_ExecCommandPacketInRecvPipe(void *socket, void *command);
extern void OS_LockMutex(void *mutex);
extern void CPS_SetSsl(int mode);
extern void OS_UnlockMutex(void *mutex);
int SOCL_EnableSsl(int s, void *con);
int SOCLi_ExecEnableSslCommand(void *socket, void *con);
int SOCLi_EnableSslCallBack(void *arg);


static inline int isReady(struct SOCLSocket *s)
{
	return s->flagMode == 0 || s->flagMode == 4;
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
	struct SOCLSocket *socket = cpacket->socket;
	SOCLRecvPipe *recv_pipe = socket->recvPipe;
	Cps *cpsoc = recv_pipe->cpsoc;

	OS_LockMutex(recv_pipe->mutex);
	if (cpacket->con != 0) {
		cpsoc->ssl = cpacket->con;
		CPS_SetSsl(1);
		socket->flagMode = 4;
	} else {
		socket->flagMode = 0;
		CPS_SetSsl(0);
		cpsoc->ssl = 0;
	}
	OS_UnlockMutex(recv_pipe->mutex);
	return 0;
}
