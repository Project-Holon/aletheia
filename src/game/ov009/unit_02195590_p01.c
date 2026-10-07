/*
 * file:     unit_02195590_p01.c
 * unit:     yes
 * function: func_02195590, func_021955C0, func_021955F0
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
 */
struct GTI2Socket;
struct GTI2Connection;
struct GTI2Connection {
    unsigned int ip;
    unsigned short port;
    char pad06[2];
    struct GTI2Socket *socket;
    int state;
    int field_10;
    int field_14;
    char pad18[0x10];
    char callbacks[0x10];
    char pad38[0x28];
    void *outgoingBuffers;
    char pad64[0x24];
    unsigned int lastSend;
    int pad8c;
    int pendingAck;
    unsigned int lastAck;
};

typedef struct Callbacks {
	int a, b, c, d;
} Callbacks;

typedef struct Conn {
	unsigned char pad0[0xc];
	int state;
	unsigned char pad1[0x18];
	Callbacks callbacks;
	void *msg;
	int msgLen;
	unsigned char pad2[0x28];
	unsigned char response[1];
} Conn;

extern int gti2NewSocketConnection(struct GTI2Socket *socket,
                                   struct GTI2Connection **connection,
                                   unsigned int ip, unsigned short port);
extern void func_02198808(unsigned char **msg, int *len);
extern void *func_0217EAB0(unsigned long size);
extern void *func_02092344(void *dst, const void *src, unsigned long n);
extern unsigned char *func_02194B74(unsigned char *buf);
extern unsigned char *func_02194C6C(unsigned char *buf, unsigned char *challenge);
extern int func_021975FC(Conn *c, char *challenge);
int gti2NewOutgoingConnection(struct GTI2Socket *socket, struct GTI2Connection **connection, unsigned int ip, unsigned short port);
int gti2NewIncomingConnection(struct GTI2Socket *socket, struct GTI2Connection **connection, unsigned int ip, unsigned short port);
int func_021955F0(Conn *c, unsigned char *message, int len, Callbacks *callbacks);


int gti2NewOutgoingConnection(struct GTI2Socket *socket,
                              struct GTI2Connection **connection,
                              unsigned int ip, unsigned short port)
{
    int result = gti2NewSocketConnection(socket, connection, ip, port);

    if (result)
        return result;
    (*connection)->state = 0;
    (*connection)->field_10 = 1;
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
    (*connection)->field_10 = 0;
    return 0;
}


/*
 * sdk:      gti2StartConnectionAttempt (libdwcgsgt2.TWL.HYB.a(gt2connection.o))
 */
int func_021955F0(Conn *c, unsigned char *message, int len, Callbacks *callbacks)
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
