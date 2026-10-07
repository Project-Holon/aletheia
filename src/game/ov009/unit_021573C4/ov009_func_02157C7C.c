/*
 * function: func_02157C7C
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
 *   func_02087988  0x02087988  arm
 *   func_020857B0  0x020857B0  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021A826C  0x021A826C  data
 *   g_02150FEC  0x02150FEC  data
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

extern unsigned long func_02087988(void);
extern void func_020857B0(void *queue);
extern unsigned long func_0208799C(unsigned long state);
extern struct NetVars g_021A826C;
extern struct ThreadInfo g_02150FEC;

static inline void *cur_thread(void)
{
	void *volatile t = g_02150FEC.current;
	return t;
}

unsigned char *func_02157C7C(unsigned long *len)
{
	unsigned short blocklen;
	unsigned long enable;
	unsigned char *buf;

	enable = func_02087988();
	while (g_021A826C.head == g_021A826C.tail) {
		g_021A826C.waiter = cur_thread();
		func_020857B0(0);
		g_021A826C.waiter = 0;
	}
	func_0208799C(enable);
	buf = g_021A826C.rcvbuf;
	do {
		if (g_021A826C.rcvsize - g_021A826C.head < 2)
			g_021A826C.head = 0;
		blocklen = *(unsigned short *)(buf + g_021A826C.head);
		if (blocklen == 0)
			g_021A826C.head = 0;
	} while (blocklen == 0);
	*len = blocklen - 2;
	return g_021A826C.rcvbuf + g_021A826C.head + 2;
}
