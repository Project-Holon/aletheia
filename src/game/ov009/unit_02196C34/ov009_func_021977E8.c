/*
 * function: gti2SendReject
 * address:  0x021977E8
 * packet:   pkt_ov009_021977E8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2SendReject (gt2message.o)
 *
 * symbols:
 *   gti2BeginReliableMessage  0x02197458 arm
 *   gti2BufferWriteData       0x02194E2C arm
 *   gti2EndReliableMessage    0x0219754C arm
 */

struct GTI2Connection;
struct GTI2Socket;
struct GTI2Buffer;

extern int gti2BeginReliableMessage(struct GTI2Connection *connection, int type,
                                    int len, int *overflow);
extern void gti2BufferWriteData(struct GTI2Buffer *buffer,
                                unsigned char *data, int len);
extern int gti2EndReliableMessage(struct GTI2Connection *connection);

struct GTI2Socket {
    char pad00[0x44];
    int field_44;
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
};

int gti2SendReject(struct GTI2Connection *connection, unsigned char *message,
                   int len)
{
    int overflow;

    if (!gti2BeginReliableMessage(connection, 5,
                                  (len + 7) + connection->socket->field_44,
                                  &overflow))
        return 0;
    if (overflow)
        return 1;
    gti2BufferWriteData(&connection->buffer, message, len);
    return gti2EndReliableMessage(connection) != 0;
}
