/*
 * function: func_0215E980
 * address:  0x0215E980
 * packet:   pkt_ov009_0215E980
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_CloseCallBack (libsoc.TWL.HYB.a(socl_close.o))
 *
 * symbols:
 *   OS_JoinThread  0x02085710  arm
 *   CPS_TcpShutdown  0x0215AD00  arm  ov009
 *   CPS_TcpClose  0x0215AD3C  arm  ov009
 *   CPS_SocRelease  0x0215AB5C  arm  ov009
 *   CPS_SocUnRegister  0x0215AA70  arm  ov009
 *   SOCLi_SendCommandPacket  0x0215CEB0  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   func_0215F31C  0x0215F31C  arm  ov009
 *   func_0215F304  0x0215F304  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

typedef struct {
	unsigned long pad0;
	struct Socket *socket;
} Cmd;

typedef struct Socket {
	unsigned char pad0[0xa0];
	unsigned char *recv_pipe;
	unsigned char *send_pipe;
	unsigned char pad1[4];
	short state;
	signed char flag_block;
	signed char flag_mode;
} Socket;

extern void OS_JoinThread(void *thread);
extern void CPS_TcpShutdown(void);
extern void CPS_TcpClose(void);
extern void CPS_SocRelease(void);
extern void CPS_SocUnRegister(void);
extern int SOCLi_SendCommandPacket(int a0, char *a1);
extern unsigned long OS_DisableInterrupts(void);
extern void func_0215F31C(int a);
extern void func_0215F304(int a);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

static inline int IsStream(Socket *socket)
{
	int r = 1;
	if (socket->flag_mode != 0 && socket->flag_mode != 4) {
		r = 0;
	}
	return r;
}

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
	SOCLi_SendCommandPacket((int)(socket->flag_mode == 2 ? socket->send_pipe : socket->recv_pipe), 0);
	enable = OS_DisableInterrupts();
	func_0215F31C((int)socket);
	func_0215F304((int)socket);
	OS_RestoreInterrupts(enable);
	socket->state |= 0x20;
	return 0;
}
