/*
 * function: func_021B5128
 * address:  0x021B5128
 * packet:   pkt_ov021_021B5128
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAB48  0x021AAB48  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
typedef unsigned char  u8;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_02188CE8(u8 *p);
extern u16 func_021AAB48(u32);

int func_021B5128(u32 a, u32 b)
{
    void *w = func_0201210C(func_0215A5DC((void *)b));
    u16 *o = func_02159AE8((void *)a, (void *)b);

    *o = func_021AAB48(func_02188CE8(w));
    return 0;
}
