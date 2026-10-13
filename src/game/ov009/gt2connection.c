/*
 * file:     gt2connection.c
 * unit:     yes
 * function: func_02195590, func_021955C0, func_021955F0, func_0219569C, func_021956F8, func_02195750, func_02195798, func_0219583C, func_021958A8, func_021958E4, func_02195918, func_02195980, func_021959D0, func_02195A30
 * address:  0x02195590
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
 *   gti2NewSocketConnection  0x02198038 arm
 *   func_02198808  0x02198808  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_02092344  0x02092344  arm
 *   func_02194B74  0x02194B74  arm  ov009
 *   func_02194C6C  0x02194C6C  arm  ov009
 *   func_021975FC  0x021975FC  arm  ov009
 *   gti2SendAccept  0x02197784 arm
 *   gti2MessageCheck  0x02198808 arm
 *   gti2SendReject    0x021977E8 arm
 *   gti2SocketSend  0x02198328 arm
 *   current_time    0x0217F264 arm
 *   func_02197BB8  0x02197BB8  arm  ov009
 *   func_0219500C  0x0219500C  arm  ov009
 *   ArrayLength       0x02184200 arm
 *   ArrayNth          0x02184208 arm
 *   gti2ResendMessage 0x02197C5C arm
 *   gti2SendAck  0x02197A30 arm
 *   gti2SendKeepAlive  0x021978CC arm
 *   gti2SendClosed          0x02197BB8 arm
 *   gti2ClosedCallback      0x02195158 arm
 *   gti2FreeSocketConnection 0x02198264 arm
 *   gti2SendClose           0x02197868 arm
 *   TableRemove  0x021847BC arm
 *   ArrayAppend  0x02184234 arm
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_021841B0  0x021841B0  arm  ov009
 */
struct GTI2Socket;
struct DArrayImplementation;
struct GTI2Connection;
struct HashImplementation;
struct GT2ConnectionCallbacks {
    void *connected;
    void *received;
    void *closed;
    void *ping;
};

struct GTI2Connection {
    unsigned int ip;                              /* +0x00 */
    unsigned short port;                          /* +0x04 */
    char pad06[2];
    struct GTI2Socket *socket;                    /* +0x08 */
    int state;                                    /* +0x0c */
    int initiated;                                /* +0x10 */
    int field_14;                                 /* +0x14 */
    char pad18[4];
    unsigned int startTime;                       /* +0x1c */
    unsigned int timeout;                         /* +0x20 */
    char pad24[4];
    struct GT2ConnectionCallbacks callbacks;      /* +0x28 */
    void *msg;                                    /* +0x38 */
    int msgLen;                                   /* +0x3c */
    char pad40[4];
    void *buf44;                                  /* +0x44 */
    char pad48[8];
    void *buf50;                                  /* +0x50 */
    char pad54[8];
    void *arr5c;                                  /* +0x5c */
    struct DArrayImplementation *outgoingBuffers; /* +0x60 */
    char pad64[4];
    unsigned char response[0x20];                 /* +0x68 */
    unsigned int lastSend;                        /* +0x88 */
    int pad8c;
    int pendingAck;                               /* +0x90 */
    unsigned int lastAck;                         /* +0x94 */
    void *arr98;                                  /* +0x98 */
    void *arr9c;                                  /* +0x9c */
};

struct GTI2OutgoingBufferMessage {
    char pad00[0xc];
    unsigned int field_0c;
};

struct GTI2Socket {
    char pad00[0xc];
    struct HashImplementation *connections;
    struct DArrayImplementation *closedConnections;
};

extern int gti2NewSocketConnection(struct GTI2Socket *socket,
                                   struct GTI2Connection **connection,
                                   unsigned int ip, unsigned short port);
extern void func_02198808(unsigned char **msg, int *len);
extern void *func_0217EAB0(unsigned long size);
extern void *func_02092344(void *dst, const void *src, unsigned long n);
extern unsigned char *func_02194B74(unsigned char *buf);
extern unsigned char *func_02194C6C(unsigned char *buf, unsigned char *challenge);
extern int func_021975FC(struct GTI2Connection *c, char *challenge);
extern int gti2SendAccept(struct GTI2Connection *connection);
extern void gti2MessageCheck(unsigned char **message, int *len);
extern int gti2SendReject(struct GTI2Connection *connection,
                          unsigned char *message, int len);
