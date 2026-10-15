/*
 * function: gti2NewSocketConnection
 * address:  0x02198038
 * packet:   pkt_ov009_02198038
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2NewSocketConnection (libdwcgsgt2.TWL.HYB.a gt2socket.o)
 *
 * symbols:
 *   func_02197D5C  0x02197D5C  arm  ov009
 *   gti2CreateConnectionObject  0x02198028  arm  ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   current_time  0x0217F264  arm  ov009
 *   gti2AllocateBuffer  0x02194DA8  arm  ov009
 *   func_02184144  0x02184144  arm  ov009
 *   func_0218474C  0x0218474C  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   func_021841B0  0x021841B0  arm  ov009
 */

struct HashImplementation;
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

struct GTI2Socket {
    int socket;                                          /* 0x00 */
    unsigned int ip;                                     /* 0x04 */
    unsigned short port;                                 /* 0x08 */
    struct HashImplementation *connections;              /* 0x0C */
    struct DArrayImplementation *closedConnections;      /* 0x10 */
    int close;                                           /* 0x14 */
    int error;                                           /* 0x18 */
    int callbackLevel;                                   /* 0x1C */
    void *connectAttemptCallback;                        /* 0x20 */
    void *socketErrorCallback;                           /* 0x24 */
    void *sendDumpCallback;                              /* 0x28 */
    void *receiveDumpCallback;                           /* 0x2C */
    void *unrecognizedMessageCallback;                   /* 0x30 */
    void *data;                                          /* 0x34 */
    int outgoingBufferSize;                              /* 0x38 */
    int incomingBufferSize;                              /* 0x3C */
    int protocolType;                                    /* 0x40 */
    int protocolOffset;                                  /* 0x44 */
    int broadcastEnabled;                                /* 0x48 */
};

extern struct GTI2Connection *func_02197D5C(struct GTI2Socket *socket, unsigned int ip, unsigned short port);
extern struct GTI2Connection *gti2CreateConnectionObject(void);
extern void *MSL_C_LIB_MemsetPtr(void *dst, int c, unsigned int n);
extern unsigned int current_time(void);
extern int gti2AllocateBuffer(struct GTI2Buffer *buffer, int size);
extern struct DArrayImplementation *func_02184144(int elemSize, int numElemsToAllocate,
                                                 void (*elemFreeFn)(void *));
extern void func_0218474C(struct HashImplementation *table, void *newElem);
extern void gsifree(void *ptr);
extern void func_021841B0(struct DArrayImplementation *array);

int gti2NewSocketConnection(struct GTI2Socket *socket, struct GTI2Connection **connection, unsigned int ip,
                  unsigned short port)
{
    struct GTI2Connection *connectionPtr = 0;

    if (func_02197D5C(socket, ip, port))
        return 5;

    connectionPtr = gti2CreateConnectionObject();
    if (!connectionPtr)
        goto failed;

    MSL_C_LIB_MemsetPtr(connectionPtr, 0, sizeof(struct GTI2Connection));
    connectionPtr->ip = ip;
    connectionPtr->port = port;
    connectionPtr->socket = socket;
    connectionPtr->startTime = current_time();
    connectionPtr->lastSend = connectionPtr->startTime;
    connectionPtr->serialNumber = 0;
    connectionPtr->expectedSerialNumber = 0;

    if (!gti2AllocateBuffer(&connectionPtr->incomingBuffer, socket->incomingBufferSize))
        goto failed;
    if (!gti2AllocateBuffer(&connectionPtr->outgoingBuffer, socket->outgoingBufferSize))
        goto failed;

    connectionPtr->incomingBufferMessages = func_02184144(16, 64, 0);
    if (!connectionPtr->incomingBufferMessages)
        goto failed;
    connectionPtr->outgoingBufferMessages = func_02184144(16, 64, 0);
    if (!connectionPtr->outgoingBufferMessages)
        goto failed;
    connectionPtr->sendFilters = func_02184144(4, 2, 0);
    if (!connectionPtr->sendFilters)
        goto failed;
    connectionPtr->receiveFilters = func_02184144(4, 2, 0);
    if (!connectionPtr->receiveFilters)
        goto failed;

    func_0218474C(socket->connections, &connectionPtr);

    *connection = func_02197D5C(socket, ip, port);
    if (*connection)
        return 0;

failed:
    if (connectionPtr) {
        gsifree(connectionPtr->incomingBuffer.buffer);
        gsifree(connectionPtr->outgoingBuffer.buffer);
        if (connectionPtr->incomingBufferMessages)
            func_021841B0(connectionPtr->incomingBufferMessages);
        if (connectionPtr->outgoingBufferMessages)
            func_021841B0(connectionPtr->outgoingBufferMessages);
        if (connectionPtr->sendFilters)
            func_021841B0(connectionPtr->sendFilters);
        if (connectionPtr->receiveFilters)
            func_021841B0(connectionPtr->receiveFilters);
        gsifree(connectionPtr);
    }
    return 1;
}
