/*
 * function: BOX2_MAIN_StateMachinePen
 * address:  0x021E0470
 * packet:   pkt_ov170_021E0470
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_UpdateListPacks 0x021EF5C4 thumb
 *   BOX2_UI_UpdateBarMove 0x021EF400 thumb
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   BOX2_UI_OpenListPack 0x021EF57C thumb
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   BOX2_UI_IsTopBarOpen 0x021EF45C thumb
 *   BOX2_MAIN_HitPartySlots 0x021DF228 thumb
 *   d_021EF79C 0x021EF79C data a1
 *   BOX2_MAIN_SetMoverTarget 0x021DE530 thumb
 *   BOX2_UI_IsListClosed 0x021EF60C thumb
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb
 *   BOX2_MAIN_FindMoverSlot 0x021DE5C8 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_UI_OpenBar 0x021EF3A0 thumb
 *   BOX2_UI_GetPartySlotPoint 0x021EF180 thumb
 *   BOX2_UI_PutBottomBarClosed 0x021EF35C thumb
 *   BOX2_UI_CloseBar 0x021EF36C thumb
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb
 *   BOX2_MAIN_MoveCursorActor 0x021DF43C thumb
 *   BOX2_MAIN_WaitCursorMove 0x021DD930 thumb
 *   BOX2_UI_CloseListPack 0x021EF534 thumb
 *   BOX2_MAIN_SetMoverEntry 0x021DE66C thumb
 *   BOX2_SEQ_MoveCursorToSlot 0x021ED7C4 thumb
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb
 *
 * State machine in the 021DFA30 family (template 021E0ABC): pick a box with
 * the pen, slide the cursor there, then close.
 */

typedef struct {
    unsigned char pad[8];
    void *entry;
    unsigned short state;
    unsigned short timer;
} Blk;

struct WinMgr;
extern int BOX2_UI_UpdateListPacks(struct WinMgr *mgr);
extern int BOX2_UI_UpdateBarMove(unsigned char *p);
extern int TOUCHPANEL_GetCont(void);
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern unsigned TOUCHPANEL_GetPointCont(unsigned *outA, unsigned *outB);
extern int BOX2_UI_IsTopBarOpen(struct WinMgr *mgr);
extern int BOX2_MAIN_HitPartySlots(short x, short y, const unsigned char *r);
extern const unsigned char d_021EF79C[];
extern void BOX2_MAIN_SetMoverTarget(unsigned char *p, int a, int b);
extern int BOX2_UI_IsListClosed(struct WinMgr *mgr);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern int BOX2_MAIN_FindMoverSlot(char *p, unsigned id);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void BOX2_UI_OpenBar(struct WinMgr *mgr);
extern int BOX2_UI_GetPartySlotPoint(int a, int b);
extern void BOX2_UI_PutBottomBarClosed(struct WinMgr *mgr);
extern void BOX2_UI_CloseBar(struct WinMgr *mgr);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
extern void BOX2_MAIN_MoveCursorActor(char *p, int x, int y);
extern int BOX2_MAIN_WaitCursorMove(unsigned char *p);
extern void BOX2_UI_CloseListPack(struct WinMgr *mgr);
extern void BOX2_MAIN_SetMoverEntry(unsigned char *p, void *e);
extern void BOX2_SEQ_MoveCursorToSlot(char *w, int i);
extern void BOX2_MAIN_ResetBoxView(char *p);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))

int BOX2_MAIN_StateMachinePen(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    int busy = BOX2_UI_UpdateListPacks(MGR(p));
    int wait = BOX2_UI_UpdateBarMove(p);
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
            int r = 0xFF;
            if (BOX2_UI_IsTopBarOpen(MGR(p)) == 1)
                r = BOX2_MAIN_HitPartySlots(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF79C);
            BOX2_MAIN_SetMoverTarget(p, p[0x16], r);
            if (BOX2_UI_IsListClosed(MGR(p)) == 0)
                BOX2_SEQ_SetSlotDim((char **)p, 0);
            p[0x16] = BOX2_MAIN_FindMoverSlot((char *)p, 0x24);
            if (p[0x16] >= 0x1E) {
                b->state = 5;
                break;
            }
            if (wait == 1 || BOX2_UI_IsTopBarOpen(MGR(p)) == 1) {
                GFL_USE_PlaySeDefaultVolume(0x669);
                BOX2_UI_OpenBar(MGR(p));
            }
            b->state = 2;
            break;
        }
        if (busy == 0 && wait == 0 && BOX2_UI_IsTopBarOpen(MGR(p)) == 0 && p[0x16] != BOX2_UI_GetPartySlotPoint(x, y)) {
            GFL_USE_PlaySeDefaultVolume(0x669);
            BOX2_UI_PutBottomBarClosed(MGR(p));
            BOX2_UI_CloseBar(MGR(p));
            BOX2_UI_DeleteSlotObjects((char *)p, 2, 2, 1);
            *(int *)(WORK(p) + 0xA168) = p[0x16];
        }
        BOX2_MAIN_MoveCursorActor((char *)p, x, y);
        break;
    case 2:
        if (BOX2_MAIN_WaitCursorMove(p) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 3;
        }
        if (wait == 0)
            BOX2_UI_CloseListPack(MGR(p));
        break;
    case 3:
        if (wait == 0) {
            BOX2_UI_CloseListPack(MGR(p));
            b->state = 4;
        }
        break;
    case 4:
        if (busy == 0) {
            BOX2_MAIN_SetMoverEntry(p, b->entry);
            BOX2_SEQ_MoveCursorToSlot(WORK(p), p[0x16]);
            BOX2_SEQ_SetSlotDim((char **)p, 1);
            b->state = 7;
        }
        break;
    case 5:
        if (BOX2_MAIN_WaitCursorMove(p) == 0) {
            BOX2_MAIN_SetMoverEntry(p, b->entry);
            GFL_USE_PlaySeDefaultVolume(0x667);
            GFL_USE_PlaySeDefaultVolume(0x669);
            p[0x16] = 0xFF;
            BOX2_UI_OpenBar(MGR(p));
            b->state = 6;
        }
        break;
    case 6:
        if (wait == 0) {
            BOX2_MAIN_ResetBoxView((char *)p);
            b->state = 7;
        }
        break;
    case 7:
        BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
        BOX2_SEQ_SetSlotActors((char *)p, 2, 0);
        b->state = 0;
        return 0;
    }
    return 1;
}
