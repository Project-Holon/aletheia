/*
 * function: func_0215D92C
 * address:  0x0215D92C
 * packet:   pkt_ov009_0215D92C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      SOCLi_CopyCPSBuffer (libsoc.TWL.HYB.a(socl_read.o))
 *
 * lane21 (2026-10-01): closed.  The Debug build of the same object
 * (sdk/TwlDWC/lib/ARM9-TS/Debug/libsoc.TWL.HYB.a socl_read.o) still carries
 * the locals the Rom DWARF dropped: copy_len and consume_len (both long), and
 * its -O0 code shows `result = consume_len;` as a separate statement after the
 * flag guard, `int result = 0;`, MATH_MIN polarity and an if/else for the
 * 0/-0x1c select.  That body reproduces the Debug object at -O0 -inline off
 * (modulo assert line constants).  At -O4,p the guard arm is kept as a branch
 * only when `consumed` is also `volatile long` (volatile is invisible in this
 * DWARF); either change alone stays 260/264.  Earlier "front-end wall" notes
 * (lanes U41, W8, A, 07; docs/notes/func_0215D92C.c.txt) are superseded.
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_0215DA34  0x0215DA34  arm  ov009
 *   func_02082EA4  0x02082EA4  arm
 *   func_0208799C  0x0208799C  arm
 */

struct SOCLRecvPipe {
	unsigned char pad[0xf8];
	volatile long consumed;
	unsigned char padfc[2];
	signed char flag_noconsume;
};

struct SOCLSocket {
	unsigned char pad[0xa0];
	struct SOCLRecvPipe *recv_pipe;
	unsigned char pada4[8];
	short state;
	signed char flag_block;
	signed char flag_mode;
	unsigned short local_port;
};

extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);
extern unsigned char *func_0215DA34(struct SOCLSocket *socket, long *buffer_len, unsigned short *local_port,
				    unsigned short *remote_port, unsigned long *remote_ip);
extern void func_02082EA4(void *srcp, void *destp, unsigned long size);

static inline int SOCL_SocketIsTCP(struct SOCLSocket *socket)
{
	return socket->flag_mode == 0 || socket->flag_mode == 4;
}

static int func_0215D92C(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
			 unsigned long *remote_ip)
{
	unsigned long enable;
	struct SOCLRecvPipe *recv_pipe;
	unsigned char *cpsbuffer;
	long cpsbuffer_len;
	long copy_len;
	long consume_len;
	unsigned short my_port;
	unsigned short his_port;
	unsigned long his_ip;
	int result = 0;

	enable = func_02087988();
	cpsbuffer = func_0215DA34(socket, &cpsbuffer_len, &my_port, &his_port, &his_ip);
	if (cpsbuffer != 0) {
		if (cpsbuffer_len == 0) {
			result = -6;
		} else {
			copy_len = (buffer_len <= cpsbuffer_len) ? buffer_len : cpsbuffer_len;
			consume_len = SOCL_SocketIsTCP(socket) ? copy_len : cpsbuffer_len;
			func_02082EA4(cpsbuffer, buffer, copy_len);
			recv_pipe = socket->recv_pipe;
			if (!recv_pipe->flag_noconsume)
				recv_pipe->consumed += consume_len;
			result = consume_len;
		}
	} else {
		if (cpsbuffer_len == 0)
			result = 0;
		else
			result = -0x1c;
		socket->state &= ~6;
	}
	if (result >= 0) {
		if (remote_port != 0 && remote_ip != 0) {
			*remote_port = his_port;
			*remote_ip = his_ip;
		}
		if (socket->local_port == 0)
			socket->local_port = my_port;
	}
	func_0208799C(enable);
	return result;
}
