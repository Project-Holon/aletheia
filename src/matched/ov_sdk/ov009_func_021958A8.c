/*
 * function: gti2CheckPendingAck
 * address:  0x021958A8
 * packet:   pkt_ov009_021958A8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2CheckPendingAck (gt2connection.o)
 *
 * symbols:
 *   gti2SendAck  0x02197A30 arm
 */

struct GTI2Connection;

extern int gti2SendAck(struct GTI2Connection *connection);

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
    int pad8c;
    int pendingAck;
    unsigned int lastAck;
};

static int gti2CheckPendingAck(struct GTI2Connection *connection,
                               unsigned int now)
{
    if (!connection->pendingAck)
        return 1;
    if ((now - connection->lastAck) > 100)
    {
        if (gti2SendAck(connection) == 0)
            return 0;
    }
    return 1;
}
