/*
 * function: gti2FreeSocketConnection
 * address:  0x02198264
 * packet:   pkt_ov009_02198264
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2FreeSocketConnection (gt2socket.o)
 *
 * symbols:
 *   ArrayLength    0x02184200  arm  ov009
 *   ArrayNth       0x02184208  arm  ov009
 *   ArrayDeleteAt  0x0218437C  arm  ov009
 *   TableRemove    0x021847BC  arm  ov009
 */

struct DArrayImplementation;
struct HashImplementation;

struct GTI2Socket {
    int socket;
    unsigned int ip;
    unsigned short port;
    struct HashImplementation *connections;
    struct DArrayImplementation *closedConnections;
};

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

extern int ArrayLength(struct DArrayImplementation *array);
extern void *ArrayNth(struct DArrayImplementation *array, int n);
extern void ArrayDeleteAt(struct DArrayImplementation *array, int n);
extern int TableRemove(struct HashImplementation *table, void *delElem);

void gti2FreeSocketConnection(struct GTI2Connection *connection)
{
    int len;
    int i;

    if (connection->freeAtAcceptReject != 0 || connection->callbackLevel != 0)
        return;
    if (connection->state == 7)
    {
        len = ArrayLength(connection->socket->closedConnections);
        for (i = 0; i < len; i++)
        {
            if (connection == *(struct GTI2Connection **)ArrayNth(
                    connection->socket->closedConnections, i))
            {
                ArrayDeleteAt(connection->socket->closedConnections, i);
                return;
            }
        }
    }
    else
    {
        TableRemove(connection->socket->connections, &connection);
    }
}
