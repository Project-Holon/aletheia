/*
 * unit: yes
 * function: HAND_TOKUSEI_StormDrain_AbsorbWaterMove, HAND_TOKUSEI_GetLightningRodHandlers
 * address: 0x021DB430
 * packet: pkt_ov093_021DB430
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   HAND_TOKUSEI_AbsorbCheckMoveType 0x021DA8A8 thumb ov093
 *   HAND_TOKUSEI_AbsorbRaiseStat 0x021DA96C thumb ov093
 *   gLightningRodHandlers 0x021F0A70 data a4
 */
extern int HAND_TOKUSEI_AbsorbCheckMoveType(int,int,int);
extern void HAND_TOKUSEI_AbsorbRaiseStat(void *,int,unsigned int,int);
extern const unsigned int gLightningRodHandlers[];

void HAND_TOKUSEI_StormDrain_AbsorbWaterMove(int a, void *b, int c)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType((int)b, c, 10) != 0) HAND_TOKUSEI_AbsorbRaiseStat(b, c, 3, 1);
}

const unsigned int *HAND_TOKUSEI_GetLightningRodHandlers(int *p)
{
    *p = 3;
    return gLightningRodHandlers;
}
