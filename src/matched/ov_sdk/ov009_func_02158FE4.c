/*
 * function: func_02158FE4
 * address:  0x02158FE4
 * packet:   pkt_ov009_02158FE4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dispatch_icmp (libcps.TWL.HYB.a network.o)
 *
 * symbols:
 *   func_0215781C  0x0215781C  arm  ov009
 *   func_02158F84  0x02158F84  arm  ov009
 *   func_02158E84  0x02158E84  arm  ov009
 *   func_02158DB0  0x02158DB0  arm  ov009
 */

#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define BE32(p, o) (((unsigned long)SWAP16(*(unsigned short *)((p) + (o))) << 16) | SWAP16(*(unsigned short *)((p) + (o) + 2)))

extern unsigned short func_0215781C(unsigned char *s, unsigned long len);
extern unsigned long func_02158F84(unsigned long ip1, unsigned long ip2);
extern void func_02158E84(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
extern void func_02158DB0(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);

void func_02158FE4(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len)
{
	if (len < 8)
		return;
	if (func_0215781C(icmpdata, len) != 0xffff)
		return;
	if (func_02158F84(BE32(iphdr, 0xc), BE32(iphdr, 0x10)) == 0)
		return;
	switch (icmpdata[0]) {
	case 0:
		func_02158E84(iphdr, icmpdata, len);
		break;
	case 8:
		func_02158DB0(iphdr, icmpdata, len);
		break;
	}
}
