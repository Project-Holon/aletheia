/*
 * function: func_0215B3A0
 * address:  0x0215B3A0
 * packet:   pkt_ov009_0215B3A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_SocWrite2 (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_021585D8  0x021585D8  arm  ov009
 *   func_02158524  0x02158524  arm  ov009
 *   func_02162CA0  0x02162CA0  arm  ov009
 *   func_0215B198  0x0215B198  arm  ov009
 *   g_02150FEC  0x02150FEC  data
 *   g_021A826C  0x021A826C  data
 */

struct Soc {
	unsigned char pad0[8];
	unsigned char state;
	unsigned char ssl;
};

struct Thread {
	unsigned char pad0[0xa4];
	struct Soc *soc;
};

struct ThreadInfo {
	unsigned long pad;
	struct Thread *current;
};

extern void func_021585D8(unsigned char *data, unsigned long len, struct Soc *soc);
extern void func_02158524(unsigned char *pattern, unsigned long len, struct Soc *soc);
extern unsigned long func_02162CA0(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2, struct Soc *soc);
extern unsigned long func_0215B198(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2, struct Soc *soc);
extern struct ThreadInfo g_02150FEC;
extern unsigned char g_021A826C;

unsigned long func_0215B3A0(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2)
{
	struct Soc *soc;
	unsigned long total_written;

	soc = g_02150FEC.current->soc;
	if (soc != 0) {
		if (soc->state == 10) {
			if (len)
				func_021585D8(buf, len, soc);
			if (len2)
				func_021585D8(buf2, len2, soc);
			total_written = len + len2;
		} else if (soc->state == 11) {
			if (len)
				func_02158524(buf, len, soc);
			if (len2)
				func_02158524(buf2, len2, soc);
			total_written = len + len2;
		} else if (soc->ssl) {
			total_written = func_02162CA0(buf, len, buf2, len2, soc);
		} else {
			total_written = func_0215B198(buf, len, buf2, len2, soc);
		}
		if (!g_021A826C)
			return total_written;
	}
	return 0;
}
