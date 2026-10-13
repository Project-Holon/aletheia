/*
 * function: EFFECT_ENCOUNT_PickItemKind4
 * address:  0x021AB018
 * packet:   pkt_ov021_021AB018
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005728  0x02005728  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   sRareItemIds     0x021D8E8A  data  a2
 */

extern unsigned long func_02005728(unsigned long v);
extern unsigned short sRareItemIds[];

unsigned short EFFECT_ENCOUNT_PickItemKind4(void)
{
    unsigned short r = func_02005728(1000);

    if (r < 100)
        return sRareItemIds[(unsigned short)(func_02005728(1000) / 100)];
    if (r < 950)
        return (unsigned short)((unsigned short)(func_02005728(1700) / 100) + 548);
    return 229;
}
