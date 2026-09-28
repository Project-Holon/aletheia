/*
 * function: gti2ConnectionClosed
 * address:  0x021959D0
 * packet:   pkt_ov009_021959D0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2ConnectionClosed (gt2connection.o)
 *
 * symbols:
 *   TableRemove  0x021847BC arm
 *   ArrayAppend  0x02184234 arm
 */

struct GTI2Connection;
struct GTI2Socket;
struct HashImplementation;
struct DArrayImplementation;

extern int TableRemove(struct HashImplementation *table, void *delElem);
extern void ArrayAppend(struct DArrayImplementation *array, void *newElem);

struct GTI2Socket {
    char pad00[0xc];
    struct HashImplementation *connections;
    struct DArrayImplementation *closedConnections;
};

struct GTI2Connection {
    unsigned int ip;
    unsigned short port;
    char pad06[2];
    struct GTI2Socket *socket;
    int state;
};

void gti2ConnectionClosed(struct GTI2Connection *connection)
{
    if (connection->state == 7)
        return;
    connection->state = 7;
    TableRemove(connection->socket->connections, &connection);
    ArrayAppend(connection->socket->closedConnections, &connection);
}
