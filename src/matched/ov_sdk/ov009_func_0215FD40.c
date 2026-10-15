/*
 * function: SOCLi_EnableSslCallBack
 * address:  0x0215FD40
 * packet:   pkt_ov009_0215FD40
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_EnableSslCallBack (libsoc.TWL.HYB.a(socl_ssl.o))
 *
 * symbols:
 *   OS_LockMutex  0x02086028  arm
 *   CPS_SetSsl  0x02162E94  arm  ov009
 *   func_02086078  0x02086078  arm
 */

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
} Sock;

typedef struct {
	int pad0;
	Sock *socket;
	char pad1[8];
	void *con;
} Cmd;

extern void OS_LockMutex(void *mutex);
extern void CPS_SetSsl(int mode);
extern void func_02086078(void *mutex);

int SOCLi_EnableSslCallBack(void *arg)
{
	Cmd *cpacket = (Cmd *)arg;
	Sock *socket = cpacket->socket;
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
