/*
 * function: strtol10
 * address:  0x0215C7E0
 * packet:   pkt_ov009_0215C7E0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      strtol10 (libcps.TWL.HYB.a network.o)
 * symbols:
 */

static unsigned long strtol10(unsigned char *s, unsigned char **endptr)
{
	unsigned long acc = 0;
	unsigned char c;

	*endptr = s;
	for (;;) {
		c = *s;
		if ((unsigned char)(c - '0') > 9)
			break;
		acc = acc * 10 + (unsigned char)(c - '0');
		s++;
		*endptr = s;
	}
	return acc;
}

