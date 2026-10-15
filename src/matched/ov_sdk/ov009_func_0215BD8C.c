/*
 * function: dhcp_send_discover
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
 *   dhcp_setcommon  0x0215BC04  arm  ov009
 *   pad_mem  0x0215BD58  arm  ov009
 *   CPS_SocWrite  0x0215B470  arm  ov009
 *   gCpsNetVars     0x021A826C  data
 *   gCpsDhcpBuffer     0x021A878E  data
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

extern unsigned char *dhcp_setcommon(unsigned char *d, int type);
extern unsigned char *pad_mem(unsigned char pattern, unsigned long minimum, unsigned char *d, unsigned long curlen);
extern unsigned long CPS_SocWrite(unsigned char *buf, unsigned long len);
extern struct NetVars gCpsNetVars;
extern unsigned char gCpsDhcpBuffer[];

unsigned long dhcp_send_discover(void)
{
	unsigned char *buf = gCpsDhcpBuffer;
	unsigned char *d;

	gCpsNetVars.rand_state = gCpsNetVars.rand_mult * gCpsNetVars.rand_state + gCpsNetVars.rand_inc;
	gCpsNetVars.xid = (unsigned long)(gCpsNetVars.rand_state >> 32);
	d = dhcp_setcommon(buf, 1);
	if (gCpsNetVars.offered_myip != 0) {
		*d++ = 0x32;
		*d++ = 4;
		*d++ = (unsigned short)(gCpsNetVars.offered_myip >> 16) >> 8;
		*d++ = gCpsNetVars.offered_myip >> 16;
		*d++ = (unsigned short)gCpsNetVars.offered_myip >> 8;
		*d++ = gCpsNetVars.offered_myip;
	}
	*d++ = 0xff;
	d = pad_mem(0, 300, d, d - buf);
	CPS_SocWrite(buf, d - buf);
	return gCpsNetVars.xid;
}
