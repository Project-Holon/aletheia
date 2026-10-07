/*
 * file:     unit_02194EC4_p02.c
 * unit:     yes
 * function: func_021950B4, func_02195158
 * address:  0x021950B4
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
 *   func_02197FDC  0x02197FDC  arm  ov009
 *   gti2CloseSocket  0x02197FDC arm
 */
struct GTI2Connection;
struct GTI2Socket;
typedef struct Sock {
	unsigned char pad0[0x14];
	int closed;
	int pad1;
	int level;
} Sock;

typedef struct Conn {
	unsigned char pad0[8];
	Sock *sock;
	unsigned char pad1[0x18];
	int level;
	unsigned char pad2[4];
	int (*received)(struct Conn *, unsigned char *, int, int);
} Conn;

typedef void (*GT2ClosedCallbackFn)(struct GTI2Connection *, int);

struct GT2ConnectionCallbacks {
    void *connected;
    void *received;
    GT2ClosedCallbackFn closed;
    void *ping;
};

struct GTI2Socket {
    char pad00[0x14];
    int field_14;
    char pad18[4];
    int field_1c;
};

struct GTI2Connection {
    char pad00[8];
    struct GTI2Socket *socket;
    int state;
    int field_10;
    int field_14;
    char pad18[0xc];
    int field_24;
    struct GT2ConnectionCallbacks callbacks;
};

extern void func_02197FDC(Sock *sock);
extern void gti2CloseSocket(struct GTI2Socket *socket);
int func_021950B4(Conn *c, unsigned char *msg, int len, int reliable);
int gti2ClosedCallback(struct GTI2Connection *connection, int reason);


/*
 * sdk:      gti2ReceivedCallback (libdwcgsgt2.TWL.HYB.a(gt2callback.o))
 */
int func_021950B4(Conn *c, unsigned char *msg, int len, int reliable)
{
	if (!c)
		return 1;
	if (!c->received)
		return 1;
	c->level++;
	if (!len || !msg) {
		msg = 0;
		len = 0;
	}
	c->sock->level++;
	c->received(c, msg, len, reliable);
	c->level--;
	c->sock->level--;
	if (c->sock->closed && !c->sock->level) {
		func_02197FDC(c->sock);
		return 0;
	}
	return 1;
}


int gti2ClosedCallback(struct GTI2Connection *connection, int reason)
{
    if (!connection)
        return 1;
    if (!connection->callbacks.closed)
        return 1;
    connection->field_24++;
    connection->socket->field_1c++;
    connection->callbacks.closed(connection, reason);
    connection->field_24--;
    connection->socket->field_1c--;
    if ((connection->socket->field_14 != 0) &&
        (connection->socket->field_1c == 0))
    {
        gti2CloseSocket(connection->socket);
        return 0;
    }
    return 1;
}
