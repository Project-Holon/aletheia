/*
 * function: func_021CA5E4
 * address:  0x021CA5E4
 * packet:   pkt_ov114_021CA5E4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     Lane wave7 (2026-09-30): EXACT from the object listing.  The DWARF
 *          local list is l(r6), len(r12), dlen(r5), data(r4) (reverse source
 *          order), and the vendor's long-form parse hoists `data++` out of the
 *          do/while: `data++; do { len = (*data & 0x7f) + (len << 7); } while
 *          (--l);`.  With the increment inside the loop this front end keeps
 *          the reload in the loop (180 B, 80 concrete bytes); hoisted, the load
 *          is loop-invariant and CSE'd into `lr`, giving the image's 4
 *          instruction loop and 184/184.
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
			data++;
			do {
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
