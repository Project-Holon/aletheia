/*
 * function: BOX2_MAIN_StateMachinePick
 * address:  0x021DF484
 * packet:   pkt_ov170_021DF484
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_020260E4 0x020260E4 thumb
 *   BGWINFRM_IsMoving 0x0202CE40 thumb
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   BOX2_MAIN_IsTaskMenuFinished 0x021DCFC0 thumb
 *   BOX2_MAIN_UpdateWindowFrame 0x021DD090 thumb
 *   BOX2_MAIN_StopSeq 0x021DD16C thumb
 *   BOX2_MAIN_SelectBox 0x021DD1C4 thumb
 *   BOX2_MAIN_RefreshBoxUi 0x021DD1E8 thumb
 *   BOX2_MAIN_IsWrappedDistance 0x021DD210 thumb
 *   BOX2_MAIN_WaitCursorMove 0x021DD930 thumb
 *   BOX2_MAIN_MoveCursorWithMon 0x021DE158 thumb
 *   BOX2_MAIN_FindMoverSlot 0x021DE5C8 thumb
 *   BOX2_MAIN_SetMoverEntry 0x021DE66C thumb
 *   BOX2_MAIN_SetBoxScroll 0x021DEC98 thumb
 *   BOX2_MAIN_GetBoxFormId 0x021DEDCC thumb
 *   BOX2_MAIN_HitBoxGrid 0x021DF1DC thumb
 *   BOX2_MAIN_HitPartySlots 0x021DF228 thumb
 *   BOX2_MAIN_HitPartyGrid 0x021DF254 thumb
 *   BOX2_MAIN_MoveCursorActor 0x021DF43C thumb
 *   BOX2_MAIN_IsSeqIdle 0x021E00C4 thumb
 *   BOX2_MAIN_IsSeqStep 0x021E0128 thumb
 *   BOX2_MAIN_ShiftWindowRight 0x021E01C4 thumb
 *   BOX2_MAIN_ShiftWindowLeft 0x021E01E0 thumb
 *   BOX2_SEQ_OpenBoxUp 0x021E19D4 thumb
 *   BOX2_SEQ_OpenBoxDown 0x021E1A28 thumb
 *   BOX2_SEQ_LoadMonIcon 0x021EC35C thumb
 *   BOX2_SEQ_HidePartialSlots 0x021EC5A0 thumb
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb
 *   BOX2_SEQ_MoveCursorToSlot 0x021ED7C4 thumb
 *   BOX2_UI_SetMiniIconVisible 0x021EE008 thumb
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb
 *   BOX2_UI_MoveCursor 0x021EE364 thumb
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb
 *   BOX2_UI_GetPartySlotPoint 0x021EF180 thumb
 *   BOX2_UI_GetCloseButtonHit 0x021EF1B4 thumb
 *   BOX2_UI_GetExitButtonHit 0x021EF1C4 thumb
 *   BOX2_UI_GetGridSlotPoint 0x021EF224 thumb
 *   BOX2_UI_GetPageButtonHit2 0x021EF264 thumb
 *   BOX2_UI_PutBottomBarClosed 0x021EF35C thumb
 *   BOX2_UI_CloseBar 0x021EF36C thumb
 *   BOX2_UI_OpenBar 0x021EF3A0 thumb
 *   BOX2_UI_UpdateBarMove 0x021EF400 thumb
 *   BOX2_UI_IsTopBarOpen 0x021EF45C thumb
 *   BOX2_UI_CloseListPack 0x021EF534 thumb
 *   BOX2_UI_OpenListPack 0x021EF57C thumb
 *   BOX2_UI_UpdateListPacks 0x021EF5C4 thumb
 *   BOX2_UI_IsListClosed 0x021EF60C thumb
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb
 *   BOX2_UI_HideWindowA 0x021EF680 thumb
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb
 *   BOX2_UI_HideWindowB 0x021EF69C thumb
 *   BOX2_UI_CloseInfoBar 0x021EF75C thumb
 *   BOX2_UI_IsInfoBarOpen 0x021EF770 thumb
 *   BOX2_UI_GetPageButtonHit 0x021EF248 thumb
 *   BOX2_UI_SlideBarIn 0x021EF3D8 thumb
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb
 *   func_02026124 0x02026124 thumb
 *   BOX2_UI_IsTopBarClosed 0x021EF480 thumb
 *   d_021EF7B4 0x021EF7B4 data a1
 *   d_021EF79C 0x021EF79C data a1
 */

