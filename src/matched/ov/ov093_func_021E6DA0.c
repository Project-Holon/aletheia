/*
 * function: HAND_WAZA_AddMirrorMove
 * address: 0x021E6DA0
 * packet: pkt_ov093_021E6DA0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E6DA0.c and filed here.
 *
 * symbols:
 *   gMirrorMoveHandlers 0x021F2574 data ov093 a4
 */

extern int gMirrorMoveHandlers[];
int *HAND_WAZA_AddMirrorMove(int *p);

int *HAND_WAZA_AddMirrorMove(int *p)
{
    *p = 1;
    return gMirrorMoveHandlers;
}
