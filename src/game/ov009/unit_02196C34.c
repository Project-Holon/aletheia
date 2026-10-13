/*
 * file:     unit_02196C34.c
 * unit:     yes
 * function: func_02196C34, func_02196CC8, func_02196D00, func_02196DC4, func_021970BC, func_021971BC, gti2ReceiveMessages, gti2StoreOutgoingReliableMessageInfo, gti2BeginReliableMessage, gti2EndReliableMessage, gti2SendAppReliable, func_021975FC, func_02197678, func_02197700, gti2SendAccept, gti2SendReject, gti2SendClose, gti2SendKeepAlive, func_02197930, gti2SendAck, func_02197AD8, gti2SendPong, func_02197BB8, func_02197BD4, func_02197C5C, func_02197CE0
 * address:  0x02196C34
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
 *   func_020923F0  0x020923F0  arm
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_021951E8  0x021951E8  arm  ov009
 *   g_021A5940  0x021A5940  data
 *   gti2ConnectionError   0x02195ec4 arm ov009
 *   func_02196AF8  0x02196AF8  arm  ov009
 *   func_02196B48  0x02196B48  arm  ov009
 *   func_02196C28  0x02196C28  arm  ov009
 *   func_02196CC8  0x02196CC8  arm  ov009
 *   func_02197D5C  0x02197D5C  arm  ov009
 *   func_02195408  0x02195408  arm  ov009
 *   func_021954F4  0x021954F4  arm  ov009
 *   func_021955C0  0x021955C0  arm  ov009
 *   func_02196098  0x02196098  arm  ov009
 *   func_02196948  0x02196948  arm  ov009
 *   g_021A5948     0x021A5948  data
 *   gti2SocketFindConnection  0x02197D5C  arm  ov009
 *   gti2DumpCallback          0x02195408  arm  ov009
 *   current_time              0x0217F264  arm  ov009
 *   func_02195EC4  0x02195EC4  arm  ov009
 *   CanReceiveOnSocket               0x0217ef50 arm
 *   recvfrom                         0x0217ec60 arm
 *   GOAGetLastError                  0x0217ed54 arm
 *   gti2HandleConnectionReset        0x021970bc arm
 *   gti2HandleHostUnreachable        0x021971bc arm
 *   gti2SocketError                  0x021985e4 arm
 *   gti2HandleMessage                0x02196dc4 arm
 *   ArrayLength   0x02184200 arm
 *   ArrayAppend   0x02184234 arm
 *   gti2GetBufferFreeSpace              0x02194DD4  arm  ov009
 *   gti2ConnectionMemoryError           0x02195F70  arm  ov009
 *   gti2BufferWriteData                 0x02194E2C  arm  ov009
 *   gti2BufferWriteByte                 0x02194DE4  arm  ov009
 *   gti2BufferWriteUShort               0x02194DFC  arm  ov009
 *   d_021A5948                          0x021A5948  data ov009
 *   ArrayNth               0x02184208 arm
 *   gti2ConnectionSendData 0x02195750 arm
 *   func_02197458  0x02197458  arm  ov009
 *   func_02194E2C  0x02194E2C  arm  ov009
 *   func_0219754C  0x0219754C  arm  ov009
 *   memcmp                    0x020923F0  arm
 *   gti2BufferShorten         0x02194E80  arm  ov009
 *   gti2UShortToBuffer      0x02195EA0 arm
 *   func_02195EA0  0x02195EA0  arm  ov009
 *   func_02195750  0x02195750  arm  ov009
 *   func_02198328  0x02198328  arm  ov009
 *   @14988         0x021A5948  data
 *   func_02197594  0x02197594  arm  ov009
 */
#include "../../matched/arm9_sdk/libc/string.h"

#define SWAP16(x) ((unsigned short)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))
struct DArrayImplementation;
struct HashImplementation;
struct GTI2Connection;
struct GTI2Socket;
typedef struct GTI2Socket GTI2Socket;

typedef struct GTI2Connection GTI2Connection;

typedef short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef void (*DumpCb)(GTI2Socket *, GTI2Connection *, unsigned int, unsigned short, int, unsigned char *, int);

typedef int GT2Bool;

