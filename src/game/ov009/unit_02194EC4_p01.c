/*
 * file:     unit_02194EC4_p01.c
 * unit:     yes
 * function: func_02194EC4, func_02194F2C
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
 *   func_02197FDC  0x02197FDC  arm  ov009
 */
struct GTI2Socket {
    int socket;
    unsigned int ip;
    unsigned short port;
    struct HashImplementation *connections;
    struct DArrayImplementation *closedConnections;
    int close;
    int error;
    int callbackLevel;
    void (*connectAttemptCallback)(void);
    void (*socketErrorCallback)(struct GTI2Socket *);
};

typedef struct Conn {
	unsigned char pad0[0x24];
	int level;
} Conn;

typedef struct Sock {
	unsigned char pad0[0x14];
	int closed;
	int pad1;
	int level;
	void (*attempt)(struct Sock *, Conn *, unsigned int, unsigned short, int, unsigned char *, int);
} Sock;

extern void gti2CloseSocket(struct GTI2Socket *socket);
extern void func_02197FDC(Sock *sock);
int gti2SocketErrorCallback(struct GTI2Socket *socket);
int func_02194F2C(Sock *sock, Conn *c, unsigned int ip, unsigned short port, int latency, unsigned char *msg, int len);


int gti2SocketErrorCallback(struct GTI2Socket *socket)
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
int func_02194F2C(Sock *sock, Conn *c, unsigned int ip, unsigned short port, int latency, unsigned char *msg, int len)
{
	if (!sock || !c)
		return 1;
	if (!sock->attempt)
		return 1;
	if (len == 0 || msg == 0) {
		msg = 0;
		len = 0;
	}
	sock->level++;
	c->level++;
	sock->attempt(sock, c, ip, port, latency, msg, len);
	sock->level--;
	c->level--;
	if (sock->closed && !sock->level) {
		func_02197FDC(sock);
		return 0;
	}
	return 1;
}
