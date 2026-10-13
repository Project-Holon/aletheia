/*
 * function: SOC_InetAtoN
 * address:  0x0215FAD0
 * packet:   pkt_ov009_0215FAD0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOC_InetAtoN (libsoc.TWL.HYB.a(soc.o))
 *
 * symbols:
 *   func_0215EE98  0x0215EE98  arm  ov009
 */

#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))

extern unsigned long func_0215EE98(char *hostname);

int SOC_InetAtoN(char *cp, unsigned long *inp)
{
	unsigned long h;

	h = func_0215EE98(cp);
	if (h == 0) {
		return 0;
	}
	if (inp != 0) {
		*inp = SWAP32(h);
	}
	return 1;
}
