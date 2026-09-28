/*
 * function: func_0215A108
 * address:  0x0215A108
 * packet:   pkt_ov009_0215A108
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dispatch_tcp (libcps.TWL.HYB.a network.o)
 *
 * symbols:
 *   func_02157838            0x02157838  arm  ov009
 *   func_02159720            0x02159720  arm  ov009
 *   func_021597F8            0x021597F8  arm  ov009
 *   func_02159A80            0x02159A80  arm  ov009
 *   func_02159FE8            0x02159FE8  arm  ov009
 *   func_0215A0CC            0x0215A0CC  arm  ov009
 *   func_021594A4            0x021594A4  arm  ov009
 */

extern unsigned long func_02157838(unsigned char *tcpudp_hdr, unsigned long len, unsigned char *ip_hdr, unsigned short proto);
extern void func_02159720(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void func_021597F8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void func_02159A80(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void func_02159FE8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void func_0215A0CC(unsigned char *iphdr, unsigned char *tcphdr);
extern void func_021594A4(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);

void func_0215A108(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	if (len < 20)
		return;
	if ((tcphdr[0xc] & 0xf0) < 0x50)
		return;
	if (len < ((unsigned long)(tcphdr[0xc] & 0xf0) >> 2))
		return;
	if (func_02157838(tcphdr, len, iphdr, 6) != 0)
		return;
	len -= (unsigned long)(tcphdr[0xc] & 0xf0) >> 2;
	switch (tcphdr[0xd] & 0x17) {
	case 0x02:
		if (tcphdr[0xd] & 0x28)
			return;
		func_02159720(iphdr, tcphdr, len);
		break;
	case 0x12:
		if (tcphdr[0xd] & 0x28)
			return;
		func_021597F8(iphdr, tcphdr, len);
		break;
	case 0x10:
	case 0x11:
		func_02159A80(iphdr, tcphdr, len);
		break;
	case 0x01:
		func_02159FE8(iphdr, tcphdr, len);
		break;
	default:
		if (tcphdr[0xd] & 0x04)
			func_0215A0CC(iphdr, tcphdr);
		else
			func_021594A4(iphdr, tcphdr, len);
		break;
	}
}
