/*
 * function: MCSS_RequestAnimeStopAtStart
 * address:  0x02016380
 * packet:   pkt_0201394C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Set bit 0 of the word at +0x144: read, clear, set, write back.  The two
 * `movs r1, #1` are the two separate constants of the `& ~1` / `| 1` pair
 * (Thumb has no ORR immediate, so both go through r1).  Entry attested by
 * the pool word 0x02016381 in MCSS_TOOL_AnimeStopCallback's own pool.
 *
 
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_RequestAnimeStopAtStart.c \
 *       --func MCSS_RequestAnimeStopAtStart --addr 0x02016380 --cc 1.1p1 --thumb
 */
#include "../include/Obj11719.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


void MCSS_RequestAnimeStopAtStart(void *o)
{
    u32 v = ((struct Obj11719 *)o)->f144;

    v = v & ~1u;
    v = v | 1u;
    ((struct Obj11719 *)o)->f144 = v;
}

