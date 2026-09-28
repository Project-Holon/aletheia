/*
 * function: func_021CA69C
 * address:  0x021CA69C
 * packet:   pkt_ov114_021CA69C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SkipPadding (libcrypto.TWL.HYB.a(sign.o))
 *
 * symbols:

 */

int func_021CA69C(unsigned char *psrc_adrs, unsigned int nsrc_size, unsigned char **ppsign_adrs, unsigned int *psign_size)
{
	unsigned char *p;
	unsigned char *pe;
	int i;

	if (nsrc_size < 10)
		return 0;
	p = psrc_adrs;
	pe = psrc_adrs + nsrc_size;
	if (*p != 1)
		return 0;
	p++;
	for (i = 0; i < 8; i++) {
		if (*p++ != 0xff)
			return 0;
	}
	for (; p != pe; p++) {
		if (*p != 0xff)
			break;
	}
	if (p == pe)
		return 0;
	if (*p != 0)
		return 0;
	p++;
	*psign_size = pe - p;
	*ppsign_adrs = p;
	return 1;
}
