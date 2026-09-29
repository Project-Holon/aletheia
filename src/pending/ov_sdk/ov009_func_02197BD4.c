/*
 * function: func_02197BD4
 * address:  0x02197BD4
 * packet:   pkt_ov009_02197BD4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gti2SendClosedOnSocket (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * symbols:
 *   func_02198328  0x02198328  arm  ov009
 *   g_021A5948  0x021A5948  data
 */

typedef struct Sock {
	unsigned char pad0[0x40];
	int type;
} Sock;

extern int func_02198328(Sock *sock, unsigned int ip, unsigned short port, unsigned char *message, int len);
extern unsigned char g_021A5948[];

int func_02197BD4(Sock *sock, unsigned int ip, unsigned short port)
{
	char buffer[5];
	int pos = 0;
	short dataLength;
	unsigned char *s;
	unsigned char *d;

	if (sock->type == 2) {
		dataLength = 3;
		s = (unsigned char *)&dataLength;
		d = (unsigned char *)buffer + pos;
		d[0] = s[0];
		d[1] = s[1];
		pos += 2;
	}
	d = (unsigned char *)buffer + pos;
	s = g_021A5948;
	d[0] = s[0];
	d[1] = s[1];
	pos += 2;
	buffer[pos] = 0x68;
	pos++;
	if (!func_02198328(sock, ip, port, (unsigned char *)buffer, pos))
		return 0;
	return 1;
}
