/*
 * file:     unit_02195E80_p05.c
 * unit:     yes
 * function: func_02196658, func_0219666C, func_0219681C, func_021968A0, func_02196920, func_02196948, func_02196AF8, func_02196B48
 * address:  0x02196658
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
 *   gti2SNDiff                   0x02195EB4  arm
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_02195EB4  0x02195EB4  arm  ov009
 *   func_02194DD4  0x02194DD4  arm  ov009
 *   func_021842D0  0x021842D0  arm  ov009
 *   func_02194E2C  0x02194E2C  arm  ov009
 *   func_02197AD8  0x02197AD8  arm  ov009
 *   func_02196658  0x02196658  arm  ov009
 *   func_0218437C  0x0218437C  arm  ov009
 *   func_02194E80  0x02194E80  arm  ov009
 *   func_02196558  0x02196558  arm  ov009
 *   current_time  0x0217f264 arm
 *   func_02195F5C  0x02195F5C  arm  ov009
 *   func_02195E80  0x02195E80  arm  ov009
 *   func_02195F9C  0x02195F9C  arm  ov009
 *   func_02196920  0x02196920  arm  ov009
 *   func_02195F70  0x02195F70  arm  ov009
 *   gti2ConnectionCommunicationError  0x02195f5c arm
 *   gti2UShortFromBuffer              0x02195e80 arm
 *   gti2HandleESN                     0x02195f9c arm
 *   func_02197C5C  0x02197C5C  arm  ov009
 */
struct DArrayImplementation;
struct Conn_02196658;
struct GTI2Connection_021968A0;
struct Conn;
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

