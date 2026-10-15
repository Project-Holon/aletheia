/*
 * function: BOX2_SEQ_StateCloseItemMenu
 * address: 0x021E92A8
 * packet: pkt_ov170_021E92A8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing extent: two-byte zero alignment at 021E93F2.
 * symbols:
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb
 *   func_020355C4 0x020355C4 arm
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   BOX2_SEQ_SetWindow9 0x021ED508 thumb
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb
 *   BOX2_UI_IsTopBarClosed 0x021EF480 thumb
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj23944.h"
struct WinMgr;
extern void BOX2_SEQ_ShowWindowObject(char *,int);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Struct_02025CD0;
extern u8 func_020355C4(void);
extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);
extern void BOX2_SEQ_SetWindow9(unsigned char *,int,int);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_UI_ToggleSlotPair(char *,int);
extern int BOX2_UI_IsTopBarClosed(struct WinMgr *mgr);
extern void BOX2_UI_ShowWindowA(char *);
extern void BOX2_UI_ShowWindowB(char *);
#define WORK (*(char **)(p+0x2c))
int BOX2_SEQ_StateCloseItemMenu(unsigned char *p)
{
    BOX2_SEQ_ShowWindowObject(WORK,0x18);
    BOX2_MAIN_RefreshCursorBox((char *)p);
    if(func_020355C4()==1) CURSOR_MOVE_SetState(*(void **)(WORK+0x70),0);
    else CURSOR_MOVE_SetState(*(void **)(WORK+0x70),1);
    BOX2_SEQ_SetWindow9(p,0xe,1);
    switch(((struct Obj23944 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24) {
    case 0: BOX2_SEQ_SetSlotActors((char *)p,2,0); return 0x31;
    case 1: BOX2_UI_ToggleSlotPair(WORK,1); BOX2_SEQ_SetSlotActors((char *)p,1,0); return 0x2c;
    case 2:
        if(BOX2_UI_IsTopBarClosed(*(struct WinMgr **)(WORK+0x74))==1) {
            BOX2_SEQ_SetSlotActors((char *)p,2,0); BOX2_UI_ShowWindowB(WORK); return 0x1b;
        }
        BOX2_UI_ToggleSlotPair(WORK,1); BOX2_SEQ_SetSlotActors((char *)p,1,0); BOX2_UI_ShowWindowA(WORK); return 0x11;
    case 3:
        if(BOX2_UI_IsTopBarClosed(*(struct WinMgr **)(WORK+0x74))==1) {
            BOX2_SEQ_SetSlotActors((char *)p,0x82,0); BOX2_UI_ShowWindowB(WORK); return 0x46;
        }
        BOX2_UI_ToggleSlotPair(WORK,1); BOX2_SEQ_SetSlotActors((char *)p,0x81,0); BOX2_UI_ShowWindowA(WORK); return 0x39;
    case 4:
        if(BOX2_UI_IsTopBarClosed(*(struct WinMgr **)(WORK+0x74))==1) {
            BOX2_SEQ_SetSlotActors((char *)p,2,0); BOX2_UI_ShowWindowB(WORK); return 0x27;
        }
        BOX2_UI_ToggleSlotPair(WORK,1); BOX2_SEQ_SetSlotActors((char *)p,1,0); BOX2_UI_ShowWindowA(WORK); return 0x23;
    case 5: BOX2_UI_ToggleSlotPair(WORK,1); BOX2_SEQ_SetSlotActors((char *)p,0x81,1); return 0x4b;
    }
    return 0x11;
}
