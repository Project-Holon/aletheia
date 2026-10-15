/*
 * function: receive_packet
 * address:  0x02157C7C
 * packet:   pkt_ov009_02157C7C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      receive_packet (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_SleepThread  0x020857B0  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   gCpsNetVars  0x021A826C  data
 *   gMslRefToken  0x02150FEC  data
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */

struct NetVars {
	unsigned char pad0[0x20];
	unsigned char *rcvbuf;
	unsigned char pad1[0x30];
	void *waiter;
	unsigned long pad2;
	unsigned long rcvsize;
	unsigned long tail;
	unsigned long head;
};

struct ThreadInfo {
	unsigned long pad;
	void *current;
};

extern unsigned long OS_DisableInterrupts(void);
extern void OS_SleepThread(void *queue);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern struct NetVars gCpsNetVars;
extern struct ThreadInfo gMslRefToken;

static inline void *cur_thread(void)
{
	void *volatile t = gMslRefToken.current;
	return t;
}

unsigned char *receive_packet(unsigned long *len)
{
	unsigned short blocklen;
	unsigned long enable;
	unsigned char *buf;

	enable = OS_DisableInterrupts();
	while (gCpsNetVars.head == gCpsNetVars.tail) {
		gCpsNetVars.waiter = cur_thread();
		OS_SleepThread(0);
		gCpsNetVars.waiter = 0;
	}
	OS_RestoreInterrupts(enable);
	buf = gCpsNetVars.rcvbuf;
	do {
		if (gCpsNetVars.rcvsize - gCpsNetVars.head < 2)
			gCpsNetVars.head = 0;
		blocklen = *(unsigned short *)(buf + gCpsNetVars.head);
		if (blocklen == 0)
			gCpsNetVars.head = 0;
	} while (blocklen == 0);
	*len = blocklen - 2;
	return gCpsNetVars.rcvbuf + gCpsNetVars.head + 2;
}
