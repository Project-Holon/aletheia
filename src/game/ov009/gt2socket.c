/*
 * file:     gt2socket.c
 * unit:     yes
 * function: func_02197CFC, func_02197D1C, func_02197D4C, func_02197D5C, gti2CreateSocket, func_02197FDC, gti2SetConnectAttemptCallback, gti2CreateConnectionObject, gti2NewSocketConnection, func_02198264, gti2SocketSend, func_02198518, func_02198570, func_021985AC, func_021985E4
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
 *   gt2StringToAddress  0x021986C4  arm  ov009
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   func_02184638  0x02184638  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   func_02184144  0x02184144  arm  ov009
 *   func_021846B4  0x021846B4  arm  ov009
 *   socket  0x0217EB18  arm  ov009
 *   func_021841B0  0x021841B0  arm  ov009
 *   func_0217EBB0  0x0217EBB0  arm  ov009
 *   closesocket  0x0217EB2C  arm  ov009
 *   func_0217ED0C  0x0217ED0C  arm  ov009
 *   func_02197D1C  0x02197D1C  arm  ov009
 *   func_02197CFC  0x02197CFC  arm  ov009
 *   func_02197D4C  0x02197D4C  arm  ov009
 *   closesocket     0x0217EB2C  arm  ov009
 *   TableFree       0x021846B4  arm  ov009
 *   ArrayFree       0x021841B0  arm  ov009
 *   gsifree         0x0217EAE0  arm  ov009
 *   SocketShutDown  0x0217F260  arm  ov009
 *   func_02197D5C  0x02197D5C  arm  ov009
 *   current_time  0x0217F264  arm  ov009
 *   gti2AllocateBuffer  0x02194DA8  arm  ov009
 *   func_0218474C  0x0218474C  arm  ov009
 *   ArrayLength    0x02184200  arm  ov009
 *   ArrayNth       0x02184208  arm  ov009
 *   ArrayDeleteAt  0x0218437C  arm  ov009
 *   TableRemove    0x021847BC  arm  ov009
 *   func_02198808  0x02198808  arm  ov009
 *   func_0217EF84  0x0217EF84  arm  ov009
 *   sendto  0x0217ECA4  arm  ov009
 *   GOAGetLastError  0x0217ED54  arm  ov009
 *   gti2HandleConnectionReset  0x021970BC  arm  ov009
 *   gti2HandleHostUnreachable  0x021971BC  arm  ov009
 *   func_021985E4  0x021985E4  arm  ov009
 *   gti2DumpCallback  0x02195408  arm  ov009
 *   gti2ConnectionThink        0x02195918  arm  ov009
 *   current_time                    0x0217F264  arm  ov009
 *   TableMapSafe2                   0x021848E4  arm  ov009
 *   gt2CloseAllConnectionsHard  0x02195DE4  arm  ov009
 *   gti2SocketErrorCallback     0x02194EC4  arm  ov009
 */
#include "gt2main_types.h"

struct HashImplementation;
struct DArrayImplementation;
struct SOCSockAddr;
struct Sock;
GTI2Connection;
typedef unsigned short u16;

typedef unsigned int u32;

struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
};

struct GTI2IncomingBufferMessage {
    int start;
    int len;
    int type;
    unsigned short serialNumber;
};

extern u32 _u32_div_f(u32 a, u32 b);
extern void gti2ConnectionCleanup(void *connection);
extern void *TableLookup(struct HashImplementation *table, void *elemKey);
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
extern int socket(int pf, int type, int protocol);
extern void func_021841B0(struct DArrayImplementation *array);
extern int func_0217EBB0(int sock, void *addr, int len);
extern int closesocket(int sock);
extern int func_0217ED0C(int sock, void *addr, int *len);
extern int func_02197D1C(void *elem1, void *elem2);
extern int func_02197CFC(void *elem, int numBuckets);
extern void func_02197D4C(void *elem);
extern void TableFree(struct HashImplementation *table);
extern void ArrayFree(struct DArrayImplementation *array);
extern void gsifree(void *ptr);
extern void SocketShutDown(void);
extern GTI2Connection *func_02197D5C(GTI2Socket *socket, unsigned int ip, unsigned short port);
extern unsigned int current_time(void);
extern int gti2AllocateBuffer(GTI2Buffer *buffer, int size);
extern void func_0218474C(struct HashImplementation *table, void *newElem);
extern int ArrayLength(struct DArrayImplementation *array);
extern void *ArrayNth(struct DArrayImplementation *array, int n);
extern void ArrayDeleteAt(struct DArrayImplementation *array, int n);
extern int TableRemove(struct HashImplementation *table, void *delElem);
extern void func_02198808(unsigned char **message, int *len);
extern int func_0217EF84(int sock);
extern int sendto(int sock, char *buf, int len, int flags, struct SOCSockAddr *addr, int tolen);
extern int GOAGetLastError(int sock);
extern int gti2HandleConnectionReset(GTI2Socket *socket, unsigned int ip, unsigned short port);
extern int gti2HandleHostUnreachable(struct Sock *sock, unsigned int ip, unsigned short port, int send);
extern void func_021985E4(GTI2Socket *socket);
extern int gti2DumpCallback(GTI2Socket *socket, GTI2Connection *connection, unsigned int ip,
                         unsigned short port, int reset, unsigned char *message, int len, int outgoing);
extern int gti2ConnectionThink(GTI2Connection *connection,
                               unsigned int now);
