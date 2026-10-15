/*
 * function: BOX2_SEQ_StateSummaryB
 * address:  0x021E3C88
 * packet:   pkt_ov170_021E3C88
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020260E0 0x020260E0 thumb
 *   BOX2_UI_IsTopBarClosed 0x021EF480 thumb
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb
 *   BOX2_UI_OpenListPack 0x021EF57C thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb
 *   BOX2_MAIN_IsWindowBusy 0x021E01B0 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_PrintYesNo 0x021EBD78 thumb
 *   BOX2_UI_SlideBarIn 0x021EF3D8 thumb
 *   BOX2_UI_PutBottomBarClosed 0x021EF35C thumb
 *   BOX2_UI_CloseBar 0x021EF36C thumb
 *   BOX2_SEQ_HidePartialSlots 0x021EC5A0 thumb
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb
 *   BOX2_UI_MoveCursor 0x021EE364 thumb
 *   BOX2_SEQ_SetCursorFrame 0x021ED544 thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   BOX2_UI_HideWindowA 0x021EF680 thumb
 *   BOX2_UI_HideWindowB 0x021EF69C thumb
 *   func_02026124 0x02026124 thumb
 *   BOX2_SEQ_SetWindow9 0x021ED508 thumb
 *   BOX2_SEQ_SwapSlotActors 0x021ECB84 thumb
 *   BOX2_SEQ_HideSlotWindow 0x021EA0BC thumb
 *
 * Three-step state machine on the work word at 0xA194: restore the cursor,
 * close the prompt, then redraw the box.  The dispatch and the step-1
 * increment read the work pointer through a local loaded once at the top; with
 * the macro on both, the 0xA194 offset is CSEd into the increment and takes r4.
 */
#include "../include/Obj14266.h"

struct WinMgr;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern int BOX2_UI_IsTopBarClosed(struct WinMgr *mgr);
extern void BOX2_MAIN_ChangeBoxFormPreserve(char *p, int b);
extern void BOX2_SEQ_ShowWindowObject(char *w, int v);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_UI_ShowWindowB(char *w);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowMoving(char *p);
extern int BOX2_MAIN_IsWindowBusy(unsigned char *p);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void BOX2_SEQ_PrintYesNo(char *p, int b);
extern void BOX2_UI_SlideBarIn(struct WinMgr *mgr);
extern void BOX2_UI_PutBottomBarClosed(struct WinMgr *mgr);
extern void BOX2_UI_CloseBar(struct WinMgr *mgr);
extern void BOX2_SEQ_HidePartialSlots(char **p, int flag);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_UI_ToggleSlotPair(char *w, int a);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
extern void BOX2_SEQ_SetCursorFrame(char *p, int b);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void BOX2_UI_HideWindowA(char *w);
extern void BOX2_UI_HideWindowB(char *w);
extern void func_02026124(struct Sound *obj, u32 idx);
extern void BOX2_SEQ_SetWindow9(unsigned char *p, int a, int b);
extern void BOX2_SEQ_SwapSlotActors(char *w, unsigned i);
extern int BOX2_SEQ_HideSlotWindow(unsigned char *p, unsigned char i);

typedef struct {
    unsigned char lo : 4;
    unsigned char hi : 4;
} Nib;

#define WORK(p) (*(char **)((p) + 0x2C))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define STATE(p) (*(int *)((p) + 0x28))
#define NIB(p) ((Nib *)((p) + 0x1C))
#define TOP(p) (*(char **)(p))

int BOX2_SEQ_StateSummaryB(unsigned char *p)
{
    char *w = WORK(p);
    switch (((struct Obj14266 *)w)->fA194) {
    case 0:
        if (NIB(p)->lo == 1) {
            p[0x17] = 0xFF;
            p[0x16] = func_020260E0(OBJ(p));
            if (BOX2_UI_IsTopBarClosed(MGR(p)) == 1) {
                if (p[0x16] >= 6)
                    p[0x16] = 0x1E;
                else
                    p[0x16] += 0x1E;
            } else if (p[0x16] >= 0x1E) {
                p[0x16] = 0;
            }
            BOX2_MAIN_ChangeBoxFormPreserve((char *)p, p[0x16]);
        } else {
            if (BOX2_UI_IsTopBarClosed(MGR(p)) == 1)
                p[0x17] = 0xFF;
            else
                p[0x17] = p[0x14];
            BOX2_SEQ_ShowWindowObject(WORK(p), 0x18);
            BOX2_MAIN_RefreshCursorBox((char *)p);
            BOX2_UI_ShowWindowB(WORK(p));
            BOX2_SEQ_SetSlotDim((char **)p, 0);
        }
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_UI_OpenListPack(MGR(p));
        STEP(p)++;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowMoving, 0x1F);
    case 1:
        if (*(int *)(TOP(p) + 0x24) == 4 && *(int *)(TOP(p) + 0x14) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x557);
            BOX2_SEQ_PrintYesNo((char *)p, 0);
            NIB(p)->lo = 0;
            STEP(p) = 0;
            STATE(p) = 0x2B;
            return 6;
        }
        (((struct Obj14266 *)w)->fA194)++;
        if (BOX2_UI_IsTopBarClosed(MGR(p)) == 1) {
            BOX2_UI_SlideBarIn(MGR(p));
        } else {
            BOX2_UI_PutBottomBarClosed(MGR(p));
            BOX2_UI_CloseBar(MGR(p));
            BOX2_SEQ_HidePartialSlots((char **)p, 0);
        }
        GFL_USE_PlaySeDefaultVolume(0x669);
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowBusy, 0x1F);
    case 2:
        BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
        BOX2_UI_ToggleSlotPair(WORK(p), 1);
        BOX2_UI_DeleteSlotObjects((char *)p, 0, 1, 0);
        BOX2_UI_MoveCursor((char **)p, 6, p[0x16]);
        BOX2_SEQ_SetCursorFrame((char *)p, 6);
        *(int *)(WORK(p) + 0xA168) = p[0x16];
        STEP(p) = 0;
        if (NIB(p)->lo == 1) {
            if (BOX2_MAIN_GetPartyValueAt((void ***)p, p[0x16], p[0x14], 0xA9, 0) == 0)
                BOX2_UI_DeleteSlotObjects((char *)p, 0, 1, 2);
            if (*(int *)(TOP(p) + 0x24) == 4) {
                BOX2_UI_HideWindowA(WORK(p));
                BOX2_UI_HideWindowB(WORK(p));
                func_02026124(OBJ(p), 0x27);
            }
            BOX2_SEQ_SetWindow9(p, 0xD, 1);
            return 0x20;
        }
        if (NIB(p)->lo == 2)
            BOX2_SEQ_SetWindow9(p, 0xD, 1);
        else
            BOX2_SEQ_SetWindow9(p, 0xE, 1);
        BOX2_SEQ_SwapSlotActors(WORK(p), p[0x16]);
        return BOX2_SEQ_HideSlotWindow(p, p[0x16]);
    }
    return 0x1F;
}
