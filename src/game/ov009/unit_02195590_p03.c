/*
 * file:     unit_02195590_p03.c
 * unit:     yes
 * function: func_0219583C, func_021958A8, func_021958E4
 * address:  0x0219583C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ArrayLength       0x02184200 arm
 *   ArrayNth          0x02184208 arm
 *   gti2ResendMessage 0x02197C5C arm
 *   gti2SendAck  0x02197A30 arm
 *   gti2SendKeepAlive  0x021978CC arm
 */
struct GTI2Connection_0219583C;
struct GTI2OutgoingBufferMessage;
struct DArrayImplementation;
struct GTI2Connection_0219583C {
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

struct GTI2Connection_021958A8 {
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
    void *outgoingBuffers;
    char pad64[0x24];
    unsigned int lastSend;
    int pad8c;
    int pendingAck;
    unsigned int lastAck;
};

struct GTI2Connection_021958E4 {
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
    void *outgoingBuffers;
    char pad64[0x24];
    unsigned int lastSend;
};

extern int ArrayLength(struct DArrayImplementation *array);
extern void *ArrayNth(struct DArrayImplementation *array, int n);
extern int gti2ResendMessage(struct GTI2Connection_0219583C *connection,
                             struct GTI2OutgoingBufferMessage *message);
extern int gti2SendAck(struct GTI2Connection_021958A8 *connection);
extern int gti2SendKeepAlive(struct GTI2Connection_021958E4 *connection);


static int gti2SendRetries(struct GTI2Connection_0219583C *connection, unsigned int now)
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


static int gti2CheckPendingAck(struct GTI2Connection_021958A8 *connection,
                               unsigned int now)
{
    if (!connection->pendingAck)
        return 1;
    if ((now - connection->lastAck) > 100)
    {
        if (gti2SendAck(connection) == 0)
            return 0;
    }
    return 1;
}


static int gti2CheckKeepAlive(struct GTI2Connection_021958E4 *connection,
                              unsigned int now)
{
    if ((now - connection->lastSend) > 30000)
    {
        if (gti2SendKeepAlive(connection) == 0)
            return 0;
    }
    return 1;
}
