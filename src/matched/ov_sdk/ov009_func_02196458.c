/*
 * function: gti2HandleAccept
 * address:  0x02196458
 * packet:   pkt_ov009_02196458
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2HandleAccept (gt2message.o)
 *
 * symbols:
 *   gti2ConnectionCommunicationError  0x02195f5c arm
 *   gti2ConnectedCallback             0x0219500c arm
 */

struct GTI2Connection {
    unsigned char pad0[0xc];
    int state;
};

extern int gti2ConnectionCommunicationError(struct GTI2Connection * connection);
extern int gti2ConnectedCallback(struct GTI2Connection * connection, int result, unsigned char * message, int len);

static int gti2HandleAccept(struct GTI2Connection * connection)
{
    if (connection->state != 1)
        return gti2ConnectionCommunicationError(connection) != 0;
    connection->state = 5;
    return gti2ConnectedCallback(connection, 0, 0, 0) != 0;
}
