/*
 * file:     gt2message.c
 * unit:     yes
 * function: gti2UShortFromBuffer, func_02195EA0, func_02195EB4, gti2ConnectionError, func_02195F5C, gti2ConnectionMemoryError, func_02195F9C, func_02196098, func_02196118, func_021961C8, func_02196268, func_02196348, gti2HandleAccept, gti2HandleReject, gti2HandleClose, func_02196558, gti2IncomingBufferMessageCompare, func_0219666C, func_0219681C, func_021968A0, gti2SetPendingAck, func_02196948, gti2HandleAck, func_02196B48, gti2HandlePing, func_02196C34, func_02196CC8, func_02196D00, func_02196DC4, func_021970BC, func_021971BC, gti2ReceiveMessages, gti2StoreOutgoingReliableMessageInfo, gti2BeginReliableMessage, gti2EndReliableMessage, gti2SendAppReliable, func_021975FC, func_02197678, func_02197700, gti2SendAccept, gti2SendReject, gti2SendClose, gti2SendKeepAlive, func_02197930, gti2SendAck, func_02197AD8, gti2SendPong, func_02197BB8, func_02197BD4, func_02197C5C, func_02197CE0
 * address:  0x02195E80
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Handler for the ping message type: answers it with a pong. Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 *
 * symbols:
 *   gti2ConnectionClosed               0x021959D0  arm ov009
 *   gti2ConnectedCallback              0x0219500C  arm ov009
 *   gti2ClosedCallback                 0x02195158  arm ov009
 *   func_02195EC4                      0x02195EC4  arm ov009
 *   gti2SendClosed                     0x02197BB8  arm
 *   func_02184200                      0x02184200  arm ov009
 *   func_02184208                      0x02184208  arm ov009
 *   func_0218437C                      0x0218437C  arm ov009
 *   func_02194E80                      0x02194E80  arm ov009
 *   func_02195340                      0x02195340  arm ov009
 *   func_021950B4                      0x021950B4  arm ov009
 *   func_02194C6C                      0x02194C6C  arm ov009
 *   func_02194B74                      0x02194B74  arm ov009
 *   func_02194D74                      0x02194D74  arm ov009
 *   func_0217EAE0                      0x0217EAE0  arm ov009
 *   gti2CheckResponse                  0x02194D74  arm ov009
 *   current_time                       0x0217F264  arm ov009
 *   gti2ConnectAttemptCallback         0x02194F2C  arm ov009
 *   func_02194DD4                      0x02194DD4  arm ov009
 *   func_021842D0                      0x021842D0  arm ov009
 *   func_02194E2C                      0x02194E2C  arm ov009
 *   func_02196658                      0x02196658  arm ov009
 *   func_02195E80                      0x02195E80  arm ov009
 *   func_02196920                      0x02196920  arm ov009
 *   func_02195F70                      0x02195F70  arm ov009
 *   func_02197C5C                      0x02197C5C  arm ov009
 *   func_02197BA4 0x02197BA4 arm
 *   func_020923F0  0x020923F0  arm
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_021951E8  0x021951E8  arm  ov009
 *   g_021A5940  0x021A5940  data
 *   func_02196AF8  0x02196AF8  arm  ov009
 *   func_02196CC8  0x02196CC8  arm  ov009
 *   func_02197D5C  0x02197D5C  arm  ov009
 *   func_02195408  0x02195408  arm  ov009
 *   func_021954F4  0x021954F4  arm  ov009
 *   func_021955C0  0x021955C0  arm  ov009
 *   g_021A5948     0x021A5948  data
 *   gti2SocketFindConnection  0x02197D5C  arm  ov009
 *   gti2DumpCallback          0x02195408  arm  ov009
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
 *   gti2BufferWriteData                 0x02194E2C  arm  ov009
 *   gti2BufferWriteByte                 0x02194DE4  arm  ov009
 *   gti2BufferWriteUShort               0x02194DFC  arm  ov009
 *   d_021A5948                          0x021A5948  data ov009
 *   ArrayNth               0x02184208 arm
 *   gti2ConnectionSendData 0x02195750 arm
 *   func_02197458  0x02197458  arm  ov009
 *   func_0219754C  0x0219754C  arm  ov009
 *   memcmp                    0x020923F0  arm
 *   gti2BufferShorten         0x02194E80  arm  ov009
 *   gti2UShortToBuffer      0x02195EA0 arm
 *   func_02195750  0x02195750  arm  ov009
 *   func_02198328  0x02198328  arm  ov009
 *   func_02197594  0x02197594  arm  ov009
 *   @14988         0x021A5948  data
 */
