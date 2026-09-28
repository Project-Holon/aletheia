/*
 * function: func_02158DB0
 * address:  0x02158DB0
 * packet:   pkt_ov009_02158DB0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      reply_icmp (libcps.TWL.HYB.a network.o)
 *
 * symbols:
 *   func_021578C8  0x021578C8  arm  ov009
 *   func_02157D8C  0x02157D8C  arm  ov009
 *   func_02157E54  0x02157E54  arm  ov009
 *   func_0215832C  0x0215832C  arm  ov009
 */

#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define BE32(p) (((unsigned long)SWAP16(*(unsigned short *)((p) + 0xc)) << 16) | SWAP16(*(unsigned short *)((p) + 0xe)))

extern unsigned long func_021578C8(unsigned long ip);
extern unsigned char *func_02157D8C(unsigned long ip);
extern void func_02157E54(unsigned long ip);
extern void func_0215832C(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned char proto);

void func_02158DB0(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len)
{
	unsigned long ip_reply_to = func_021578C8(BE32(iphdr));
	unsigned long sum;

	if (ip_reply_to == 0)
		return;
	if (func_02157D8C(ip_reply_to) == 0) {
		func_02157E54(ip_reply_to);
		return;
	}
	icmpdata[0] = 0;
	sum = *(unsigned short *)(icmpdata + 2) + 8;
	sum += sum >> 16;
	*(unsigned short *)(icmpdata + 2) = sum;
	func_0215832C(icmpdata, len, 0, 0, BE32(iphdr), 1);
}
