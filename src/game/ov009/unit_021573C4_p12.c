/*
 * file:     unit_021573C4_p12.c
 * unit:     yes
 * function: func_02159720, func_021597F8, func_021598EC
 * address:  0x02159720
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02158F84  0x02158F84  arm  ov009
 *   func_021596A8  0x021596A8  arm  ov009
 *   func_021590BC  0x021590BC  arm  ov009
 *   func_021595C0  0x021595C0  arm  ov009
 *   func_020858D8  0x020858D8  arm
 *   func_02159244  0x02159244  arm  ov009
 *   func_021594A4  0x021594A4  arm  ov009
 *   func_021592A8  0x021592A8  arm  ov009
 *   func_02159404  0x02159404  arm  ov009
 *   func_02085868  0x02085868  arm
 */
#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define BE32(p, o) (((unsigned long)SWAP16(*(unsigned short *)((p) + (o))) << 16) | SWAP16(*(unsigned short *)((p) + (o) + 2)))
struct _CPSSoc;
struct Soc;
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

struct rwin {
    unsigned long a;
    unsigned long b;
    unsigned long order;
};

struct soc {
    char pad[0x70];
    struct rwin rw[3];
};

extern unsigned long func_02158F84(unsigned long ip1, unsigned long ip2);
extern unsigned long func_021596A8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern struct Soc *func_021590BC(unsigned char *iphdr, unsigned char *tcphdr);
extern void func_021595C0(unsigned char *iphdr, unsigned char *tcphdr, struct _CPSSoc *soc);
extern void func_020858D8(void);
extern struct _CPSSoc *func_02159244(unsigned char *iphdr, unsigned char *tcphdr);
extern void func_021594A4(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern void func_021592A8(unsigned char *tcphdr, struct _CPSSoc *soc);
extern void func_02159404(struct _CPSSoc *soc, int flush);
extern void func_02085868(void *thread);
void func_02159720(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void func_021597F8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void func_021598EC(struct soc *soc, long chunk);


/*
 * sdk:      dt_syn (libcps.TWL.HYB.a(network.o))
 */
void func_02159720(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct _CPSSoc *soc;

	if (func_02158F84(BE32(iphdr, 0xc), BE32(iphdr, 0x10)) == 0)
		return;
	if (func_021596A8(iphdr, tcphdr, len) != 0)
		return;
	soc = (struct _CPSSoc *)func_021590BC(iphdr, tcphdr);
	if (soc != 0) {
		func_021595C0(iphdr, tcphdr, soc);
		return;
	}
	func_020858D8();
	soc = (struct _CPSSoc *)func_021590BC(iphdr, tcphdr);
	if (soc != 0)
		func_021595C0(iphdr, tcphdr, soc);
}


/*
 * sdk:      dt_synack (libcps.TWL.HYB.a(network.o))
 */
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


void func_021598EC(struct soc *soc, long chunk)
{
    long ci;
    unsigned long order_max = 0;

    for (ci = 0; ci < 3 && soc->rw[ci].a != 0; ci++) {
        if (order_max < soc->rw[ci].order)
            order_max = soc->rw[ci].order;
    }
    soc->rw[chunk].order = order_max + 1;
}
