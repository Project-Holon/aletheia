/*
 * function: BOX2_MAIN_StateMachineMove
 * address:  0x021E0200
 * packet:   pkt_ov170_021E0200
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * State machine in the family of src/matched/ov170_func_021DFA30.c.
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   BOX2_MAIN_StopSeq 0x021DD16C thumb
 *   BOX2_MAIN_WaitCursorMove 0x021DD930 thumb
 *   BOX2_MAIN_WaitBoxScroll 0x021DDAE8 thumb
 *   BOX2_MAIN_SwapWithNeighbour 0x021DE428 thumb
 *   BOX2_MAIN_FindMoverSlot 0x021DE5C8 thumb
 *   BOX2_MAIN_SetMoverEntry 0x021DE66C thumb
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb
 *   BOX2_MAIN_HitBoxGrid 0x021DF1DC thumb
 *   BOX2_MAIN_MoveCursorActor 0x021DF43C thumb
 *   BOX2_MAIN_IsSeqIdle 0x021E00C4 thumb
 *   BOX2_MAIN_IsSeqStep 0x021E0128 thumb
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb
 *   BOX2_SEQ_MoveCursorToSlot 0x021ED7C4 thumb
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb
 *   BOX2_UI_GetCloseButtonHit 0x021EF1B4 thumb
 *   BOX2_UI_GetPageButtonHit 0x021EF248 thumb
 *   BOX2_UI_CloseBar 0x021EF36C thumb
 *   BOX2_UI_OpenBar 0x021EF3A0 thumb
 *   BOX2_UI_UpdateBarMove 0x021EF400 thumb
 *   BOX2_UI_IsTopBarClosed 0x021EF480 thumb
 *   BOX2_UI_CloseListPack 0x021EF534 thumb
 *   BOX2_UI_OpenListPack 0x021EF57C thumb
 *   BOX2_UI_UpdateListPacks 0x021EF5C4 thumb
 *   BOX2_UI_IsListClosed 0x021EF60C thumb
 */

typedef struct {
    unsigned char pad[8];
    void *moves;
    unsigned short state;
    unsigned short timer;
} Blk;

struct WinMgr;
extern int BOX2_UI_UpdateListPacks(struct WinMgr *mgr);
extern int BOX2_UI_UpdateBarMove(unsigned char *p);
extern int TOUCHPANEL_GetCont(void);
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern int BOX2_UI_IsTopBarClosed(struct WinMgr *mgr);
extern void BOX2_UI_ToggleSlotPair(char *p, int v);
extern unsigned TOUCHPANEL_GetPointCont(unsigned *outA, unsigned *outB);
extern int BOX2_MAIN_HitBoxGrid(short x, int y);
extern void BOX2_MAIN_SwapWithNeighbour(unsigned char *p, unsigned a, unsigned b);
extern int BOX2_UI_IsListClosed(struct WinMgr *mgr);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern int BOX2_MAIN_FindMoverSlot(char *p, unsigned id);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void BOX2_UI_CloseBar(struct WinMgr *mgr);
extern void BOX2_UI_CloseListPack(struct WinMgr *mgr);
extern int BOX2_UI_GetPageButtonHit(void);
extern void BOX2_UI_OpenBar(struct WinMgr *mgr);
extern int BOX2_UI_GetCloseButtonHit(void);
extern void BOX2_MAIN_StopSeq(unsigned char *p, int dir);
extern void BOX2_MAIN_MoveCursorActor(char *p, int x, int y);
extern int BOX2_MAIN_IsSeqIdle(char *p);
extern int BOX2_MAIN_IsSeqStep(char *p);
extern int BOX2_MAIN_WaitCursorMove(unsigned char *p);
extern void BOX2_MAIN_SetMoverEntry(unsigned char *p, void *e);
extern void BOX2_SEQ_MoveCursorToSlot(char *p, int i);
extern int BOX2_MAIN_WaitBoxScroll(unsigned char *p);
extern void BOX2_MAIN_ResetBoxView(char *p);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))

