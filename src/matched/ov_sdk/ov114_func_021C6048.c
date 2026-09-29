/*
 * function: func_021C6048
 * address:  0x021C6048
 * packet:   pkt_ov114_021C6048
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      decodeChar (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   (none)
 */

int func_021C6048(unsigned char c)
{
	if (c >= 'A' && c <= 'Z')
		return c - 'A';
	if (c >= 'a' && c <= 'z')
		return c - 'a' + 26;
	if (c >= '0' && c <= '9')
		return c - '0' + 52;
	if (c == '.')
		return 62;
	if (c == '-')
		return 63;
	return -1;
}
