/*
 * function: func_021CA5E4
 * address:  0x021CA5E4
 * packet:   pkt_ov114_021CA5E4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  32 mismatched words, register allocation only: original keeps data in r4, tag and dlen temp in lr, len in r12; here data lands in lr, temps in r4; ~35 variants (declaration orders, dlen CSE forms) tried
 *
 * sdk:      ASN1Skip (libcrypto.TWL.HYB.a(sign.o))
 *
 * symbols:

 */

int func_021CA5E4(unsigned char **datap, unsigned int *dlenp, unsigned char type, unsigned int *lenp)
{
	unsigned int dlen;
	unsigned int len;
	unsigned char *data;
	unsigned char l;

	data = *datap;
	dlen = *dlenp;
	len = 0;
	if (*data++ != type)
		return 0;
	if (dlen < 1)
		return 0;
	dlen--;
	l = *data;
	if (l & 0x80) {
		l &= 0x7f;
		if (dlen < (unsigned int)l + 1)
			return 0;
		dlen -= l;
		if (lenp != 0) {
			do {
				data++;
				len = (*data & 0x7f) + (len << 7);
			} while (--l);
		} else {
			data += l;
		}
	} else {
		data++;
		len = l;
		if (dlen < 1)
			return 0;
		dlen--;
	}
	*datap = data;
	*dlenp = dlen;
	if (lenp != 0)
		*lenp = len;
	return 1;
}
