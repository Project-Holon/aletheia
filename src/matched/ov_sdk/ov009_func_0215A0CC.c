/*
 * function: dt_rst
 * address:  0x0215A0CC
 * packet:   pkt_ov009_0215A0CC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dt_rst (libcps.TWL.HYB.a network.o)
 * symbols:
 *   find_socket                      0x02159244 arm
 *   OS_YieldThread                   0x020858d8 arm
 *   OS_WakeupThreadDirect            0x02085868 arm
 */

struct _OSThread;

struct _CPSSoc {
	struct _OSThread *thread;
	unsigned long block_type;
	unsigned char state;
};

extern struct _CPSSoc *find_socket(unsigned char *iphdr, unsigned char *tcphdr);
extern void OS_YieldThread(void);
extern void OS_WakeupThreadDirect(struct _OSThread *thread);

static void dt_rst(unsigned char *iphdr, unsigned char *tcphdr)
{
	struct _CPSSoc *soc = find_socket(iphdr, tcphdr);

	if (soc == 0)
		return;
	OS_YieldThread();
	soc->state = 0;
	if (soc->block_type - 1 <= 1) {
		soc->block_type = 0;
		OS_WakeupThreadDirect(soc->thread);
	}
}

