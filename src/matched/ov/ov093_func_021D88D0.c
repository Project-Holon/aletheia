/*
 * function: BTL_CALC_GetStallHandlers
 * address: 0x021D88D0
 * packet: pkt_ov093_021D88D0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_CALC_PackAbilityHandlerInfo 0x021D84F0 thumb ov093
 *   gStallHandlers 0x021F05A0 data a4
 */
extern unsigned int BTL_CALC_PackAbilityHandlerInfo(unsigned int,unsigned int);
extern unsigned char gStallHandlers[];

void *BTL_CALC_GetStallHandlers(unsigned int *p)
{
    *p=BTL_CALC_PackAbilityHandlerInfo(7,1); return gStallHandlers;
}
