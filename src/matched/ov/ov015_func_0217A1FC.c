/*
 * function: IRCi_CheckTimeout
 * address:  0x0217A1FC
 * packet:   pkt_ov015_0217A1FC
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    2026-10-05 wave P16 lane E5: libirc timeout check. Elapsed ticks since the stored tick, converted
 *           to milliseconds as (ticks << 6) / 33514 (same form as ov094 BTLV_TIMER_IsExpired); true after 100 ms.
 *           Plain C, no pragmas.
 *
 * symbols:
 *   func_020870D0  0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm
 *   IRCi_Finish  0x0217A0CC  arm  ov015
 *   d_0217ABA8     0x0217ABA8  data  ov015
 */

#include "../include/G_ov015_0217ABA8.h"

typedef unsigned int u32;
typedef unsigned long long u64;
extern struct G_ov015_0217ABA8 d_0217ABA8;
extern u64 func_020870D0(void);
extern void IRCi_Finish(int a);

int IRCi_CheckTimeout(void)
{
    u64 d;

    if (d_0217ABA8.f24 == 0 && d_0217ABA8.f1C == 0)
        return 0;
    d = func_020870D0() - d_0217ABA8.tick;
    d = (d << 6) / 33514ULL;
    if (d < 100)
        return 0;
    IRCi_Finish(1);
    d_0217ABA8.f1C = 0;
    return 1;
}
