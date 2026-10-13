/*
 * unit:     no
 * address:  0x02021438
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: PALANM_StopTimer
 *
 * symbols:
 *   g_02146788  0x02146788  data
 *
 * Clears the one word at 0x02146788.  Four bytes of code and its pool word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_StopTimer.c \
 *       --func PALANM_StopTimer --addr 0x02021438 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32 g_02146788;

void PALANM_StopTimer(void)
{
    g_02146788 = 0;
}
