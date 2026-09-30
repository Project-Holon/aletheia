/*
 * function: SOCL_Shutdown
 * address:  0x0215E6B8
 * packet:   pkt_ov009_0215E6B8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      SOCL_Shutdown (libsoc.TWL.HYB.a(socl_shutdown.o))
 * vendor:   sdkobj.py SOCL_Shutdown -- .comment "4.0.0.1024" resolves to
 *           dsi/1.1p1, so the front end is right and this is a body residue.
 *
 * w10_t2: 156 B -> 164 B, 122 -> 80 concrete bytes out. The parked body typed
 * the parameter `Socket *socket` and used a branchy `if (!IsOpen(socket))`; the
 * defining object's DWARF names the parameter `int s` AND carries locals
 * `result` (long), `command`, `send_pipe` AND `socket`, and the image
 * MATERIALISES the open test into r1 (`mov r1, #0` / `ldrsh r0, [r4, #0xac]` /
 * `tst r0, #1` / `movne r1, #1` / `cmp r1, #0` / `mvneq r0, #0x26`) and
 * reloads the flags (`ldrsh`) at each of the three separate tests instead of
 * CSE-ing them, which was the whole of the 16-byte shortfall. Recasting the
 * parameter to `int s`, binding `socket = (struct SOCLSocket *)s`, and spelling
 * the test `result = 0; if (socket != 0 && (socket->flags & 1) != 0) result = 1;
 * if (result == 0) return -0x27;` reproduces both.
 *
 * REMAINING RESIDUE (8 B / 80 concrete bytes), one transposition and one
 * if-conversion:
 *   image `mov r4, r0` (s -> r4)              | ours `mov r5, r0`
 *   image `ldr r5, [r4, #0xa4]` (pipe -> r5)  | ours `ldr r4, [r5, #0xa4]`
 *   image `ldr r0, [r5, #0x10c]`              | ours `ldr r0, [r4, #0x10c]`
 *   image `beq 0x0215E758` (`mov r0, #0; pop`) | ours `moveq r0, #0` / `popeq`
 * The second argument of SOCLi_CreateCommandPacket must be the `send_pipe->queue`
 * value already live in r1 from the guard: the image has NO `mov r1, rB` before
 * the `bl` at 0x0215E73C.
 *
 * w10_t2 measured and rejected, none moved the 164/80 point: all four
 * declaration permutations of {socket, send_pipe, command, result} (the
 * register choice is not declaration-driven here); `long` vs `int result` and a
 * separate `open` local; the guard split as two separate null tests; and a
 * `Socket *`-typed second argument to SOCLi_CreateCommandPacket (worse -- it
 * adds the `mov r1, rB` the image does not have). 88 pin x flag configurations
 * also compiled: `-O4,s` / `-O4` / `-O3` collapse to 152 B, nothing reaches 172.
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
extern Command *SOCLi_CreateCommandPacket(int (*handler)(void *), SendPipe *pipe, long flag);
extern int func_0215CF98(void *queue, Command *command);
extern int func_0215E764(void *arg);

int SOCL_Shutdown(int s)
{
    Socket *socket;
    SendPipe *send_pipe;
    Command *command;
    long result;

    if (func_0215F3D0((Socket *)s) != 0)
        return -0x1c;
    socket = (Socket *)s;
    result = 0;
    if (socket != 0 && (socket->flags & 1) != 0)
        result = 1;
    if (result == 0)
        return -0x27;
    if ((socket->flags & 4) == 0 || (socket->flags & 8) != 0)
        return -0x38;
    socket->flags |= 8;
    send_pipe = socket->send_pipe;
    if (send_pipe == 0 || send_pipe->queue == 0)
        return 0;
    command = SOCLi_CreateCommandPacket(func_0215E764, send_pipe->queue, socket->flag_block);
    if (command == 0)
        return -0x21;
    return func_0215CF98(send_pipe->queue, command);
}
