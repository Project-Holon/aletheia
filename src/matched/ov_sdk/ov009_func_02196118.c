/*
 * function: gti2HandleAppReliable
 * address:  0x02196118
 * packet:   pkt_ov009_02196118
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2HandleAppReliable (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * symbols:
 *   gti2ConnectionCommunicationError  0x02195F5C  arm  ov009
 *   func_02184200  0x02184200  arm  ov009
 *   func_02195340  0x02195340  arm  ov009
 *   func_021950B4  0x021950B4  arm  ov009
 */

typedef struct Conn {
	unsigned char pad0[0xc];
	int state;
	unsigned char pad1[0x8c];
	void *filters;
} Conn;

extern int gti2ConnectionCommunicationError(Conn *c);
extern int func_02184200(const int *p);
extern int func_02195340(Conn *c, int filterID, unsigned char *msg, int len, int reliable);
extern int func_021950B4(Conn *c, unsigned char *msg, int len, int reliable);

int gti2HandleAppReliable(Conn *c, unsigned char *message, int len)
{
	int ret;

	if (c->state != 5 && c->state != 6) {
		if (!gti2ConnectionCommunicationError(c))
			return 0;
	} else if (func_02184200(c->filters)) {
		ret = 1;
		if (!func_02195340(c, 0, message, len, 1))
			ret = 0;
		return ret;
	} else {
		if (!func_021950B4(c, message, len, 1))
			return 0;
	}
	return 1;
}
