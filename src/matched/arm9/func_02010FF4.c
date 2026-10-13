/*
 * function: GPOWER_ApplyHatchRate
 * address:  0x02010FF4
 * packet:   pkt_02010EEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02146208      0x02146208  data
 *   g_02146228      0x02146228  data
 *   _u32_div_f      0x0209C2B0  arm
 *
 * Scale by the u16 at +6 of g_02146228 unless the mode byte at +0x16 of
 * g_02146208 is 0x30.  The divide is unsigned (`_u32_div_f`, which the runtime
 * table at 0x0209C2B0 calls `_div_by_zero_check`: mwcc's own symbol name for
 * the site is the `_u32_div_f` one, see docs/notes/pkt_0202EC44.c.txt), and the
 * multiply is spelled table-value-first: `x * v`, not `v * x`, or the result
 * register comes out r1 and the function is four bytes too long.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_ApplyHatchRate.c \
 *       --func GPOWER_ApplyHatchRate --addr 0x02010FF4 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 g_02146208[];
extern u8 g_02146228[];

u32 GPOWER_ApplyHatchRate(u32 v)
{
    if (g_02146208[0x16] != 0x30)
        v = *(u16 *)(g_02146228 + 6) * v / 100;
    return v;
}
