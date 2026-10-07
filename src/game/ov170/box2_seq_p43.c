/*
 * file:     box2_seq_p43.c
 * unit:     yes
 * function: func_021ECFDC, func_021ED028, func_021ED058, func_021ED094, func_021ED108, func_021ED14C, func_021ED164, func_021ED198, func_021ED1C8, func_021ED2F4, func_021ED310, func_021ED370, func_021ED508, func_021ED544, func_021ED55C, func_021ED588, func_021ED594, func_021ED6E4, func_021ED75C, func_021ED7C4
 * address:  0x021ECFDC
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021EC08C 0x021EC08C thumb ov170
 *   func_020490F4 0x020490F4 arm
 *   func_02020E60 0x02020E60 thumb
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_02049238 0x02049238 arm
 *   func_02020F08 0x02020F08 thumb
 *   func_02049E34 0x02049E34 arm
 *   func_0204B7F0 0x0204B7F0 arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049F34 0x02049F34 arm
 *   func_0204B7F8 0x0204B7F8 arm
 *   func_0204ADEC 0x0204ADEC arm
 *   func_0204B570 0x0204B570 arm
 *   func_0204B588 0x0204B588 arm
 *   func_021EC548  0x021EC548  thumb  ov170
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_0204B838 0x0204B838 arm
 *   func_0204B864 0x0204B864 arm
 *   func_021EBEE0 0x021EBEE0 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_021EC048 0x021EC048 thumb
 *   func_021EC030 0x021EC030 thumb
 *   d_021EFE70 0x021EFE70 data a1
 *   d_021EFCD0 0x021EFCD0 data a1
 *   d_021EFCC8 0x021EFCC8 data a1
 *   d_021EFD80 0x021EFD80 data
 *   func_021EBFA8 0x021EBFA8 thumb
 *   func_020260F0 0x020260F0 thumb
 *   func_0204B7C8 0x0204B7C8 arm
 *   func_0204B784 0x0204B784 arm
 *   d_021EFD04 0x021EFD04 data a4
 */
#include "../../matched/include/Obj02214.h"
#include "../../matched/include/Obj14276.h"
#include "../../matched/include/Obj08247.h"
#include "../../matched/include/Obj24020.h"
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj24021.h"
#include "../../matched/include/Obj24022.h"
#include "../../matched/include/Obj08248.h"

#define HND(p) (*(int *)((p) + 0x9E9C))
#define WORK(p) (*(char **)((p) + 0x2C))
#define CELL(w, k) (*(void **)((w) + (k) * 4 + 0x9E74))
struct Sub0204A9D0;
struct Actor;
struct Pt;
struct Obj;
struct Sound;
struct Struct36;
typedef struct {unsigned char low:7;unsigned char high:1;} Flag;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

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
    Desc a[13];
    Desc b[6];
    Desc c[6];
    Desc d[3];
} DescTable;

struct Slot { unsigned char a[0x1c]; unsigned char f : 4; };

typedef struct {
    int w[9];
} Struct36;

extern void func_021EC000(char *, int, int);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern void *func_020490F4(u32 id, u32 heap);
extern unsigned func_02020E60(unsigned,unsigned);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern void func_02049238(void*);
extern unsigned func_02020F08(void);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u16 func_0204B7F0(u8 *p);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern u32 func_020307B0(void *p);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern u16 func_0204B7F8(u8 *p);
extern void func_0204ADEC(void *dst, void *src, unsigned flag);
extern void func_0204B588(struct Actor *actor, const struct Pt *src);
extern void func_0204B570(struct Actor *actor, u32 value);
extern void func_021EC548(unsigned i, short *x, short *y, int mode);
extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern int func_0204B838(int a0);
extern u32 func_0204B864(u8 *a0);
extern void *func_021EBEE0(char *w, const Desc *s);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_021EC048(char *p, int i, int c);
extern void func_021EC030(char *p, int i, int c);
extern void func_021EBFA8(char *w, int i, int v);
extern u32 func_020260F0(struct Sound *obj);
extern void func_0204B7C8(const char *src, struct Struct36 *dst);
extern void func_0204B784(char *dst, const struct Struct36 *src);
void func_021ECFDC(char *p, int a, int b);
void func_021ED028(char *p,unsigned char *q);
void func_021ED058(u8*p);
void func_021ED094(char *w, unsigned item);
void func_021ED108(char *p, int on);
void func_021ED14C(int a, int b, int c);
void func_021ED164(char *p, int a, int c);
void func_021ED198(char *p, int a, int c);
void func_021ED1C8(char *w);
void func_021ED2F4(char *p);
void func_021ED310(char *w);
void func_021ED370(unsigned char *p);
void func_021ED508(unsigned char *p, int a, int b);
void func_021ED544(char *p, int b);
void func_021ED55C(char **p, int flag);
void func_021ED588(char *p);
void func_021ED594(char *p, unsigned i);
void func_021ED6E4(char **p, int v);
void func_021ED75C(char **p, int i);
void func_021ED7C4(char *p, int i);
extern const Desc d_021EFE70;
extern const signed char d_021EFCD0[];
extern const signed char d_021EFCC8[];
extern const DescTable d_021EFD80;
extern const Desc d_021EFD04;

