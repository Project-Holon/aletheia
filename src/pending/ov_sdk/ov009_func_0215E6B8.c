/*
 * function: func_0215E6B8
 * address:  0x0215E6B8
 * packet:   pkt_ov009_0215E6B8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH (near miss: 120 B; image reloads flags (ldrsh) at each of three tests and keeps socket in r4, send_pipe r5; ours CSEs the loads and swaps r4/r5; IsOpen predicate not materialised)
 *
 * w9_nm2:   still DIFF (120 to 122 B), body unchanged. Tried predicate inline helpers
 *           (IsConnected/IsShutdown/SetShutdown), helpers taking `int s` with a
 *           local socket as in the DWARF, `int open = IsOpen(s); if (open == 0)`
 *           (76 B, the only improvement: it materialises IsOpen, but into r0 not r1),
 *           separate ifs, a flags pointer. The object reloads flags (ldrsh) at each
 *           of four accesses and keeps s in r4, send_pipe in r5; ours keeps s in r5.
 *
 * sdk:      SOCL_Shutdown (libsoc.TWL.HYB.a(socl_shutdown.o))
 *
 * symbols:
 *   func_0215F3D0  0x0215F3D0  arm  ov009
 *   SOCLi_CreateCommandPacket          0x0215CE3C  arm  ov009
 *   func_0215CF98  0x0215CF98  arm  ov009
 *   func_0215E764  0x0215E764  arm  ov009
 */

typedef struct {
    unsigned char pad0[0x10C];
    void *queue;
} SendPipe;

typedef struct {
    unsigned char pad0[0xA4];
    SendPipe *send_pipe;
    unsigned char pad1[4];
    short flags;
    signed char flag_block;
} Socket;

typedef struct Command Command;

extern int func_0215F3D0(Socket *socket);
extern Command *SOCLi_CreateCommandPacket(int (*handler)(void *), Socket *socket, long flag);
extern int func_0215CF98(void *queue, Command *command);
extern int func_0215E764(void *arg);

static inline int IsOpen(Socket *socket)
{
    int r = 0;

    if (socket != 0) {
        if (socket->flags & 1)
            r = 1;
    }
    return r;
}

int func_0215E6B8(Socket *socket)
{
    SendPipe *send_pipe;
    Command *command;

    if (func_0215F3D0(socket) != 0)
        return -0x1c;
    if (!IsOpen(socket))
        return -0x27;
    if ((socket->flags & 4) == 0 || (socket->flags & 8) != 0)
        return -0x38;
    socket->flags |= 8;
    send_pipe = socket->send_pipe;
    if (send_pipe != 0 && send_pipe->queue != 0) {
        command = SOCLi_CreateCommandPacket(func_0215E764, socket, socket->flag_block);
        if (command == 0)
            return -0x21;
        return func_0215CF98(send_pipe->queue, command);
    }
    return 0;
}
