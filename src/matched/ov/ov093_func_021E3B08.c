/*
 * function: HAND_WAZA_GetProtectHandlers
 * address: 0x021E3B08
 * packet: pkt_ov093_021E3B08
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E3A48.c and filed here.
 *
 * symbols:
 *   gProtectHandlers 0x021F2D58 data ov093 a4
 */

int *HAND_WAZA_GetProtectHandlers(int *p);
extern int gProtectHandlers[];

int *HAND_WAZA_GetProtectHandlers(int *p)
{
    *p = 4;
    return gProtectHandlers;
}