typedef enum { GT2Success, GT2OutOfMemory, GT2Rejected } GT2Result;

typedef enum { GT2LocalClose, GT2RemoteClose } GT2CloseReason;

typedef struct GT2ConnectionCallbacks {
    int (*connected)(GTI2Connection *, int, unsigned char *, int);
    int (*received)(GTI2Connection *, unsigned char *, int, int);
    void (*closed)(GTI2Connection *, int);
    void (*ping)(GTI2Connection *, int);
} GT2ConnectionCallbacks;

struct GTI2Buffer {
    unsigned char *buffer;
    int size;
    int len;
};

struct GTI2Socket {
    int socket;                                      /* 0x00 */
    unsigned int ip;                                 /* 0x04 */
    unsigned short port;                             /* 0x08 */
    struct HashImplementation *connections;          /* 0x0C */
    struct DArrayImplementation *closedConnections;  /* 0x10 */
    int close;                                       /* 0x14 */
    int error;                                       /* 0x18 */
    int callbackLevel;                               /* 0x1C */
    DumpCb connectAttemptCallback;                   /* 0x20 */
    void (*socketErrorCallback)(GTI2Socket *);       /* 0x24 */
    DumpCb sendDump;                                 /* 0x28 */
    DumpCb recvDump;                                 /* 0x2C */
    unsigned char pad30[0x10];                       /* 0x30 */
    int protocolType;                                /* 0x40 */
    int protocolOffset;                              /* 0x44 */
};

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

struct GTI2OutgoingBufferMessage {
    int offset;
    int len;
    unsigned short SN;
    unsigned short pad;
    unsigned int sendTime;
};

typedef struct GTI2Buffer GTI2Buffer;

typedef struct GTI2IncomingBufferMessage GTI2IncomingBufferMessage;

typedef struct GTI2OutgoingBufferMessage GTI2OutgoingBufferMessage;

struct SOCSockAddrIn {
    unsigned char  len;
    unsigned char  family;
    unsigned short port;
    unsigned long  addr;
};

extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern unsigned int func_0217F264(void);
extern int func_021951E8(GTI2Connection *c, int latency);
extern GT2Bool gti2ConnectionError(GTI2Connection *connection, GT2Result result, GT2CloseReason reason);
extern int func_02196AF8(GTI2Connection *c, unsigned char *msg, int len);
extern int func_02196B48(GTI2Connection *c, unsigned char *msg, int len);
extern int func_02196C28(void *connection, unsigned char *message, int len);
extern int func_02196CC8(GTI2Connection *c);
extern GTI2Connection *func_02197D5C(GTI2Socket *socket, unsigned int ip, unsigned short port);
extern int func_02195408(GTI2Socket *socket, GTI2Connection *connection, unsigned int ip,
                         unsigned short port, int reset, unsigned char *message, int len, int outgoing);
extern int func_021954F4(char *p, int a1, int a2, int a3, int a4, int *a5);
extern int func_021955C0(GTI2Socket *socket, GTI2Connection **connection,
                         unsigned int ip, unsigned short port);
extern int func_02196098(GTI2Connection *c, unsigned char *msg, int len);
extern int func_02196948(GTI2Connection *connection, int type, unsigned char *message, int len);
extern GTI2Connection *gti2SocketFindConnection();
extern int gti2DumpCallback();
extern u32 current_time(void);
extern int func_02195EC4(GTI2Connection *c, int result, int reason);
extern int CanReceiveOnSocket(int sock);
extern int recvfrom(int sock, char *buf, int len, int flags,
                    struct SOCSockAddrIn *addr, int *fromlen);
extern int GOAGetLastError(int sock);
extern int gti2HandleConnectionReset(GTI2Socket *socket,
                                     unsigned int ip, unsigned short port);
extern int gti2HandleHostUnreachable(GTI2Socket *socket,
                                     unsigned int ip, unsigned short port,
                                     int send);
extern void gti2SocketError(GTI2Socket *socket);
extern int gti2HandleMessage(GTI2Socket *socket,
                             unsigned char *message, int len,
                             unsigned int ip, unsigned short port);
