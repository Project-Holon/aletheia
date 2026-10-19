/*
 * function: BOX2_SEQ_StateSummaryD
 * address:  0x021E644C
 * packet:   pkt_ov170_021E644C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb
 *   BOX2_UI_IsTopBarClosed 0x021EF480 thumb
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb
 *   BOX2_MAIN_RefreshCurrentBoxMonInfo 0x021DEFEC thumb
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb
 *   BOX2_UI_OpenListPack 0x021EF57C thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_StateMachineHideHandWindow 0x021E0ED4 thumb
 *   BOX2_UI_SlideBarIn 0x021EF3D8 thumb
 *   BOX2_UI_PutBottomBarClosed 0x021EF35C thumb
 *   BOX2_UI_CloseBar 0x021EF36C thumb
 *   BOX2_SEQ_HidePartialSlots 0x021EC5A0 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_MAIN_IsWindowBusy 0x021E01B0 thumb
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb
 *   BOX2_UI_MoveCursor 0x021EE364 thumb
 *   BOX2_SEQ_SetCursorFrame 0x021ED544 thumb
 *   CURSOR_MOVE_ClearSkipBit 0x02026124 thumb
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb
 *   BOX2_SEQ_SetWindow9 0x021ED508 thumb
 *   BOX2_SEQ_DrawGridSlotB 0x021EA458 thumb
 *
 * Three-step machine on the work word at 0xA194: close the held view,
 * fade, then reopen the menu for the current nibble mode.
 */

typedef struct {
    unsigned char lo : 4;
    unsigned char hi : 4;
} Nib;

struct WinMgr;
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern int BOX2_UI_IsTopBarClosed(struct WinMgr *mgr);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_MAIN_RefreshCurrentBoxMonInfo(char *p, int b);
extern void BOX2_SEQ_ShowWindowObject(char *w, int v);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_StateMachineHideHandWindow(unsigned char *p);
extern void BOX2_UI_SlideBarIn(struct WinMgr *mgr);
extern void BOX2_UI_PutBottomBarClosed(struct WinMgr *mgr);
extern void BOX2_UI_CloseBar(struct WinMgr *mgr);
extern void BOX2_SEQ_HidePartialSlots(char **p, int flag);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern int BOX2_MAIN_IsWindowBusy(unsigned char *p);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_UI_ToggleSlotPair(char *w, int a);
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
extern void BOX2_SEQ_SetCursorFrame(char *p, int b);
typedef unsigned int   u32;
struct Sound;
extern void CURSOR_MOVE_ClearSkipBit(struct Sound *obj, u32 idx);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
extern void BOX2_SEQ_SetWindow9(unsigned char *p, int a, int b);
extern int BOX2_SEQ_DrawGridSlotB(unsigned char *p, unsigned i);

#define WORK(p) (*(char **)((p) + 0x2C))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define NIB(p) ((Nib *)((p) + 0x1C))

int BOX2_SEQ_StateSummaryD(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        STEP(p)++;
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        if (BOX2_UI_IsTopBarClosed(MGR(p)) == 1)
            p[0x1E] = 1;
        else
            p[0x1E] = 0;
        if (NIB(p)->lo == 1) {
            p[0x17] = 0xFF;
            *(unsigned short *)(WORK(p) + 0xA16C) = 0;
            BOX2_MAIN_RefreshCursorBox((char *)p);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((char *)p, p[0x16]);
        } else {
            if (NIB(p)->lo == 2 && *(unsigned short *)(WORK(p) + 0xA16C) == 0) {
                p[0x17] = 0xFF;
                NIB(p)->lo = 1;
            }
            BOX2_SEQ_ShowWindowObject(WORK(p), 0x18);
            BOX2_MAIN_RefreshCursorBox((char *)p);
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            BOX2_UI_OpenListPack(MGR(p));
            return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_StateMachineHideHandWindow, 0x3F);
        }
    case 1:
        STEP(p)++;
        if (BOX2_UI_IsTopBarClosed(MGR(p)) == 1) {
            BOX2_UI_SlideBarIn(MGR(p));
        } else {
            BOX2_UI_PutBottomBarClosed(MGR(p));
            BOX2_UI_CloseBar(MGR(p));
            BOX2_SEQ_HidePartialSlots((char **)p, 0);
        }
        GFL_USE_PlaySeDefaultVolume(0x669);
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowBusy, 0x3F);
    case 2:
        STEP(p) = 0;
        BOX2_SEQ_SetSlotActors((char *)p, 0x81, 1);
        BOX2_SEQ_SetSlotActors((char *)p, 0x82, 1);
        BOX2_UI_ToggleSlotPair(WORK(p), 1);
        BOX2_UI_MoveCursor((char **)p, 6, p[0x16]);
        BOX2_SEQ_SetCursorFrame((char *)p, 6);
        CURSOR_MOVE_ClearSkipBit(OBJ(p), 0x27);
        CURSOR_MOVE_ClearSkipBit(OBJ(p), 0x28);
        if (NIB(p)->lo == 1) {
            BOX2_UI_DeleteSlotObjects((char *)p, 0, 1, 1);
            BOX2_SEQ_SetWindow9(p, 0xD, 1);
            return 0x40;
        }
        if (NIB(p)->lo == 2)
            BOX2_SEQ_SetWindow9(p, 0xD, 1);
        else
            BOX2_SEQ_SetWindow9(p, 0xE, 1);
        BOX2_UI_DeleteSlotObjects((char *)p, 2, 1, 1);
        return BOX2_SEQ_DrawGridSlotB(p, p[0x16]);
    }
    return 0x3F;
}
