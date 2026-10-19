/*
 * file:     gt2callback.c
 * unit:     yes
 * function: gti2SocketErrorCallback, gti2ConnectAttemptCallback, gti2ConnectedCallback, gti2ReceivedCallback, gti2ClosedCallback, gti2PingCallback, gti2SendFilterCallback, gti2ReceiveFilterCallback, gti2DumpCallback, gti2UnrecognizedMessageCallback
 * address:  0x02194EC4
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
 *   gti2CloseSocket  0x02197FDC  arm  ov009
 *   gti2CloseSocket  0x02197FDC  arm  ov009
 *   ArrayNth  0x02184208  arm  ov009
 */
struct GTI2Connection;
struct GTI2Socket;
typedef struct GTI2Socket GTI2Socket;

typedef struct GTI2Connection GTI2Connection;

typedef void (*DumpCb)(GTI2Socket *, GTI2Connection *, unsigned int, unsigned short, int, unsigned char *, int);

typedef struct GT2ConnectionCallbacks {
	int (*connected)(GTI2Connection *, int, unsigned char *, int);
	int (*received)(GTI2Connection *, unsigned char *, int, int);
	void (*closed)(GTI2Connection *, int);
	void (*ping)(GTI2Connection *, int);
} GT2ConnectionCallbacks;

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
};

struct GTI2Connection {
	unsigned int ip;                                 /* 0x00 */
	unsigned short port;                             /* 0x04 */
	GTI2Socket *socket;                              /* 0x08 */
	int state;                                       /* 0x0C */
	unsigned char pad10[8];                          /* 0x10 */
	int result;                                      /* 0x18 */
	unsigned char pad1C[8];                          /* 0x1C */
	int callbackLevel;                               /* 0x24 */
	GT2ConnectionCallbacks callbacks;                /* 0x28 */
	unsigned char pad38[0x60];                       /* 0x38 */
	void *sendFilters;                               /* 0x98 */
	void *receiveFilters;                            /* 0x9C */
};

typedef int (*FilterCb)(GTI2Connection *, int, unsigned char *, int, int);

typedef int (*Hook)(char *p, int a1, int a2, int a3, int a4);

extern void gti2CloseSocket(GTI2Socket *socket);
extern void gti2CloseSocket(GTI2Socket *sock);
extern FilterCb *ArrayNth(void *array, int n);
int gti2SocketErrorCallback(GTI2Socket *socket);
int gti2ConnectAttemptCallback(GTI2Socket *sock, GTI2Connection *c, unsigned int ip, unsigned short port, int latency, unsigned char *msg, int len);
int gti2ConnectedCallback(GTI2Connection *c, int result, unsigned char *msg, int len);
int gti2ReceivedCallback(GTI2Connection *c, unsigned char *msg, int len, int reliable);
int gti2ClosedCallback(GTI2Connection *connection, int reason);
int gti2PingCallback(GTI2Connection *c, int latency);
int gti2SendFilterCallback(GTI2Connection *c, int filterID, unsigned char *msg, int len, int reliable);
int gti2ReceiveFilterCallback(GTI2Connection *c, int filterID, unsigned char *msg, int len, int reliable);
int gti2DumpCallback(GTI2Socket *sock, GTI2Connection *c, unsigned int ip, unsigned short port, int reset, unsigned char *msg, int len, int send);
int gti2UnrecognizedMessageCallback(char *p, int ip, int port, int message, int len, int *handled);







int gti2SocketErrorCallback(GTI2Socket *socket)
{
    if (socket == 0)
        return 1;
    if (socket->socketErrorCallback == 0)
        return 1;
    socket->callbackLevel++;
    socket->socketErrorCallback(socket);
    socket->callbackLevel--;
    if (socket->close != 0 && socket->callbackLevel == 0)
    {
        gti2CloseSocket(socket);
        return 0;
    }
    return 1;
}







/*
 * sdk:      gti2ConnectAttemptCallback (libdwcgsgt2.TWL.HYB.a(gt2callback.o))
 */
int gti2ConnectAttemptCallback(GTI2Socket *sock, GTI2Connection *c, unsigned int ip, unsigned short port, int latency, unsigned char *msg, int len)
{
	if (!sock || !c)
		return 1;
	if (!sock->connectAttemptCallback)
		return 1;
	if (len == 0 || msg == 0) {
		msg = 0;
		len = 0;
	}
	sock->callbackLevel++;
	c->callbackLevel++;
	sock->connectAttemptCallback(sock, c, ip, port, latency, msg, len);
	sock->callbackLevel--;
	c->callbackLevel--;
	if (sock->close && !sock->callbackLevel) {
		gti2CloseSocket(sock);
		return 0;
	}
	return 1;
}






/*
 * sdk:      gti2ConnectedCallback (libdwcgsgt2.TWL.HYB.a(gt2callback.o))
 */
int gti2ConnectedCallback(GTI2Connection *c, int result, unsigned char *msg, int len)
{
	if (!c)
		return 1;
	c->result = result;
	if (!c->callbacks.connected)
		return 1;
	c->callbackLevel++;
	if (!len || !msg) {
		msg = 0;
		len = 0;
	}
	c->socket->callbackLevel++;
	c->callbacks.connected(c, result, msg, len);
	c->callbackLevel--;
	c->socket->callbackLevel--;
	if (c->socket->close && !c->socket->callbackLevel) {
		gti2CloseSocket(c->socket);
		return 0;
	}
	return 1;
}






