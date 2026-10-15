/*
 * function: BOX2_SEQ_SetCursorMove
 * address:  0x021EA2DC
 * packet:   pkt_ov170_021EA2DC
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   BOX2_SEQ_SetActorAnim 0x021EA878 thumb
 *   BOX2_UI_CloseListPack 0x021EF534 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_SEQ_MoveActorToSlot 0x021ED164 thumb
 *   BOX2_SEQ_SetSlotCharacter 0x021ED094 thumb
 *   BOX2_SEQ_CreateHandSlotActorsB 0x021ED1C8 thumb
 *   func_020260E0 0x020260E0 thumb
 *   BOX2_UI_MoveCursorBetweenIcons 0x021EEF74 thumb
 *   func_020260E4 0x020260E4 thumb
 *   BOX2_SEQ_SetState 0x021E8FE0 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_Check0A40 0x021E0A40 thumb
 *   BOX2_MAIN_RefreshCursorBox  0x021DD14C  thumb
 *   BOX2_MAIN_StateMachineCoin  0x021E0ABC  thumb
 *   BOX2_SEQ_CreateB  0x021EA728  thumb
 *   BOX2_SEQ_ShowWindowObject  0x021EBA5C  thumb
 *   BOX2_SEQ_GetActorDrawEnable  0x021EC01C  thumb
 *   BOX2_SEQ_GetSlotPos  0x021EC548  thumb
 *   BOX2_SEQ_SetSlotDim  0x021ED6E4  thumb
 *   BOX2_UI_DeleteSlotObjects  0x021EE038  thumb
 *   BOX2_UI_ResetSlotFrames  0x021EF508  thumb
 */

typedef struct {
    unsigned char pad0[2];
    unsigned char pad2[0x26];
    unsigned short h28;
} Top;

typedef struct {
    Top *top;
    unsigned char pad4[0x13 - 4];
    unsigned char b13;
    unsigned char b14;
    unsigned char pad15;
    unsigned char b16;
    unsigned char b17;
    unsigned char pad18[3];
    unsigned char b1B;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char pad1D[0x24 - 0x1D];
    int x24;
    int x28;
    char *work;
} Obj;

struct WinMgr;
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void BOX2_SEQ_ShowWindowObject(char *w, int v);
typedef unsigned char  u8;
struct Sound;
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);
extern void BOX2_SEQ_MoveActorToSlot(char *w, int i, int v);
extern void BOX2_SEQ_SetSlotCharacter(char *w, unsigned item);
extern void BOX2_SEQ_CreateHandSlotActorsB(char *w);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
typedef unsigned int   u32;
extern u32 BOX2_SEQ_GetActorDrawEnable(char *p, int i);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern void BOX2_SEQ_GetSlotPos(unsigned i, short *x, short *y, int mode);
extern int BOX2_SEQ_SetState(char *p, int v);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern void BOX2_UI_ResetSlotFrames(struct WinMgr *mgr);
extern void BOX2_UI_CloseListPack(struct WinMgr *mgr);
extern void BOX2_SEQ_CreateB(void *p);
extern void BOX2_SEQ_SetActorAnim(Obj *p, int v);
extern void BOX2_MAIN_ChangeBoxFormPreserve(char *p, int b);
extern u8 func_020260E0(struct Sound *obj);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void BOX2_UI_MoveCursorBetweenIcons(char *w, int k, int v);
extern int BOX2_MAIN_StateMachineCoin(unsigned char *p);
extern int BOX2_MAIN_Check0A40(char *p);

#define OBJ(p) (*(void **)((p)->work + 0x70))
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))
#define CNT(p) (*(unsigned short *)((p)->work + 0xA16C))

int BOX2_SEQ_SetCursorMove(Obj *p, int i)
{
    p->b16 = i;
    p->b17 = p->b14;
    p->work[0xA172] = 1;
    BOX2_MAIN_ChangeBoxFormPreserve((char *)p, p->b16);
    CNT(p) = BOX2_MAIN_GetPartyValueAt((void ***)p, p->b16, p->b14, 6, 0);
    BOX2_SEQ_SetActorAnim(p, (short)CNT(p));
    BOX2_UI_CloseListPack(MGR(p));
    if (CNT(p) != 0) {
        BOX2_SEQ_SetActorDrawEnable(p->work, 10, 0);
        BOX2_SEQ_MoveActorToSlot(p->work, p->b16, 0);
        BOX2_SEQ_SetSlotCharacter(p->work, CNT(p));
        BOX2_SEQ_CreateHandSlotActorsB(p->work);
        BOX2_UI_MoveCursorBetweenIcons(p->work, 0x24, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), 0x24);
    } else {
        BOX2_UI_MoveCursorBetweenIcons(p->work, 0x25, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), 0x25);
    }
    return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_Check0A40, BOX2_SEQ_SetState((char *)p, 0x39));
}
