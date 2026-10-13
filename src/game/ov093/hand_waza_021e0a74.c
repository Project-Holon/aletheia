/*
 * file:     hand_waza_021e0a74.c
 * unit:     yes
 * function: HAND_WAZA_GetSketchHandlers
 * address:  0x021E0A74
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
 *   gSketchHandlers     0x021F264C  data   ov093  a4
 */
#include "hand_waza_021e0518_types.h"

extern const BtlEventHandler gSketchHandlers[];

const BtlEventHandler *HAND_WAZA_GetSketchHandlers(int *handlerCount);

const BtlEventHandler *HAND_WAZA_GetSketchHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSketchHandlers;
}
