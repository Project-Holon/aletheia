/*
 * file:     box2_ui_p01.c
 * unit:     yes
 * function: func_021ED824, func_021ED888, func_021ED8A4, func_021ED904, func_021ED918, func_021ED9B4, func_021ED9C8, func_021EDA70, func_021EDAB0, func_021EDB1C, func_021EDB34, func_021EDB64, func_021EDB94, func_021EDBE8, func_021EDC0C
 * address:  0x021ED824
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
 *   d_021EFD1C 0x021EFD1C data a4
 *   func_021EBEE0 0x021EBEE0 thumb ov170
 *   func_021EC000  0x021EC000  thumb  ov170
 *   func_0202CF98 0x0202CF98 thumb
 *   func_021EC08C 0x021EC08C thumb ov170
 *   func_021EC0B0 0x021EC0B0 thumb ov170
 *   func_020258E8 0x020258E8 thumb
 *   func_0202590C 0x0202590C thumb
 *   func_021DEB14 0x021DEB14 thumb ov170
 *   func_021EB874 0x021EB874 thumb ov170
 *   func_02049E34 0x02049E34 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021DEDCC 0x021DEDCC thumb ov170
 *   g_021EFCEC  0x021EFCEC  data  ov170
 *   func_02007A18  0x02007A18  thumb
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_02082A48  0x02082A48  arm
 */
#include "../../matched/include/Obj14281.h"
#include "../../matched/include/Obj24023.h"
#include "../../matched/include/Obj03849.h"
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj24024.h"
#include "../../matched/include/Obj18524.h"

struct WinMgr;
struct Grid;
struct Obj02025774;
struct Personal;
struct Sav;
struct Sub020079BCEntry;
typedef struct { short x, y; int b, c, d, e; short f, g; } Desc;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short   s16;

typedef unsigned short u16;

typedef unsigned char  u8;

extern void *func_021EBEE0(char *, const Desc *);
extern void func_021EC000(char *, int, int);
extern void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern void func_021EC0B0(char *, int, short *, short *, unsigned short);
extern void func_020258E8(struct Obj02025774 *p, s16 *out_x, s16 *out_y);
extern void func_0202590C(struct Grid *g, s16 x, s16 y);
extern unsigned char func_021DEB14(unsigned char *p, int a);
extern void func_021EB874(char **, unsigned, int);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02082D44(const void *, void *, unsigned);
extern u32 func_020307B0(void *p);
extern int func_021DEDCC(char *p, int box);
extern u16 func_0204B7F0(u8 *p);
extern void func_0204AA94(int a, void *b, u32 c, int d, int e);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void *func_0201ADE4(u32 a, int b, u32 c);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern void func_02082A48(u32 value, void *dest, u32 size);
void func_021ED824(char *p);
void func_021ED888(char *p, int a);
void func_021ED8A4(char *p);
void func_021ED904(unsigned char *p);
void func_021ED918(char *p, int d);
void func_021ED9B4(int a);
void func_021ED9C8(char *p);
void func_021EDA70(int a0, int a1, short *a2, short *a3);
void func_021EDAB0(char *p, int i);
void func_021EDB1C(int p);
void func_021EDB34(char *p, int a);
void func_021EDB64(char *p, int a, int i);
void func_021EDB94(char *p, int a, int b);
void func_021EDBE8(int x0, unsigned char *a, unsigned c, unsigned char d, unsigned n);
void func_021EDC0C(int **a, int box, u8 *dest);
extern const Desc d_021EFD1C;
extern const unsigned char g_021EFCEC[];

void func_021ED824(char *p)
{
    Desc t;
    Desc base = d_021EFD1C;
    unsigned i;
    for (i = 0; i < 6; i++) {
        t = base;
        t.y += (short)(i * 0x22);
        t.c = i + 0x39;
        *(void **)(p + i * 4 + 0x9f28) = func_021EBEE0(p, &t);
    }
}

/*
 * Release slots 0 and 1 of the 0x9E74 array.
 */
