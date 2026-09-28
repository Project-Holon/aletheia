/*
 * function: func_021597F8
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
 *   func_02159244  0x02159244  arm  ov009
 *   func_021594A4  0x021594A4  arm  ov009
 *   func_020858D8  0x020858D8  arm
 *   func_021592A8  0x021592A8  arm  ov009
 *   func_02159404  0x02159404  arm  ov009
 *   func_02085868  0x02085868  arm
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

extern struct _CPSSoc *func_02159244(unsigned char *iphdr, unsigned char *tcphdr);
extern void func_021594A4(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void func_020858D8(void);
extern void func_021592A8(unsigned char *tcphdr, struct _CPSSoc *soc);
extern void func_02159404(struct _CPSSoc *soc, int flush);
extern void func_02085868(void *thread);

void func_021597F8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct _CPSSoc *soc;

	soc = func_02159244(iphdr, tcphdr);
	if (soc == 0 || soc->state != 2) {
		func_021594A4(iphdr, tcphdr, len);
		return;
	}
	func_020858D8();
	soc->ackno = BE32(tcphdr, 4) + 1;
	soc->ackrcvd = BE32(tcphdr, 8);
	soc->remote_win = SWAP16(*(unsigned short *)(tcphdr + 0xe));
	func_021592A8(tcphdr, soc);
	func_02159404(soc, 2);
	soc->state = 4;
	if (soc->waiting == 1) {
		soc->waiting = 0;
		func_02085868(soc->thread);
	}
}
