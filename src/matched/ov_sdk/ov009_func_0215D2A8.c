/*
 * function: SOCLi_InitSocket
 * address:  0x0215D2A8
 * packet:   pkt_ov009_0215D2A8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Two things close the 99 B of register-allocation diff this file carried
 * while it sat at MATCH with all eight relocations already resolved.
 *
 * `const` on the second parameter is the whole of the first 98. The object
 * issues `ldrh r1,[r6,#2]` (param->send) as the *second* instruction of the
 * function, above both `strb` stores into `socket->f_af`/`f_ae`, and sinks
 * `add r5,r7,#0xbc` below them. Without the qualifier mwcc treats the two
 * pointers as possibly aliasing, keeps the load where the source order puts
 * it, and then colours the whole function one register down: r5 = param,
 * r6 = socket, r4 = ptr, r7 = rpipe, against the object's r6 = param,
 * r7 = socket, r5 = ptr, r4 = pipe. The qualifier is what lets the load
 * hoist, and the hoist is what fixes the colouring -- same shape as
 * docs/idioms/a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md.
 * The callee's third parameter has to be spelled `const void *` for the same
 * reason: `param->pipe1` and `param->pipe2` are four-byte arrays, and passing
 * them to a `void *` is the error that first shows the qualifier is real.
 *
 * The last byte is a struct offset, not code: `spipe->f10a` is at +0x10a, so
 * the run between the u16 at +0xfc and it is 0xc bytes, not 0xa. The 0xf8
 * command pipe behind that header is the one
 * src/matched/ov_sdk/SOCLi_InitCommandPipe.c already pins (queue +0x00,
 * thread +0x20, mutex +0xe0), which is why +0x10c and +0x110 land on the two
 * word stores that follow.
 *
 * sdk:      SOCLi_InitSocket (libsoc.TWL.HYB.a(socl_create.o))
 *
 * symbols:
 *   SOCLi_InitCommandPipe  0x0215D3C8  arm  ov009
 *   SOCLi_InitSocketBuffer  0x0215D3A0  arm  ov009
 *   SOCLiUDPSendSocket  0x021AA44C  data
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
	char pad1[0xc];
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

extern unsigned char *SOCLi_InitCommandPipe(unsigned char *ptr, void *pipe, const void *param);
extern unsigned char *SOCLi_InitSocketBuffer(unsigned char *ptr, Buf *buf, unsigned long size);
extern Sock *SOCLiUDPSendSocket;

unsigned char *SOCLi_InitSocket(Sock *socket, const Param *param)
{
	unsigned char *ptr = (unsigned char *)socket + 0xbc;

	socket->f_af = param->a;
	socket->f_ae = param->b;
	if (param->send) {
		SendPipe *spipe;

		spipe = (SendPipe *)ptr;
		socket->pipe_send = ptr;
		spipe->f0fc = param->f4;
		ptr = SOCLi_InitCommandPipe(ptr + 0x114, spipe, param->pipe1);
		ptr = SOCLi_InitSocketBuffer(ptr, &socket->b48, param->send);
		ptr = SOCLi_InitSocketBuffer(ptr, &socket->b5c, param->sendbuf);
		spipe->f10a = param->f0e;
		spipe->f110 = 0;
		spipe->f10c = 0;
	}
	if (param->recv == 0) {
		socket->pipe_recv = SOCLiUDPSendSocket->pipe_recv;
	} else {
		RecvPipe *rpipe;

		socket->pipe_recv = ptr;
		rpipe = (RecvPipe *)ptr;
		rpipe->f10c = socket;
		ptr = SOCLi_InitCommandPipe(ptr + 0x110, rpipe, param->pipe2);
		ptr = SOCLi_InitSocketBuffer(ptr, &socket->b54, param->recv);
		ptr = SOCLi_InitSocketBuffer(ptr, &socket->b64, param->rbuf1);
		ptr = SOCLi_InitSocketBuffer(ptr, &rpipe->f0f8, param->rbuf2);
		rpipe->f108 = 0;
		rpipe->f104 = 0;
	}
	return ptr;
}
