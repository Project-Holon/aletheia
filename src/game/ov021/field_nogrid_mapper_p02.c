/*
 * file:     field_nogrid_mapper_p02.c
 * unit:     yes
 * function: func_021B919C, func_021B91A8, func_021B91AC, func_021B91C8, func_021B91F8, func_021B9238
 * address:  0x021B919C
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
 *   func_021B9164  0x021B9164  thumb  ov021
 *   d_021D9A0C     0x021D9A0C  data  a4
 *   func_021B8820  0x021B8820  thumb  ov021
 *   func_021B8848  0x021B8848  thumb  ov021
 *   func_021B8894  0x021B8894  thumb  ov021
 *   func_021B97D0  0x021B97D0  thumb  ov021
 *   func_021B97FC  0x021B97FC  thumb  ov021
 */
#include "../../matched/include/Obj01358.h"
#include "../../matched/include/Obj18138.h"
#include "../../matched/include/Obj09186.h"
#include "../../matched/include/G_Elem.h"
#include "../../matched/include/Obj00454.h"
#include "../../matched/include/Obj20083.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    char pad[0x10];
    void *f10;
    char pad2[0x28];
    void *f3C;
} Info;

typedef struct {
    u16 h0;
    Info *f4;
    char pad[0x1C];
    void *f24;
} Obj;

typedef struct { u32 a, b, c; } V3;

typedef void (*Fn)(void *, void *);

typedef struct { u16 a; u8 t; u8 c; u16 e; u16 d; } Out;

typedef struct { u16 t; u16 pad; void *p4; int p8; int pc; int p10; int p14; int p18; int p1c; u32 p20; void *p24; } In;

extern void func_021B9164(u8 *p, u32 a, u32 v);
extern void *func_021B8820(void *a, void *b);
u32 *func_021B8848(void *a, u32 b);
Fn func_021B8894(void *a, u32 b);
int func_021B97D0(void *a, void *b);
int func_021B97FC(void *a, void *b);
void func_021B919C(u8 *p, u32 a);
u16 func_021B91A8(u8 *p);
int func_021B91AC(u32 a);
void *func_021B91C8(Obj *p);
void func_021B91F8(u8 *p, V3 *out);
void func_021B9238(const In *p, Out *out);
extern struct Elem d_021D9A0C;


void func_021B919C(u8 *p, u32 a)
{
    func_021B9164(p, a, *(u32 *)&((struct Obj01358 *)p)->f78);
}


u16 func_021B91A8(u8 *p)
{
    return ((struct Obj18138 *)p)->f2;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B91AC(u32 a)
{
if (((struct Obj09186 *)((u8 *)(a)))->f0 < 2) {
    if (((struct Obj09186 *)((u8 *)(a)))->f4 != 0) {
        if (((struct Obj09186 *)((u8 *)(a)))->f2 != 0) {
            return 1;
        }
    }
}
return 0;
}


void *func_021B91C8(Obj *p)
{
    switch (p->h0) {
    case 0:
        return func_021B8820(p->f24, p->f4->f3C);
    case 1:
        return func_021B8820(p->f24, p->f4->f10);
    }
    return &(*(int *)&d_021D9A0C);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021B91F8(u8 *p, V3 *out)
{
    Fn f;

    if (((struct Obj00454 *)p)->f0 == 0) {
        *out = *(V3 *)(*(u8 * *)&((struct Obj00454 *)p)->f4 + 0x30);
        return;
    }
    if (((struct Obj00454 *)p)->f0 == 1) {
        u32 *r = func_021B8848(((struct Obj00454 *)p)->f24, ((struct Obj20083 *)(*(u8 * *)&((struct Obj00454 *)p)->f4))->fC);
        f = func_021B8894(((struct Obj00454 *)p)->f24, *r);
        if (f)
            f(p, out);
    }
}


void func_021B9238(const In *p, Out *out)
{
    int v;
    u32 t;

    t = p->t;
    out->t = t;
    if (t == 0)
        v = func_021B97D0(p->p24, p->p4);
    else
        v = func_021B97FC(p->p24, p->p4);
    out->a = v;
    out->d = p->pc / 16;
    out->e = p->p14 / 16;
    out->c = p->p20;
}
