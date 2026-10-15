/*
 * function: SOCLi_GetOptimumSendBufLen
 * address:  0x0215E588
 * packet:   pkt_ov009_0215E588
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Send-buffer length that fits the current link: min(winSize, mss, the CPS
 * config buffer size), doubled, then as many whole copies of `len` as the
 * divisor helper allows.  Interrupts are off across the window-size read.
 *
 * The lever was the `int max = SOCLiCPSConfig.bufSize;` local: reading the config
 * word into a local *before* the two min compares is what makes the scheduler
 * hoist the config base load above `cmp winSize, mss`, which in turn keeps
 * `mss` alive in r2 (r3 = winSize, r2 = mss, r1 = bufSize).  Reading
 * SOCLiCPSConfig.bufSize inline in the second compare sinks both loads below the
 * first min and reuses r1 for mss (21 bytes out); using `temp` itself as the
 * running minimum forces it into r6 and costs the frame (`push {r4,r5,r6,lr}`).
 *
 * sdk:      SOCLi_GetOptimumSendBufLen (libsoc.TWL.HYB.a(socl_write.o))
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_0209C0A4  0x0209C0A4  arm
 *   gMslRefToken     0x02150FEC  data
 *   SOCLiCPSConfig     0x021AA450  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_0215E588.c \
 *       --func SOCLi_GetOptimumSendBufLen --addr 0x0215E588 --region ov009 --arm --cc 1.1p1 \
 *       --lang c99 --diff
 */

#include "../include/G_CPSConfig.h"

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

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern int func_0209C0A4(int a, int b);
extern Info gMslRefToken;
extern struct CPSConfig SOCLiCPSConfig;

int SOCLi_GetOptimumSendBufLen(int len)
{
	Soc *soc;
	int temp;
	unsigned long enabled;
	int count;

	soc = gMslRefToken.cur->soc;
	enabled = OS_DisableInterrupts();
	if (soc != 0) {
		if (soc->winSize != 0 && soc->mss != 0) {
			int w = soc->winSize;
			int max = SOCLiCPSConfig.bufSize;
			if (w > soc->mss) {
				w = soc->mss;
			}
			if (w > max) {
				w = max;
			}
			temp = w << 1;
		} else {
			temp = SOCLiCPSConfig.bufSize << 1;
		}
	} else {
		temp = SOCLiCPSConfig.bufSize << 1;
	}
	OS_RestoreInterrupts(enabled);
	if (temp > 0) {
		count = func_0209C0A4(len, temp);
		if (count > 0) {
			return temp * count;
		}
	}
	return len;
}
