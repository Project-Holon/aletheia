/*
 * function: func_021AF544
 * address:  0x021AF544
 * packet:   pkt_ov021_021AF544
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201292C  0x0201292C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02007E50  0x02007E50  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0215A5CC(u32 a);
extern void *func_0215A5E4(void *a0);
struct BigObj;
extern void *func_0201292C(const struct BigObj *p);
extern u32 func_02159B10(u32 a, u32 b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u16 func_02007E50(void *a, u32 b, u32 c, u32 d);

int func_021AF544(u32 a, u32 b)
{
    u32 p;
    void *x;
    u32 u, v;
    u16 *h;

    p = func_0215A5CC(b);
    x = func_0201292C(func_0215A5E4((void *)b));
    u = func_02159B10(a, b);
    v = func_02159B10(a, b);
    h = func_02159AE8((void *)a, (void *)b);
    *h = func_02007E50(x, u, v, p);
    return 0;
}
