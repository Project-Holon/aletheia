/*
 * function: func_021C3C30
 * address:  0x021C3C30
 * packet:   pkt_ov021_021C3C30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copies the parent's form for species 0x226.
 *
 * symbols:
 *   func_021C3C5C  0x021C3C5C  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_021C3C5C(void *a);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);

void func_021C3C30(void *a, u32 *out)
{
    void *mon = func_021C3C5C(a);
    u32 sp = func_02017E1C(mon, 5, 0);

    if (sp == 0x226)
        out[1] = func_02017E1C(mon, 0x6F, 0);
}
