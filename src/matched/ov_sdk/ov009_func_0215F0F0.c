/*
 * function: func_0215F0F0
 * address:  0x0215F0F0
 * packet:   pkt_ov009_0215F0F0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 2026-10-01 lane08: EXACT.  A `(unsigned int)` cast on `addr` in IS_A makes
 *   the two xors distinct expressions to CSE (cast-between-uses idiom), and
 *   IS_B is the `(x || y) ? 1 : 0` value form with `~m ^ (d & ~m)` (teq).
 *
 * sdk:      SOCLi_IsIPv4ValidDNSAddr (libsoc.TWL.HYB.a(socl_misc.o))
 */

#define IS_A(m, d, a) ((((unsigned int)(a) ^ (d)) & (m)) != 0 || ((d) & ~(m)) != 0)
#define IS_B(m, d, a) (((((a) ^ (d)) & (m)) != 0 || (~(m) ^ ((d) & ~(m))) != 0) ? 1 : 0)

int func_0215F0F0(unsigned long netmask, unsigned long dns, unsigned long addr)
{
	int ret = 0;
	int notloop = 0;
	int valid = 0;

	if (dns != 0xffffffff && dns != 0 && addr != dns && IS_A(netmask, dns, addr) && IS_B(netmask, dns, addr))
		valid = 1;
	if (valid && ((dns & 0xff000000) ^ 0x7f000000) != 0)
		notloop = 1;
	if (notloop && ((dns & 0xf0000000) ^ 0xe0000000) != 0)
		ret = 1;
	return ret;
}
