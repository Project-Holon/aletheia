/*
 * function: TOUCHPANEL_HitCircle
 * address:  0x02035A70
 * packet:   pkt_02035760
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The radius test of a packed four-byte record: (x - p[1])^2 + (y - p[2])^2 is
 * compared against p[3]^2, and the answer is 1 when it is strictly smaller.
 * The two differences are the second and third arguments, which is why the
 * argument registers r1 and r2 are subtracted from p[1] and p[2] rather than
 * the other way round.
 *
 * Two tells worth keeping.  The squared radius is computed with `smulbb`,
 * a 16x16 multiply, because p[3] is a `u8` and mwcc knows both factors fit in
 * sixteen bits; the two distance squares need the full 32-bit `mul`/`mla`
 * because their operands are `int` differences.  And the comparison is
 * unsigned (`movcc`/`movcs`), which is free here: both sides are sums of
 * squares and therefore non-negative, so mwcc may pick either.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TOUCHPANEL_HitCircle.c \
 *       --func TOUCHPANEL_HitCircle --addr 0x02035A70 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef signed int    s32;
typedef unsigned int  u32;

u32 TOUCHPANEL_HitCircle(u8 *p, s32 x, s32 y)
{
    s32 dx = p[1] - x;
    s32 dy = p[2] - y;
    u32 r = p[3];

    return (u32)(dx * dx + dy * dy) < r * r;
}
