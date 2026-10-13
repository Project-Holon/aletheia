/*
 * function: FIELD_LIGHT_EvalColorLerp
 * address:  0x021A0860
 * packet:   pkt_ov021_021A0860
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Colour interpolation: three {base, delta} s16 pairs, each channel
 * base + delta * t / n, packed GX_RGB. Each channel is an s16 local set
 * from the quotient and then `+=` its base; a single-expression
 * initialiser lets the compiler hoist all three divisions and evaluate
 * them right to left.
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 * Addresses are Black-image addresses.
 */

typedef signed short   s16;
typedef unsigned short u16;

typedef struct {
    s16 base;
    s16 delta;
} Lerp021A0860;

#define GX_RGB(r, g, b) ((u16)(((r) << 0) | ((g) << 5) | ((b) << 10)))

u16 FIELD_LIGHT_EvalColorLerp(Lerp021A0860 *c, int t, int n)
{
    s16 r = (s16)(c[0].delta * t / n);
    s16 g, b;

    r += c[0].base;
    g = (s16)(c[1].delta * t / n);
    g += c[1].base;
    b = (s16)(c[2].delta * t / n);
    b += c[2].base;
    return GX_RGB(r, g, b);
}