extern int ArrayLength(struct DArrayImplementation *array);
extern void ArrayAppend(struct DArrayImplementation *array, void *newElem);
extern int gti2GetBufferFreeSpace(GTI2Buffer *buffer);
extern int gti2ConnectionMemoryError(GTI2Connection *connection);
extern void gti2BufferWriteData(GTI2Buffer *buffer,
                                unsigned char *data, int len);
extern void gti2BufferWriteByte(GTI2Buffer *buffer, unsigned char b);
extern void gti2BufferWriteUShort(GTI2Buffer *buffer, unsigned short s);
extern void *ArrayNth(struct DArrayImplementation *array, int n);
extern int gti2ConnectionSendData(GTI2Connection *connection,
                                  unsigned char *message, int len);
extern int func_02197458(GTI2Connection *c, int type, int len, int *overflow);
extern void func_02194E2C(void *buffer, unsigned char *data, int len);
extern int func_0219754C(GTI2Connection *c);
extern int memcmp();
extern void gti2BufferShorten();
extern void gti2UShortToBuffer(unsigned char *buffer, int pos, unsigned short s);
extern void func_02195EA0(unsigned char *buffer, int pos, unsigned short s);
extern int func_02195750(GTI2Connection *c, unsigned char *message, int len);
extern int func_02198328(GTI2Socket *sock, unsigned int ip, unsigned short port, unsigned char *message, int len);
extern void func_02197594(int a, int b, int c);
int func_02196C34(GTI2Connection *c, unsigned char *message, int len);
int func_02196D00(GTI2Connection *c, int type, unsigned char *message, int len);
int func_02196DC4(GTI2Socket *socket, unsigned char *message, int len, unsigned int ip, unsigned short port);
int func_021970BC(GTI2Socket *socket, u32 ip, u16 port);
int func_021971BC(GTI2Socket *sock, unsigned int ip, unsigned short port, int send);
int gti2ReceiveMessages(GTI2Socket *socket);
int gti2SendAppReliable(GTI2Connection * connection, unsigned char * message, int len);
int gti2SendClientChallenge(GTI2Connection * connection, char * challenge);
int func_02197678(GTI2Connection *c, char *response, char *challenge);
int func_02197700(GTI2Connection *c, char *response, char *message, int len);
int gti2SendAccept(GTI2Connection *connection);
int gti2SendReject(GTI2Connection *connection, unsigned char *message, int len);
int gti2SendClose(GTI2Connection *connection);
int gti2SendKeepAlive(GTI2Connection *connection);
int func_02197930(GTI2Connection *connection, u8 *message, int len);
int gti2SendAck(GTI2Connection *connection);
int func_02197AD8(GTI2Connection *connection, unsigned short SNMin, unsigned short SNMax);
int gti2SendPong(GTI2Connection *connection, unsigned char *message, int len);
int func_02197BB8(int *p);
int func_02197BD4(GTI2Socket *sock, unsigned int ip, unsigned short port);
int gti2ResendMessage(GTI2Connection *connection, GTI2OutgoingBufferMessage *message);
void func_02197CE0(int a, int b, int c, int d);
extern unsigned char g_021A5940[];
extern const char g_021A5948[];
extern unsigned char d_021A5948[];











/*
 * sdk:      gti2HandlePong (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02196C34(GTI2Connection *c, unsigned char *message, int len)
{
	unsigned int startTime;
	unsigned char *d;

	if (!c->callbacks.ping)
		return 1;
	if (len != 8)
		return 1;
	if (func_020923F0(message, g_021A5940, 4))
		return 1;
	d = (unsigned char *)&startTime;
	d[0] = message[4];
	d[1] = message[5];
	d[2] = message[6];
	d[3] = message[7];
	if (!func_021951E8((GTI2Connection *)c, func_0217F264() - startTime))
		return 0;
	return 1;
}













static GT2Bool gti2HandleClosed(GTI2Connection *connection)
{
    if (connection->state == 7)
        return 1;
    if (!gti2ConnectionError(connection, GT2Rejected,
                             (connection->state == 6) ? GT2LocalClose : GT2RemoteClose))
        return 0;
    return 1;
}













/*
 * sdk:      gti2HandleUnreliableMessage (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02196D00(GTI2Connection *c, int type, unsigned char *message, int len)
{
	int headerLength;
	unsigned char *dataStart;
	int dataLen;

	headerLength = c->socket->protocolOffset + 3;
	dataStart = message + headerLength;
	dataLen = len - headerLength;
	if (type == 0x64) {
		if (!func_02196AF8((GTI2Connection *)c, dataStart, dataLen))
			return 0;
	} else if (type == 0x65) {
		if (!func_02196B48((GTI2Connection *)c, dataStart, dataLen))
			return 0;
	} else if (type == 0x66) {
		if (!func_02196C28(c, message, len))
			return 0;
	} else if (type == 0x67) {
		if (!func_02196C34((GTI2Connection *)c, dataStart, dataLen))
			return 0;
	} else if (type == 0x68) {
		if (!func_02196CC8((GTI2Connection *)c))
			return 0;
	}
	return 1;
}












/*
 * sdk:      gti2HandleMessage (libdwcgsgt2.TWL.HYB.a gt2message.o)
 */
