/*
 * function: CPSi_TcpShutdownRaw
 * address:  0x0215ACA0
 * packet:   pkt_ov009_0215ACA0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_TcpShutdownRaw (libcps.TWL.HYB.a network.o)
 * symbols:
 *   OS_YieldThread                   0x020858d8 arm
 *   OS_DisableInterrupts             0x02087988 arm
 *   OS_RestoreInterrupts             0x0208799c arm
 *   _tcp_send_finack                 0x02159494 arm
 *   _tcp_send_ack                    0x02159404 arm
 */

struct _CPSSoc {
	unsigned char pad[8];
	unsigned char state;
};

extern void OS_YieldThread(void);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void _tcp_send_finack(struct _CPSSoc *soc);
extern void _tcp_send_ack(struct _CPSSoc *soc, int flush);

void CPSi_TcpShutdownRaw(struct _CPSSoc *soc)
{
	unsigned long enable;
	unsigned char state;

	OS_YieldThread();
	enable = OS_DisableInterrupts();
	state = soc->state;
	if ((unsigned char)(state + 0xfd) <= 1) {
		soc->state = 7;
		OS_RestoreInterrupts(enable);
		_tcp_send_finack(soc);
	} else if (state != 0) {
		OS_RestoreInterrupts(enable);
		_tcp_send_ack(soc, 2);
	} else {
		OS_RestoreInterrupts(enable);
	}
}

