/*
 * unit:     no
 * function: func_0203F4E4
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
 *   python tools/match.py one --src src/matched/func_0203F4E4.c \
 *       --func func_0203F4E4 --addr 0x0203F4E4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct RtcDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

extern struct RtcDate g_02146A0C;

void func_0203F4E4(struct RtcDate *date)
{
    *date = g_02146A0C;
}
