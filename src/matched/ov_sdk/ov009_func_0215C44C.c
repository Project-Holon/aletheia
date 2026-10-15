/*
 * function: dhcp_release_server
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
 *   CPS_SocUse  0x0215AB10  arm  ov009
 *   CPS_SocDatagramMode  0x0215AA88  arm  ov009
 *   CPS_SocBind  0x0215AAB0  arm  ov009
 *   dhcp_setcommon  0x0215BC04  arm  ov009
 *   pad_mem  0x0215BD58  arm  ov009
 *   CPS_SocWrite  0x0215B470  arm  ov009
 *   CPS_SocRelease  0x0215AB5C  arm  ov009
 *   gCpsNetVars  0x021A826C  data
 *   gCpsDhcpBuffer  0x021A878E  data
 */

struct NetVars {
	unsigned char pad0[0x1c];
	unsigned long dhcp_server_ip;
};

extern void CPS_SocUse(void);
extern void CPS_SocDatagramMode(void);
extern void CPS_SocBind(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
extern unsigned char *dhcp_setcommon(unsigned char *d, int type);
extern unsigned char *pad_mem(unsigned char pattern, unsigned long minimum, unsigned char *d, unsigned long curlen);
extern unsigned long CPS_SocWrite(unsigned char *buf, unsigned long len);
extern void CPS_SocRelease(void);
extern struct NetVars gCpsNetVars;
extern unsigned char gCpsDhcpBuffer[];

void dhcp_release_server(void)
{
	unsigned char *buf;
	unsigned char *d;

	CPS_SocUse();
	CPS_SocDatagramMode();
	CPS_SocBind(0x44, 0x43, gCpsNetVars.dhcp_server_ip);
	buf = gCpsDhcpBuffer;
	d = dhcp_setcommon(buf, 7);
	*d++ = 0x36;
	*d++ = 4;
	*d++ = (unsigned short)(gCpsNetVars.dhcp_server_ip >> 16) >> 8;
	*d++ = gCpsNetVars.dhcp_server_ip >> 16;
	*d++ = (unsigned short)gCpsNetVars.dhcp_server_ip >> 8;
	*d++ = gCpsNetVars.dhcp_server_ip;
	*d++ = 0xff;
	d = pad_mem(0, 300, d, d - buf);
	CPS_SocWrite(buf, d - buf);
	CPS_SocRelease();
}
