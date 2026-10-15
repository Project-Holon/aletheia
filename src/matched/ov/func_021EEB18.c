/*
 * function: BOX2_UI_SetCursorSeqD
 * address:  0x021EEB18
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_MoveCursorBetweenIcons  0x021EEF74  thumb  ov170
 *   BOX2_MAIN_SetSeqParam  0x021DC9B4  thumb  ov170
 *   BOX2_MAIN_SceneApplyScroll  0x021E066C  thumb  ov170
 *
 * Release the child at +0x2c and reset its field +0x5c to the handler.
 */
#include "../include/Obj12181.h"

extern void BOX2_UI_MoveCursorBetweenIcons(char *q, int a, int b);
extern void BOX2_MAIN_SetSeqParam(char *p, int v);
extern int BOX2_MAIN_SceneApplyScroll(char *p);

void BOX2_UI_SetCursorSeqD(char *p, int a, int b)
{
    BOX2_UI_MoveCursorBetweenIcons(*(char * *)&((struct Obj12181 *)p)->f2C, a, b);
    BOX2_MAIN_SetSeqParam(((struct Obj12181 *)p)->f2C, (int)((void *)&BOX2_MAIN_SceneApplyScroll));
}

