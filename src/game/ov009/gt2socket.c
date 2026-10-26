/*
 * file:     gt2socket.c
 * unit:     yes
 * function: gti2ConnectionHash, gti2ConnectionCompare, gti2ConnectionFree, gti2SocketFindConnection, gti2CreateSocket, gti2CloseSocket, gti2SetConnectAttemptCallback, gti2CreateConnectionObject, gti2NewSocketConnection, gti2FreeSocketConnection, gti2SocketSend, gti2SocketConnectionsThinkMap, gti2SocketConnectionsThink, gti2FreeClosedConnections, gti2SocketError
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
 *   TableNew2  0x02184638  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   ArrayNew  0x02184144  arm  ov009
 *   TableFree  0x021846B4  arm  ov009
 *   socket  0x0217EB18  arm  ov009
 *   ArrayFree  0x021841B0  arm  ov009
 *   bind  0x0217EBB0  arm  ov009
 *   closesocket  0x0217EB2C  arm  ov009
 *   getsockname  0x0217ED0C  arm  ov009
 *   gti2ConnectionCompare  0x02197D1C  arm  ov009
 *   gti2ConnectionHash  0x02197CFC  arm  ov009
 *   gti2ConnectionFree  0x02197D4C  arm  ov009
 *   closesocket     0x0217EB2C  arm  ov009
 *   TableFree       0x021846B4  arm  ov009
 *   ArrayFree       0x021841B0  arm  ov009
 *   gsifree         0x0217EAE0  arm  ov009
 *   SocketShutDown  0x0217F260  arm  ov009
 *   gti2SocketFindConnection  0x02197D5C  arm  ov009
 *   current_time  0x0217F264  arm  ov009
 *   gti2AllocateBuffer  0x02194DA8  arm  ov009
 *   TableEnter  0x0218474C  arm  ov009
 *   ArrayLength    0x02184200  arm  ov009
 *   ArrayNth       0x02184208  arm  ov009
 *   ArrayDeleteAt  0x0218437C  arm  ov009
 *   TableRemove    0x021847BC  arm  ov009
 *   gti2MessageCheck  0x02198808  arm  ov009
 *   CanSendOnSocket  0x0217EF84  arm  ov009
 *   sendto  0x0217ECA4  arm  ov009
 *   GOAGetLastError  0x0217ED54  arm  ov009
 *   gti2HandleConnectionReset  0x021970BC  arm  ov009
 *   gti2HandleHostUnreachable  0x021971BC  arm  ov009
 *   gti2SocketError  0x021985E4  arm  ov009
 *   gti2DumpCallback  0x02195408  arm  ov009
 *   gti2ConnectionThink        0x02195918  arm  ov009
 *   current_time                    0x0217F264  arm  ov009
 *   TableMapSafe2                   0x021848E4  arm  ov009
 *   gt2CloseAllConnectionsHard  0x02195DE4  arm  ov009
 *   gti2SocketErrorCallback     0x02194EC4  arm  ov009
 */
#include "gt2main_types.h"
extern void *__builtin__clear(void *dest, unsigned long size);

struct HashImplementation;
struct DArrayImplementation;
struct SOCSockAddr;
struct Sock;
GTI2Connection;
#include "../types.h"

#include "../sdk_soc.h"

extern u32 _u32_div_f(u32 a, u32 b);
struct GTI2Connection;
#include "gt2connection.h"
#include "hashtable.h"
#include "gsplatformutil.h"
#include "gt2utility.h"
#include "gsmemory.h"
#include "../arm9/msl_string_mem.h"
#include "darray.h"
#include "gsplatformsocket.h"
extern GTI2Connection *gti2SocketFindConnection(GTI2Socket *socket, unsigned int ip, unsigned short port);
#include "gt2buffer.h"
#include "gt2message.h"
struct GTI2Socket;
#include "gt2callback.h"
#include "gt2main.h"
GTI2Connection *gti2SocketFindConnection(GTI2Socket *socket, u32 ip, u16 port);
int gti2CreateSocket(GTI2Socket **sock, char *localAddress, int outgoingBufferSize, int incomingBufferSize, void (*callback)(GTI2Socket *), int type);
void gti2CloseSocket(GTI2Socket *socket);
void gti2SetConnectAttemptCallback(GTI2Socket *socket, GT2DumpCallback connectAttemptCallback);
void *gti2CreateConnectionObject(void);
int gti2NewSocketConnection(GTI2Socket *socket, GTI2Connection **connection, unsigned int ip, unsigned short port);
void gti2FreeSocketConnection(GTI2Connection *connection);
int gti2SocketSend(GTI2Socket *socket, unsigned int ip, unsigned short port, unsigned char *message, int len);
int gti2SocketConnectionsThink(GTI2Socket *socket);
void gti2FreeClosedConnections(GTI2Socket *socket);
void gti2SocketError(GTI2Socket *socket);

