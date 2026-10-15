/*
 * unit:     no
 * function: GF_STANDARD_SetupRtc
 * address:  0x0203F524
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A0C     0x02146A0C  data
 *   g_02146A1C     0x02146A1C  data
 *   RTC_ConvertDateTimeToSecond  0x02089004  arm
 *
 * TU: gf_standard.c.
 *
 * Refresh the cached RTC date and time: a tail call, so the callee's
 * address is a third pool word and the transfer is `bx ip`, and another
 * unlabelled leaf because nothing is pushed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_SetupRtc.c \
 *       --func GF_STANDARD_SetupRtc --addr 0x0203F524 --cc 1.1p1 --arm
 */

#include "../include/G_RtcDate.h"
#include "../include/G_RtcTime.h"

typedef unsigned int u32;

extern struct RtcDate g_02146A0C;
extern struct RtcTime g_02146A1C;

struct RTCDate;
struct RTCTime;
extern long long RTC_ConvertDateTimeToSecond(struct RTCDate *date, struct RTCTime *time);

void GF_STANDARD_SetupRtc(void)
{
    RTC_ConvertDateTimeToSecond((struct RTCDate *)(&g_02146A0C), (struct RTCTime *)(&g_02146A1C));
}