void func_021ECFDC(char *p, int a, int b)
{
    int k = a + 0x1c;
    func_021EC000(p, k, 1);
    func_021EC08C(p, k, 0x58, 0x38, 1);
    if (b != 0 && a != b) {
        k = b + 0x1c;
        func_021EC000(p, k, 1);
        func_021EC08C(p, k, 0x7a, 0x38, 1);
    }
}

/*
 * lever: Byte bitfield access reproduces the original ldrb/lsl24/lsr31
 * at 0x021ED042..0x021ED046; a mask test emitted movs/tst instead.
 */
void func_021ED028(char *p,unsigned char *q){unsigned i;for(i=28;i<45;i++)func_021EC000(p,i,0);if(!((Flag *)(q+18))->high)func_021ECFDC(p,q[12],q[13]);}

void func_021ED058(u8*p){void*h;h=func_020490F4(25,76);*(void* *)&((struct Obj02214 *)p)->fA114=(void *)func_0204ABF0(h,func_02020E60(0,2),0,0x180,76);func_02049238(h);}


void func_021ED094(char *w, unsigned item)
{
    void *a;
    void *b;
    void *q;
    q = func_02049E34(func_02020F08(), func_02020E60(item, 1), 0, (u32)(&a), 0x4C);
    func_0204A9D0(func_0204B7F0(((struct Obj14276 *)w)->f9E9C), a);
    func_020307B0(q);
    q = func_02049F34(func_02020F08(), func_02020E60(item, 2), (u32)(&b), 0x4C);
    func_0204ADEC((void *)func_0204B7F8(((struct Obj14276 *)w)->f9E9C), b, 1);
    func_020307B0(q);
}


void func_021ED108(char *p, int on)
{
    unsigned short s[2];
    if (on == 1) {
        func_0204B570((struct Actor *)HND(p), 1);
        s[0] = 0xC;
        s[1] = 0xC;
        func_0204B588((struct Actor *)HND(p), (const struct Pt *)s);
    } else {
        s[0] = 0;
        s[1] = 0;
        func_0204B588((struct Actor *)HND(p), (const struct Pt *)s);
        func_0204B570((struct Actor *)HND(p), 0);
    }
}

/*
 * One range call with the sub-range selector.
 */
void func_021ED14C(int a, int b, int c)
{
    func_021EC08C((char *)a, 10, b, c, 0);
}

/*
 * Twin of func_021ED198 with both shorts biased by 8.
 */
void func_021ED164(char *p, int a, int c)
{
    short t[2];
    func_021EC548(a, t + 1, t, c);
    func_021ED14C((int)p, (short)(t[1] + 8), (short)(t[0] + 8));
}

/*
 * Read the 2-short record for the sub-range then push it back with
 *   the first element biased by 4.
 */
void func_021ED198(char *p, int a, int c)
{
    short t[2];
    func_021EC548(a, t + 1, t, c);
    func_021ED14C((int)p, t[1], (short)(t[0] + 4));
}


static inline void setup(Desc *dp, void **res)
{
    dp->b6 = func_0204B838((int)(*res)) + 1;
    dp->b7 = func_0204B864(*res);
}


/*
 * Sibling of src/matched/ov/ov170_func_021ED594.c: builds (or moves) the
 * eight frame pieces around window 10 while the count at 0xA16C is nonzero.
 * The index is an int compared against 8u (docs/idioms/a-signed-index-under-an-unsigned-bound-keeps-the-window-sum-uncached.md).
 */
