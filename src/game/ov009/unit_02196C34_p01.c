/*
 * file:     unit_02196C34_p01.c
 * unit:     yes
 * function: func_02196C34, func_02196CC8, func_02196D00, func_02196DC4
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
 *   func_02197BD4  0x02197BD4  arm  ov009
 *   func_021955C0  0x021955C0  arm  ov009
 *   func_02197BB8  0x02197BB8  arm  ov009
 *   func_02196098  0x02196098  arm  ov009
 *   func_02196948  0x02196948  arm  ov009
 *   g_021A5948     0x021A5948  data
 */
struct DArrayImplementation;
struct Conn_02196CC8;
struct Sock;
typedef struct Conn_02196C34 {
	unsigned char pad0[0x34];
	void *ping;
} Conn_02196C34;

typedef unsigned char  u8;

typedef int GT2Bool;

typedef enum { GT2Success, GT2OutOfMemory, GT2Rejected } GT2Result;

typedef enum { GT2LocalClose, GT2RemoteClose } GT2CloseReason;

struct GTI2Connection_02196C34 {
    unsigned char pad0[0xc];
    int state;
};

typedef struct Sock {
	unsigned char pad0[0x44];
	int headerBase;
} Sock;

typedef struct Conn_02196CC8 {
	unsigned char pad0[8];
	Sock *sock;
} Conn_02196CC8;

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

struct GTI2Connection_02196DC4 {
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

struct GTI2Socket {
    char pad00[0x20];
    void *connectAttemptCallback;                        /* 0x20 */
    char pad24[0x08];
    void *dumpCallback;                                  /* 0x2C */
    char pad30[0x10];
    int protocolType;                                    /* 0x40 */
    int protocolOffset;                                  /* 0x44 */
};

extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern unsigned int func_0217F264(void);
extern int func_021951E8(Conn_02196C34 *c, int latency);
extern GT2Bool gti2ConnectionError(struct GTI2Connection_02196C34 *connection, GT2Result result, GT2CloseReason reason);
extern int func_02196AF8(Conn_02196CC8 *c, unsigned char *msg, int len);
extern int func_02196B48(Conn_02196CC8 *c, unsigned char *msg, int len);
extern int func_02196C28(void *connection, unsigned char *message, int len);
extern int func_02196CC8(Conn_02196CC8 *c);
extern struct GTI2Connection_02196DC4 *func_02197D5C(struct GTI2Socket *socket, unsigned int ip, unsigned short port);
extern int func_02195408(struct GTI2Socket *socket, struct GTI2Connection_02196DC4 *connection, unsigned int ip,
                         unsigned short port, int reset, unsigned char *message, int len, int outgoing);
extern int func_021954F4(char *p, int a1, int a2, int a3, int a4, int *a5);
extern int func_02197BD4(struct Sock *sock, unsigned int ip, unsigned short port);
extern int func_021955C0(struct GTI2Socket *socket, struct GTI2Connection_02196DC4 **connection,
                         unsigned int ip, unsigned short port);
extern int func_02197BB8(int *p);
extern int func_02196098(struct Conn_02196CC8 *c, unsigned char *msg, int len);
extern int func_02196948(struct GTI2Connection_02196DC4 *connection, int type, unsigned char *message, int len);
int func_02196C34(Conn_02196C34 *c, unsigned char *message, int len);
int func_02196D00(Conn_02196CC8 *c, int type, unsigned char *message, int len);
int func_02196DC4(struct GTI2Socket *socket, unsigned char *message, int len, unsigned int ip, unsigned short port);
extern unsigned char g_021A5940[];
extern const char g_021A5948[];


/*
 * sdk:      gti2HandlePong (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_02196C34(Conn_02196C34 *c, unsigned char *message, int len)
{
	unsigned int startTime;
	unsigned char *d;

	if (!c->ping)
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
	if (!func_021951E8((Conn_02196C34 *)c, func_0217F264() - startTime))
		return 0;
	return 1;
}




static GT2Bool gti2HandleClosed(struct GTI2Connection_02196C34 *connection)
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
int func_02196D00(Conn_02196CC8 *c, int type, unsigned char *message, int len)
{
	int headerLength;
	unsigned char *dataStart;
	int dataLen;

	headerLength = c->sock->headerBase + 3;
	dataStart = message + headerLength;
	dataLen = len - headerLength;
	if (type == 0x64) {
		if (!func_02196AF8((Conn_02196CC8 *)c, dataStart, dataLen))
			return 0;
	} else if (type == 0x65) {
		if (!func_02196B48((Conn_02196CC8 *)c, dataStart, dataLen))
			return 0;
	} else if (type == 0x66) {
		if (!func_02196C28(c, message, len))
			return 0;
	} else if (type == 0x67) {
		if (!func_02196C34((Conn_02196C34 *)c, dataStart, dataLen))
			return 0;
	} else if (type == 0x68) {
		if (!func_02196CC8((Conn_02196CC8 *)c))
			return 0;
	}
	return 1;
}



/*
 * sdk:      gti2HandleMessage (libdwcgsgt2.TWL.HYB.a gt2message.o)
 */
int func_02196DC4(struct GTI2Socket *socket, unsigned char *message, int len, unsigned int ip, unsigned short port)
{
    struct GTI2Connection_02196DC4 *connection;
    int magicString;
    int result;
    int type;
    int handled;
    int actualLength;
    unsigned char *actualMessage;

    actualLength = len - socket->protocolOffset;
    actualMessage = message + socket->protocolOffset;

    connection = func_02197D5C(socket, ip, port);

    if (socket->dumpCallback) {
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
                if (!func_02197BD4((struct Sock *)socket, ip, port))
                    return 0;
            }
            return 1;
        }
        if (!socket->connectAttemptCallback)
            return 1;
        result = func_021955C0(socket, &connection, ip, port);
        if (result != 0) {
            if (result != 5) {
                if (!func_02197BD4((struct Sock *)socket, ip, port))
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
            if (!func_02196098((struct Conn_02196CC8 *)connection, message, len))
                return 0;
        }
        return 1;
    }

    type = actualMessage[2];
    if (type < 8)
        return func_02196948(connection, type, message, len) != 0;
    if (!func_02196D00((Conn_02196CC8 *)((struct Conn_02196CC8 *)connection), type, message, len))
        return 0;
    return 1;
}
