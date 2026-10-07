/*
 * file:     bsubway_scr_p08.c
 * unit:     yes
 * function: func_021C8DE4, func_021C8DF4, func_021C8E14, func_021C8E30, func_021C8E5C
 * address:  0x021C8DE4
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
 *   func_021A2F98  0x021A2F98  thumb  ov021
 *   func_021ACBC8  0x021ACBC8  thumb  ov021
 *   func_02005C64  0x02005C64  thumb
 *   func_0200616C  0x0200616C  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_02006224  0x02006224  thumb
 */
#include "../../matched/include/Obj18342.h"
#include "../../matched/include/Obj18343.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; void *f14; u32 f18; u32 f1C; u32 f20; u32 f24; } P;

extern u32 func_021A2F98(u8 *p);
extern u32 func_021ACBC8(u32, u32);
extern int func_02005C64(void);
extern void func_020061F8(int i);
extern void func_0200616C(void *arg, int i);
extern int func_02006224(u32 h);
int func_021C8DE4(u32 a);
void func_021C8DF4(P *p);
void func_021C8E14(P *p);
void func_021C8E30(P *p);
void func_021C8E5C(int *p);


int func_021C8DE4(u32 a)
{
return func_021ACBC8(func_021A2F98((u8 *)(((struct Obj18342 *)((u8 *)(a)))->f8)), 1);
}

void func_021C8DF4(P *p)
{
    if (func_02005C64() == 0) {
        func_020061F8(p->f24);
        func_0200616C((void *)0x55e, p->f1C);
    }
}

void func_021C8E14(P *p)
{
    if (func_02005C64() == 0)
        func_0200616C((void *)0x6e2, p->f20);
}

void func_021C8E30(P *p)
{
    if (func_02005C64() == 0 && p->f18 == 0 && func_02006224(p->f24) == 0)
        func_0200616C((void *)0x769, p->f24);
}


/*
 * Tail-call thunk: the object's word at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void func_021C8E5C(int *p)
{
    func_020061F8(((struct Obj18343 *)p)->f24);
}