extern int TableMapSafe2(struct HashImplementation *table,
                         int (*fn)(void *, void *), void *data);
extern void gt2CloseAllConnectionsHard(GTI2Socket *socket);
extern int gti2SocketErrorCallback(GTI2Socket *socket);
GTI2Connection *gti2SocketFindConnection(GTI2Socket *socket, u32 ip, u16 port);
int gti2CreateSocket(GTI2Socket **sock, char *localAddress, int outgoingBufferSize, int incomingBufferSize, void (*callback)(GTI2Socket *), int type);
void gti2CloseSocket(GTI2Socket *socket);
void gti2SetConnectAttemptCallback(GTI2Socket *socket, void *connectAttemptCallback);
void *gti2CreateConnectionObject(void);
int gti2NewSocketConnection(GTI2Socket *socket, GTI2Connection **connection, unsigned int ip, unsigned short port);
void gti2FreeSocketConnection(GTI2Connection *connection);
int gti2SocketSend(GTI2Socket *socket, unsigned int ip, unsigned short port, unsigned char *message, int len);
int gti2SocketConnectionsThink(GTI2Socket *socket);
void gti2FreeClosedConnections(GTI2Socket *socket);
void gti2SocketError(GTI2Socket *socket);

static void gti2ConnectionFree(void **elem);



static int gti2ConnectionHash(void *elem, int numBuckets)
{
    GTI2Connection *connection = *(GTI2Connection **)elem;

    return (connection->ip * connection->port) % (u32)numBuckets;
}



static int gti2ConnectionCompare(void *elem1, void *elem2)
{
    GTI2Connection *connection1 = *(GTI2Connection **)elem1;
    GTI2Connection *connection2 = *(GTI2Connection **)elem2;

    return connection1->ip != connection2->ip
        ? connection1->ip - connection2->ip
        : (short)(connection1->port - connection2->port);
}


static void gti2ConnectionFree(void **elem)
{
    gti2ConnectionCleanup(*elem);
}



GTI2Connection *gti2SocketFindConnection(GTI2Socket *socket,
                                                u32 ip, u16 port)
{
    GTI2Connection connection;
    GTI2Connection *connectionPtr;
    GTI2Connection **result;

    connection.ip = ip;
    connection.port = port;
    connectionPtr = &connection;
    result = (GTI2Connection **)TableLookup(socket->connections,
                                                   &connectionPtr);
    if (result != 0)
        return *result;
    return 0;
}



/*
 * sdk:      gti2CreateSocket (libdwcgsgt2.TWL.HYB.a gt2socket.o)
 */
int gti2CreateSocket(GTI2Socket **sock, char *localAddress, int outgoingBufferSize,
                  int incomingBufferSize, void (*callback)(GTI2Socket *), int type)
{
    struct SOCSockAddrIn address;
    GTI2Socket *socketTemp;
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

    socketTemp = (GTI2Socket *)gsimalloc(sizeof(GTI2Socket));
    if (!socketTemp)
        return 1;

    MSL_C_LIB_MemsetPtr(socketTemp, 0, sizeof(GTI2Socket));
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

    socketTemp->socket = socket(2, 2, 0);
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



void gti2CloseSocket(GTI2Socket *socket)
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


void gti2SetConnectAttemptCallback(GTI2Socket *socket, void *connectAttemptCallback)
{
    socket->connectAttemptCallback = connectAttemptCallback;
}



/*
 * Tail call with a constant 0xa0 argument.
 */
void *gti2CreateConnectionObject(void)
{
    return gsimalloc(0xa0);
}





/*
 * sdk:      gti2NewSocketConnection (libdwcgsgt2.TWL.HYB.a gt2socket.o)
 */
int gti2NewSocketConnection(GTI2Socket *socket, GTI2Connection **connection, unsigned int ip,
                  unsigned short port)
{
    GTI2Connection *connectionPtr = 0;

    if (func_02197D5C(socket, ip, port))
        return 5;

    connectionPtr = gti2CreateConnectionObject();
    if (!connectionPtr)
        goto failed;

    MSL_C_LIB_MemsetPtr(connectionPtr, 0, sizeof(GTI2Connection));
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






void gti2FreeSocketConnection(GTI2Connection *connection)
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
            if (connection == *(GTI2Connection **)ArrayNth(
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
int gti2SocketSend(GTI2Socket *socket, unsigned int ip, unsigned short port, unsigned char *message, int len)
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





static int gti2SocketConnectionsThinkMap(void *elem, void *clientData)
{
    GTI2Connection *connection = *(GTI2Connection **)elem;
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





int gti2SocketConnectionsThink(GTI2Socket *socket)
{
    unsigned int now = current_time();

    if (TableMapSafe2(socket->connections, gti2SocketConnectionsThinkMap, &now))
        return 0;
    return 1;
}





void gti2FreeClosedConnections(GTI2Socket *socket)
{
    int len = ArrayLength(socket->closedConnections);
    int i;

    for (i = len - 1; i >= 0; i--)
        gti2FreeSocketConnection(*(GTI2Connection **)
                                     ArrayNth(socket->closedConnections, i));
}





void gti2SocketError(GTI2Socket *socket)
{
    if (socket->error != 0)
        return;
    socket->error = 1;
    gt2CloseAllConnectionsHard(socket);
    if (gti2SocketErrorCallback(socket))
        gti2CloseSocket(socket);
}
