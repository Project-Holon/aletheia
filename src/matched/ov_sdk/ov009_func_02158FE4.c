/*
 * function: dispatch_icmp
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
 *   calc_checksum  0x0215781C  arm  ov009
 *   valid_IP  0x02158F84  arm  ov009
 *   process_icmp_reply  0x02158E84  arm  ov009
 *   reply_icmp  0x02158DB0  arm  ov009
 */

#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define BE32(p, o) (((unsigned long)SWAP16(*(unsigned short *)((p) + (o))) << 16) | SWAP16(*(unsigned short *)((p) + (o) + 2)))

extern int calc_checksum(int a, int b);
extern unsigned long valid_IP(unsigned long ip1, unsigned long ip2);
extern void process_icmp_reply(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
extern void reply_icmp(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);

void dispatch_icmp(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len)
{
	if (len < 8)
		return;
	if (calc_checksum((int)icmpdata, len) != 0xffff)
		return;
	if (valid_IP(BE32(iphdr, 0xc), BE32(iphdr, 0x10)) == 0)
		return;
	switch (icmpdata[0]) {
	case 0:
		process_icmp_reply(iphdr, icmpdata, len);
		break;
	case 8:
		reply_icmp(iphdr, icmpdata, len);
		break;
	}
}
