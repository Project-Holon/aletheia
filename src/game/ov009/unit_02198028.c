/*
 * file:     unit_02198028.c
 * unit:     yes
 * function: func_02198028, func_02198038, func_02198264, func_02198328, func_02198518, func_02198570, func_021985AC, func_021985E4
 * address:  0x02198028
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
 *   func_0217EAB0  0x0217EAB0  arm
 *   func_02197D5C  0x02197D5C  arm  ov009
 *   func_020923B0  0x020923B0  arm
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_02194DA8  0x02194DA8  arm  ov009
 *   func_02184144  0x02184144  arm  ov009
 *   func_0218474C  0x0218474C  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_021841B0  0x021841B0  arm  ov009
 *   ArrayLength    0x02184200  arm  ov009
 *   ArrayNth       0x02184208  arm  ov009
 *   ArrayDeleteAt  0x0218437C  arm  ov009
 *   TableRemove    0x021847BC  arm  ov009
 *   func_02198808  0x02198808  arm  ov009
 *   func_0217EF84  0x0217EF84  arm  ov009
 *   func_0217ECA4  0x0217ECA4  arm  ov009
 *   func_0217ED54  0x0217ED54  arm  ov009
 *   func_021970BC  0x021970BC  arm  ov009
 *   func_021971BC  0x021971BC  arm  ov009
 *   func_021985E4  0x021985E4  arm  ov009
 *   func_02195408  0x02195408  arm  ov009
 *   gti2ConnectionThink        0x02195918  arm  ov009
 *   current_time                    0x0217F264  arm  ov009
 *   TableMapSafe2                   0x021848E4  arm  ov009
 *   gt2CloseAllConnectionsHard  0x02195DE4  arm  ov009
 *   gti2SocketErrorCallback     0x02194EC4  arm  ov009
 *   gti2CloseSocket             0x02197FDC  arm  ov009
 */
struct HashImplementation;
struct DArrayImplementation;
struct SOCSockAddr;
struct Sock;
struct GTI2Connection;
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

struct GTI2IncomingBufferMessage {
    int start;
    int len;
    int type;
    unsigned short serialNumber;
};

struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
};

extern void *func_0217EAB0(int v);
extern struct GTI2Connection *func_02197D5C(struct GTI2Socket *socket, unsigned int ip, unsigned short port);
extern void *func_020923B0(void *dst, int c, unsigned int n);
extern unsigned int func_0217F264(void);
extern int func_02194DA8(struct GTI2Buffer *buffer, int size);
extern struct DArrayImplementation *func_02184144(int elemSize, int numElemsToAllocate,
                                                 void (*elemFreeFn)(void *));
extern void func_0218474C(struct HashImplementation *table, void *newElem);
extern void func_0217EAE0(void *ptr);
extern void func_021841B0(struct DArrayImplementation *array);
extern int ArrayLength(struct DArrayImplementation *array);
extern void *ArrayNth(struct DArrayImplementation *array, int n);
extern void ArrayDeleteAt(struct DArrayImplementation *array, int n);
extern int TableRemove(struct HashImplementation *table, void *delElem);
extern void func_02198808(unsigned char **message, int *len);
extern int func_0217EF84(int sock);
extern int func_0217ECA4(int sock, char *buf, int len, int flags, struct SOCSockAddr *addr, int tolen);
extern int func_0217ED54(int sock);
extern int func_021970BC(struct GTI2Socket *socket, unsigned int ip, unsigned short port);
extern int func_021971BC(struct Sock *sock, unsigned int ip, unsigned short port, int send);
extern void func_021985E4(struct GTI2Socket *socket);
extern int func_02195408(struct GTI2Socket *socket, struct GTI2Connection *connection, unsigned int ip,
                         unsigned short port, int reset, unsigned char *message, int len, int outgoing);
extern int gti2ConnectionThink(struct GTI2Connection *connection,
                               unsigned int now);
extern unsigned int current_time(void);
extern int TableMapSafe2(struct HashImplementation *table,
                         int (*fn)(void *, void *), void *data);
extern void gt2CloseAllConnectionsHard(struct GTI2Socket *socket);
extern int gti2SocketErrorCallback(struct GTI2Socket *socket);
extern void gti2CloseSocket(struct GTI2Socket *socket);
void *func_02198028(void);
int func_02198038(struct GTI2Socket *socket, struct GTI2Connection **connection, unsigned int ip, unsigned short port);
void gti2FreeSocketConnection(struct GTI2Connection *connection);
/* * sdk: gti2SocketSend (libdwcgsgt2.TWL.HYB.a gt2socket.o) */ int func_02198328(struct GTI2Socket *socket, unsigned int ip, unsigned short port, unsigned char *message, int len);
int gti2SocketConnectionsThink(struct GTI2Socket *socket);
void gti2FreeClosedConnections(struct GTI2Socket *socket);
void gti2SocketError(struct GTI2Socket *socket);