typedef struct {
    unsigned char pad[8];
    void *moves;
    unsigned short state;
    unsigned short timer;
} Blk;

typedef unsigned int u32;
struct WinMgr;
extern u32 BGWINFRM_IsMoving(struct WinMgr *mgr, u32 idx);
typedef unsigned char  u8;
struct Sound;
extern int BOX2_MAIN_ShiftWindowRight(char *p);
extern int BOX2_UI_UpdateListPacks(struct WinMgr *mgr);
extern int TOUCHPANEL_GetCont(void);
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern unsigned TOUCHPANEL_GetPointCont(unsigned *outA, unsigned *outB);
extern int BOX2_UI_IsInfoBarOpen(struct WinMgr *mgr);
extern int BOX2_MAIN_HitPartyGrid(unsigned char *p, short x, short y);
extern int BOX2_MAIN_MoveCursorWithMon(unsigned char *p, unsigned a, unsigned b);
extern void BOX2_UI_CloseInfoBar(struct WinMgr *mgr);
extern void BOX2_UI_SetMiniIconVisible(char *p, int a, int b);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern int BOX2_UI_IsTopBarOpen(struct WinMgr *mgr);
extern int BOX2_MAIN_HitPartySlots(short x, short y, const unsigned char *r);
extern const unsigned char d_021EF79C[];
extern const unsigned char d_021EF7B4[];
extern int BOX2_UI_GetPageButtonHit(void);
extern void BOX2_UI_SlideBarIn(struct WinMgr *mgr);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_UI_ToggleSlotPair(char *q, int a);
extern void func_02026124(struct Sound *obj, u32 idx);
extern int BOX2_UI_IsTopBarClosed(struct WinMgr *mgr);
extern int BOX2_MAIN_HitBoxGrid(short x, int y);
extern int BOX2_UI_IsListClosed(struct WinMgr *mgr);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern int BOX2_MAIN_FindMoverSlot(char *p, unsigned id);
extern void BOX2_UI_CloseListPack(struct WinMgr *mgr);
extern int BOX2_MAIN_IsWrappedDistance(unsigned char *p, unsigned a, unsigned b);
extern void BOX2_SEQ_LoadMonIcon(char **p, int box);
extern int BOX2_MAIN_GetBoxFormId(char *p, int box);
extern void BOX2_MAIN_SetBoxScroll(char *p, void *a, int dir);
extern int BOX2_UI_GetPartySlotPoint(int a, int b);
extern void BOX2_MAIN_RefreshBoxUi(char *p);
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
extern int BOX2_UI_GetCloseButtonHit(void);
extern void BOX2_MAIN_StopSeq(unsigned char *p, int dir);
extern int BOX2_UI_GetPageButtonHit2(void);
extern void BOX2_MAIN_UpdateWindowFrame(unsigned char *p, unsigned idx);
extern void BOX2_UI_OpenBar(struct WinMgr *mgr);
extern int BOX2_UI_GetExitButtonHit(void);
extern void BOX2_MAIN_SelectBox(char *p, int a);
extern int BOX2_UI_GetGridSlotPoint(int a, int b);
extern void BOX2_MAIN_MoveCursorActor(char *p, int x, int y);
extern int BOX2_MAIN_IsSeqIdle(char *p);
extern int BOX2_MAIN_IsSeqStep(char *p);
extern int BOX2_MAIN_WaitCursorMove(unsigned char *p);
extern int BOX2_SEQ_OpenBoxDown(char *p);
extern int BOX2_SEQ_OpenBoxUp(char *p);
extern int BOX2_MAIN_IsTaskMenuFinished(char *p);
extern int BOX2_MAIN_ShiftWindowLeft(char *p);
extern void BOX2_UI_PutBottomBarClosed(struct WinMgr *mgr);
extern void BOX2_UI_CloseBar(struct WinMgr *mgr);
extern void BOX2_SEQ_HidePartialSlots(char **p, int flag);
extern void BOX2_UI_HideWindowA(char *p);
extern void BOX2_UI_ShowWindowB(char *p);
extern int BOX2_UI_UpdateBarMove(unsigned char *p);
extern void BOX2_UI_HideWindowB(char *p);
extern void BOX2_UI_ShowWindowA(char *p);
extern void BOX2_MAIN_SetMoverEntry(unsigned char *p, void *e);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void BOX2_UI_SetCursorPos(char **p, unsigned idx);
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern void BOX2_SEQ_MoveCursorToSlot(char *p, int i);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))

