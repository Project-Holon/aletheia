/*
 * function: func_0215ABB0
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
 *   func_0215AA18  0x0215AA18  arm  ov009
 *   func_020870D0  0x020870D0  arm
 *   func_021593A8  0x021593A8  arm  ov009
 *   func_02087988  0x02087988  arm
 *   func_020857B0  0x020857B0  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021A826C  0x021A826C  data
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

extern unsigned long func_0215AA18(void);
extern unsigned long long func_020870D0(void);
extern void func_021593A8(struct Soc *soc, unsigned char flag);
extern unsigned long func_02087988(void);
extern void func_020857B0(void *queue);
extern unsigned long func_0208799C(unsigned long state);
extern struct NetVars g_021A826C;

unsigned long func_0215ABB0(struct Soc *soc)
{
	unsigned long retry;
	unsigned long seqno;
	unsigned long enabled;

	seqno = func_0215AA18();
	for (retry = 0; retry < 3; retry++) {
		soc->seqno = seqno;
		soc->state = 2;
		soc->when = (unsigned long)(func_020870D0() >> 16);
		func_021593A8(soc, 2);
		enabled = func_02087988();
		if (soc->state == 2 && g_021A826C.myip != 0) {
			soc->block_type = 1;
			func_020857B0(0);
		}
		func_0208799C(enabled);
		if (soc->state == 4)
			return 0;
		if (g_021A826C.myip == 0)
			break;
	}
	return 1;
}
