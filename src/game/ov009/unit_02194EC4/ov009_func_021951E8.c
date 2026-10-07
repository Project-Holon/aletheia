/*
 * function: func_021951E8
 * address:  0x021951E8
 * packet:   pkt_ov009_021951E8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2PingCallback (libdwcgsgt2.TWL.HYB.a(gt2callback.o))
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
	unsigned char pad2[0x0C];
	void (*ping)(struct Conn *, int);
} Conn;

extern void func_02197FDC(Sock *sock);

int func_021951E8(Conn *c, int latency)
{
	if (!c)
		return 1;
	if (!c->ping)
		return 1;
	c->level++;
	c->sock->level++;
	c->ping(c, latency);
	c->level--;
	c->sock->level--;
	if (c->sock->closed && !c->sock->level) {
		func_02197FDC(c->sock);
		return 0;
	}
	return 1;
}
