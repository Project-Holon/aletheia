/*
 * function: func_021ED594
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
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_0204B838 0x0204B838 arm
 *   func_0204B864 0x0204B864 arm
 *   func_021EBEE0 0x021EBEE0 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B7C8 0x0204B7C8 arm
 *   func_0204B784 0x0204B784 arm
 *   func_021EC08C 0x021EC08C thumb
 *   func_021EC048 0x021EC048 thumb
 *   func_021EC030 0x021EC030 thumb
 *   func_021EC000 0x021EC000 thumb
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

extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern int func_0204B838(void *a);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
extern u32 func_0204B864(u8 *a0);
extern void *func_021EBEE0(char *w, const Desc *s);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B7C8(void *src, Struct36 *dst);
extern void func_0204B784(void *dst, const Struct36 *src);
extern void func_021EC08C(char *p, int i, short a, short b, short c);
extern void func_021EC048(char *p, int i, int c);
extern void func_021EC030(char *p, int i, int c);
extern void func_021EC000(char *p, int i, int v);
extern const Desc d_021EFD04;
extern const signed char d_021EFCD0[];
extern const signed char d_021EFCC8[];

static inline void setup(Desc *dp, void **res)
{
    dp->b6 = func_0204B838(*res) + 1;
    dp->b7 = func_0204B864(*res);
}

void func_021ED594(char *p, unsigned i)
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
    func_021EC0B0(w, c, &xy[1], &xy[0], 0);
    if (((struct Obj08248 *)w)->f9FD4 == 0) {
        d = d_021EFD04;
        setup(&d, &((void **)(w + 0x9E74))[c]);
        d.a = c - 0x33;
        d.b = 6;
        d.e = 1;
        for (; j < 8; j++) {
            d.x = xy[1] + d_021EFCD0[j];
            d.y = xy[0] + d_021EFCC8[j];
            *(void **)(w + j * 4 + 0x9FD4) = func_021EBEE0(w, &d);
            func_0204B6F4(*(void **)(w + j * 4 + 0x9FD4), (unsigned char)d.e, 1);
        }
    } else {
        int n6;
        int n7;
        func_0204B7C8(((void **)(w + 0x9E74))[c], &buf);
        n6 = func_0204B838(((void **)(w + 0x9E74))[c]);
        n7 = func_0204B864(((void **)(w + 0x9E74))[c]);
        for (; j < 8; j++) {
            func_0204B784(*(void **)(w + j * 4 + 0x9FD4), &buf);
            func_021EC08C(w, j + 0x58, xy[1] + d_021EFCD0[j], xy[0] + d_021EFCC8[j], 0);
            func_021EC048(w, j + 0x58, n6 + 1);
            func_021EC030(w, j + 0x58, n7);
            func_021EC000(w, j + 0x58, 1);
        }
    }
}
