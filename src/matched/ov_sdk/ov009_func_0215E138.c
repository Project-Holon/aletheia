/*
 * function: SOCLi_WriteBuffer
 * address:  0x0215E138
 * packet:   pkt_ov009_0215E138
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_WriteBuffer (socl_write.o)
 *
 * symbols:
 *   SOCLi_AllocWriteBuffer  0x0215E23C  arm  ov009
 *   func_0215E2E4  0x0215E2E4  arm  ov009
 */

struct SOCLiCommandWrite;

struct SOCLiSocketRingBuffer {
    long size;
    unsigned char *area;
    unsigned short in;
    unsigned short out;
    struct { void *head; void *tail; } waiting;
};

struct SOCLiSocketSendCommandPipe {
    unsigned char pad0[0xf8];
    struct SOCLiSocketRingBuffer buffer;
    struct SOCLSocket *exe_socket;
};

struct SOCLSocket {
    unsigned char pad0[0x54];
    long field54;
    unsigned char *field58;
    unsigned char pad5c[0xa4 - 0x5c];
    struct SOCLiSocketSendCommandPipe *send_pipe;
    long result;
    short state;
    signed char flag_block;
    signed char flag_mode;
    unsigned short local_port;
    unsigned short remote_port;
    unsigned long remote_ip;
};

struct SOCLiCommandWrite {
    int (*handler)(void *);
    struct SOCLSocket *socket;
    long field8;
    signed char fieldC;
    signed char fieldD;
    unsigned char padE[2];
    unsigned char *buffer1;
    long buffer1_len;
    unsigned char *buffer2;
    long buffer2_len;
    unsigned short wrtbuf_after;
    unsigned char padding[2];
    unsigned short local_port;
    unsigned short remote_port;
    unsigned long remote_ip;
};

extern int SOCLi_AllocWriteBuffer(void *a, int n, int m, int *out, int f5);
extern int func_0215E2E4(struct SOCLSocket *socket, unsigned char *buffer, long buffer_len, long wrtbuf_in,
                         unsigned short remote_port, unsigned long remote_ip, long flag_block);

static int SOCLi_WriteBuffer(struct SOCLSocket *socket, unsigned char *buffer, long buffer_len,
                         unsigned short remote_port, unsigned long remote_ip, long flag_block)
{
    int result;
    long buffer_min;
    long write_len;
    long copied_len;
    long wrtbuf_in;
    long sndbuf_len;

    sndbuf_len = socket->send_pipe->exe_socket->field54;
    copied_len = 0;
    if (socket->flag_mode == 1) {
        sndbuf_len -= 0x2a;
        if (buffer_len > sndbuf_len)
            return -0x23;
        buffer_min = buffer_len;
    } else {
        sndbuf_len -= 0x36;
        buffer_min = sndbuf_len;
        if (buffer_len <= buffer_min)
            buffer_min = buffer_len;
    }
    while (buffer_len > 0) {
        write_len = SOCLi_AllocWriteBuffer(socket, buffer_len, buffer_min, (int *)(&wrtbuf_in), flag_block);
        if (write_len > 0) {
            result = func_0215E2E4(socket, buffer, write_len, wrtbuf_in, remote_port, remote_ip, flag_block);
            if (result <= 0)
                return -6;
            buffer += write_len;
            buffer_len -= write_len;
            copied_len += write_len;
        }
        if (!(flag_block & 1)) {
            if (write_len <= 0)
                return -6;
            break;
        }
    }
    return copied_len;
}
