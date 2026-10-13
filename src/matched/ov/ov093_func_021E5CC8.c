/*
 * function: HAND_WAZA_GetFlingHandlers
 * address: 0x021E5CC8
 * packet: pkt_ov093_021E5CC8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E5B78.c and filed here.
 *
 * symbols:
 *   gFlingHandlers 0x021F2EC8 data ov093 a4
 */

int *HAND_WAZA_GetFlingHandlers(int *p);
extern int gFlingHandlers[];

int *HAND_WAZA_GetFlingHandlers(int *p)
{
    *p = 5;
    return gFlingHandlers;
}
