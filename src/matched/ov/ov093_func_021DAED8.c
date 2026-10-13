/*
 * function: HAND_TOKUSEI_GetDampHandlers
 * address: 0x021DAED8
 * packet: pkt_ov093_021DAED8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DA624_p02.c and filed here.
 *
 * symbols:
 *   gDampHandlers 0x021F0BD4 data ov093 a4
 */

int *HAND_TOKUSEI_GetDampHandlers(int *p);
extern int gDampHandlers[];

int *HAND_TOKUSEI_GetDampHandlers(int *p)
{
    *p = 5;
    return gDampHandlers;
}
