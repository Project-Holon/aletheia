/*
 * function: gti2EndReliableMessage
 * address:  0x0219754C
 * packet:   pkt_ov009_0219754C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2EndReliableMessage (gt2message.o)
 *
 * symbols:
 *   ArrayLength            0x02184200 arm
 *   ArrayNth               0x02184208 arm
 *   gti2ConnectionSendData 0x02195750 arm
 */

struct GTI2Connection;
struct GTI2OutgoingBufferMessage;
struct DArrayImplementation;

extern int ArrayLength(struct DArrayImplementation *array);
extern void *ArrayNth(struct DArrayImplementation *array, int n);
extern int gti2ConnectionSendData(struct GTI2Connection *connection,
                                  unsigned char *message, int len);

struct GTI2OutgoingBufferMessage {
    unsigned int offset;
    int len;
};

struct GTI2Connection {
    char pad00[0x50];
    unsigned char *buffer;
    char pad54[0xc];
    struct DArrayImplementation *outgoingBuffers;
    char pad64[0x2c];
    int pendingAck;
};

static int gti2EndReliableMessage(struct GTI2Connection *connection)
{
    struct GTI2OutgoingBufferMessage *message;
    int len;

    len = ArrayLength(connection->outgoingBuffers);
    message = ArrayNth(connection->outgoingBuffers, len - 1);
    if (gti2ConnectionSendData(connection, connection->buffer + message->offset,
                               message->len))
    {
        connection->pendingAck = 0;
        return 1;
    }
    return 0;
}
