/*
 * file:     unit_06899BE0.c
 * unit:     yes
 * function: func_06899BE0, func_06899CA4
 * address:  0x06899BE0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02043598  0x02043598  arm
 *   func_021B8588  0x021B8588  thumb
 *   func_021B86B8  0x021B86B8  thumb
 *   func_021B8748  0x021B8748  thumb
 *   func_021F86E0  0x021F86E0  thumb
 *   func_0220207C  0x0220207C  thumb
 *   func_022025D8  0x022025D8  thumb
 *   func_06899D38  0x06899D38  thumb  ov095
 */
#include "../../matched/include/Obj07907.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Obj {
    u8 pad0[8];
    int f08;
    u8 pad0c[0x8f - 0x0c];
    u8 f8f;
    u8 f90;
    u8 pad91[0xa0 - 0x91];
    int fa0;
    u8 pada4[0xac - 0xa4];
    u16 fac;
    u8 padae[2];
    int fb0;
} Obj;

typedef signed char s8;

extern int func_021B8748(int a);
extern int func_021B8588(int a);
extern int func_021B86B8(int a);
extern int func_021F86E0(void);
extern int func_0220207C(int a, int b, int c, int d, int e, u8 *f, int g, int h);
extern void func_02043598(int a, int b);
extern void func_06899D38(Obj *o);
extern int func_022025D8(u32, u32);
void func_06899BE0(Obj *o);
void func_06899CA4(const s8 *p, u32 a);


void func_06899BE0(Obj *o)
{
    int a;
    int b;
    int c;
    int d;

    a = func_021B8748(o->fa0);
    b = func_021B8588(o->fa0);
    c = func_021B86B8(o->fa0);
    d = func_021F86E0();
    o->fb0 = func_0220207C(a, b, c, d, o->f08, &o->f8f, o->f90, o->fac);
    func_02043598(0x10, 1);
    func_06899D38(o);
}

void func_06899CA4(const s8 *p, u32 a)
{
    enum { ZERO = 0 } zero = ZERO;
    ((struct Obj07907 *)p)->f8C = zero;
    ((struct Obj07907 *)p)->f8D = -16;
    ((struct Obj07907 *)p)->f8E = zero - 1;
    func_022025D8(*(const u32 *)&((struct Obj07907 *)p)->fB0, a);
}
