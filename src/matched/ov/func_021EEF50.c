/*
 * function: BOX2_UI_SetCursorSeqJ
 * address:  0x021EEF50
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
 * Detach the sub-object and seat the reset handler.
 */
#include "../include/Obj12188.h"



extern void BOX2_UI_MoveCursorBetweenIcons(char *q, int a, int b);
extern void BOX2_MAIN_SetSeqParam(char *, int);
extern int BOX2_MAIN_SceneApplyScroll(char *p);
void BOX2_UI_SetCursorSeqJ(char *p, int a, int b)
{
    BOX2_UI_MoveCursorBetweenIcons(*(char * *)&((struct Obj12188 *)p)->f2C, a, b);
    BOX2_MAIN_SetSeqParam(*(char * *)&((struct Obj12188 *)p)->f2C, (int)BOX2_MAIN_SceneApplyScroll);
}
