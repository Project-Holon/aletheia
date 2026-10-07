/*
 * file:     unit_02196C34_p01.c
 * unit:     yes
 * function: func_02196CC8, func_02196D00
 * address:  0x02196CC8
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
 *   gti2ConnectionError   0x02195ec4 arm ov009
 *   func_02196AF8  0x02196AF8  arm  ov009
 *   func_02196B48  0x02196B48  arm  ov009
 *   func_02196C28  0x02196C28  arm  ov009
 *   func_02196C34  0x02196C34  arm  ov009
 *   func_02196CC8  0x02196CC8  arm  ov009
 */
typedef int GT2Bool;

typedef enum { GT2Success, GT2OutOfMemory, GT2Rejected } GT2Result;

typedef enum { GT2LocalClose, GT2RemoteClose } GT2CloseReason;

struct GTI2Connection {
    unsigned char pad0[0xc];
    int state;
};

typedef struct Sock {
	unsigned char pad0[0x44];
	int headerBase;
} Sock;

typedef struct Conn {
	unsigned char pad0[8];
	Sock *sock;
} Conn;

extern GT2Bool gti2ConnectionError(struct GTI2Connection *connection, GT2Result result, GT2CloseReason reason);
extern int func_02196AF8(Conn *c, unsigned char *msg, int len);
extern int func_02196B48(Conn *c, unsigned char *msg, int len);
extern int func_02196C28(void *connection, unsigned char *message, int len);
extern int func_02196C34(Conn *c, unsigned char *msg, int len);
extern int func_02196CC8(Conn *c);
int func_02196D00(Conn *c, int type, unsigned char *message, int len);


static GT2Bool gti2HandleClosed(struct GTI2Connection *connection)
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
int func_02196D00(Conn *c, int type, unsigned char *message, int len)
{
	int headerLength;
	unsigned char *dataStart;
	int dataLen;

	headerLength = c->sock->headerBase + 3;
	dataStart = message + headerLength;
	dataLen = len - headerLength;
	if (type == 0x64) {
		if (!func_02196AF8(c, dataStart, dataLen))
			return 0;
	} else if (type == 0x65) {
		if (!func_02196B48(c, dataStart, dataLen))
			return 0;
	} else if (type == 0x66) {
		if (!func_02196C28(c, message, len))
			return 0;
	} else if (type == 0x67) {
		if (!func_02196C34(c, dataStart, dataLen))
			return 0;
	} else if (type == 0x68) {
		if (!func_02196CC8(c))
			return 0;
	}
	return 1;
}
