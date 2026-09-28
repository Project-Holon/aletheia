/*
 * function: gti2CheckKeepAlive
 * address:  0x021958E4
 * packet:   pkt_ov009_021958E4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2CheckKeepAlive (gt2connection.o)
 *
 * symbols:
 *   gti2SendKeepAlive  0x021978CC arm
 */

struct GTI2Connection;

extern int gti2SendKeepAlive(struct GTI2Connection *connection);

struct GTI2Connection {
    unsigned int ip;
    unsigned short port;
    char pad06[2];
    void *socket;
    int state;
    int field_10;
    int field_14;
    char pad18[0x10];
    char callbacks[0x10];
    char pad38[0x28];
    void *outgoingBuffers;
    char pad64[0x24];
    unsigned int lastSend;
};

static int gti2CheckKeepAlive(struct GTI2Connection *connection,
                              unsigned int now)
{
    if ((now - connection->lastSend) > 30000)
    {
        if (gti2SendKeepAlive(connection) == 0)
            return 0;
    }
    return 1;
}
