/*
 * function: func_02167ED8
 * address:  0x02167ED8
 * packet:   pkt_ov009_02167ED8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GetDateTime (libdwcnas.TWL.HYB.a dwc_nasfunc.o)
 *
 * symbols:
 *   func_020889C0  0x020889C0  arm
 *   RTC_ConvertDateTimeToSecond  0x02089004  arm
 *   RTC_ConvertSecondToDateTime  0x020891E0  arm
 *   g_021AA834     0x021AA834  data
 *   g_021AA838     0x021AA838  data
 *   g_021AA840     0x021AA840  data
 */

#include "../include/G_NasTimeDiff_.h"

struct RTCDate;
struct RTCTime;
extern int func_020889C0(struct RTCDate *date, struct RTCTime *time);
extern long long RTC_ConvertDateTimeToSecond(struct RTCDate *date, struct RTCTime *time);
extern void RTC_ConvertSecondToDateTime(struct RTCDate *date, struct RTCTime *time, long long sec);
extern struct NasTimeDiff_ g_021AA834;
extern long long g_021AA838;
extern long long g_021AA840;

int func_02167ED8(void *date, void *time)
{
    long long localsec;

    if ((*(int *)&g_021AA834) == 0)
        return 0;
    if (func_020889C0(date, time) != 0)
        return 0;
    localsec = RTC_ConvertDateTimeToSecond(date, time);
    if (localsec == -1LL)
        return 0;
    if (localsec < g_021AA838)
        localsec += 3155760000LL;
    localsec -= g_021AA840;
    if (localsec < 0 || localsec > 3155759999LL)
        return 0;
    RTC_ConvertSecondToDateTime(date, time, localsec);
    return 1;
}
