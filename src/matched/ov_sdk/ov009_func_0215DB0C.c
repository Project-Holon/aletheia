/*
 * function: func_0215DB0C
 * address:  0x0215DB0C
 * packet:   pkt_ov009_0215DB0C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_ReadCallBack (socl_read.o)
 *
 * symbols:
 *   CPS_SocRead  0x0215AEB0  arm  ov009
 *   OS_Sleep  0x02085A38  arm
 *   func_02082EA4  0x02082EA4  arm
 *   CPS_SocConsume  0x0215B064  arm  ov009
 *   func_0215D92C  0x0215D92C  arm  ov009
 *   SOCLi_ConsumeCPSBuffer  0x0215DD88  arm  ov009
 */

struct SOCLiSocketRecvCommandPipe {
    unsigned char pad0[0xf8];
    long consumed;
    unsigned short consumed_min;
};

struct SOCLSocket {
    unsigned char pad0[8];
    unsigned char cps_state;
    unsigned char pad9[0xa0 - 9];
    struct SOCLiSocketRecvCommandPipe *recv_pipe;
    unsigned char pada4[0xac - 0xa4];
    short state;
    signed char flag_block;
    signed char flag_mode;
};

struct SOCLiCommandRead {
    int (*handler)(void *);
    struct SOCLSocket *socket;
    long field8;
    signed char fieldC;
    signed char fieldD;
    unsigned char padE[2];
    unsigned char *buffer;
    long buffer_len;
    unsigned short *remote_port;
    unsigned long *remote_ip;
};

extern unsigned char *CPS_SocRead(unsigned long *len);
extern void OS_Sleep(unsigned long msec);
extern void func_02082EA4(void *srcp, void *destp, unsigned long size);
extern void CPS_SocConsume(unsigned long len);
extern int func_0215D92C(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
                         unsigned long *remote_ip);
extern int SOCLi_ConsumeCPSBuffer(struct SOCLSocket *socket);

static inline int isStream(signed char m)
{
    int r = 1;
    if (m != 0 && m != 4)
        r = 0;
    return r;
}

static int func_0215DB0C(void *arg)
{
    struct SOCLSocket *socket;
    int result;
    unsigned char *cpsbuffer;
    unsigned char *buffer;
    unsigned short *remote_port;
    unsigned long cpsbuffer_len;
    unsigned long *remote_ip;
    struct SOCLiSocketRecvCommandPipe *recv_pipe;
    long consumed;
    long buffer_len;
    struct SOCLiCommandRead *cpacket = arg;

    socket = cpacket->socket;
    recv_pipe = socket->recv_pipe;
    buffer = cpacket->buffer;
    buffer_len = cpacket->buffer_len;
    remote_port = cpacket->remote_port;
    remote_ip = cpacket->remote_ip;
    consumed = recv_pipe->consumed;
    for (;;) {
        cpsbuffer = CPS_SocRead(&cpsbuffer_len);
        if (cpsbuffer == 0)
            break;
        if ((long)cpsbuffer_len - consumed > 0)
            break;
        if (isStream(socket->flag_mode) && socket->cps_state != 4) {
            cpsbuffer = 0;
            break;
        }
        OS_Sleep(10);
    }
    if (socket->state & 0x80)
        return -0xf;
    if (socket->flag_mode == 4) {
        if (cpsbuffer == 0)
            return 0;
        if (buffer_len > cpsbuffer_len)
            buffer_len = cpsbuffer_len;
        func_02082EA4(cpsbuffer, buffer, buffer_len);
        CPS_SocConsume(buffer_len);
        return buffer_len;
    }
    if (cpsbuffer != 0)
        result = func_0215D92C(socket, buffer, buffer_len, remote_port, remote_ip);
    else
        result = 0;
    if (result <= 0)
        return result;
    if (recv_pipe->consumed >= recv_pipe->consumed_min)
        SOCLi_ConsumeCPSBuffer(socket);
    return result;
}
