/*
 * function: func_021592A8
 * address:  0x021592A8
 * packet:   pkt_ov009_021592A8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      parse_mss (libcps.TWL.HYB.a(network.o))
 *
 * symbols:

 */

struct _CPSSoc {
	unsigned char pad0[0x33];
	unsigned char sack;
	unsigned char pad1[6];
	unsigned short mss;
};

void func_021592A8(unsigned char *tcphdr, struct _CPSSoc *soc)
{
	long len;
	unsigned char *p;

	soc->mss = 536;
	len = ((tcphdr[0xc] & 0xf0) / 4) - 20;
	p = tcphdr + 0x14;
	while (len-- > 0) {
		switch (*p++) {
		case 0:
			return;
		case 1:
			break;
		case 2:
			if (len <= 2)
				return;
			if (p[0] != 4)
				return;
			soc->mss = (p[1] << 8) | p[2];
			p += 3;
			len -= 3;
			break;
		case 4:
			if (len <= 0)
				return;
			if (p[0] != 2)
				return;
			soc->sack = 1;
			p++;
			len--;
			break;
		default: {
			unsigned long l;

			if (len <= 0)
				return;
			l = p[0];
			if (l < 2)
				return;
			l--;
			len -= l;
			p += l;
		}
		}
	}
}
