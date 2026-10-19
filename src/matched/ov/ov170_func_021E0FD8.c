/*
 * function: BOX2_MAIN_StateMachineDragNoBar
 * address:  0x021E0FD8
 * packet:   pkt_ov170_021E0FD8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of src/matched/BOX2_MAIN_StateMachineCoin.c.
 *
 * symbols:
 *   BOX2_SEQ_SetActorAffineMode 0x021ED108 thumb
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_SEQ_IsActorAnimActive 0x021EBFEC thumb
 *   BOX2_SEQ_ShowHandSlots 0x021ED2F4 thumb
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   BOX2_MAIN_HitBoxGrid 0x021DF1DC thumb
 *   BOX2_MAIN_HitPartySlots 0x021DF228 thumb
 *   BOX2_MAIN_CompareSlots 0x021DDE80 thumb
 *   BOX2_MAIN_StartHandMotionToBoxSlot 0x021DEA3C thumb
 *   BOX2_MAIN_IsWrappedDistance 0x021DD210 thumb
 *   BOX2_SEQ_LoadMonIcon 0x021EC35C thumb
 *   BOX2_MAIN_GetBoxWallpaper 0x021DEDCC thumb
 *   BOX2_MAIN_SetBoxScroll 0x021DEC98 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_UI_GetCloseButtonHit 0x021EF1B4 thumb
 *   BOX2_MAIN_StepToAdjacentBox 0x021DD16C thumb
 *   BOX2_MAIN_MoveCursorTo 0x021E0FB0 thumb
 *   BOX2_MAIN_StepScrollToPrevBox 0x021E00C4 thumb
 *   BOX2_MAIN_StepScrollToNextBox 0x021E0128 thumb
 *   BOX2_MAIN_StepHandMotionToSlot 0x021DEAFC thumb
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb
 *   d_021EF79C 0x021EF79C data a1
 */

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
    unsigned short timer;
} Blk;

extern void BOX2_SEQ_SetActorAffineMode(char *w, int on);
extern void BOX2_SEQ_SetActorAnimSeq(char *w, int i, int v);
extern void BOX2_SEQ_SetActorDrawEnable(char *w, int i, int v);
typedef unsigned int   u32;
extern u32 BOX2_SEQ_IsActorAnimActive(char *p, int i);
extern void BOX2_SEQ_ShowHandSlots(char *w);
extern unsigned TOUCHPANEL_GetPointCont(unsigned *outA, unsigned *outB);
extern int BOX2_MAIN_HitBoxGrid(short x, int y);
extern int BOX2_MAIN_HitPartySlots(short x, short y, const unsigned char *r);
extern const unsigned char d_021EF79C[];
extern int BOX2_MAIN_CompareSlots(unsigned char *p, unsigned a, unsigned b);
extern void BOX2_MAIN_StartHandMotionToBoxSlot(int a, int b, int c, int d);
extern int BOX2_MAIN_IsWrappedDistance(unsigned char *p, unsigned a, unsigned b);
extern void BOX2_SEQ_LoadMonIcon(char **p, int box);
extern int BOX2_MAIN_GetBoxWallpaper(char *p, int box);
extern void BOX2_MAIN_SetBoxScroll(char *p, void *a, int dir);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern int BOX2_UI_GetCloseButtonHit(void);
extern void BOX2_MAIN_StepToAdjacentBox(unsigned char *p, int dir);
extern void BOX2_MAIN_MoveCursorTo(char *w, int x, int y);
extern int BOX2_MAIN_StepScrollToPrevBox(char *p);
extern int BOX2_MAIN_StepScrollToNextBox(char *p);
extern int BOX2_MAIN_StepHandMotionToSlot(int a);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);

#define WORK(p) (*(char **)((p) + 0x2C))

int BOX2_MAIN_StateMachineDragNoBar(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        BOX2_SEQ_SetActorAffineMode(WORK(p), 1);
        BOX2_SEQ_SetActorAnimSeq(WORK(p), 10, 1);
        BOX2_SEQ_SetActorDrawEnable(WORK(p), 10, 1);
        b->state = 1;
        break;
    case 1:
        if (BOX2_SEQ_IsActorAnimActive(WORK(p), 10) != 0)
            break;
        BOX2_SEQ_SetActorAffineMode(WORK(p), 0);
        BOX2_SEQ_ShowHandSlots(WORK(p));
        b->state = 2;
        break;
    case 2:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            unsigned first;
            unsigned r;
            int back;
            r = (unsigned short)BOX2_MAIN_HitBoxGrid(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184)));
            if (r == 0xFF)
                r = (unsigned short)BOX2_MAIN_HitPartySlots(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF79C);
            back = 0;
            first = r;
            if (r == 0xFF) {
                r = p[0x16];
                back = 1;
            } else if (BOX2_MAIN_CompareSlots(p, p[0x16], r) == 0) {
                r = p[0x16];
                back = 1;
            }
            BOX2_MAIN_StartHandMotionToBoxSlot((int)p, first, r, 2);
            if (back == 1 && p[0x17] != 0xFF && p[0x17] != p[0x14]) {
                int dir = BOX2_MAIN_IsWrappedDistance(p, p[0x14], p[0x17]);
                p[0x14] = p[0x17];
                BOX2_SEQ_LoadMonIcon((char **)p, p[0x14]);
                BOX2_MAIN_SetBoxScroll((char *)p, (void *)BOX2_MAIN_GetBoxWallpaper((char *)p, p[0x14]), dir);
                if (dir == 0)
                    b->state = 5;
                else
                    b->state = 6;
            } else {
                b->state = 7;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (b->timer == 0) {
            int dir = BOX2_UI_GetCloseButtonHit();
            if (dir == 0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                BOX2_MAIN_StepToAdjacentBox(p, 0);
                b->state = 3;
            } else if (dir == 1) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                BOX2_MAIN_StepToAdjacentBox(p, 1);
                b->state = 4;
            }
        }
        BOX2_MAIN_MoveCursorTo(WORK(p), x, y);
        break;
    case 3:
        if (BOX2_MAIN_StepScrollToPrevBox((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorTo(WORK(p), x, y);
        break;
    case 4:
        if (BOX2_MAIN_StepScrollToNextBox((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorTo(WORK(p), x, y);
        break;
    case 5:
    case 6:
        if (b->state == 5 && BOX2_MAIN_StepScrollToPrevBox((char *)p) == 0)
            b->state = 7;
        if (b->state == 6 && BOX2_MAIN_StepScrollToNextBox((char *)p) == 0)
            b->state = 7;
    case 7:
        if (BOX2_MAIN_StepHandMotionToSlot((int)p) == 0 && b->state == 7) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 8;
        }
        break;
    case 8:
        BOX2_SEQ_SetActorAffineMode(WORK(p), 1);
        BOX2_SEQ_SetActorAnimSeq(WORK(p), 10, 2);
        BOX2_SEQ_SetSlotDim((char **)p, 0);
        b->state = 9;
        break;
    case 9:
        if (BOX2_SEQ_IsActorAnimActive(WORK(p), 10) == 0) {
            BOX2_SEQ_SetActorDrawEnable(WORK(p), 10, 0);
            BOX2_SEQ_SetActorAffineMode(WORK(p), 0);
            b->state = 10;
        }
        break;
    case 10:
        b->state = 0;
        return 0;
    }
    return 1;
}
