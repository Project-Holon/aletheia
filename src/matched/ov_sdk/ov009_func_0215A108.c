/*
 * function: dispatch_tcp
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
 *   check_tcpudpsum            0x02157838  arm  ov009
 *   dt_syn            0x02159720  arm  ov009
 *   dt_synack            0x021597F8  arm  ov009
 *   dt_ack            0x02159A80  arm  ov009
 *   dt_fin            0x02159FE8  arm  ov009
 *   dt_rst            0x0215A0CC  arm  ov009
 *   _tcp_send_rst            0x021594A4  arm  ov009
 */

extern unsigned long check_tcpudpsum(unsigned char *tcpudp_hdr, unsigned long len, unsigned char *ip_hdr, unsigned short proto);
extern void dt_syn(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void dt_synack(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void dt_ack(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void dt_fin(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void dt_rst(unsigned char *iphdr, unsigned char *tcphdr);
extern void _tcp_send_rst(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);

void dispatch_tcp(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	if (len < 20)
		return;
	if ((tcphdr[0xc] & 0xf0) < 0x50)
		return;
	if (len < ((unsigned long)(tcphdr[0xc] & 0xf0) >> 2))
		return;
	if (check_tcpudpsum(tcphdr, len, iphdr, 6) != 0)
		return;
	len -= (unsigned long)(tcphdr[0xc] & 0xf0) >> 2;
	switch (tcphdr[0xd] & 0x17) {
	case 0x02:
		if (tcphdr[0xd] & 0x28)
			return;
		dt_syn(iphdr, tcphdr, len);
		break;
	case 0x12:
		if (tcphdr[0xd] & 0x28)
			return;
		dt_synack(iphdr, tcphdr, len);
		break;
	case 0x10:
	case 0x11:
		dt_ack(iphdr, tcphdr, len);
		break;
	case 0x01:
		dt_fin(iphdr, tcphdr, len);
		break;
	default:
		if (tcphdr[0xd] & 0x04)
			dt_rst(iphdr, tcphdr);
		else
			_tcp_send_rst(iphdr, tcphdr, len);
		break;
	}
}
