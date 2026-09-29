/*
 * function: func_02197700
 * address:  0x02197700
 * packet:   pkt_ov009_02197700
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2SendClientResponse (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * symbols:
 *   func_02197458  0x02197458  arm  ov009
 *   func_02194E2C  0x02194E2C  arm  ov009
 *   func_0219754C  0x0219754C  arm  ov009
 */

typedef struct Sock {
	unsigned char pad0[0x44];
	int overhead;
} Sock;

typedef struct Conn {
	unsigned char pad0[8];
	Sock *sock;
	unsigned char pad1[0x44];
	unsigned char buffer[1];
} Conn;

extern int func_02197458(Conn *c, int type, int len, int *overflow);
extern void func_02194E2C(void *buffer, unsigned char *data, int len);
extern int func_0219754C(Conn *c);

int func_02197700(Conn *c, char *response, char *message, int len)
{
	int overflow;

	if (!func_02197458(c, 3, len + 0x27 + c->sock->overhead, &overflow))
		return 0;
	if (overflow)
		return 1;
	func_02194E2C(c->buffer, (unsigned char *)response, 0x20);
	func_02194E2C(c->buffer, (unsigned char *)message, len);
	return func_0219754C(c) ? 1 : 0;
}
