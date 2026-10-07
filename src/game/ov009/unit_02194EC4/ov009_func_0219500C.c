/*
 * function: func_0219500C
 * address:  0x0219500C
 * packet:   pkt_ov009_0219500C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2ConnectedCallback (libdwcgsgt2.TWL.HYB.a(gt2callback.o))
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
	unsigned char pad1[0x0C];
	int result;
	unsigned char pad2[8];
	int level;
	int (*connected)(struct Conn *, int, unsigned char *, int);
} Conn;

extern void func_02197FDC(Sock *sock);

int func_0219500C(Conn *c, int result, unsigned char *msg, int len)
{
	if (!c)
		return 1;
	c->result = result;
	if (!c->connected)
		return 1;
	c->level++;
	if (!len || !msg) {
		msg = 0;
		len = 0;
	}
	c->sock->level++;
	c->connected(c, result, msg, len);
	c->level--;
	c->sock->level--;
	if (c->sock->closed && !c->sock->level) {
		func_02197FDC(c->sock);
		return 0;
	}
	return 1;
}
