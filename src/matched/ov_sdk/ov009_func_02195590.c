/*
 * function: gti2NewOutgoingConnection
 * address:  0x02195590
 * packet:   pkt_ov009_02195590
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2NewOutgoingConnection (gt2connection.o)
 *
 * symbols:
 *   gti2NewSocketConnection  0x02198038 arm
 */

struct GTI2Socket;
struct GTI2Connection;

extern int gti2NewSocketConnection(struct GTI2Socket *socket,
                                   struct GTI2Connection **connection,
                                   unsigned int ip, unsigned short port);

struct GTI2Connection {
    unsigned int ip;
    unsigned short port;
    char pad06[2];
    struct GTI2Socket *socket;
    int state;
    int field_10;
    int field_14;
    char pad18[0x10];
    char callbacks[0x10];
    char pad38[0x28];
    void *outgoingBuffers;
    char pad64[0x24];
    unsigned int lastSend;
    int pad8c;
    int pendingAck;
    unsigned int lastAck;
};

int gti2NewOutgoingConnection(struct GTI2Socket *socket,
                              struct GTI2Connection **connection,
                              unsigned int ip, unsigned short port)
{
    int result = gti2NewSocketConnection(socket, connection, ip, port);

    if (result)
        return result;
    (*connection)->state = 0;
    (*connection)->field_10 = 1;
    return 0;
}
