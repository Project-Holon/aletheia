/*
 * function: func_021C3ADC
 * address:  0x021C3ADC
 * packet:   pkt_ov021_021C3ADC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Volbeat / Illumise: offspring species is a coin flip of the two.
 *
 * symbols:
 *   func_021C3BB0  0x021C3BB0  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_021C3BB0(void *a);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u32 func_02005728(u32 v);

void func_021C3ADC(void *a, u32 *out)
{
    u32 sp = func_02017E1C(func_021C3BB0(a), 5, 0);

    if (sp == 0x139 || sp == 0x13A) {
        if (func_02005728(2) == 0)
            *out = 0x139;
        else
            *out = 0x13A;
    }
}
