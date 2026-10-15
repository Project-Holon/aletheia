/*
 * function: BOX2_SEQ_StateSummaryC
 * address:  0x021E594C
 * packet:   pkt_ov170_021E594C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_OpenListPack 0x021EF57C thumb
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb
 *   BOX2_SEQ_CheckTradableMon 0x021EA8CC thumb
 *   BOX2_SEQ_SwapSlotActors 0x021ECB84 thumb
 *   BOX2_SEQ_SetSlotDrawPriority 0x021EC768 thumb
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb
 *   BOX2_MAIN_SceneWaitCursor 0x021E0778 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb
 *   BOX2_SEQ_PrintMonName 0x021EBBC8 thumb
 *   BOX2_SEQ_PrintPrompt 0x021EBC58 thumb
 *   BOX2_UI_OpenBar 0x021EF3A0 thumb
 *   BOX2_MAIN_IsWindowBusy 0x021E01B0 thumb
 *   BOX2_UI_PlaceCursorAtIcon 0x021EE520 thumb
 *   BOX2_MAIN_SceneApplyScroll 0x021E066C thumb
 *   func_020307B0 0x020307B0 arm
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb
 *   BOX2_UI_MoveCursor 0x021EE364 thumb
 *
 * Five-step machine on the work word at 0xA194: fade out, confirm the
 * party slot (or back out to state 0x33), fade, swap, then reopen.
 */

struct WinMgr;
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern void BOX2_SEQ_ShowWindowObject(char *w, int v);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowMoving(char *p);
extern int BOX2_SEQ_CheckTradableMon(unsigned char *p);
extern void BOX2_SEQ_SwapSlotActors(char *w, unsigned i);
extern void BOX2_SEQ_SetSlotDrawPriority(char *p, unsigned i, int flag);
extern void BOX2_UI_SetCursorPos(char **p, unsigned idx);
extern int BOX2_MAIN_SceneWaitCursor(unsigned char *p);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern void BOX2_SEQ_PrintMonName(unsigned char *p, unsigned kind, int i);
extern void BOX2_SEQ_PrintPrompt(unsigned char *p, int sel, int kind, int i);
extern void BOX2_UI_OpenBar(struct WinMgr *mgr);
extern int BOX2_MAIN_IsWindowBusy(unsigned char *p);
extern void BOX2_UI_PlaceCursorAtIcon(char *p, unsigned idx);
extern int BOX2_MAIN_SceneApplyScroll(char *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void BOX2_UI_ToggleSlotPair(char *w, int a);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define STATE(p) (*(int *)((p) + 0x28))

int BOX2_SEQ_StateSummaryC(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        BOX2_UI_OpenListPack(MGR(p));
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_ShowWindowObject(WORK(p), 0x18);
        BOX2_MAIN_RefreshCursorBox((char *)p);
        STEP(p)++;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowMoving, 0x34);
    case 1:
        switch (BOX2_SEQ_CheckTradableMon(p)) {
        case 0:
            p[0x18] = 1;
            BOX2_SEQ_SwapSlotActors(WORK(p), p[0x16]);
            BOX2_SEQ_SetSlotDrawPriority(WORK(p), 0x24, 0);
            BOX2_SEQ_SetCursorDraw((char **)p, 1);
            BOX2_UI_SetCursorPos((char **)p, p[0x16] - 0x1E);
            STEP(p)++;
            return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_SceneWaitCursor, 0x34);
        case 1:
            GFL_USE_PlaySeDefaultVolume(0x557);
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            BOX2_SEQ_PrintMonName(p, 6, 0x18);
            STATE(p) = 0x33;
            STEP(p) = 0;
            return 6;
        case 2:
            GFL_USE_PlaySeDefaultVolume(0x557);
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            BOX2_SEQ_PrintPrompt(p, 0, 5, 0x18);
            STATE(p) = 0x33;
            STEP(p) = 0;
            return 6;
        }
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x669);
        BOX2_UI_OpenBar(MGR(p));
        STEP(p)++;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowBusy, 0x34);
    case 3:
        BOX2_UI_PlaceCursorAtIcon((char *)p, p[0x16] - 0x1E);
        STEP(p)++;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_SceneApplyScroll, 0x34);
    case 4:
        func_020307B0(*(void **)(WORK(p) + 0x60));
        BOX2_UI_ToggleSlotPair(WORK(p), 1);
        BOX2_SEQ_PrintPrompt(p, 0, 3, 0x1A);
        BOX2_UI_DeleteSlotObjects((char *)p, 0, 1, 1);
        BOX2_UI_MoveCursor((char **)p, 1, 0);
        STEP(p) = 0;
        return 0x35;
    }
    return 0x34;
}
