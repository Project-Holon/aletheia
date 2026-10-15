/*
 * function: BOX2_SEQ_StateMenuSwap
 * address:  0x021E1458
 * packet:   pkt_ov170_021E1458
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetCursorFrame 0x021ED544 thumb
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_SetActorAffineMode 0x021ED108 thumb
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb
 *   BOX2_SEQ_IsActorAnimActive 0x021EBFEC thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 */

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
    unsigned short cnt;
} Blk;

extern void BOX2_SEQ_SetCursorFrame(char *p, int b);
extern void BOX2_SEQ_GetActorSurfacePos(char *p, int i, short *a, short *b, unsigned short space);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void BOX2_SEQ_SetActorAffineMode(char *p, int on);
extern void BOX2_SEQ_SetActorAnimSeq(char *p, int i, int v);
typedef unsigned int   u32;
extern u32 BOX2_SEQ_IsActorAnimActive(char *p, int i);
extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);

#define WORK(p) (*(char **)((p) + 0x2C))

int BOX2_SEQ_StateMenuSwap(char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    short t[2];
    switch (b->state) {
    case 0:
        BOX2_SEQ_SetCursorFrame(p, 7);
        b->state = 1;
    case 1:
        if (b->cnt == 4) {
            b->cnt = 0;
            b->state = 2;
            break;
        }
        BOX2_SEQ_GetActorSurfacePos(WORK(p), 10, &t[1], &t[0], 0);
        BOX2_SEQ_AddActorSurfacePos(WORK(p), 10, (short)t[1], (short)(t[0] + 2), (short)0);
        b->cnt++;
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x667);
        BOX2_SEQ_SetCursorFrame(p, 6);
        BOX2_SEQ_SetActorAffineMode(WORK(p), 1);
        BOX2_SEQ_SetActorAnimSeq(WORK(p), 10, 2);
        b->state = 3;
        break;
    case 3:
        if (BOX2_SEQ_IsActorAnimActive(WORK(p), 10) == 0) {
            BOX2_SEQ_SetActorAffineMode(WORK(p), 0);
            BOX2_SEQ_SetActorDrawEnable(WORK(p), 10, 0);
            b->state = 4;
        }
        break;
    case 4:
        BOX2_SEQ_SetCursorFrame(p, 6);
        b->state = 0;
        return 0;
    }
    return 1;
}
