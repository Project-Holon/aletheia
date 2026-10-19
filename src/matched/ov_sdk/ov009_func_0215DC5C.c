/*
 * function: SOCLi_ReadSSLNblockCallBack
 * address:  0x0215DC5C
 * packet:   pkt_ov009_0215DC5C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_ReadSSLNblockCallBack (libsoc.TWL.HYB.a(socl_read.o))
 *
 * The state (vs16) and consumed (vs32) fields are volatile; they must be
 * declared volatile or the scheduler hoists the state load into the first
 * block (image keeps it last, right before the tst).
 *
 * symbols:
 *   CPS_SocGetLength  0x0215B504  arm  ov009
 *   CPS_SocRead  0x0215AEB0  arm  ov009
 *   MI_CpuCopy     0x02082EA4  arm
 *   CPS_SocConsume 0x0215B064  arm  ov009
 */

struct SOCLiSocketRecvCommandPipe {
    unsigned char pad0[0xf8];
    volatile long consumed;
};

struct SOCLSocket {
    unsigned char pad0[8];
    unsigned char cps_state;
    unsigned char pad9[0xa0 - 9];
    struct SOCLiSocketRecvCommandPipe *recv_pipe;
    unsigned char pada4[0xac - 0xa4];
    volatile short state;
    unsigned char padAE;
    signed char flag_mode;
};

struct SOCLiCommandRead {
    unsigned long pad0;
    struct SOCLSocket *socket;
    unsigned char pad8[8];
    unsigned char *buffer;
    long buffer_len;
};

extern long CPS_SocGetLength(void);
extern unsigned char *CPS_SocRead(unsigned long *len);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern void CPS_SocConsume(unsigned long len);

static inline int isTcp(signed char m)
{
    int r = 1;

    if (m != 0 && m != 4)
        r = 0;
    return r;
}

static int SOCLi_ReadSSLNblockCallBack(void *arg)
{
    struct SOCLiCommandRead *cpacket;
    struct SOCLSocket *socket;
    struct SOCLiSocketRecvCommandPipe *recv_pipe;
    unsigned char *buffer;
    long buffer_len;
    unsigned char *cpsbuffer;
    unsigned long cpsbuffer_len;
    long consumed;
    int datalen;

    cpacket = (struct SOCLiCommandRead *)arg;
    socket = cpacket->socket;
    buffer = cpacket->buffer;
    recv_pipe = socket->recv_pipe;
    buffer_len = cpacket->buffer_len;
    consumed = recv_pipe->consumed;
    if (socket->state & 0x80)
        return -15;
    datalen = CPS_SocGetLength();
    if (datalen == 0)
        return -6;
    if (datalen == -1)
        return 0;
    cpsbuffer = CPS_SocRead(&cpsbuffer_len);
    if (cpsbuffer != 0 && (long)cpsbuffer_len - consumed <= 0) {
        if (isTcp(socket->flag_mode) && socket->cps_state != 4)
            cpsbuffer = 0;
    }
    if (socket->state & 0x80)
        return -15;
    if (cpsbuffer == 0)
        return 0;
    if (buffer_len > cpsbuffer_len)
        buffer_len = cpsbuffer_len;
    MI_CpuCopy(cpsbuffer, buffer, buffer_len);
    CPS_SocConsume(buffer_len);
    return buffer_len;
}