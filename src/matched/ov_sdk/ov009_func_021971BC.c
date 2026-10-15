/*
 * function: gti2HandleHostUnreachable
 * address:  0x021971BC
 * packet:   pkt_ov009_021971BC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2HandleHostUnreachable (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * symbols:
 *   func_02197D5C  0x02197D5C  arm  ov009
 *   gti2DumpCallback  0x02195408  arm  ov009
 *   func_02195EC4  0x02195EC4  arm  ov009
 */

typedef struct Conn Conn;

typedef struct Sock {
	unsigned char pad0[0x2c];
	void *dump;
} Sock;

extern Conn *func_02197D5C(Sock *sock, unsigned int ip, unsigned short port);
extern int gti2DumpCallback(Sock *sock, Conn *c, unsigned int ip, unsigned short port, int reset, unsigned char *msg, int len, int send);
extern int func_02195EC4(Conn *c, int result, int reason);

int gti2HandleHostUnreachable(Sock *sock, unsigned int ip, unsigned short port, int send)
{
	Conn *c;

	c = func_02197D5C(sock, ip, port);
	if (sock->dump) {
		if (!gti2DumpCallback(sock, c, ip, port, 1, 0, 0, send))
			return 0;
	}
	if (!c)
		return 1;
	send = 1;
	if (!func_02195EC4(c, 6, send))
		send = 0;
	return send;
}
