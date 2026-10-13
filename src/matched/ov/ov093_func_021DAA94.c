/*
 * unit: yes
 * function: HAND_TOKUSEI_DrySkinAbsorbWater, HAND_TOKUSEI_GetDrySkinHandlers
 * address: 0x021DAA94
 * packet: pkt_ov093_021DAA94
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gDrySkinHandlers 0x021F0B30 data a4
 *   HAND_TOKUSEI_AbsorbCheckMoveType 0x021DA8A8 thumb ov093
 *   HAND_TOKUSEI_AbsorbRecoverHp 0x021DA8DC thumb ov093
 * extent: includes store-and-return followers 021DAAB4.
 */
extern unsigned char gDrySkinHandlers[];
extern int HAND_TOKUSEI_AbsorbCheckMoveType(int, int, int);
extern void HAND_TOKUSEI_AbsorbRecoverHp(int, int, int);

void HAND_TOKUSEI_DrySkinAbsorbWater(int a, int b, int c)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType(b, c, 10))
        HAND_TOKUSEI_AbsorbRecoverHp(b, c, 4);
}

void *HAND_TOKUSEI_GetDrySkinHandlers(int *p)
{
    *p = 3;
    return gDrySkinHandlers;
}
