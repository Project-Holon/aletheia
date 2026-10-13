/*
 * file:     gt2socket_1.c
 * unit:     yes
 * function: func_02197CFC, func_02197D1C, func_02197D4C, func_02197D5C, func_02197D94, func_02197FDC
 * address:  0x02197CFC
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
 *   _u32_div_f  0x0209C2B0  arm
 *   gti2ConnectionCleanup        0x02195A30  arm
 *   TableLookup  0x0218482C  arm  ov009
 *   SocketStartUp  0x0217F25C  arm  ov009
 *   func_021986C4  0x021986C4  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_020923B0  0x020923B0  arm
 *   func_02184638  0x02184638  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_02184144  0x02184144  arm  ov009
 *   func_021846B4  0x021846B4  arm  ov009
 *   func_0217EB18  0x0217EB18  arm  ov009
 *   func_021841B0  0x021841B0  arm  ov009
 *   func_0217EBB0  0x0217EBB0  arm  ov009
 *   func_0217EB2C  0x0217EB2C  arm  ov009
 *   func_0217ED0C  0x0217ED0C  arm  ov009
 *   func_02197D1C  0x02197D1C  arm  ov009
 *   func_02197CFC  0x02197CFC  arm  ov009
 *   func_02197D4C  0x02197D4C  arm  ov009
 *   closesocket     0x0217EB2C  arm  ov009
 *   TableFree       0x021846B4  arm  ov009
 *   ArrayFree       0x021841B0  arm  ov009
 *   gsifree         0x0217EAE0  arm  ov009
 *   SocketShutDown  0x0217F260  arm  ov009
 */
struct HashImplementation;
struct DArrayImplementation;
typedef unsigned short u16;

typedef unsigned int u32;

struct GTI2Connection_02197CFC {
    u32 ip;
    u16 port;
};

struct GTI2Connection_02197D1C {
    u32 ip;
    u16 port;
};

struct GTI2Connection_02197D5C {
    u32 ip;
    u16 port;
    char _pad[0xa0 - 6];
};

struct GTI2Socket_02197D5C {
    char _pad0[0xc];
    struct HashImplementation *connections;
};

