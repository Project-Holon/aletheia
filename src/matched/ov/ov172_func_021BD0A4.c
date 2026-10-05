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

struct BigObj;
struct Sub020097BCObj;
extern u32 func_021BE004(void *p);
extern u32 func_0201283C(const struct BigObj *p);
extern int func_02009D50(struct Sub020097BCObj *obj, const void *unused, u32 id, u32 kind, u32 *out);

int func_021BD0A4(void *ctx, u32 unused, u32 a, u32 b, u32 c)
{
    return func_02009D50((struct Sub020097BCObj *)func_0201283C((const struct BigObj *)(*((u32 *)func_021BE004(ctx)))), (const void *)a, b, c, 0);
}