int func_02196DC4(GTI2Socket *socket, unsigned char *message, int len, unsigned int ip, unsigned short port)
{
    GTI2Connection *connection;
    int magicString;
    int result;
    int type;
    int handled;
    int actualLength;
    unsigned char *actualMessage;

    actualLength = len - socket->protocolOffset;
    actualMessage = message + socket->protocolOffset;

    connection = func_02197D5C(socket, ip, port);

    if (socket->recvDump) {
        if (!func_02195408(socket, connection, ip, port, 0, message, len, 0))
            return 0;
    }

    magicString = (actualLength > 2) && !func_020923F0(actualMessage, (const u8 *)g_021A5948, 2);

    if (!connection) {
        if (!func_021954F4((char *)socket, ip, port, (int)message, len, &handled))
            return 0;
        if (handled)
            return 1;

        if (!magicString || actualMessage[2] != 1) {
            if (!magicString || actualMessage[2] != 0x68) {
                if (!func_02197BD4((GTI2Socket *)socket, ip, port))
                    return 0;
            }
            return 1;
        }
        if (!socket->connectAttemptCallback)
            return 1;
        result = func_021955C0(socket, &connection, ip, port);
        if (result != 0) {
            if (result != 5) {
                if (!func_02197BD4((GTI2Socket *)socket, ip, port))
                    return 0;
            }
            return 1;
        }
    }

    if (connection->state == 7) {
        if (!magicString || actualMessage[2] != 0x68) {
            if (!func_02197BB8((int *)connection))
                return 0;
        }
        return 1;
    }

    if (magicString && actualLength >= 4 && !func_020923F0(actualMessage + 2, (const u8 *)g_021A5948, 2)) {
        message[3] = message[1];
        message[2] = message[0];
        message += 2;
        actualMessage += 2;
        len -= 2;
        magicString = 0;
    }

    if (!magicString) {
        if (connection->state < 5) {
            if (!func_021954F4((char *)socket, ip, port, (int)message, len, &handled))
                return 0;
        } else {
            if (!func_02196098((GTI2Connection *)connection, message, len))
                return 0;
        }
        return 1;
    }

    type = actualMessage[2];
    if (type < 8)
        return func_02196948(connection, type, message, len) != 0;
    if (!func_02196D00((GTI2Connection *)((GTI2Connection *)connection), type, message, len))
        return 0;
    return 1;
}