struct GTI2Connection_02196658 {
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

typedef struct Hold_02196658 {
	int start;
	int len;
} Hold_02196658;

typedef struct Conn_02196658 {
	unsigned char pad0[0x44];
	unsigned char buffer[0x18];
	void *holds;
} Conn_02196658;

typedef struct Hold_021968A0 {
	int start;
	int len;
	int type;
	unsigned short id;
} Hold_021968A0;

typedef struct Conn_021968A0 {
	unsigned char pad0[0x44];
	unsigned char *data;
	unsigned char pad1[0x14];
	void *holds;
	unsigned char pad2[6];
	unsigned short expectedId;
} Conn_021968A0;

typedef unsigned char  u8;

struct GTI2Connection_021968A0 {
    unsigned char pad0[0x90];
    int field_90;
    unsigned int field_94;
};

struct GTI2Socket {
    char pad00[0x40];
    int protocolType;                                    /* 0x40 */
    int protocolOffset;                                  /* 0x44 */
};

struct GTI2Connection_02196AF8 {
    unsigned char pad0[0xc];
    int state;
};

typedef struct Msg {
	unsigned char pad0[8];
	unsigned short SN;
} Msg;

typedef struct Conn {
	unsigned char pad0[0x60];
	void *outgoing;
} Conn;

extern void gti2SNDiff(void);
extern int func_02184200(const int *p);
extern void *func_02184208(struct DArrayImplementation *array, int n);
extern int func_02195EB4(unsigned short SN1, unsigned short SN2);
extern int func_02194DD4(const int *p);
extern void func_021842D0(struct DArrayImplementation *array, void *newElem, int (*comparator)(void *, void *));
extern void func_02194E2C(struct GTI2Buffer *buffer, unsigned char *data, int len);
extern int func_02197AD8(struct Conn_02196658 *connection, unsigned short SNMin, unsigned short SNMax);
extern int func_02196658(void *elem1, void *elem2);
extern void func_0218437C(int a, int b);
extern void func_02194E80(void *buffer, int start, int shortenBy);
extern int func_02196558(struct GTI2Connection_021968A0 *connection, int type, u8 *message, int len);
extern unsigned int current_time(void);
extern int func_02195F5C(struct GTI2Connection_02196658 *connection);
extern unsigned short func_02195E80(unsigned char *buffer, int pos);
extern int func_02195F9C(struct Conn *connection, unsigned short ESN);
extern void func_02196920(struct GTI2Connection_02196658 *connection);
extern int func_02195F70(struct GTI2Connection_02196658 *connection);
extern int gti2ConnectionCommunicationError(struct GTI2Connection_02196AF8 * connection);
extern unsigned short gti2UShortFromBuffer(unsigned char * buffer, int pos);
extern int gti2HandleESN(struct GTI2Connection_02196AF8 * connection, unsigned short ESN);
extern int func_02197C5C(Conn *c, Msg *message);
asm void gti2IncomingBufferMessageCompare(void);
int func_0219666C(struct GTI2Connection_02196658 *connection, int type, unsigned short SN, unsigned char *message, int len, int *overflow);
void func_0219681C(Conn_02196658 *c, Hold_02196658 *message, int index);
int func_021968A0(Conn_021968A0 *c);
int func_02196948(struct GTI2Connection_02196658 *connection, int type, unsigned char *message, int len);
int func_02196B48(Conn *connection, unsigned char *message, int len);






asm void gti2IncomingBufferMessageCompare(void)
{
	ldrh r0, [r0, #0xc]
	ldrh r1, [r1, #0xc]
	ldr ip, =gti2SNDiff
	bx ip
}






/*
 * sdk:      gti2BufferIncomingMessage (libdwcgsgt2.TWL.HYB.a gt2message.o)
 */
int func_0219666C(struct GTI2Connection_02196658 *connection, int type, unsigned short SN,
                  unsigned char *message, int len, int *overflow)
{
    struct GTI2IncomingBufferMessage messageInfo;
    struct GTI2IncomingBufferMessage *bufferedMessage;
    int num;
    int i;
    struct GTI2IncomingBufferMessage *msg;
    struct GTI2IncomingBufferMessage *prev;
    unsigned short diff;

    num = func_02184200((const int *)connection->incomingBufferMessages);
    for (i = 0; i < num; i++) {
        bufferedMessage = (struct GTI2IncomingBufferMessage *)func_02184208(connection->incomingBufferMessages, i);
        if (bufferedMessage->serialNumber == SN) {
            *overflow = 0;
            return 1;
        }
        if (func_02195EB4(bufferedMessage->serialNumber, SN) > 0)
            break;
    }

    if (func_02194DD4((const int *)(&connection->incomingBuffer)) < len) {
        *overflow = 1;
        return 1;
    }

    messageInfo.start = connection->incomingBuffer.len;
    messageInfo.len = len;
    messageInfo.type = type;
    messageInfo.serialNumber = SN;
    func_021842D0(connection->incomingBufferMessages, &messageInfo, func_02196658);

    if (func_02184200((const int *)connection->incomingBufferMessages) != num + 1) {
        *overflow = 1;
        return 1;
    }

    func_02194E2C(&connection->incomingBuffer, message, len);

    if (num == 0) {
        if (!func_02197AD8((struct Conn_02196658 *)connection, connection->expectedSerialNumber, (unsigned short)(SN - 1)))
            return 0;
    } else {
        msg = (struct GTI2IncomingBufferMessage *)func_02184208(connection->incomingBufferMessages, num);
        if (msg->serialNumber == SN) {
            prev = (struct GTI2IncomingBufferMessage *)func_02184208(connection->incomingBufferMessages, num - 1);
            diff = (unsigned short)func_02195EB4(SN, prev->serialNumber);
            if (diff > 1) {
                if (!func_02197AD8((struct Conn_02196658 *)connection, (unsigned short)(prev->serialNumber + 1), (unsigned short)(SN - 1)))
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
void func_0219681C(Conn_02196658 *c, Hold_02196658 *message, int index)
{
	int moveAfter;
	int shortenBy;
	int num;
	int i;
	int moveEnd;
	Hold_02196658 *m;

	moveAfter = message->start;
	shortenBy = message->len;
	moveEnd = 0;
	func_0218437C((int)c->holds, index);
	num = func_02184200(c->holds);
	for (i = 0; i < num; i++) {
		m = (Hold_02196658 *)func_02184208(c->holds, i);
		if (m->start > moveAfter) {
			m->start -= shortenBy;
			if (moveEnd <= m->start + m->len)
				moveEnd = m->start + m->len;
		}
	}
	func_02194E80(c->buffer, moveAfter, shortenBy);
}





/*
 * sdk:      gti2DeliverHoldMessages (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_021968A0(Conn_021968A0 *c)
{
	int i;
	Hold_021968A0 *m;

again:
	for (i = func_02184200(c->holds) - 1; i >= 0; i--) {
		m = (Hold_021968A0 *)func_02184208((struct DArrayImplementation *)c->holds, i);
		if (m->id == c->expectedId) {
			if (!func_02196558((struct GTI2Connection_021968A0 *)c, m->type, c->data + m->start, m->len))
				return 0;
			func_0219681C((Conn_02196658 *)c, (Hold_02196658 *)m, i);
			goto again;
		}
	}
	return 1;
}





static void gti2SetPendingAck(struct GTI2Connection_021968A0 * connection)
{
    if (connection->field_90)
        return;
    connection->field_90 = 1;
    connection->field_94 = current_time();
}



/*
 * sdk:      gti2HandleReliableMessage (libdwcgsgt2.TWL.HYB.a gt2message.o)
 */
int func_02196948(struct GTI2Connection_02196658 *connection, int type, unsigned char *message, int len)
{
    unsigned short SN;
    unsigned short ESN;
    int headerLength;
    int overflow;

    headerLength = connection->socket->protocolOffset + 7;
    if (len < headerLength)
        return func_02195F5C((struct GTI2Connection_02196658 *)connection) != 0;

    SN = func_02195E80(message + connection->socket->protocolOffset, 3);
    ESN = func_02195E80(message + connection->socket->protocolOffset, 5);

    if (connection->socket->protocolType == 2 && type == 0) {
        message[connection->socket->protocolOffset + 5] = message[0];
        message[connection->socket->protocolOffset + 6] = message[1];
        message += headerLength - connection->socket->protocolOffset;
        len -= headerLength - connection->socket->protocolOffset;
    } else {
        message += headerLength;
        len -= headerLength;
    }

    if (!func_02195F9C((struct Conn *)connection, ESN))
        return 0;

    if (SN == connection->expectedSerialNumber) {
        func_02196920((struct GTI2Connection_02196658 *)connection);
        if (!func_02196558((struct GTI2Connection_021968A0 *)connection, type, message, len))
            return 0;
        if (!func_021968A0((Conn_021968A0 *)((struct Conn *)connection)))
            return 0;
        return 1;
    }

    if (func_02195EB4(SN, connection->expectedSerialNumber) < 0) {
        func_02196920((struct GTI2Connection_02196658 *)connection);
        return 1;
    }

    if (!func_0219666C((struct GTI2Connection_02196658 *)connection, type, SN, message, len, &overflow))
        return 0;
    if (overflow) {
        if (!func_02195F70((struct GTI2Connection_02196658 *)connection))
            return 0;
    }
    return 1;
}



static int gti2HandleAck(struct GTI2Connection_02196AF8 * connection, unsigned char * message, int len)
{
    unsigned short ESN;

    if (len != 2)
        return gti2ConnectionCommunicationError(connection) != 0;
    ESN = gti2UShortFromBuffer(message, 0);
    return gti2HandleESN(connection, ESN) != 0;
}



/*
 * sdk:      gti2HandleNack (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02196B48(Conn *connection, unsigned char *message, int len)
{
	unsigned short SNMin;
	unsigned short SNMax;
	int num;
	int i;
	Msg *messageInfo;

	SNMin = func_02195E80(message, 0);
	if (len == 2)
		SNMax = SNMin;
	else if (len == 4)
		SNMax = func_02195E80(message, 2);
	else {
		if (func_02195F5C((struct GTI2Connection_02196658 *)connection))
			return 1;
		return 0;
	}
	num = func_02184200(connection->outgoing);
	for (i = 0; i < num; i++) {
		messageInfo = func_02184208((struct DArrayImplementation *)connection->outgoing, i);
		if (func_02195EB4(messageInfo->SN, SNMin) < 0)
			continue;
		if (func_02195EB4(messageInfo->SN, SNMax) > 0)
			continue;
		if (!func_02197C5C(connection, messageInfo))
			return 0;
	}
	return 1;
}
