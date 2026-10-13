/*
 * file:     str.c
 * unit:     yes
 * function: func_021D7200, func_021D722C
 * address:  0x021D7200
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
int func_021D7200(unsigned char *s, int maxlen);
int func_021D722C(unsigned short *dst, unsigned char *src, int len);

int func_021D7200(unsigned char *s, int maxlen)
{
	int i;

	for (i = 0; i < maxlen; i++) {
		if (s[i] == 0)
			break;
	}
	return i;
}

/*
 * sdk:      DWCi_STRlConvertStringAsciiToUnicode (libdwcutil.TWL.HYB.a(str.o))
 */
int func_021D722C(unsigned short *dst, unsigned char *src, int len)
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