#include "gt2main_types.h"
#include "../../matched/arm9_sdk/libc/string.h"

#define SWAP16(x) ((unsigned short)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))
typedef short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef int GT2Bool;

typedef enum { GT2Success, GT2OutOfMemory, GT2Rejected } GT2Result;

typedef enum { GT2LocalClose, GT2RemoteClose } GT2CloseReason;

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

typedef struct GTI2IncomingBufferMessage GTI2IncomingBufferMessage;

typedef struct GTI2OutgoingBufferMessage GTI2OutgoingBufferMessage;

struct SOCSockAddrIn {
    unsigned char  len;
    unsigned char  family;
    unsigned short port;
    unsigned long  addr;
};

extern void gti2ConnectionClosed(GTI2Connection *connection);
extern int gti2ConnectedCallback(GTI2Connection *connection, int result, unsigned char *message, int len);
extern int gti2ClosedCallback(GTI2Connection *connection, int reason);
extern int gti2SendClosed(GTI2Connection *connection);
extern int gti2ConnectAttemptCallback(GTI2Socket *sock, GTI2Connection *c, unsigned int ip, unsigned short port, int latency, unsigned char *msg, int len);
extern int gti2CheckResponse();
extern u32 current_time(void);
extern int func_02184200(struct DArrayImplementation *array);
extern void *func_02184208(struct DArrayImplementation *array, int n);
extern void func_021842D0(struct DArrayImplementation *array, void *newElem, int (*comparator)(void *, void *));
extern void func_0218437C(struct DArrayImplementation *array, int n);
extern int func_02194DD4(struct GTI2Buffer *buffer);
extern void func_02194E2C(void *buffer, unsigned char *data, int len);
extern void func_02194E80(struct GTI2Buffer *buffer, int start, int shortenBy);
extern unsigned char *func_02194C6C(unsigned char *buffer, unsigned char *challenge);
extern unsigned char *func_02194B74(unsigned char *buffer);
extern int func_02194D74(unsigned char *response1, unsigned char *response2);
extern int func_02195340(GTI2Connection *c, int filterID, unsigned char *msg, int len, int reliable);
extern int func_021950B4(GTI2Connection *c, unsigned char *msg, int len, int reliable);
extern int func_02197C5C(GTI2Connection *c, GTI2OutgoingBufferMessage *message);
extern void func_0217EAE0(void *ptr);
extern int func_02197BA4(GTI2Connection *connection, unsigned char *message, int len);
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern unsigned int func_0217F264(void);
extern int func_021951E8(GTI2Connection *c, int latency);
extern int func_02196AF8(GTI2Connection *c, unsigned char *msg, int len);
extern int func_02196CC8(GTI2Connection *c);
extern GTI2Connection *func_02197D5C(GTI2Socket *socket, unsigned int ip, unsigned short port);
extern int func_02195408(GTI2Socket *socket, GTI2Connection *connection, unsigned int ip,
                         unsigned short port, int reset, unsigned char *message, int len, int outgoing);
extern int func_021954F4(char *p, int a1, int a2, int a3, int a4, int *a5);
extern int func_021955C0(GTI2Socket *socket, GTI2Connection **connection,
                         unsigned int ip, unsigned short port);
extern GTI2Connection *gti2SocketFindConnection();
extern int gti2DumpCallback();
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
extern void gti2BufferWriteData(GTI2Buffer *buffer,
                                unsigned char *data, int len);
extern void gti2BufferWriteByte(GTI2Buffer *buffer, unsigned char b);
extern void gti2BufferWriteUShort(GTI2Buffer *buffer, unsigned short s);
extern void *ArrayNth(struct DArrayImplementation *array, int n);
extern int gti2ConnectionSendData(GTI2Connection *connection,
                                  unsigned char *message, int len);
