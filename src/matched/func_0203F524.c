/*
 * unit:     no
 * function: func_0203F524
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
 *   func_02089004  0x02089004  arm
 *
 * TU: gf_standard.c.
 *
 * Refresh the cached RTC date and time: a tail call, so the callee's
 * address is a third pool word and the transfer is `bx ip`, and another
 * unlabelled leaf because nothing is pushed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F524.c \
 *       --func func_0203F524 --addr 0x0203F524 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct RtcDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

struct RtcTime {
    u32 hour;
    u32 minute;
    u32 second;
};

extern struct RtcDate g_02146A0C;
extern struct RtcTime g_02146A1C;

extern void func_02089004(struct RtcDate *date, struct RtcTime *time);

void func_0203F524(void)
{
    func_02089004(&g_02146A0C, &g_02146A1C);
}
