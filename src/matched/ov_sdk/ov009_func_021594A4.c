/*
 * function: _tcp_send_rst
 * address:  0x021594A4
 * packet:   pkt_ov009_021594A4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      _tcp_send_rst (libcps.TWL.HYB.a network.o)
 *
 * symbols:
 *   MI_CpuFill8              0x02082BCC  arm
 *   _tcp_send_handshake            0x021593A8  arm  ov009
 *   g_021A8484               0x021A8484  data
 */

struct _CPSSoc {
	unsigned char pad0[0xa];
	unsigned short local_port;      /* 0x0a */
	unsigned char padc[0xc];
	unsigned short remote_port;     /* 0x18 */
	unsigned char pad1a[2];
	unsigned long remote_ip;        /* 0x1c */
	unsigned char pad20[4];
	unsigned long ackno;            /* 0x24 */
	unsigned char pad28[0xc];
	unsigned long seqno;            /* 0x34 */
	unsigned char pad38[0x68];
};

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void _tcp_send_handshake(char *soc, unsigned char flag);
extern struct _CPSSoc g_021A8484;

#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define GET16(p) SWAP16(*(unsigned short *)(p))
#define GET32(p) (((unsigned long)GET16(p) << 16) | GET16((p) + 2))

void _tcp_send_rst(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct _CPSSoc *soc;

	soc = &g_021A8484;
	MI_CpuFill8(soc, 0, sizeof(struct _CPSSoc));
	soc->local_port = GET16(tcphdr + 2);
	soc->remote_port = GET16(tcphdr);
	soc->remote_ip = GET32(iphdr + 0xc);
	if (tcphdr[0xd] & 0x10) {
		soc->seqno = GET32(tcphdr + 8);
		_tcp_send_handshake((char *)soc, 4);
		return;
	}
	soc->seqno = 0;
	soc->ackno = GET32(tcphdr + 4) + len;
	if (tcphdr[0xd] & 3)
		soc->ackno++;
	_tcp_send_handshake((char *)soc, 0x14);
}
