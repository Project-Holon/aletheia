/*
 * function: BTL_ABILITY_MotorDriveAbsorbElectric
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
 *   BTL_ABILITY_AbsorbCheckMoveType 0x021DA8A8 thumb ov093
 *   BTL_ABILITY_AbsorbRaiseStat 0x021DA96C thumb ov093
 */
extern int BTL_ABILITY_AbsorbCheckMoveType(int, int, int);
extern void BTL_ABILITY_AbsorbRaiseStat(void *, int, unsigned int, int);

void BTL_ABILITY_MotorDriveAbsorbElectric(int a, void *b, int c)
{
    if (BTL_ABILITY_AbsorbCheckMoveType((int)b, c, 0xc))
        BTL_ABILITY_AbsorbRaiseStat(b, c, 5, 1);
}
