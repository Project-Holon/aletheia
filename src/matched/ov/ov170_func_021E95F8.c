/*
 * function: BOX2_SEQ_StatePmVoiceMenuB
 * address: 0x021E95F8
 * packet: pkt_ov170_021E95F8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb
 *   BOX2_SEQ_StopLeftBar 0x021EA75C thumb
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb
 *   BOX2_UI_MoveCursor 0x021EE364 thumb
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb
 *   BOX2_SEQ_RefreshCursorSlot 0x021ED588 thumb
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb
 *   BOX2_SEQ_DrawFrameList 0x021EB988 thumb
 *   data_021EFA10 0x021EFA10 data a1
 *   BOX2_UI_PutListFrames 0x021EF4E4 thumb
 *   BOX2_SEQ_PrintPrompt 0x021EBC58 thumb
 *   FILE_UTIL_Check136C 0x0202136C thumb
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb
 *   BOX2_MAIN_SetBoxValueAt 0x021DD2B4 thumb
 *   BOX2_MAIN_CanPlaceInBox 0x021DD718 thumb
 *   BOX2_MAIN_RecalcPartyParam 0x021DD8A8 thumb
 *   BOX2_SEQ_ShowSlotIcon 0x021EC48C thumb
 *   func_02007F1C 0x02007F1C thumb
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj23948.h"
struct WinMgr;
extern void BOX2_UI_ShowWindowA(char *);
extern void BOX2_SEQ_StopLeftBar(int p);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_UI_ToggleSlotPair(char *,int);
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
extern void BOX2_UI_ShowWindowB(char *);
extern void BOX2_SEQ_RefreshCursorSlot(char *p);
extern void BOX2_MAIN_ChangeBoxFormPreserve(char *p, int b);
extern void BOX2_SEQ_DrawFrameList(unsigned char *,const void *,unsigned);
extern const unsigned char data_021EFA10[];
extern void BOX2_UI_PutListFrames(struct WinMgr *mgr);
extern void BOX2_SEQ_PrintPrompt(unsigned char *,int,int,int);
extern unsigned FILE_UTIL_Check136C(unsigned short);
extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);
extern void BOX2_MAIN_SetBoxValueAt(int a, int b, int c, int d, int e);
extern int BOX2_MAIN_CanPlaceInBox(void **pp, void *mon);
extern void BOX2_MAIN_RecalcPartyParam(unsigned char *,unsigned);
extern void BOX2_SEQ_ShowSlotIcon(unsigned char *,int,int,int);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
#define WORK (*(char **)(p+0x2c))
#define ITEM (*(unsigned short *)(p+0x10))
int BOX2_SEQ_StatePmVoiceMenuB(unsigned char *p)
{
    int next;
    void *mon;
    switch(p[0x13]) {
    case 0: BOX2_UI_ShowWindowA(WORK); next=0x11; break;
    case 1:
        BOX2_SEQ_StopLeftBar((int)p); BOX2_SEQ_SetSlotActors((char *)p,1,1); BOX2_UI_ToggleSlotPair(WORK,0);
        BOX2_UI_MoveCursor((char **)p,5,0xb); BOX2_UI_ShowWindowB(WORK); next=0x1b; break;
    }
    BOX2_SEQ_RefreshCursorSlot((char *)p);
    if(ITEM==0) {
        BOX2_MAIN_ChangeBoxFormPreserve((char *)p,p[0x16]); BOX2_SEQ_DrawFrameList(p,data_021EFA10,6);
        BOX2_UI_PutListFrames(*(struct WinMgr **)(WORK+0x74)); BOX2_SEQ_PrintPrompt(p,p[0x16],1,0x18);
        return next;
    }
    if(FILE_UTIL_Check136C(ITEM)==0) {
        mon=(void *)BOX2_MAIN_GetMonAt((void ***)p,p[0x14],p[0x16]);
        BOX2_MAIN_SetBoxValueAt((int)p,p[0x16],p[0x14],6,ITEM);
        if(BOX2_MAIN_CanPlaceInBox((void **)p,mon)==1) {
            BOX2_MAIN_RecalcPartyParam(p,p[0x16]);
            BOX2_SEQ_ShowSlotIcon(p,p[0x14],p[0x16],*(unsigned char *)(WORK+p[0x16]+0x3dd2));
        }
        func_02007F1C(((struct Obj23948 *)(*(char * *)&((struct Obj00000 *)p)->f0))->fC,ITEM,1,0x804c);
    }
    BOX2_MAIN_ChangeBoxFormPreserve((char *)p,p[0x16]); BOX2_SEQ_SetCursorDraw((char **)p,0);
    return 0x54;
}
