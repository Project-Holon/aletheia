/*
 * function: HAND_TOKUSEI_LightningRod_CheckRedirect
 * address: 0x021DB460
 * packet: pkt_ov093_021DB460
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   HAND_TOKUSEI_CheckRedirectMoveType 0x021DB4E8 thumb ov093
 */
extern int HAND_TOKUSEI_CheckRedirectMoveType(int,int,int,int);

void HAND_TOKUSEI_LightningRod_CheckRedirect(int a, int b, int c, int *d)
{
    *d = HAND_TOKUSEI_CheckRedirectMoveType(b, c, (int)d, 12);
}
