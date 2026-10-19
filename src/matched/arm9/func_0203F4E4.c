/*
 * unit:     no
 * function: GF_STANDARD_GetCachedDate
 * address:  0x0203F4E4
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
 *
 * TU: gf_standard.c.  Copy the cached RTC date out; four words, one ldm/stm
 * pair, no frame.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_GetCachedDate.c \
 *       --func GF_STANDARD_GetCachedDate --addr 0x0203F4E4 --cc 1.1p1 --arm
 */

#include "../include/G_RtcDate.h"

typedef unsigned int u32;

extern struct RtcDate g_02146A0C;

void GF_STANDARD_GetCachedDate(struct RtcDate *date)
{
    *date = g_02146A0C;
}
