/*
 * function: gti2StoreOutgoingReliableMessageInfo
 * address:  0x021973E4
 * packet:   pkt_ov009_021973E4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2StoreOutgoingReliableMessageInfo (gt2message.o)
 *
 * symbols:
 *   current_time  0x0217F264 arm
 *   ArrayLength   0x02184200 arm
 *   ArrayAppend   0x02184234 arm
 */

struct GTI2Connection;
struct GTI2OutgoingBufferMessage;
struct DArrayImplementation;

extern unsigned int current_time(void);
extern int ArrayLength(struct DArrayImplementation *array);
extern void ArrayAppend(struct DArrayImplementation *array, void *newElem);

struct GTI2OutgoingBufferMessage {
    unsigned int offset;
    int len;
    unsigned short SN;
    unsigned short pad;
    unsigned int sendTime;
};

struct GTI2Connection {
    char pad00[0x58];
    unsigned int field_58;
    char pad5c[4];
    struct DArrayImplementation *outgoingBuffers;
};

static int gti2StoreOutgoingReliableMessageInfo(struct GTI2Connection *connection,
                                                unsigned short SN, int len)
{
    struct GTI2OutgoingBufferMessage messageInfo = { 0 };
    int num;
    int result = 0;

    messageInfo.offset = connection->field_58;
    messageInfo.len = len;
    messageInfo.SN = SN;
    messageInfo.sendTime = current_time();
    num = ArrayLength(connection->outgoingBuffers);
    ArrayAppend(connection->outgoingBuffers, &messageInfo);
    if (ArrayLength(connection->outgoingBuffers) == (num + 1))
        result = 1;
    return result;
}