void func_021ED1C8(char *w)
{
    int j;
    Desc d;
    short xy[2];
    if (((struct Obj08247 *)w)->fA16C == 0)
        return;
    j = 0;
    func_021EC0B0(w, 10, &xy[1], &xy[0], 0);
    if (((struct Obj08247 *)w)->f9FD4 == 0) {
        d = d_021EFE70;
        setup(&d, (void **)(w + 0x9E9C));
        d.a = 0x27;
        d.b = 6;
        d.e = 1;
        for (; j < 8u; j++) {
            d.x = xy[1] + d_021EFCD0[j];
            d.y = xy[0] + d_021EFCC8[j];
            *(void **)(w + j * 4 + 0x9FD4) = func_021EBEE0(w, &d);
            func_0204B6F4(*(void **)(w + j * 4 + 0x9FD4), (unsigned char)d.e, 1);
            func_021EC000(w, j + 0x58, 0);
        }
    } else {
        int n6 = func_0204B838((int)(((struct Obj08247 *)w)->f9E9C));
        int n7 = func_0204B864(((struct Obj08247 *)w)->f9E9C);
        for (; j < 8u; j++) {
            func_021EC08C(w, j + 0x58, (short)(xy[1] + d_021EFCD0[j]), (short)(xy[0] + d_021EFCC8[j]), (short)0);
            func_021EC048(w, j + 0x58, n6 + 1);
            func_021EC030(w, j + 0x58, n7);
            func_021EC000(w, j + 0x58, 0);
        }
    }
}

/*
 * Loop 8 entries forwarding (i+0x58, 1).
 */
void func_021ED2F4(char *p)
{
    unsigned i;
    for (i = 0; i < 8; i++)
        func_021EC000(p, i + 0x58, 1);
}


void func_021ED310(char *w)
{
    short xy[2];
    unsigned i;
    if (((struct Obj24020 *)w)->f9FD4 != 0) {
        i = 0;
        func_021EC0B0(w, 0xA, &xy[1], &xy[0], 0);
        for (; i < 8; i++)
            func_021EC08C(w, i + 0x58, (short)(xy[1] + d_021EFCD0[i]), (short)(xy[0] + d_021EFCC8[i]), (short)0);
    }
}


/*
 * Builds the cell objects of the box screen from the descriptor table
 * at 0x021EFD80 into the work slots at 0x9E74, hides five of them, then
 * refreshes the cursor.  The loop rows are addressed as a byte offset
 * (i * 0x18 + 0x138) from the table base: both the member form .b[i] and
 * the index form [i + 13] fold the row offset into the literal instead.
 */
void func_021ED370(unsigned char *p)
{
    char *w = WORK(p);
    unsigned i;

    CELL(w, 0) = func_021EBEE0(w, &d_021EFD80.a[0]);
    CELL(w, 1) = func_021EBEE0(w, &d_021EFD80.a[1]);
    CELL(w, 2) = func_021EBEE0(w, &d_021EFD80.a[2]);
    CELL(w, 3) = func_021EBEE0(w, &d_021EFD80.a[3]);
    CELL(w, 4) = func_021EBEE0(w, &d_021EFD80.a[4]);
    CELL(w, 5) = func_021EBEE0(w, &d_021EFD80.a[5]);
    CELL(w, 10) = func_021EBEE0(w, &d_021EFD80.a[10]);
    CELL(w, 6) = func_021EBEE0(w, &d_021EFD80.a[6]);
    CELL(w, 7) = func_021EBEE0(w, &d_021EFD80.a[7]);
    CELL(w, 8) = func_021EBEE0(w, &d_021EFD80.a[8]);
    CELL(w, 9) = func_021EBEE0(w, &d_021EFD80.a[9]);
    for (i = 0; i < 6; i++) {
        *(void **)(w + i * 4 + 0x9EA8) = func_021EBEE0(w, (const Desc *)((const char *)&d_021EFD80 + (i * 0x18 + 0x138)));
        *(void **)(w + i * 4 + 0x9EC0) = func_021EBEE0(w, (const Desc *)((const char *)&d_021EFD80 + (i * 0x18 + 0x1C8)));
    }
    CELL(w, 25) = func_021EBEE0(w, &d_021EFD80.d[0]);
    CELL(w, 26) = func_021EBEE0(w, &d_021EFD80.d[1]);
    CELL(w, 27) = func_021EBEE0(w, &d_021EFD80.d[2]);
    func_021EC000(w, 5, 0);
    func_021EC000(w, 10, 0);
    func_021EC000(w, 0x19, 0);
    func_021EC000(w, 0x1A, 0);
    func_021EC000(w, 0x1B, 0);
    func_021ED508(p, 0xE, 1);
}


