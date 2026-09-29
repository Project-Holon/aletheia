/*
 * function: func_0215F184
 * address:  0x0215F184
 * packet:   pkt_ov009_0215F184
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_IsIPv4ValidNodeAddr (libsoc.TWL.HYB.a(socl_misc.o))
 */

int func_0215F184(unsigned long netmask, unsigned long addr)
{
	int ret = 0;
	int notloop = 0;
	int host = 0;
	unsigned long h = addr & ~netmask;

	if ((~netmask ^ h) != 0 && h != 0)
		host = 1;
	if (host && ((addr & 0xff000000) ^ 0x7f000000) != 0)
		notloop = 1;
	if (notloop && ((addr & 0xf0000000) ^ 0xe0000000) != 0)
		ret = 1;
	return ret;
}
