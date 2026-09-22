/*
 * function: func_020520A4
 * address:  0x020520A4
 * packet:   pkt_020520A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * VEC_MultAdd-style scale: dst = v * s in 1.19.12 fixed point, component by
 * component, with the SDK's own rounding.  Each component is the inlined body
 * of FX_Mul: a 32x32 signed `smull`, +0x800 for round-to-nearest with the
 * carry folded into the high word by `adc`, then the 64-bit >> 12 spelled as
 * `lsr #12` of the low word `orr`ed with `lsl #20` of the high word.  Writing
 * it as a (s64) multiply and shift is what makes the compiler emit exactly
 * that quartet rather than a call to a runtime helper.
 *
 * All three components are computed before any store, which is why the first
 * two land as one `stm r2,{r4,ip}` and only the third takes its own `str`
 * (the source order is x, y, z and the compiler interleaves the three
 * independent multiplies freely).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020520A4.c \
 *       --func func_020520A4 --addr 0x020520A4 --cc 1.1p1 --arm
 */

typedef long long s64;

struct Vec3 {
    int x;  /* 0x00 */
    int y;  /* 0x04 */
    int z;  /* 0x08 */
};

void func_020520A4(const struct Vec3 *v, int s, struct Vec3 *dst)
{
    dst->x = (int)((((s64)v->x * s) + 0x800) >> 12);
    dst->y = (int)((((s64)v->y * s) + 0x800) >> 12);
    dst->z = (int)((((s64)v->z * s) + 0x800) >> 12);
}
