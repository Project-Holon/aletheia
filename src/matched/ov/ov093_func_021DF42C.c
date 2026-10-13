/*
 * function: HAND_ITEM_GetGriseousOrbHandlers
 * address: 0x021DF42C
 * packet: pkt_ov093_021DF42C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF3A4.c and filed here.
 *
 * symbols:
 *   gGriseousOrbHandlers 0x021F1534 data ov093 a4
 */

int *HAND_ITEM_GetGriseousOrbHandlers(int *p);
extern int gGriseousOrbHandlers[];

int *HAND_ITEM_GetGriseousOrbHandlers(int *p)
{
    *p = 1;
    return gGriseousOrbHandlers;
}
