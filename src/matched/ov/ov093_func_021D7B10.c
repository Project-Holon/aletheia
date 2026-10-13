/*
 * function: BTL_CALC_MulRatio
 * address:  0x021D7B10
 * packet:   pkt_ov093_021D7B10
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-03 (wave B3 lane 10): EXACT. Rounded 20.12 product. The product,
 * the shift and the increment all reuse the parameter a; with a separate
 * product local mwcc copies an operand to r2 first (adds r2,r0,#0; muls).
 * See docs/idioms/a-product-kept-in-its-parameter-multiplies-in-place.md.
 */
typedef unsigned int u32;

u32 BTL_CALC_MulRatio(u32 a, u32 b)
{
    u32 f;

    a *= b;
    f = a & 0xfff;
    a >>= 12;
    if (f > 0x800)
        a++;
    return a;
}
