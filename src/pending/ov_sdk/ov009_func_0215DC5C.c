/*
 * function: func_0215DC5C
 * address:  0x0215DC5C
 * packet:   pkt_ov009_0215DC5C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH (near miss: 13 B, load schedule only in the first six instructions: image ldr r1,[r4,#0xa0]; ldr r6; ldr r7; ldrsh, ours ldr r2; ldrsh; ldr r6; ldr r7)
 *
 * sdk:      SOCLi_ReadSSLNblockCallBack (libsoc.TWL.HYB.a(socl_read.o))
 *
 * symbols:
 *   func_0215B504   0x0215B504  arm  ov009
 *   func_0215AEB0   0x0215AEB0  arm  ov009
 *   MI_CpuCopy      0x02082EA4  arm
 *   CPS_SocConsume  0x0215B064  arm  ov009
 */

typedef struct {
    unsigned char pad0[0xF8];
    long consumed;
} RecvPipe;

typedef struct {
    unsigned char pad0[8];
    unsigned char state;
    unsigned char pad9[0x97];
    RecvPipe *recv_pipe;
    unsigned char padA4[8];
    short flags;
    unsigned char padAE;
    signed char mode;
} Socket;

typedef struct {
    unsigned long pad0;
    Socket *socket;
    unsigned char pad8[8];
    unsigned char *buffer;
    long buffer_len;
} Cpacket;

extern long func_0215B504(void);
extern unsigned char *func_0215AEB0(unsigned long *len);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern void CPS_SocConsume(unsigned long len);

static inline int IsTcp(int mode)
{
    int r = 1;

    if (mode != 0 && mode != 4)
        r = 0;
    return r;
}

long func_0215DC5C(void *arg)
{
    Cpacket *cpacket;
    Socket *socket;
    unsigned char *buffer;
    long buffer_len;
    unsigned char *cpsbuffer;
    unsigned long cpsbuffer_len;
    long consumed;
    int datalen;

    cpacket = (Cpacket *)arg;
    socket = cpacket->socket;
    buffer = cpacket->buffer;
    buffer_len = cpacket->buffer_len;
    consumed = socket->recv_pipe->consumed;
    if (socket->flags & 0x80)
        return -15;
    datalen = func_0215B504();
    if (datalen == 0)
        return -6;
    if (datalen == -1)
        return 0;
    cpsbuffer = func_0215AEB0(&cpsbuffer_len);
    if (cpsbuffer != 0 && (long)cpsbuffer_len - consumed <= 0) {
        if (IsTcp(socket->mode) && socket->state != 4)
            cpsbuffer = 0;
    }
    if (socket->flags & 0x80)
        return -15;
    if (cpsbuffer == 0)
        return 0;
    if (buffer_len > cpsbuffer_len)
        buffer_len = cpsbuffer_len;
    MI_CpuCopy(cpsbuffer, buffer, buffer_len);
    CPS_SocConsume(buffer_len);
    return buffer_len;
}
