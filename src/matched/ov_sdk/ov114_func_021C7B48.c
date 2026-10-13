/*
 * function: DWCi_Ndi_hexToStrFigure
 * address:  0x021C7B48
 * packet:   pkt_ov114_021C7B48
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Ndi_hexToStrFigure (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   (none)
 */

int DWCi_Ndi_hexToStrFigure(char *p, unsigned long n, int figure)
{
	int i;
	unsigned long x;
	int len = 0;
	if (figure > 8)
		return -1;
	for (i = 1; i <= figure; i++) {
		x = (n >> ((figure - i) * 4)) & 0xf;
		if (x < 10)
			p[len++] = x + '0';
		else
			p[len++] = x + 'a' - 10;
	}
	return len;
}
