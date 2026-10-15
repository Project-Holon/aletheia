/*
 * function: BOX2_UI_HideSlots678
 * address:  0x021EE0FC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetActorDrawEnable  0x021EC000  thumb  ov170
 *
 * Release slots 6, 7 and 8 of the 0x9E74 array.
 */
#include "../include/Obj09226.h"


extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);
void BOX2_UI_HideSlots678(char *p)
{
    BOX2_SEQ_SetActorDrawEnable((char *)(((struct Obj09226 *)p)->f2C), 6, 0);
    BOX2_SEQ_SetActorDrawEnable((char *)(((struct Obj09226 *)p)->f2C), 7, 0);
    BOX2_SEQ_SetActorDrawEnable((char *)(((struct Obj09226 *)p)->f2C), 8, 0);
}
