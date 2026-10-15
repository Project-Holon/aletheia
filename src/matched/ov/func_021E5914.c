/*
 * function: BOX2_SEQ_StateCursorMove
 * address:  0x021E5914
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_SetCursorPos  0x021EE3E4  thumb  ov170
 *   BOX2_SEQ_SetCursorDraw  0x021ED55C  thumb  ov170
 *   BOX2_SEQ_ShowWindowObject  0x021EBA5C  thumb  ov170
 *   BOX2_MAIN_RefreshCursorBox  0x021DD14C  thumb  ov170
 *
 * Refresh the tag-derived index, re-key, arm, retag 0x18, forward,
 *   and report 0x31.
 */
#include "../include/Obj00000.h"


typedef unsigned char  u8;
struct Sound;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void BOX2_UI_SetCursorPos(char **p, unsigned idx);
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern void BOX2_SEQ_ShowWindowObject(char *p, int i);
extern void BOX2_MAIN_RefreshCursorBox(char *);
int BOX2_SEQ_StateCursorMove(char *p)
{
    func_020260E4((struct Sound *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x70)),
                  (unsigned char)(((struct Obj00000 *)p)->f16 - 0x1e));
    BOX2_UI_SetCursorPos((char **)p, ((struct Obj00000 *)p)->f16 - 0x1e);
    BOX2_SEQ_SetCursorDraw((char **)p, 1);
    BOX2_SEQ_ShowWindowObject((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 0x18);
    BOX2_MAIN_RefreshCursorBox(p);
    return 0x31;
}
