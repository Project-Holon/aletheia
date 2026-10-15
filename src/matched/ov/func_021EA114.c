/*
 * function: BOX2_SEQ_SelectBoxSlot
 * address:  0x021EA114
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetSlotDrawPriority  0x021EC768  thumb  ov170
 *   BOX2_SEQ_MoveCursorActor  0x021ED594  thumb  ov170
 *   BOX2_UI_DeleteSlotObjects  0x021EE038  thumb  ov170
 *   BOX2_SEQ_SetSeqThird  0x021E8FC0  thumb  ov170
 *
 * Arm the flag, store the state byte, zero the 0x24 queue entry,
 *   re-stage it, publish (2,1,0) and set selector 0x021E0779.
 */
#include "../include/Obj00000.h"


extern void BOX2_SEQ_SetSlotDrawPriority(char *p, unsigned i, int flag);
extern void BOX2_SEQ_MoveCursorActor(char *p, unsigned i);
extern void BOX2_UI_DeleteSlotObjects(char *, int, int, int);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
int BOX2_SEQ_SelectBoxSlot(char *p, int a)
{
    ((struct Obj00000 *)p)->f18 = 1;
    ((struct Obj00000 *)p)->f16 = a;
    BOX2_SEQ_SetSlotDrawPriority((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 0x24, 0);
    BOX2_SEQ_MoveCursorActor(p, 0x24);
    BOX2_UI_DeleteSlotObjects(p, 2, 1, 0);
    return BOX2_SEQ_SetSeqThird(p, 0x021E0779, 0x15);
}
