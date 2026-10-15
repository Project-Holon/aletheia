/*
 * function: BOX2_SEQ_StatePmVoiceOpenC
 * address:  0x021E99B0
 * packet:   pkt_ov170_021E99B0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_DrawFrameList 0x021EB988 thumb
 *   BOX2_UI_PutListFrames 0x021EF4E4 thumb
 *   BOX2_SEQ_PrintPrompt 0x021EBC58 thumb
 *   BOX2_SEQ_RefreshCursorSlot 0x021ED588 thumb
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb
 *   BOX2_UI_MoveCursor 0x021EE364 thumb
 *   BOX2_SEQ_StopLeftBar 0x021EA75C thumb
 *   BOX2_SEQ_HideSlotsC61C 0x021EC61C thumb
 *   BOX2_MAIN_RefreshBoxUi 0x021DD1E8 thumb
 *   BOX2_MAIN_ShiftWindowRight 0x021E01C4 thumb
 *   BOX2_UI_DeleteSlotIcon 0x021EDF5C thumb
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb
 *   BOX2_SEQ_SwapSlotActors 0x021ECB84 thumb
 *   BOX2_SEQ_ShowSlotIcon 0x021EC48C thumb
 *   BOX2_MAIN_SceneMoveCursor 0x021E072C thumb
 *   BOX2_SEQ_SetSlotDimB 0x021ED75C thumb
 *   BOX2_UI_SetMiniIconVisible 0x021EE008 thumb
 *   BOX2_SEQ_MoveCursorActor 0x021ED594 thumb
 *   BOX2_SEQ_StopRightBar 0x021EA770 thumb
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb
 *   d_021EFA10 0x021EFA10 data a1
 *
 * Leaves a box-menu mode (p[0x13]): restores the windows the mode changed
 * and returns the next menu state.
 */

struct WinMgr;
extern void BOX2_SEQ_DrawFrameList(unsigned char *p, const void *e, unsigned n);
extern void BOX2_UI_PutListFrames(struct WinMgr *mgr);
extern void BOX2_SEQ_PrintPrompt(unsigned char *p, int sel, int kind, int i);
extern void BOX2_SEQ_RefreshCursorSlot(char *p);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_UI_ToggleSlotPair(char *w, int a);
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
extern void BOX2_SEQ_StopLeftBar(int p);
extern void BOX2_SEQ_HideSlotsC61C(unsigned char *p);
extern void BOX2_MAIN_RefreshBoxUi(char *p);
extern int BOX2_MAIN_ShiftWindowRight(char *p);
extern void BOX2_UI_DeleteSlotIcon(unsigned char *p);
extern void BOX2_UI_ShowWindowA(char *w);
extern void BOX2_SEQ_SwapSlotActors(char *w, unsigned i);
extern void BOX2_SEQ_ShowSlotIcon(unsigned char *p, int box, int pos, int win);
extern void BOX2_MAIN_SceneMoveCursor(unsigned char *p);
extern void BOX2_SEQ_SetSlotDimB(char **p, int i);
extern void BOX2_UI_SetMiniIconVisible(char *p, int a, int b);
extern void BOX2_SEQ_MoveCursorActor(char *p, unsigned i);
extern void BOX2_SEQ_StopRightBar(int p);
extern void BOX2_UI_ShowWindowB(char *w);
extern const unsigned char d_021EFA10[];

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define HELD_WIN(p) (*(unsigned char *)(WORK(p) + 0x3DF6))

int BOX2_SEQ_StatePmVoiceOpenC(unsigned char *p)
{
    switch (p[0x13]) {
    case 0:
        BOX2_SEQ_DrawFrameList(p, d_021EFA10, 6);
        BOX2_UI_PutListFrames(MGR(p));
        BOX2_SEQ_PrintPrompt(p, p[0x16], 1, 0x18);
        BOX2_SEQ_RefreshCursorSlot((char *)p);
        return 0x11;
    case 1:
        BOX2_SEQ_DrawFrameList(p, d_021EFA10, 6);
        BOX2_UI_PutListFrames(MGR(p));
        BOX2_SEQ_PrintPrompt(p, p[0x16], 1, 0x18);
        BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
        BOX2_UI_ToggleSlotPair(WORK(p), 0);
        BOX2_UI_MoveCursor((char **)p, 5, 10);
        BOX2_SEQ_StopLeftBar((int)p);
        BOX2_SEQ_RefreshCursorSlot((char *)p);
        return 0x1B;
    case 2:
        if (p[0x1B] == 1)
            BOX2_SEQ_HideSlotsC61C(p);
        BOX2_UI_MoveCursor((char **)p, 4, p[0x16]);
        BOX2_MAIN_RefreshBoxUi((char *)p);
        while (BOX2_MAIN_ShiftWindowRight((char *)p) != 0)
            ;
        BOX2_UI_DeleteSlotIcon(p);
        BOX2_UI_ShowWindowA(WORK(p));
        p[0x16] = 0xFF;
        return 0x15;
    case 3:
        if (p[0x16] >= 0x1E) {
            BOX2_SEQ_HideSlotsC61C(p);
            BOX2_SEQ_SwapSlotActors(WORK(p), p[0x16]);
        } else if (p[0x14] == p[0x17]) {
            BOX2_SEQ_SwapSlotActors(WORK(p), p[0x16]);
        } else {
            BOX2_SEQ_ShowSlotIcon(p, p[0x17], p[0x16], HELD_WIN(p));
        }
        BOX2_MAIN_SceneMoveCursor(p);
        BOX2_SEQ_SetSlotDimB((char **)p, 0x24);
        BOX2_UI_MoveCursor((char **)p, 4, p[0x1D]);
        BOX2_MAIN_RefreshBoxUi((char *)p);
        while (BOX2_MAIN_ShiftWindowRight((char *)p) != 0)
            ;
        BOX2_UI_DeleteSlotIcon(p);
        BOX2_UI_ShowWindowA(WORK(p));
        if (p[0x1D] >= 0x22 && p[0x1D] <= 0x25)
            BOX2_UI_SetMiniIconVisible((char *)p, p[0x1D] - 0x22, 1);
        BOX2_SEQ_MoveCursorActor((char *)p, 0x24);
        return 0x15;
    case 4:
        BOX2_SEQ_StopRightBar((int)p);
        BOX2_UI_MoveCursor((char **)p, 6, p[0x16]);
        BOX2_UI_ShowWindowB(WORK(p));
        p[0x16] = 0xFF;
        return 0x20;
    case 5:
        BOX2_SEQ_StopRightBar((int)p);
        if (p[0x16] < 0x1E && p[0x14] != p[0x17])
            BOX2_SEQ_ShowSlotIcon(p, p[0x17], p[0x16], HELD_WIN(p));
        else
            BOX2_SEQ_SwapSlotActors(WORK(p), p[0x16]);
        BOX2_MAIN_SceneMoveCursor(p);
        BOX2_SEQ_SetSlotDimB((char **)p, 0x24);
        BOX2_UI_MoveCursor((char **)p, 6, p[0x1D]);
        BOX2_UI_ShowWindowB(WORK(p));
        BOX2_SEQ_MoveCursorActor((char *)p, 0x24);
        return 0x20;
    }
    return 0;
}
