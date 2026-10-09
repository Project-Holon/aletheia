/*
 * file:     unit_02195E80.c
 * unit:     yes
 * function: gti2UShortFromBuffer, func_02195EA0, func_02195EB4, gti2ConnectionError, func_02195F5C, gti2ConnectionMemoryError, func_02195F9C, func_02196098, func_02196118, func_021961C8, func_02196268, func_02196348, gti2HandleAccept, gti2HandleReject, gti2HandleClose, func_02196558, gti2IncomingBufferMessageCompare, func_0219666C, func_0219681C, func_021968A0, gti2SetPendingAck, func_02196948, gti2HandleAck, func_02196B48
 * address:  0x02195E80
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gti2ConnectionClosed               0x021959D0  arm ov009
 *   gti2ConnectedCallback              0x0219500C  arm ov009
 *   gti2ClosedCallback                 0x02195158  arm ov009
 *   func_02195EC4                      0x02195EC4  arm ov009
 *   gti2SendClosed                     0x02197BB8  arm
 *   func_02184200                      0x02184200  arm ov009
 *   func_02184208                      0x02184208  arm ov009
 *   func_02195EB4                      0x02195EB4  arm ov009
 *   func_0218437C                      0x0218437C  arm ov009
 *   func_02194E80                      0x02194E80  arm ov009
 *   func_02195340                      0x02195340  arm ov009
 *   func_021950B4                      0x021950B4  arm ov009
 *   func_02195F5C                      0x02195F5C  arm ov009
 *   func_02194C6C                      0x02194C6C  arm ov009
 *   func_02194B74                      0x02194B74  arm ov009
 *   func_02197678                      0x02197678  arm ov009
 *   func_02194D74                      0x02194D74  arm ov009
 *   func_02197700                      0x02197700  arm ov009
 *   func_0217EAE0                      0x0217EAE0  arm ov009
 *   func_02195F5C   0x02195F5C  arm ov009
 *   gti2CheckResponse                  0x02194D74  arm ov009
 *   current_time                       0x0217F264  arm ov009
 *   gti2ConnectAttemptCallback         0x02194F2C  arm ov009
 *   gti2ConnectionError                0x02195ec4  arm ov009
 *   func_02196118              0x02196118  arm ov009
 *   func_021961C8          0x021961C8  arm ov009
 *   func_02196268          0x02196268  arm ov009
 *   func_02196348           0x02196348  arm ov009
 *   gti2HandleAccept                   0x02196458  arm ov009
 *   gti2HandleReject                   0x021964A8  arm ov009
 *   gti2HandleClose                    0x02196514  arm ov009
 *   func_02195EB4                         0x02195EB4  arm
 *   func_02194DD4                      0x02194DD4  arm ov009
 *   func_021842D0                      0x021842D0  arm ov009
 *   func_02194E2C                      0x02194E2C  arm ov009
 *   func_02197AD8                      0x02197AD8  arm ov009
 *   func_02196658                      0x02196658  arm ov009
 *   func_02196558                      0x02196558  arm ov009
 *   func_02195E80                      0x02195E80  arm ov009
 *   func_02195F9C                      0x02195F9C  arm ov009
 *   func_02196920                      0x02196920  arm ov009
 *   func_02195F70                      0x02195F70  arm ov009
 *   gti2UShortFromBuffer               0x02195e80  arm
 *   func_02195F9C                      0x02195f9c  arm
 *   func_02197C5C                      0x02197C5C  arm ov009
 */
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
    unsigned char pad4[4];
    unsigned short SN;
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
extern void func_02194E2C(struct GTI2Buffer *buffer, unsigned char *data, int len);
extern void func_02194E80(struct GTI2Buffer *buffer, int start, int shortenBy);
extern unsigned char *func_02194C6C(unsigned char *buffer, unsigned char *challenge);
extern unsigned char *func_02194B74(unsigned char *buffer);
extern int func_02194D74(unsigned char *response1, unsigned char *response2);
extern int func_02195340(GTI2Connection *c, int filterID, unsigned char *msg, int len, int reliable);
extern int func_021950B4(GTI2Connection *c, unsigned char *msg, int len, int reliable);
extern int func_02197678(GTI2Connection *c, char *response, char *challenge);
extern int func_02197700(GTI2Connection *c, char *response, char *message, int len);
extern int func_02197AD8(GTI2Connection *connection, unsigned short SNMin, unsigned short SNMax);
extern int func_02197C5C(GTI2Connection *c, struct GTI2OutgoingBufferMessage *message);
extern void func_0217EAE0(void *ptr);

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
	struct GTI2OutgoingBufferMessage *message;
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


asm int gti2IncomingBufferMessageCompare(void *elem1, void *elem2)
{
	ldrh r0, [r0, #0xc]
	ldrh r1, [r1, #0xc]
	ldr ip, =func_02195EB4
	bx ip
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
	struct GTI2OutgoingBufferMessage *messageInfo;

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
