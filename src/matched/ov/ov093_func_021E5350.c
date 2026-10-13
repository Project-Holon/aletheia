/*
 * function: HAND_WAZA_AddSafeguard
 * address: 0x021E5350
 * packet: pkt_ov093_021E5350
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E5318.c and filed here.
 *
 * symbols:
 *   gSafeguardHandlers 0x021F25CC data ov093 a4
 */

extern int gSafeguardHandlers[];
int *HAND_WAZA_AddSafeguard(int *p);

int *HAND_WAZA_AddSafeguard(int *p)
{
    *p = 1;
    return gSafeguardHandlers;
}
