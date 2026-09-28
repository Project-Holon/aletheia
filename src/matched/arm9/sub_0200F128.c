/*
 * function: sub_0200F128
 * address:  0x0200F128
 * packet:   pkt_0200F168
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A piecewise remap of one id space onto another: below 0xdf the id passes
 * through unchanged; two disjoint windows (0x1000..0x1235 and
 * 0x2000..0x2009) are rebased by subtracting a fixed offset (0xf21 and
 * 0x1ceb respectively, read as u16); everything else, including the gap
 * between the two windows, maps to the constant 0xa.  Each `if` here has to
 * be written with the in-window case as the `then` and the fallback as the
 * trailing `return`, not the other way around, or the branch polarity comes
 * out reversed; see docs/idioms/the-fall-through-arm-is-the-source-order.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F128.c \
 *       --func sub_0200F128 --addr 0x0200F128 --cc 1.1p1
 */

typedef unsigned short u16;
typedef unsigned int u32;

u32 sub_0200F128(u32 x)
{
    if (x < 0xdf) {
        return x;
    }
    if (x >= 0x1000 && x < 0x1236) {
        return (u16)(x - 0xf21);
    }
    if (x >= 0x2000 && x < 0x200a) {
        return (u16)(x - 0x1ceb);
    }
    return 0xa;
}
