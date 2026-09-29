/*
 * function: func_0215E588
 * address:  0x0215E588
 * packet:   pkt_ov009_0215E588
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      SOCLi_GetOptimumSendBufLen (libsoc.TWL.HYB.a(socl_write.o))
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_0209C0A4  0x0209C0A4  arm
 *   g_02150FEC  0x02150FEC  data
 *   g_021AA450  0x021AA450  data
 */

typedef struct {
	char pad0[0x38];
	unsigned short mss;
	unsigned short winSize;
} Soc;

typedef struct {
	char pad0[0xa4];
	Soc *soc;
} Thr;

typedef struct {
	char pad0[4];
	Thr *cur;
} Info;

typedef struct {
	char pad0[0x24];
	int bufSize;
} Cfg;

extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);
extern int func_0209C0A4(int a, int b);
extern Info g_02150FEC;
extern Cfg g_021AA450;

int func_0215E588(int len)
{
	int count;
	unsigned long enabled;
	int temp;
	Soc *soc;

	soc = g_02150FEC.cur->soc;
	enabled = func_02087988();
	if (soc != 0) {
		int w = soc->winSize;
		if (w != 0 && soc->mss != 0) {
			if (w > soc->mss) {
				w = soc->mss;
			}
			if (w > g_021AA450.bufSize) {
				w = g_021AA450.bufSize;
			}
			temp = w << 1;
		} else {
			temp = g_021AA450.bufSize << 1;
		}
	} else {
		temp = g_021AA450.bufSize << 1;
	}
	func_0208799C(enabled);
	if (temp > 0) {
		count = func_0209C0A4(len, temp);
		if (count > 0) {
			return temp * count;
		}
	}
	return len;
}
