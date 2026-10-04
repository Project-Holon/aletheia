/*
 * function: func_021B0480
 * address:  0x021B0480
 * packet:   pkt_ov021_021B0480
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_02191008  0x02191008  thumb  ov021
 *   func_0215A630  0x0215A630  thumb  ov010
 *   func_0202F038  0x0202F038  thumb
 *   func_0215A624  0x0215A624  thumb  ov010
 *   func_0215A614  0x0215A614  thumb  ov010
 *   func_02159168  0x02159168  thumb  ov010
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern int func_02159190(int a0);
extern int func_0215A61C(int a0);
extern int func_02191008(u32 a);
extern u32 func_0215A630(u8 *p);
extern void func_0202F038(u8 *p);
extern void func_0215A624(u8 *p, u32 v);
extern void func_0215A614(u8 *p, u32 v);
extern void func_02159168(int n);

void func_021B0480(u32 a)
{
    u32 t;

    if (func_02159190(1)) {
        func_02191008(func_0215A61C(a));
        t = func_0215A630((u8 *)a);
        if (t) {
            func_0202F038((void *)t);
            func_0215A624((u8 *)a, 0);
        }
        func_0215A614((u8 *)a, 0);
        func_02159168(1);
    }
}
