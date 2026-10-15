/*
 * function: BOX2_SEQ_StateMachineMove
 * address:  0x021E1628
 * packet:   pkt_ov170_021E1628
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of src/matched/ov170_func_021E0ABC.c.
 *
 * symbols:
 *   BOX2_UI_UpdateListPacks 0x021EF5C4 thumb
 *   BOX2_UI_UpdateBarMove 0x021EF400 thumb
 *   BOX2_SEQ_SetActorAnim 0x021EA878 thumb
 *   BOX2_SEQ_SetActorAffineMode 0x021ED108 thumb
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_UI_CloseListPack 0x021EF534 thumb
 *   BOX2_SEQ_IsActorAnimActive 0x021EBFEC thumb
 *   BOX2_SEQ_ShowHandSlots 0x021ED2F4 thumb
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   BOX2_UI_IsTopBarOpen 0x021EF45C thumb
 *   BOX2_MAIN_HitBoxGrid 0x021DF1DC thumb
 *   BOX2_MAIN_HitPartySlots 0x021DF228 thumb
 *   BOX2_MAIN_CompareSlots 0x021DDE80 thumb
 *   BOX2_MAIN_PlaceMonSceneFromBox 0x021DEA3C thumb
 *   BOX2_MAIN_IsWrappedDistance 0x021DD210 thumb
 *   BOX2_SEQ_LoadMonIcon 0x021EC35C thumb
 *   BOX2_MAIN_GetBoxFormId 0x021DEDCC thumb
 *   BOX2_MAIN_SetBoxScroll 0x021DEC98 thumb
 *   BOX2_UI_GetPartySlotPoint 0x021EF180 thumb
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_UI_MoveCursor 0x021EE364 thumb
 *   func_02026124 0x02026124 thumb
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb
 *   BOX2_UI_GetCloseButtonHit 0x021EF1B4 thumb
 *   BOX2_MAIN_StopSeq 0x021DD16C thumb
 *   BOX2_MAIN_MoveCursorTo 0x021E0FB0 thumb
 *   BOX2_MAIN_IsSeqIdle 0x021E00C4 thumb
 *   BOX2_MAIN_IsSeqStep 0x021E0128 thumb
 *   BOX2_MAIN_IsSwapScene 0x021DEAFC thumb
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb
 *   d_021EF79C 0x021EF79C data a1
 *   d_021EF7B4 0x021EF7B4 data a1
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb
 *   BOX2_UI_GetPageButtonHit 0x021EF248 thumb
 *   BOX2_UI_SlideBarIn 0x021EF3D8 thumb
 *   func_0202136C 0x0202136C thumb
 */

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
    unsigned short timer;
} Blk;

struct WinMgr;
extern int BOX2_UI_UpdateListPacks(struct WinMgr *mgr);
extern int BOX2_UI_UpdateBarMove(unsigned char *p);
extern void BOX2_SEQ_SetActorAnim(unsigned char *p, int v);
extern void BOX2_SEQ_SetActorAffineMode(char *w, int on);
extern void BOX2_SEQ_SetActorAnimSeq(char *w, int i, int v);
extern void BOX2_SEQ_SetActorDrawEnable(char *w, int i, int v);
extern void BOX2_UI_CloseListPack(struct WinMgr *mgr);
extern unsigned int BOX2_SEQ_IsActorAnimActive(char *p, int i);
extern void BOX2_SEQ_ShowHandSlots(char *w);
extern unsigned TOUCHPANEL_GetPointCont(unsigned *outA, unsigned *outB);
extern int BOX2_UI_IsTopBarOpen(struct WinMgr *mgr);
extern int BOX2_MAIN_HitBoxGrid(short x, int y);
extern int BOX2_MAIN_HitPartySlots(short x, short y, const unsigned char *r);
extern const unsigned char d_021EF79C[];
extern const unsigned char d_021EF7B4[];
extern void BOX2_UI_ToggleSlotPair(char *w, int a);
extern int BOX2_UI_GetPageButtonHit(void);
extern void BOX2_UI_SlideBarIn(struct WinMgr *mgr);
extern unsigned func_0202136C(unsigned short v);
extern int BOX2_MAIN_CompareSlots(unsigned char *p, unsigned a, unsigned b);
extern void BOX2_MAIN_PlaceMonSceneFromBox(int a, int b, int c, int d);
extern int BOX2_MAIN_IsWrappedDistance(unsigned char *p, unsigned a, unsigned b);
typedef unsigned int   u32;
struct Sound;
extern void BOX2_SEQ_LoadMonIcon(char **p, int box);
extern int BOX2_MAIN_GetBoxFormId(char *p, int box);
extern void BOX2_MAIN_SetBoxScroll(char *p, void *a, int dir);
extern int BOX2_UI_GetPartySlotPoint(int a, int b);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
extern void func_02026124(struct Sound *obj, u32 idx);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
extern int BOX2_UI_GetCloseButtonHit(void);
extern void BOX2_MAIN_StopSeq(unsigned char *p, int dir);
extern void BOX2_MAIN_MoveCursorTo(char *w, int x, int y);
extern int BOX2_MAIN_IsSeqIdle(char *p);
extern int BOX2_MAIN_IsSeqStep(char *p);
extern int BOX2_MAIN_IsSwapScene(int a);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define CNT(p) (*(unsigned short *)(WORK(p) + 0xA16C))

