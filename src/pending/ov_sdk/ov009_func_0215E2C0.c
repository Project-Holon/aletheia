/*
 * function: func_0215E2C0
 * address:  0x0215E2C0
 * packet:   pkt_ov009_0215E2C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * w9_nm: DIFF 4 B (only the two ldrh destinations and the sub operand order: the object loads +0 into r1 and +2 into r0). 14 spellings, none moved it: locals in either order, direct expression, split subtract, u16 locals, const pointers, out-first declarations, if-return form.
 *
 * sdk:      SOCLi_GetWriteBufferFreeSize (libsoc.TWL.HYB.a(socl_write.o))
 *
 * symbols:
 *   (none)
 */

typedef struct {
	char pad0[0xf8];
	long wrtbufSize;
	char pad1[4];
	unsigned short wrtbufIn;
	unsigned short wrtbufOut;
} Pipe;

typedef struct {
	char pad0[0xa4];
	Pipe *send_pipe;
} Sock;

long func_0215E2C0(Sock *socket)
{
	Pipe *send_pipe = socket->send_pipe;
	long wrtbuf_size = send_pipe->wrtbufSize;
	long wrtbuf_in = send_pipe->wrtbufIn;
	long wrtbuf_out = send_pipe->wrtbufOut;
	long available_len = wrtbuf_out - wrtbuf_in - 1;

	if (available_len < 0) {
		available_len += wrtbuf_size;
	}
	return available_len;
}
