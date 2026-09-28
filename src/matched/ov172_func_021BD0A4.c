/*
 * function: func_021BD0A4
 * address:  0x021BD0A4
 * packet:   pkt_ov172_021BD0A4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE004  0x021BE004  thumb  ov172
 *   func_0201283C  0x0201283C  thumb
 *   func_02009D50  0x02009D50  thumb
 *
 * Starts a fade on the context's display: forwards the three fade parameters with a zero fourth to 0x02009D50 for the display handle.
 */

typedef unsigned long u32;

extern u32 *func_021BE004(void *p);
extern u32 func_0201283C(u32 h);
extern void func_02009D50(u32 h, u32 a, u32 b, u32 c, u32 d);

void func_021BD0A4(void *ctx, u32 unused, u32 a, u32 b, u32 c)
{
    func_02009D50(func_0201283C(*func_021BE004(ctx)), a, b, c, 0);
}
