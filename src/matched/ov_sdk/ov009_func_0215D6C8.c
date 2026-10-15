/*
 * function: SOCL_ReadFrom
 * address:  0x0215D6C8
 * packet:   pkt_ov009_0215D6C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_ReadFrom (socl_read.o)
 *
 * symbols:
 *   func_0215F3D0  0x0215F3D0  arm  ov009
 *   func_020879EC  0x020879EC  arm
 *   OS_TryLockMutex  0x020860D0  arm
 *   OS_LockMutex  0x02086028  arm
 *   SOCLi_ReadAndConsumeBuffer  0x0215D7FC  arm  ov009
 *   func_02086078  0x02086078  arm
 *
 * The second state test is a volatile load: the image reloads socket->state between the two bit tests.
 */

struct SOCLiSocketRecvCommandPipe {
    unsigned char pad0[0xe0];
    unsigned char mutex[0x18];
};

struct SOCLSocket {
    unsigned char pad0[0xa0];
    struct SOCLiSocketRecvCommandPipe *recv_pipe;
    unsigned char pada4[0xac - 0xa4];
    short state;
    signed char flag_block;
    signed char flag_mode;
};

extern int func_0215F3D0(struct SOCLSocket *socket);
extern int func_020879EC(void);
extern int OS_TryLockMutex(void *mutex);
extern void OS_LockMutex(void *mutex);
extern int SOCLi_ReadAndConsumeBuffer(char *a, int b, int c, int d, int e, int f, int g);
extern void func_02086078(void *mutex);

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

int SOCL_ReadFrom(int s, void *buffer, int buffer_len, unsigned short *remote_port, unsigned long *remote_ip,
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
    result = SOCLi_ReadAndConsumeBuffer((char *)socket, (int)buffer, buffer_len, (int)remote_port, (int)remote_ip, flag_block, flags);
    func_02086078(recv_pipe->mutex);
    return result;
}
