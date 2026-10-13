/*
 * function: HAND_WAZA_GetMudSportHandlers
 * address: 0x021E06D0
 * packet: pkt_ov093_021E06D0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E0628.c and filed here.
 *
 * symbols:
 *   gMudSportHandlers 0x021F2614 data ov093 a4
 */

int *HAND_WAZA_GetMudSportHandlers(int *p);
extern int gMudSportHandlers[];

/*
 * extent: 0754 tail-call stub; 075C state getter; 0764 64-bit getter; 0772 padding.
 */
int *HAND_WAZA_GetMudSportHandlers(int *p)
{
    *p = 1;
    return gMudSportHandlers;
}
