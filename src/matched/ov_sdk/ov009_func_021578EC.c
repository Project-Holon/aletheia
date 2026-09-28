/*
 * function: is_broadcast
 * address:  0x021578EC
 * packet:   pkt_ov009_021578EC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      is_broadcast (libcps.TWL.HYB.a network.o)
 * symbols:
 *   ip_islocal                       0x02157888 arm
 *   wfailed                          0x021a826c data
 */

extern unsigned long ip_islocal(unsigned long ip);
extern unsigned char wfailed;

static unsigned long is_broadcast(unsigned long ip)
{
	unsigned long result = 0;

	if (ip_islocal(ip)) {
		unsigned long mask = *(unsigned long *)((char *)&wfailed + 0x10);

		if ((~mask & ip) == ~mask)
			result = 1;
	}
	return result;
}

