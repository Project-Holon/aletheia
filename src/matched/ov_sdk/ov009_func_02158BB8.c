/*
 * function: reply_arp
 * address:  0x02158BB8
 * packet:   pkt_ov009_02158BB8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      reply_arp (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_02082EA4  0x02082EA4  arm
 *   send_packet  0x021579E8  arm  ov009
 *   CPSMyMac  0x021A82D4  data
 *   gCpsNetVars  0x021A826C  data
 */

struct NetVars {
	unsigned char pad0[0x50];
	unsigned long myip;
};
extern void func_02082EA4(void *src, void *dst, unsigned long size);
extern void send_packet(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len);
extern unsigned char CPSMyMac[6];
extern struct NetVars gCpsNetVars;

void reply_arp(unsigned char *buf)
{
	unsigned short v;
	*(unsigned short *)(buf + 6) = 0x200;
	func_02082EA4(buf + 8, buf + 0x12, 10);
	func_02082EA4(CPSMyMac, buf + 8, 6);
	v = (unsigned short)(gCpsNetVars.myip >> 16);
	*(unsigned short *)(buf + 0xe) = (v >> 8) | (v << 8);
	v = (unsigned short)gCpsNetVars.myip;
	*(unsigned short *)(buf + 0x10) = (v >> 8) | (v << 8);
	func_02082EA4(buf + 0x12, buf - 0xe, 6);
	func_02082EA4(CPSMyMac, buf - 8, 6);
	send_packet(buf - 0xe, 0x2a, 0, 0);
}
