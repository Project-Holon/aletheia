/*
 * function: func_021DC564
 * address: 0x021DC564
 * packet: pkt_ov093_021DC564
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_CALC_PackAbilityHandlerInfo 0x021D84F0 thumb ov093
 *   gPoisonTouchHandlers 0x021F0600 data a4
 */
extern unsigned int BTL_CALC_PackAbilityHandlerInfo(unsigned int, unsigned int);
extern unsigned char gPoisonTouchHandlers[];
void *func_021DC564(unsigned int *p)
{
    *p = BTL_CALC_PackAbilityHandlerInfo(4, 1);
    return gPoisonTouchHandlers;
}
