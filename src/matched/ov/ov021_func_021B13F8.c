/*
 * function: func_021B13F8
 * address:  0x021B13F8
 * packet:   pkt_ov021_021B13F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159168  0x02159168  thumb  ov010
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A614  0x0215A614  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_02192628  0x02192628  thumb  ov021
 */

typedef unsigned int u32;

extern int func_02159190(int a0);
extern int func_0215A61C(int a0);
extern void func_02192628(u32);
extern void func_0215A614(u32, u32);
extern void func_02159168(int n);

void func_021B13F8(u32 a)
{
    u32 id = 6;

    if (func_02159190(id)) {
        func_02192628(func_0215A61C(a));
        func_0215A614(a, 0);
        func_02159168(id);
    }
}
