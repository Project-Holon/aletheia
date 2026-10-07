/*
 * function: func_0215E450
 * address:  0x0215E450
 * packet:   pkt_ov009_0215E450
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_WriteCallBack (socl_write.o)
 *
 * symbols:
 *   func_0215AAB0  0x0215AAB0  arm  ov009
 *   func_0215E588  0x0215E588  arm  ov009
 *   func_0215E620  0x0215E620  arm  ov009
 *   func_0215B470  0x0215B470  arm  ov009
 *   func_0215AD3C  0x0215AD3C  arm  ov009
 *   func_02085800  0x02085800  arm
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

extern void func_0215AAB0(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
extern int func_0215E588(int len);
typedef unsigned char  u8;
struct Ring;
extern int func_0215E620(u8 *dst, int len, struct Ring *r);
extern unsigned long func_0215B470(unsigned char *buf, unsigned long len);
extern void func_0215AD3C(void);
extern void func_02085800(void *queue);

static inline int isStream(signed char m)
{
    int r = 1;
    if (m != 0 && m != 4)
        r = 0;
    return r;
}

static int func_0215E450(void *arg)
{
    unsigned char *sndbuf;
    struct SOCLSocket *socket;
    int hdr;
    int sndbuf_len;
    int result;
    struct SOCLiSocketSendCommandPipe *send_pipe;
    int copied;
    struct SOCLiCommandWrite *cpacket = arg;

    socket = cpacket->socket;
    send_pipe = socket->send_pipe;
    copied = 0;

    if (socket->flag_mode == 2 && (socket->state & 8))
        return -0x1c;
    if ((socket->flag_mode == 0 || socket->flag_mode == 4) && !(socket->state & 4))
        goto fail;
    if (cpacket->remote_ip)
        func_0215AAB0(cpacket->local_port, cpacket->remote_port, cpacket->remote_ip);
    hdr = 0x36;
    if (!isStream(socket->flag_mode))
        hdr = 0x2a;
    sndbuf = socket->field58;
    if (socket->flag_mode == 0 || socket->flag_mode == 4)
        sndbuf_len = func_0215E588(socket->field54 - hdr);
    else
        sndbuf_len = socket->field54 - hdr;
    for (;;) {
        int n = func_0215E620(sndbuf + hdr, sndbuf_len, (struct Ring *)cpacket);
        if (n <= 0)
            goto done;
        result = func_0215B470(sndbuf + hdr, n);
        if (result <= 0) {
            if (isStream(socket->flag_mode)) {
                socket->state &= ~0xe;
                socket->state |= 0x80;
                func_0215AD3C();
            }
            copied = -0x4c;
            goto done;
        } else {
            copied += result;
        }
    }
fail:
    copied = -0x4c;
done:
    send_pipe->buffer.out = cpacket->wrtbuf_after;
    func_02085800(&send_pipe->buffer.waiting);
    return copied;
}
