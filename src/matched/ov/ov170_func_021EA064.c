/*
 * function: BOX2_SEQ_SelectSlotD
 * address:  0x021EA064
 * packet:   pkt_ov170_021EA064
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SwapSlotActors 0x021ECB84 thumb
 *   BOX2_SEQ_SetSlotDrawPriority 0x021EC768 thumb
 *   BOX2_SEQ_MoveCursorActor 0x021ED594 thumb
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb
 *   BOX2_SEQ_Create 0x021EA1C0 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_StateMachineScroll 0x021DFA30 thumb
 */
#include "../include/Obj00000.h"


extern void BOX2_SEQ_SwapSlotActors(char *w, unsigned i);
extern void BOX2_SEQ_SetSlotDrawPriority(char *p, unsigned i, int flag);
extern void BOX2_SEQ_MoveCursorActor(char *p, unsigned i);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
extern void BOX2_SEQ_Create(void *p);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_StateMachineScroll(unsigned char *p);

#define WORK(p) (*(char **)((p) + 0x2C))

int BOX2_SEQ_SelectSlotD(unsigned char *p, int i, int v)
{
    p[0x17] = p[0x14];
    p[0x16] = i;
    *(int *)(WORK(p) + 0xA168) = i;
    BOX2_SEQ_SwapSlotActors(WORK(p), p[0x16]);
    BOX2_SEQ_SetSlotDrawPriority(WORK(p), 0x24, 0);
    BOX2_SEQ_MoveCursorActor((char *)p, 0x24);
    BOX2_UI_DeleteSlotObjects((char *)p, 2, 1, 2);
    BOX2_SEQ_Create(p);
    ((struct Obj00000 *)p)->f28 = v;
    p[0x1A] = 2;
    return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_StateMachineScroll, 0x17);
}
