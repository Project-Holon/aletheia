/*
 * unit: yes
 * function: BTL_ABILITY_VoltAbsorbAbsorbElectric, BTL_ABILITY_GetVoltAbsorbHandlers, BTL_ABILITY_GetMotorDriveHandlers
 * address: 0x021DAAEC
 * packet: pkt_ov093_021DAAEC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gMotorDriveHandlerTable 0x021F0798 data a4
 *   BTL_ABILITY_AbsorbCheckMoveType 0x021DA8A8 thumb ov093
 *   BTL_ABILITY_AbsorbRecoverHp 0x021DA8DC thumb ov093
 * extent: includes store-and-return followers 021DAB0C, 021DAB18.
 */
extern unsigned char gMotorDriveHandlerTable[];
extern int BTL_ABILITY_AbsorbCheckMoveType(int, int, int);
extern void BTL_ABILITY_AbsorbRecoverHp(int, int, int);

void BTL_ABILITY_VoltAbsorbAbsorbElectric(int a, int b, int c)
{
    if (BTL_ABILITY_AbsorbCheckMoveType(b, c, 12))
        BTL_ABILITY_AbsorbRecoverHp(b, c, 4);
}

void *BTL_ABILITY_GetVoltAbsorbHandlers(int *p)
{
    *p = 1;
    return gMotorDriveHandlerTable + 8;
}

void *BTL_ABILITY_GetMotorDriveHandlers(int *p)
{
    *p = 1;
    return gMotorDriveHandlerTable;
}
