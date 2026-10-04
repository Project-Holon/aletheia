/*
 * function: func_021C3BD4
 * address:  0x021C3BD4
 * packet:   pkt_ov021_021C3BD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copies the parent's form for species 0x1A6..0x1A7.
 *
 * symbols:
 *   func_021C3C5C  0x021C3C5C  thumb  ov021
 */

typedef unsigned int u32;

extern int func_021C3C5C(u32 a);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);

void func_021C3BD4(void *a, u32 *out)
{
    void *mon = (void *)func_021C3C5C((u32)a);
    u32 sp = func_02017E1C(mon, 5, 0);

    if (sp - 0x1A6 <= 1)
        out[1] = func_02017E1C(mon, 0x6F, 0);
}
