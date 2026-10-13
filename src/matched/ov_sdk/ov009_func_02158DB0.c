/*
 * function: reply_icmp
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
 *   get_targetip  0x021578C8  arm  ov009
 *   inq_arpcache  0x02157D8C  arm  ov009
 *   send_arprequest  0x02157E54  arm  ov009
 *   send_ip  0x0215832C  arm  ov009
 */

#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define BE32(p) (((unsigned long)SWAP16(*(unsigned short *)((p) + 0xc)) << 16) | SWAP16(*(unsigned short *)((p) + 0xe)))

extern unsigned long get_targetip(unsigned long ip);
extern unsigned char *inq_arpcache(unsigned long ip);
extern void send_arprequest(unsigned long ip);
extern void send_ip(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned char proto);

void reply_icmp(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len)
{
	unsigned long ip_reply_to = get_targetip(BE32(iphdr));
	unsigned long sum;

	if (ip_reply_to == 0)
		return;
	if (inq_arpcache(ip_reply_to) == 0) {
		send_arprequest(ip_reply_to);
		return;
	}
	icmpdata[0] = 0;
	sum = *(unsigned short *)(icmpdata + 2) + 8;
	sum += sum >> 16;
	*(unsigned short *)(icmpdata + 2) = sum;
	send_ip(icmpdata, len, 0, 0, BE32(iphdr), 1);
}
