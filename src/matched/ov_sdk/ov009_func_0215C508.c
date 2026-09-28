/*
 * function: dns_skipname
 * address:  0x0215C508
 * packet:   pkt_ov009_0215C508
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dns_skipname (libcps.TWL.HYB.a network.o)
 * symbols:
 */

static unsigned char *dns_skipname(unsigned char *s)
{
	unsigned char c;

	while ((c = *s++) != 0) {
		if ((c & 0xc0) == 0xc0) {
			s++;
			break;
		}
		s += c;
	}
	return s;
}

