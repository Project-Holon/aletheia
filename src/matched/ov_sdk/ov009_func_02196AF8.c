/*
 * function: gti2HandleAck
 * address:  0x02196AF8
 * packet:   pkt_ov009_02196AF8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2HandleAck (gt2message.o)
 *
 * symbols:
 *   gti2ConnectionCommunicationError  0x02195f5c arm
 *   gti2UShortFromBuffer              0x02195e80 arm
 *   gti2HandleESN                     0x02195f9c arm
 */

struct GTI2Connection {
    unsigned char pad0[0xc];
    int state;
};

extern int gti2ConnectionCommunicationError(struct GTI2Connection * connection);
extern unsigned short gti2UShortFromBuffer(unsigned char * buffer, int pos);
extern int gti2HandleESN(struct GTI2Connection * connection, unsigned short ESN);

static int gti2HandleAck(struct GTI2Connection * connection, unsigned char * message, int len)
{
    unsigned short ESN;

    if (len != 2)
        return gti2ConnectionCommunicationError(connection) != 0;
    ESN = gti2UShortFromBuffer(message, 0);
    return gti2HandleESN(connection, ESN) != 0;
}
