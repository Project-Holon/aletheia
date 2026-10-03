/*
 * function: func_021C3A90
 * address:  0x021C3A90
 * packet:   pkt_ov021_021C3A90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores the base form of the parent species.
 *
 * symbols:
 *   func_021C3BB0  0x021C3BB0  thumb  ov021
 *   func_021C4504  0x021C4504  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_021C3BB0(void *a);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u16 func_021C4504(u16 sp);

void func_021C3A90(void *a, u32 *out)
{
    *out = func_021C4504(func_02017E1C(func_021C3BB0(a), 5, 0));
}
