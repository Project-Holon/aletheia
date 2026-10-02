/*
 * function: func_021B240C
 * address:  0x021B240C
 * packet:   pkt_ov021_021B240C
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021F37C8  0x021F37C8  thumb  ov040
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(void *p);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_021F37C8(void *);

int func_021B240C(u32 a, u32 b)
{
    void *w;
    u16 *o;

    func_0215A5F4((void *)b);
    w = func_0201210C(func_0215A5DC((void *)b));
    o = func_02159AE8((void *)a, (void *)b);
    if (func_021F37C8(w) != 0) {
        *o = 1;
    } else {
        *o = 0;
    }
    return 0;
}
