/*
 * function: HAND_WAZA_GetWorrySeedHandlers
 * address: 0x021E0F68
 * packet: pkt_ov093_021E0F68
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
 *   gWorrySeedHandlers 0x021F2A48 data ov093 a4
 */

int *HAND_WAZA_GetWorrySeedHandlers(int *p);
extern int gWorrySeedHandlers[];

int *HAND_WAZA_GetWorrySeedHandlers(int *p)
{
    *p = 2;
    return gWorrySeedHandlers;
}
