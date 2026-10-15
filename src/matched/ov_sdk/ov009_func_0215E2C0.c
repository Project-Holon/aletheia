/*
 * function: SOCLi_GetWriteBufferFreeSize
 * address:  0x0215E2C0
 * packet:   pkt_ov009_0215E2C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Free space in a socket's send ring buffer: (out - in - 1), plus the buffer
 * size when that goes negative.
 *
 * The pipe's two cursors are `vu16` in the vendor header
 * (sdk/TwlDWC/include/nitroWiFi/socl.h, SOCLiSocketRingBuffer), not plain
 * u16: with volatile loads the two ldrh keep source order (in at +0x100, out
 * at +0x102) and the size word at +0xf8 (a non-volatile CPSSocBuf.size) is
 * free to float below them.  Without the qualifier the front end folds the
 * pair into the subtraction the other way round and only nine bytes of the
 * 36 come out.
 *
 * sdk:      SOCLi_GetWriteBufferFreeSize (libsoc.TWL.HYB.a(socl_write.o))
 *
 * symbols:
 *   (none)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_0215E2C0.c \
 *       --func SOCLi_GetWriteBufferFreeSize --addr 0x0215E2C0 --region ov009 --arm --cc 1.1p1 \
 *       --lang c99 --diff
 */

typedef struct {
	unsigned long size;
	unsigned char *data;
} CPSSocBuf;

typedef struct {
	CPSSocBuf area;
	volatile unsigned short in;
	volatile unsigned short out;
	char waiting[8];
} RingBuffer;

typedef struct {
	char h[0xf8];
	RingBuffer buffer;
	void *exe_socket;
} SendPipe;

typedef struct {
	char pad0[0xa4];
	SendPipe *send_pipe;
} Sock;

long SOCLi_GetWriteBufferFreeSize(Sock *socket)
{
	SendPipe *send_pipe = socket->send_pipe;
	long wrtbuf_size = send_pipe->buffer.area.size;
	long wrtbuf_in = send_pipe->buffer.in;
	long wrtbuf_out = send_pipe->buffer.out;
	long available_len = wrtbuf_out - wrtbuf_in - 1;

	if (available_len < 0) {
		available_len += wrtbuf_size;
	}
	return available_len;
}
