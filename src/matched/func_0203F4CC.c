/*
 * unit:     no
 * function: func_0203F4CC
 * address:  0x0203F4CC
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A1C  0x02146A1C  data
 *
 * TU: gf_standard.c.  Copy the cached RTC time out; three words, so one
 * ldm/stm pair and no frame at all.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F4CC.c \
 *       --func func_0203F4CC --addr 0x0203F4CC --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct RtcTime {
    u32 hour;
    u32 minute;
    u32 second;
};

extern struct RtcTime g_02146A1C;

void func_0203F4CC(struct RtcTime *time)
{
    *time = g_02146A1C;
}