/*
 * sdk:      gti2HandleConnectionReset (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_021970BC(GTI2Socket *socket, u32 ip, u16 port)
{
    GTI2Connection *connection;

    connection = gti2SocketFindConnection(socket, ip, port);
    if (socket->recvDump)
    {
        if (!gti2DumpCallback(socket, connection, ip, port, 1, 0, 0, 0))
            return 0;
    }
    if (!connection)
        return 1;
    if (connection->state == 0)
    {
        if (!connection->timeout || current_time() - connection->startTime < connection->timeout)
            return 1;
        if (!gti2ConnectionError(connection, 6, 1))
            return 0;
    }
    else
    {
        if (!gti2ConnectionError(connection, 2, 1))
            return 0;
    }
    return 1;
}











/*
 * sdk:      gti2HandleHostUnreachable (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_021971BC(GTI2Socket *sock, unsigned int ip, unsigned short port, int send)
{
	GTI2Connection *c;

	c = func_02197D5C(sock, ip, port);
	if (sock->recvDump) {
		if (!func_02195408(sock, c, ip, port, 1, 0, 0, send))
			return 0;
	}
	if (!c)
		return 1;
	send = 1;
	if (!func_02195EC4(c, 6, send))
		send = 0;
	return send;
}










int gti2ReceiveMessages(GTI2Socket *socket)
{
    char buffer[1500];
    struct SOCSockAddrIn address;
    int addressLen;
    int rcode;

    if (CanReceiveOnSocket(socket->socket) != 0) {
        do {
            addressLen = 8;
            rcode = recvfrom(socket->socket, buffer, 1500, 0, &address,
                             &addressLen);
            if (rcode == -1) {
                int err = GOAGetLastError(socket->socket);
                if (err == -15) {
                    if (gti2HandleConnectionReset(socket, address.addr,
                                                  SWAP16(address.port)) != 0)
                        continue;
                    return 0;
                } else if (err == -23) {
                    if (gti2HandleHostUnreachable(socket, address.addr,
                                                  SWAP16(address.port), 0) != 0)
                        continue;
                    return 0;
                } else {
                    if (err == -35)
                        continue;
                    gti2SocketError(socket);
                    return 0;
                }
            } else {
                if (gti2HandleMessage(socket, (unsigned char *)buffer, rcode,
                                      address.addr, SWAP16(address.port)) == 0)
                    return 0;
            }
        } while (CanReceiveOnSocket(socket->socket) != 0);
    }
    return 1;
}










static int gti2StoreOutgoingReliableMessageInfo(GTI2Connection *connection,
                                                unsigned short SN, int len)
{
    GTI2OutgoingBufferMessage messageInfo = { 0 };
    int num;
    int result = 0;

    messageInfo.offset = connection->outgoingBuffer.len;
    messageInfo.len = len;
    messageInfo.SN = SN;
    messageInfo.sendTime = current_time();
    num = ArrayLength(connection->outgoingBufferMessages);
    ArrayAppend(connection->outgoingBufferMessages, &messageInfo);
    if (ArrayLength(connection->outgoingBufferMessages) == (num + 1))
        result = 1;
    return result;
}









static int gti2BeginReliableMessage(GTI2Connection *connection,
                                    int type, int len, int *overflow)
{
    unsigned short vdpDataLength;
    int freeSpace;

    vdpDataLength = (unsigned short)(len - connection->socket->protocolOffset);
    freeSpace = gti2GetBufferFreeSpace(&connection->outgoingBuffer);
    if (freeSpace < len)
        return (gti2ConnectionMemoryError(connection) == 0) ? 0 : (*overflow = 1);
    if (!gti2StoreOutgoingReliableMessageInfo(connection, connection->serialNumber,
                                              len))
        return (gti2ConnectionMemoryError(connection) == 0) ? 0 : (*overflow = 1);
    if (connection->socket->protocolType == 2)
        gti2BufferWriteData(&connection->outgoingBuffer,
                            (unsigned char *)&vdpDataLength,
                            connection->socket->protocolOffset);
    gti2BufferWriteData(&connection->outgoingBuffer, d_021A5948, 2);
    gti2BufferWriteByte(&connection->outgoingBuffer, (unsigned char)type);
    gti2BufferWriteUShort(&connection->outgoingBuffer, connection->serialNumber++);
    gti2BufferWriteUShort(&connection->outgoingBuffer, connection->expectedSerialNumber);
    *overflow = 0;
    return 1;
}









static int gti2EndReliableMessage(GTI2Connection *connection)
{
    GTI2OutgoingBufferMessage *message;
    int len;

    len = ArrayLength(connection->outgoingBufferMessages);
    message = ArrayNth(connection->outgoingBufferMessages, len - 1);
    if (gti2ConnectionSendData(connection, connection->outgoingBuffer.buffer + message->offset,
                               message->len))
    {
        connection->pendingAck = 0;
        return 1;
    }
    return 0;
}








int gti2SendAppReliable(GTI2Connection * connection, unsigned char * message, int len)
{
    int overflow;

    if (!gti2BeginReliableMessage(connection, 0, len + 7, &overflow))
        return 0;
    if (overflow)
        return 1;
    gti2BufferWriteData(&connection->outgoingBuffer, message, len);
    return gti2EndReliableMessage(connection) != 0;
}









int gti2SendClientChallenge(GTI2Connection * connection, char * challenge)
{
    int overflow;

    if (!gti2BeginReliableMessage(connection, 1, connection->socket->protocolOffset + 0x27, &overflow))
        return 0;
    if (overflow)
        return 1;
    gti2BufferWriteData(&connection->outgoingBuffer, (unsigned char *)challenge, 0x20);
    return gti2EndReliableMessage(connection) != 0;
}









/*
 * sdk:      gti2SendServerChallenge (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02197678(GTI2Connection *c, char *response, char *challenge)
{
	int overflow;

	if (!func_02197458(c, 2, c->socket->protocolOffset + 0x47, &overflow))
		return 0;
	if (overflow)
		return 1;
	func_02194E2C(&c->outgoingBuffer, (unsigned char *)response, 0x20);
	func_02194E2C(&c->outgoingBuffer, (unsigned char *)challenge, 0x20);
	if (!func_0219754C(c))
		return 0;
	c->challengeTime = c->lastSend;
	return 1;
}







int func_02197700(GTI2Connection *c, char *response, char *message, int len)
{
	int overflow;

	if (!func_02197458(c, 3, len + 0x27 + c->socket->protocolOffset, &overflow))
		return 0;
	if (overflow)
		return 1;
	func_02194E2C(&c->outgoingBuffer, (unsigned char *)response, 0x20);
	func_02194E2C(&c->outgoingBuffer, (unsigned char *)message, len);
	return func_0219754C(c) ? 1 : 0;
}







int gti2SendAccept(GTI2Connection *connection)
{
    int overflow;

    if (!gti2BeginReliableMessage(connection, 4,
                                  connection->socket->protocolOffset + 7, &overflow))
        return 0;
    if (overflow)
        return 1;
    return gti2EndReliableMessage(connection) != 0;
}






int gti2SendReject(GTI2Connection *connection, unsigned char *message,
                   int len)
{
    int overflow;

    if (!gti2BeginReliableMessage(connection, 5,
                                  (len + 7) + connection->socket->protocolOffset,
                                  &overflow))
        return 0;
    if (overflow)
        return 1;
    gti2BufferWriteData(&connection->outgoingBuffer, message, len);
    return gti2EndReliableMessage(connection) != 0;
}







int gti2SendClose(GTI2Connection *connection)
{
    int overflow;

    if (!gti2BeginReliableMessage(connection, 6,
                                  connection->socket->protocolOffset + 7, &overflow))
        return 0;
    if (overflow)
        return 1;
    return gti2EndReliableMessage(connection) != 0;
}







int gti2SendKeepAlive(GTI2Connection *connection)
{
    int overflow;

    if (!gti2BeginReliableMessage(connection, 7,
                                  connection->socket->protocolOffset + 7, &overflow))
        return 0;
    if (overflow)
        return 1;
    return gti2EndReliableMessage(connection) != 0;
}




int func_02197930(GTI2Connection *connection, u8 *message, int len)
{
    u8 *start;
    int totalLen;
    int freeSpace;

    if (len < 2 || memcmp(message + connection->socket->protocolOffset, d_021A5948, 2) != 0)
    {
        if (!gti2ConnectionSendData(connection, message, len))
            return 0;
        return 1;
    }
    totalLen = len + 2;
    freeSpace = gti2GetBufferFreeSpace(&connection->outgoingBuffer);
    if (freeSpace < totalLen)
        return 1;
    start = connection->outgoingBuffer.buffer + connection->outgoingBuffer.len;
    if (connection->socket->protocolType == 2)
        gti2BufferWriteData(&connection->outgoingBuffer, message, 2);
    gti2BufferWriteData(&connection->outgoingBuffer, d_021A5948, 2);
    gti2BufferWriteData(&connection->outgoingBuffer, message + connection->socket->protocolOffset, len - connection->socket->protocolOffset);
    if (!gti2ConnectionSendData(connection, start, totalLen))
        return 0;
    gti2BufferShorten(&connection->outgoingBuffer, -1, totalLen);
    return 1;
}







int gti2SendAck(GTI2Connection *connection)
{
    short dataLength;
    int pos;
    char buffer[7];

    pos = 0;
    if (connection->socket->protocolType == 2)
    {
        unsigned char *s;
        unsigned char *d;
        dataLength = 5;
        s = (unsigned char *)&dataLength;
        d = (unsigned char *)buffer + pos;
        d[0] = s[0];
        d[1] = s[1];
        pos += 2;
    }
    {
        unsigned char *s = d_021A5948;
        unsigned char *d = (unsigned char *)buffer + pos;
        d[0] = s[0];
        d[1] = s[1];
        pos += 2;
    }
    buffer[pos] = 100;
    pos += 1;
    gti2UShortToBuffer((unsigned char *)buffer, pos, connection->expectedSerialNumber);
    pos += 2;
    if (gti2ConnectionSendData(connection, (unsigned char *)buffer, pos))
    {
        connection->pendingAck = 0;
        return 1;
    }
    return 0;
}







/*
 * sdk:      gti2SendNack (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02197AD8(GTI2Connection *connection, unsigned short SNMin, unsigned short SNMax)
{
	char buffer[9];
	int pos = 0;
	short dataLength;

	if (connection->socket->protocolType == 2) {
		dataLength = 7;
		memcpy(buffer + pos, &dataLength, 2);
		pos += 2;
	}
	memcpy(buffer + pos, g_021A5948, 2);
	pos += 2;
	buffer[pos] = 0x65;
	pos++;
	func_02195EA0((unsigned char *)buffer, pos, SNMin);
	pos += 2;
	if (SNMin != SNMax) {
		func_02195EA0((unsigned char *)buffer, pos, SNMax);
		pos += 2;
	}
	if (!func_02195750(connection, (unsigned char *)buffer, pos))
		return 0;
	return 1;
}






int gti2SendPong(GTI2Connection *connection, unsigned char *message, int len)
{
    message[2] = 0x67;
    return gti2ConnectionSendData(connection, message, len);
}





/*
 * Tail call on three fields of the object.
 */
