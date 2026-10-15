/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_DeleteGraphic
 * address:  0x0217AF04
 * packet:   pkt_0217AF04
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_GRAPHIC_Delete  0x021E54E0  thumb  ov177
 */
#include "../include/Obj03869.h"

extern void WIFIBATTLEMATCH_GRAPHIC_Delete(char *p);

void BATTLE_CHAMPIONSHIP_FLOW_DeleteGraphic(int *p)
{
    WIFIBATTLEMATCH_GRAPHIC_Delete((char *)(((struct Obj03869 *)p)->f24));
    ((struct Obj03869 *)p)->f24 = 0;
}
