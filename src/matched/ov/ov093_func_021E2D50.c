/*
 * function: HAND_WAZA_AddTrumpCard
 * address: 0x021E2D50
 * packet: pkt_ov093_021E2D50
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E2ACC.c and filed here.
 *
 * symbols:
 *   gTrumpCardHandlers 0x021F272C data ov093 a4
 */

int *HAND_WAZA_AddTrumpCard(int *p);
extern int gTrumpCardHandlers[];

int *HAND_WAZA_AddTrumpCard(int *p)
{
    *p = 1;
    return gTrumpCardHandlers;
}
