/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_CreateGraphic
 * address:  0x0217AEF4
 * packet:   pkt_0217AEF4
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_GRAPHIC_Create  0x021E5440  thumb  ov177
 */
#include "../include/Obj14355.h"

extern int *WIFIBATTLEMATCH_GRAPHIC_Create(unsigned swap, int heap);

void BATTLE_CHAMPIONSHIP_FLOW_CreateGraphic(int *p)
{
    ((struct Obj14355 *)p)->f24 = (int)WIFIBATTLEMATCH_GRAPHIC_Create(1, ((struct Obj14355 *)p)->f0);
}
