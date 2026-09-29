/*
 * function: func_02196948
 * address:  0x02196948
 * packet:   pkt_ov009_02196948
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2HandleReliableMessage (libdwcgsgt2.TWL.HYB.a gt2message.o)
 *
 * symbols:
 *   func_02195F5C  0x02195F5C  arm  ov009
 *   func_02195E80  0x02195E80  arm  ov009
 *   func_02195F9C  0x02195F9C  arm  ov009
 *   func_02196920  0x02196920  arm  ov009
 *   func_02196558  0x02196558  arm  ov009
 *   func_021968A0  0x021968A0  arm  ov009
 *   func_02195EB4  0x02195EB4  arm  ov009
 *   func_0219666C  0x0219666C  arm  ov009
 *   func_02195F70  0x02195F70  arm  ov009
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
struct GTI2Socket {
    char pad00[0x40];
    int protocolType;                                    /* 0x40 */
    int protocolOffset;                                  /* 0x44 */
};

extern int func_02195F5C(struct GTI2Connection *connection);
extern unsigned short func_02195E80(unsigned char *buffer, int pos);
extern int func_02195F9C(struct GTI2Connection *connection, unsigned short ESN);
extern void func_02196920(struct GTI2Connection *connection);
extern int func_02196558(struct GTI2Connection *connection, int type, unsigned char *message, int len);
extern int func_021968A0(struct GTI2Connection *connection);
extern int func_02195EB4(unsigned short SN1, unsigned short SN2);
extern int func_0219666C(struct GTI2Connection *connection, int type, unsigned short SN,
                         unsigned char *message, int len, int *overflow);
extern int func_02195F70(struct GTI2Connection *connection);

int func_02196948(struct GTI2Connection *connection, int type, unsigned char *message, int len)
{
    unsigned short SN;
    unsigned short ESN;
    int headerLength;
    int overflow;

    headerLength = connection->socket->protocolOffset + 7;
    if (len < headerLength)
        return func_02195F5C(connection) != 0;

    SN = func_02195E80(message + connection->socket->protocolOffset, 3);
    ESN = func_02195E80(message + connection->socket->protocolOffset, 5);

    if (connection->socket->protocolType == 2 && type == 0) {
        message[connection->socket->protocolOffset + 5] = message[0];
        message[connection->socket->protocolOffset + 6] = message[1];
        message += headerLength - connection->socket->protocolOffset;
        len -= headerLength - connection->socket->protocolOffset;
    } else {
        message += headerLength;
        len -= headerLength;
    }

    if (!func_02195F9C(connection, ESN))
        return 0;

    if (SN == connection->expectedSerialNumber) {
        func_02196920(connection);
        if (!func_02196558(connection, type, message, len))
            return 0;
        if (!func_021968A0(connection))
            return 0;
        return 1;
    }

    if (func_02195EB4(SN, connection->expectedSerialNumber) < 0) {
        func_02196920(connection);
        return 1;
    }

    if (!func_0219666C(connection, type, SN, message, len, &overflow))
        return 0;
    if (overflow) {
        if (!func_02195F70(connection))
            return 0;
    }
    return 1;
}
