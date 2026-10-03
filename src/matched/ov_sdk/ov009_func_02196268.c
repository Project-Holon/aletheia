/*
 * function: func_02196268
 * address:  0x02196268
 * packet:   pkt_ov009_02196268
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2HandleServerChallenge (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * symbols:
 *   func_02195F5C  0x02195F5C  arm  ov009
 *   func_02194D74  0x02194D74  arm  ov009
 *   func_02194C6C  0x02194C6C  arm  ov009
 *   func_02197700  0x02197700  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 */

typedef struct Conn {
	unsigned char pad0[0xc];
	int state;
	unsigned char pad1[0x28];
	void *challenge;
	int challengeLen;
	unsigned char pad2[0x28];
	unsigned char response[1];
} Conn;

extern int func_02195F5C(Conn *c);
extern int func_02194D74(unsigned char *response1, unsigned char *response2);
extern unsigned char *func_02194C6C(unsigned char *buffer, unsigned char *challenge);
extern int func_02197700(struct Conn *c, char *response, char *message, int len);
extern void func_0217EAE0(void *ptr);

int func_02196268(Conn *connection, unsigned char *message, int len)
{
	char response[32];

	if (connection->state != 0) {
		if (func_02195F5C(connection))
			return 1;
		return 0;
	}
	if (len < 0x40) {
		if (func_02195F5C(connection))
			return 1;
		return 0;
	}
	if (!func_02194D74(message, connection->response)) {
		if (func_02195F5C(connection))
			return 1;
		return 0;
	}
	func_02194C6C((unsigned char *)response, message + 0x20);
	if (!func_02197700(connection, response, connection->challenge, connection->challengeLen))
		return 0;
	if (connection->challenge != 0) {
		func_0217EAE0(connection->challenge);
		connection->challenge = 0;
	}
	connection->state = 1;
	return 1;
}