extern int func_02197458(GTI2Connection *c, int type, int len, int *overflow);
extern int func_0219754C(GTI2Connection *c);
extern int memcmp();
extern void gti2BufferShorten();
extern void gti2UShortToBuffer(unsigned char *buffer, int pos, unsigned short s);
extern int func_02195750(GTI2Connection *c, unsigned char *message, int len);
extern int func_02198328(GTI2Socket *sock, unsigned int ip, unsigned short port, unsigned char *message, int len);
extern void func_02197594(int a, int b, int c);
unsigned short gti2UShortFromBuffer(unsigned char *buffer, int pos);
void func_02195EA0(char *p, int i, int v);
s16 func_02195EB4(unsigned short a, unsigned short b);
int gti2ConnectionError(GTI2Connection *connection, GT2Result result, GT2CloseReason reason);
int func_02195F5C(GTI2Connection *connection);
int gti2ConnectionMemoryError(GTI2Connection *connection);
int func_02195F9C(GTI2Connection *connection, unsigned short ESN);
int func_02196098(GTI2Connection *c, unsigned char *msg, int len);
int func_02196118(GTI2Connection *c, unsigned char *message, int len);
int func_021961C8(GTI2Connection *c, unsigned char *message, int len);
int func_02196268(GTI2Connection *connection, unsigned char *message, int len);
int func_02196348(GTI2Connection *connection, unsigned char *message, int len);
int gti2HandleAccept(GTI2Connection *connection);
int gti2HandleReject(GTI2Connection *connection, unsigned char *message, int len);
int gti2HandleClose(GTI2Connection *connection);
int func_02196558(GTI2Connection *connection, int type, unsigned char *message, int len);
int gti2IncomingBufferMessageCompare(void *elem1, void *elem2);
int func_0219666C(GTI2Connection *connection, int type, unsigned short SN, unsigned char *message, int len, int *overflow);
void func_0219681C(GTI2Connection *c, struct GTI2IncomingBufferMessage *message, int index);
int func_021968A0(GTI2Connection *c);
void gti2SetPendingAck(GTI2Connection *connection);
int func_02196948(GTI2Connection *connection, int type, unsigned char *message, int len);
int gti2HandleAck(GTI2Connection *connection, unsigned char *message, int len);
int func_02196B48(GTI2Connection *connection, unsigned char *message, int len);
int gti2HandlePing(GTI2Connection *connection, unsigned char *message, int len);
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


unsigned short gti2UShortFromBuffer(unsigned char *buffer, int pos)
{
    unsigned short s;
    s = (unsigned short)((buffer[pos] << 8) & 0xff00);
    s |= buffer[pos + 1];
    return s;
}


/*
 * Stores a word big-endian at p[i].
 */
void func_02195EA0(char *p, int i, int v)
{
    p[i] = (char)(v >> 8);
    p[i + 1] = (char)v;
}



/*
 * Halfword difference, sign extended.
 */
s16 func_02195EB4(unsigned short a, unsigned short b)
{
    return (s16)(a - b);
}



int gti2ConnectionError(GTI2Connection *connection, GT2Result result, GT2CloseReason reason)
{
    if (connection->state < 5)
    {
        if (connection->initiated != 0)
        {
            gti2ConnectionClosed(connection);
            reason = 0;
            if (gti2ConnectedCallback(connection, result, 0, 0) == 0)
                return 0;
            goto ret1;
        }
        if (connection->state == 4)
            connection->freeAtAcceptReject = 1;
        gti2ConnectionClosed(connection);
    }
    else
    {
        if (connection->state != 7)
        {
            gti2ConnectionClosed(connection);
            if (gti2ClosedCallback(connection, reason) == 0)
                return 0;
        }
    }
ret1:
    return 1;
}



/*
 * Tail call with the constant argument pair (7, 2).
 */
int func_02195F5C(GTI2Connection *connection)
{
    return gti2ConnectionError(connection, 7, 2);
}



int gti2ConnectionMemoryError(GTI2Connection *connection)
{
    if (gti2SendClosed(connection) == 0)
        return 0;
    return gti2ConnectionError(connection, 1, 4);
}



