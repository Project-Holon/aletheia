/*
 * function: func_0215DD28
 * address:  0x0215DD28
 * packet:   pkt_ov009_0215DD28
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_ConsumeBuffer (libsoc.TWL.HYB.a(socl_read.o))
 *
 * symbols:
 *   SOCLi_CreateCommandPacket          0x0215CE3C  arm  ov009
 *   SOCLi_ExecCommandPacketInRecvPipe  0x0215CF88  arm  ov009
 *   SOCLi_ConsumeCallBack              0x0215DD78  arm  ov009
 */

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

extern Command *SOCLi_CreateCommandPacket(int (*handler)(void *), Socket *socket, long flag);
extern int SOCLi_ExecCommandPacketInRecvPipe(Socket *socket, Command *command);
extern int SOCLi_ConsumeCallBack(void *arg);

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
