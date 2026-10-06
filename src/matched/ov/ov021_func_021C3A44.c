/*
 * function: func_021C3A44
 * address:  0x021C3A44
 * packet:   pkt_ov021_021C3A44
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Applies the special-case hook for species 0x84 holding item 2 (EXACT*: pad).
 *
 * symbols:
 *   func_021C3A70  0x021C3A70  thumb  ov021
 */

typedef unsigned int u32;

extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void func_021C3A70(u32 *p);

void func_021C3A44(void **p)
{
    u32 sp = func_02017E1C(p[0], 5, 0);
    u32 item = func_02017E1C(p[1], 0x6E, 0);

    if (sp == 0x84 && item == 2)
        func_021C3A70((u32 *)p);
}
