/*
 * file:     socl_shutdown.c
 * unit:     yes
 * function: SOCL_Shutdown, SOCLi_ShutdownCallBack
 * address:  0x0215E6B8
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
 *   SOCL_SocketIsInvalid              0x0215F3D0  arm  ov009
 *   SOCLi_CreateCommandPacket         0x0215CE3C  arm  ov009
 *   SOCLi_ExecCommandPacketInSendPipe 0x0215CF98  arm  ov009
 *   SOCLi_ShutdownCallBack            0x0215E764  arm  ov009
 *   CPS_TcpShutdown  0x0215AD00  arm  ov009
 */
#include "socl_types.h"
#include "socl_command.h"

/* the original reads and writes the state word as volatile */
#define SOCKET_STATE(s) (*(volatile short *)&(s)->state)
#include "socl_command_types.h"

typedef struct {
    unsigned char pad0[0xAF];
    signed char mode;
} Socket;

typedef struct {
    unsigned long pad0;
    Socket *socket;
} Cmd;

#include "socl_list.h"
extern SOCLiCommandPacket *SOCLi_CreateCommandPacket(int (*handler)(void *),
                                                     SOCLSocket *socket,
                                                     long flag);
#include "cps_network.h"
int SOCL_Shutdown(sptr s);

static int SOCLi_ShutdownCallBack(void *arg);


int SOCL_Shutdown(sptr s)
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
        result = (SOCKET_STATE(socket) & 1) != 0;
    if (result == 0)
        return -0x27;
    if ((SOCKET_STATE(socket) & 4) == 0 || (SOCKET_STATE(socket) & 8) != 0)
        return -0x38;
    SOCKET_STATE(socket) |= 8;
    send_pipe = socket->send_pipe;
    if (send_pipe != 0 && send_pipe->exe_socket != 0) {
        command = SOCLi_CreateCommandPacket(SOCLi_ShutdownCallBack,
                                            send_pipe->exe_socket,
                                            socket->flag_block);
        if (command == 0)
            return -0x21;
        return SOCLi_ExecCommandPacketInSendPipe(send_pipe->exe_socket, command);
    }
    return 0;
}


static inline int IsTcp(int mode)
{
    int r = 1;

    if (mode != 0 && mode != 4)
        r = 0;
    return r;
}


/*
 * sdk:      SOCLi_ShutdownCallBack (libsoc.TWL.HYB.a(socl_shutdown.o))
 */
static int SOCLi_ShutdownCallBack(void *arg)
{
    Socket *socket = ((Cmd *)arg)->socket;

    if (IsTcp(socket->mode))
        CPS_TcpShutdown();
    return 0;
}
