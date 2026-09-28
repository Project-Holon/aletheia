/*
 * function: gti2SocketConnectionsThinkMap
 * address:  0x02198518
 * packet:   pkt_ov009_02198518
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2SocketConnectionsThinkMap (gt2socket.o)
 *
 * symbols:
 *   gti2ConnectionThink        0x02195918  arm  ov009
 *   gti2FreeSocketConnection   0x02198264  arm  ov009
 */

struct GTI2Connection {
    unsigned int ip;
    unsigned short port;
    struct GTI2Socket *socket;
    int state;
    int initiated;
    int freeAtAcceptReject;
    int connectionResult;
    unsigned int startTime;
    unsigned int timeout;
    int callbackLevel;
};

extern int gti2ConnectionThink(struct GTI2Connection *connection,
                               unsigned int now);
extern void gti2FreeSocketConnection(struct GTI2Connection *connection);

static int gti2SocketConnectionsThinkMap(void *elem, void *clientData)
{
    struct GTI2Connection *connection = *(struct GTI2Connection **)elem;
    unsigned int now = *(unsigned int *)clientData;

    if (connection->state != 7)
    {
        if (gti2ConnectionThink(connection, now) == 0)
            return 0;
    }
    if (connection->state == 7 && connection->freeAtAcceptReject == 0
        && connection->callbackLevel == 0)
        gti2FreeSocketConnection(connection);
    return 1;
}
