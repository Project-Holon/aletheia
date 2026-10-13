/*
 * file:     hand_waza_021e6da0.c
 * unit:     yes
 * function: HAND_WAZA_AddMirrorMove
 * address:  0x021E6DA0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Hidden setter that follows a linker veneer, so it cannot join the unit before it.
 *
 * symbols:
 *   gMirrorMoveHandlers     0x021F2574  data   ov093  a4
 */
extern int gMirrorMoveHandlers[];
int *HAND_WAZA_AddMirrorMove(int *handlerCount);

/* Mirror Move: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddMirrorMove(int *handlerCount)
{
    *handlerCount = 1;
    return gMirrorMoveHandlers;
}
