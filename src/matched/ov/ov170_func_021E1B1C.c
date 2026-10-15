/*
 * function: BOX2_SEQ_StateMachineScroll
 * address:  0x021E1B1C
 * packet:   pkt_ov170_021E1B1C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of src/matched/ov170_func_021DFA30.c.
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_020260E4 0x020260E4 thumb
 *   BGWINFRM_IsMoving 0x0202CE40 thumb
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   BOX2_MAIN_StopSeq 0x021DD16C thumb
 *   BOX2_MAIN_IsWrappedDistance 0x021DD210 thumb
 *   BOX2_MAIN_WaitCursorMove 0x021DD930 thumb
 *   BOX2_MAIN_MoveCursorWithMon 0x021DE158 thumb
 *   BOX2_MAIN_FindMoverSlot 0x021DE5C8 thumb
 *   BOX2_MAIN_SetMoverEntry 0x021DE66C thumb
 *   BOX2_MAIN_SetBoxScroll 0x021DEC98 thumb
 *   BOX2_MAIN_GetBoxFormId 0x021DEDCC thumb
 *   BOX2_MAIN_HitBoxGrid 0x021DF1DC thumb
 *   BOX2_MAIN_HitPartySlots 0x021DF228 thumb
 *   BOX2_MAIN_MoveCursorActor 0x021DF43C thumb
 *   BOX2_MAIN_IsSeqIdle 0x021E00C4 thumb
 *   BOX2_MAIN_IsSeqStep 0x021E0128 thumb
 *   BOX2_SEQ_LoadMonIcon 0x021EC35C thumb
 *   BOX2_SEQ_HidePartialSlots 0x021EC5A0 thumb
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb
 *   BOX2_SEQ_MoveCursorToSlot 0x021ED7C4 thumb
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb
 *   BOX2_UI_MoveCursor 0x021EE364 thumb
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb
 *   BOX2_UI_GetPartySlotPoint 0x021EF180 thumb
 *   BOX2_UI_GetCloseButtonHit 0x021EF1B4 thumb
 *   BOX2_UI_PutBottomBarClosed 0x021EF35C thumb
 *   BOX2_UI_CloseBar 0x021EF36C thumb
 *   BOX2_UI_IsTopBarOpen 0x021EF45C thumb
 *   BOX2_UI_CloseListPack 0x021EF534 thumb
 *   BOX2_UI_OpenListPack 0x021EF57C thumb
 *   BOX2_MAIN_IsWindowBusy 0x021E01B0 thumb
 *   BOX2_UI_UpdateListPacks 0x021EF5C4 thumb
 *   BOX2_UI_IsListClosed 0x021EF60C thumb
 *   BOX2_UI_IsInfoBarOpen 0x021EF770 thumb
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
extern int BOX2_MAIN_IsWindowBusy(unsigned char *p);
extern int BOX2_UI_UpdateListPacks(struct WinMgr *mgr);
extern int TOUCHPANEL_GetCont(void);
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern unsigned TOUCHPANEL_GetPointCont(unsigned *outA, unsigned *outB);
extern int BOX2_UI_IsInfoBarOpen(struct WinMgr *mgr);
extern int BOX2_MAIN_MoveCursorWithMon(unsigned char *p, unsigned a, unsigned b);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern int BOX2_UI_IsTopBarOpen(struct WinMgr *mgr);
extern int BOX2_MAIN_HitPartySlots(short x, short y, const unsigned char *r);
extern const unsigned char d_021EF79C[];
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
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
extern int BOX2_UI_GetCloseButtonHit(void);
extern void BOX2_MAIN_StopSeq(unsigned char *p, int dir);
extern void BOX2_MAIN_MoveCursorActor(char *p, int x, int y);
extern int BOX2_MAIN_IsSeqIdle(char *p);
extern int BOX2_MAIN_IsSeqStep(char *p);
extern int BOX2_MAIN_WaitCursorMove(unsigned char *p);
extern void BOX2_UI_PutBottomBarClosed(struct WinMgr *mgr);
extern void BOX2_UI_CloseBar(struct WinMgr *mgr);
extern void BOX2_SEQ_HidePartialSlots(char **p, int flag);
extern void BOX2_MAIN_SetMoverEntry(unsigned char *p, void *e);
typedef unsigned char  u8;
struct Sound;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void BOX2_UI_SetCursorPos(char **p, unsigned idx);
extern void BOX2_SEQ_MoveCursorToSlot(char *p, int i);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define SYS(p) (*(unsigned **)(p))

int BOX2_SEQ_StateMachineScroll(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    int busy;
    unsigned r;
    unsigned x;
    unsigned y;
    if (BGWINFRM_IsMoving(MGR(p), 8) == 1)
        busy = BOX2_MAIN_IsWindowBusy(p);
    else
        busy = 0;
    r = BOX2_UI_UpdateListPacks(MGR(p));
    switch (b->state) {
    case 0:
        if (TOUCHPANEL_GetCont() == 1)
            BOX2_UI_OpenListPack(MGR(p));
        b->state = 1;
        break;
    case 1:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            r = 0xFF;
            if (BOX2_UI_IsTopBarOpen(MGR(p)) == 1)
                r = BOX2_MAIN_HitPartySlots(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF79C);
            if (r == 0xFF)
                r = BOX2_MAIN_HitBoxGrid(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184)));
            if (SYS(p)[9] == 4 && SYS(p)[5] == 1) {
                r = 0xFF;
                *(unsigned char *)(WORK(p) + 0xA173) = 5;
            }
            if (BOX2_MAIN_MoveCursorWithMon(p, p[0x16], r) == 0)
                r = 0xFF;
            if (BOX2_UI_IsListClosed(MGR(p)) == 0)
                BOX2_SEQ_SetSlotDim((char **)p, 0);
            if (r != 0xFF)
                p[0x16] = BOX2_MAIN_FindMoverSlot((char *)p, 0x24);
            if (BOX2_UI_IsTopBarOpen(MGR(p)) == 0 && busy == 0)
                BOX2_UI_CloseListPack(MGR(p));
            if (r == 0xFF && p[0x14] != p[0x17]) {
                r = BOX2_MAIN_IsWrappedDistance(p, p[0x14], p[0x17]);
                p[0x14] = p[0x17];
                BOX2_SEQ_LoadMonIcon((char **)p, p[0x14]);
                BOX2_MAIN_SetBoxScroll((char *)p, (void *)BOX2_MAIN_GetBoxFormId((char *)p, p[0x14]), r);
                if (r == 0)
                    b->state = 4;
                else
                    b->state = 5;
            } else {
                b->state = 2;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (busy == 0 && r == 0 && BOX2_UI_IsTopBarOpen(MGR(p)) == 0 && p[0x16] != BOX2_UI_GetPartySlotPoint(x, y)) {
            p[0x1A] = 2;
            BOX2_UI_PutBottomBarClosed(MGR(p));
            BOX2_UI_CloseBar(MGR(p));
            BOX2_SEQ_HidePartialSlots((char **)p, 1);
            GFL_USE_PlaySeDefaultVolume(0x669);
            BOX2_UI_MoveCursor((char **)p, 6, p[0x16]);
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
        BOX2_MAIN_MoveCursorActor((char *)p, x, y);
        break;
    case 4:
        if (BOX2_MAIN_IsSeqIdle((char *)p) == 0)
            b->state = 2;
        break;
    case 5:
        if (BOX2_MAIN_IsSeqStep((char *)p) == 0)
            b->state = 2;
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
    case 16:
        BOX2_MAIN_SetMoverEntry(p, b->moves);
        if (BOX2_UI_IsInfoBarOpen(MGR(p)) == 0 && BOX2_UI_IsTopBarOpen(MGR(p)) == 0) {
            BOX2_SEQ_MoveCursorToSlot(WORK(p), p[0x16]);
            BOX2_SEQ_SetSlotDim((char **)p, 1);
        } else {
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            func_020260E4(*(void **)(WORK(p) + 0x70), p[0x16]);
            BOX2_UI_SetCursorPos((char **)p, p[0x16]);
        }
        b->state = 0;
        return 0;
    }
    return 1;
}
