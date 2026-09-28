/*
 * function: gti2ClosedCallback
 * address:  0x02195158
 * packet:   pkt_ov009_02195158
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2ClosedCallback (gt2callback.o)
 *
 * symbols:
 *   gti2CloseSocket  0x02197FDC arm
 */

struct GTI2Connection;
struct GTI2Socket;

typedef void (*GT2ClosedCallbackFn)(struct GTI2Connection *, int);

extern void gti2CloseSocket(struct GTI2Socket *socket);

struct GT2ConnectionCallbacks {
    void *connected;
    void *received;
    GT2ClosedCallbackFn closed;
    void *ping;
};

struct GTI2Socket {
    char pad00[0x14];
    int field_14;
    char pad18[4];
    int field_1c;
};

struct GTI2Connection {
    char pad00[8];
    struct GTI2Socket *socket;
    int state;
    int field_10;
    int field_14;
    char pad18[0xc];
    int field_24;
    struct GT2ConnectionCallbacks callbacks;
};

int gti2ClosedCallback(struct GTI2Connection *connection, int reason)
{
    if (!connection)
        return 1;
    if (!connection->callbacks.closed)
        return 1;
    connection->field_24++;
    connection->socket->field_1c++;
    connection->callbacks.closed(connection, reason);
    connection->field_24--;
    connection->socket->field_1c--;
    if ((connection->socket->field_14 != 0) &&
        (connection->socket->field_1c == 0))
    {
        gti2CloseSocket(connection->socket);
        return 0;
    }
    return 1;
}
