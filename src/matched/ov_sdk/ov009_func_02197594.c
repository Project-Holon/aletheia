/*
 * function: gti2SendAppReliable
 * address:  0x02197594
 * packet:   pkt_ov009_02197594
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2SendAppReliable (gt2message.o)
 *
 * symbols:
 *   gti2BeginReliableMessage  0x02197458 arm
 *   gti2BufferWriteData       0x02194e2c arm
 *   gti2EndReliableMessage    0x0219754c arm
 */

struct GTI2Connection {
    unsigned char pad0[0x50];
};

extern int gti2BeginReliableMessage(struct GTI2Connection * connection, int type, int len, int * overflow);
extern void gti2BufferWriteData(void * buffer, unsigned char * data, int len);
extern int gti2EndReliableMessage(struct GTI2Connection * connection);

int gti2SendAppReliable(struct GTI2Connection * connection, unsigned char * message, int len)
{
    int overflow;

    if (!gti2BeginReliableMessage(connection, 0, len + 7, &overflow))
        return 0;
    if (overflow)
        return 1;
    gti2BufferWriteData((char *)connection + 0x50, message, len);
    return gti2EndReliableMessage(connection) != 0;
}
