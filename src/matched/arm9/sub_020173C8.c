/*
 * function: MCSS_TOOL_AnimeStopCallback
 * address:  0x020173C8
 * packet:   pkt_0201394C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MCSS_RequestAnimeStopAtStart  0x02016380  thumb
 *
 * A four-byte tail call: the pool word 0x02016381 (Thumb) is loaded and
 * `bx r3` jumps with the incoming r0 untouched, i.e. MCSS_RequestAnimeStopAtStart itself.
 * Its witness is the EXACT entry for 0x02016380 in this same shard - the
 * `matched` class - which is what makes the pool word resolve.
 *
 
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_TOOL_AnimeStopCallback.c \
 *       --func MCSS_TOOL_AnimeStopCallback --addr 0x020173C8 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern void MCSS_RequestAnimeStopAtStart(void *o);

void MCSS_TOOL_AnimeStopCallback(void *o)
{
    MCSS_RequestAnimeStopAtStart(o);
}