/*
 * sdk:      func_02195F9C (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02195F9C(GTI2Connection *connection, unsigned short ESN)
{
	int len;
	int i;
	GTI2OutgoingBufferMessage *message;
	int shortenBy;

	len = func_02184200(connection->outgoingBufferMessages);
	if (len == 0)
		return 1;
	for (i = 0; i < len; i++) {
		message = func_02184208(connection->outgoingBufferMessages, i);
		if (func_02195EB4(message->SN, ESN) >= 0)
			break;
	}
	if (i == 0)
		return 1;
	while (i-- != 0)
		func_0218437C(connection->outgoingBufferMessages, i);
	len = func_02184200(connection->outgoingBufferMessages);
	if (len == 0) {
		connection->outgoingBuffer.len = 0;
		return 1;
	}
	message = func_02184208(connection->outgoingBufferMessages, 0);
	shortenBy = message->offset;
	for (i = 0; i < len; i++) {
		message = func_02184208(connection->outgoingBufferMessages, i);
		message->offset -= shortenBy;
	}
	func_02194E80(&connection->outgoingBuffer, 0, shortenBy);
	return 1;
}





/*
 * sdk:      gti2HandleAppUnreliable (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02196098(GTI2Connection *c, unsigned char *msg, int len)
{
	int ret;

	if (c->state != 5 && c->state != 6)
		return 1;
	if (func_02184200(c->receiveFilters)) {
		ret = 0;
		if (func_02195340(c, 0, msg, len, 0))
			ret = 1;
		return ret;
	}
	ret = 0;
	if (func_021950B4(c, msg, len, 0))
		ret = 1;
	return ret;
}





/*
 * sdk:      func_02196118 (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02196118(GTI2Connection *c, unsigned char *message, int len)
{
	int ret;

	if (c->state != 5 && c->state != 6) {
		if (!func_02195F5C(c))
			return 0;
	} else if (func_02184200(c->receiveFilters)) {
		ret = 1;
		if (!func_02195340(c, 0, message, len, 1))
			ret = 0;
		return ret;
	} else {
		if (!func_021950B4(c, message, len, 1))
			return 0;
	}
	return 1;
}




/*
 * sdk:      func_021961C8 (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_021961C8(GTI2Connection *c, unsigned char *message, int len)
{
	char response[32];
	char challenge[32];

	if (c->state != 2) {
		if (func_02195F5C(c))
			return 1;
		return 0;
	}
	if (len < 0x20) {
		if (func_02195F5C(c))
			return 1;
		return 0;
	}
	func_02194C6C((unsigned char *)response, message);
	func_02194B74((unsigned char *)challenge);
	func_02194C6C((unsigned char *)c->response, (unsigned char *)challenge);
	if (!func_02197678(c, response, challenge))
		return 0;
	c->state = 3;
	return 1;
}





/*
 * sdk:      func_02196268 (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02196268(GTI2Connection *connection, unsigned char *message, int len)
{
	char response[32];

	if (connection->state != 0) {
		if (func_02195F5C(connection))
			return 1;
		return 0;
	}
	if (len < 0x40) {
		if (func_02195F5C(connection))
			return 1;
		return 0;
	}
	if (!func_02194D74(message, (unsigned char *)connection->response)) {
		if (func_02195F5C(connection))
			return 1;
		return 0;
	}
	func_02194C6C((unsigned char *)response, message + 0x20);
	if (!func_02197700(connection, response, connection->initialMessage, connection->initialMessageLen))
		return 0;
	if (connection->initialMessage != 0) {
		func_0217EAE0(connection->initialMessage);
		connection->initialMessage = 0;
	}
	connection->state = 1;
	return 1;
}





/*
 * sdk:      func_02196348 (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02196348(GTI2Connection *connection, unsigned char *message, int len)
{
    int latency;

    if (connection->state != 3)
        return func_02195F5C(connection) != 0;
    if (len < 32)
        return func_02195F5C(connection) != 0;
    if (!gti2CheckResponse(message, connection->response))
        return func_02195F5C(connection) != 0;
    if (connection->socket->connectAttemptCallback == 0)
    {
        if (!gti2SendClosed(connection))
            return 0;
        gti2ConnectionClosed(connection);
        return 1;
    }
    connection->state = 4;
    latency = current_time() - connection->challengeTime;
    return gti2ConnectAttemptCallback(connection->socket, connection, connection->ip, connection->port, latency, message + 32, len - 32) != 0;
}



int gti2HandleAccept(GTI2Connection *connection)
{
    if (connection->state != 1)
        return func_02195F5C(connection) != 0;
    connection->state = 5;
    return gti2ConnectedCallback(connection, 0, 0, 0) != 0;
}



int gti2HandleReject(GTI2Connection *connection, unsigned char *message, int len)
{
    if (connection->state != 1)
        return func_02195F5C(connection) != 0;
    gti2ConnectionClosed(connection);
    if (!gti2SendClosed(connection))
        return 0;
    if (gti2ConnectedCallback(connection, 2, message, len))
        return 1;
    return 0;
}



int gti2HandleClose(GTI2Connection *connection)
{
    if (!gti2SendClosed(connection))
        return 0;
    if (!gti2ConnectionError(connection, GT2Rejected,
                             (connection->state == 6) ? GT2LocalClose : GT2RemoteClose))
        return 0;
    return 1;
}



int func_02196558(GTI2Connection *connection, int type, unsigned char *message, int len)
{
    connection->expectedSerialNumber++;
    if (type == 0)
    {
        if (!func_02196118(connection, message, len))
            return 0;
    }
    else if (type == 1)
    {
        if (!func_021961C8(connection, message, len))
            return 0;
    }
    else if (type == 2)
    {
        if (!func_02196268(connection, message, len))
            return 0;
    }
    else if (type == 3)
    {
        if (!func_02196348(connection, message, len))
            return 0;
    }
    else if (type == 4)
    {
        if (!gti2HandleAccept(connection))
            return 0;
    }
    else if (type == 5)
    {
        if (!gti2HandleReject(connection, message, len))
            return 0;
    }
    else if (type == 6)
    {
        if (!gti2HandleClose(connection))
            return 0;
    }
    return 1;
}



int gti2IncomingBufferMessageCompare(void *elem1, void *elem2)
{
    return func_02195EB4(((struct GTI2IncomingBufferMessage *)elem1)->serialNumber, ((struct GTI2IncomingBufferMessage *)elem2)->serialNumber);
}



/*
 * sdk:      gti2BufferIncomingMessage (libdwcgsgt2.TWL.HYB.a gt2message.o)
 */
