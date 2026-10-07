/*
 * function: func_02195278
 * address:  0x02195278
 * packet:   pkt_ov009_02195278
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2SendFilterCallback (libdwcgsgt2.TWL.HYB.a(gt2callback.o))
 *
 * symbols:
 *   func_02184208  0x02184208  arm  ov009
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
	unsigned char pad2[0x70];
	void *filters;
} Conn;

typedef int (*FilterCb)(Conn *, int, unsigned char *, int, int);

extern FilterCb *func_02184208(void *array, int n);
extern void func_02197FDC(Sock *sock);

int func_02195278(Conn *c, int filterID, unsigned char *msg, int len, int reliable)
{
	FilterCb *callback;

	if (!c)
		return 1;
	callback = func_02184208(c->filters, filterID);
	if (!callback)
		return 1;
	if (!len || !msg) {
		msg = 0;
		len = 0;
	}
	c->level++;
	c->sock->level++;
	(*callback)(c, filterID, msg, len, reliable);
	c->level--;
	c->sock->level--;
	if (c->sock->closed && !c->sock->level) {
		func_02197FDC(c->sock);
		return 0;
	}
	return 1;
}
