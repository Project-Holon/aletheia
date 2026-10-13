/*
 * function: DWCi_STRlConvertStringAsciiToUnicode
 * address:  0x021D722C
 * packet:   pkt_ov016_021D722C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_STRlConvertStringAsciiToUnicode (libdwcutil.TWL.HYB.a(str.o))
 *
 * symbols:
 */

int DWCi_STRlConvertStringAsciiToUnicode(unsigned short *dst, unsigned char *src, int len)
{
	int i;

	for (i = 0; i < len - 1; i++) {
		if (src[i] == 0)
			break;
		dst[i] = src[i];
	}
	dst[i] = 0;
	return i;
}
