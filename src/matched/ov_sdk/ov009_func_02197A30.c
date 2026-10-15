/*
 * function: gti2SendAck
 * address:  0x02197A30
 * packet:   pkt_ov009_02197A30
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    w9_nm2: the two 2-byte copies written through pointer locals (s declared and assigned after dataLength = 5, then d = buffer + pos) keep the address arithmetic in registers instead of folding to sp offsets; the first attempt as a plain byte copy if-converted the arm.
 *
 * sdk:      gti2SendAck (gt2message.o)
 *
 * symbols:
 *   gti2UShortToBuffer      0x02195EA0 arm
 *   gti2ConnectionSendData  0x02195750 arm
 *   gGti2PacketMagic              0x021A5948 data
 */

struct GTI2Connection;
struct GTI2Socket;

extern void gti2UShortToBuffer(unsigned char *buffer, int pos, unsigned short s);
extern int gti2ConnectionSendData(struct GTI2Connection *connection,
                                  unsigned char *message, int len);
extern unsigned char gGti2PacketMagic[];

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
        unsigned char *s;
        unsigned char *d;
        dataLength = 5;
        s = (unsigned char *)&dataLength;
        d = (unsigned char *)buffer + pos;
        d[0] = s[0];
        d[1] = s[1];
        pos += 2;
    }
    {
        unsigned char *s = gGti2PacketMagic;
        unsigned char *d = (unsigned char *)buffer + pos;
        d[0] = s[0];
        d[1] = s[1];
        pos += 2;
    }
    buffer[pos] = 100;
    pos += 1;
    gti2UShortToBuffer((unsigned char *)buffer, pos, connection->field_66);
    pos += 2;
    if (gti2ConnectionSendData(connection, (unsigned char *)buffer, pos))
    {
        connection->pendingAck = 0;
        return 1;
    }
    return 0;
}
