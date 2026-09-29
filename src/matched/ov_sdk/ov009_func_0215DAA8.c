/*
 * function: func_0215DAA8
 * address:  0x0215DAA8
 * packet:   pkt_ov009_0215DAA8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      SOCLi_ExecReadCommand (libsoc.TWL.HYB.a(socl_read.o))
 *
 * symbols:
 *   SOCLi_CreateCommandPacket          0x0215CE3C  arm  ov009
 *   SOCLi_ExecCommandPacketInRecvPipe  0x0215CF88  arm  ov009
 *   SOCLi_ReadCallBack                 0x0215DB0C  arm  ov009
 *   SOCLi_ReadSSLNblockCallBack        0x0215DC5C  arm  ov009
 */

typedef struct Socket Socket;

typedef struct {
    int (*handler)(void *);
    Socket *socket;
    long field8;
    char padC[4];
    void *buffer;
    int buffer_len;
    unsigned short *remote_port;
    unsigned long *remote_ip;
} Command;

extern Command *SOCLi_CreateCommandPacket(int (*handler)(void *), Socket *socket, long flag);
extern int SOCLi_ExecCommandPacketInRecvPipe(Socket *socket, Command *command);
extern int SOCLi_ReadCallBack(void *arg);
extern int SOCLi_ReadSSLNblockCallBack(void *arg);

int func_0215DAA8(Socket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
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
