/*
 * function: func_021C3250
 * address:  0x021C3250
 * packet:   pkt_ov021_021C3250
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Resets the held item when it is item 0x1EC.
 */

typedef unsigned int u32;

extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void func_02017988(void *mon, u32 v);

void func_021C3250(void *mon)
{
    if (func_02017E1C(mon, 5, 0) == 0x1EC)
        func_02017988(mon, 0);
}
