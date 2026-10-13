/*
 * function: HAND_WAZA_AddMagicCoat
 * address: 0x021E34A8
 * packet: pkt_ov093_021E34A8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E3420.c and filed here.
 *
 * symbols:
 *   gMagicCoatHandlers 0x021F2F18 data ov093 a4
 */

int *HAND_WAZA_AddMagicCoat(int *p);
extern int gMagicCoatHandlers[];

int *HAND_WAZA_AddMagicCoat(int *p)
{
    *p = 5;
    return gMagicCoatHandlers;
}
