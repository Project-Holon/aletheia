/*
 * function: DWC_GetDateTime
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
 *   RTC_GetDateTime  0x020889C0  arm
 *   RTC_ConvertDateTimeToSecond  0x02089004  arm
 *   RTC_ConvertSecondToDateTime  0x020891E0  arm
 *   gDwcNasTimeDiff     0x021AA834  data
 *   gDwcNasTimeBase     0x021AA838  data
 *   gDwcNasTimeOffset     0x021AA840  data
 */

#include "../include/G_NasTimeDiff_.h"

struct RTCDate;
struct RTCTime;
extern int RTC_GetDateTime(struct RTCDate *date, struct RTCTime *time);
extern long long RTC_ConvertDateTimeToSecond(struct RTCDate *date, struct RTCTime *time);
extern void RTC_ConvertSecondToDateTime(struct RTCDate *date, struct RTCTime *time, long long sec);
extern struct NasTimeDiff_ gDwcNasTimeDiff;
extern long long gDwcNasTimeBase;
extern long long gDwcNasTimeOffset;

int DWC_GetDateTime(void *date, void *time)
{
    long long localsec;

    if ((*(int *)&gDwcNasTimeDiff) == 0)
        return 0;
    if (RTC_GetDateTime(date, time) != 0)
        return 0;
    localsec = RTC_ConvertDateTimeToSecond(date, time);
    if (localsec == -1LL)
        return 0;
    if (localsec < gDwcNasTimeBase)
        localsec += 3155760000LL;
    localsec -= gDwcNasTimeOffset;
    if (localsec < 0 || localsec > 3155759999LL)
        return 0;
    RTC_ConvertSecondToDateTime(date, time, localsec);
    return 1;
}
