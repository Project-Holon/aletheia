/*
 * function: HAND_WAZA_PerishSongGetHandlers
 * address: 0x021E1F90
 * packet: pkt_ov093_021E1F90
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E1E44.c and filed here.
 *
 * symbols:
 *   gPerishSongHandlers 0x021F2988 data ov093 a4
 */

int *HAND_WAZA_PerishSongGetHandlers(int *p);
extern int gPerishSongHandlers[];

int *HAND_WAZA_PerishSongGetHandlers(int *p)
{
    *p = 2;
    return gPerishSongHandlers;
}
