/*
 * function: func_0219666C
 * address:  0x0219666C
 * packet:   pkt_ov009_0219666C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2BufferIncomingMessage (libdwcgsgt2.TWL.HYB.a gt2message.o)
 *
 * symbols:
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_02195EB4  0x02195EB4  arm  ov009
 *   func_02194DD4  0x02194DD4  arm  ov009
 *   func_021842D0  0x021842D0  arm  ov009
 *   func_02194E2C  0x02194E2C  arm  ov009
 *   func_02197AD8  0x02197AD8  arm  ov009
 *   func_02196658  0x02196658  arm  ov009
 */

struct DArrayImplementation;

struct GTI2Buffer {
    unsigned char *buffer;
    int size;
    int len;
};

typedef struct GT2ConnectionCallbacks {
    void *connected;
    void *received;
    void *closed;
    void *ping;
} GT2ConnectionCallbacks;

struct GTI2Connection {
    unsigned int ip;                                     /* 0x00 */
    unsigned short port;                                 /* 0x04 */
    struct GTI2Socket *socket;                           /* 0x08 */
    int state;                                           /* 0x0C */
    int initiated;                                       /* 0x10 */
    int freeAtAcceptReject;                              /* 0x14 */
    int connectionResult;                                /* 0x18 */
    unsigned int startTime;                              /* 0x1C */
    unsigned int timeout;                                /* 0x20 */
    int callbackLevel;                                   /* 0x24 */
    GT2ConnectionCallbacks callbacks;                    /* 0x28 */
    char *initialMessage;                                /* 0x38 */
    int initialMessageLen;                               /* 0x3C */
    void *data;                                          /* 0x40 */
    struct GTI2Buffer incomingBuffer;                    /* 0x44 */
    struct GTI2Buffer outgoingBuffer;                    /* 0x50 */
    struct DArrayImplementation *incomingBufferMessages; /* 0x5C */
    struct DArrayImplementation *outgoingBufferMessages; /* 0x60 */
    unsigned short serialNumber;                         /* 0x64 */
    unsigned short expectedSerialNumber;                 /* 0x66 */
    char response[32];                                   /* 0x68 */
    unsigned int lastSend;                               /* 0x88 */
    unsigned int challengeTime;                          /* 0x8C */
    int pendingAck;                                      /* 0x90 */
    unsigned int pendingAckTime;                         /* 0x94 */
    struct DArrayImplementation *sendFilters;            /* 0x98 */
    struct DArrayImplementation *receiveFilters;         /* 0x9C */
};

struct GTI2IncomingBufferMessage {
    int start;
    int len;
    int type;
    unsigned short serialNumber;
};

extern int func_02184200();
extern void *func_02184208(struct DArrayImplementation *array, int n);
extern int func_02195EB4(unsigned short SN1, unsigned short SN2);
extern int func_02194DD4(struct GTI2Buffer *buffer);
extern void func_021842D0(struct DArrayImplementation *array, void *newElem, int (*comparator)(void *, void *));
extern void func_02194E2C(struct GTI2Buffer *buffer, unsigned char *data, int len);
extern int func_02197AD8(struct GTI2Connection *connection, unsigned short SNMin, unsigned short SNMax);
extern int func_02196658(void *elem1, void *elem2);

int func_0219666C(struct GTI2Connection *connection, int type, unsigned short SN,
                  unsigned char *message, int len, int *overflow)
{
    struct GTI2IncomingBufferMessage messageInfo;
    struct GTI2IncomingBufferMessage *bufferedMessage;
    int num;
    int i;
    struct GTI2IncomingBufferMessage *msg;
    struct GTI2IncomingBufferMessage *prev;
    unsigned short diff;

    num = func_02184200(connection->incomingBufferMessages);
    for (i = 0; i < num; i++) {
        bufferedMessage = (struct GTI2IncomingBufferMessage *)func_02184208(connection->incomingBufferMessages, i);
        if (bufferedMessage->serialNumber == SN) {
            *overflow = 0;
            return 1;
        }
        if (func_02195EB4(bufferedMessage->serialNumber, SN) > 0)
            break;
    }

    if (func_02194DD4(&connection->incomingBuffer) < len) {
        *overflow = 1;
        return 1;
    }

    messageInfo.start = connection->incomingBuffer.len;
    messageInfo.len = len;
    messageInfo.type = type;
    messageInfo.serialNumber = SN;
    func_021842D0(connection->incomingBufferMessages, &messageInfo, func_02196658);

    if (func_02184200(connection->incomingBufferMessages) != num + 1) {
        *overflow = 1;
        return 1;
    }

    func_02194E2C(&connection->incomingBuffer, message, len);

    if (num == 0) {
        if (!func_02197AD8(connection, connection->expectedSerialNumber, (unsigned short)(SN - 1)))
            return 0;
    } else {
        msg = (struct GTI2IncomingBufferMessage *)func_02184208(connection->incomingBufferMessages, num);
        if (msg->serialNumber == SN) {
            prev = (struct GTI2IncomingBufferMessage *)func_02184208(connection->incomingBufferMessages, num - 1);
            diff = (unsigned short)func_02195EB4(SN, prev->serialNumber);
            if (diff > 1) {
                if (!func_02197AD8(connection, (unsigned short)(prev->serialNumber + 1), (unsigned short)(SN - 1)))
                    return 0;
            }
        }
    }

    *overflow = 0;
    return 1;
}
