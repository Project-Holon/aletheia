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
 *   ArrayLength  0x02184200  arm  ov009
 *   gti2ReceiveFilterCallback  0x02195340  arm  ov009
 *   gti2ReceivedCallback  0x021950B4  arm  ov009
 */

typedef struct Conn {
	unsigned char pad0[0xc];
	int state;
	unsigned char pad1[0x8c];
	void *filters;
} Conn;

extern int gti2ConnectionCommunicationError(Conn *c);
extern int ArrayLength(const int *p);
extern int gti2ReceiveFilterCallback(Conn *c, int filterID, unsigned char *msg, int len, int reliable);
extern int gti2ReceivedCallback(Conn *c, unsigned char *msg, int len, int reliable);

int gti2HandleAppReliable(Conn *c, unsigned char *message, int len)
{
	int ret;

	if (c->state != 5 && c->state != 6) {
		if (!gti2ConnectionCommunicationError(c))
			return 0;
	} else if (ArrayLength(c->filters)) {
		ret = 1;
		if (!gti2ReceiveFilterCallback(c, 0, message, len, 1))
			ret = 0;
		return ret;
	} else {
		if (!gti2ReceivedCallback(c, message, len, 1))
			return 0;
	}
	return 1;
}