/*
 * sdk:      gti2ReceivedCallback (libdwcgsgt2.TWL.HYB.a(gt2callback.o))
 */
int gti2ReceivedCallback(GTI2Connection *c, unsigned char *msg, int len, int reliable)
{
	if (!c)
		return 1;
	if (!c->callbacks.received)
		return 1;
	c->callbackLevel++;
	if (!len || !msg) {
		msg = 0;
		len = 0;
	}
	c->socket->callbackLevel++;
	c->callbacks.received(c, msg, len, reliable);
	c->callbackLevel--;
	c->socket->callbackLevel--;
	if (c->socket->close && !c->socket->callbackLevel) {
		gti2CloseSocket(c->socket);
		return 0;
	}
	return 1;
}






int gti2ClosedCallback(GTI2Connection *connection, int reason)
{
    if (!connection)
        return 1;
    if (!connection->callbacks.closed)
        return 1;
    connection->callbackLevel++;
    connection->socket->callbackLevel++;
    connection->callbacks.closed(connection, reason);
    connection->callbackLevel--;
    connection->socket->callbackLevel--;
    if ((connection->socket->close != 0) &&
        (connection->socket->callbackLevel == 0))
    {
        gti2CloseSocket(connection->socket);
        return 0;
    }
    return 1;
}




/*
 * sdk:      gti2PingCallback (libdwcgsgt2.TWL.HYB.a(gt2callback.o))
 */
int gti2PingCallback(GTI2Connection *c, int latency)
{
	if (!c)
		return 1;
	if (!c->callbacks.ping)
		return 1;
	c->callbackLevel++;
	c->socket->callbackLevel++;
	c->callbacks.ping(c, latency);
	c->callbackLevel--;
	c->socket->callbackLevel--;
	if (c->socket->close && !c->socket->callbackLevel) {
		gti2CloseSocket(c->socket);
		return 0;
	}
	return 1;
}



/*
 * sdk:      gti2SendFilterCallback (libdwcgsgt2.TWL.HYB.a(gt2callback.o))
 */
int gti2SendFilterCallback(GTI2Connection *c, int filterID, unsigned char *msg, int len, int reliable)
{
	FilterCb *callback;

	if (!c)
		return 1;
	callback = ArrayNth(c->sendFilters, filterID);
	if (!callback)
		return 1;
	if (!len || !msg) {
		msg = 0;
		len = 0;
	}
	c->callbackLevel++;
	c->socket->callbackLevel++;
	(*callback)(c, filterID, msg, len, reliable);
	c->callbackLevel--;
	c->socket->callbackLevel--;
	if (c->socket->close && !c->socket->callbackLevel) {
		gti2CloseSocket(c->socket);
		return 0;
	}
	return 1;
}




/*
 * sdk:      gti2ReceiveFilterCallback (libdwcgsgt2.TWL.HYB.a(gt2callback.o))
 */
int gti2ReceiveFilterCallback(GTI2Connection *c, int filterID, unsigned char *msg, int len, int reliable)
{
	FilterCb *callback;

	if (!c)
		return 1;
	callback = ArrayNth(c->receiveFilters, filterID);
	if (!callback)
		return 1;
	if (!len || !msg) {
		msg = 0;
		len = 0;
	}
	c->callbackLevel++;
	c->socket->callbackLevel++;
	(*callback)(c, filterID, msg, len, reliable);
	c->callbackLevel--;
	c->socket->callbackLevel--;
	if (c->socket->close && !c->socket->callbackLevel) {
		gti2CloseSocket((GTI2Socket *)c->socket);
		return 0;
	}
	return 1;
}




/*
 * sdk:      gti2DumpCallback (libdwcgsgt2.TWL.HYB.a(gt2callback.o))
 */
int gti2DumpCallback(GTI2Socket *sock, GTI2Connection *c, unsigned int ip, unsigned short port, int reset, unsigned char *msg, int len, int send)
{
	DumpCb callback;

	if (!sock)
		return 1;
	if (send)
		callback = sock->sendDump;
	else
		callback = sock->recvDump;
	if (!callback)
		return 1;
	if (!len || !msg) {
		msg = 0;
		len = 0;
	}
	sock->callbackLevel++;
	if (c)
		c->callbackLevel++;
	callback(sock, c, ip, port, reset, msg, len);
	sock->callbackLevel--;
	if (c)
		c->callbackLevel--;
	if (sock->close && !sock->callbackLevel) {
		gti2CloseSocket((GTI2Socket *)sock);
		return 0;
	}
	return 1;
}



/*
 * Bracket a call to the object's +0x30 hook with the +0x1c counter: clear the
 * caller's output word, zero the last two arguments when either is zero, bump
 * the counter, call the hook with all five arguments, store the result back
 * through the pointer, drop the counter and report whether the object still
 * has work outstanding.
 */
int gti2UnrecognizedMessageCallback(char *socket, int ip, int port, int message, int len, int *handled)
{
    int r;

    *handled = 0;
    if (socket == 0)
        return 1;
    if (*(int *)(socket + 0x30) == 0)
        return 1;

    if (len == 0 || message == 0) {
        message = 0;
        len = 0;
    }

    *(int *)(socket + 0x1c) += 1;
    r = (*(Hook *)(socket + 0x30))(socket, ip, port, message, len);
    *handled = r;

    *(int *)(socket + 0x1c) -= 1;
    if (*(int *)(socket + 0x14) != 0 && *(int *)(socket + 0x1c) == 0) {
        gti2CloseSocket((GTI2Socket *)socket);
        return 0;
    }
    return 1;
}
