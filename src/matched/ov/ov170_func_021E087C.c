/*
 * function: BOX2_MAIN_SceneOpenBox
 * address:  0x021E087C
 * packet:   pkt_ov170_021E087C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_IsInfoBarOpen 0x021EF770 thumb
 *   BOX2_MAIN_MoveCursorWithMon 0x021DE158 thumb
 *   BOX2_UI_SetMiniIconVisible 0x021EE008 thumb
 *   BOX2_UI_CloseInfoBar 0x021EF75C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_MAIN_IsWrappedDistance 0x021DD210 thumb
 *   BOX2_SEQ_LoadMonIcon 0x021EC35C thumb
 *   BOX2_MAIN_GetBoxWallpaper 0x021DEDCC thumb
 *   BOX2_MAIN_SetBoxScroll 0x021DEC98 thumb
 *   BOX2_SEQ_SetCursorFrame 0x021ED544 thumb
 *   BOX2_MAIN_StepScrollToPrevBox 0x021E00C4 thumb
 *   BOX2_MAIN_StepScrollToNextBox 0x021E0128 thumb
 *   BOX2_MAIN_WaitCursorMove 0x021DD930 thumb
 *   BOX2_MAIN_SetMoverEntry 0x021DE66C thumb
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb
 *   BOX2_MAIN_ShiftWindowLeft 0x021E01E0 thumb
 *   BOX2_UI_PutBottomBarClosed 0x021EF35C thumb
 *   BOX2_UI_CloseBar 0x021EF36C thumb
 *   BOX2_MAIN_IsWindowBusy 0x021E01B0 thumb
 *
 * Drop callback while carrying a Pokemon (block at work + 0x58, template
 * BOX2_MAIN_StateMachineScroll): changes box if the cursor sits on another box, then
 * settles the carried icon; returns 0 once the drop is finished.
 */

typedef struct {
    unsigned char pad[8];
    void *moves;
    unsigned short state;
    unsigned short timer;
} Blk;

struct WinMgr;
extern int BOX2_UI_IsInfoBarOpen(struct WinMgr *mgr);
extern int BOX2_MAIN_MoveCursorWithMon(unsigned char *p, unsigned a, unsigned b);
extern void BOX2_UI_SetMiniIconVisible(char *p, int a, int b);
extern void BOX2_UI_CloseInfoBar(struct WinMgr *mgr);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern int BOX2_MAIN_IsWrappedDistance(unsigned char *p, unsigned a, unsigned b);
extern void BOX2_SEQ_LoadMonIcon(char **p, int box);
extern int BOX2_MAIN_GetBoxWallpaper(char *p, int box);
extern void BOX2_MAIN_SetBoxScroll(char *p, void *a, int dir);
extern void BOX2_SEQ_SetCursorFrame(char *p, int b);
extern int BOX2_MAIN_StepScrollToPrevBox(char *p);
extern int BOX2_MAIN_StepScrollToNextBox(char *p);
extern int BOX2_MAIN_WaitCursorMove(unsigned char *p);
extern void BOX2_MAIN_SetMoverEntry(unsigned char *p, void *e);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern int BOX2_MAIN_ShiftWindowLeft(char *p);
extern void BOX2_UI_PutBottomBarClosed(struct WinMgr *mgr);
extern void BOX2_UI_CloseBar(struct WinMgr *mgr);
extern int BOX2_MAIN_IsWindowBusy(unsigned char *p);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define HELD(p) (*(unsigned char *)(WORK(p) + 0xA17E))

int BOX2_MAIN_SceneOpenBox(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    int r;

    switch (b->state) {
    case 0:
        if (p[0x16] >= 0x1E && BOX2_UI_IsInfoBarOpen(MGR(p)) == 1) {
            if (HELD(p) < 0x1E || HELD(p) == 0xFF || BOX2_MAIN_MoveCursorWithMon(p, p[0x16], HELD(p)) == 0) {
                BOX2_UI_SetMiniIconVisible((char *)p, 0, 0);
                BOX2_UI_CloseInfoBar(MGR(p));
                GFL_USE_PlaySeDefaultVolume(0x669);
                b->state = 5;
                break;
            }
        }
        if (p[0x16] < 0x1E && p[0x14] != p[0x17]) {
            if (HELD(p) == 0xFF || BOX2_MAIN_MoveCursorWithMon(p, p[0x16], HELD(p)) == 0) {
                r = BOX2_MAIN_IsWrappedDistance(p, p[0x14], p[0x17]);
                p[0x14] = p[0x17];
                BOX2_SEQ_LoadMonIcon((char **)p, p[0x14]);
                BOX2_MAIN_SetBoxScroll((char *)p, (void *)BOX2_MAIN_GetBoxWallpaper((char *)p, p[0x14]), r);
                if (r == 0)
                    b->state = 2;
                else
                    b->state = 3;
                break;
            }
        }
    case 1:
        BOX2_SEQ_SetCursorFrame((char *)p, 7);
        BOX2_MAIN_MoveCursorWithMon(p, p[0x16], HELD(p));
        b->state = 4;
        break;
    case 2:
        if (BOX2_MAIN_StepScrollToPrevBox((char *)p) == 0)
            b->state = 1;
        break;
    case 3:
        if (BOX2_MAIN_StepScrollToNextBox((char *)p) == 0)
            b->state = 1;
        break;
    case 4:
        if (BOX2_MAIN_WaitCursorMove(p) == 0) {
            BOX2_MAIN_SetMoverEntry(p, b->moves);
            BOX2_SEQ_SetCursorFrame((char *)p, 6);
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 0;
            return 0;
        }
        break;
    case 5:
        if (BOX2_MAIN_ShiftWindowLeft((char *)p) == 0) {
            BOX2_UI_PutBottomBarClosed(MGR(p));
            BOX2_UI_CloseBar(MGR(p));
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 6;
        }
        break;
    case 6:
        if (BOX2_MAIN_IsWindowBusy(p) == 0)
            b->state = 1;
        break;
    }
    return 1;
}
