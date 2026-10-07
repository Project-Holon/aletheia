/*
 * file:     unit_0215E024_p01.c
 * unit:     yes
 * function: func_0215E23C, func_0215E2C0
 * address:  0x0215E23C
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
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_020857B0  0x020857B0  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

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

int func_0215E23C(void *a, int n, int m, int *out, int f5);
long func_0215E2C0(Sock *socket);


/*
 * Pull a count out of the object at +0xa4, clamped to `n` (and, when it came
 * back short, to `m`) -- below `m` the loop instead either gives up with 0 or
 * pumps func_020857B0 on the +0x104 channel, depending on the low bit of the
 * fifth argument.  The success path copies the u16 at +0x100 out.  The whole
 * scan runs inside a func_02087988/func_0208799C interrupt bracket.
 */
int func_0215E23C(void *a, int n, int m, int *out, int f5)
{
    u32 *base;
    int st;
    int v;
    int flag;

    base = *(u32 **)((u8 *)a + 0xa4);
    if (m > n)
        m = n;
    st = func_02087988();
    flag = f5 & 1;
    for (;;) {
        v = func_0215E2C0(a);
        if (v >= m) {
            if (v >= n)
                v = n;
            *out = *(u16 *)((u8 *)base + 0x100);
            break;
        }
        if (flag == 0) {
            v = 0;
            break;
        }
        func_020857B0((u8 *)base + 0x104);
    }
    func_0208799C(st);
    return v;
}


/*
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
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_0215E2C0.c \
 *       --func func_0215E2C0 --addr 0x0215E2C0 --region ov009 --arm --cc 1.1p1 \
 *       --lang c99 --diff
 */
long func_0215E2C0(Sock *socket)
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
