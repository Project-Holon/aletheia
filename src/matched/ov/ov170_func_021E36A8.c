/*
 * function: BOX2_SEQ_StateSwapFinish
 * address: 0x021E36A8
 * packet: pkt_ov170_021E36A8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_MAIN_ClearCursorBox 0x021DF0BC thumb ov170
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb ov170
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb ov170
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb ov170
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 *   BOX2_UI_PutBottomBarOpen 0x021EF34C thumb ov170
 *   BOX2_UI_CloseBar 0x021EF36C thumb ov170
 *   BOX2_SEQ_HidePartialSlots 0x021EC5A0 thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb ov170
 *   BOX2_MAIN_IsWindowBusy 0x021E01B0 thumb ov170
 *   BOX2_MAIN_RefreshCurrentBoxMonInfo 0x021DEFEC thumb ov170
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb ov170
 *   BOX2_UI_MoveCursor 0x021EE364 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23895.h"
#include "../include/Obj23896.h"
struct WinMgr;
extern void BOX2_MAIN_ClearCursorBox(unsigned char *);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_UI_ToggleSlotPair(char *, int);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_SEQ_SetCursorDraw(char **, int);
extern void BOX2_UI_PutBottomBarOpen(struct WinMgr *mgr);
extern void BOX2_UI_CloseBar(struct WinMgr *mgr);
extern void BOX2_SEQ_HidePartialSlots(char **, int);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowBusy(unsigned char *);
extern void BOX2_MAIN_RefreshCurrentBoxMonInfo(char *p, int b);
extern void BOX2_UI_ShowWindowB(char *);
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
#define W(p) (*(char **)((p) + 0x2C))
int BOX2_SEQ_StateSwapFinish(unsigned char *p)
{
    switch (*(int *)(W(p) + 0xA194)) {
    case 0:
        BOX2_MAIN_ClearCursorBox(p);
        BOX2_MAIN_RefreshCursorBox((char *)p);
        BOX2_UI_ToggleSlotPair(W(p), 0);
        BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_UI_PutBottomBarOpen(*(struct WinMgr **)(W(p) + 0x74));
        BOX2_UI_CloseBar(*(struct WinMgr **)(W(p) + 0x74));
        BOX2_SEQ_HidePartialSlots((char **)p, 0);
        if (((struct Obj23895 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 3)
            BOX2_SEQ_SetSlotActors((char *)p, 0x82, 1);
        GFL_USE_PlaySeDefaultVolume(0x669);
        (*(int *)(W(p) + 0xA194))++;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowBusy, 0x1A);
    case 1:
        *(int *)(W(p) + 0xA194) = 0;
        BOX2_MAIN_RefreshCurrentBoxMonInfo((char *)p, 0x1E);
        BOX2_UI_ShowWindowB(W(p));
        if (((struct Obj23896 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 3) {
            BOX2_UI_MoveCursor((char **)p, 8, 0);
            return 0x46;
        } else {
            BOX2_UI_MoveCursor((char **)p, 5, 0);
            return 0x1B;
        }
    }
    return 0x1A;
}
