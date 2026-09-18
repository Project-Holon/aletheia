/*
 * function: func_02010EEC
 * address:  0x02010EEC
 * packet:   pkt_02010EEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02146228  0x02146228  data
 *   g_021461E8  0x021461E8  data
 *   _u32_div_f  0x0209C2B0  arm
 *
 * Index g_02146228[0x1c] selects one of thirteen u32 counters in g_021461E8;
 * 0xd means "none" and answers 0, otherwise the counter is divided by 60 and
 * a zero quotient is lifted to 1.  The divide is unsigned (`_u32_div_f`), so the
 * counter is read as u32.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010EEC.c \
 *       --func func_02010EEC --addr 0x02010EEC --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u8 g_02146228[];
extern u32 g_021461E8[];

extern u32 _u32_div_f(u32 a, u32 b);

int func_02010EEC(void)
{
    u8 idx = g_02146228[0x1c];
    u32 v;

    if (idx == 0xd) {
        return 0;
    }
    v = g_021461E8[idx] / 0x3c;
    if (v == 0) {
        v = 1;
    }
    return v;
}