void func_021ED888(char *p, int a)
{
    func_021EC000(p, 0, a);
    func_021EC000(p, 1, a);
}

void func_021ED8A4(char *p)
{
    signed char t[2];
    unsigned i;
    short x, y;
    func_0202CF98(*(struct WinMgr * *)&((struct Obj24023 *)(*(char * *)&((struct Obj14281 *)p)->f2C))->f74, 7, &t[1], &t[0]);
    i = 0;
    y = t[0] * 8 + 8;
    x = t[1] * 8 + 0x17;
    for (; i < 6; i++)
        func_021EC08C(*(char * *)&((struct Obj14281 *)p)->f2C, i + 0xd, (short)(x + (i % 2) * 0x20), (short)(y + (i / 2) * 0x18), (short)0);
}

/*
 * Seat one entry, then re-sort.
 */
void func_021ED904(unsigned char *p)
{
    func_021EDAB0((char *)p, p[0x14]);
    func_021ED9C8((char *)p);
}

/*
 * extent: Two trailing zero bytes at 0x021ED9B2 are alignment padding.
 */
void func_021ED918(char *p, int d)
{
    short t[2];
    int i = 0;
    func_021EC0B0(*(char * *)&((struct Obj03849 *)p)->f2C, 2, &t[1], &t[0], 0);
    func_021EC08C(*(char * *)&((struct Obj03849 *)p)->f2C, 2, (short)(t[1] - d), (short)t[0], (short)0);
    for (; i < 6u; i++) {
        func_021EC0B0(*(char * *)&((struct Obj03849 *)p)->f2C, i + 0x2d, &t[1], &t[0], 0);
        func_021EC08C(*(char * *)&((struct Obj03849 *)p)->f2C, i + 0x2d, (short)(t[1] - d), (short)t[0], (short)0);
        func_020258E8(*(void **)(*(char * *)&((struct Obj03849 *)p)->f2C + i * 8 + 0xc), &t[1], &t[0]);
        func_0202590C(*(void **)(*(char * *)&((struct Obj03849 *)p)->f2C + i * 8 + 0xc), t[1] - d, t[0]);
    }
}

/*
 * One range call with fixed arguments.
 */
void func_021ED9B4(int a)
{
    func_021EC08C((char *)a, 2, 0x4b * 4, 0x22, 0);
}

void func_021ED9C8(char *p)
{
    Desc t;
    Desc base = d_021EFD1C;
    short i;
    int a, y;
    for (i = 0; i < 6; i++) {
        a = func_021DEB14((unsigned char *)p, (signed char)(i - 1));
        t = base;
        y = i * 0x22;
        t.y += (short)y;
        func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, i + 0x2d, t.x, t.y, 0);
        func_021EDB64(p, a, i + 0x2d);
        func_0202590C(*(void **)(*(char * *)&((struct Obj00000 *)p)->f2C + i * 8 + 0xc), 0x13c, y + 2);
        func_021EB874((char **)p, a, i + 1);
    }
}

/*
 * Scan six 0x2d-spaced panel rows for the (a1+1)*0x22 key and clear
 *   both shorts when nothing matched.  The key must be written as an
 *   ASSIGNMENT TO THE PARAMETER,
 *       a1 = (a1 + 1) * 0x22;
 *   then tested as `if (a1 == a3[0])`.  A separate `int k = ...` local
 *   loses the image's two-instruction parameter home (r6 = a1, r1 =
 *   r6+1, r6 = r1, muls r6) and swaps a2/a3 between r6 and r7.
 */
void func_021EDA70(int a0, int a1, short *a2, short *a3)
{
    unsigned i;
    a1 = (a1 + 1) * 0x22;
    for (i = 0; i < 6; i++) {
        func_021EC0B0((char *)a0, i + 0x2d, a2, a3, 0);
        if (a1 == a3[0])
            return;
    }
    *a2 = 0;
    *a3 = 0;
}

