/*
 * function: BOX2_SEQ_SelectPartySlotA
 * address:  0x021E9EC0
 * packet:   pkt_ov170_021E9EC0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetSlotDrawPriority 0x021EC768 thumb
 *   BOX2_SEQ_SwapSlotActors 0x021ECB84 thumb
 *   BOX2_SEQ_MoveCursorActor 0x021ED594 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   BOX2_SEQ_Create 0x021EA1C0 thumb
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_StateMachinePick 0x021DF484 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj23952.h"

extern void BOX2_SEQ_SetSlotDrawPriority(char *w, unsigned i, int flag);
extern void BOX2_SEQ_SwapSlotActors(char *w, unsigned i);
extern void BOX2_SEQ_MoveCursorActor(char *p, unsigned i);
extern void *POKEPARTY_GetMember(void *party, unsigned i);
extern void BOX2_SEQ_Create(void *p);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
extern void BOX2_SEQ_ShowWindowObject(char *w, int v);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_UI_ShowWindowB(char *w);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_StateMachinePick(unsigned char *p);

typedef struct {
    unsigned char lo : 4;
    unsigned char hi : 4;
} Nib;

#define WORK(p) (*(char **)((p) + 0x2C))

void BOX2_SEQ_SelectPartySlotA(unsigned char *p, unsigned char i)
{
    p[0x16] = i;
    ((Nib *)(p + 0x1C))->lo = 0;
    p[0x17] = p[0x14];
    p[0x1B] = 1;
    BOX2_SEQ_SetSlotDrawPriority(WORK(p), p[0x16], 0);
    BOX2_SEQ_SwapSlotActors(WORK(p), p[0x16]);
    BOX2_SEQ_MoveCursorActor((char *)p, 0x24);
    POKEPARTY_GetMember(((struct Obj23952 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f8, i - 0x1E);
    BOX2_SEQ_Create(p);
    BOX2_UI_DeleteSlotObjects((char *)p, 2, 2, 1);
    BOX2_SEQ_ShowWindowObject(WORK(p), 0x18);
    BOX2_MAIN_RefreshCursorBox((char *)p);
    BOX2_UI_ShowWindowB(WORK(p));
    ((struct Obj00000 *)p)->f28 = 0x20;
    p[0x1A] = 1;
    BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_StateMachinePick, 0x1E);
}
