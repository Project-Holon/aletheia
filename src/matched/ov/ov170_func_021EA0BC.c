/*
 * function: BOX2_SEQ_HideSlotWindow
 * address:  0x021EA0BC
 * packet:   pkt_ov170_021EA0BC
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetSlotDrawPriority 0x021EC768 thumb
 *   BOX2_SEQ_MoveCursorActor 0x021ED594 thumb
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb
 *   BOX2_UI_HideWindowA 0x021EF680 thumb
 *   BOX2_UI_HideWindowB 0x021EF69C thumb
 *   func_02026124 0x02026124 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_SceneWaitCursor 0x021E0778 thumb
 */
#include "../include/Obj00000.h"

typedef struct {
    int pad[9];
    int x24;
} Top;

extern void BOX2_SEQ_SetSlotDrawPriority(char *p, unsigned i, int flag);
extern void BOX2_SEQ_MoveCursorActor(char *p, unsigned i);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
extern void BOX2_UI_HideWindowA(char *w);
extern void BOX2_UI_HideWindowB(char *w);
typedef unsigned int   u32;
struct Sound;
extern void func_02026124(struct Sound *obj, u32 idx);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_SceneWaitCursor(unsigned char *p);

#define WORK(p) (*(char **)((p) + 0x2C))

int BOX2_SEQ_HideSlotWindow(unsigned char *p, unsigned char i)
{
    p[0x18] = 1;
    p[0x16] = i;
    BOX2_SEQ_SetSlotDrawPriority(WORK(p), 0x24, 0);
    BOX2_SEQ_MoveCursorActor((char *)p, 0x24);
    BOX2_UI_DeleteSlotObjects((char *)p, 2, 1, 0);
    if ((*(Top * *)&((struct Obj00000 *)p)->f0)->x24 == 4) {
        BOX2_UI_HideWindowA(WORK(p));
        BOX2_UI_HideWindowB(WORK(p));
        func_02026124(*(void **)(WORK(p) + 0x70), 0x27);
    }
    return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_SceneWaitCursor, 0x20);
}
