/*
 * function: func_0215BD8C
 * address:  0x0215BD8C
 * packet:   pkt_ov009_0215BD8C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dhcp_send_discover (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_0215BC04  0x0215BC04  arm  ov009
 *   func_0215BD58  0x0215BD58  arm  ov009
 *   func_0215B470  0x0215B470  arm  ov009
 *   g_021A826C     0x021A826C  data
 *   g_021A878E     0x021A878E  data
 */

struct NetVars {
	unsigned char pad0[0x30];
	unsigned long xid;
	unsigned char pad1[4];
	unsigned long offered_myip;
	unsigned char pad2[0x3c];
	unsigned long long rand_state;
	unsigned long long rand_mult;
	unsigned long long rand_inc;
};

extern unsigned char *func_0215BC04(unsigned char *d, int type);
extern unsigned char *func_0215BD58(unsigned char pattern, unsigned long minimum, unsigned char *d, unsigned long curlen);
extern unsigned long func_0215B470(unsigned char *buf, unsigned long len);
extern struct NetVars g_021A826C;
extern unsigned char g_021A878E[];

unsigned long func_0215BD8C(void)
{
	unsigned char *buf = g_021A878E;
	unsigned char *d;

	g_021A826C.rand_state = g_021A826C.rand_mult * g_021A826C.rand_state + g_021A826C.rand_inc;
	g_021A826C.xid = (unsigned long)(g_021A826C.rand_state >> 32);
	d = func_0215BC04(buf, 1);
	if (g_021A826C.offered_myip != 0) {
		*d++ = 0x32;
		*d++ = 4;
		*d++ = (unsigned short)(g_021A826C.offered_myip >> 16) >> 8;
		*d++ = g_021A826C.offered_myip >> 16;
		*d++ = (unsigned short)g_021A826C.offered_myip >> 8;
		*d++ = g_021A826C.offered_myip;
	}
	*d++ = 0xff;
	d = func_0215BD58(0, 300, d, d - buf);
	func_0215B470(buf, d - buf);
	return g_021A826C.xid;
}
