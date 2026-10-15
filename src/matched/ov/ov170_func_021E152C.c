/*
 * function: BOX2_SEQ_StateMenuMain
 * address:  0x021E152C
 * packet:   pkt_ov170_021E152C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_IsWrappedDistance 0x021DD210 thumb
 *   BOX2_SEQ_LoadMonIcon 0x021EC35C thumb
 *   BOX2_MAIN_GetBoxFormId 0x021DEDCC thumb
 *   BOX2_MAIN_SetBoxScroll 0x021DEC98 thumb
 *   BOX2_SEQ_SetCursorFrame 0x021ED544 thumb
 *   BOX2_MAIN_PlaceTargetMonScene 0x021DEA4C thumb
 *   BOX2_MAIN_IsSeqIdle 0x021E00C4 thumb
 *   BOX2_MAIN_IsSeqStep 0x021E0128 thumb
 *   BOX2_MAIN_IsMoveScene 0x021DEB08 thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_SetActorAffineMode 0x021ED108 thumb
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb
 *   BOX2_SEQ_IsActorAnimActive 0x021EBFEC thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 */

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
} Blk;

extern int BOX2_MAIN_IsWrappedDistance(unsigned char *p, unsigned a, unsigned b);
extern void BOX2_SEQ_LoadMonIcon(char **p, int box);
extern int BOX2_MAIN_GetBoxFormId(char *p, int box);
extern void BOX2_MAIN_SetBoxScroll(char *p, void *a, int dir);
extern void BOX2_SEQ_SetCursorFrame(char *p, int b);
extern void BOX2_MAIN_PlaceTargetMonScene(char *p, int a, int b);
extern int BOX2_MAIN_IsSeqIdle(char *p);
extern int BOX2_MAIN_IsSeqStep(char *p);
extern int BOX2_MAIN_IsMoveScene(unsigned char *p);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void BOX2_SEQ_SetActorAffineMode(char *p, int on);
extern void BOX2_SEQ_SetActorAnimSeq(char *p, int i, int v);
typedef unsigned int   u32;
extern u32 BOX2_SEQ_IsActorAnimActive(char *p, int i);
extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);

#define WORK(p) (*(char **)((p) + 0x2C))

int BOX2_SEQ_StateMenuMain(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    switch (b->state) {
    case 0:
        if (p[0x17] != 0xFF && p[0x17] != p[0x14]) {
            int dir = BOX2_MAIN_IsWrappedDistance(p, p[0x14], p[0x17]);
            p[0x14] = p[0x17];
            BOX2_SEQ_LoadMonIcon((char **)p, p[0x14]);
            BOX2_MAIN_SetBoxScroll((char *)p, (void *)BOX2_MAIN_GetBoxFormId((char *)p, p[0x14]), dir);
            if (dir == 0)
                b->state = 2;
            else
                b->state = 3;
            break;
        }
    case 1:
        BOX2_SEQ_SetCursorFrame((char *)p, 7);
        BOX2_MAIN_PlaceTargetMonScene((char *)p, *(unsigned short *)(WORK(p) + 0xA16E), 2);
        b->state = 4;
        break;
    case 2:
        if (BOX2_MAIN_IsSeqIdle((char *)p) == 0)
            b->state = 1;
        break;
    case 3:
        if (BOX2_MAIN_IsSeqStep((char *)p) == 0)
            b->state = 1;
        break;
    case 4:
        if (BOX2_MAIN_IsMoveScene(p) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 5;
        }
        break;
    case 5:
        BOX2_SEQ_SetActorAffineMode(WORK(p), 1);
        BOX2_SEQ_SetActorAnimSeq(WORK(p), 10, 2);
        b->state = 6;
        break;
    case 6:
        if (BOX2_SEQ_IsActorAnimActive(WORK(p), 10) == 0) {
            BOX2_SEQ_SetActorAffineMode(WORK(p), 0);
            BOX2_SEQ_SetActorDrawEnable(WORK(p), 10, 0);
            b->state = 7;
        }
        break;
    case 7:
        BOX2_SEQ_SetCursorFrame((char *)p, 6);
        b->state = 0;
        return 0;
    }
    return 1;
}
