/*
 * function: get_targetip
 * address:  0x021578C8
 * packet:   pkt_ov009_021578C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      get_targetip (libcps.TWL.HYB.a network.o)
 * symbols:
 *   ip_islocal                       0x02157888 arm
 *   wfailed                          0x021a826c data
 */

extern unsigned long ip_islocal(unsigned long ip);
extern unsigned char wfailed;

static unsigned long get_targetip(unsigned long ip)
{
	if (ip_islocal(ip) == 0)
		ip = *(unsigned long *)((char *)&wfailed + 0x2c);
	return ip;
}

