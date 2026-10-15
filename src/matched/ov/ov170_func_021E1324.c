/*
 * function: BOX2_SEQ_StateMenuSelect
 * address:  0x021E1324
 * packet:   pkt_ov170_021E1324
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
 *   BOX2_SEQ_CreateHandSlotActorsB 0x021ED1C8 thumb
 *   BOX2_SEQ_ShowHandSlots 0x021ED2F4 thumb
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
extern void BOX2_SEQ_CreateHandSlotActorsB(char *w);
extern void BOX2_SEQ_ShowHandSlots(char *w);

#define WORK(p) (*(char **)((p) + 0x2C))

int BOX2_SEQ_StateMenuSelect(char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    short t[2];
    switch (b->state) {
    case 0:
        BOX2_SEQ_SetActorAffineMode(WORK(p), 1);
        BOX2_SEQ_SetActorAnimSeq(WORK(p), 10, 1);
        BOX2_SEQ_SetActorDrawEnable(WORK(p), 10, 1);
        b->state++;
        break;
    case 1:
        if (BOX2_SEQ_IsActorAnimActive(WORK(p), 10) != 0)
            break;
        BOX2_SEQ_SetActorAffineMode(WORK(p), 0);
        b->state++;
        break;
    case 2:
        BOX2_SEQ_SetCursorFrame(p, 7);
        b->state++;
    case 3:
        if (b->cnt == 4) {
            b->cnt = 0;
            b->state++;
            break;
        }
        BOX2_SEQ_GetActorSurfacePos(WORK(p), 4, &t[1], &t[0], 0);
        BOX2_SEQ_AddActorSurfacePos(WORK(p), 4, (short)t[1], (short)(t[0] + 2), (short)0);
        b->cnt++;
        break;
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x666);
        BOX2_SEQ_SetCursorFrame(p, 8);
        b->state++;
    case 5:
        if (b->cnt == 4) {
            BOX2_SEQ_CreateHandSlotActorsB(WORK(p));
            BOX2_SEQ_ShowHandSlots(WORK(p));
            b->cnt = 0;
            b->state = 0;
            return 0;
        }
        BOX2_SEQ_GetActorSurfacePos(WORK(p), 4, &t[1], &t[0], 0);
        BOX2_SEQ_AddActorSurfacePos(WORK(p), 4, (short)t[1], (short)(t[0] - 2), (short)0);
        BOX2_SEQ_GetActorSurfacePos(WORK(p), 10, &t[1], &t[0], 0);
        BOX2_SEQ_AddActorSurfacePos(WORK(p), 10, (short)t[1], (short)(t[0] - 2), (short)0);
        b->cnt++;
        break;
    }
    return 1;
}
