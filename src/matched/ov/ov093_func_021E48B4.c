/*
 * function: HAND_WAZA_AddImprison
 * address: 0x021E48B4
 * packet: pkt_ov093_021E48B4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E4754.c and filed here.
 *
 * symbols:
 *   gImprisonHandlers 0x021F2534 data ov093 a4
 */

int *HAND_WAZA_AddImprison(int *p);
extern int gImprisonHandlers[];

int *HAND_WAZA_AddImprison(int *p)
{
    *p = 1;
    return gImprisonHandlers;
}
