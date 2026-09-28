/*
 * function: gti2SendRetries
 * address:  0x0219583C
 * packet:   pkt_ov009_0219583C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2SendRetries (gt2connection.o)
 *
 * symbols:
 *   ArrayLength       0x02184200 arm
 *   ArrayNth          0x02184208 arm
 *   gti2ResendMessage 0x02197C5C arm
 */

struct GTI2Connection;
struct GTI2OutgoingBufferMessage;
struct DArrayImplementation;

extern int ArrayLength(struct DArrayImplementation *array);
extern void *ArrayNth(struct DArrayImplementation *array, int n);
extern int gti2ResendMessage(struct GTI2Connection *connection,
                             struct GTI2OutgoingBufferMessage *message);

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
    struct DArrayImplementation *outgoingBuffers;
};

struct GTI2OutgoingBufferMessage {
    char pad00[0xc];
    unsigned int field_0c;
};

static int gti2SendRetries(struct GTI2Connection *connection, unsigned int now)
{
    int i;
    int len;

    len = ArrayLength(connection->outgoingBuffers);
    for (i = 0; i < len; i++)
    {
        struct GTI2OutgoingBufferMessage *message =
            ArrayNth(connection->outgoingBuffers, i);

        if ((now - message->field_0c) > 1000)
        {
            if (gti2ResendMessage(connection, message) == 0)
                return 0;
        }
    }
    return 1;
}
