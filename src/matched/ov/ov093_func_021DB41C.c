/*
 * function: BTL_TOKUSEI_StormDrain_CheckRedirect
 * address: 0x021DB41C
 * packet: pkt_ov093_021DB41C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_TOKUSEI_CheckRedirectMoveType 0x021DB4E8 thumb ov093
 */
extern int BTL_TOKUSEI_CheckRedirectMoveType(int,int,int,int);

void BTL_TOKUSEI_StormDrain_CheckRedirect(int a, int b, int c, int *d)
{
    *d = BTL_TOKUSEI_CheckRedirectMoveType(b, c, (int)d, 10);
}
