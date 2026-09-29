/*
 * function: func_0215D124
 * address:  0x0215D124
 * packet:   pkt_ov009_0215D124
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_CreateSocketCallBack (libsoc.TWL.HYB.a(socl_create.o))
 *
 * symbols:
 *   func_0215AA5C  0x0215AA5C  arm  ov009
 *   func_0215AB7C  0x0215AB7C  arm  ov009
 *   func_0215AB10  0x0215AB10  arm  ov009
 *   func_0215AA88  0x0215AA88  arm  ov009
 *   func_0215AB94  0x0215AB94  arm  ov009
 *   func_0215DF08  0x0215DF08  arm  ov009
 */

typedef struct {
	unsigned char pad0[0xa4];
	unsigned char *send_pipe;
	unsigned char pad1[4];
	short state;
	signed char flag_block;
	signed char flag_mode;
} Socket;

typedef struct {
	unsigned long pad0;
	Socket *socket;
} Cmd;

extern void func_0215AA5C(void *soc);
extern void func_0215AB7C(void *thread);
extern void func_0215AB10(void);
extern void func_0215AA88(void);
extern void func_0215AB94(int (*callback)(unsigned char *, unsigned long, void *));
extern int func_0215DF08(unsigned char *, unsigned long, void *);

int func_0215D124(void *arg)
{
	Socket *socket;
	unsigned char *send_pipe;

	socket = ((Cmd *)arg)->socket;
	func_0215AA5C(socket);
	send_pipe = socket->send_pipe;
	switch (socket->flag_mode) {
	case 0:
	case 4:
		func_0215AB7C(send_pipe + 0x20);
		func_0215AB10();
		break;
	case 1:
		func_0215AB10();
		func_0215AA88();
		func_0215AB94(func_0215DF08);
		break;
	case 2:
		func_0215AA88();
		break;
	}
	socket->state = 1;
	return 0;
}
