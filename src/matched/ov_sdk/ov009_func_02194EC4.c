/*
 * function: gti2SocketErrorCallback
 * address:  0x02194EC4
 * packet:   pkt_ov009_02194EC4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2SocketErrorCallback (gt2callback.o)
 *
 * symbols:
 *   gti2CloseSocket  0x02197FDC  arm  ov009
 */

struct GTI2Socket {
    int socket;
    unsigned int ip;
    unsigned short port;
    struct HashImplementation *connections;
    struct DArrayImplementation *closedConnections;
    int close;
    int error;
    int callbackLevel;
    void (*connectAttemptCallback)(void);
    void (*socketErrorCallback)(struct GTI2Socket *);
};

extern void gti2CloseSocket(struct GTI2Socket *socket);

int gti2SocketErrorCallback(struct GTI2Socket *socket)
{
    if (socket == 0)
        return 1;
    if (socket->socketErrorCallback == 0)
        return 1;
    socket->callbackLevel++;
    socket->socketErrorCallback(socket);
    socket->callbackLevel--;
    if (socket->close != 0 && socket->callbackLevel == 0)
    {
        gti2CloseSocket(socket);
        return 0;
    }
    return 1;
}
