/*
 * function: HAND_WAZA_GetQuickGuardHandlers
 * address: 0x021E7E00
 * packet: pkt_ov093_021E7E00
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
 *   gQuickGuardHandlers 0x021F2DB8 data ov093 a4
 */

extern int gQuickGuardHandlers[];
int *HAND_WAZA_GetQuickGuardHandlers(int *p);

int *HAND_WAZA_GetQuickGuardHandlers(int *p)
{
    *p = 4;
    return gQuickGuardHandlers;
}