int func_02197BB8(int *p)
{
    return func_02197BD4((GTI2Socket *)p[2], p[0], *(unsigned short *)((char *)p + 4));
}




/*
 * sdk:      gti2SendClosedOnSocket (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * w4_nm: both two-byte copies are memcpy through string.h (inlined as the
 * ldrb/strb pairs with the object's register roles); the magic source is the
 * string literal "\xFE\xFE", the vendor template @14988 at 0x021A5948.
 */
int func_02197BD4(GTI2Socket *sock, unsigned int ip, unsigned short port)
{
	char buffer[5];
	int pos = 0;
	short dataLength;

	if (sock->protocolType == 2) {
		dataLength = 3;
		memcpy(buffer + pos, &dataLength, 2);
		pos += 2;
	}
	memcpy(buffer + pos, "\xFE\xFE", 2);
	pos += 2;
	buffer[pos] = 0x68;
	pos++;
	if (!func_02198328(sock, ip, port, (unsigned char *)buffer, pos))
		return 0;
	return 1;
}



int gti2ResendMessage(GTI2Connection *connection,
                      GTI2OutgoingBufferMessage *message)
{
    gti2UShortToBuffer(connection->outgoingBuffer.buffer,
                       message->offset + connection->socket->protocolOffset + 5,
                       connection->expectedSerialNumber);
    if (gti2ConnectionSendData(connection,
                               connection->outgoingBuffer.buffer + message->offset,
                               message->len) == 0)
        return 0;
    message->sendTime = connection->lastSend;
    if (connection->outgoingBuffer.buffer[message->offset +
                                connection->socket->protocolOffset + 2] == 2)
        connection->challengeTime = connection->lastSend;
    return 1;
}



/*
 * Dispatches on the fourth argument.
 */
void func_02197CE0(int a, int b, int c, int d)
{
    if (d != 0) {
        func_02197594(a, b, c);
    } else {
        func_02197930((GTI2Connection *)a, (u8 *)b, c);
    }
}
