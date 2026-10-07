/*
 * file:     unit_02195590_p02.c
 * unit:     yes
 * function: func_0219569C, func_021956F8, func_02195750, func_02195798
 * address:  0x0219569C
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
 *   gti2SendAccept  0x02197784 arm
 *   gti2MessageCheck  0x02198808 arm
 *   gti2SendReject    0x021977E8 arm
 *   gti2SocketSend  0x02198328 arm
 *   current_time    0x0217F264 arm
 *   func_02197BB8  0x02197BB8  arm  ov009
 *   func_021959D0  0x021959D0  arm  ov009
 *   func_0219500C  0x0219500C  arm  ov009
 */
struct GTI2Connection_0219569C;
struct GTI2Socket;
struct GT2ConnectionCallbacks {
    void *connected;
    void *received;
    void *closed;
    void *ping;
};

struct GTI2Connection_0219569C {
    unsigned int ip;
    unsigned short port;
    char pad06[2];
    void *socket;
    int state;
    int field_10;
    int field_14;
    char pad18[0x10];
    struct GT2ConnectionCallbacks callbacks;
};

struct GTI2Connection_021956F8 {
    unsigned int ip;
    unsigned short port;
    char pad06[2];
    void *socket;
    int state;
    int field_10;
    int field_14;
};

struct GTI2Connection_02195750 {
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
};

typedef struct Conn {
	unsigned char pad0[0xc];
	int state;
	int useTimeout;
	unsigned char pad1[8];
	unsigned int start;
	unsigned int timeout;
} Conn;

extern int gti2SendAccept(struct GTI2Connection_0219569C *connection);
extern void gti2MessageCheck(unsigned char **message, int *len);
extern int gti2SendReject(struct GTI2Connection_021956F8 *connection,
                          unsigned char *message, int len);
extern int gti2SocketSend(struct GTI2Socket *socket, unsigned int ip,
                          unsigned short port, unsigned char *message, int len);
extern unsigned int current_time(void);
extern int func_02197BB8(int *p);
extern void func_021959D0(Conn *c);
extern int func_0219500C(Conn *c, int result, unsigned char *msg, int len);
int gti2AcceptConnection(struct GTI2Connection_0219569C *connection, struct GT2ConnectionCallbacks *callbacks);
void gti2RejectConnection(struct GTI2Connection_021956F8 *connection, unsigned char *message, int len);
int gti2ConnectionSendData(struct GTI2Connection_02195750 *connection, unsigned char *message, int len);
int func_02195798(Conn *c, unsigned int now);


int gti2AcceptConnection(struct GTI2Connection_0219569C *connection,
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


void gti2RejectConnection(struct GTI2Connection_021956F8 *connection,
                          unsigned char *message, int len)
{
    connection->field_14 = 0;
    if (connection->state != 4)
        return;
    gti2MessageCheck(&message, &len);
    gti2SendReject(connection, message, len);
    connection->state = 6;
}


int gti2ConnectionSendData(struct GTI2Connection_02195750 *connection,
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
int func_02195798(Conn *c, unsigned int now)
{
	int timedOut;

	if (c->state < 5) {
		timedOut = 0;
		if (c->useTimeout) {
			if (c->timeout) {
				if (now - c->start > c->timeout)
					timedOut = 1;
			}
		} else if (c->state < 4) {
			if (now - c->start > 60000)
				timedOut = 1;
		}
		if (timedOut) {
			func_02197BB8((int *)c);
			func_021959D0(c);
			if (!func_0219500C(c, 6, 0, 0))
				return 0;
		}
	}
	return 1;
}