/*
 * Tail call with a constant 0xa0 argument.
 */
void *func_02198028(void)
{
    return func_0217EAB0(0xa0);
}




/*
 * sdk:      gti2NewSocketConnection (libdwcgsgt2.TWL.HYB.a gt2socket.o)
 */
int func_02198038(struct GTI2Socket *socket, struct GTI2Connection **connection, unsigned int ip,
                  unsigned short port)
{
    struct GTI2Connection *connectionPtr = 0;

    if (func_02197D5C(socket, ip, port))
        return 5;

    connectionPtr = func_02198028();
    if (!connectionPtr)
        goto failed;

    func_020923B0(connectionPtr, 0, sizeof(struct GTI2Connection));
    connectionPtr->ip = ip;
    connectionPtr->port = port;
    connectionPtr->socket = socket;
    connectionPtr->startTime = func_0217F264();
    connectionPtr->lastSend = connectionPtr->startTime;
    connectionPtr->serialNumber = 0;
    connectionPtr->expectedSerialNumber = 0;

    if (!func_02194DA8(&connectionPtr->incomingBuffer, socket->incomingBufferSize))
        goto failed;
    if (!func_02194DA8(&connectionPtr->outgoingBuffer, socket->outgoingBufferSize))
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
        func_0217EAE0(connectionPtr->incomingBuffer.buffer);
        func_0217EAE0(connectionPtr->outgoingBuffer.buffer);
        if (connectionPtr->incomingBufferMessages)
            func_021841B0(connectionPtr->incomingBufferMessages);
        if (connectionPtr->outgoingBufferMessages)
            func_021841B0(connectionPtr->outgoingBufferMessages);
        if (connectionPtr->sendFilters)
            func_021841B0(connectionPtr->sendFilters);
        if (connectionPtr->receiveFilters)
            func_021841B0(connectionPtr->receiveFilters);
        func_0217EAE0(connectionPtr);
    }
    return 1;
}





void gti2FreeSocketConnection(struct GTI2Connection *connection)
{
    int len;
    int i;

    if (connection->freeAtAcceptReject != 0 || connection->callbackLevel != 0)
        return;
    if (connection->state == 7)
    {
        len = ArrayLength(connection->socket->closedConnections);
        for (i = 0; i < len; i++)
        {
            if (connection == *(struct GTI2Connection **)ArrayNth(
                    connection->socket->closedConnections, i))
            {
                ArrayDeleteAt(connection->socket->closedConnections, i);
                return;
            }
        }
    }
    else
    {
        TableRemove(connection->socket->connections, &connection);
    }
}





/*
 * sdk:      gti2SocketSend (libdwcgsgt2.TWL.HYB.a gt2socket.o)
 */
int func_02198328(struct GTI2Socket *socket, unsigned int ip, unsigned short port, unsigned char *message, int len)
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

        rcode = func_0217ECA4(socket->socket, (char *)message, len, 0, (struct SOCSockAddr *)(&address), sizeof(address));
    }
    if (rcode == -1) {
        rcode = func_0217ED54(socket->socket);
        if (rcode == -15) {
            if (!func_021970BC(socket, ip, port))
                return 0;
        } else if (rcode == -23) {
            if (!func_021971BC((struct Sock *)socket, ip, port, 1))
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
            if (!func_02195408(socket, func_02197D5C(socket, ip, port), ip, port, 0, message, len, 1))
                return 0;
        }
    }
    return 1;
}




static int gti2SocketConnectionsThinkMap(void *elem, void *clientData)
{
    struct GTI2Connection *connection = *(struct GTI2Connection **)elem;
    unsigned int now = *(unsigned int *)clientData;

    if (connection->state != 7)
    {
        if (gti2ConnectionThink(connection, now) == 0)
            return 0;
    }
    if (connection->state == 7 && connection->freeAtAcceptReject == 0
        && connection->callbackLevel == 0)
        gti2FreeSocketConnection(connection);
    return 1;
}




int gti2SocketConnectionsThink(struct GTI2Socket *socket)
{
    unsigned int now = current_time();

    if (TableMapSafe2(socket->connections, gti2SocketConnectionsThinkMap, &now))
        return 0;
    return 1;
}




void gti2FreeClosedConnections(struct GTI2Socket *socket)
{
    int len = ArrayLength(socket->closedConnections);
    int i;

    for (i = len - 1; i >= 0; i--)
        gti2FreeSocketConnection(*(struct GTI2Connection **)
                                     ArrayNth(socket->closedConnections, i));
}




void gti2SocketError(struct GTI2Socket *socket)
{
    if (socket->error != 0)
        return;
    socket->error = 1;
    gt2CloseAllConnectionsHard(socket);
    if (gti2SocketErrorCallback(socket))
        gti2CloseSocket(socket);
}
