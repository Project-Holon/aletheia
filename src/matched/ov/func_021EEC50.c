/*
 * function: BOX2_UI_PlayAndUpdateCursorC
 * address:  0x021EEC50
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_UpdateCursor  0x021EE408  thumb  ov170
 *   CURSOR_MOVE_SetCurrent  0x020260E4  thumb  arm9
 *
 * Twin of BOX2_UI_PlayAndUpdateCursorB.
 */
#include "../include/Obj18532.h"


typedef unsigned char  u8;
struct Sound;
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern void BOX2_UI_UpdateCursor(char *, int);
void BOX2_UI_PlayAndUpdateCursorC(char *p, unsigned int a)
{
    CURSOR_MOVE_SetCurrent((struct Sound *)(*(int *)(((struct Obj18532 *)p)->f2C + 0x70)), (unsigned char)a);
    BOX2_UI_UpdateCursor(p, a);
}
