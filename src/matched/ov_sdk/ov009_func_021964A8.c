/*
 * function: gti2HandleReject
 * address:  0x021964A8
 * packet:   pkt_ov009_021964A8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2HandleReject (gt2message.o)
 *
 * symbols:
 *   gti2ConnectionCommunicationError  0x02195f5c arm
 *   gti2ConnectionClosed              0x021959d0 arm
 *   gti2SendClosed                    0x02197bb8 arm
 *   gti2ConnectedCallback             0x0219500c arm
 */

struct GTI2Connection {
    unsigned char pad0[0xc];
    int state;
};

extern int gti2ConnectionCommunicationError(struct GTI2Connection * connection);
extern void gti2ConnectionClosed(struct GTI2Connection * connection);
extern int gti2SendClosed(struct GTI2Connection * connection);
extern int gti2ConnectedCallback(struct GTI2Connection * connection, int result, unsigned char * message, int len);

static int gti2HandleReject(struct GTI2Connection * connection, unsigned char * message, int len)
{
    if (connection->state != 1)
        return gti2ConnectionCommunicationError(connection) != 0;
    gti2ConnectionClosed(connection);
    if (!gti2SendClosed(connection))
        return 0;
    if (gti2ConnectedCallback(connection, 2, message, len))
        return 1;
    return 0;
}
