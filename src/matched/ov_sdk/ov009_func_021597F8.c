/*
 * function: dt_synack
 * address:  0x021597F8
 * packet:   pkt_ov009_021597F8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dt_synack (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   find_socket  0x02159244  arm  ov009
 *   _tcp_send_rst  0x021594A4  arm  ov009
 *   OS_YieldThread  0x020858D8  arm
 *   parse_mss  0x021592A8  arm  ov009
 *   _tcp_send_ack  0x02159404  arm  ov009
 *   OS_WakeupThreadDirect  0x02085868  arm
 */

#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define BE32(p, o) (((unsigned long)SWAP16(*(unsigned short *)((p) + (o))) << 16) | SWAP16(*(unsigned short *)((p) + (o) + 2)))

struct _CPSSoc {
	void *thread;
	unsigned long waiting;
	unsigned char state;
	unsigned char pad0[0x1b];
	unsigned long ackno;
	unsigned char pad1[0x10];
	unsigned short remote_win;
	unsigned char pad2[2];
	unsigned long ackrcvd;
};

extern struct _CPSSoc *find_socket(unsigned char *iphdr, unsigned char *tcphdr);
extern void _tcp_send_rst(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void OS_YieldThread(void);
extern void parse_mss(unsigned char *tcphdr, struct _CPSSoc *soc);
extern void _tcp_send_ack(struct _CPSSoc *soc, int flush);
extern void OS_WakeupThreadDirect(void *thread);

void dt_synack(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct _CPSSoc *soc;

	soc = find_socket(iphdr, tcphdr);
	if (soc == 0 || soc->state != 2) {
		_tcp_send_rst(iphdr, tcphdr, len);
		return;
	}
	OS_YieldThread();
	soc->ackno = BE32(tcphdr, 4) + 1;
	soc->ackrcvd = BE32(tcphdr, 8);
	soc->remote_win = SWAP16(*(unsigned short *)(tcphdr + 0xe));
	parse_mss(tcphdr, soc);
	_tcp_send_ack(soc, 2);
	soc->state = 4;
	if (soc->waiting == 1) {
		soc->waiting = 0;
		OS_WakeupThreadDirect(soc->thread);
	}
}