int func_0219666C(GTI2Connection *connection, int type, unsigned short SN,
                  unsigned char *message, int len, int *overflow)
{
    struct GTI2IncomingBufferMessage messageInfo;
    struct GTI2IncomingBufferMessage *bufferedMessage;
    int num;
    int i;
    struct GTI2IncomingBufferMessage *msg;
    struct GTI2IncomingBufferMessage *prev;
    unsigned short diff;

    num = func_02184200(connection->incomingBufferMessages);
    for (i = 0; i < num; i++) {
        bufferedMessage = (struct GTI2IncomingBufferMessage *)func_02184208(connection->incomingBufferMessages, i);
        if (bufferedMessage->serialNumber == SN) {
            *overflow = 0;
            return 1;
        }
        if (func_02195EB4(bufferedMessage->serialNumber, SN) > 0)
            break;
    }

    if (func_02194DD4(&connection->incomingBuffer) < len) {
        *overflow = 1;
        return 1;
    }

    messageInfo.start = connection->incomingBuffer.len;
    messageInfo.len = len;
    messageInfo.type = type;
    messageInfo.serialNumber = SN;
    func_021842D0(connection->incomingBufferMessages, &messageInfo, gti2IncomingBufferMessageCompare);

    if (func_02184200(connection->incomingBufferMessages) != num + 1) {
        *overflow = 1;
        return 1;
    }

    func_02194E2C(&connection->incomingBuffer, message, len);

    if (num == 0) {
        if (!func_02197AD8(connection, connection->expectedSerialNumber, (unsigned short)(SN - 1)))
            return 0;
    } else {
        msg = (struct GTI2IncomingBufferMessage *)func_02184208(connection->incomingBufferMessages, num);
        if (msg->serialNumber == SN) {
            prev = (struct GTI2IncomingBufferMessage *)func_02184208(connection->incomingBufferMessages, num - 1);
            diff = (unsigned short)func_02195EB4(SN, prev->serialNumber);
            if (diff > 1) {
                if (!func_02197AD8(connection, (unsigned short)(prev->serialNumber + 1), (unsigned short)(SN - 1)))
                    return 0;
            }
        }
    }

    *overflow = 0;
    return 1;
}






