/*
 * function: BOX2_SEQ_CreateHandSlotActorsB
 * address:  0x021ED1C8
 * packet:   pkt_ov170_021ED1C8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb
 *   CLACT_GetActorDrawPriority 0x0204B838 arm
 *   CLACT_GetActorBgPriority 0x0204B864 arm
 *   BOX2_SEQ_CreateActorFromDesc 0x021EBEE0 thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb
 *   BOX2_SEQ_SetActorDrawPriority 0x021EC048 thumb
 *   BOX2_SEQ_SetActorBgPriority 0x021EC030 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   d_021EFE70 0x021EFE70 data a1
 *   d_021EFCD0 0x021EFCD0 data a1
 *   d_021EFCC8 0x021EFCC8 data a1
 *
 * Sibling of src/matched/ov/BOX2_SEQ_MoveCursorActor.c: builds (or moves) the
 * eight frame pieces around window 10 while the count at 0xA16C is nonzero.
 * The index is an int compared against 8u (docs/idioms/a-signed-index-under-an-unsigned-bound-keeps-the-window-sum-uncached.md).
 */
#include "../include/Obj08247.h"

typedef struct {
    short x;
    short y;
    unsigned char pad4[2];
    unsigned char b6;
    unsigned char b7;
    int a;
    int b;
    int c;
    unsigned short e;
    unsigned short d;
} Desc;

extern void BOX2_SEQ_GetActorSurfacePos(char *p, int i, short *a, short *b, unsigned short space);
extern int CLACT_GetActorDrawPriority(int a0);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
extern u32 CLACT_GetActorBgPriority(u8 *a0);
extern void *BOX2_SEQ_CreateActorFromDesc(char *w, const Desc *s);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern void BOX2_SEQ_SetActorDrawPriority(char *p, int i, int c);
extern void BOX2_SEQ_SetActorBgPriority(char *p, int i, int c);
extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);
extern const Desc d_021EFE70;
extern const signed char d_021EFCD0[];
extern const signed char d_021EFCC8[];

static inline void setup(Desc *dp, void **res)
{
    dp->b6 = CLACT_GetActorDrawPriority((int)(*res)) + 1;
    dp->b7 = CLACT_GetActorBgPriority(*res);
}

void BOX2_SEQ_CreateHandSlotActorsB(char *w)
{
    int j;
    Desc d;
    short xy[2];
    if (((struct Obj08247 *)w)->fA16C == 0)
        return;
    j = 0;
    BOX2_SEQ_GetActorSurfacePos(w, 10, &xy[1], &xy[0], 0);
    if (((struct Obj08247 *)w)->f9FD4 == 0) {
        d = d_021EFE70;
        setup(&d, (void **)(w + 0x9E9C));
        d.a = 0x27;
        d.b = 6;
        d.e = 1;
        for (; j < 8u; j++) {
            d.x = xy[1] + d_021EFCD0[j];
            d.y = xy[0] + d_021EFCC8[j];
            *(void **)(w + j * 4 + 0x9FD4) = BOX2_SEQ_CreateActorFromDesc(w, &d);
            CLACT_SetActorPaletteOffset(*(void **)(w + j * 4 + 0x9FD4), (unsigned char)d.e, 1);
            BOX2_SEQ_SetActorDrawEnable(w, j + 0x58, 0);
        }
    } else {
        int n6 = CLACT_GetActorDrawPriority((int)(((struct Obj08247 *)w)->f9E9C));
        int n7 = CLACT_GetActorBgPriority(((struct Obj08247 *)w)->f9E9C);
        for (; j < 8u; j++) {
            BOX2_SEQ_AddActorSurfacePos(w, j + 0x58, (short)(xy[1] + d_021EFCD0[j]), (short)(xy[0] + d_021EFCC8[j]), (short)0);
            BOX2_SEQ_SetActorDrawPriority(w, j + 0x58, n6 + 1);
            BOX2_SEQ_SetActorBgPriority(w, j + 0x58, n7);
            BOX2_SEQ_SetActorDrawEnable(w, j + 0x58, 0);
        }
    }
}
