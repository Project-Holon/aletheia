/*
 * unit: yes
 * function: BTL_TOKUSEI_StormDrain_AbsorbWaterMove, BTL_TOKUSEI_GetLightningRodHandlers
 * address: 0x021DB430
 * packet: pkt_ov093_021DB430
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_ABILITY_AbsorbCheckMoveType 0x021DA8A8 thumb ov093
 *   BTL_ABILITY_AbsorbRaiseStat 0x021DA96C thumb ov093
 *   gLightningRodHandlers 0x021F0A70 data a4
 */
extern int BTL_ABILITY_AbsorbCheckMoveType(int,int,int);
extern void BTL_ABILITY_AbsorbRaiseStat(void *,int,unsigned int,int);
extern const unsigned int gLightningRodHandlers[];

void BTL_TOKUSEI_StormDrain_AbsorbWaterMove(int a, void *b, int c)
{
    if (BTL_ABILITY_AbsorbCheckMoveType((int)b, c, 10) != 0) BTL_ABILITY_AbsorbRaiseStat(b, c, 3, 1);
}

const unsigned int *BTL_TOKUSEI_GetLightningRodHandlers(int *p)
{
    *p = 3;
    return gLightningRodHandlers;
}