/*
 * sdk:      gti2RemoveHoldMessage (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
void func_0219681C(GTI2Connection *c, struct GTI2IncomingBufferMessage *message, int index)
{
	int moveAfter;
	int shortenBy;
	int num;
	int i;
	int moveEnd;
	struct GTI2IncomingBufferMessage *m;

	moveAfter = message->start;
	shortenBy = message->len;
	moveEnd = 0;
	func_0218437C(c->incomingBufferMessages, index);
	num = func_02184200(c->incomingBufferMessages);
	for (i = 0; i < num; i++) {
		m = (struct GTI2IncomingBufferMessage *)func_02184208(c->incomingBufferMessages, i);
		if (m->start > moveAfter) {
			m->start -= shortenBy;
			if (moveEnd <= m->start + m->len)
				moveEnd = m->start + m->len;
		}
	}
	func_02194E80(&c->incomingBuffer, moveAfter, shortenBy);
}






/*
 * sdk:      gti2DeliverHoldMessages (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_021968A0(GTI2Connection *c)
{
	int i;
	struct GTI2IncomingBufferMessage *m;

again:
	for (i = func_02184200(c->incomingBufferMessages) - 1; i >= 0; i--) {
		m = (struct GTI2IncomingBufferMessage *)func_02184208(c->incomingBufferMessages, i);
		if (m->serialNumber == c->expectedSerialNumber) {
			if (!func_02196558(c, m->type, c->incomingBuffer.buffer + m->start, m->len))
				return 0;
			func_0219681C(c, m, i);
			goto again;
		}
	}
	return 1;
}






void gti2SetPendingAck(GTI2Connection *connection)
{
    if (connection->pendingAck)
        return;
    connection->pendingAck = 1;
    connection->pendingAckTime = current_time();
}




/*
 * sdk:      gti2HandleReliableMessage (libdwcgsgt2.TWL.HYB.a gt2message.o)
 */
int func_02196948(GTI2Connection *connection, int type, unsigned char *message, int len)
{
    unsigned short SN;
    unsigned short ESN;
    int headerLength;
    int overflow;

    headerLength = connection->socket->protocolOffset + 7;
    if (len < headerLength)
        return func_02195F5C(connection) != 0;

    SN = gti2UShortFromBuffer(message + connection->socket->protocolOffset, 3);
    ESN = gti2UShortFromBuffer(message + connection->socket->protocolOffset, 5);

    if (connection->socket->protocolType == 2 && type == 0) {
        message[connection->socket->protocolOffset + 5] = message[0];
        message[connection->socket->protocolOffset + 6] = message[1];
        message += headerLength - connection->socket->protocolOffset;
        len -= headerLength - connection->socket->protocolOffset;
    } else {
        message += headerLength;
        len -= headerLength;
    }

    if (!func_02195F9C(connection, ESN))
        return 0;

    if (SN == connection->expectedSerialNumber) {
        gti2SetPendingAck(connection);
        if (!func_02196558(connection, type, message, len))
            return 0;
        if (!func_021968A0(connection))
            return 0;
        return 1;
    }

    if (func_02195EB4(SN, connection->expectedSerialNumber) < 0) {
        gti2SetPendingAck(connection);
        return 1;
    }

    if (!func_0219666C(connection, type, SN, message, len, &overflow))
        return 0;
    if (overflow) {
        if (!gti2ConnectionMemoryError(connection))
            return 0;
    }
    return 1;
}




int gti2HandleAck(GTI2Connection *connection, unsigned char *message, int len)
{
    unsigned short ESN;

    if (len != 2)
        return func_02195F5C(connection) != 0;
    ESN = gti2UShortFromBuffer(message, 0);
    return func_02195F9C(connection, ESN) != 0;
}




/*
 * sdk:      gti2HandleNack (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02196B48(GTI2Connection *connection, unsigned char *message, int len)
{
	unsigned short SNMin;
	unsigned short SNMax;
	int num;
	int i;
	GTI2OutgoingBufferMessage *messageInfo;

	SNMin = gti2UShortFromBuffer(message, 0);
	if (len == 2)
		SNMax = SNMin;
	else if (len == 4)
		SNMax = gti2UShortFromBuffer(message, 2);
	else {
		if (func_02195F5C(connection))
			return 1;
		return 0;
	}
	num = func_02184200(connection->outgoingBufferMessages);
	for (i = 0; i < num; i++) {
		messageInfo = func_02184208(connection->outgoingBufferMessages, i);
		if (func_02195EB4(messageInfo->SN, SNMin) < 0)
			continue;
		if (func_02195EB4(messageInfo->SN, SNMax) > 0)
			continue;
		if (!func_02197C5C(connection, messageInfo))
			return 0;
	}
	return 1;
}


int gti2HandlePing(GTI2Connection *connection, unsigned char *message, int len)
{
    return func_02197BA4(connection, message, len);
}












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
		if (!gti2HandlePing(c, message, len))
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

    if (socket->receiveDumpCallback) {
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
    if (socket->receiveDumpCallback)
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
	if (sock->receiveDumpCallback) {
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
	func_02195EA0(buffer, pos, SNMin);
	pos += 2;
	if (SNMin != SNMax) {
		func_02195EA0(buffer, pos, SNMax);
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
