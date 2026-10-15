/*
 * function: gti2CreateSocket
 * address:  0x02197D94
 * packet:   pkt_ov009_02197D94
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2CreateSocket (libdwcgsgt2.TWL.HYB.a gt2socket.o)
 *
 * symbols:
 *   SocketStartUp  0x0217F25C  arm  ov009
 *   gt2StringToAddress  0x021986C4  arm  ov009
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   func_02184638  0x02184638  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   func_02184144  0x02184144  arm  ov009
 *   func_021846B4  0x021846B4  arm  ov009
 *   func_0217EB18  0x0217EB18  arm  ov009
 *   func_021841B0  0x021841B0  arm  ov009
 *   func_0217EBB0  0x0217EBB0  arm  ov009
 *   closesocket  0x0217EB2C  arm  ov009
 *   func_0217ED0C  0x0217ED0C  arm  ov009
 *   func_02197D1C  0x02197D1C  arm  ov009
 *   func_02197CFC  0x02197CFC  arm  ov009
 *   func_02197D4C  0x02197D4C  arm  ov009
 */

struct HashImplementation;
struct DArrayImplementation;

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
    void (*socketErrorCallback)(struct GTI2Socket *);    /* 0x24 */
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

extern void SocketStartUp(void);
extern int gt2StringToAddress(char *string, unsigned int *ip, unsigned short *port);
extern void *gsimalloc(unsigned long size);
extern void *MSL_C_LIB_MemsetPtr(void *dst, int c, unsigned int n);
extern struct HashImplementation *func_02184638(int elemSize, int nBuckets, int nChains,
                                                int (*hashFn)(void *, int),
                                                int (*compFn)(void *, void *),
                                                void (*freeFn)(void *));
extern void gsifree(void *ptr);
extern struct DArrayImplementation *func_02184144(int elemSize, int numElemsToAllocate,
                                                 void (*elemFreeFn)(void *));
extern void func_021846B4(struct HashImplementation *table);
extern int func_0217EB18(int pf, int type, int protocol);
extern void func_021841B0(struct DArrayImplementation *array);
extern int func_0217EBB0(int sock, void *addr, int len);
extern int closesocket(int sock);
extern int func_0217ED0C(int sock, void *addr, int *len);
extern int func_02197D1C(void *elem1, void *elem2);
extern int func_02197CFC(void *elem, int numBuckets);
extern void func_02197D4C(void *elem);

int gti2CreateSocket(struct GTI2Socket **sock, char *localAddress, int outgoingBufferSize,
                  int incomingBufferSize, void (*callback)(struct GTI2Socket *), int type)
{
    struct SOCSockAddrIn address;
    struct GTI2Socket *socketTemp;
    int rcode;
    unsigned int ip;
    unsigned short port;
    int len;

    SocketStartUp();

    if (!incomingBufferSize)
        incomingBufferSize = 0x10000;
    if (!outgoingBufferSize)
        outgoingBufferSize = 0x10000;

    if (!gt2StringToAddress(localAddress, &ip, &port))
        return 4;

    socketTemp = (struct GTI2Socket *)gsimalloc(sizeof(struct GTI2Socket));
    if (!socketTemp)
        return 1;

    MSL_C_LIB_MemsetPtr(socketTemp, 0, sizeof(struct GTI2Socket));
    socketTemp->socket = -1;
    socketTemp->incomingBufferSize = incomingBufferSize;
    socketTemp->outgoingBufferSize = outgoingBufferSize;
    socketTemp->socketErrorCallback = callback;

    socketTemp->connections = func_02184638(4, 32, 2, func_02197CFC, func_02197D1C, 0);
    if (!socketTemp->connections) {
        gsifree(socketTemp);
        return 1;
    }

    socketTemp->closedConnections = func_02184144(4, 4, func_02197D4C);
    if (!socketTemp->closedConnections) {
        func_021846B4(socketTemp->connections);
        gsifree(socketTemp);
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
        gsifree(socketTemp);
        return 3;
    }

    __builtin__clear(&address, sizeof(address));
    address.family = 2;
    address.addr = ip;
    address.port = (unsigned short)(((port >> 8) & 0xFF) | ((port << 8) & 0xFF00));

    if (type != 3) {
        rcode = func_0217EBB0(socketTemp->socket, &address, sizeof(address));
        if (rcode == -1) {
            closesocket(socketTemp->socket);
            func_021846B4(socketTemp->connections);
            func_021841B0(socketTemp->closedConnections);
            gsifree(socketTemp);
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
