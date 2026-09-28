/*
 * function: SOCL_SocketIsInvalid
 * address:  0x0215f3d0
 * packet:   pkt_ov009_0215F3D0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_SocketIsInvalid (socl_list.o)
 *
 * symbols:
 *   SOCLi_SocketGetNextPtr   0x0215f36c arm
 *   SOCLiSocketList          0x021aa4b4 data
 */

struct SOCLSocket;

extern struct SOCLSocket *SOCLiSocketList;
extern struct SOCLSocket **SOCLi_SocketGetNextPtr(struct SOCLSocket **next,
                                                  struct SOCLSocket *socket);

int SOCL_SocketIsInvalid(struct SOCLSocket *socket)
{
    if ((int)socket <= 0
        || SOCLi_SocketGetNextPtr(&SOCLiSocketList, socket) == 0)
        return 1;
    return 0;
}
