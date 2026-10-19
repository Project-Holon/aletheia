/*
 * function: BOX2_SEQ_StateCloseBoxB
 * address: 0x021E53B0
 * packet: pkt_ov170_021E53B0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb ov170
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb ov170
 *   BOX2_UI_OpenListPack 0x021EF57C thumb ov170
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb ov170
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb ov170
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_PrintPrompt 0x021EBC58 thumb ov170
 *   BOX2_MAIN_RefreshCurrentBoxMonInfo  0x021DEFEC  thumb
 *   BOX2_MAIN_ClearCursorBox  0x021DF0BC  thumb
 *   BOX2_MAIN_IsWindowBusy  0x021E01B0  thumb
 *   BOX2_SEQ_RefreshBoxUiAndWait  0x021EA83C  thumb
 *   BOX2_SEQ_SetActorAnim  0x021EA878  thumb
 *   BOX2_SEQ_PrintPromptB  0x021EBCB4  thumb
 *   BOX2_SEQ_IsActorAnimActive  0x021EBFEC  thumb
 *   BOX2_SEQ_SetActorDrawEnable  0x021EC000  thumb
 *   BOX2_SEQ_HidePartialSlots  0x021EC5A0  thumb
 *   BOX2_SEQ_SetSlotActors  0x021ECB20  thumb
 *   BOX2_SEQ_SetActorAffineMode  0x021ED108  thumb
 *   BOX2_SEQ_SetWindow9  0x021ED508  thumb
 *   BOX2_SEQ_SetSlotDim  0x021ED6E4  thumb
 *   BOX2_UI_ToggleSlotPair  0x021ED888  thumb
 *   BOX2_UI_MoveCursor  0x021EE364  thumb
 *   BOX2_UI_SetCursorPos  0x021EE3E4  thumb
 *   BOX2_UI_PutBottomBarOpen  0x021EF34C  thumb
 *   BOX2_UI_CloseBar  0x021EF36C  thumb
 *   BOX2_UI_OpenBar  0x021EF3A0  thumb
 *   BOX2_UI_IsTopBarClosed  0x021EF480  thumb
 *   BOX2_UI_ShowWindowA  0x021EF670  thumb
 *   BOX2_UI_ShowWindowB  0x021EF68C  thumb
 *   CURSOR_MOVE_SetCurrent  0x020260E4  thumb  arm9
 *   CURSOR_MOVE_SetState  0x020260F4  thumb  arm9
 */
#include "../include/Obj00000.h"
struct WinMgr;
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);
extern u8 func_020355C4(void);
extern unsigned POKEPARTY_GetCount(void *);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_MAIN_ClearCursorBox(unsigned char *);
extern void BOX2_MAIN_RefreshCurrentBoxMonInfo(char *p, int b);
extern void BOX2_SEQ_ShowWindowObject(char *, int);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern void BOX2_UI_SetCursorPos(char **, unsigned);
extern void BOX2_SEQ_SetCursorDraw(char **, int);
extern void BOX2_SEQ_SetWindow9(unsigned char *, int, int);
extern void BOX2_UI_ToggleSlotPair(char *, int);
extern void BOX2_UI_ShowWindowA(char *);
extern void BOX2_UI_ShowWindowB(char *);
extern int BOX2_UI_IsTopBarClosed(struct WinMgr *mgr);
extern void BOX2_UI_OpenBar(struct WinMgr *mgr);
extern void BOX2_UI_PutBottomBarOpen(struct WinMgr *mgr);
extern void BOX2_UI_CloseBar(struct WinMgr *mgr);
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern void BOX2_SEQ_SetActorDrawEnable(char *, int, int);
extern u32 BOX2_SEQ_IsActorAnimActive(char *p, int i);
extern void BOX2_SEQ_SetActorAffineMode(char *, int);
extern void BOX2_SEQ_SetActorAnim(unsigned char *, int);
extern void BOX2_SEQ_PrintPromptB(unsigned char *, int, int);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_SEQ_HidePartialSlots(char **p, int flag);
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
extern int BOX2_SEQ_RefreshBoxUiAndWait(char *p, int a);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowMoving(char *p);
extern int BOX2_MAIN_IsWindowBusy(unsigned char *);
extern void BOX2_SEQ_PrintPrompt(unsigned char *, int, int, int);
#define WORK(p) (*(char **)((p) + 0x2c))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xa194))
int BOX2_SEQ_StateCloseBoxB(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_ShowWindowObject(WORK(p), 0x18);
        BOX2_MAIN_RefreshCursorBox((char *)p);
        BOX2_UI_OpenListPack(MGR(p));
        STEP(p)++;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowMoving, 0x2e);
    case 1:
        if (POKEPARTY_GetCount(((void **)((struct Obj00000 *)p)->f0)[2]) != 6)
            return BOX2_SEQ_ReturnAfterClear((char *)p, 0x2f);
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_PrintPrompt(p, 0, 2, 0x18);
        ((struct Obj00000 *)p)->f28 = 0xe;
        return BOX2_SEQ_ReturnAfterClear((char *)p, 6);
    }
    return 0x2e;
}
