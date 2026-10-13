/*
 * function: dt_fin
 * address:  0x02159FE8
 * packet:   pkt_ov009_02159FE8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dt_fin (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   find_socket  0x02159244  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   _tcp_send_ack  0x02159404  arm  ov009
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   _tcp_send_finack  0x02159494  arm  ov009
 *   _tcp_send_rst  0x021594A4  arm  ov009
 */

struct _CPSSoc {
	void *thread;
	unsigned long waiting;
	unsigned char state;
	unsigned char pad0[0x1b];
	unsigned long ackno;
};

extern struct _CPSSoc *find_socket(unsigned char *iphdr, unsigned char *tcphdr);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void _tcp_send_ack(struct _CPSSoc *soc, int flush);
extern void OS_WakeupThreadDirect(void *thread);
extern void _tcp_send_finack(int a);
extern void _tcp_send_rst(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);

void dt_fin(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct _CPSSoc *soc;
	unsigned long enabled;

	soc = find_socket(iphdr, tcphdr);
	if (soc == 0)
		return;
	enabled = OS_DisableInterrupts();
	switch (soc->state) {
	case 7:
		soc->ackno++;
		soc->state = 9;
		OS_RestoreInterrupts(enabled);
		_tcp_send_ack(soc, 2);
		break;
	case 8:
		soc->ackno++;
		OS_RestoreInterrupts(enabled);
		_tcp_send_ack(soc, 2);
		soc->state = 0;
		if (soc->waiting == 2) {
			soc->waiting = 0;
			OS_WakeupThreadDirect(soc->thread);
		}
		break;
	case 4:
		soc->ackno++;
		soc->state = 6;
		OS_RestoreInterrupts(enabled);
		_tcp_send_finack((int)soc);
		break;
	default:
		OS_RestoreInterrupts(enabled);
		_tcp_send_rst(iphdr, tcphdr, len);
		break;
	}
}
