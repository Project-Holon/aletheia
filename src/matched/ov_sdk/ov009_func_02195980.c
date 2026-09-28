/*
 * function: gti2CloseConnection
 * address:  0x02195980
 * packet:   pkt_ov009_02195980
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2CloseConnection (gt2connection.o)
 *
 * symbols:
 *   gti2ConnectionClosed    0x021959D0 arm
 *   gti2SendClosed          0x02197BB8 arm
 *   gti2ClosedCallback      0x02195158 arm
 *   gti2FreeSocketConnection 0x02198264 arm
 *   gti2SendClose           0x02197868 arm
 */

struct GTI2Connection;

extern void gti2ConnectionClosed(struct GTI2Connection *connection);
extern int gti2SendClosed(struct GTI2Connection *connection);
extern int gti2ClosedCallback(struct GTI2Connection *connection, int reason);
extern void gti2FreeSocketConnection(struct GTI2Connection *connection);
extern int gti2SendClose(struct GTI2Connection *connection);

struct GTI2Connection {
    unsigned int ip;
    unsigned short port;
    char pad06[2];
    void *socket;
    int state;
};

void gti2CloseConnection(struct GTI2Connection *connection, int hard)
{
    if (hard)
    {
        if (connection->state >= 7)
            return;
        gti2ConnectionClosed(connection);
        gti2SendClosed(connection);
        gti2ClosedCallback(connection, 0);
        gti2FreeSocketConnection(connection);
    }
    else
    {
        connection->state = 6;
        gti2SendClose(connection);
    }
}