extern int gti2SocketSend(struct GTI2Socket *socket, unsigned int ip,
                          unsigned short port, unsigned char *message, int len);
extern unsigned int current_time(void);
extern int gti2SendClosed(struct GTI2Connection *connection);
extern int func_0219500C(struct GTI2Connection *c, int result, unsigned char *msg, int len);
extern int ArrayLength(struct DArrayImplementation *array);
extern void *ArrayNth(struct DArrayImplementation *array, int n);
extern int gti2ResendMessage(struct GTI2Connection *connection,
                             struct GTI2OutgoingBufferMessage *message);
extern int gti2SendAck(struct GTI2Connection *connection);
extern int gti2SendKeepAlive(struct GTI2Connection *connection);
extern int gti2ClosedCallback(struct GTI2Connection *connection, int reason);
extern void gti2FreeSocketConnection(struct GTI2Connection *connection);
extern int gti2SendClose(struct GTI2Connection *connection);
extern int TableRemove(struct HashImplementation *table, void *delElem);
extern void ArrayAppend(struct DArrayImplementation *array, void *newElem);
extern void func_0217EAE0(void *ptr);
extern void func_021841B0(void *array);
int gti2NewOutgoingConnection(struct GTI2Socket *socket, struct GTI2Connection **connection, unsigned int ip, unsigned short port);
int gti2NewIncomingConnection(struct GTI2Socket *socket, struct GTI2Connection **connection, unsigned int ip, unsigned short port);
int func_021955F0(struct GTI2Connection *c, unsigned char *message, int len, struct GT2ConnectionCallbacks *callbacks);
int gti2AcceptConnection(struct GTI2Connection *connection, struct GT2ConnectionCallbacks *callbacks);
void gti2RejectConnection(struct GTI2Connection *connection, unsigned char *message, int len);
int gti2ConnectionSendData(struct GTI2Connection *connection, unsigned char *message, int len);
int func_02195798(struct GTI2Connection *c, unsigned int now);
int gti2ConnectionThink(struct GTI2Connection *connection, unsigned int now);
void gti2CloseConnection(struct GTI2Connection *connection, int hard);
void gti2ConnectionClosed(struct GTI2Connection *connection);
void func_02195A30(struct GTI2Connection *c);






int gti2NewOutgoingConnection(struct GTI2Socket *socket,
                              struct GTI2Connection **connection,
                              unsigned int ip, unsigned short port)
{
    int result = gti2NewSocketConnection(socket, connection, ip, port);

    if (result)
        return result;
    (*connection)->state = 0;
    (*connection)->initiated = 1;
    return 0;
}






int gti2NewIncomingConnection(struct GTI2Socket *socket,
                              struct GTI2Connection **connection,
                              unsigned int ip, unsigned short port)
{
    int result = gti2NewSocketConnection(socket, connection, ip, port);

    if (result)
        return result;
    (*connection)->state = 2;
    (*connection)->initiated = 0;
    return 0;
}






/*
 * sdk:      gti2StartConnectionAttempt (libdwcgsgt2.TWL.HYB.a(gt2connection.o))
 */
int func_021955F0(struct GTI2Connection *c, unsigned char *message, int len, struct GT2ConnectionCallbacks *callbacks)
{
	char challenge[32];

	func_02198808(&message, &len);
	if (len > 0) {
		c->msg = func_0217EAB0(len);
		if (!c->msg)
			return 1;
		func_02092344(c->msg, message, len);
		c->msgLen = len;
	}
	if (callbacks)
		c->callbacks = *callbacks;
	func_02194B74((unsigned char *)challenge);
	func_02194C6C(c->response, (unsigned char *)challenge);
	func_021975FC(c, challenge);
	c->state = 0;
	return 0;
}






int gti2AcceptConnection(struct GTI2Connection *connection,
                         struct GT2ConnectionCallbacks *callbacks)
{
    if (connection->field_14)
    {
        connection->field_14 = 0;
        return 0;
    }
    connection->field_14 = 0;
    if (connection->state != 4)
        return 0;
    gti2SendAccept(connection);
    connection->state = 5;
    if (callbacks)
        connection->callbacks = *callbacks;
    return 1;
}






