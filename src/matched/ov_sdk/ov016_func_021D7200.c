/*
 * function: func_021D7200
 * address:  0x021D7200
 * packet:   pkt_ov016_021D7200
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_STRlNLen (libdwcutil.TWL.HYB.a(str.o))
 *
 * symbols:
 */

int func_021D7200(unsigned char *s, int maxlen)
{
	int i;

	for (i = 0; i < maxlen; i++) {
		if (s[i] == 0)
			break;
	}
	return i;
}
