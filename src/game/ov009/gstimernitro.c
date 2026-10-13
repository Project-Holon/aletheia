/*
 * file:     gstimernitro.c
 * function: func_02184098
 * address:  0x02184098
 * packet:   pkt_ov009_02184098
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiTimeNitro (gstimernitro.o)
 *
 * symbols:
 *   func_020870D0                  0x020870D0  arm
 *   _ll_udiv                       0x0209C00C  arm
 */

extern unsigned long long func_020870D0(void);

long func_02184098(long *timer)
{
    long t = (long)((func_020870D0() * 64) / 0x01FF6210ULL);
    if (timer != 0)
        *timer = t;
    return t;
}
