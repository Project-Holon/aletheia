/*
 * function: gti2ReceivedCallback
 * address:  0x021950B4
 * packet:   pkt_ov009_021950B4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2ReceivedCallback (libdwcgsgt2.TWL.HYB.a(gt2callback.o))
 *
 * symbols:
 *   func_02197FDC  0x02197FDC  arm  ov009
 */

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

extern void func_02197FDC(Sock *sock);

int gti2ReceivedCallback(Conn *c, unsigned char *msg, int len, int reliable)
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