void func_021EDAB0(char *p, int i)
{
    void *t;
    void *q = func_02049E34(0x74, 0x47, 1, (u32)(&t), 0x4c);
    func_02082D44(((struct Obj24024 *)t)->f14, *(char * *)&((struct Obj00000 *)p)->f2C + 0x3e70 + i * 0x400, 0x400);
    func_020307B0(q);
    func_021EDBE8((int)p, (unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + 0x3e70 + i * 0x400), func_021DEDCC((char *)p, i), 8, 0x400);
    func_021EDC0C((int **)p, i, (unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + 0x3e70 + i * 0x400));
}

/*
 * Clear all 24 entries.
 */
void func_021EDB1C(int p)
{
    unsigned i;
    for (i = 0; i < 24; i++)
        func_021EDAB0((char *)p, i);
}

/*
 * Scan channels -1..4 for the one that reports a; on a hit run the
 *   sub-range call with the channel index.  The compared result must live in a
 *   LOCAL, or mwccarm emits `cmp r5,r0` where the image has `cmp r0,r5`.
 */
void func_021EDB34(char *p, int a)
{
    short i;
    for (i = 0; i < 6; i++) {
        unsigned char c = func_021DEB14((unsigned char *)p, (signed char)(i - 1));
        if (c != a)
            continue;
        func_021EDB94(p, a, i);
        return;
    }
}

/*
 * Detach slot i then hand the a*0x400 span of the 0x3E70 pool to
 *   the 0x400/0/0 emitter.
 */
void func_021EDB64(char *p, int a, int i)
{
    int q = ((struct Obj18524 *)p)->f2C;
    int x = func_0204B7F0((u8 *)(*(int *)(q + i * 4 + 0x9E74)));
    func_0204AA94(x, (void *)(q + 0x3E70 + a * 0x400), 0x400, 0, 0);
}

/*
 * extent: Two trailing zero bytes at 0x021EDBE6 are alignment padding.
 */
void func_021EDB94(char *p, int a, int b)
{
    short t[2];
    int i = 0;
    b *= 0x22;
    for (; i < 6u; i++) {
        func_021EC0B0(*(char * *)&((struct Obj00000 *)p)->f2C, i + 0x2d, &t[1], &t[0], 0);
        if (b == t[0]) {
            func_021EDB64(p, a, i + 0x2d);
            func_021EB874((char **)p, a, i + 1);
            return;
        }
    }
}

void func_021EDBE8(int x0, unsigned char *a, unsigned c, unsigned char d, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i++)
        if (a[i] == d)
            a[i] = g_021EFCEC[c];
}


/*
 * lever: the u16 fill value reuses the colour-index local t (t = (u16)((t << 8) | t));
 *   a separate v local takes the spill slot above ty instead of below it.
 */
void func_021EDC0C(int **a, int box, u8 *dest)
{
    void *e;
    u32 sv;
    u8 y, x, tx, ty;
    u8 i;
    u32 sp, t;
    u16 form;
    for (ty = 11, y = 0; y < 5; ty += 2, y++) {
        tx = 10;
        for (x = 0; x < 6; tx += 2, x++) {
            e = func_02007A18((void *)(*a)[1], box, x + y * 6);
            sv = func_02017DBC(e);
            sp = func_02017E88(e, 5, 0);
            if (func_02017E88(e, 0xa9, 0)) {
                if (func_02017E88(e, 0x4c, 0) == 0) {
                    void *pd;
                    form = func_02017E88(e, 0x6f, 0);
                    pd = func_0201ADE4((u16)sp, form, 0x4c);
                    t = (u16)func_0201AE1C(pd, 0x21);
                    func_0201AE14(pd);
                } else {
                    t = (sp == 490) ? 1 : 8;
                }
                t = (u16)(t + 16);
                t = (u16)((t << 8) | t);
                for (i = ty; i < ty + 2; i++)
                    func_02082A48(t, dest + ((((i & 7) << 3) + ((((i >> 3) << 2) + (tx >> 3)) << 6)) + (tx & 7)), 2);
            }
            func_02017DE4(e, sv);
        }
    }
}
