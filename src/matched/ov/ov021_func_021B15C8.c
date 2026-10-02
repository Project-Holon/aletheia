/*
 * function: func_021B15C8
 * address:  0x021B15C8
 * packet:   pkt_ov021_021B15C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02011330  0x02011330  thumb
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159144  0x02159144  thumb  ov010
 *   func_02159168  0x02159168  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021904DC  0x021904DC  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern u32 *func_02158F58(void *);
extern u32 func_02011330(u32);
extern void func_021904DC(u32, u32);
extern void func_02159144(u32);
extern void func_02159168(u32);

int func_021B15C8(u32 a, u32 b)
{
    u32 *p = func_02158F58(func_0215A5F4((void *)b));

    if (func_02011330(a)) {
        func_021904DC(*p, 1);
        func_02159144(9);
    } else {
        func_021904DC(*p, 0);
        func_02159168(9);
    }
    return 0;
}
