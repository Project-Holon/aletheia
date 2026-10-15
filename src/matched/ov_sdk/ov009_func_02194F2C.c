/*
 * function: gti2ConnectAttemptCallback
 * address:  0x02194F2C
 * packet:   pkt_ov009_02194F2C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2ConnectAttemptCallback (libdwcgsgt2.TWL.HYB.a(gt2callback.o))
 *
 * symbols:
 *   func_02197FDC  0x02197FDC  arm  ov009
 */

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

extern void func_02197FDC(Sock *sock);

int gti2ConnectAttemptCallback(Sock *sock, Conn *c, unsigned int ip, unsigned short port, int latency, unsigned char *msg, int len)
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
