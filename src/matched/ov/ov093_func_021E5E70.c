/*
 * function: HAND_WAZA_GetMagnetRiseHandlers
 * address: 0x021E5E70
 * packet: pkt_ov093_021E5E70
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E5B78.c and filed here.
 *
 * symbols:
 *   gMagnetRiseHandlers 0x021F2A38 data ov093 a4
 */

int *HAND_WAZA_GetMagnetRiseHandlers(int *p);
extern int gMagnetRiseHandlers[];

int *HAND_WAZA_GetMagnetRiseHandlers(int *p)
{
    *p = 2;
    return gMagnetRiseHandlers;
}
