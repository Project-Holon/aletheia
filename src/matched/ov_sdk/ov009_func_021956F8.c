/*
 * function: gti2RejectConnection
 * address:  0x021956F8
 * packet:   pkt_ov009_021956F8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2RejectConnection (gt2connection.o)
 *
 * symbols:
 *   gti2MessageCheck  0x02198808 arm
 *   gti2SendReject    0x021977E8 arm
 */

struct GTI2Connection;

extern void gti2MessageCheck(unsigned char **message, int *len);
extern int gti2SendReject(struct GTI2Connection *connection,
                          unsigned char *message, int len);

struct GTI2Connection {
    unsigned int ip;
    unsigned short port;
    char pad06[2];
    void *socket;
    int state;
    int field_10;
    int field_14;
};

void gti2RejectConnection(struct GTI2Connection *connection,
                          unsigned char *message, int len)
{
    connection->field_14 = 0;
    if (connection->state != 4)
        return;
    gti2MessageCheck(&message, &len);
    gti2SendReject(connection, message, len);
    connection->state = 6;
}
