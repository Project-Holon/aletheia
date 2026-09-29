/*
 * function: func_021C60C8
 * address:  0x021C60C8
 * packet:   pkt_ov114_021C60C8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      DWCi_Ndi_encodeBASE64 (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   func_021C6004  0x021C6004  arm  ov114
 *   g_021CE0F4  0x021CE0F4  data
 */

extern int func_021C6004(unsigned char *dst, char *p, int n);
extern char g_021CE0F4[];

int func_021C60C8(char *encstr, char *srcbin, int length)
{
	unsigned char c[3];
	unsigned char base2;
	unsigned char base3;
	unsigned char base1;
	unsigned char base0;
	int n;
	int len = 0;
	n = func_021C6004(c, srcbin, length > 3 ? 3 : length);
	while (n > 0) {
		if (length < 3)
			c[2] = 0;
		if (length < 2)
			c[1] = 0;
		base1 = (unsigned char)(c[0] >> 2);
		base2 = ((c[1] << 2) | (c[2] >> 6)) & 0x3f;
		base3 = c[2] & 0x3f;
		base0 = ((c[0] << 4) | (c[1] >> 4)) & 0x3f;
		encstr[0] = g_021CE0F4[base1];
		encstr[1] = g_021CE0F4[base0];
		encstr[2] = n > 1 ? g_021CE0F4[base2] : '*';
		encstr[3] = n > 2 ? g_021CE0F4[base3] : '*';
		len += 4;
		srcbin += n;
		encstr += 4;
		length -= n;
		if (length == 0)
			break;
		n = func_021C6004(c, srcbin, length > 3 ? 3 : length);
	}
	*encstr = 0;
	return len;
}
