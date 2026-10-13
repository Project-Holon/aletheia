/*
 * function: HAND_WAZA_GetRefreshHandlers
 * address: 0x021E0C80
 * packet: pkt_ov093_021E0C80
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E0A80.c and filed here.
 *
 * symbols:
 *   gRefreshHandlers 0x021F2434 data ov093 a4
 */

extern int gRefreshHandlers[];
int *HAND_WAZA_GetRefreshHandlers(int *p);

int *HAND_WAZA_GetRefreshHandlers(int *p)
{
    *p = 1;
    return gRefreshHandlers;
}