int BOX2_MAIN_StateMachinePick(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    int busy = BOX2_UI_UpdateBarMove(p);
    unsigned r = BOX2_UI_UpdateListPacks(MGR(p));
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        if (TOUCHPANEL_GetCont() == 1)
            BOX2_UI_OpenListPack(MGR(p));
        b->state = 1;
        break;
    case 1:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            *(unsigned char *)(WORK(p) + 0xA171) = 0;
            b->timer = 0;
            r = 0xFF;
            if (BOX2_UI_IsInfoBarOpen(MGR(p)) == 1) {
                BOX2_UI_SetMiniIconVisible((char *)p, 0, 0);
                r = BOX2_MAIN_HitPartyGrid(p, *(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184));
                if (r == 0xFF || BOX2_MAIN_MoveCursorWithMon(p, p[0x16], r) == 0) {
                    BOX2_UI_CloseInfoBar(MGR(p));
                    GFL_USE_PlaySeDefaultVolume(0x669);
                    b->state = 0xE;
                    break;
                }
            }
            if (BOX2_UI_IsTopBarOpen(MGR(p)) == 1) {
                r = BOX2_MAIN_HitPartySlots(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF79C);
                if (r == 0xFF)
                    r = BOX2_MAIN_HitBoxGrid(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184)));
            }
            if (BOX2_UI_IsTopBarClosed(MGR(p)) == 1)
                r = BOX2_MAIN_HitPartySlots(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF7B4);
            if ((*(int **)p)[9] == 4 && (*(int **)p)[5] == 1) {
                r = 0xFF;
                *(unsigned char *)(WORK(p) + 0xA173) = 5;
            }
            BOX2_MAIN_MoveCursorWithMon(p, p[0x16], r);
            if (BOX2_UI_IsListClosed(MGR(p)) == 0)
                BOX2_SEQ_SetSlotDim((char **)p, 0);
            if (r != 0xFF)
                p[0x16] = BOX2_MAIN_FindMoverSlot((char *)p, 0x24);
            if (BOX2_UI_IsTopBarOpen(MGR(p)) == 0 && BOX2_UI_IsInfoBarOpen(MGR(p)) == 0 && busy == 0)
                BOX2_UI_CloseListPack(MGR(p));
            b->state = 2;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (busy == 0 && r == 0) {
            if (BOX2_UI_IsTopBarOpen(MGR(p)) == 0 && BOX2_UI_IsInfoBarOpen(MGR(p)) == 0 && BOX2_UI_GetPageButtonHit() == 0) {
                p[0x17] = 0xFF;
                p[0x1A] = 2;
                BOX2_UI_SlideBarIn(MGR(p));
                GFL_USE_PlaySeDefaultVolume(0x669);
                BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
                BOX2_UI_ToggleSlotPair(WORK(p), 1);
                BOX2_UI_MoveCursor((char **)p, 6, p[0x16]);
                if ((*(int **)p)[9] == 4)
                    func_02026124(*(void **)(WORK(p) + 0x70), 0x27);
                BOX2_UI_DeleteSlotObjects((char *)p, 2, 1, 2);
                *(int *)(WORK(p) + 0xA168) = p[0x16];
                *(int *)(WORK(p) + 0x68) = 0x17;
            }
            if (b->timer == 0) {
                int dir = BOX2_UI_GetCloseButtonHit();
                if (dir == 0) {
                    GFL_USE_PlaySeDefaultVolume(0x548);
                    BOX2_MAIN_StopSeq(p, 0);
                    b->state = 6;
                } else if (dir == 1) {
                    GFL_USE_PlaySeDefaultVolume(0x548);
                    BOX2_MAIN_StopSeq(p, 1);
                    b->state = 7;
                }
            }
            if ((*(int **)p)[9] != 4) {
                if (BOX2_UI_GetPageButtonHit2() != -1) {
                    if (*(unsigned char *)(WORK(p) + 0xA171) == 0) {
                        if (BOX2_UI_IsInfoBarOpen(MGR(p)) == 1) {
                            BOX2_UI_CloseInfoBar(MGR(p));
                            BOX2_MAIN_UpdateWindowFrame(p, 0xA);
                            GFL_USE_PlaySeDefaultVolume(0x54C);
                            GFL_USE_PlaySeDefaultVolume(0x669);
                            *(unsigned char *)(WORK(p) + 0xA171) = 1;
                            b->state = 0xB;
                        }
                        if (BOX2_UI_IsTopBarOpen(MGR(p)) == 1) {
                            BOX2_UI_OpenBar(MGR(p));
                            BOX2_MAIN_UpdateWindowFrame(p, 0xB);
                            GFL_USE_PlaySeDefaultVolume(0x54C);
                            GFL_USE_PlaySeDefaultVolume(0x669);
                            *(unsigned char *)(WORK(p) + 0xA171) = 1;
                            b->state = 0xD;
                        }
                    }
                } else {
                    *(unsigned char *)(WORK(p) + 0xA171) = 0;
                }
            }
            if (BOX2_UI_IsInfoBarOpen(MGR(p)) == 1) {
                int dir = BOX2_UI_GetExitButtonHit();
                if (dir == 0) {
                    GFL_USE_PlaySeDefaultVolume(0x548);
                    BOX2_MAIN_SelectBox((char *)p, -1);
                    b->state = 8;
                    b->timer = 0;
                } else if (dir == 1) {
                    GFL_USE_PlaySeDefaultVolume(0x548);
                    BOX2_MAIN_SelectBox((char *)p, 1);
                    b->state = 9;
                    b->timer = 0;
                }
            }
            if (BOX2_UI_IsInfoBarOpen(MGR(p)) == 1) {
                int k = BOX2_UI_GetGridSlotPoint(x, y);
                if (k != 0xFF)
                    BOX2_UI_SetMiniIconVisible((char *)p, k - 0x24, 1);
                else
                    BOX2_UI_SetMiniIconVisible((char *)p, 0, 0);
            }
        }
        BOX2_MAIN_MoveCursorActor((char *)p, x, y);
        break;
    case 2:
        if (BOX2_MAIN_WaitCursorMove(p) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 3;
        }
        break;
    case 3:
        if (busy == 0 && r == 0)
            b->state = 0x10;
        break;
    case 6:
        if (BOX2_MAIN_IsSeqIdle((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((char *)p, x, y);
        break;
    case 7:
        if (BOX2_MAIN_IsSeqStep((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((char *)p, x, y);
        break;
    case 8:
        if (BOX2_SEQ_OpenBoxDown((char *)p) == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((char *)p, x, y);
        break;
    case 9:
        if (BOX2_SEQ_OpenBoxUp((char *)p) == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((char *)p, x, y);
        break;
    case 10:
        if (BOX2_MAIN_ShiftWindowRight((char *)p) == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((char *)p, x, y);
        break;
    case 11:
        BOX2_MAIN_IsTaskMenuFinished((char *)p);
        if (BOX2_MAIN_ShiftWindowLeft((char *)p) == 0) {
            BOX2_UI_PutBottomBarClosed(MGR(p));
            BOX2_UI_CloseBar(MGR(p));
            BOX2_SEQ_HidePartialSlots((char **)p, 1);
            BOX2_UI_HideWindowA(WORK(p));
            BOX2_UI_ShowWindowB(WORK(p));
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 0xC;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((char *)p, x, y);
        break;
    case 12:
        if (busy == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((char *)p, x, y);
        break;
    case 13:
        BOX2_MAIN_IsTaskMenuFinished((char *)p);
        if (busy == 0) {
            BOX2_MAIN_RefreshBoxUi((char *)p);
            BOX2_UI_HideWindowB(WORK(p));
            BOX2_UI_ShowWindowA(WORK(p));
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 0xA;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((char *)p, x, y);
        break;
    case 16:
        BOX2_MAIN_SetMoverEntry(p, b->moves);
        if (BOX2_UI_IsTopBarClosed(MGR(p)) == 1) {
            BOX2_SEQ_MoveCursorToSlot(WORK(p), p[0x16]);
            BOX2_SEQ_SetSlotDim((char **)p, 1);
        } else {
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            func_020260E4(*(void **)(WORK(p) + 0x70), p[0x16]);
            BOX2_UI_SetCursorPos((char **)p, p[0x16]);
            BOX2_SEQ_SetCursorDraw((char **)p, 1);
        }
        b->state = 0;
        return 0;
    case 14:
        if (BOX2_MAIN_ShiftWindowLeft((char *)p) == 0) {
            BOX2_UI_PutBottomBarClosed(MGR(p));
            BOX2_UI_CloseBar(MGR(p));
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 0xF;
        }
        break;
    case 15:
        if (busy == 0) {
            p[0x1A] = 2;
            BOX2_MAIN_MoveCursorWithMon(p, p[0x16], BOX2_MAIN_HitBoxGrid(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184))));
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            b->state = 2;
        }
        break;
    }
    return 1;
}

