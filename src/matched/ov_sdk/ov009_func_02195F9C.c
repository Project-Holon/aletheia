/*
 * function: func_02195F9C
 * address:  0x02195F9C
 * packet:   pkt_ov009_02195F9C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2HandleESN (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * symbols:
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_02195EB4  0x02195EB4  arm  ov009
 *   func_0218437C  0x0218437C  arm  ov009
 *   func_02194E80  0x02194E80  arm  ov009
 */

typedef struct Msg {
	int offset;
	unsigned char pad0[4];
	unsigned short SN;
} Msg;

typedef struct Conn {
	unsigned char pad0[0x50];
	unsigned char buffer[8];
	int a58;
	unsigned char pad1[4];
	void *outgoing;
} Conn;

extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern int func_02195EB4(unsigned short SN1, unsigned short SN2);
extern void func_0218437C(void *array, int n);
extern void func_02194E80(void *buffer, int start, int shortenBy);

int func_02195F9C(Conn *connection, unsigned short ESN)
{
	int len;
	int i;
	Msg *message;
	int shortenBy;

	len = func_02184200(connection->outgoing);
	if (len == 0)
		return 1;
	for (i = 0; i < len; i++) {
		message = func_02184208(connection->outgoing, i);
		if (func_02195EB4(message->SN, ESN) >= 0)
			break;
	}
	if (i == 0)
		return 1;
	while (i-- != 0)
		func_0218437C(connection->outgoing, i);
	len = func_02184200(connection->outgoing);
	if (len == 0) {
		connection->a58 = 0;
		return 1;
	}
	message = func_02184208(connection->outgoing, 0);
	shortenBy = message->offset;
	for (i = 0; i < len; i++) {
		message = func_02184208(connection->outgoing, i);
		message->offset -= shortenBy;
	}
	func_02194E80(connection->buffer, 0, shortenBy);
	return 1;
}