static void gti2ConnectionFree(void * elemArg);

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

static void gti2ConnectionFree(void * elemArg)
{
    void ** elem = (void **)elemArg;
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

    socketTemp->connections = TableNew2(4, 32, 2, gti2ConnectionHash, gti2ConnectionCompare, 0);
    if (!socketTemp->connections) {
        gsifree(socketTemp);
        return 1;
    }

    socketTemp->closedConnections = ArrayNew(4, 4, gti2ConnectionFree);
    if (!socketTemp->closedConnections) {
        TableFree(socketTemp->connections);
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
        TableFree(socketTemp->connections);
        ArrayFree(socketTemp->closedConnections);
        gsifree(socketTemp);
        return 3;
    }

    __builtin__clear(&address, sizeof(address));
    address.family = 2;
    address.addr = ip;
    address.port = (unsigned short)(((port >> 8) & 0xFF) | ((port << 8) & 0xFF00));

    if (type != 3) {
        rcode = bind(socketTemp->socket, (struct SOCSockAddr *)(&address), sizeof(address));
        if (rcode == -1) {
            closesocket(socketTemp->socket);
            TableFree(socketTemp->connections);
            ArrayFree(socketTemp->closedConnections);
            gsifree(socketTemp);
            return 3;
        }
    }

    len = sizeof(address);
    getsockname(socketTemp->socket, (struct SOCSockAddr *)(&address), &len);
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

void gti2SetConnectAttemptCallback(GTI2Socket *socket, GT2DumpCallback connectAttemptCallback)
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

    if (gti2SocketFindConnection(socket, ip, port))
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

    connectionPtr->incomingBufferMessages = ArrayNew(16, 64, 0);
    if (!connectionPtr->incomingBufferMessages)
        goto failed;
    connectionPtr->outgoingBufferMessages = ArrayNew(16, 64, 0);
    if (!connectionPtr->outgoingBufferMessages)
        goto failed;
    connectionPtr->sendFilters = ArrayNew(4, 2, 0);
    if (!connectionPtr->sendFilters)
        goto failed;
    connectionPtr->receiveFilters = ArrayNew(4, 2, 0);
    if (!connectionPtr->receiveFilters)
        goto failed;

    TableEnter(socket->connections, &connectionPtr);

    *connection = gti2SocketFindConnection(socket, ip, port);
    if (*connection)
        return 0;

failed:
    if (connectionPtr) {
        gsifree(connectionPtr->incomingBuffer.buffer);
        gsifree(connectionPtr->outgoingBuffer.buffer);
        if (connectionPtr->incomingBufferMessages)
            ArrayFree(connectionPtr->incomingBufferMessages);
        if (connectionPtr->outgoingBufferMessages)
            ArrayFree(connectionPtr->outgoingBufferMessages);
        if (connectionPtr->sendFilters)
            ArrayFree(connectionPtr->sendFilters);
        if (connectionPtr->receiveFilters)
            ArrayFree(connectionPtr->receiveFilters);
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
        len = ArrayLength((struct DArrayImplementation *)connection->socket->closedConnections);
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

    gti2MessageCheck(&message, &len);

    if (socket->protocolType != 3) {
        if (!CanSendOnSocket(socket->socket))
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
            if (!gti2HandleHostUnreachable((struct GTI2Socket *)socket, ip, port, 1))
                return 0;
        } else {
            if (rcode == -42 || rcode == -6)
                return 1;
            if (rcode != -35) {
                gti2SocketError(socket);
                return 0;
            }
        }
    } else {
        if (socket->sendDumpCallback) {
            if (!gti2DumpCallback(socket, gti2SocketFindConnection(socket, ip, port), ip, port, 0, message, len, 1))
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
    int len = ArrayLength((struct DArrayImplementation *)socket->closedConnections);
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
