/*
 * file:     unit_0215D6C8_p02.c
 * unit:     yes
 * function: func_0215DB0C, func_0215DC5C, func_0215DD28
 * address:  0x0215DB0C
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
 *   func_0215AEB0  0x0215AEB0  arm  ov009
 *   func_02085A38  0x02085A38  arm
 *   func_02082EA4  0x02082EA4  arm
 *   func_0215B064  0x0215B064  arm  ov009
 *   func_0215D92C  0x0215D92C  arm  ov009
 *   func_0215DD88  0x0215DD88  arm  ov009
 *   func_0215B504  0x0215B504  arm  ov009
 *   MI_CpuCopy     0x02082EA4  arm
 *   CPS_SocConsume 0x0215B064  arm  ov009
 *   SOCLi_CreateCommandPacket          0x0215CE3C  arm  ov009
 *   SOCLi_ExecCommandPacketInRecvPipe  0x0215CF88  arm  ov009
 *   SOCLi_ConsumeCallBack              0x0215DD78  arm  ov009
 */
struct SOCLiSocketRecvCommandPipe_0215DB0C {
    unsigned char pad0[0xf8];
    long consumed;
    unsigned short consumed_min;
};

struct SOCLSocket_0215DB0C {
    unsigned char pad0[8];
    unsigned char cps_state;
    unsigned char pad9[0xa0 - 9];
    struct SOCLiSocketRecvCommandPipe_0215DB0C *recv_pipe;
    unsigned char pada4[0xac - 0xa4];
    short state;
    signed char flag_block;
    signed char flag_mode;
};

struct SOCLiCommandRead_0215DB0C {
    int (*handler)(void *);
    struct SOCLSocket_0215DB0C *socket;
    long field8;
    signed char fieldC;
    signed char fieldD;
    unsigned char padE[2];
    unsigned char *buffer;
    long buffer_len;
    unsigned short *remote_port;
    unsigned long *remote_ip;
};

struct SOCLiSocketRecvCommandPipe_0215DC5C {
    unsigned char pad0[0xf8];
    volatile long consumed;
};

struct SOCLSocket_0215DC5C {
    unsigned char pad0[8];
    unsigned char cps_state;
    unsigned char pad9[0xa0 - 9];
    struct SOCLiSocketRecvCommandPipe_0215DC5C *recv_pipe;
    unsigned char pada4[0xac - 0xa4];
    volatile short state;
    unsigned char padAE;
    signed char flag_mode;
};

struct SOCLiCommandRead_0215DC5C {
    unsigned long pad0;
    struct SOCLSocket_0215DC5C *socket;
    unsigned char pad8[8];
    unsigned char *buffer;
    long buffer_len;
};

typedef struct {
    char pad0[0xF8];
    long consumed;
    unsigned short limit;
} RecvPipe;

typedef struct {
    char pad0[0xA0];
    RecvPipe *recv_pipe;
} Socket;

typedef struct Command Command;

extern unsigned char *func_0215AEB0(unsigned long *len);
extern void func_02085A38(unsigned long msec);
extern void func_02082EA4(void *srcp, void *destp, unsigned long size);
extern void func_0215B064(unsigned long len);
extern int func_0215D92C(struct SOCLSocket_0215DB0C *socket, void *buffer, int buffer_len, unsigned short *remote_port,
                         unsigned long *remote_ip);
extern int func_0215DD88(struct SOCLSocket_0215DB0C *socket);
extern long func_0215B504(void);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern void CPS_SocConsume(unsigned long len);
extern Command *SOCLi_CreateCommandPacket(int (*handler)(void *), Socket *socket, long flag);
extern int SOCLi_ExecCommandPacketInRecvPipe(Socket *socket, Command *command);
extern int SOCLi_ConsumeCallBack(void *arg);
int func_0215DD28(Socket *socket);


static inline int isStream(signed char m)
{
    int r = 1;
    if (m != 0 && m != 4)
        r = 0;
    return r;
}


