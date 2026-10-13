/*
 * function: HAND_WAZA_GetDreamEaterHandlers
 * address: 0x021E1010
 * packet: pkt_ov093_021E1010
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E0F50.c and filed here.
 *
 * symbols:
 *   gDreamEaterHandlers 0x021F28E8 data ov093 a4
 */

int *HAND_WAZA_GetDreamEaterHandlers(int *p);
extern int gDreamEaterHandlers[];

int *HAND_WAZA_GetDreamEaterHandlers(int *p)
{
    *p = 2;
    return gDreamEaterHandlers;
}
