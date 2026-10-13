/*
 * function: HAND_WAZA_AddNaturalGift
 * address: 0x021E3324
 * packet: pkt_ov093_021E3324
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E324C.c and filed here.
 *
 * symbols:
 *   gNaturalGiftHandlers 0x021F2E18 data a4
 */

int *HAND_WAZA_AddNaturalGift(int *p);
extern int gNaturalGiftHandlers;

int *HAND_WAZA_AddNaturalGift(int *p)
{
    *p = 4;
    return &gNaturalGiftHandlers;
}
