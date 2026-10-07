/*
 * file:     fldeff_namipoke_p07.c
 * unit:     yes
 * function: func_021AD530, func_021AD564, func_021AD598, func_021AD5CC, func_021AD5E0
 * address:  0x021AD530
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 *   d_021D9170  0x021D9170  data
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   d_021D91F8     0x021D91F8  data  a4
 */
#include "../../matched/include/Obj18088.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct X { u32 f0; u16 h4; u16 h6; u16 h8; u16 ha; u16 hc; } X;

typedef struct Arg { u32 f0; u32 f4; u32 f8; u32 fc; } Arg;

typedef struct Vec {
    int x, y, z;
} Vec;

typedef struct T5 {
    Vec v[5];
} T5;

typedef struct S16 {
    int a, b, c, d;
} S16;

typedef struct Tab {
    int f0;
    u16 h4, h6, h8, ha, hc;
} Tab;

typedef struct Obj {
    Vec v;
    int padc;
    u16 h10;
    u16 pad12;
    S16 s14;
} Obj;

extern u32 func_021ABE18(u8 *p);
extern void func_021C6580(u8 *p, int i);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
extern int func_021AC1E0(u32 a);
extern int func_021AC1AC(u32 a);
extern u16 func_021C6590(int a, int b, int c, int d);
extern void func_021AC1B8(int a, Vec *v);
extern void func_021AC1CC(int a, Vec *v);
void func_021AD530(X *x);
void func_021AD564(u32 a, u32 b, u32 c);
void func_021AD598(u32 a, u32 b, u32 c);
int func_021AD5CC(u32 a);
void func_021AD5E0(int a, int *bp);
extern u8 d_021D9170[];
extern T5 d_021D91F8;


void func_021AD530(X *x)
{
    u32 h = func_021ABE18((u8 *)x->f0);

    func_021C6580((u8 *)h, x->h4);
    func_021C6580((u8 *)h, x->h6);
    func_021C6580((u8 *)h, x->ha);
    func_021C6580((u8 *)h, x->h8);
    func_021C6580((u8 *)h, x->hc);
}


void func_021AD564(u32 a, u32 b, u32 c)
{
    Arg s;

    s.f4 = func_021ABEA0(a, 9);
    s.f8 = b;
    s.fc = c;
    s.f0 = 0;
    func_021ABFA8(a, d_021D9170, 0, 0, &s, 1);
}


void func_021AD598(u32 a, u32 b, u32 c)
{
    Arg s;

    s.f4 = func_021ABEA0(a, 9);
    s.f8 = b;
    s.fc = 0;
    s.f0 = 1;
    func_021ABFA8(a, d_021D9170, c, 0, &s, 1);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AD5CC(u32 a)
{
if (a != 0) {
    return ((struct Obj18088 *)((u8 *)(func_021AC1E0(a))))->fC;
}
return 1;
}


void func_021AD5E0(int a, int *bp)
{
    Obj *b = (Obj *)bp;
    Vec out;
    T5 tab;
    int r;
    int m;
    Tab *t;

    b->s14 = *((S16 *)func_021AC1AC(a));
    t = (Tab *)b->s14.b;
    r = func_021ABE18((u8 *)t->f0);
    switch (b->s14.c) {
    case 0:
        m = ((Tab *)b->s14.b)->h4;
        break;
    case 1:
        m = ((Tab *)b->s14.b)->h6;
        break;
    case 2:
        m = ((Tab *)b->s14.b)->ha;
        break;
    case 3:
        m = ((Tab *)b->s14.b)->h8;
        break;
    case 4:
        m = ((Tab *)b->s14.b)->hc;
        break;
    default:
        goto skip;
    }
    b->h10 = func_021C6590(r, m, 0, 0);
skip:
    if (b->s14.d != 0) {
        tab = d_021D91F8;
        b->v = tab.v[b->s14.c];
        func_021AC1B8(b->s14.d, &out);
        out.x += b->v.x;
        out.y += b->v.y;
        out.z += b->v.z;
        func_021AC1CC(a, &out);
    }
}
