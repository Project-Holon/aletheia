/*
 * function: func_021B10A4
 * address:  0x021B10A4
 * packet:   pkt_ov021_021B10A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B10A4  0x021B10A4  thumb
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_021915B4  0x021915B4  thumb  ov021
 *   func_0215A614  0x0215A614  thumb  ov010
 *   func_02159168  0x02159168  thumb  ov010
 */

extern int func_02159190(int);
extern int func_0215A61C(int a0);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_021915B4(u32 a);
extern void func_0215A614(u8 *p, u32 v);
extern void func_02159168(int);

void func_021B10A4(void *p)
{
    int n = 3;
    if (func_02159190(3) != 0) {
        func_021915B4(func_0215A61C((int)p));
        func_0215A614(p, 0);
        func_02159168(n);
    }
}