struct GTI2Socket_02197D94 {
    int socket;                                          /* 0x00 */
    unsigned int ip;                                     /* 0x04 */
    unsigned short port;                                 /* 0x08 */
    struct HashImplementation *connections;              /* 0x0C */
    struct DArrayImplementation *closedConnections;      /* 0x10 */
    int close;                                           /* 0x14 */
    int error;                                           /* 0x18 */
    int callbackLevel;                                   /* 0x1C */
    void *connectAttemptCallback;                        /* 0x20 */
    void (*socketErrorCallback)(struct GTI2Socket_02197D94 *);    /* 0x24 */
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

struct GTI2Socket_02197FDC {
    int socket;
    unsigned int ip;
    unsigned short port;
    struct HashImplementation *connections;
    struct DArrayImplementation *closedConnections;
    int close;
    int error;
    int callbackLevel;
};

extern u32 _u32_div_f(u32 a, u32 b);
extern void gti2ConnectionCleanup(void *connection);
extern void *TableLookup(struct HashImplementation *table, void *elemKey);
extern void SocketStartUp(void);
extern int func_021986C4(char *string, unsigned int *ip, unsigned short *port);
extern void *func_0217EAB0(unsigned long size);
extern void *func_020923B0(void *dst, int c, unsigned int n);
extern struct HashImplementation *func_02184638(int elemSize, int nBuckets, int nChains,
                                                int (*hashFn)(void *, int),
                                                int (*compFn)(void *, void *),
                                                void (*freeFn)(void *));
extern void func_0217EAE0(void *ptr);
extern struct DArrayImplementation *func_02184144(int elemSize, int numElemsToAllocate,
                                                 void (*elemFreeFn)(void *));
extern void func_021846B4(struct HashImplementation *table);
extern int func_0217EB18(int pf, int type, int protocol);
extern void func_021841B0(struct DArrayImplementation *array);
extern int func_0217EBB0(int sock, void *addr, int len);
extern int func_0217EB2C(int sock);
extern int func_0217ED0C(int sock, void *addr, int *len);
extern int func_02197D1C(void *elem1, void *elem2);
extern int func_02197CFC(void *elem, int numBuckets);
extern void func_02197D4C(void *elem);
extern int closesocket(int sock);
extern void TableFree(struct HashImplementation *table);
extern void ArrayFree(struct DArrayImplementation *array);
extern void gsifree(void *ptr);
extern void SocketShutDown(void);
static void gti2ConnectionFree(void **elem);
struct GTI2Connection_02197D5C *gti2SocketFindConnection(struct GTI2Socket_02197D5C *socket, u32 ip, u16 port);
int func_02197D94(struct GTI2Socket_02197D94 **sock, char *localAddress, int outgoingBufferSize, int incomingBufferSize, void (*callback)(struct GTI2Socket_02197D94 *), int type);
void gti2CloseSocket(struct GTI2Socket_02197FDC *socket);


static int gti2ConnectionHash(void *elem, int numBuckets)
{
    struct GTI2Connection_02197CFC *connection = *(struct GTI2Connection_02197CFC **)elem;

    return (connection->ip * connection->port) % (u32)numBuckets;
}


static int gti2ConnectionCompare(void *elem1, void *elem2)
{
    struct GTI2Connection_02197D1C *connection1 = *(struct GTI2Connection_02197D1C **)elem1;
    struct GTI2Connection_02197D1C *connection2 = *(struct GTI2Connection_02197D1C **)elem2;

    return connection1->ip != connection2->ip
        ? connection1->ip - connection2->ip
        : (short)(connection1->port - connection2->port);
}

static void gti2ConnectionFree(void **elem)
{
    gti2ConnectionCleanup(*elem);
}


struct GTI2Connection_02197D5C *gti2SocketFindConnection(struct GTI2Socket_02197D5C *socket,
                                                u32 ip, u16 port)
{
    struct GTI2Connection_02197D5C connection;
    struct GTI2Connection_02197D5C *connectionPtr;
    struct GTI2Connection_02197D5C **result;

    connection.ip = ip;
    connection.port = port;
    connectionPtr = &connection;
    result = (struct GTI2Connection_02197D5C **)TableLookup(socket->connections,
                                                   &connectionPtr);
    if (result != 0)
        return *result;
    return 0;
}


/*
 * sdk:      gti2CreateSocket (libdwcgsgt2.TWL.HYB.a gt2socket.o)
 */
int func_02197D94(struct GTI2Socket_02197D94 **sock, char *localAddress, int outgoingBufferSize,
                  int incomingBufferSize, void (*callback)(struct GTI2Socket_02197D94 *), int type)
{
    struct SOCSockAddrIn address;
    struct GTI2Socket_02197D94 *socketTemp;
    int rcode;
    unsigned int ip;
    unsigned short port;
    int len;

    SocketStartUp();

    if (!incomingBufferSize)
        incomingBufferSize = 0x10000;
    if (!outgoingBufferSize)
        outgoingBufferSize = 0x10000;

    if (!func_021986C4(localAddress, &ip, &port))
        return 4;

    socketTemp = (struct GTI2Socket_02197D94 *)func_0217EAB0(sizeof(struct GTI2Socket_02197D94));
    if (!socketTemp)
        return 1;

    func_020923B0(socketTemp, 0, sizeof(struct GTI2Socket_02197D94));
    socketTemp->socket = -1;
    socketTemp->incomingBufferSize = incomingBufferSize;
    socketTemp->outgoingBufferSize = outgoingBufferSize;
    socketTemp->socketErrorCallback = callback;

    socketTemp->connections = func_02184638(4, 32, 2, func_02197CFC, func_02197D1C, 0);
    if (!socketTemp->connections) {
        func_0217EAE0(socketTemp);
        return 1;
    }

    socketTemp->closedConnections = func_02184144(4, 4, func_02197D4C);
    if (!socketTemp->closedConnections) {
        func_021846B4(socketTemp->connections);
        func_0217EAE0(socketTemp);
        return 1;
    }

    socketTemp->socket = func_0217EB18(2, 2, 0);
    socketTemp->protocolType = type;
    if (type == 3)
        socketTemp->protocolOffset = 0;
    else
        socketTemp->protocolOffset = type;

    if (socketTemp->socket == -1) {
        func_021846B4(socketTemp->connections);
        func_021841B0(socketTemp->closedConnections);
        func_0217EAE0(socketTemp);
        return 3;
    }

    __builtin__clear(&address, sizeof(address));
    address.family = 2;
    address.addr = ip;
    address.port = (unsigned short)(((port >> 8) & 0xFF) | ((port << 8) & 0xFF00));

    if (type != 3) {
        rcode = func_0217EBB0(socketTemp->socket, &address, sizeof(address));
        if (rcode == -1) {
            func_0217EB2C(socketTemp->socket);
            func_021846B4(socketTemp->connections);
            func_021841B0(socketTemp->closedConnections);
            func_0217EAE0(socketTemp);
            return 3;
        }
    }

    len = sizeof(address);
    func_0217ED0C(socketTemp->socket, &address, &len);
    socketTemp->ip = address.addr;
    socketTemp->port = (unsigned short)(((address.port >> 8) & 0xFF) | ((address.port << 8) & 0xFF00));

    *sock = socketTemp;
    return 0;
}


void gti2CloseSocket(struct GTI2Socket_02197FDC *socket)
{
    if (socket->callbackLevel != 0)
    {
        socket->close = 1;
        return;
    }
    closesocket(socket->socket);
    TableFree(socket->connections);
    ArrayFree(socket->closedConnections);
    gsifree(socket);
    SocketShutDown();
}
