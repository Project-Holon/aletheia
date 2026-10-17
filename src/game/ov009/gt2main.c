/*
 * file:     gt2main.c
 * unit:     yes
 * function: gt2CreateSocket, gt2CloseSocket, gt2Think, gt2Listen, gt2Accept, gt2Reject, gt2Connect, gt2Send, gt2CloseConnectionHard, gti2CloseAllConnectionsHardMap, gt2CloseAllConnectionsHard, gt2GetConnectionState, gt2GetRemoteIP, gt2GetRemotePort, gt2GetLocalIP, gt2GetLocalPort, gt2GetOutgoingBufferSize, gt2GetOutgoingBufferFreeSpace, gt2GetSocketSOCKET, gt2SetUnrecognizedMessageCallback, gt2SetConnectionData, gt2GetConnectionData
 * address:  0x02195AB4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Difference of the two words at +0x54 and +0x58.
 *
 * symbols:
 *   gti2CreateSocket  0x02197D94  arm  ov009
 *   gti2CloseSocket  0x02197FDC  arm  ov009
 *   gti2ReceiveMessages              0x0219725c arm
 *   gti2SocketConnectionsThink       0x02198570 arm
 *   gti2FreeClosedConnections        0x021985ac arm
 *   gti2SetConnectAttemptCallback  0x02198020  arm
 *   gt2StringToAddress          0x021986C4  arm  ov009
 *   gti2NewOutgoingConnection   0x02195590  arm  ov009
 *   gti2StartConnectionAttempt  0x021955F0  arm  ov009
 *   gti2FreeSocketConnection    0x02198264  arm  ov009
 *   msleep                      0x0217F2BC  arm  ov009
 *   gti2MessageCheck        0x02198808 arm
 *   ArrayLength             0x02184200 arm
 *   gti2SendFilterCallback  0x02195278 arm
 *   gti2Send                0x02197CE0 arm
 *   gti2CloseConnection  0x02195980  arm  ov009
 *   gt2CloseConnectionHard       0x02195DC4  arm  ov009
 *   TableMapSafe  0x0218489C  arm  ov009
 *   gti2AcceptConnection  0x0219569C  arm
 *   gti2RejectConnection  0x021956F8  arm
 */
#include "gt2main_types.h"

struct GTI2Socket;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int gti2CreateSocket(void **sock, char *addr, int outSize, int inSize, void *callback, int type);
extern void gti2CloseSocket(void *p);
extern int gti2ReceiveMessages(struct GTI2Socket *socket);
extern int gti2SocketConnectionsThink(struct GTI2Socket *socket);
extern void gti2FreeClosedConnections(struct GTI2Socket *socket);
extern void gti2SetConnectAttemptCallback(GTI2Socket *socket, void *connectAttemptCallback);
extern int gti2AcceptConnection(GTI2Connection *connection, GT2ConnectionCallbacks *callbacks);
extern void gti2RejectConnection(void);
extern int gt2StringToAddress();
extern int gti2NewOutgoingConnection();
extern int gti2StartConnectionAttempt();
extern void gti2FreeSocketConnection();
extern void msleep();
extern void gti2MessageCheck(unsigned char **message, int *len);
extern int ArrayLength(void *array);
extern int gti2SendFilterCallback(void *connection, int filterID,
    unsigned char *message, int len, int reliable);
extern int gti2Send(void *connection, unsigned char *message, int len, int reliable);
extern void gti2CloseConnection(int a, int b);
extern void TableMapSafe(int a, char *p, int c);
int gt2CreateSocket(void **sock, char *addr, int outSize, int inSize, void *callback);
void gt2CloseSocket(void *p);
void gt2Think(struct GTI2Socket *socket);
void gt2Listen(GTI2Socket *socket, void *connectAttemptCallback);
int gt2Accept(GTI2Connection *connection, GT2ConnectionCallbacks *callbacks);
void gt2Reject(void);
int gt2Connect(void *socket, GTI2Connection **connection, char *remoteAddress, u8 *message, int len, int timeout, void *callbacks, int blocking);
int gt2Send(void *connection, unsigned char *message, int len, int reliable);
void gt2CloseConnectionHard(int a);
void gt2CloseAllConnectionsHard(int *p);
int gt2GetConnectionState(const int *p);
unsigned int gt2GetRemoteIP(const GTI2Connection *connection);
unsigned short gt2GetRemotePort(const GTI2Connection *connection);
unsigned int gt2GetLocalIP(const GTI2Socket *socket);
unsigned short gt2GetLocalPort(const GTI2Socket *socket);
int gt2GetOutgoingBufferSize(const GTI2Connection *connection);
int gt2GetOutgoingBufferFreeSpace(const int *p);
int gt2GetSocketSOCKET(const GTI2Socket *socket);
void gt2SetUnrecognizedMessageCallback(GTI2Socket *socket, void *callback);
void gt2SetConnectionData(GTI2Connection *connection, void *data);
void *gt2GetConnectionData(const GTI2Connection *connection);



/*
 * sdk:      gt2CreateSocket (libdwcgsgt2.TWL.HYB.a(gt2main.o))
 */
int gt2CreateSocket(void **sock, char *addr, int outSize, int inSize, void *callback)
{
	return gti2CreateSocket(sock, addr, outSize, inSize, callback, 0);
}



/*
 * Calls the two helpers on the argument.
 */
void gt2CloseSocket(void *p)
{
    gt2CloseAllConnectionsHard(p);
    gti2CloseSocket(p);
}



void gt2Think(struct GTI2Socket *socket)
{
    if (gti2ReceiveMessages(socket) == 0)
        return;
    if (gti2SocketConnectionsThink(socket) == 0)
        return;
    gti2FreeClosedConnections(socket);
}



