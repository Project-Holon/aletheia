/*
 * function: HAND_WAZA_GetBeatUpHandlers
 * address: 0x021E6004
 * packet: pkt_ov093_021E6004
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
 *   gBeatUpHandlers 0x021F2A68 data ov093 a4
 */

int *HAND_WAZA_GetBeatUpHandlers(int *p);
extern int gBeatUpHandlers[];

int *HAND_WAZA_GetBeatUpHandlers(int *p)
{
    *p = 2;
    return gBeatUpHandlers;
}
