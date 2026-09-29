/*
 * function: func_0215F0F0
 * address:  0x0215F0F0
 * packet:   pkt_ov009_0215F0F0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      SOCLi_IsIPv4ValidDNSAddr (libsoc.TWL.HYB.a(socl_misc.o))
 */

static inline int isA(unsigned long m, unsigned long d, unsigned long a)
{
	return ((a ^ d) & m) != 0 || (d & ~m) != 0;
}

static inline int isB(unsigned long m, unsigned long d, unsigned long a)
{
	int r = 1;
	if (((a ^ d) & m) == 0) {
		unsigned long t = ~m;
		if (t == (d & t))
			r = 0;
	}
	return r;
}

int func_0215F0F0(unsigned long netmask, unsigned long dns, unsigned long addr)
{
	int ret = 0;
	int notloop = 0;
	int valid = 0;

	if (dns != 0xffffffff && dns != 0 && addr != dns && isA(netmask, dns, addr) && isB(netmask, dns, addr))
		valid = 1;
	if (valid && ((dns & 0xff000000) ^ 0x7f000000) != 0)
		notloop = 1;
	if (notloop && ((dns & 0xf0000000) ^ 0xe0000000) != 0)
		ret = 1;
	return ret;
}
