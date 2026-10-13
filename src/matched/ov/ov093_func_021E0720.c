/*
 * function: HAND_WAZA_GetDefogHandlers
 * address: 0x021E0720
 * packet: pkt_ov093_021E0720
 * region: ov093
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E06DC.c and filed here.
 *
 * symbols:
 *   gDefogHandlers 0x021F29B8 data ov093 a4
 */

extern int gDefogHandlers[];
int *HAND_WAZA_GetDefogHandlers(int *p);

int *HAND_WAZA_GetDefogHandlers(int *p)
{
    *p = 2;
    return gDefogHandlers;
}