int BOX2_SEQ_StateMachineMove(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    int busy = BOX2_UI_UpdateListPacks(MGR(p));
    int wait = BOX2_UI_UpdateBarMove(p);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        BOX2_SEQ_SetActorAnim(p, (short)CNT(p));
        if (CNT(p) != 0) {
            BOX2_SEQ_SetActorAffineMode(WORK(p), 1);
            BOX2_SEQ_SetActorAnimSeq(WORK(p), 10, 1);
            BOX2_SEQ_SetActorDrawEnable(WORK(p), 10, 1);
            b->state = 1;
        } else {
            BOX2_UI_CloseListPack(MGR(p));
            b->state = 11;
        }
        break;
    case 1:
        if (BOX2_SEQ_IsActorAnimActive(WORK(p), 10) == 1)
            break;
        BOX2_SEQ_SetActorAffineMode(WORK(p), 0);
        BOX2_SEQ_ShowHandSlots(WORK(p));
        b->state = 2;
    case 2:
        if (BOX2_UI_IsTopBarOpen(MGR(p)) == 1)
            BOX2_UI_ToggleSlotPair(WORK(p), 1);
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            unsigned first;
            int flag;
            unsigned r;
            if (wait == 1 || BOX2_UI_IsTopBarOpen(MGR(p)) == 1)
                flag = 1;
            else
                flag = 0;
            if (wait == 0 && BOX2_UI_IsTopBarOpen(MGR(p)) == 1) {
                r = (unsigned short)BOX2_MAIN_HitBoxGrid(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184)));
                if (r == 0xFF)
                    r = (unsigned short)BOX2_MAIN_HitPartySlots(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF79C);
            } else {
                r = (unsigned short)BOX2_MAIN_HitPartySlots(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF7B4);
            }
            first = r;
            if (r == 0xFF)
                r = p[0x16];
            else if (BOX2_MAIN_CompareSlots(p, p[0x16], r) == 0)
                r = p[0x16];
            if (flag == 1) {
                BOX2_MAIN_PlaceMonSceneFromBox((int)p, first, r, 2);
                b->state = 7;
            } else {
                BOX2_MAIN_PlaceMonSceneFromBox((int)p, first, r, 1);
                if (r == p[0x16] && (func_0202136C(CNT(p)) == 0 || first == p[0x16]))
                    BOX2_UI_CloseListPack(MGR(p));
                b->state = 8;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (busy == 0 && wait == 0 && BOX2_UI_IsTopBarOpen(MGR(p)) == 0 && BOX2_UI_GetPageButtonHit() == 0) {
            BOX2_UI_SlideBarIn(MGR(p));
            BOX2_SEQ_SetSlotActors((char *)p, 0x81, 1);
            GFL_USE_PlaySeDefaultVolume(0x669);
            BOX2_UI_MoveCursor((char **)p, 6, p[0x16]);
            func_02026124(*(void **)(WORK(p) + 0x70), 0x27);
            func_02026124(*(void **)(WORK(p) + 0x70), 0x28);
            BOX2_SEQ_SetActorDrawEnable(WORK(p), 4, 0);
            BOX2_UI_DeleteSlotObjects((char *)p, 2, 1, 1);
            p[0x1E] = 1;
            *(int *)(WORK(p) + 0xA168) = p[0x16];
            *(int *)(WORK(p) + 0x68) = 0x42;
        }
        if (b->timer == 0) {
            int dir = BOX2_UI_GetCloseButtonHit();
            if (dir == 0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                BOX2_MAIN_StopSeq(p, 0);
                b->state = 3;
            } else if (dir == 1) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                BOX2_MAIN_StopSeq(p, 1);
                b->state = 4;
            }
        }
        BOX2_MAIN_MoveCursorTo(WORK(p), x, y);
        break;
    case 3:
        if (BOX2_MAIN_IsSeqIdle((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorTo(WORK(p), x, y);
        break;
    case 4:
        if (BOX2_MAIN_IsSeqStep((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorTo(WORK(p), x, y);
        break;
    case 7:
    case 8:
        if (BOX2_MAIN_IsSwapScene((int)p) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            if (b->state == 7) {
                b->state = 9;
            } else if (b->state == 8) {
                if (CNT(p) != 0) {
                    BOX2_SEQ_SetActorAffineMode(WORK(p), 0);
                    BOX2_SEQ_ShowHandSlots(WORK(p));
                }
                BOX2_UI_DeleteSlotObjects((char *)p, 0, 0, 1);
                b->state = 11;
            }
        }
        break;
    case 9:
        BOX2_SEQ_SetActorAffineMode(WORK(p), 1);
        BOX2_SEQ_SetActorAnimSeq(WORK(p), 10, 2);
        BOX2_SEQ_SetSlotDim((char **)p, 0);
        b->state = 10;
        break;
    case 10:
        if (BOX2_SEQ_IsActorAnimActive(WORK(p), 10) == 0) {
            BOX2_SEQ_SetActorDrawEnable(WORK(p), 10, 0);
            BOX2_SEQ_SetActorAffineMode(WORK(p), 0);
            b->state = 11;
        }
        break;
    case 11:
        if (busy == 0 && wait == 0) {
            b->state = 0;
            return 0;
        }
        break;
    }
    return 1;
}
