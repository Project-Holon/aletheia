/*
 * function: func_0215E024
 * address:  0x0215E024
 * packet:   pkt_ov009_0215E024
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_WriteTo (socl_write.o)
 *
 * symbols:
 *   func_0215F3D0  0x0215F3D0  arm  ov009
 *   func_020860D0  0x020860D0  arm
 *   func_02086028  0x02086028  arm
 *   func_0215E138  0x0215E138  arm  ov009
 *   func_02086078  0x02086078  arm
 *
 * The second state test is a volatile load: the image reloads socket->state between the two bit tests.
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
    unsigned char pad0[0xe0];
    unsigned char mutex[0x18];
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

extern int func_0215F3D0(struct SOCLSocket *socket);
extern int func_020860D0(void *mutex);
extern void func_02086028(void *mutex);
extern int func_0215E138(struct SOCLSocket *socket, unsigned char *buffer, long buffer_len,
                         unsigned short remote_port, unsigned long remote_ip, long flag_block);
extern void func_02086078(void *mutex);

static inline int isNotReady(struct SOCLSocket *socket)
{
    int r = 0;
    if (socket != 0)
        r = (socket->state & 1) ? 1 : 0;
    return r;
}
#define isNotReady(x) (isNotReady(x))

static inline int isStream(signed char m)
{
    int r = 1;
    if (m != 0 && m != 4)
        r = 0;
    return r;
}

int func_0215E024(int s, void *buffer, int buffer_len, unsigned short remote_port, unsigned long remote_ip,
                  int flags)
{
    int result;
    int flag_block;
    struct SOCLiSocketSendCommandPipe *send_pipe;
    struct SOCLSocket *socket = (struct SOCLSocket *)s;

    if (func_0215F3D0(socket))
        return -0x1c;
    if (!isNotReady(socket))
        return -0x27;
    if (isStream(socket->flag_mode)) {
        if (!(socket->state & 4) || (*(volatile short *)&socket->state & 8))
            return -0x38;
    }
    send_pipe = socket->send_pipe;
    if ((flags & 4) || socket->flag_block == 0) {
        if (!func_020860D0(send_pipe->mutex))
            return -6;
        flag_block = 0;
    } else {
        func_02086028(send_pipe->mutex);
        flag_block = 1;
    }
    result = func_0215E138(socket, buffer, buffer_len, remote_port, remote_ip, flag_block);
    func_02086078(send_pipe->mutex);
    return result;
}
