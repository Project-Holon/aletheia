/*
 * function: HAND_TOKUSEI_GetMagicGuardHandlers
 * address: 0x021DB9AC
 * packet: pkt_ov093_021DB9AC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gMagicGuardHandlers 0x021F06F8 data a4
 */
extern int gMagicGuardHandlers;
int *HAND_TOKUSEI_GetMagicGuardHandlers(int *p) { *p=1; return &gMagicGuardHandlers; }
