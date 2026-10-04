/*
 * function: func_021B5EB8
 * address:  0x021B5EB8
 * packet:   pkt_ov021_021B5EB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0200D298  0x0200D298  thumb
 *   func_0200D2B0  0x0200D2B0  thumb
 *   func_0200D2C4  0x0200D2C4  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5E4(void *a0);
extern void *func_0215A5DC(void *a0);
extern u16 *func_02159AE8(void *a0, void *a1);
extern unsigned int func_02159B10(void *a, void *b);
extern u32 func_0200CA1C(void *a);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_0200D298(u32 a);
extern u32 func_0200D2B0(u32 a, u32 b);
extern u32 func_0200D2C4(u32 a, u32 b);
extern u16 func_02188C84(u8 *p);

int func_021B5EB8(u32 a, u32 b)
{
    u32 w;
    void *s;
    u16 *out;

    w = func_0200CA1C(func_0215A5E4((void *)b));
    s = func_0201210C(func_0215A5DC((void *)b));
    out = func_02159AE8((void *)a, (void *)b);
    switch (func_02159B10((void *)a, (void *)b)) {
    case 1:
        *out = func_0200D298(w);
        break;
    case 3:
        *out = func_0200D2B0(w, func_02188C84(s));
        break;
    case 2:
        *out = func_0200D2C4(w, func_02188C84(s));
        break;
    }
    return 0;
}
