/*
 * function: BOX2_SEQ_SelectSlotC
 * address:  0x021E9DF8
 * packet:   pkt_021E9DF8
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetSlotDrawPriority  0x021EC768  thumb  ov170
 *   BOX2_SEQ_SwapSlotActors  0x021ECB84  thumb  ov170
 *   BOX2_SEQ_MoveCursorActor  0x021ED594  thumb  ov170
 *   BOX2_UI_ToggleSlotPair  0x021ED888  thumb  ov170
 *   BOX2_SEQ_HideSlotsC61C  0x021EC61C  thumb  ov170
 *   BOX2_SEQ_SetSlotActors  0x021ECB20  thumb  ov170
 *   BOX2_SEQ_SetSlotActorMode  0x021ECB60  thumb  ov170
 *   BOX2_SEQ_Create  0x021EA1C0  thumb  ov170
 *   BOX2_UI_DeleteSlotObjects  0x021EE038  thumb  ov170
 *   BOX2_SEQ_ShowWindowObject  0x021EBA5C  thumb  ov170
 *   BOX2_MAIN_RefreshCursorBox  0x021DD14C  thumb  ov170
 *   BOX2_SEQ_SetSeqThird  0x021E8FC0  thumb  ov170
 *   BOX2_MAIN_StateMachinePen  0x021E0470  thumb  ov170
 */
#include "../include/Obj00000.h"
typedef unsigned char u8;
typedef unsigned int u32;

extern void BOX2_SEQ_SetSlotDrawPriority(char *p, unsigned i, int flag);
extern void BOX2_SEQ_SwapSlotActors(char *w, unsigned i);
extern void BOX2_SEQ_MoveCursorActor(char *p, unsigned i);
extern void BOX2_UI_ToggleSlotPair(char *p, int a);
extern void BOX2_SEQ_HideSlotsC61C(u8 *p);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_SEQ_SetSlotActorMode(char *p, int i, int f);
extern void BOX2_SEQ_Create(void *p);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
extern void BOX2_SEQ_ShowWindowObject(char *p, int i);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_StateMachinePen(unsigned char *p);

void BOX2_SEQ_SelectSlotC(u8 *p, u8 a)
{
    u8 old = ((struct Obj00000 *)p)->f14;
    ((struct Obj00000 *)p)->f16 = a;
    ((struct Obj00000 *)p)->f17 = old;
    BOX2_SEQ_SetSlotDrawPriority((char *)(*(u32 *)&((struct Obj00000 *)p)->f2C), ((struct Obj00000 *)p)->f16, 0);
    BOX2_SEQ_SwapSlotActors((char *)(*(u32 *)&((struct Obj00000 *)p)->f2C), ((struct Obj00000 *)p)->f16);
    BOX2_SEQ_MoveCursorActor((char *)p, 0x24);
    BOX2_UI_ToggleSlotPair((char *)(*(u32 *)&((struct Obj00000 *)p)->f2C), 0);
    BOX2_SEQ_HideSlotsC61C(p);
    BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
    BOX2_SEQ_SetSlotActors((char *)p, 2, 1);
    BOX2_SEQ_SetSlotActorMode((char *)(*(u32 *)&((struct Obj00000 *)p)->f2C), 0x24, 0);
    BOX2_SEQ_Create(p);
    BOX2_UI_DeleteSlotObjects((char *)p, 2, 2, 1);
    BOX2_SEQ_ShowWindowObject((char *)(*(u32 *)&((struct Obj00000 *)p)->f2C), 0x18);
    BOX2_MAIN_RefreshCursorBox((char *)p);
    ((struct Obj00000 *)p)->f1A = 2;
    BOX2_SEQ_SetSeqThird((char *)p, (int)((void (*)(void))BOX2_MAIN_StateMachinePen), 0x30);
}


