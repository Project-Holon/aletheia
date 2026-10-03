/*
 * function: func_021D1A54
 * address:  0x021D1A54
 * packet:   pkt_ov021_021D1A54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   func_02159104  0x02159104  thumb  ov010
 *   func_0215910C  0x0215910C  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021D1884  0x021D1884  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern u32 func_0215910C(void *a);
extern void func_021D1884(u32 a);
extern void func_02159104(u8 *p, u32 v);

int func_021D1A54(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);

    func_021D1884(func_0215910C(x));
    func_02159104(x, 0);
    return 0;
}
