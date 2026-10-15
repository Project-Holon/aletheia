/*
 * unit:     no
 * function: GF_STANDARD_CopyCachedRtc
 * address:  0x0203F49C
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A0C  0x02146A0C  data
 *   g_02146A1C  0x02146A1C  data
 *
 * TU: gf_standard.c.
 *
 * Copy the cached RTC date and time out to the caller.  Both are whole
 * structure assignments, four words and three words, so each becomes one
 * inlined ldm/stm pair and the two out pointers have to be parked in lr and
 * ip because the copies want r0-r3.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_CopyCachedRtc.c \
 *       --func GF_STANDARD_CopyCachedRtc --addr 0x0203F49C --cc 1.1p1 --arm
 */

#include "../include/G_RtcDate.h"
#include "../include/G_RtcTime.h"

typedef unsigned int u32;

extern struct RtcDate g_02146A0C;
extern struct RtcTime g_02146A1C;

void GF_STANDARD_CopyCachedRtc(struct RtcDate *date, struct RtcTime *time)
{
    *date = g_02146A0C;
    *time = g_02146A1C;
}
