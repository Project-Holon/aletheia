/*
 * function: gt2Think
 * address:  0x02195AF0
 * packet:   pkt_ov009_02195AF0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gt2Think (gt2main.o)
 *
 * symbols:
 *   gti2ReceiveMessages              0x0219725c arm
 *   gti2SocketConnectionsThink       0x02198570 arm
 *   gti2FreeClosedConnections        0x021985ac arm
 */

struct GTI2Socket;

extern int gti2ReceiveMessages(struct GTI2Socket *socket);
extern int gti2SocketConnectionsThink(struct GTI2Socket *socket);
extern void gti2FreeClosedConnections(struct GTI2Socket *socket);

void gt2Think(struct GTI2Socket *socket)
{
    if (gti2ReceiveMessages(socket) == 0)
        return;
    if (gti2SocketConnectionsThink(socket) == 0)
        return;
    gti2FreeClosedConnections(socket);
}
