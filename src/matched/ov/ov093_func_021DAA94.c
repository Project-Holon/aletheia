/*
 * unit: yes
 * function: BTL_ABILITY_DrySkinAbsorbWater, BTL_ABILITY_GetDrySkinHandlers
 * address: 0x021DAA94
 * packet: pkt_ov093_021DAA94
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gDrySkinHandlerTable 0x021F0B30 data a4
 *   BTL_ABILITY_AbsorbCheckMoveType 0x021DA8A8 thumb ov093
 *   BTL_ABILITY_AbsorbRecoverHp 0x021DA8DC thumb ov093
 * extent: includes store-and-return followers 021DAAB4.
 */
extern unsigned char gDrySkinHandlerTable[];
extern int BTL_ABILITY_AbsorbCheckMoveType(int, int, int);
extern void BTL_ABILITY_AbsorbRecoverHp(int, int, int);

void BTL_ABILITY_DrySkinAbsorbWater(int a, int b, int c)
{
    if (BTL_ABILITY_AbsorbCheckMoveType(b, c, 10))
        BTL_ABILITY_AbsorbRecoverHp(b, c, 4);
}

void *BTL_ABILITY_GetDrySkinHandlers(int *p)
{
    *p = 3;
    return gDrySkinHandlerTable;
}
