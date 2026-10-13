/*
 * function: HAND_TOKUSEI_MotorDriveAbsorbElectric
 * address: 0x021DAB24
 * packet: pkt_ov093_021DAB24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding.
 * symbols:
 *   HAND_TOKUSEI_AbsorbCheckMoveType 0x021DA8A8 thumb ov093
 *   HAND_TOKUSEI_AbsorbRaiseStat 0x021DA96C thumb ov093
 */
extern int HAND_TOKUSEI_AbsorbCheckMoveType(int, int, int);
extern void HAND_TOKUSEI_AbsorbRaiseStat(void *, int, unsigned int, int);

void HAND_TOKUSEI_MotorDriveAbsorbElectric(int a, void *b, int c)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType((int)b, c, 0xc))
        HAND_TOKUSEI_AbsorbRaiseStat(b, c, 5, 1);
}
