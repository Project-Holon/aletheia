/*
 * function: gti2HandleServerChallenge
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
 *   gti2ConnectionCommunicationError  0x02195F5C  arm  ov009
 *   gti2CheckResponse  0x02194D74  arm  ov009
 *   gti2GetResponse  0x02194C6C  arm  ov009
 *   gti2SendClientResponse  0x02197700  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
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

extern int gti2ConnectionCommunicationError(Conn *c);
extern int gti2CheckResponse(unsigned char *response1, unsigned char *response2);
extern unsigned char *gti2GetResponse(unsigned char *buffer, unsigned char *challenge);
extern int gti2SendClientResponse(struct Conn *c, char *response, char *message, int len);
extern void gsifree(void *ptr);

int gti2HandleServerChallenge(Conn *connection, unsigned char *message, int len)
{
	char response[32];

	if (connection->state != 0) {
		if (gti2ConnectionCommunicationError(connection))
			return 1;
		return 0;
	}
	if (len < 0x40) {
		if (gti2ConnectionCommunicationError(connection))
			return 1;
		return 0;
	}
	if (!gti2CheckResponse(message, connection->response)) {
		if (gti2ConnectionCommunicationError(connection))
			return 1;
		return 0;
	}
	gti2GetResponse((unsigned char *)response, message + 0x20);
	if (!gti2SendClientResponse(connection, response, connection->challenge, connection->challengeLen))
		return 0;
	if (connection->challenge != 0) {
		gsifree(connection->challenge);
		connection->challenge = 0;
	}
	connection->state = 1;
	return 1;
}
