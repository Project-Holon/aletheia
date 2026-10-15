/*
 * file:     socl_read.c
 * unit:     yes
 * function: func_0215D6C8, func_0215D7FC, func_0215D898, func_0215D92C, func_0215DA34, func_0215DAA8, func_0215DB0C, func_0215DC5C, func_0215DD28, func_0215DD78, func_0215DD88, func_0215DDC4, func_0215DF08
 * address:  0x0215D6C8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0215F3D0  0x0215F3D0  arm  ov009
 *   func_020879EC  0x020879EC  arm
 *   OS_TryLockMutex  0x020860D0  arm
 *   OS_LockMutex  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   CPS_SocRead  0x0215AEB0  arm  ov009
 *   OS_Sleep  0x02085A38  arm
 *   CPS_SocGetLength  0x0215B504  arm  ov009
 *   MI_CpuCopy     0x02082EA4  arm
 *   CPS_SocConsume 0x0215B064  arm  ov009
 *   SOCLi_CreateCommandPacket          0x0215CE3C  arm  ov009
 *   SOCLi_ExecCommandPacketInRecvPipe  0x0215CF88  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OS_SleepThread  0x020857B0  arm
 *   OS_WakeupThread  0x02085800  arm
 *   g_021A1CD8  0x021A1CD8  data
 *   g_021AA4A4  0x021AA4A4  data
 */
#include "../../matched/include/G_021A1CD8.h"

/* CPS socket: the first 0xa0 bytes of every SOCLSocket */
struct CPSSoc {
    unsigned char pad0[8];
    unsigned char state;
    unsigned char pad9;
    unsigned short local_port;
    unsigned char padc[0x18 - 0xc];
    unsigned short remote_port;
    unsigned short remote_port2;
    unsigned long remote_ip;
    unsigned long remote_ip2;
    unsigned char pad24[0x4c - 0x24];
    unsigned char *buf;
    long total;
    long field54;
    unsigned char *field58;
    unsigned char pad5c[0xa0 - 0x5c];
};

struct SOCLiUdpData {
    struct SOCLiUdpData *next;
    unsigned short size;
    unsigned short remote_port;
    unsigned long remote_ip;
    unsigned char data[1];
};

struct SOCLiSocketRecvCommandPipe {
    unsigned char pad0[0xc4];
    struct CPSSoc *cpsoc;
    unsigned char padc8[0x18];
    unsigned char mutex[0x18];
    volatile long consumed;
    unsigned short consumed_min;
    signed char flag_noconsume;
    unsigned char padff;
    struct SOCLiUdpData *volatile tail;
    struct SOCLiUdpData *head;
    unsigned short recv_size;
    unsigned short recv_max;
    struct { void *head; void *tail; } waiting;
};

