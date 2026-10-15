/*
 * function: gti2StartConnectionAttempt
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
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   func_02092344  0x02092344  arm
 *   gti2GetChallenge  0x02194B74  arm  ov009
 *   gti2GetResponse  0x02194C6C  arm  ov009
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
extern void *gsimalloc(unsigned long size);
extern void *func_02092344(void *dst, const void *src, unsigned long n);
extern unsigned char *gti2GetChallenge(unsigned char *buf);
extern unsigned char *gti2GetResponse(unsigned char *buf, unsigned char *challenge);
extern int gti2SendClientChallenge(Conn *c, char *challenge);

int gti2StartConnectionAttempt(Conn *c, unsigned char *message, int len, Callbacks *callbacks)
{
	char challenge[32];

	func_02198808(&message, &len);
	if (len > 0) {
		c->msg = gsimalloc(len);
		if (!c->msg)
			return 1;
		func_02092344(c->msg, message, len);
		c->msgLen = len;
	}
	if (callbacks)
		c->callbacks = *callbacks;
	gti2GetChallenge((unsigned char *)challenge);
	gti2GetResponse(c->response, (unsigned char *)challenge);
	gti2SendClientChallenge(c, challenge);
	c->state = 0;
	return 0;
}
