/*
 * function: SOCLi_ReadBuffer
 * address:  0x0215D898
 * packet:   pkt_ov009_0215D898
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_ReadBuffer (libsoc.TWL.HYB.a(socl_read.o))
 *
 * symbols:
 *   SOCLi_ExecReadCommand  0x0215DAA8  arm  ov009
 *   func_0215D92C  0x0215D92C  arm  ov009
 */

typedef struct {
    char pad0[0xAF];
    signed char mode;
} Socket;

extern int SOCLi_ExecReadCommand(Socket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
                         unsigned long *remote_ip, long flag_block);
struct SOCLSocket;
extern int func_0215D92C(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port, unsigned long *remote_ip);

int SOCLi_ReadBuffer(Socket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
                  unsigned long *remote_ip, long flag_block)
{
    int result;

    if (socket->mode == 4)
        return SOCLi_ExecReadCommand(socket, buffer, buffer_len, remote_port, remote_ip, flag_block);
    result = func_0215D92C((struct SOCLSocket *)socket, buffer, buffer_len, remote_port, remote_ip);
    if (result != -6)
        return result;
    if ((flag_block & 1) == 0)
        return result;
    return SOCLi_ExecReadCommand(socket, buffer, buffer_len, remote_port, remote_ip, 1);
}
