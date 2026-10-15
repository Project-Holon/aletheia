/*
 * function: gti2HandleClientChallenge
 * address:  0x021961C8
 * packet:   pkt_ov009_021961C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2HandleClientChallenge (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * symbols:
 *   gti2ConnectionCommunicationError  0x02195F5C  arm  ov009
 *   gti2GetResponse  0x02194C6C  arm  ov009
 *   gti2GetChallenge  0x02194B74  arm  ov009
 *   gti2SendServerChallenge  0x02197678  arm  ov009
 */

typedef struct Conn {
	unsigned char pad0[0xc];
	int state;
	unsigned char pad1[0x58];
	unsigned char response[1];
} Conn;

extern int gti2ConnectionCommunicationError(Conn *c);
extern unsigned char *gti2GetResponse(unsigned char *buffer, unsigned char *challenge);
extern unsigned char *gti2GetChallenge(unsigned char *buffer);
extern int gti2SendServerChallenge(Conn *c, char *response, char *challenge);

int gti2HandleClientChallenge(Conn *c, unsigned char *message, int len)
{
	char response[32];
	char challenge[32];

	if (c->state != 2) {
		if (gti2ConnectionCommunicationError(c))
			return 1;
		return 0;
	}
	if (len < 0x20) {
		if (gti2ConnectionCommunicationError(c))
			return 1;
		return 0;
	}
	gti2GetResponse((unsigned char *)response, message);
	gti2GetChallenge((unsigned char *)challenge);
	gti2GetResponse(c->response, (unsigned char *)challenge);
	if (!gti2SendServerChallenge(c, response, challenge))
		return 0;
	c->state = 3;
	return 1;
}
