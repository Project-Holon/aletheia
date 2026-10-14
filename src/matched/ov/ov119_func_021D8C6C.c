/*
 * function: POKETRADE_PROC_ClearDragIcon
 * address:  0x021D8C6C
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear the pending pointer and hand the object to the updater.
 *
 * symbols:
 *   POKETRADE_2D_DeleteFloatingIconActor  0x021E66E8  thumb  ov119
 */
#include "../include/Obj04474.h"

extern void POKETRADE_2D_DeleteFloatingIconActor(void *p);

void POKETRADE_PROC_ClearDragIcon(void *p)
{
    if (((struct Obj04474 *)p)->fF60 != 0)
        ((struct Obj04474 *)p)->fF60 = 0;
    POKETRADE_2D_DeleteFloatingIconActor(p);
}

