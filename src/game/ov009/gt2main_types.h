#ifndef OV009_GT2MAIN_2_TYPES_H
#define OV009_GT2MAIN_2_TYPES_H
/*
 * GameSpy GT2 types (gt2main, gt2connection, gt2socket): the socket and
 * connection objects behind the public gt2 accessors.
 */

struct HashImplementation;
struct DArrayImplementation;
typedef struct GTI2Connection GTI2Connection;
typedef struct GTI2Socket GTI2Socket;

typedef void (*GT2DumpCallback)(GTI2Socket *, GTI2Connection *, unsigned int, unsigned short, int,
                                unsigned char *, int);

typedef struct GTI2Buffer {
    unsigned char *buffer;
    int size;
    int len;
} GTI2Buffer;

typedef struct GT2ConnectionCallbacks {
    int (*connected)(GTI2Connection *, int, unsigned char *, int);
    int (*received)(GTI2Connection *, unsigned char *, int, int);
    void (*closed)(GTI2Connection *, int);
    void (*ping)(GTI2Connection *, int);
} GT2ConnectionCallbacks;

struct GTI2Connection {
    unsigned int ip;                                     /* 0x00 */
    unsigned short port;                                 /* 0x04 */
    GTI2Socket *socket;                                  /* 0x08 */
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
    GT2DumpCallback connectAttemptCallback;              /* 0x20 */
    void (*socketErrorCallback)(GTI2Socket *);          /* 0x24 */
    GT2DumpCallback sendDumpCallback;                    /* 0x28 */
    GT2DumpCallback receiveDumpCallback;                 /* 0x2C */
    void *unrecognizedMessageCallback;                   /* 0x30 */
    void *data;                                          /* 0x34 */
    int outgoingBufferSize;                              /* 0x38 */
    int incomingBufferSize;                              /* 0x3C */
    int protocolType;                                    /* 0x40 */
    int protocolOffset;                                  /* 0x44 */
    int broadcastEnabled;                                /* 0x48 */
};

#endif
