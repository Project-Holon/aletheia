/*
 * function: func_021C3AAC
 * address:  0x021C3AAC
 * packet:   pkt_ov021_021C3AAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Nidoran family: offspring species is a coin flip of 0x1D / 0x20.
 *
 * symbols:
 *   func_021C3BB0  0x021C3BB0  thumb  ov021
 */

typedef unsigned int u32;

extern int func_021C3BB0(u32 a);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u32 func_02005728(u32 v);

void func_021C3AAC(void *a, u32 *out)
{
    u32 sp = func_02017E1C((void *)func_021C3BB0((u32)a), 5, 0);

    if (sp == 0x1D || sp - 0x20 <= 2) {
        if (func_02005728(2) == 0)
            *out = 0x1D;
        else
            *out = 0x20;
    }
}
