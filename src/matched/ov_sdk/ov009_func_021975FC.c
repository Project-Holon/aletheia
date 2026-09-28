/*
 * function: gti2SendClientChallenge
 * address:  0x021975FC
 * packet:   pkt_ov009_021975FC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2SendClientChallenge (gt2message.o)
 *
 * symbols:
 *   gti2BeginReliableMessage  0x02197458 arm
 *   gti2BufferWriteData       0x02194e2c arm
 *   gti2EndReliableMessage    0x0219754c arm
 */

struct GTI2Peer {
    unsigned char pad0[0x44];
    int field_44;
};

struct GTI2Connection {
    unsigned char pad0[8];
    struct GTI2Peer * peer;
};

extern int gti2BeginReliableMessage(struct GTI2Connection * connection, int type, int len, int * overflow);
extern void gti2BufferWriteData(void * buffer, unsigned char * data, int len);
extern int gti2EndReliableMessage(struct GTI2Connection * connection);

int gti2SendClientChallenge(struct GTI2Connection * connection, char * challenge)
{
    int overflow;

    if (!gti2BeginReliableMessage(connection, 1, connection->peer->field_44 + 0x27, &overflow))
        return 0;
    if (overflow)
        return 1;
    gti2BufferWriteData((char *)connection + 0x50, (unsigned char *)challenge, 0x20);
    return gti2EndReliableMessage(connection) != 0;
}
