/*
 * function: gti2HandleUnreliableMessage
 * address:  0x02196D00
 * packet:   pkt_ov009_02196D00
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2HandleUnreliableMessage (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * symbols:
 *   func_02196AF8  0x02196AF8  arm  ov009
 *   gti2HandleNack  0x02196B48  arm  ov009
 *   gti2HandlePing  0x02196C28  arm  ov009
 *   gti2HandlePong  0x02196C34  arm  ov009
 *   gti2HandleClosed  0x02196CC8  arm  ov009
 */

typedef struct Sock {
	unsigned char pad0[0x44];
	int headerBase;
} Sock;

typedef struct Conn {
	unsigned char pad0[8];
	Sock *sock;
} Conn;

extern int func_02196AF8(Conn *c, unsigned char *msg, int len);
extern int gti2HandleNack(Conn *c, unsigned char *msg, int len);
extern int gti2HandlePing(void *connection, unsigned char *message, int len);
extern int gti2HandlePong(Conn *c, unsigned char *msg, int len);
extern int gti2HandleClosed(Conn *c);

int gti2HandleUnreliableMessage(Conn *c, int type, unsigned char *message, int len)
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
		if (!gti2HandleNack(c, dataStart, dataLen))
			return 0;
	} else if (type == 0x66) {
		if (!gti2HandlePing(c, message, len))
			return 0;
	} else if (type == 0x67) {
		if (!gti2HandlePong(c, dataStart, dataLen))
			return 0;
	} else if (type == 0x68) {
		if (!gti2HandleClosed(c))
			return 0;
	}
	return 1;
}
