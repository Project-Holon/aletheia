/*
 * function: gti2FreeClosedConnections
 * address:  0x021985AC
 * packet:   pkt_ov009_021985AC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2FreeClosedConnections (gt2socket.o)
 *
 * symbols:
 *   ArrayLength               0x02184200  arm  ov009
 *   ArrayNth                  0x02184208  arm  ov009
 *   gti2FreeSocketConnection  0x02198264  arm  ov009
 */

struct GTI2Connection;
struct DArrayImplementation;

struct GTI2Socket {
    char _pad0[0x10];
    struct DArrayImplementation *closedConnections;
};

extern int ArrayLength(struct DArrayImplementation *array);
extern void *ArrayNth(struct DArrayImplementation *array, int n);
extern void gti2FreeSocketConnection(struct GTI2Connection *connection);

void gti2FreeClosedConnections(struct GTI2Socket *socket)
{
    int len = ArrayLength(socket->closedConnections);
    int i;

    for (i = len - 1; i >= 0; i--)
        gti2FreeSocketConnection(*(struct GTI2Connection **)
                                     ArrayNth(socket->closedConnections, i));
}