int BOX2_MAIN_StateMachineMove(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    unsigned r = BOX2_UI_UpdateListPacks(MGR(p));
    int busy = BOX2_UI_UpdateBarMove(p);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        if (TOUCHPANEL_GetCont() == 1)
            BOX2_UI_OpenListPack(MGR(p));
        b->state = 1;
        break;
    case 1:
        if (BOX2_UI_IsTopBarClosed(MGR(p)) == 0)
            BOX2_UI_ToggleSlotPair(WORK(p), 1);
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            r = 0xFF;
            if (BOX2_UI_IsTopBarClosed(MGR(p)) == 0 && busy == 0)
                r = BOX2_MAIN_HitBoxGrid(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184)));
            BOX2_MAIN_SwapWithNeighbour(p, p[0x16], r);
            if (BOX2_UI_IsListClosed(MGR(p)) == 0)
                BOX2_SEQ_SetSlotDim((char **)p, 0);
            p[0x16] = BOX2_MAIN_FindMoverSlot((char *)p, 0x24);
            if (p[0x16] < 0x1E) {
                b->state = 6;
            } else {
                if (BOX2_UI_IsTopBarClosed(MGR(p)) == 0)
                    GFL_USE_PlaySeDefaultVolume(0x669);
                BOX2_UI_CloseBar(MGR(p));
                BOX2_UI_CloseListPack(MGR(p));
                b->state = 4;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (r == 0 && busy == 0) {
            if (BOX2_UI_IsTopBarClosed(MGR(p)) == 1) {
                if (BOX2_UI_GetPageButtonHit() == 0) {
                    p[0x17] = 0xFF;
                    p[0x1A] = 0;
                    BOX2_UI_OpenBar(MGR(p));
                    GFL_USE_PlaySeDefaultVolume(0x669);
                }
            } else if (b->timer == 0) {
                int dir = BOX2_UI_GetCloseButtonHit();
                if (dir == 0) {
                    GFL_USE_PlaySeDefaultVolume(0x548);
                    BOX2_MAIN_StopSeq(p, 0);
                    b->state = 2;
                } else if (dir == 1) {
                    GFL_USE_PlaySeDefaultVolume(0x548);
                    BOX2_MAIN_StopSeq(p, 1);
                    b->state = 3;
                }
            }
        }
        BOX2_MAIN_MoveCursorActor((char *)p, x, y);
        break;
    case 2:
        if (BOX2_MAIN_IsSeqIdle((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((char *)p, x, y);
        break;
    case 3:
        if (BOX2_MAIN_IsSeqStep((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((char *)p, x, y);
        break;
    case 4:
        if (BOX2_MAIN_WaitCursorMove(p) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 5;
        }
        break;
    case 5:
        if (busy == 0 && r == 0) {
            BOX2_MAIN_SetMoverEntry(p, b->moves);
            BOX2_SEQ_MoveCursorToSlot(WORK(p), p[0x16]);
            BOX2_SEQ_SetSlotDim((char **)p, 1);
            b->state = 8;
        }
        break;
    case 6:
        if (BOX2_MAIN_WaitBoxScroll(p) == 0) {
            BOX2_MAIN_SetMoverEntry(p, b->moves);
            BOX2_MAIN_ResetBoxView((char *)p);
            GFL_USE_PlaySeDefaultVolume(0x667);
            GFL_USE_PlaySeDefaultVolume(0x669);
            BOX2_UI_CloseBar(MGR(p));
            p[0x16] = 0xFF;
            b->state = 7;
        }
        break;
    case 7:
        if (busy == 0)
            b->state = 8;
        break;
    case 8:
        BOX2_UI_ToggleSlotPair(WORK(p), 0);
        BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
        BOX2_SEQ_SetSlotActors((char *)p, 2, 0);
        b->state = 0;
        return 0;
    }
    return 1;
}
