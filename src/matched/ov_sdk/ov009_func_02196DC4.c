/*
 * function: func_02196DC4
 * address:  0x02196DC4
 * packet:   pkt_ov009_02196DC4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2HandleMessage (libdwcgsgt2.TWL.HYB.a gt2message.o)
 *
 * symbols:
 *   func_02197D5C  0x02197D5C  arm  ov009
 *   func_02195408  0x02195408  arm  ov009
 *   func_020923F0  0x020923F0  arm
 *   func_021954F4  0x021954F4  arm  ov009
 *   func_02197BD4  0x02197BD4  arm  ov009
 *   func_021955C0  0x021955C0  arm  ov009
 *   func_02197BB8  0x02197BB8  arm  ov009
 *   func_02196098  0x02196098  arm  ov009
 *   func_02196948  0x02196948  arm  ov009
 *   func_02196D00  0x02196D00  arm  ov009
 *   g_021A5948     0x021A5948  data
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
    char pad00[0x20];
    void *connectAttemptCallback;                        /* 0x20 */
    char pad24[0x08];
    void *dumpCallback;                                  /* 0x2C */
    char pad30[0x10];
    int protocolType;                                    /* 0x40 */
    int protocolOffset;                                  /* 0x44 */
};

extern const char g_021A5948[];

extern struct GTI2Connection *func_02197D5C(struct GTI2Socket *socket, unsigned int ip, unsigned short port);
extern int func_02195408(struct GTI2Socket *socket, struct GTI2Connection *connection, unsigned int ip,
                         unsigned short port, int reset, unsigned char *message, int len, int outgoing);
extern int func_020923F0();
extern int func_021954F4(struct GTI2Socket *socket, unsigned int ip, unsigned short port,
                         unsigned char *message, int len, int *handled);
extern int func_02197BD4(struct GTI2Socket *socket, unsigned int ip, unsigned short port);
extern int func_021955C0(struct GTI2Socket *socket, struct GTI2Connection **connection,
                         unsigned int ip, unsigned short port);
extern int func_02197BB8(struct GTI2Connection *connection);
extern int func_02196098(struct GTI2Connection *connection, unsigned char *message, int len);
extern int func_02196948(struct GTI2Connection *connection, int type, unsigned char *message, int len);
extern int func_02196D00(struct GTI2Connection *connection, int type, unsigned char *message, int len);

int func_02196DC4(struct GTI2Socket *socket, unsigned char *message, int len, unsigned int ip, unsigned short port)
{
    struct GTI2Connection *connection;
    int magicString;
    int result;
    int type;
    int handled;
    int actualLength;
    unsigned char *actualMessage;

    actualLength = len - socket->protocolOffset;
    actualMessage = message + socket->protocolOffset;

    connection = func_02197D5C(socket, ip, port);

    if (socket->dumpCallback) {
        if (!func_02195408(socket, connection, ip, port, 0, message, len, 0))
            return 0;
    }

    magicString = (actualLength > 2) && !func_020923F0(actualMessage, g_021A5948, 2);

    if (!connection) {
        if (!func_021954F4(socket, ip, port, message, len, &handled))
            return 0;
        if (handled)
            return 1;

        if (!magicString || actualMessage[2] != 1) {
            if (!magicString || actualMessage[2] != 0x68) {
                if (!func_02197BD4(socket, ip, port))
                    return 0;
            }
            return 1;
        }
        if (!socket->connectAttemptCallback)
            return 1;
        result = func_021955C0(socket, &connection, ip, port);
        if (result != 0) {
            if (result != 5) {
                if (!func_02197BD4(socket, ip, port))
                    return 0;
            }
            return 1;
        }
    }

    if (connection->state == 7) {
        if (!magicString || actualMessage[2] != 0x68) {
            if (!func_02197BB8(connection))
                return 0;
        }
        return 1;
    }

    if (magicString && actualLength >= 4 && !func_020923F0(actualMessage + 2, g_021A5948, 2)) {
        message[3] = message[1];
        message[2] = message[0];
        message += 2;
        actualMessage += 2;
        len -= 2;
        magicString = 0;
    }

    if (!magicString) {
        if (connection->state < 5) {
            if (!func_021954F4(socket, ip, port, message, len, &handled))
                return 0;
        } else {
            if (!func_02196098(connection, message, len))
                return 0;
        }
        return 1;
    }

    type = actualMessage[2];
    if (type < 8)
        return func_02196948(connection, type, message, len) != 0;
    if (!func_02196D00(connection, type, message, len))
        return 0;
    return 1;
}
