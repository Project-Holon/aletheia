/*
 * function: gti2SendNack
 * address:  0x02197AD8
 * packet:   pkt_ov009_02197AD8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2SendNack (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * symbols:
 *   gti2UShortToBuffer  0x02195EA0  arm  ov009
 *   func_02195750  0x02195750  arm  ov009
 *   g_021A5948  0x021A5948  data
 */

#include "../arm9_sdk/libc/string.h"

typedef struct Sock {
	unsigned char pad0[0x40];
	int type;
} Sock;

typedef struct Conn {
	unsigned char pad0[8];
	Sock *sock;
} Conn;

extern void gti2UShortToBuffer(unsigned char *buffer, int pos, unsigned short s);
extern int func_02195750(Conn *c, unsigned char *message, int len);
extern unsigned char g_021A5948[];

int gti2SendNack(Conn *connection, unsigned short SNMin, unsigned short SNMax)
{
	char buffer[9];
	int pos = 0;
	short dataLength;

	if (connection->sock->type == 2) {
		dataLength = 7;
		memcpy(buffer + pos, &dataLength, 2);
		pos += 2;
	}
	memcpy(buffer + pos, g_021A5948, 2);
	pos += 2;
	buffer[pos] = 0x65;
	pos++;
	gti2UShortToBuffer((unsigned char *)buffer, pos, SNMin);
	pos += 2;
	if (SNMin != SNMax) {
		gti2UShortToBuffer((unsigned char *)buffer, pos, SNMax);
		pos += 2;
	}
	if (!func_02195750(connection, (unsigned char *)buffer, pos))
		return 0;
	return 1;
}
