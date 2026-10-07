/*
 * file:     unit_0215D6C8_p01.c
 * unit:     yes
 * function: func_0215DA34, func_0215DAA8
 * address:  0x0215DA34
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
 *   SOCLi_CreateCommandPacket          0x0215CE3C  arm  ov009
 *   SOCLi_ExecCommandPacketInRecvPipe  0x0215CF88  arm  ov009
 *   SOCLi_ReadCallBack                 0x0215DB0C  arm  ov009
 *   SOCLi_ReadSSLNblockCallBack        0x0215DC5C  arm  ov009
 */
typedef struct {
    char pad0[8];
    unsigned char state;
    char pad9;
    unsigned short local_port;
    char padC[0xC];
    unsigned short remote_port;
    char pad1A[2];
    unsigned long remote_ip;
    char pad20[0x2C];
    unsigned char *buf;
    long total;
} CpSoc;

typedef struct {
    char pad0[0xC4];
    CpSoc *cpsoc;
    char padC8[0x30];
    long consumed;
} RecvPipe;

typedef struct {
    char pad0[0xA0];
    RecvPipe *recv_pipe;
} Socket_0215DA34;

typedef struct Socket_0215DAA8 Socket_0215DAA8;

typedef struct {
    int (*handler)(void *);
    Socket_0215DAA8 *socket;
    long field8;
    char padC[4];
    void *buffer;
    int buffer_len;
    unsigned short *remote_port;
    unsigned long *remote_ip;
} Command;

extern Command *SOCLi_CreateCommandPacket(int (*handler)(void *), Socket_0215DAA8 *socket, long flag);
extern int SOCLi_ExecCommandPacketInRecvPipe(Socket_0215DAA8 *socket, Command *command);
extern int SOCLi_ReadCallBack(void *arg);
extern int SOCLi_ReadSSLNblockCallBack(void *arg);
unsigned char *func_0215DA34(Socket_0215DA34 *socket, long *buffer_len, unsigned short *local_port, unsigned short *remote_port, unsigned long *remote_ip);
int func_0215DAA8(Socket_0215DAA8 *socket, void *buffer, int buffer_len, unsigned short *remote_port, unsigned long *remote_ip, long flag_block);


/*
 * sdk:      SOCLi_ReadCPSBuffer (libsoc.TWL.HYB.a(socl_read.o))
 */
unsigned char *func_0215DA34(Socket_0215DA34 *socket, long *buffer_len, unsigned short *local_port,
                             unsigned short *remote_port, unsigned long *remote_ip)
{
    RecvPipe *recv_pipe;
    CpSoc *cpsoc;
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
int func_0215DAA8(Socket_0215DAA8 *socket, void *buffer, int buffer_len, unsigned short *remote_port,
                  unsigned long *remote_ip, long flag_block)
{
    Command *command;
    long result;

    if (flag_block & 1)
        command = SOCLi_CreateCommandPacket(SOCLi_ReadCallBack, socket, 1);
    else
        command = SOCLi_CreateCommandPacket(SOCLi_ReadSSLNblockCallBack, socket, 1);
    command->buffer = buffer;
    command->buffer_len = buffer_len;
    command->remote_port = remote_port;
    command->remote_ip = remote_ip;
    return SOCLi_ExecCommandPacketInRecvPipe(socket, command);
}
