/*
 * file:     unit_0215E024_p02.c
 * unit:     yes
 * function: func_0215E588, func_0215E620
 * address:  0x0215E588
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
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_0209C0A4  0x0209C0A4  arm
 *   g_02150FEC     0x02150FEC  data
 *   g_021AA450     0x021AA450  data
 */
#include "../../matched/include/G_CPSConfig.h"

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

typedef unsigned char u8;

typedef unsigned int  u32;

struct Ring {
    u8   pad_00[0x10];
    u8  *head;      /* +0x10 */
    int  head_len;  /* +0x14 */
    u8  *tail;      /* +0x18 */
    int  tail_len;  /* +0x1c */
};

extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);
extern int func_0209C0A4(int a, int b);
extern void func_02082EA4(void *a, u8 *b, int n);
int func_0215E588(int len);
int func_0215E620(u8 *dst, int len, struct Ring *r);
extern Info g_02150FEC;
extern struct CPSConfig g_021AA450;


/*
 * Send-buffer length that fits the current link: min(winSize, mss, the CPS
 * config buffer size), doubled, then as many whole copies of `len` as the
 * divisor helper allows.  Interrupts are off across the window-size read.
 *
 * The lever was the `int max = g_021AA450.bufSize;` local: reading the config
 * word into a local *before* the two min compares is what makes the scheduler
 * hoist the config base load above `cmp winSize, mss`, which in turn keeps
 * `mss` alive in r2 (r3 = winSize, r2 = mss, r1 = bufSize).  Reading
 * g_021AA450.bufSize inline in the second compare sinks both loads below the
 * first min and reuses r1 for mss (21 bytes out); using `temp` itself as the
 * running minimum forces it into r6 and costs the frame (`push {r4,r5,r6,lr}`).
 *
 * sdk:      SOCLi_GetOptimumSendBufLen (libsoc.TWL.HYB.a(socl_write.o))
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_0215E588.c \
 *       --func func_0215E588 --addr 0x0215E588 --region ov009 --arm --cc 1.1p1 \
 *       --lang c99 --diff
 */
int func_0215E588(int len)
{
	Soc *soc;
	int temp;
	unsigned long enabled;
	int count;

	soc = g_02150FEC.cur->soc;
	enabled = func_02087988();
	if (soc != 0) {
		if (soc->winSize != 0 && soc->mss != 0) {
			int w = soc->winSize;
			int max = g_021AA450.bufSize;
			if (w > soc->mss) {
				w = soc->mss;
			}
			if (w > max) {
				w = max;
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


/*
 * Consume up to `len` bytes from a two-segment ring object into `dst`: the
 * head segment is `[+0x10]/len[+0x14]`, the wrapped tail `[+0x18]/len[+0x1c]`.
 * A request longer than the head drops the tail entirely (n = len, m = 0),
 * otherwise the tail is clamped to what is left.  Both segments copied with
 * the byte copier at 0x02082EA4, and the two cursors advanced in place.
 * Returns the number of bytes produced.
 */
int func_0215E620(u8 *dst, int len, struct Ring *r)
{
    int n;
    int m;

    n = r->head_len;
    m = r->tail_len;
    if (n > len) {
        n = len;
        m = 0;
    } else if (m > len - n) {
        m = len - n;
    }
    if (n > 0) {
        func_02082EA4(r->head, dst, n);
        r->head += n;
        r->head_len -= n;
    }
    if (m > 0) {
        func_02082EA4(r->tail, dst + n, m);
        r->tail += m;
        r->tail_len -= m;
    }
    return n + m;
}
