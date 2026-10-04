/*
 * function: func_021C3B0C
 * address:  0x021C3B0C
 * packet:   pkt_ov021_021C3B0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Manaphy parents produce Phione.
 *
 * symbols:
 *   func_021C3BB0  0x021C3BB0  thumb  ov021
 */

typedef unsigned int u32;

extern int func_021C3BB0(u32 a);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);

void func_021C3B0C(void *a, u32 *out)
{
    if (func_02017E1C((void *)func_021C3BB0((u32)a), 5, 0) == 0x1EA)
        *out = 0x1E9;
}
