/*
 * function: gti2SocketError
 * address:  0x021985E4
 * packet:   pkt_ov009_021985E4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2SocketError (gt2socket.o)
 *
 * symbols:
 *   gt2CloseAllConnectionsHard  0x02195DE4  arm  ov009
 *   gti2SocketErrorCallback     0x02194EC4  arm  ov009
 *   gti2CloseSocket             0x02197FDC  arm  ov009
 */

struct GTI2Socket {
    char _pad0[0x18];
    int error;
};

extern void gt2CloseAllConnectionsHard(struct GTI2Socket *socket);
extern int gti2SocketErrorCallback(struct GTI2Socket *socket);
extern void gti2CloseSocket(struct GTI2Socket *socket);

void gti2SocketError(struct GTI2Socket *socket)
{
    if (socket->error != 0)
        return;
    socket->error = 1;
    gt2CloseAllConnectionsHard(socket);
    if (gti2SocketErrorCallback(socket))
        gti2CloseSocket(socket);
}
