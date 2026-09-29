/*
 * function: func_021961C8
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
 *   func_02195F5C  0x02195F5C  arm  ov009
 *   func_02194C6C  0x02194C6C  arm  ov009
 *   func_02194B74  0x02194B74  arm  ov009
 *   func_02197678  0x02197678  arm  ov009
 */

typedef struct Conn {
	unsigned char pad0[0xc];
	int state;
	unsigned char pad1[0x58];
	unsigned char response[1];
} Conn;

extern int func_02195F5C(Conn *c);
extern unsigned char *func_02194C6C(unsigned char *buffer, unsigned char *challenge);
extern unsigned char *func_02194B74(unsigned char *buffer);
extern int func_02197678(Conn *c, char *response, char *challenge);

int func_021961C8(Conn *c, unsigned char *message, int len)
{
	char response[32];
	char challenge[32];

	if (c->state != 2) {
		if (func_02195F5C(c))
			return 1;
		return 0;
	}
	if (len < 0x20) {
		if (func_02195F5C(c))
			return 1;
		return 0;
	}
	func_02194C6C((unsigned char *)response, message);
	func_02194B74((unsigned char *)challenge);
	func_02194C6C(c->response, (unsigned char *)challenge);
	if (!func_02197678(c, response, challenge))
		return 0;
	c->state = 3;
	return 1;
}
