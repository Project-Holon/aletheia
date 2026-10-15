/*
 * function: dispatch_arp
 * address:  0x02158C68
 * packet:   pkt_ov009_02158C68
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dispatch_arp (libcps.TWL.HYB.a network.o)
 *
 * symbols:
 *   maccmp            0x021579BC  arm  ov009
 *   reg_arpcache            0x02157FF8  arm  ov009
 *   reply_arp            0x02158BB8  arm  ov009
 *   CPSMyMac               0x021A82D4  data
 *   gCpsNetVars               0x021A826C  data
 */

extern int maccmp(unsigned short *a, unsigned short *b);
extern void reg_arpcache(unsigned char (*mac)[6], unsigned long ip, int new_entry);
extern void reply_arp(unsigned char *buf);
extern unsigned char CPSMyMac[6];
extern unsigned char gCpsNetVars;

#define NV(off, type) (*(type *)((char *)&gCpsNetVars + (off)))
#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define GET16(p) SWAP16(*(unsigned short *)(p))
#define GET32(p) (((unsigned long)GET16(p) << 16) | GET16((p) + 2))

/*
 * The link-up test reads the address word as long: read as unsigned long it
 * is common-subexpression-merged with the later compares and the image's
 * second load of the word disappears.
 */
void dispatch_arp(unsigned char *buf, unsigned long len)
{
	unsigned short op;
	unsigned long ipfrom;
	int from_me;
	int to_me;

	if (len < 0x1c)
		return;
	if (maccmp((short unsigned int *)(buf + 8), (short unsigned int *)CPSMyMac) == 0 || NV(0x50, long) == 0)
		return;
	if (*(unsigned short *)buf != 0x100 || *(unsigned short *)(buf + 2) != 8 || *(unsigned short *)(buf + 4) != 0x406)
		return;
	op = GET16(buf + 6);
	if (op != 1 && op != 2)
		return;
	ipfrom = GET32(buf + 0xe);
	from_me = (ipfrom == NV(0x50, unsigned long));
	to_me = (NV(0x50, unsigned long) == GET32(buf + 0x18));
	if (!from_me)
		reg_arpcache((unsigned char (*)[6])(buf + 8), ipfrom, to_me);
	if (op == 1 && to_me) {
		reply_arp(buf);
		return;
	}
	if (op == 2 && to_me && from_me)
		NV(1, unsigned char) = 1;
}
