/*
 * function: func_021C3A00
 * address:  0x021C3A00
 * packet:   pkt_ov021_021C3A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021C3A70  0x021C3A70  thumb  ov021
 */

typedef unsigned int u32;

extern u32 func_02017E1C(void *a, u32 b, u32 c);
extern void func_021C3A70(u32 *p);

void func_021C3A00(u32 *p)
{
    u32 a = func_02017E1C((void *)p[0], 0x6e, 0);

    func_02017E1C((void *)p[1], 0x6e, 0);
    if (a == 1)
        func_021C3A70(p);
    func_02017E1C((void *)p[0], 0x6e, 0);
    if (func_02017E1C((void *)p[1], 0x6e, 0) == 0)
        func_021C3A70(p);
}
