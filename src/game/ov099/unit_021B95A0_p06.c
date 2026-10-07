/*
 * file:     unit_021B95A0_p06.c
 * unit:     yes
 * function: func_021B9D6C, func_021B9DB0, func_021B9DC0, func_021B9DD4, func_021B9DE4, func_021B9DEC, func_021B9DF4, func_021B9DFC, func_021B9E04
 * address:  0x021B9D6C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021C289C     0x021C289C  data  a1
 *   func_021C59F4  0x021C59F4  thumb  ov127
 *   func_021C5A4C  0x021C5A4C  thumb  ov127
 *   func_021B9E50  0x021B9E50  thumb
 *   func_021B9EA0  0x021B9EA0  thumb
 *   func_021B9EB8  0x021B9EB8  thumb
 *   func_021B9F34  0x021B9F34  thumb
 */
#include "../../matched/include/Obj18155.h"

typedef unsigned char u8;

typedef struct {
    u8 b[11];
} Tab;

typedef struct {
    char pad[0x10];
    void *f10;
    char pad14[4];
    void *f18;
    char pad1c[0x598 - 0x1c];
    int f598;
} Obj;

typedef unsigned short u16;

typedef unsigned long  u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

extern int func_021C59F4(void *a, void *b, Tab *t, int x);
extern void func_021C5A4C(u8 *p);
extern void func_021B9E50(void *a, int b, u32 c);
extern void func_021B9EA0(void *a);
extern void func_021B9EB8(void *a, int b);
extern void func_021B9F34(void *a);
void func_021B9D6C(Obj *o, int x, int unused, int c);
void func_021B9DB0(char *p);
void func_021B9DC0(void *a, u32 b, u32 c);
void func_021B9DD4(void *a);
void func_021B9DE4(void *a, int b, u32 c);
void func_021B9DEC(void *a);
void func_021B9DF4(void *a, int b);
void func_021B9DFC(void *a);
void func_021B9E04(void *a, int heap);
extern Tab d_021C289C;


void func_021B9D6C(Obj *o, int x, int unused, int c)
{
    Tab t = d_021C289C;

    t.b[9] += (u8)c;
    o->f598 = func_021C59F4(o->f18, o->f10, &t, x);
}


void func_021B9DB0(char *p)
{
    func_021C5A4C(((struct Obj18155 *)p)->f598);
}


void func_021B9DC0(void *a, u32 b, u32 c)
{
    func_021B9DE4(a, b, c);
    func_021B9DF4(a, b);
}


void func_021B9DD4(void *a)
{
    func_021B9DFC(a);
    func_021B9DEC(a);
}


/*
 * Tail call thunk onto func_021B9E50.
 */
void func_021B9DE4(void *a, int b, u32 c)
{
    func_021B9E50(a, b, c);
}


void func_021B9DEC(void *a)
{
    func_021B9EA0(a);
}


/*
 * Tail call thunk onto func_021B9EB8.
 */
void func_021B9DF4(void *a, int b)
{
    func_021B9EB8(a, b);
}


void func_021B9DFC(void *a)
{
    func_021B9F34(a);
}

/*
 * Empty body: the original is a bare `bx lr`.  disasm.py labels it only
 * because something branches to it.
 */
void func_021B9E04(void *a, int heap)
{
}
