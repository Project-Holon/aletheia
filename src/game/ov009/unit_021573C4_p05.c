/*
 * file:     unit_021573C4_p05.c
 * unit:     yes
 * function: func_02158BB8, func_02158C68, func_02158DB0
 * address:  0x02158BB8
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
 *   func_02082EA4  0x02082EA4  arm
 *   func_021579E8  0x021579E8  arm  ov009
 *   g_021A82D4  0x021A82D4  data
 *   g_021A826C  0x021A826C  data
 *   func_021579BC            0x021579BC  arm  ov009
 *   func_02157FF8            0x02157FF8  arm  ov009
 *   func_021578C8  0x021578C8  arm  ov009
 *   func_02157D8C  0x02157D8C  arm  ov009
 *   func_02157E54  0x02157E54  arm  ov009
 *   func_0215832C  0x0215832C  arm  ov009
 */
#define NV(off, type) (*(type *)((char *)&g_021A826C + (off)))
#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define GET16(p) SWAP16(*(unsigned short *)(p))
#define GET32(p) (((unsigned long)GET16(p) << 16) | GET16((p) + 2))
#define BE32(p) (((unsigned long)SWAP16(*(unsigned short *)((p) + 0xc)) << 16) | SWAP16(*(unsigned short *)((p) + 0xe)))
struct NetVars {
	unsigned char pad0[0x50];
	unsigned long myip;
};

extern void func_02082EA4(void *src, void *dst, unsigned long size);
extern void func_021579E8(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len);
extern int func_021579BC(unsigned short *a, unsigned short *b);
extern void func_02157FF8(unsigned char (*mac)[6], unsigned long ip, int new_entry);
extern unsigned long func_021578C8(unsigned long ip);
extern unsigned char *func_02157D8C(unsigned long ip);
extern void func_02157E54(unsigned long ip);
extern void func_0215832C(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned char proto);
void func_02158BB8(unsigned char *buf);
/* * The link-up test reads the address word as long: read as unsigned long it * is common-subexpression-merged with the later compares and the image's * second load of the word disappears. */ void func_02158C68(unsigned char *buf, unsigned long len);
void func_02158DB0(unsigned char *iphdr, unsigned char *icmpdata, unsigned long len);
extern unsigned char g_021A82D4[6];
extern struct NetVars g_021A826C;


/*
 * sdk:      reply_arp (libcps.TWL.HYB.a(network.o))
 */
void func_02158BB8(unsigned char *buf)
{
	unsigned short v;
	*(unsigned short *)(buf + 6) = 0x200;
	func_02082EA4(buf + 8, buf + 0x12, 10);
	func_02082EA4(g_021A82D4, buf + 8, 6);
	v = (unsigned short)(g_021A826C.myip >> 16);
	*(unsigned short *)(buf + 0xe) = (v >> 8) | (v << 8);
	v = (unsigned short)g_021A826C.myip;
	*(unsigned short *)(buf + 0x10) = (v >> 8) | (v << 8);
	func_02082EA4(buf + 0x12, buf - 0xe, 6);
	func_02082EA4(g_021A82D4, buf - 8, 6);
	func_021579E8(buf - 0xe, 0x2a, 0, 0);
}


/*
 * The link-up test reads the address word as long: read as unsigned long it
 * is common-subexpression-merged with the later compares and the image's
 * second load of the word disappears.
 */
/*
 * sdk:      dispatch_arp (libcps.TWL.HYB.a network.o)
 */
void func_02158C68(unsigned char *buf, unsigned long len)
{
	unsigned short op;
	unsigned long ipfrom;
	int from_me;
	int to_me;

	if (len < 0x1c)
		return;
	if (func_021579BC((short unsigned int *)(buf + 8), (short unsigned int *)g_021A82D4) == 0 || NV(0x50, long) == 0)
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
		func_02157FF8((unsigned char (*)[6])(buf + 8), ipfrom, to_me);
	if (op == 1 && to_me) {
		func_02158BB8(buf);
		return;
	}
	if (op == 2 && to_me && from_me)
		NV(1, unsigned char) = 1;
}


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
