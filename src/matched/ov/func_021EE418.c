/*
 * function: BOX2_UI_ShowCursor
 * address:  0x021EE418
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_UI_UpdateCursor  0x021EE408  thumb  ov170
 *   BOX2_SEQ_SetActorDrawEnable  0x021EC000  thumb  ov170
 *
 * Run the frame update, then release slot 4 with force 1.
 */
#include "../include/Obj18526.h"


extern void BOX2_UI_UpdateCursor(char *p, int v);
extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);
void BOX2_UI_ShowCursor(char *p, int v)
{
    BOX2_UI_UpdateCursor(p, v);
    BOX2_SEQ_SetActorDrawEnable((char *)(((struct Obj18526 *)p)->f2C), 4, 1);
}
