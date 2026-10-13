/*
 * function: HAND_WAZA_AddVenoshock
 * address: 0x021E6FBC
 * packet: pkt_ov093_021E6FBC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E6F14_p02.c and filed here.
 *
 * symbols:
 *   gVenoshockHandlers 0x021F251C data ov093 a4
 */

extern int gVenoshockHandlers[];
int *HAND_WAZA_AddVenoshock(int *p);

int *HAND_WAZA_AddVenoshock(int *p)
{
    *p = 1;
    return gVenoshockHandlers;
}
