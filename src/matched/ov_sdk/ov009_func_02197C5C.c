/*
 * function: gti2ResendMessage
 * address:  0x02197C5C
 * packet:   pkt_ov009_02197C5C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2ResendMessage (gt2message.o)
 *
 * symbols:
 *   gti2UShortToBuffer      0x02195EA0 arm
 *   gti2ConnectionSendData  0x02195750 arm
 */

struct GTI2Connection;
struct GTI2Socket;
struct GTI2Buffer;
struct GTI2OutgoingBufferMessage;

extern void gti2UShortToBuffer(unsigned char *buffer, int pos, unsigned short s);
extern int gti2ConnectionSendData(struct GTI2Connection *connection,
                                  unsigned char *message, int len);

struct GTI2Socket {
    char pad00[0x44];
    int field_44;
};

struct GTI2Buffer {
    unsigned char *data;
    int size;
    int position;
};

struct GTI2OutgoingBufferMessage {
    unsigned int offset;
    int len;
    unsigned short SN;
    unsigned short pad;
    unsigned int sendTime;
};

struct GTI2Connection {
    char pad00[8];
    struct GTI2Socket *socket;
    char pad0c[0x44];
    struct GTI2Buffer buffer;
    char pad5c[8];
    unsigned short field_64;
    unsigned short field_66;
    char pad68[0x20];
    unsigned int lastSend;
    unsigned int field_8c;
};

int gti2ResendMessage(struct GTI2Connection *connection,
                      struct GTI2OutgoingBufferMessage *message)
{
    gti2UShortToBuffer(connection->buffer.data,
                       message->offset + connection->socket->field_44 + 5,
                       connection->field_66);
    if (gti2ConnectionSendData(connection,
                               connection->buffer.data + message->offset,
                               message->len) == 0)
        return 0;
    message->sendTime = connection->lastSend;
    if (connection->buffer.data[message->offset +
                                connection->socket->field_44 + 2] == 2)
        connection->field_8c = connection->lastSend;
    return 1;
}
