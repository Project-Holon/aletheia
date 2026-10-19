/*
 * function: BOX2_MAIN_StateMachineReturnHeld
 * address:  0x021E122C
 * packet:   pkt_ov170_021E122C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetActorAffineMode 0x021ED108 thumb
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_SEQ_IsActorAnimActive 0x021EBFEC thumb
 *   BOX2_MAIN_StartHandMotionToBoxArrow 0x021DE980 thumb
 *   BOX2_MAIN_StartHandMotionToBoxSlot 0x021DEA3C thumb
 *   BOX2_MAIN_StepHandMotionToSlot 0x021DEAFC thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *
 * Callback of BOX2_SEQ_StateMoveItemScroll (state machine in the 021E1324 family): show
 * window 10, return the held item to its slot, then hide the window.
 */

typedef struct {
    unsigned short idx;
    unsigned short slot;
} Entry;

typedef struct {
    unsigned char pad[8];
    Entry *entry;
    unsigned short state;
} Blk;

extern void BOX2_SEQ_SetActorAffineMode(char *w, int on);
extern void BOX2_SEQ_SetActorAnimSeq(char *w, int i, int v);
extern void BOX2_SEQ_SetActorDrawEnable(char *w, int i, int v);
typedef unsigned int   u32;
extern u32 BOX2_SEQ_IsActorAnimActive(char *p, int i);
extern void BOX2_MAIN_StartHandMotionToBoxArrow(unsigned char *p, int mode);
extern void BOX2_MAIN_StartHandMotionToBoxSlot(int a, int b, int c, int d);
extern int BOX2_MAIN_StepHandMotionToSlot(int a);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);

#define WORK(p) (*(char **)((p) + 0x2C))

int BOX2_MAIN_StateMachineReturnHeld(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
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
        b->state = 2;
        break;
    case 2: {
        unsigned char old = p[0x16];
        p[0x16] = b->entry->idx;
        if (p[0x17] != 0xFF && p[0x17] != p[0x14])
            BOX2_MAIN_StartHandMotionToBoxArrow(p, 2);
        else
            BOX2_MAIN_StartHandMotionToBoxSlot((int)p, old, old, 2);
        b->state = 3;
        break;
    }
    case 3:
        if (BOX2_MAIN_StepHandMotionToSlot((int)p) != 0)
            break;
        if (p[0x17] != 0xFF && p[0x17] != p[0x14]) {
            b->state = 5;
        } else {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 4;
        }
        break;
    case 4:
        BOX2_SEQ_SetActorAffineMode(WORK(p), 1);
        BOX2_SEQ_SetActorAnimSeq(WORK(p), 10, 2);
        b->state = 5;
        break;
    case 5:
        if (BOX2_SEQ_IsActorAnimActive(WORK(p), 10) != 0)
            break;
        BOX2_SEQ_SetActorDrawEnable(WORK(p), 10, 0);
        BOX2_SEQ_SetActorAffineMode(WORK(p), 0);
        b->state = 6;
        break;
    case 6:
        b->state = 0;
        return 0;
    }
    return 1;
}