void gti2RejectConnection(struct GTI2Connection *connection,
                          unsigned char *message, int len)
{
    connection->field_14 = 0;
    if (connection->state != 4)
        return;
    gti2MessageCheck(&message, &len);
    gti2SendReject(connection, message, len);
    connection->state = 6;
}






int gti2ConnectionSendData(struct GTI2Connection *connection,
                           unsigned char *message, int len)
{
    if (gti2SocketSend(connection->socket, connection->ip, connection->port,
                       message, len) == 0)
        return 0;
    connection->lastSend = current_time();
    return 1;
}






/*
 * sdk:      gti2CheckTimeout (libdwcgsgt2.TWL.HYB.a(gt2connection.o))
 */
int func_02195798(struct GTI2Connection *c, unsigned int now)
{
	int timedOut;

	if (c->state < 5) {
		timedOut = 0;
		if (c->initiated) {
			if (c->timeout) {
				if (now - c->startTime > c->timeout)
					timedOut = 1;
			}
		} else if (c->state < 4) {
			if (now - c->startTime > 60000)
				timedOut = 1;
		}
		if (timedOut) {
			gti2SendClosed(c);
			gti2ConnectionClosed(c);
			if (!func_0219500C(c, 6, 0, 0))
				return 0;
		}
	}
	return 1;
}





static int gti2SendRetries(struct GTI2Connection *connection, unsigned int now)
{
    int i;
    int len;

    len = ArrayLength(connection->outgoingBuffers);
    for (i = 0; i < len; i++)
    {
        struct GTI2OutgoingBufferMessage *message =
            ArrayNth(connection->outgoingBuffers, i);

        if ((now - message->field_0c) > 1000)
        {
            if (gti2ResendMessage(connection, message) == 0)
                return 0;
        }
    }
    return 1;
}





static int gti2CheckPendingAck(struct GTI2Connection *connection,
                               unsigned int now)
{
    if (!connection->pendingAck)
        return 1;
    if ((now - connection->lastAck) > 100)
    {
        if (gti2SendAck(connection) == 0)
            return 0;
    }
    return 1;
}





static int gti2CheckKeepAlive(struct GTI2Connection *connection,
                              unsigned int now)
{
    if ((now - connection->lastSend) > 30000)
    {
        if (gti2SendKeepAlive(connection) == 0)
            return 0;
    }
    return 1;
}




int gti2ConnectionThink(struct GTI2Connection *connection, unsigned int now)
{
    if (func_02195798(connection, now) == 0)
        return 0;
    if (gti2CheckKeepAlive(connection, now) == 0)
        return 0;
    if (gti2SendRetries(connection, now) == 0)
        return 0;
    return gti2CheckPendingAck(connection, now) != 0;
}




void gti2CloseConnection(struct GTI2Connection *connection, int hard)
{
    if (hard)
    {
        if (connection->state >= 7)
            return;
        gti2ConnectionClosed(connection);
        gti2SendClosed(connection);
        gti2ClosedCallback(connection, 0);
        gti2FreeSocketConnection(connection);
    }
    else
    {
        connection->state = 6;
        gti2SendClose(connection);
    }
}



void gti2ConnectionClosed(struct GTI2Connection *connection)
{
    if (connection->state == 7)
        return;
    connection->state = 7;
    TableRemove(connection->socket->connections, &connection);
    ArrayAppend(connection->socket->closedConnections, &connection);
}



/*
 * sdk:      gti2ConnectionCleanup (libdwcgsgt2.TWL.HYB.a(gt2connection.o))
 */
void func_02195A30(struct GTI2Connection *c)
{
	if (c->msg)
		func_0217EAE0(c->msg);
	if (c->buf44)
		func_0217EAE0(c->buf44);
	if (c->buf50)
		func_0217EAE0(c->buf50);
	if (c->arr5c)
		func_021841B0(c->arr5c);
	if (c->outgoingBuffers)
		func_021841B0(c->outgoingBuffers);
	if (c->arr98)
		func_021841B0(c->arr98);
	if (c->arr9c)
		func_021841B0(c->arr9c);
	func_0217EAE0(c);
}
