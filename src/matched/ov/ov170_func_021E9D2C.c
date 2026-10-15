/*
 * function: BOX2_SEQ_SelectSlotA
 * address:  0x021E9D2C
 * packet:   pkt_ov170_021E9D2C
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
 *   BOX2_SEQ_Create 0x021EA1C0 thumb
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_StateMachineScroll 0x021DFA30 thumb
 */


typedef struct {
    unsigned char pad[0x14];
    unsigned char b14;
    unsigned char pad15;
    unsigned char b16;
    unsigned char b17;
    unsigned char pad18[2];
    unsigned char b1A;
    unsigned char b1B;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char pad1D[0x28 - 0x1D];
    int next;
    char *work;
} Obj;

extern void BOX2_SEQ_SetSlotDrawPriority(char *p, unsigned i, int flag);
extern void BOX2_SEQ_SwapSlotActors(char *w, unsigned i);
extern void BOX2_SEQ_MoveCursorActor(char *p, unsigned i);
extern void BOX2_SEQ_Create(void *p);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
extern void BOX2_SEQ_ShowWindowObject(char *w, int v);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_UI_ShowWindowA(char *w);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_StateMachineScroll(unsigned char *p);

void BOX2_SEQ_SelectSlotA(Obj *p, unsigned char i)
{
    p->b1B = 0;
    p->lo = 0;
    p->b16 = i;
    p->b17 = p->b14;
    BOX2_SEQ_SetSlotDrawPriority(p->work, p->b16, 0);
    BOX2_SEQ_SwapSlotActors(p->work, p->b16);
    BOX2_SEQ_MoveCursorActor((char *)p, 0x24);
    BOX2_SEQ_Create(p);
    BOX2_UI_DeleteSlotObjects((char *)p, 2, 2, 1);
    BOX2_SEQ_ShowWindowObject(p->work, 0x18);
    BOX2_MAIN_RefreshCursorBox((char *)p);
    BOX2_UI_ShowWindowA(p->work);
    p->next = 0x15;
    p->b1A = 0;
    BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_StateMachineScroll, 0x12);
}
