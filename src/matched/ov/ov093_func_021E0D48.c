/*
 * function: HAND_WAZA_GetHazeHandlers
 * address: 0x021E0D48
 * packet: pkt_ov093_021E0D48
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E0C8C.c and filed here.
 *
 * symbols:
 *   gHazeHandlers 0x021F2594 data ov093 a4
 */

int *HAND_WAZA_GetHazeHandlers(int *p);
extern int gHazeHandlers[];

int *HAND_WAZA_GetHazeHandlers(int *p)
{
    *p = 1;
    return gHazeHandlers;
}
