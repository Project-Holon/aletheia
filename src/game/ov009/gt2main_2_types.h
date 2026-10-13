#ifndef OV009_GT2MAIN_2_TYPES_H
#define OV009_GT2MAIN_2_TYPES_H
/*
 * GameSpy GT2 types (gt2main, gt2connection, gt2socket): the socket and
 * connection objects behind the public gt2 accessors.
 */

struct HashImplementation;
struct DArrayImplementation;
struct GTI2Connection;
struct GTI2Socket;

typedef struct GTI2Buffer {
    unsigned char *buffer;
    int size;
    int len;
} GTI2Buffer;

typedef struct GT2ConnectionCallbacks {
    void *connected;
    void *received;
    void *closed;
    void *ping;
} GT2ConnectionCallbacks;

typedef struct GTI2Connection {
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
    GTI2Buffer incomingBuffer;                           /* 0x44 */
    GTI2Buffer outgoingBuffer;                           /* 0x50 */
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
} GTI2Connection;

typedef struct GTI2Socket {
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
} GTI2Socket;

#endif
