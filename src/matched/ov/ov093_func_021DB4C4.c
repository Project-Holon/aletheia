/*
 * function: HAND_TOKUSEI_LightningRod_AbsorbElectricMove
 * address: 0x021DB4C4
 * packet: pkt_ov093_021DB4C4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   HAND_TOKUSEI_AbsorbCheckMoveType 0x021DA8A8 thumb ov093
 *   HAND_TOKUSEI_AbsorbRaiseStat 0x021DA96C thumb ov093
 */
extern int HAND_TOKUSEI_AbsorbCheckMoveType(int,int,int);
extern void HAND_TOKUSEI_AbsorbRaiseStat(void *,int,unsigned int,int);

void HAND_TOKUSEI_LightningRod_AbsorbElectricMove(int a, void *b, int c)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType((int)b, c, 12) != 0) HAND_TOKUSEI_AbsorbRaiseStat(b, c, 3, 1);
}
