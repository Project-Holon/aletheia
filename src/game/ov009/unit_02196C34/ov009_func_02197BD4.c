/*
 * function: func_02197BD4
 * address:  0x02197BD4
 * packet:   pkt_ov009_02197BD4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2SendClosedOnSocket (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * w4_nm: both two-byte copies are memcpy through string.h (inlined as the
 * ldrb/strb pairs with the object's register roles); the magic source is the
 * string literal "\xFE\xFE", the vendor template @14988 at 0x021A5948.
 *
 * symbols:
 *   func_02198328  0x02198328  arm  ov009
 *   @14988         0x021A5948  data
 */

#include "../../../matched/arm9_sdk/libc/string.h"

typedef struct Sock {
	unsigned char pad0[0x40];
	int type;
} Sock;

extern int func_02198328(Sock *sock, unsigned int ip, unsigned short port, unsigned char *message, int len);

int func_02197BD4(Sock *sock, unsigned int ip, unsigned short port)
{
	char buffer[5];
	int pos = 0;
	short dataLength;

	if (sock->type == 2) {
		dataLength = 3;
		memcpy(buffer + pos, &dataLength, 2);
		pos += 2;
	}
	memcpy(buffer + pos, "\xFE\xFE", 2);
	pos += 2;
	buffer[pos] = 0x68;
	pos++;
	if (!func_02198328(sock, ip, port, (unsigned char *)buffer, pos))
		return 0;
	return 1;
}
