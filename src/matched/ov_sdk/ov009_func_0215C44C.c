/*
 * function: func_0215C44C
 * address:  0x0215C44C
 * packet:   pkt_ov009_0215C44C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dhcp_release_server (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_0215AB10  0x0215AB10  arm  ov009
 *   func_0215AA88  0x0215AA88  arm  ov009
 *   func_0215AAB0  0x0215AAB0  arm  ov009
 *   func_0215BC04  0x0215BC04  arm  ov009
 *   func_0215BD58  0x0215BD58  arm  ov009
 *   func_0215B470  0x0215B470  arm  ov009
 *   func_0215AB5C  0x0215AB5C  arm  ov009
 *   g_021A826C  0x021A826C  data
 *   g_021A878E  0x021A878E  data
 */

struct NetVars {
	unsigned char pad0[0x1c];
	unsigned long dhcp_server_ip;
};

extern void func_0215AB10(void);
extern void func_0215AA88(void);
extern void func_0215AAB0(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
extern unsigned char *func_0215BC04(unsigned char *d, int type);
extern unsigned char *func_0215BD58(unsigned char pattern, unsigned long minimum, unsigned char *d, unsigned long curlen);
extern unsigned long func_0215B470(unsigned char *buf, unsigned long len);
extern void func_0215AB5C(void);
extern struct NetVars g_021A826C;
extern unsigned char g_021A878E[];

void func_0215C44C(void)
{
	unsigned char *buf;
	unsigned char *d;

	func_0215AB10();
	func_0215AA88();
	func_0215AAB0(0x44, 0x43, g_021A826C.dhcp_server_ip);
	buf = g_021A878E;
	d = func_0215BC04(buf, 7);
	*d++ = 0x36;
	*d++ = 4;
	*d++ = (unsigned short)(g_021A826C.dhcp_server_ip >> 16) >> 8;
	*d++ = g_021A826C.dhcp_server_ip >> 16;
	*d++ = (unsigned short)g_021A826C.dhcp_server_ip >> 8;
	*d++ = g_021A826C.dhcp_server_ip;
	*d++ = 0xff;
	d = func_0215BD58(0, 300, d, d - buf);
	func_0215B470(buf, d - buf);
	func_0215AB5C();
}
