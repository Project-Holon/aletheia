/*
 * function: HAND_WAZA_GetTauntHandlers
 * address: 0x021E4748
 * packet: pkt_ov093_021E4748
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E4340_p02.c and filed here.
 *
 * symbols:
 *   gTauntHandlers 0x021F2774 data ov093 a4
 */

extern int gTauntHandlers[];
int *HAND_WAZA_GetTauntHandlers(int *p);

int *HAND_WAZA_GetTauntHandlers(int *p)
{
    *p = 1;
    return gTauntHandlers;
}