struct SOCLSocket {
    struct CPSSoc cps_socket;
    struct SOCLiSocketRecvCommandPipe *recv_pipe;
    void *send_pipe;
    long result;
    short state;
    signed char flag_block;
    signed char flag_mode;
    unsigned short local_port;
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

extern int func_0215F3D0(struct SOCLSocket *socket);
extern int func_020879EC(void);
extern int OS_TryLockMutex(void *mutex);
extern void OS_LockMutex(void *mutex);
extern void func_02086078(void *mutex);
extern unsigned char *CPS_SocRead(unsigned long *len);
extern void OS_Sleep(unsigned long msec);
extern long CPS_SocGetLength(void);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern void CPS_SocConsume(unsigned long len);
extern struct SOCLiCommandRead *SOCLi_CreateCommandPacket(int (*handler)(void *), struct SOCLSocket *socket, long flag);
extern int SOCLi_ExecCommandPacketInRecvPipe(struct SOCLSocket *socket, struct SOCLiCommandRead *command);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void OS_SleepThread(void *queue);
extern void OS_WakeupThread(void *queue);
extern struct G_021A1CD8 *g_021A1CD8;
extern unsigned long g_021AA4A4[2];

int func_0215D6C8(int s, void *buffer, int buffer_len, unsigned short *remote_port, unsigned long *remote_ip,
                  int flags);
int func_0215D7FC(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
                  unsigned long *remote_ip, int flag_block, int flags);
int func_0215D898(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
                  unsigned long *remote_ip, long flag_block);
static int func_0215D92C(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
                         unsigned long *remote_ip);
unsigned char *func_0215DA34(struct SOCLSocket *socket, long *buffer_len, unsigned short *local_port,
                             unsigned short *remote_port, unsigned long *remote_ip);
int func_0215DAA8(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
                  unsigned long *remote_ip, long flag_block);
static int func_0215DB0C(void *arg);
static int func_0215DC5C(void *arg);
int func_0215DD28(struct SOCLSocket *socket);
int func_0215DD78(void *arg);
long func_0215DD88(struct SOCLSocket *socket);
static int func_0215DDC4(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
                         unsigned long *remote_ip, long flag_block);
int func_0215DF08(unsigned char *data, unsigned long len, struct SOCLSocket *socket);

static inline int isNotReady(struct SOCLSocket *socket)
{
    int r = 0;
    if (socket != 0)
        r = (socket->state & 1) ? 1 : 0;
    return r;
}

static inline int isStream(signed char m)
{
    int r = 1;
    if (m != 0 && m != 4)
        r = 0;
    return r;
}

/*
 * sdk:      SOCL_ReadFrom (socl_read.o)
 *
 * The second state test is a volatile load: the image reloads socket->state between the two bit tests.
 */
int func_0215D6C8(int s, void *buffer, int buffer_len, unsigned short *remote_port, unsigned long *remote_ip,
                  int flags)
{
    struct SOCLiSocketRecvCommandPipe *recv_pipe;
    int flag_block;
    int result;
    struct SOCLSocket *socket = (struct SOCLSocket *)s;

    if (func_0215F3D0(socket))
        return -0x1c;
    if ((flags & 4) || socket->flag_block == 0) {
        flag_block = 0;
    } else {
        if (func_020879EC() == 0x12)
            return -0x1c;
        flag_block = 1;
    }
    if (!isNotReady(socket))
        return -0x27;
    if (isStream(socket->flag_mode)) {
        if (!(socket->state & 4) || (*(volatile short *)&socket->state & 8))
            return -0x38;
    }
    recv_pipe = socket->recv_pipe;
    if (!(flag_block & 1)) {
        if (!OS_TryLockMutex(recv_pipe->mutex))
            return -6;
    } else {
        OS_LockMutex(recv_pipe->mutex);
    }
    result = func_0215D7FC(socket, buffer, buffer_len, remote_port, remote_ip, flag_block, flags);
    func_02086078(recv_pipe->mutex);
    return result;
}

/*
 * When the +0xa0 object exists and the caller asked for flag 2, latch its
 * +0xfe byte to 1 and put it back afterwards.  Mode 1 at +0xaf takes the
 * direct path, anything else goes through func_0215D898 and follows up with
 * func_0215DD28 when that did not fail.
 */
int func_0215D7FC(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
                  unsigned long *remote_ip, int flag_block, int flags)
{
    struct SOCLiSocketRecvCommandPipe *recv_pipe = socket->recv_pipe;
    int old;
    int t;
    int r;

    if ((flags & 2) != 0 && recv_pipe != 0)
        t = 1;
    else
        t = 0;

    if (t != 0) {
        old = recv_pipe->flag_noconsume;
        recv_pipe->flag_noconsume = 1;
    }

    if (socket->flag_mode == 1) {
        r = func_0215DDC4(socket, buffer, buffer_len, remote_port, remote_ip, flag_block);
    } else {
        r = func_0215D898(socket, buffer, buffer_len, remote_port, remote_ip, flag_block);
        if (r >= 0)
            func_0215DD28(socket);
    }

    if (t != 0)
        recv_pipe->flag_noconsume = old;

    return r;
}

/*
 * sdk:      SOCLi_ReadBuffer (libsoc.TWL.HYB.a(socl_read.o))
 */
int func_0215D898(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
                  unsigned long *remote_ip, long flag_block)
{
    int result;

    if (socket->flag_mode == 4)
        return func_0215DAA8(socket, buffer, buffer_len, remote_port, remote_ip, flag_block);
    result = func_0215D92C(socket, buffer, buffer_len, remote_port, remote_ip);
    if (result != -6)
        return result;
    if ((flag_block & 1) == 0)
        return result;
    return func_0215DAA8(socket, buffer, buffer_len, remote_port, remote_ip, 1);
}

static inline int SOCL_SocketIsTCP(struct SOCLSocket *socket)
{
    return socket->flag_mode == 0 || socket->flag_mode == 4;
}

/*
 * sdk:      SOCLi_CopyCPSBuffer (libsoc.TWL.HYB.a(socl_read.o))
 *
 * lane21 (2026-10-01): closed.  The Debug build of the same object
 * (sdk/TwlDWC/lib/ARM9-TS/Debug/libsoc.TWL.HYB.a socl_read.o) still carries
 * the locals the Rom DWARF dropped: copy_len and consume_len (both long), and
 * its -O0 code shows `result = consume_len;` as a separate statement after the
 * flag guard, `int result = 0;`, MATH_MIN polarity and an if/else for the
 * 0/-0x1c select.  That body reproduces the Debug object at -O0 -inline off
 * (modulo assert line constants).  At -O4,p the guard arm is kept as a branch
 * only when `consumed` is also `volatile long` (volatile is invisible in this
 * DWARF); either change alone stays 260/264.  Earlier "front-end wall" notes
 * (lanes U41, W8, A, 07; docs/notes/func_0215D92C.c.txt) are superseded.
 */
static int func_0215D92C(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
                         unsigned long *remote_ip)
{
    unsigned long enable;
    struct SOCLiSocketRecvCommandPipe *recv_pipe;
    unsigned char *cpsbuffer;
    long cpsbuffer_len;
    long copy_len;
    long consume_len;
    unsigned short my_port;
    unsigned short his_port;
    unsigned long his_ip;
    int result = 0;

    enable = OS_DisableInterrupts();
    cpsbuffer = func_0215DA34(socket, &cpsbuffer_len, &my_port, &his_port, &his_ip);
    if (cpsbuffer != 0) {
        if (cpsbuffer_len == 0) {
            result = -6;
        } else {
            copy_len = (buffer_len <= cpsbuffer_len) ? buffer_len : cpsbuffer_len;
            consume_len = SOCL_SocketIsTCP(socket) ? copy_len : cpsbuffer_len;
            MI_CpuCopy(cpsbuffer, buffer, copy_len);
            recv_pipe = socket->recv_pipe;
            if (!recv_pipe->flag_noconsume)
                recv_pipe->consumed += consume_len;
            result = consume_len;
        }
    } else {
        if (cpsbuffer_len == 0)
            result = 0;
        else
            result = -0x1c;
        socket->state &= ~6;
    }
    if (result >= 0) {
        if (remote_port != 0 && remote_ip != 0) {
            *remote_port = his_port;
            *remote_ip = his_ip;
        }
        if (socket->local_port == 0)
            socket->local_port = my_port;
    }
    OS_RestoreInterrupts(enable);
    return result;
}

/*
 * sdk:      SOCLi_ReadCPSBuffer (libsoc.TWL.HYB.a(socl_read.o))
 */
unsigned char *func_0215DA34(struct SOCLSocket *socket, long *buffer_len, unsigned short *local_port,
                             unsigned short *remote_port, unsigned long *remote_ip)
{
    struct SOCLiSocketRecvCommandPipe *recv_pipe;
    struct CPSSoc *cpsoc;
    long consumed;
    long len;

    recv_pipe = socket->recv_pipe;
    cpsoc = recv_pipe->cpsoc;
    consumed = recv_pipe->consumed;
    len = cpsoc->total - consumed;
    if (len >= 0) {
        *local_port = cpsoc->local_port;
        *remote_port = cpsoc->remote_port;
        *remote_ip = cpsoc->remote_ip;
        *buffer_len = len;
        if (len == 0 && cpsoc->state != 4)
            return 0;
    } else {
        *buffer_len = -1;
        return 0;
    }
    return cpsoc->buf + consumed;
}

/*
 * sdk:      SOCLi_ExecReadCommand (libsoc.TWL.HYB.a(socl_read.o))
 */
int func_0215DAA8(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
                  unsigned long *remote_ip, long flag_block)
{
    struct SOCLiCommandRead *command;
    long result;

    if (flag_block & 1)
        command = SOCLi_CreateCommandPacket(func_0215DB0C, socket, 1);
    else
        command = SOCLi_CreateCommandPacket(func_0215DC5C, socket, 1);
    command->buffer = buffer;
    command->buffer_len = buffer_len;
    command->remote_port = remote_port;
    command->remote_ip = remote_ip;
    return SOCLi_ExecCommandPacketInRecvPipe(socket, command);
}

/*
 * sdk:      SOCLi_ReadCallBack (socl_read.o)
 */
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
        if (isStream(socket->flag_mode) && socket->cps_socket.state != 4) {
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
        MI_CpuCopy(cpsbuffer, buffer, buffer_len);
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
        func_0215DD88(socket);
    return result;
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
    if (*(volatile short *)&socket->state & 0x80)
        return -15;
    datalen = CPS_SocGetLength();
    if (datalen == 0)
        return -6;
    if (datalen == -1)
        return 0;
    cpsbuffer = CPS_SocRead(&cpsbuffer_len);
    if (cpsbuffer != 0 && (long)cpsbuffer_len - consumed <= 0) {
        if (isStream(socket->flag_mode) && socket->cps_socket.state != 4)
            cpsbuffer = 0;
    }
    if (*(volatile short *)&socket->state & 0x80)
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
int func_0215DD28(struct SOCLSocket *socket)
{
    struct SOCLiSocketRecvCommandPipe *recv_pipe;
    struct SOCLiCommandRead *command;
    long result;

    recv_pipe = socket->recv_pipe;
    if (recv_pipe->consumed < recv_pipe->consumed_min)
        return 0;
    result = 0;
    command = SOCLi_CreateCommandPacket(func_0215DD78, socket, result);
    if (command == 0)
        return result - 0x21;
    return SOCLi_ExecCommandPacketInRecvPipe(socket, command);
}

/* SOCLi_ConsumeCallBack: the command's socket sits at +4 */
int func_0215DD78(void *arg)
{
    return func_0215DD88(((struct SOCLiCommandRead *)arg)->socket);
}

/*
 * sdk:      SOCLi_ConsumeCPSBuffer (libsoc.TWL.HYB.a(socl_read.o))
 */
long func_0215DD88(struct SOCLSocket *socket)
{
    struct SOCLiSocketRecvCommandPipe *recv_pipe;
    unsigned long enable;
    long consumed;

    recv_pipe = socket->recv_pipe;
    enable = OS_DisableInterrupts();
    consumed = recv_pipe->consumed;
    if (consumed != 0) {
        recv_pipe->consumed = 0;
        CPS_SocConsume(consumed);
    }
    OS_RestoreInterrupts(enable);
    return consumed;
}

/*
 * sdk:      SOCLi_ReadUdpBuffer (socl_read.o)
 */
static int func_0215DDC4(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
                         unsigned long *remote_ip, long flag_block)
{
    unsigned long enable;
    struct SOCLiSocketRecvCommandPipe *pipe;
    struct SOCLiUdpData *udpdata;
    int result;

    pipe = socket->recv_pipe;
    enable = OS_DisableInterrupts();
    udpdata = pipe->head;
    if (udpdata == 0) {
        for (;;) {
            if (!(flag_block & 1)) {
                result = -6;
                break;
            }
            OS_SleepThread(&pipe->waiting);
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
        MI_CpuCopy(udpdata->data, buffer, buffer_len);
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
    OS_RestoreInterrupts(enable);
    return result;
}

/*
 * sdk:      SOCLi_UdpRecvCallback (libsoc.TWL.HYB.a(socl_read.o))
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
int func_0215DF08(unsigned char *data, unsigned long len, struct SOCLSocket *socket)
{
    struct SOCLiSocketRecvCommandPipe *pipe = socket->recv_pipe;
    struct SOCLiUdpData *udpheader;
    unsigned long enable;

    enable = OS_DisableInterrupts();
    if (pipe->recv_max >= pipe->recv_size + len) {
        udpheader = g_021A1CD8->alloc(len + 12);
        if (udpheader != 0) {
            pipe->recv_size += len;
            udpheader->next = 0;
            udpheader->size = len;
            udpheader->remote_port = socket->cps_socket.remote_port;
            udpheader->remote_ip = socket->cps_socket.remote_ip;
            MI_CpuCopy(data, udpheader->data, len);
            if (pipe->tail != 0)
                pipe->tail->next = udpheader;
            pipe->tail = udpheader;
            if (pipe->head == 0)
                pipe->head = udpheader;
        } else {
            g_021AA4A4[0]++;
        }
    } else {
        g_021AA4A4[1]++;
    }
    socket->cps_socket.remote_port = socket->cps_socket.remote_port2;
    socket->cps_socket.remote_ip = socket->cps_socket.remote_ip2;
    if (socket->local_port == 0)
        socket->local_port = socket->cps_socket.local_port;
    OS_WakeupThread(&pipe->waiting);
    OS_RestoreInterrupts(enable);
    return 1;
}
