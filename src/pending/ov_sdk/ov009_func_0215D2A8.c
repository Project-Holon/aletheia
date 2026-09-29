/*
 * function: func_0215D2A8
 * address:  0x0215D2A8
 * packet:   pkt_ov009_0215D2A8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      SOCLi_InitSocket (libsoc.TWL.HYB.a(socl_create.o))
 *
 * symbols:
 *   func_0215D3C8  0x0215D3C8  arm  ov009
 *   func_0215D3A0  0x0215D3A0  arm  ov009
 *   g_021AA44C  0x021AA44C  data
 */

typedef struct {
	unsigned long size;
	unsigned char *data;
} Buf;

typedef struct {
	signed char a;
	signed char b;
	unsigned short send;
	unsigned short f4;
	unsigned short recv;
	unsigned short sendbuf;
	unsigned short rbuf1;
	unsigned short rbuf2;
	unsigned short f0e;
	unsigned char pipe1[4];
	unsigned char pipe2[4];
} Param;

typedef struct {
	char pad0[0xfc];
	unsigned short f0fc;
	char pad1[0xa];
	unsigned short f10a;
	int f10c;
	int f110;
} SendPipe;

typedef struct {
	char pad0[0xf8];
	Buf f0f8;
	char pad1[0x4];
	int f104;
	int f108;
	void *f10c;
} RecvPipe;

typedef struct Sock {
	char pad0[0x48];
	Buf b48;
	char pad3[4];
	Buf b54;
	Buf b5c;
	Buf b64;
	char pad1[0x34];
	void *pipe_send;
	void *pipe_recv;
	char pad2[0x6];
	signed char f_ae;
	signed char f_af;
} Sock;

extern unsigned char *func_0215D3C8(unsigned char *ptr, void *pipe, void *param);
extern unsigned char *func_0215D3A0(unsigned char *ptr, Buf *buf, unsigned long size);
extern Sock *g_021AA44C;

unsigned char *func_0215D2A8(Sock *socket, Param *param)
{
	unsigned char *ptr = (unsigned char *)socket + 0xbc;

	socket->f_af = param->a;
	socket->f_ae = param->b;
	if (param->send) {
		SendPipe *spipe;

		spipe = (SendPipe *)ptr;
		socket->pipe_send = ptr;
		spipe->f0fc = param->f4;
		ptr = func_0215D3C8(ptr + 0x114, spipe, param->pipe1);
		ptr = func_0215D3A0(ptr, &socket->b48, param->send);
		ptr = func_0215D3A0(ptr, &socket->b5c, param->sendbuf);
		spipe->f10a = param->f0e;
		spipe->f110 = 0;
		spipe->f10c = 0;
	}
	if (param->recv == 0) {
		socket->pipe_recv = g_021AA44C->pipe_recv;
	} else {
		RecvPipe *rpipe;

		socket->pipe_recv = ptr;
		rpipe = (RecvPipe *)ptr;
		rpipe->f10c = socket;
		ptr = func_0215D3C8(ptr + 0x110, rpipe, param->pipe2);
		ptr = func_0215D3A0(ptr, &socket->b54, param->recv);
		ptr = func_0215D3A0(ptr, &socket->b64, param->rbuf1);
		ptr = func_0215D3A0(ptr, &rpipe->f0f8, param->rbuf2);
		rpipe->f108 = 0;
		rpipe->f104 = 0;
	}
	return ptr;
}
