/*
 * function: HAND_WAZA_GetAllySwitchHandlers
 * address: 0x021E7E4C
 * packet: pkt_ov093_021E7E4C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E7DB0_p02.c and filed here.
 *
 * symbols:
 *   gAllySwitchHandlers 0x021F26CC data a4
 */

extern int gAllySwitchHandlers[];
int *HAND_WAZA_GetAllySwitchHandlers(int *p);

int *HAND_WAZA_GetAllySwitchHandlers(int *p)
{
    *p = 1;
    return gAllySwitchHandlers;
}
