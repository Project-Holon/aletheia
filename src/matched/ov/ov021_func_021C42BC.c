/*
 * function: func_021C42BC
 * address:  0x021C42BC
 * packet:   pkt_ov021_021C42BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pikachu offspring learns move 0x158 when a parent holds item 0xEC.
 *
 * symbols:
 *   func_021C42F4  0x021C42F4  thumb  ov021
 */

typedef unsigned int u32;

extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void func_021C42F4(u32 *q, u32 move);

void func_021C42BC(void **p, u32 *q)
{
    if (q[0] == 0xAC) {
        if (func_02017E1C(p[0], 6, 0) == 0xEC || func_02017E1C(p[1], 6, 0) == 0xEC)
            func_021C42F4(q, 0x158);
    }
}
