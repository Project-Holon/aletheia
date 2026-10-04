/*
 * function: func_021B1604
 * address:  0x021B1604
 * packet:   pkt_ov021_021B1604
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159168  0x02159168  thumb  ov010
 *   func_02159190  0x02159190  thumb  ov010
 *   func_021904DC  0x021904DC  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern int func_02158F58(int a0);
extern int func_02159190(int a0);
extern void func_021904DC(u8 *p, u8 v);
extern void func_02159168(int n);

int func_021B1604(u32 *a)
{
    u32 *p = (u32 *)func_02158F58(a[2]);
    u32 id = 9;

    if (func_02159190(id)) {
        func_021904DC((u8 *)(*p), 0);
        func_02159168(id);
    }
    return 1;
}
