/*
 * function: func_0215DDC4
 * address:  0x0215DDC4
 * packet:   pkt_ov009_0215DDC4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_ReadUdpBuffer (socl_read.o)
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_020857B0  0x020857B0  arm
 *   func_0215F3D0  0x0215F3D0  arm  ov009
 *   func_02082EA4  0x02082EA4  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021A1CD8  0x021A1CD8  data
 */

struct SOCLiSocketUdpData {
    struct SOCLiSocketUdpData *next;
    unsigned short size;
    unsigned short remote_port;
    unsigned long remote_ip;
};

struct SOCLiSocketRecvCommandPipe {
    unsigned char pad0[0xf8];
    long consumed;
    unsigned short consumed_min;
    signed char flag_noconsume;
    unsigned char padding[1];
    struct SOCLiSocketUdpData *tail;
    struct SOCLiSocketUdpData *head;
    unsigned short recv_size;
    unsigned char pad10a[2];
    struct { void *head; void *tail; } waiting;
};

struct SOCLSocket {
    unsigned char pad0[0xa0];
    struct SOCLiSocketRecvCommandPipe *recv_pipe;
    unsigned char pada4[0xac - 0xa4];
    short state;
    signed char flag_block;
    signed char flag_mode;
};

struct SOCLiConfig {
    unsigned char pad0[0x1c];
    void (*free)(void *);
};

extern unsigned long func_02087988(void);
extern void func_020857B0(void *queue);
extern int func_0215F3D0(struct SOCLSocket *socket);
extern void func_02082EA4(void *srcp, void *destp, unsigned long size);
extern unsigned long func_0208799C(unsigned long state);
extern struct SOCLiConfig *g_021A1CD8;

static inline int isNotReady(struct SOCLSocket *socket)
{
    int r = 0;
    if (socket != 0)
        r = (socket->state & 1) ? 1 : 0;
    return r;
}

static int func_0215DDC4(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
                         unsigned long *remote_ip, long flag_block)
{
    unsigned long enable;
    struct SOCLiSocketRecvCommandPipe *pipe;
    struct SOCLiSocketUdpData *udpdata;
    int result;

    pipe = socket->recv_pipe;
    enable = func_02087988();
    udpdata = pipe->head;
    if (udpdata == 0) {
        for (;;) {
            if (!(flag_block & 1)) {
                result = -6;
                break;
            }
            func_020857B0(&pipe->waiting);
            if (func_0215F3D0(socket) || !isNotReady(socket)) {
                result = -0x38;
                break;
            }
            udpdata = pipe->head;
            if (udpdata != 0)
                break;
        }
    }
    if (udpdata != 0) {
        if (buffer_len > udpdata->size)
            buffer_len = udpdata->size;
        func_02082EA4(udpdata + 1, buffer, buffer_len);
        if (remote_port)
            *remote_port = udpdata->remote_port;
        if (remote_ip)
            *remote_ip = udpdata->remote_ip;
        result = udpdata->size;
        if (!pipe->flag_noconsume) {
            pipe->head = udpdata->next;
            if (udpdata->next == 0)
                pipe->tail = 0;
            g_021A1CD8->free(udpdata);
            pipe->recv_size -= (unsigned short)result;
        }
    }
    func_0208799C(enable);
    return result;
}
