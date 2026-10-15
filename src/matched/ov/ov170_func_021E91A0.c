/*
 * function: BOX2_SEQ_StateUseItemMenu
 * address: 0x021E91A0
 * packet: pkt_ov170_021E91A0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb ov170
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb ov170
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb ov170
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb ov170
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb ov170
 *   BOX2_SEQ_SetActorAffineMode 0x021ED108 thumb ov170
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb ov170
 *   BOX2_SEQ_PrintPromptB 0x021EBCB4 thumb ov170
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb ov170
 *   func_02007E50 0x02007E50 thumb
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb ov170
 *   BOX2_SEQ_PrintWordsetB 0x021EBB34 thumb ov170
 *   BOX2_MAIN_SetBoxValueAt 0x021DD2B4 thumb ov170
 *   BOX2_MAIN_CanPlaceInBox 0x021DD718 thumb ov170
 *   BOX2_MAIN_RecalcPartyParam 0x021DD8A8 thumb ov170
 *   BOX2_SEQ_ShowSlotIcon 0x021EC48C thumb ov170
 *   BOX2_MAIN_SetBoxForm 0x021DEFF8 thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_PrintMessageD 0x021EBB58 thumb ov170
 *   func_020355C4 0x020355C4 arm
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23943.h"
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Struct_02025CD0;
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);
extern void BOX2_SEQ_PrintWordsetB(char *p, int a, int b);
extern void BOX2_MAIN_SetBoxValueAt(int a, int b, int c, int d, int e);
extern int BOX2_MAIN_CanPlaceInBox(void **pp, void *mon);
extern void BOX2_MAIN_RecalcPartyParam(void **pp, u32 idx);
extern void BOX2_SEQ_ShowSlotIcon(unsigned char *p, int box, int pos, int win);
extern void BOX2_MAIN_SetBoxForm(char *p, unsigned b);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void BOX2_SEQ_PrintMessageD(char *p, int b);
extern u8 func_020355C4(void);
extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
extern void BOX2_MAIN_ChangeBoxFormPreserve(char *p, int b);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern void BOX2_SEQ_ShowWindowObject(char *,int);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_UI_ShowWindowA(char *);
extern void BOX2_SEQ_SetActorAffineMode(char *,int);
extern void BOX2_SEQ_SetActorAnimSeq(char *,int,int);
extern void BOX2_SEQ_PrintPromptB(unsigned char *,int,int);
#define WORK(p) (*(char **)((p) + 0x2C))
int BOX2_SEQ_StateUseItemMenu(unsigned char *p)
{
    void *mon;
    if(func_020355C4()==1) CURSOR_MOVE_SetState(*(void **)(WORK(p)+0x70),0);
    else { CURSOR_MOVE_SetState(*(void **)(WORK(p)+0x70),1); BOX2_SEQ_SetCursorDraw((char **)p,0); }
    if(func_02007E50(((struct Obj23943 *)(*(char * *)&((struct Obj00000 *)p)->f0))->fC,*(unsigned short *)(WORK(p)+0xa16c),1,0x4c)==1) {
        mon=(void *)BOX2_MAIN_GetMonAt((void ***)p,p[0x14],p[0x16]);
        BOX2_MAIN_SetBoxValueAt((int)p,p[0x16],p[0x14],6,0);
        if(BOX2_MAIN_CanPlaceInBox((void **)p,mon)==1) {
            BOX2_MAIN_RecalcPartyParam((void **)p,p[0x16]);
            BOX2_SEQ_ShowSlotIcon(p,p[0x14],p[0x16],*(unsigned char *)(WORK(p)+p[0x16]+0x3dd2));
        }
        BOX2_MAIN_ChangeBoxFormPreserve((char *)p,p[0x16]); BOX2_SEQ_SetSlotDim((char **)p,0);
        BOX2_SEQ_ShowWindowObject(WORK(p),0x18); BOX2_MAIN_RefreshCursorBox((char *)p); BOX2_UI_ShowWindowA(WORK(p));
        BOX2_SEQ_SetActorAffineMode(WORK(p),1); BOX2_SEQ_SetActorAnimSeq(WORK(p),0xa,2);
        return 0x3b;
    }
    GFL_USE_PlaySeDefaultVolume(0x557); BOX2_SEQ_PrintPromptB(p,6,0x18);
    ((struct Obj00000 *)p)->f28=0xe;
    return BOX2_SEQ_ReturnAfterClear((char *)p,6);
}
