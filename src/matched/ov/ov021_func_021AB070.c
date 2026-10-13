/*
 * function: EFFECT_ENCOUNT_PickItemKind7
 * address:  0x021AB070
 * packet:   pkt_ov021_021AB070
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005728  0x02005728  thumb
 *   _u32_div_f  0x0209C2B0  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02005728(u32 n);

u16 EFFECT_ENCOUNT_PickItemKind7(void)
{
    if ((u16)func_02005728(1000) < 900) {
        return (u16)(func_02005728(600) / 100) + 565;
    }
    return 571;
}
