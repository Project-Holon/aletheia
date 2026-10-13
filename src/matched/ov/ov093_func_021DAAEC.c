/*
 * unit: yes
 * function: HAND_TOKUSEI_VoltAbsorbAbsorbElectric, HAND_TOKUSEI_GetVoltAbsorbHandlers, HAND_TOKUSEI_GetMotorDriveHandlers
 * address: 0x021DAAEC
 * packet: pkt_ov093_021DAAEC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gMotorDriveHandlers 0x021F0798 data a4
 *   HAND_TOKUSEI_AbsorbCheckMoveType 0x021DA8A8 thumb ov093
 *   HAND_TOKUSEI_AbsorbRecoverHp 0x021DA8DC thumb ov093
 * extent: includes store-and-return followers 021DAB0C, 021DAB18.
 */
extern unsigned char gMotorDriveHandlers[];
extern int HAND_TOKUSEI_AbsorbCheckMoveType(int, int, int);
extern void HAND_TOKUSEI_AbsorbRecoverHp(int, int, int);

void HAND_TOKUSEI_VoltAbsorbAbsorbElectric(int a, int b, int c)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType(b, c, 12))
        HAND_TOKUSEI_AbsorbRecoverHp(b, c, 4);
}

void *HAND_TOKUSEI_GetVoltAbsorbHandlers(int *p)
{
    *p = 1;
    return gMotorDriveHandlers + 8;
}

void *HAND_TOKUSEI_GetMotorDriveHandlers(int *p)
{
    *p = 1;
    return gMotorDriveHandlers;
}
