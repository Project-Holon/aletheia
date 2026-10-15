/*
 * function: CPSi_TcpConnectRaw
 * address:  0x0215ABB0
 * packet:   pkt_ov009_0215ABB0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_TcpConnectRaw (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   get_seqno  0x0215AA18  arm  ov009
 *   func_020870D0  0x020870D0  arm
 *   _tcp_send_handshake  0x021593A8  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_SleepThread  0x020857B0  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   gCpsNetVars  0x021A826C  data
 */

struct NetVars {
	unsigned char pad0[0x50];
	unsigned long myip;
};

struct Soc {
	unsigned char pad0[4];
	unsigned long block_type;
	unsigned char state;
	unsigned char pad1[7];
	unsigned long when;
	unsigned char pad2[0x20];
	unsigned long seqno;
};

extern unsigned long get_seqno(void);
extern unsigned long long func_020870D0(void);
extern void _tcp_send_handshake(char *soc, unsigned char flag);
extern unsigned long OS_DisableInterrupts(void);
extern void OS_SleepThread(void *queue);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern struct NetVars gCpsNetVars;

unsigned long CPSi_TcpConnectRaw(struct Soc *soc)
{
	unsigned long retry;
	unsigned long seqno;
	unsigned long enabled;

	seqno = get_seqno();
	for (retry = 0; retry < 3; retry++) {
		soc->seqno = seqno;
		soc->state = 2;
		soc->when = (unsigned long)(func_020870D0() >> 16);
		_tcp_send_handshake((char *)soc, 2);
		enabled = OS_DisableInterrupts();
		if (soc->state == 2 && gCpsNetVars.myip != 0) {
			soc->block_type = 1;
			OS_SleepThread(0);
		}
		OS_RestoreInterrupts(enabled);
		if (soc->state == 4)
			return 0;
		if (gCpsNetVars.myip == 0)
			break;
	}
	return 1;
}
