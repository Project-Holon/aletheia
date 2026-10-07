/*
 * file:     unit_021573C4_p02.c
 * unit:     yes
 * function: func_02157808, func_0215781C, func_02157838, func_02157888, func_021578C8, func_021578EC, func_02157928
 * address:  0x02157808
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02157700  0x02157700  arm  ov009
 *   wfailed                          0x021a826c data
 */
extern unsigned long func_02157700(unsigned char *s, unsigned long len, unsigned long sum);
unsigned int func_02157808(unsigned int x);
int func_0215781C(int a, int b);
unsigned long func_02157838(unsigned char *tcpudp_hdr, unsigned long len, unsigned char *ip_hdr, unsigned short proto);
int func_02157928(unsigned v);
extern unsigned char wfailed;

/*
 * Maps the 0xffff sentinel onto itself and everything else onto its complement.
 */
unsigned int func_02157808(unsigned int x)
{
    unsigned int y = x ^ 0xffffu;

    return y ? y : 0xffffu;
}


/*
 * The halfword the three-argument call lands on, tested.
 */
int func_0215781C(int a, int b)
{
    return func_02157808((unsigned short)func_02157700((unsigned char *)a, b, 0));
}


/*
 * sdk:      check_tcpudpsum (libcps.TWL.HYB.a(network.o))
 */
unsigned long func_02157838(unsigned char *tcpudp_hdr, unsigned long len, unsigned char *ip_hdr, unsigned short proto)
{
    unsigned long sum = func_02157700(tcpudp_hdr, len, proto);

    sum = func_02157700(ip_hdr + 0xc, 8, sum);
    sum += len;
    if (sum & 0x10000)
        sum = (unsigned short)(sum + 1);
    return sum != 0xffff;
}


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


static unsigned long get_targetip(unsigned long ip)
{
	if (ip_islocal(ip) == 0)
		ip = *(unsigned long *)((char *)&wfailed + 0x2c);
	return ip;
}


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

int func_02157928(unsigned v)
{
    return (v & 0xF0000000u) == 0xE0000000u;
}
