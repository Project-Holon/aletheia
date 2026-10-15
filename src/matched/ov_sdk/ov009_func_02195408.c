/*
 * function: gti2DumpCallback
 * address:  0x02195408
 * packet:   pkt_ov009_02195408
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2DumpCallback (libdwcgsgt2.TWL.HYB.a(gt2callback.o))
 *
 * symbols:
 *   func_02197FDC  0x02197FDC  arm  ov009
 */

typedef struct Sock Sock;

typedef struct Conn {
	unsigned char pad0[0x24];
	int level;
} Conn;

typedef void (*DumpCb)(Sock *, Conn *, unsigned int, unsigned short, int, unsigned char *, int);

struct Sock {
	unsigned char pad0[0x14];
	int closed;
	int pad1;
	int level;
	unsigned char pad2[8];
	DumpCb sendDump;
	DumpCb recvDump;
};

extern void func_02197FDC(Sock *sock);

int gti2DumpCallback(Sock *sock, Conn *c, unsigned int ip, unsigned short port, int reset, unsigned char *msg, int len, int send)
{
	DumpCb callback;

	if (!sock)
		return 1;
	if (send)
		callback = sock->sendDump;
	else
		callback = sock->recvDump;
	if (!callback)
		return 1;
	if (!len || !msg) {
		msg = 0;
		len = 0;
	}
	sock->level++;
	if (c)
		c->level++;
	callback(sock, c, ip, port, reset, msg, len);
	sock->level--;
	if (c)
		c->level--;
	if (sock->closed && !sock->level) {
		func_02197FDC(sock);
		return 0;
	}
	return 1;
}
