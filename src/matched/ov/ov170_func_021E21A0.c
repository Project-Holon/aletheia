/*
 * function: BOX2_SEQ_DeleteBox2Ui
 * address: 0x021E21A0
 * packet: pkt_ov170_021E21A0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_RestartLeftBar 0x021EA784 thumb ov170
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb ov170
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb ov170
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb ov170
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb ov170
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   BOX2_UI_MoveCursor 0x021EE364 thumb ov170
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb ov170
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb ov170
 *   BOX2_SEQ_StateWaitPrint 0x021E22B8 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23887.h"
#include "../include/Obj23888.h"
typedef unsigned char u8;
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern void BOX2_SEQ_RestartLeftBar(int p);
extern void BOX2_UI_ToggleSlotPair(char *,int);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_MAIN_ChangeBoxFormPreserve(char *p, int b);
extern void BOX2_UI_ShowWindowA(char *);
typedef unsigned int   u32;
extern u32 POKEPARTY_GetCount(void *p);
extern void BOX2_UI_MoveCursor(char **,int,int);
extern void BOX2_UI_ShowWindowB(char *);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
extern int BOX2_SEQ_StateWaitPrint(int p);
#define W(p) (*(char **)((p)+0x2C))
#define NEXT(p) (*(int *)(W(p)+0xA198))
int BOX2_SEQ_DeleteBox2Ui(u8 *p)
{
    GFL_USE_PlaySeDefaultVolume(0x55C);
    switch(((struct Obj23887 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24) {
    case 0:
        BOX2_SEQ_RestartLeftBar((int)p);
        BOX2_UI_ToggleSlotPair(W(p),0);
        BOX2_SEQ_SetSlotActors((char *)p,1,1);
        BOX2_MAIN_ChangeBoxFormPreserve((char *)p,30);
        NEXT(p)=0x31;
        break;
    case 1:
        BOX2_MAIN_ChangeBoxFormPreserve((char *)p,0);
        NEXT(p)=0x2C;
        break;
    case 2:
        BOX2_MAIN_ChangeBoxFormPreserve((char *)p,0);
        BOX2_UI_ShowWindowA(W(p));
        NEXT(p)=0x11;
        break;
    case 3:
        BOX2_SEQ_SetSlotActors((char *)p,0x81,1);
        BOX2_MAIN_ChangeBoxFormPreserve((char *)p,0);
        BOX2_UI_ShowWindowA(W(p));
        NEXT(p)=0x39;
        break;
    case 4:
        if(POKEPARTY_GetCount(((struct Obj23888 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f8)==0) {
            BOX2_UI_ShowWindowA(W(p));
            BOX2_MAIN_ChangeBoxFormPreserve((char *)p,0);
            BOX2_UI_MoveCursor((char **)p,13,0);
            NEXT(p)=0x23;
        } else {
            BOX2_SEQ_RestartLeftBar((int)p);
            BOX2_UI_ToggleSlotPair(W(p),0);
            BOX2_SEQ_SetSlotActors((char *)p,1,1);
            BOX2_UI_ShowWindowB(W(p));
            BOX2_MAIN_ChangeBoxFormPreserve((char *)p,30);
            BOX2_UI_MoveCursor((char **)p,14,0);
            NEXT(p)=0x27;
        }
        break;
    case 5:
        BOX2_MAIN_ChangeBoxFormPreserve((char *)p,0);
        BOX2_SEQ_SetSlotActors((char *)p,0x81,1);
        BOX2_UI_DeleteSlotObjects((char *)p,0,1,1);
        NEXT(p)=0x4B;
        break;
    }
    return BOX2_SEQ_StateWaitPrint((int)p);
}