/*
 * sdk:      SOCLi_ReadCallBack (socl_read.o)
 */
static int func_0215DB0C(void *arg)
{
    struct SOCLSocket_0215DB0C *socket;
    int result;
    unsigned char *cpsbuffer;
    unsigned char *buffer;
    unsigned short *remote_port;
    unsigned long cpsbuffer_len;
    unsigned long *remote_ip;
    struct SOCLiSocketRecvCommandPipe_0215DB0C *recv_pipe;
    long consumed;
    long buffer_len;
    struct SOCLiCommandRead_0215DB0C *cpacket = arg;

    socket = cpacket->socket;
    recv_pipe = socket->recv_pipe;
    buffer = cpacket->buffer;
    buffer_len = cpacket->buffer_len;
    remote_port = cpacket->remote_port;
    remote_ip = cpacket->remote_ip;
    consumed = recv_pipe->consumed;
    for (;;) {
        cpsbuffer = func_0215AEB0(&cpsbuffer_len);
        if (cpsbuffer == 0)
            break;
        if ((long)cpsbuffer_len - consumed > 0)
            break;
        if (isStream(socket->flag_mode) && socket->cps_state != 4) {
            cpsbuffer = 0;
            break;
        }
        func_02085A38(10);
    }
    if (socket->state & 0x80)
        return -0xf;
    if (socket->flag_mode == 4) {
        if (cpsbuffer == 0)
            return 0;
        if (buffer_len > cpsbuffer_len)
            buffer_len = cpsbuffer_len;
        func_02082EA4(cpsbuffer, buffer, buffer_len);
        func_0215B064(buffer_len);
        return buffer_len;
    }
    if (cpsbuffer != 0)
        result = func_0215D92C(socket, buffer, buffer_len, remote_port, remote_ip);
    else
        result = 0;
    if (result <= 0)
        return result;
    if (recv_pipe->consumed >= recv_pipe->consumed_min)
        func_0215DD88(socket);
    return result;
}


static inline int isTcp(signed char m)
{
    int r = 1;

    if (m != 0 && m != 4)
        r = 0;
    return r;
}


/*
 * sdk:      SOCLi_ReadSSLNblockCallBack (libsoc.TWL.HYB.a(socl_read.o))
 *
 * The state (vs16) and consumed (vs32) fields are volatile; they must be
 * declared volatile or the scheduler hoists the state load into the first
 * block (image keeps it last, right before the tst).
 */
static int func_0215DC5C(void *arg)
{
    struct SOCLiCommandRead_0215DC5C *cpacket;
    struct SOCLSocket_0215DC5C *socket;
    struct SOCLiSocketRecvCommandPipe_0215DC5C *recv_pipe;
    unsigned char *buffer;
    long buffer_len;
    unsigned char *cpsbuffer;
    unsigned long cpsbuffer_len;
    long consumed;
    int datalen;

    cpacket = (struct SOCLiCommandRead_0215DC5C *)arg;
    socket = cpacket->socket;
    buffer = cpacket->buffer;
    recv_pipe = socket->recv_pipe;
    buffer_len = cpacket->buffer_len;
    consumed = recv_pipe->consumed;
    if (socket->state & 0x80)
        return -15;
    datalen = func_0215B504();
    if (datalen == 0)
        return -6;
    if (datalen == -1)
        return 0;
    cpsbuffer = func_0215AEB0(&cpsbuffer_len);
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


/*
 * sdk:      SOCLi_ConsumeBuffer (libsoc.TWL.HYB.a(socl_read.o))
 */
int func_0215DD28(Socket *socket)
{
    RecvPipe *recv_pipe;
    Command *command;
    long result;

    recv_pipe = socket->recv_pipe;
    if (recv_pipe->consumed < recv_pipe->limit)
        return 0;
    result = 0;
    command = SOCLi_CreateCommandPacket(SOCLi_ConsumeCallBack, socket, result);
    if (command == 0)
        return result - 0x21;
    return SOCLi_ExecCommandPacketInRecvPipe(socket, command);
}
