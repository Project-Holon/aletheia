/*
 * file:     unit_02196C34_p02.c
 * unit:     yes
 * function: func_021970BC, func_021971BC
 * address:  0x021970BC
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
 *   gti2SocketFindConnection  0x02197D5C  arm  ov009
 *   gti2DumpCallback          0x02195408  arm  ov009
 *   current_time              0x0217F264  arm  ov009
 *   gti2ConnectionError       0x02195EC4  arm  ov009
 *   func_02197D5C  0x02197D5C  arm  ov009
 *   func_02195408  0x02195408  arm  ov009
 *   func_02195EC4  0x02195EC4  arm  ov009
 */
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct GTI2Connection
{
    char pad0[0xC];
    int state;
    char pad1[0xC];
    u32 startTime;
    u32 timeout;
} GTI2Connection;

typedef struct GTI2Socket
{
    char pad0[0x2C];
    void *callback;
} GTI2Socket;

typedef struct Conn Conn;

typedef struct Sock {
	unsigned char pad0[0x2c];
	void *dump;
} Sock;

extern GTI2Connection *gti2SocketFindConnection();
extern int gti2DumpCallback();
extern u32 current_time(void);
extern int gti2ConnectionError();
extern Conn *func_02197D5C(Sock *sock, unsigned int ip, unsigned short port);
extern int func_02195408(Sock *sock, Conn *c, unsigned int ip, unsigned short port, int reset, unsigned char *msg, int len, int send);
extern int func_02195EC4(Conn *c, int result, int reason);
int func_021970BC(GTI2Socket *socket, u32 ip, u16 port);
int func_021971BC(Sock *sock, unsigned int ip, unsigned short port, int send);


/*
 * sdk:      gti2HandleConnectionReset (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 */
int func_021970BC(GTI2Socket *socket, u32 ip, u16 port)
{
    GTI2Connection *connection;

    connection = gti2SocketFindConnection(socket, ip, port);
    if (socket->callback)
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
int func_021971BC(Sock *sock, unsigned int ip, unsigned short port, int send)
{
	Conn *c;

	c = func_02197D5C(sock, ip, port);
	if (sock->dump) {
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
