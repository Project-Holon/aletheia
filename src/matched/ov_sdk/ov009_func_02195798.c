/*
 * function: func_02195798
 * address:  0x02195798
 * packet:   pkt_ov009_02195798
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2CheckTimeout (libdwcgsgt2.TWL.HYB.a(gt2connection.o))
 *
 * symbols:
 *   func_02197BB8  0x02197BB8  arm  ov009
 *   func_021959D0  0x021959D0  arm  ov009
 *   func_0219500C  0x0219500C  arm  ov009
 */

typedef struct Conn {
	unsigned char pad0[0xc];
	int state;
	int useTimeout;
	unsigned char pad1[8];
	unsigned int start;
	unsigned int timeout;
} Conn;

extern void func_02197BB8(int *p);
extern void func_021959D0(Conn *c);
extern int func_0219500C(Conn *c, int result, unsigned char *msg, int len);

int func_02195798(Conn *c, unsigned int now)
{
	int timedOut;

	if (c->state < 5) {
		timedOut = 0;
		if (c->useTimeout) {
			if (c->timeout) {
				if (now - c->start > c->timeout)
					timedOut = 1;
			}
		} else if (c->state < 4) {
			if (now - c->start > 60000)
				timedOut = 1;
		}
		if (timedOut) {
			func_02197BB8((int *)c);
			func_021959D0(c);
			if (!func_0219500C(c, 6, 0, 0))
				return 0;
		}
	}
	return 1;
}
