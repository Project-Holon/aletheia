/*
 * function: SOCL_Shutdown
 * address:  0x0215E6B8
 * packet:   pkt_ov009_0215E6B8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_Shutdown (libsoc.TWL.HYB.a(socl_shutdown.o))
 * vendor:   sdkobj.py SOCL_Shutdown -- .comment "4.0.0.1024" == dsi/1.1p1.
 *           Prototype int SOCL_Shutdown(int s) (s -> r4), locals result
 *           (long), command, send_pipe (r5), socket.
 *
 * Two source shapes pin the body:
 *   - `flags` is `volatile short`: the image re-reads it with a fresh ldrsh
 *     at each of the four tests (flags&1, flags&4, flags&8, |=8); without
 *     volatile 1.1p1 CSEs the load.
 *   - the connected test is written as a null guard around a bool
 *     assignment: `if (socket != 0) result = (socket->flags & 1) != 0;`.
 *     The one-expression forms (`result = (socket != 0) && (...);`, or
 *     `if (socket && ...) result = 1;`) make 1.1p1 emit a branchy
 *     selection in r0 (mov r0,#0 / movne r0,#1 / bne); the null-guarded
 *     bool assignment keeps `mov r1,#0` hoisted above the branch and
 *     predicates `movne r1,#1`, which is the image.
 *   - the pipe guard is the shared-exit inverted form
 *     `if (pipe != 0 && pipe->queue != 0) { ... } return 0;`; a plain
 *     `if (pipe == 0 || ...) return 0;` predicates the return.
 *
 * symbols:
 *   SOCL_SocketIsInvalid              0x0215F3D0  arm  ov009
 *   SOCLi_CreateCommandPacket         0x0215CE3C  arm  ov009
 *   SOCLi_ExecCommandPacketInSendPipe 0x0215CF98  arm  ov009
 *   SOCLi_ShutdownCallBack            0x0215E764  arm  ov009
 */

typedef struct SOCLSocket SOCLSocket;

typedef struct {
    unsigned char pad0[0x10C];
    SOCLSocket *socket;
} SOCLiSocketSendCommandPipe;

struct SOCLSocket {
    unsigned char pad0[0xA4];
    SOCLiSocketSendCommandPipe *send_pipe;
    unsigned char pad1[4];
    volatile short flags;
    signed char flag_block;
};

typedef union SOCLiCommandPacket SOCLiCommandPacket;

extern int SOCL_SocketIsInvalid(SOCLSocket *socket);
extern SOCLiCommandPacket *SOCLi_CreateCommandPacket(int (*handler)(void *),
                                                     SOCLSocket *socket,
                                                     long flag);
extern int SOCLi_ExecCommandPacketInSendPipe(SOCLSocket *socket,
                                             SOCLiCommandPacket *command);
static int SOCLi_ShutdownCallBack(void *arg);

int SOCL_Shutdown(int s)
{
    long result;
    SOCLiCommandPacket *command;
    SOCLiSocketSendCommandPipe *send_pipe;
    SOCLSocket *socket;

    if (SOCL_SocketIsInvalid((SOCLSocket *)s))
        return -0x1c;

    socket = (SOCLSocket *)s;
    result = 0;
    if (socket != 0)
        result = (socket->flags & 1) != 0;
    if (result == 0)
        return -0x27;
    if ((socket->flags & 4) == 0 || (socket->flags & 8) != 0)
        return -0x38;
    socket->flags |= 8;
    send_pipe = socket->send_pipe;
    if (send_pipe != 0 && send_pipe->socket != 0) {
        command = SOCLi_CreateCommandPacket(SOCLi_ShutdownCallBack,
                                            send_pipe->socket,
                                            socket->flag_block);
        if (command == 0)
            return -0x21;
        return SOCLi_ExecCommandPacketInSendPipe(send_pipe->socket, command);
    }
    return 0;
}
