/*
 * file:     unit_02198028_p02.c
 * unit:     yes
 * function: func_02198518, func_02198570, func_021985AC, func_021985E4
 * address:  0x02198518
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
 *   gti2ConnectionThink        0x02195918  arm  ov009
 *   gti2FreeSocketConnection   0x02198264  arm  ov009
 *   current_time                    0x0217F264  arm  ov009
 *   TableMapSafe2                   0x021848E4  arm  ov009
 *   ArrayLength               0x02184200  arm  ov009
 *   ArrayNth                  0x02184208  arm  ov009
 *   gt2CloseAllConnectionsHard  0x02195DE4  arm  ov009
 *   gti2SocketErrorCallback     0x02194EC4  arm  ov009
 *   gti2CloseSocket             0x02197FDC  arm  ov009
 */
struct GTI2Connection;
struct DArrayImplementation;
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

struct GTI2Socket_02198570 {
    char _pad0[0xc];
    struct HashImplementation *connections;
};

struct GTI2Socket_021985AC {
    char _pad0[0x10];
    struct DArrayImplementation *closedConnections;
};

struct GTI2Socket_021985E4 {
    char _pad0[0x18];
    int error;
};

extern int gti2ConnectionThink(struct GTI2Connection *connection,
                               unsigned int now);
extern void gti2FreeSocketConnection(struct GTI2Connection *connection);
extern unsigned int current_time(void);
extern int TableMapSafe2(struct HashImplementation *table,
                         int (*fn)(void *, void *), void *data);
extern int ArrayLength(struct DArrayImplementation *array);
extern void *ArrayNth(struct DArrayImplementation *array, int n);
extern void gt2CloseAllConnectionsHard(struct GTI2Socket_021985E4 *socket);
extern int gti2SocketErrorCallback(struct GTI2Socket_021985E4 *socket);
extern void gti2CloseSocket(struct GTI2Socket_021985E4 *socket);
int gti2SocketConnectionsThink(struct GTI2Socket_02198570 *socket);
void gti2FreeClosedConnections(struct GTI2Socket_021985AC *socket);
void gti2SocketError(struct GTI2Socket_021985E4 *socket);


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


int gti2SocketConnectionsThink(struct GTI2Socket_02198570 *socket)
{
    unsigned int now = current_time();

    if (TableMapSafe2(socket->connections, gti2SocketConnectionsThinkMap, &now))
        return 0;
    return 1;
}


void gti2FreeClosedConnections(struct GTI2Socket_021985AC *socket)
{
    int len = ArrayLength(socket->closedConnections);
    int i;

    for (i = len - 1; i >= 0; i--)
        gti2FreeSocketConnection(*(struct GTI2Connection **)
                                     ArrayNth(socket->closedConnections, i));
}


void gti2SocketError(struct GTI2Socket_021985E4 *socket)
{
    if (socket->error != 0)
        return;
    socket->error = 1;
    gt2CloseAllConnectionsHard(socket);
    if (gti2SocketErrorCallback(socket))
        gti2CloseSocket(socket);
}
