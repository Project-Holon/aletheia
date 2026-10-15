/*
 * function: gti2SocketSend
 * address:  0x02198328
 * packet:   pkt_ov009_02198328
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2SocketSend (libdwcgsgt2.TWL.HYB.a gt2socket.o)
 *
 * symbols:
 *   func_02198808  0x02198808  arm  ov009
 *   func_0217EF84  0x0217EF84  arm  ov009
 *   sendto  0x0217ECA4  arm  ov009
 *   GOAGetLastError  0x0217ED54  arm  ov009
 *   gti2HandleConnectionReset  0x021970BC  arm  ov009
 *   gti2HandleHostUnreachable  0x021971BC  arm  ov009
 *   func_021985E4  0x021985E4  arm  ov009
 *   func_02197D5C  0x02197D5C  arm  ov009
 *   gti2DumpCallback  0x02195408  arm  ov009
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

struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
};

extern void func_02198808(unsigned char **message, int *len);
extern int func_0217EF84(int sock);
struct SOCSockAddr;
struct Sock;
extern int sendto(int sock, char *buf, int len, int flags, struct SOCSockAddr *addr, int tolen);
extern int GOAGetLastError(int sock);
extern int gti2HandleConnectionReset(struct GTI2Socket *socket, unsigned int ip, unsigned short port);
extern int gti2HandleHostUnreachable(struct Sock *sock, unsigned int ip, unsigned short port, int send);
extern void func_021985E4(struct GTI2Socket *socket);
extern struct GTI2Connection *func_02197D5C(struct GTI2Socket *socket, unsigned int ip, unsigned short port);
extern int gti2DumpCallback(struct GTI2Socket *socket, struct GTI2Connection *connection, unsigned int ip,
                         unsigned short port, int reset, unsigned char *message, int len, int outgoing);

int gti2SocketSend(struct GTI2Socket *socket, unsigned int ip, unsigned short port, unsigned char *message, int len)
{
    int rcode;

    func_02198808(&message, &len);

    if (socket->protocolType != 3) {
        if (!func_0217EF84(socket->socket))
            return 1;
    }

    {
        struct SOCSockAddrIn address = {0};

        address.family = 2;
        address.addr = ip;
        address.port = (unsigned short)(((port >> 8) & 0xFF) | ((port << 8) & 0xFF00));

        rcode = sendto(socket->socket, (char *)message, len, 0, (struct SOCSockAddr *)(&address), sizeof(address));
    }
    if (rcode == -1) {
        rcode = GOAGetLastError(socket->socket);
        if (rcode == -15) {
            if (!gti2HandleConnectionReset(socket, ip, port))
                return 0;
        } else if (rcode == -23) {
            if (!gti2HandleHostUnreachable((struct Sock *)socket, ip, port, 1))
                return 0;
        } else {
            if (rcode == -42 || rcode == -6)
                return 1;
            if (rcode != -35) {
                func_021985E4(socket);
                return 0;
            }
        }
    } else {
        if (socket->sendDumpCallback) {
            if (!gti2DumpCallback(socket, func_02197D5C(socket, ip, port), ip, port, 0, message, len, 1))
                return 0;
        }
    }
    return 1;
}
