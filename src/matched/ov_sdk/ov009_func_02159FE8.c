/*
 * function: func_02159FE8
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
 *   func_02159244  0x02159244  arm  ov009
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02159404  0x02159404  arm  ov009
 *   func_02085868  0x02085868  arm
 *   func_02159494  0x02159494  arm  ov009
 *   func_021594A4  0x021594A4  arm  ov009
 */

struct _CPSSoc {
	void *thread;
	unsigned long waiting;
	unsigned char state;
	unsigned char pad0[0x1b];
	unsigned long ackno;
};

extern struct _CPSSoc *func_02159244(unsigned char *iphdr, unsigned char *tcphdr);
extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);
extern void func_02159404(struct _CPSSoc *soc, int flush);
extern void func_02085868(void *thread);
extern void func_02159494(int a);
extern void func_021594A4(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);

void func_02159FE8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct _CPSSoc *soc;
	unsigned long enabled;

	soc = func_02159244(iphdr, tcphdr);
	if (soc == 0)
		return;
	enabled = func_02087988();
	switch (soc->state) {
	case 7:
		soc->ackno++;
		soc->state = 9;
		func_0208799C(enabled);
		func_02159404(soc, 2);
		break;
	case 8:
		soc->ackno++;
		func_0208799C(enabled);
		func_02159404(soc, 2);
		soc->state = 0;
		if (soc->waiting == 2) {
			soc->waiting = 0;
			func_02085868(soc->thread);
		}
		break;
	case 4:
		soc->ackno++;
		soc->state = 6;
		func_0208799C(enabled);
		func_02159494((int)soc);
		break;
	default:
		func_0208799C(enabled);
		func_021594A4(iphdr, tcphdr, len);
		break;
	}
}
