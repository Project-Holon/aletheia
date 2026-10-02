/*
 * function: func_021B27F8
 * address:  0x021B27F8
 * packet:   pkt_ov021_021B27F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021F3B18  0x021F3B18  thumb  ov046
 */

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern u32 func_02159B10(u32, u32);
extern u32 func_021F3B18(u32, u32);
extern void func_0215897C(u32, u32);

int func_021B27F8(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = func_021F3B18(d, func_02159B10(a, b));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, r);
    return 1;
}
