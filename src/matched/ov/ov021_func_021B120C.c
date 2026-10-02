/*
 * function: func_021B120C
 * address:  0x021B120C
 * packet:   pkt_ov021_021B120C
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02191978  0x02191978  thumb  ov021
 */

typedef unsigned int u32;

extern u32 func_02159190(u32);
extern void *func_0215A5F4(void *p);
extern u32 *func_02158F58(u32);
extern void func_02191978(u32);
extern void func_02159168(u32);

void func_021B120C(u32 a)
{
    u32 id = 5;

    if (func_02159190(id)) {
        func_02191978(*func_02158F58(func_0215A5F4((void *)a)));
        func_02159168(id);
    }
}
