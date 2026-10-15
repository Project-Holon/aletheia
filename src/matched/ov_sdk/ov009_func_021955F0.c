/*
 * function: func_021955F0
 * address:  0x021955F0
 * packet:   pkt_ov009_021955F0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2StartConnectionAttempt (libdwcgsgt2.TWL.HYB.a(gt2connection.o))
 *
 * symbols:
 *   func_02198808  0x02198808  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_02092344  0x02092344  arm
 *   func_02194B74  0x02194B74  arm  ov009
 *   func_02194C6C  0x02194C6C  arm  ov009
 *   gti2SendClientChallenge  0x021975FC  arm  ov009
 */

typedef struct Callbacks {
	int a, b, c, d;
} Callbacks;

typedef struct Conn {
	unsigned char pad0[0xc];
	int state;
	unsigned char pad1[0x18];
	Callbacks callbacks;
	void *msg;
	int msgLen;
	unsigned char pad2[0x28];
	unsigned char response[1];
} Conn;

extern void func_02198808(unsigned char **msg, int *len);
extern void *func_0217EAB0(unsigned long size);
extern void *func_02092344(void *dst, const void *src, unsigned long n);
extern unsigned char *func_02194B74(unsigned char *buf);
extern unsigned char *func_02194C6C(unsigned char *buf, unsigned char *challenge);
extern int gti2SendClientChallenge(Conn *c, char *challenge);

int func_021955F0(Conn *c, unsigned char *message, int len, Callbacks *callbacks)
{
	char challenge[32];

	func_02198808(&message, &len);
	if (len > 0) {
		c->msg = func_0217EAB0(len);
		if (!c->msg)
			return 1;
		func_02092344(c->msg, message, len);
		c->msgLen = len;
	}
	if (callbacks)
		c->callbacks = *callbacks;
	func_02194B74((unsigned char *)challenge);
	func_02194C6C(c->response, (unsigned char *)challenge);
	gti2SendClientChallenge(c, challenge);
	c->state = 0;
	return 0;
}
