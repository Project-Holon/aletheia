/*
 * function: gti2SendAck
 * address:  0x02197A30
 * packet:   pkt_ov009_02197A30
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * blocker: field_40==2 arm if-converted to conditional stores; orig keeps branch; 144 vs 168 B
 * status:   DIFF
 *
 * sdk:      gti2SendAck (gt2message.o)
 *
 * symbols:
 *   gti2UShortToBuffer      0x02195EA0 arm
 *   gti2ConnectionSendData  0x02195750 arm
 *   d_021A5948              0x021A5948 data
 */

struct GTI2Connection;
struct GTI2Socket;

extern void gti2UShortToBuffer(unsigned char *buffer, int pos, unsigned short s);
extern int gti2ConnectionSendData(struct GTI2Connection *connection,
                                  unsigned char *message, int len);
extern unsigned char d_021A5948[];

struct GTI2Socket {
    char pad00[0x40];
    int field_40;
};

struct GTI2Buffer {
    unsigned char *data;
    int size;
    int position;
};

struct GTI2Connection {
    char pad00[8];
    struct GTI2Socket *socket;
    char pad0c[0x44];
    struct GTI2Buffer buffer;
    char pad5c[8];
    unsigned short field_64;
    unsigned short field_66;
    char pad68[0x28];
    int pendingAck;
};

int gti2SendAck(struct GTI2Connection *connection)
{
    short dataLength;
    int pos;
    char buffer[7];

    pos = 0;
    if (connection->socket->field_40 == 2)
    {
        dataLength = 5;
        buffer[0] = (unsigned char)dataLength;
        buffer[1] = (unsigned char)(dataLength >> 8);
        pos = 2;
    }
    buffer[pos] = d_021A5948[0];
    buffer[pos + 1] = d_021A5948[1];
    buffer[pos + 2] = 100;
    gti2UShortToBuffer((unsigned char *)buffer, pos + 3, connection->field_66);
    if (gti2ConnectionSendData(connection, (unsigned char *)buffer, pos + 5))
    {
        connection->pendingAck = 0;
        return 1;
    }
    return 0;
}
