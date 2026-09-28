/*
 * function: gti2AcceptConnection
 * address:  0x0219569C
 * packet:   pkt_ov009_0219569C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      gti2AcceptConnection (gt2connection.o)
 *
 * symbols:
 *   gti2SendAccept  0x02197784 arm
 */

struct GTI2Connection;

struct GT2ConnectionCallbacks {
    void *connected;
    void *received;
    void *closed;
    void *ping;
};

extern int gti2SendAccept(struct GTI2Connection *connection);

struct GTI2Connection {
    unsigned int ip;
    unsigned short port;
    char pad06[2];
    void *socket;
    int state;
    int field_10;
    int field_14;
    char pad18[0x10];
    struct GT2ConnectionCallbacks callbacks;
};

int gti2AcceptConnection(struct GTI2Connection *connection,
                         struct GT2ConnectionCallbacks *callbacks)
{
    if (connection->field_14)
    {
        connection->field_14 = 0;
        return 0;
    }
    connection->field_14 = 0;
    if (connection->state != 4)
        return 0;
    gti2SendAccept(connection);
    connection->state = 5;
    if (callbacks)
        connection->callbacks = *callbacks;
    return 1;
}
