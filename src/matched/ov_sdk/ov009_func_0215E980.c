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
 *   func_02085710  0x02085710  arm
 *   func_0215AD00  0x0215AD00  arm  ov009
 *   func_0215AD3C  0x0215AD3C  arm  ov009
 *   func_0215AB5C  0x0215AB5C  arm  ov009
 *   func_0215AA70  0x0215AA70  arm  ov009
 *   func_0215CEB0  0x0215CEB0  arm  ov009
 *   func_02087988  0x02087988  arm
 *   func_0215F31C  0x0215F31C  arm  ov009
 *   func_0215F304  0x0215F304  arm  ov009
 *   func_0208799C  0x0208799C  arm
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

extern void func_02085710(void *thread);
extern void func_0215AD00(void);
extern void func_0215AD3C(void);
extern void func_0215AB5C(void);
extern void func_0215AA70(void);
extern int func_0215CEB0(void *pipe, void *command);
extern unsigned long func_02087988(void);
extern void func_0215F31C(Socket *socket);
extern void func_0215F304(Socket *socket);
extern unsigned long func_0208799C(unsigned long state);

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
		func_02085710(socket->send_pipe + 0x20);
		func_0215AD00();
		func_0215AD3C();
		func_0215AB5C();
	}
	func_0215AA70();
	socket->state &= ~6;
	func_0215CEB0(socket->flag_mode == 2 ? socket->send_pipe : socket->recv_pipe, 0);
	enable = func_02087988();
	func_0215F31C(socket);
	func_0215F304(socket);
	func_0208799C(enable);
	socket->state |= 0x20;
	return 0;
}
