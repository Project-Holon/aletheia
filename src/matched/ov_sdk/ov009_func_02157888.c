/*
 * function: ip_islocal
 * address:  0x02157888
 * packet:   pkt_ov009_02157888
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ip_islocal (libcps.TWL.HYB.a network.o)
 * symbols:
 *   wfailed                          0x021a826c data
 */

extern unsigned char wfailed;

static unsigned long ip_islocal(unsigned long ip)
{
	unsigned long result = 1;

	if (ip != 0xffffffff && ip != 0x7f000001) {
		unsigned long mask = *(unsigned long *)((char *)&wfailed + 0x10);
		unsigned long myip = *(unsigned long *)((char *)&wfailed + 0x50);

		if ((ip & mask) != (myip & mask))
			result = 0;
	}
	return result;
}

