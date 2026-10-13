/*
 * function: HAND_WAZA_FocusEnergyGetHandlers
 * address: 0x021E1E38
 * packet: pkt_ov093_021E1E38
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E1C8C.c and filed here.
 *
 * symbols:
 *   gFocusEnergyHandlers 0x021F24FC data ov093 a4
 */

int *HAND_WAZA_FocusEnergyGetHandlers(int *p);
extern int gFocusEnergyHandlers[];

int *HAND_WAZA_FocusEnergyGetHandlers(int *p)
{
    *p = 1;
    return gFocusEnergyHandlers;
}