/*
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 *
 * Unblocked by matching the 8-byte ARM leaf at 0x02198020 in ov009 (its
 * listing emits it as a .word run, unlabelled); the ABS32 site now resolves
 * via `matched`.  Packet renamed from pkt_02155168 so this promotion does
 * not rewrite that packet's shard.
 */
void gt2Listen(GTI2Socket *socket, void *connectAttemptCallback)
{
    gti2SetConnectAttemptCallback(socket, connectAttemptCallback);
}



/*
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 */
int gt2Accept(GTI2Connection *connection, GT2ConnectionCallbacks *callbacks)
{
    return gti2AcceptConnection(connection, callbacks);
}



void gt2Reject(void)
{
    gti2RejectConnection();
}

static void gti2CloseAllConnectionsHardMap(void **elem);



/*
 * sdk:      gt2Connect (libdwcgsgt2.TWL.HYB.a(gt2main.o))
 */
int gt2Connect(void *socket, GTI2Connection **connection, char *remoteAddress, u8 *message, int len, int timeout, void *callbacks, int blocking)
{
    GTI2Connection *connectionTemp;
    int result;
    int done;
    u32 ip;
    u16 port;

    if (!gt2StringToAddress(remoteAddress, &ip, &port) || !ip || !port)
        return 4;
    if (((((ip >> 24) & 0xFF) | ((ip >> 8) & 0xFF00) | ((ip << 8) & 0xFF0000) | ((ip << 24) & 0xFF000000)) & 0xE0000000) == 0xE0000000)
        return 4;
    result = gti2NewOutgoingConnection(socket, &connectionTemp, ip, port);
    if (result)
        return result;
    connectionTemp->timeout = timeout;
    result = gti2StartConnectionAttempt(connectionTemp, message, len, callbacks);
    if (result)
    {
        gti2FreeSocketConnection(connectionTemp);
        return result;
    }
    if (!blocking)
    {
        if (connection)
            *connection = connectionTemp;
        return 0;
    }
    connectionTemp->callbackLevel++;
    do
    {
        gt2Think(socket);
        done = connectionTemp->state >= 5;
        if (!done)
            msleep(1);
    } while (!done);
    connectionTemp->callbackLevel--;
    if (connectionTemp->state == 5)
        *connection = connectionTemp;
    return connectionTemp->connectionResult;
}



int gt2Send(void *connection, unsigned char *message, int len, int reliable)
{
    unsigned short vdpDataLength;

    if (*(int *)((char *)connection + 0xc) != 5)
        return 8;
    gti2MessageCheck(&message, &len);
    if (reliable) {
        char *p = *(char **)((char *)connection + 8);

        if (*(int *)(p + 0x40) == 2) {
            unsigned char *b = (unsigned char *)&vdpDataLength;

            b[0] = message[0];
            b[1] = message[1];
            if (len != vdpDataLength + *(int *)(p + 0x44))
                return 9;
        }
    }
    if (ArrayLength(*(void **)((char *)connection + 0x98)) != 0) {
        gti2SendFilterCallback(connection, 0, message, len, reliable);
        return 0;
    }
    return gti2Send(connection, message, len, reliable) ? 0 : 0xa;
}



/*
 * Tail call that supplies the second argument 1.
 */
void gt2CloseConnectionHard(int a)
{
    gti2CloseConnection(a, 1);
}


static void gti2CloseAllConnectionsHardMap(void **elem)
{
    gt2CloseConnectionHard((int)*elem);
}



/*
 * Tail call on the word at +0xc of the object.  The pool word at +0x14 is the
 * address of the ARM function gti2CloseAllConnectionsHardMap (0x02195DD4, EXACT in
 * gti2CloseAllConnectionsHardMap.c), not data: seeded as a function 2026-09-28.
 */
void gt2CloseAllConnectionsHard(int *p)
{
    TableMapSafe(p[3], (char *)gti2CloseAllConnectionsHardMap, 0);
}


/*
 * Maps the word at +0xc onto 0..3.
 */
int gt2GetConnectionState(const int *p)
{
    int v = p[3];

    if (v < 5)
        return 0;
    if (v == 5)
        return 1;
    return v == 6 ? 2 : 3;
}


/*
 * Remote address of a connection.
 */
unsigned int gt2GetRemoteIP(const GTI2Connection *connection)
{
    return connection->ip;
}


/*
 * Remote port of a connection.
 */
unsigned short gt2GetRemotePort(const GTI2Connection *connection)
{
    return connection->port;
}


/*
 * Local address of a socket.
 */
unsigned int gt2GetLocalIP(const GTI2Socket *socket)
{
    return socket->ip;
}


/*
 * Local port of a socket.
 */
unsigned short gt2GetLocalPort(const GTI2Socket *socket)
{
    return socket->port;
}


/*
 * Size of the outgoing buffer of a connection.
 */
int gt2GetOutgoingBufferSize(const GTI2Connection *connection)
{
    return connection->outgoingBuffer.size;
}

int gt2GetOutgoingBufferFreeSpace(const int *p)
{
    return p[0x15] - p[0x16];
}


/*
 * Operating system socket handle behind a socket object.
 */
int gt2GetSocketSOCKET(const GTI2Socket *socket)
{
    return socket->socket;
}


/*
 * Sets the callback for messages that belong to no connection.
 */
void gt2SetUnrecognizedMessageCallback(GTI2Socket *socket, void *callback)
{
    socket->unrecognizedMessageCallback = callback;
}


/*
 * Sets the user data of a connection.
 */
void gt2SetConnectionData(GTI2Connection *connection, void *data)
{
    connection->data = data;
}


/*
 * User data of a connection.
 */
void *gt2GetConnectionData(const GTI2Connection *connection)
{
    return connection->data;
}
