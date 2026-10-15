/*
 * function: BOX2_SEQ_MoveCursorActor
 * address:  0x021ED594
 * packet:   pkt_ov170_021ED594
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
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   CLACT_SetActorImageProxy 0x0204B784 arm
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb
 *   BOX2_SEQ_SetActorDrawPriority 0x021EC048 thumb
 *   BOX2_SEQ_SetActorBgPriority 0x021EC030 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   d_021EFD04 0x021EFD04 data a4
 *   d_021EFCD0 0x021EFCD0 data a1
 *   d_021EFCC8 0x021EFCC8 data a1
 */
#include "../include/Obj00000.h"
#include "../include/Obj08248.h"

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

typedef struct {
    int w[9];
} Struct36;

extern void BOX2_SEQ_GetActorSurfacePos(char *p, int i, short *a, short *b, unsigned short space);
extern int CLACT_GetActorDrawPriority(int a0);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
extern u32 CLACT_GetActorBgPriority(u8 *a0);
extern void *BOX2_SEQ_CreateActorFromDesc(char *w, const Desc *s);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
struct Struct36;
extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);
extern void CLACT_SetActorImageProxy(char *dst, const struct Struct36 *src);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern void BOX2_SEQ_SetActorDrawPriority(char *p, int i, int c);
extern void BOX2_SEQ_SetActorBgPriority(char *p, int i, int c);
extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);
extern const Desc d_021EFD04;
extern const signed char d_021EFCD0[];
extern const signed char d_021EFCC8[];

static inline void setup(Desc *dp, void **res)
{
    dp->b6 = CLACT_GetActorDrawPriority((int)(*res)) + 1;
    dp->b7 = CLACT_GetActorBgPriority(*res);
}

void BOX2_SEQ_MoveCursorActor(char *p, unsigned i)
{
    char *w;
    unsigned c;
    unsigned short j;
    Desc d;
    Struct36 buf;
    short xy[2];
    if (i == 0xFF)
        return;
    w = *(char * *)&((struct Obj00000 *)p)->f2C;
    c = *(unsigned char *)(w + i + 0x3DD2);
    j = 0;
    BOX2_SEQ_GetActorSurfacePos(w, c, &xy[1], &xy[0], 0);
    if (((struct Obj08248 *)w)->f9FD4 == 0) {
        d = d_021EFD04;
        setup(&d, &((void **)(w + 0x9E74))[c]);
        d.a = c - 0x33;
        d.b = 6;
        d.e = 1;
        for (; j < 8; j++) {
            d.x = xy[1] + d_021EFCD0[j];
            d.y = xy[0] + d_021EFCC8[j];
            *(void **)(w + j * 4 + 0x9FD4) = BOX2_SEQ_CreateActorFromDesc(w, &d);
            CLACT_SetActorPaletteOffset(*(void **)(w + j * 4 + 0x9FD4), (unsigned char)d.e, 1);
        }
    } else {
        int n6;
        int n7;
        CLACT_GetActorImageProxy(((void **)(w + 0x9E74))[c], (struct Struct36 *)(&buf));
        n6 = CLACT_GetActorDrawPriority((int)(((void **)(w + 0x9E74))[c]));
        n7 = CLACT_GetActorBgPriority(((void **)(w + 0x9E74))[c]);
        for (; j < 8; j++) {
            CLACT_SetActorImageProxy(*(void **)(w + j * 4 + 0x9FD4), (const struct Struct36 *)(&buf));
            BOX2_SEQ_AddActorSurfacePos(w, j + 0x58, (short)(xy[1] + d_021EFCD0[j]), (short)(xy[0] + d_021EFCC8[j]), (short)0);
            BOX2_SEQ_SetActorDrawPriority(w, j + 0x58, n6 + 1);
            BOX2_SEQ_SetActorBgPriority(w, j + 0x58, n7);
            BOX2_SEQ_SetActorDrawEnable(w, j + 0x58, 1);
        }
    }
}