/*
 * Sets window 9's frame and mode; outside modes 2, 3 and 4 the mode is
 * cleared again.
 */
void func_021ED508(unsigned char *p, int a, int b)
{
    int kind;
    func_021EBFA8(WORK(p), 9, a);
    func_021EC000(WORK(p), 9, b);
    kind = ((struct Obj24021 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24;
    if (kind != 2 && kind != 4 && kind != 3)
        func_021EC000(WORK(p), 9, 0);
}

/*
 * Offset by four when the low nibble of 0x1c is set.
 */
void func_021ED544(char *p, int b)
{
    if (((struct Slot *)p)->f)
        b += 4;
    func_021EBFA8(*(char * *)&((struct Obj00000 *)p)->f2C, 4, b);
}


void func_021ED55C(char **p, int flag)
{
    if (flag == 1) {
        if (func_020260F0(((struct Obj24022 *)(p[11]))->f70) == 1)
            func_021EC000(p[11], 4, 1);
    } else {
        func_021EC000(p[11], 4, 0);
    }
}


/*
 * Forward with the byte field at +0x16.
 */
void func_021ED588(char *p)
{
    func_021ED594(p, ((struct Obj00000 *)p)->f16);
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
        func_0204B7C8(((void **)(w + 0x9E74))[c], (struct Struct36 *)(&buf));
        n6 = func_0204B838((int)(((void **)(w + 0x9E74))[c]));
        n7 = func_0204B864(((void **)(w + 0x9E74))[c]);
        for (; j < 8; j++) {
            func_0204B784(*(void **)(w + j * 4 + 0x9FD4), (const struct Struct36 *)(&buf));
            func_021EC08C(w, j + 0x58, (short)(xy[1] + d_021EFCD0[j]), (short)(xy[0] + d_021EFCC8[j]), (short)0);
            func_021EC048(w, j + 0x58, n6 + 1);
            func_021EC030(w, j + 0x58, n7);
            func_021EC000(w, j + 0x58, 1);
        }
    }
}


void func_021ED6E4(char **p, int v)
{
    int j;
    for (j = 0; j < 8u; j++) {
        if (*(int *)(p[11] + j * 4 + 0x9FD4) != 0) {
            func_021EC000(p[11], j + 0x58, v);
            if (v == 1 && ((unsigned char *)p)[0x16] != 0xFF) {
                unsigned char k = *(unsigned char *)(p[11] + ((unsigned char *)p)[0x16] + 0x3DD2);
                func_021EC048(p[11], j + 0x58, func_0204B838(*(int *)(p[11] + k * 4 + 0x9E74)) + 1);
                func_021EC030(p[11], j + 0x58, func_0204B864((u8 *)(*(int *)(p[11] + k * 4 + 0x9E74))));
            }
        }
    }
}


void func_021ED75C(char **p, int i)
{
    unsigned char k = *(unsigned char *)(p[11] + i + 0x3DD2);
    int a = func_0204B838(*(int *)(p[11] + k * 4 + 0x9E74));
    int b = func_0204B864((u8 *)(*(int *)(p[11] + k * 4 + 0x9E74)));
    int j;
    for (j = 0; j < 8u; j++) {
        if (*(int *)(p[11] + j * 4 + 0x9FD4) != 0 && ((unsigned char *)p)[0x16] != 0xFF) {
            func_021EC048(p[11], j + 0x58, a + 1);
            func_021EC030(p[11], j + 0x58, b);
        }
    }
}


void func_021ED7C4(char *p, int i)
{
    short xy[2];
    int j;
    if (i == 0xFF)
        return;
    j = 0;
    func_021EC0B0(p, *(unsigned char *)(p + i + 0x3DD2), &xy[1], &xy[0], j);
    for (; j < 8u; j++)
        func_021EC08C(p, j + 0x58, (short)(xy[1] + d_021EFCD0[j]), (short)(xy[0] + d_021EFCC8[j]), (short)0);
}
