/*
 * function: func_02196B48
 * address:  0x02196B48
 * packet:   pkt_ov009_02196B48
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2HandleNack (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * symbols:
 *   func_02195E80  0x02195E80  arm  ov009
 *   func_02195F5C  0x02195F5C  arm  ov009
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_02195EB4  0x02195EB4  arm  ov009
 *   func_02197C5C  0x02197C5C  arm  ov009
 */

typedef struct Msg {
	unsigned char pad0[8];
	unsigned short SN;
} Msg;

typedef struct Conn {
	unsigned char pad0[0x60];
	void *outgoing;
} Conn;

extern unsigned short func_02195E80(unsigned char *buffer, int pos);
extern int func_02195F5C(Conn *c);
extern int func_02184200(const int *p);
extern void *func_02184208(void *array, int n);
extern int func_02195EB4(unsigned short SN1, unsigned short SN2);
extern int func_02197C5C(Conn *c, Msg *message);

int func_02196B48(Conn *connection, unsigned char *message, int len)
{
	unsigned short SNMin;
	unsigned short SNMax;
	int num;
	int i;
	Msg *messageInfo;

	SNMin = func_02195E80(message, 0);
	if (len == 2)
		SNMax = SNMin;
	else if (len == 4)
		SNMax = func_02195E80(message, 2);
	else {
		if (func_02195F5C(connection))
			return 1;
		return 0;
	}
	num = func_02184200(connection->outgoing);
	for (i = 0; i < num; i++) {
		messageInfo = func_02184208(connection->outgoing, i);
		if (func_02195EB4(messageInfo->SN, SNMin) < 0)
			continue;
		if (func_02195EB4(messageInfo->SN, SNMax) > 0)
			continue;
		if (!func_02197C5C(connection, messageInfo))
			return 0;
	}
	return 1;
}
