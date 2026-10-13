/*
 * function: HAND_WAZA_GetGravityHandlers
 * address: 0x021E061C
 * packet: pkt_ov093_021E061C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E0518.c and filed here.
 *
 * symbols:
 *   gGravityHandlers 0x021F2424 data ov093 a4
 */

int *HAND_WAZA_GetGravityHandlers(int *p);
extern int gGravityHandlers[];

int *HAND_WAZA_GetGravityHandlers(int *p)
{
    *p = 1;
    return gGravityHandlers;
}
