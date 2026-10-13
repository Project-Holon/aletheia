/*
 * unit: yes
 * function: HAND_TOKUSEI_WaterAbsorbAbsorbWater, HAND_TOKUSEI_GetWaterAbsorbHandlers
 * address: 0x021DAAC0
 * packet: pkt_ov093_021DAAC0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gWaterAbsorbHandlers 0x021F0730 data a4
 *   HAND_TOKUSEI_AbsorbCheckMoveType 0x021DA8A8 thumb ov093
 *   HAND_TOKUSEI_AbsorbRecoverHp 0x021DA8DC thumb ov093
 * extent: includes store-and-return followers 021DAAE0.
 */
extern unsigned char gWaterAbsorbHandlers[];
extern int HAND_TOKUSEI_AbsorbCheckMoveType(int, int, int);
extern void HAND_TOKUSEI_AbsorbRecoverHp(int, int, int);

void HAND_TOKUSEI_WaterAbsorbAbsorbWater(int a, int b, int c)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType(b, c, 10))
        HAND_TOKUSEI_AbsorbRecoverHp(b, c, 4);
}

void *HAND_TOKUSEI_GetWaterAbsorbHandlers(int *p)
{
    *p = 1;
    return gWaterAbsorbHandlers;
}
