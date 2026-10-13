/*
 * function: dt_syn_LISTEN
 * address:  0x021595C0
 * packet:   pkt_ov009_021595C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dt_syn_LISTEN (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_020870D0  0x020870D0  arm
 *   parse_mss  0x021592A8  arm  ov009
 *   _tcp_send_handshake  0x021593A8  arm  ov009
 */

#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define BE32(p, o) (((unsigned long)SWAP16(*(unsigned short *)((p) + (o))) << 16) | SWAP16(*(unsigned short *)((p) + (o) + 2)))

struct _CPSSoc {
	unsigned char pad0[8];
	unsigned char state;
	unsigned char pad1[7];
	unsigned long seqno;
	unsigned long local_ip;
	unsigned short remote_port;
	unsigned char pad2[2];
	unsigned long remote_ip;
	unsigned char pad3[4];
	unsigned long ackno;
};

extern unsigned long long func_020870D0(void);
extern void parse_mss(unsigned char *tcphdr, struct _CPSSoc *soc);
extern void _tcp_send_handshake(char *soc, unsigned char flag);

void dt_syn_LISTEN(unsigned char *iphdr, unsigned char *tcphdr, struct _CPSSoc *soc)
{
	soc->state = 3;
	soc->seqno = (unsigned long)(func_020870D0() >> 16);
	soc->local_ip = BE32(iphdr, 0x10);
	soc->remote_port = SWAP16(*(unsigned short *)tcphdr);
	soc->remote_ip = BE32(iphdr, 0xc);
	soc->ackno = BE32(tcphdr, 4) + 1;
	parse_mss(tcphdr, soc);
	_tcp_send_handshake((char *)soc, 0x12);
}
