/*
 * file:     bsubway_scr_p04.c
 * unit:     yes
 * function: func_021C8A7C, func_021C8A8C, func_021C8A9C, func_021C8AAC, func_021C8AD0, func_021C8B14, func_021C8B48, func_021C8B5C, func_021C8B78
 * address:  0x021C8A7C
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
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   _u32_div_f     0x0209C2B0  arm
 *   func_02006148  0x02006148  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02006224  0x02006224  thumb
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021C8984  0x021C8984  thumb  ov021
 *   func_021639C0  0x021639C0  thumb  ov010
 */
#include "../../matched/include/Obj00876.h"
#include "../../matched/include/Obj12134.h"

struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u32 x, y, z; } V;

typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; } P;

extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern u32 func_02188C98(u8 *p);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F0(u32 a);
extern u32 *func_0216D550(u32 *p, u32 v);
extern void func_0216D5E0(int a, int b);
extern u32 *func_0216D548(u32 *p, u32 v);
extern void func_0216D410(u32 a, u32 b);
extern int func_02006148(u32 a0);
extern int func_02006224(u32 a0);
extern void func_020061E4(u32 id);
extern void *func_021C8984(u16 id);
extern u32 func_021639C0(u32, u32);
int func_021C8A7C(u32 a);
int func_021C8A8C(u32 a);
int func_021C8A9C(u32 a);
u16 func_021C8AAC(P *p);
void func_021C8AD0(int *p);
void func_021C8B14(P *p);
void func_021C8B48(P *p);
int func_021C8B5C(u32 a);
void func_021C8B78(P *p);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C8A7C(u32 a)
{
if (*(u32 *)&((struct Obj00876 *)((u8 *)(a)))->f10 != 0) {
    return *(u16 *)((u8 *)(*(u32 *)&((struct Obj00876 *)((u8 *)(a)))->f10) + 2);
}
return 0;
}


int func_021C8A8C(u32 a)
{
if (*(u32 *)&((struct Obj00876 *)((u8 *)(a)))->f10 != 0) {
    return *(u16 *)((u8 *)(*(u32 *)&((struct Obj00876 *)((u8 *)(a)))->f10) + 4);
}
return 0;
}


int func_021C8A9C(u32 a)
{
if (((struct Obj12134 *)((u8 *)(a)))->f10 != 0) {
    return *(u16 *)((u8 *)(((struct Obj12134 *)((u8 *)(a)))->f10) + 6);
}
return 0;
}

u16 func_021C8AAC(P *p)
{
    V t;
    func_021A3038((unsigned char *)p->f8, (struct VecFx32 *)&t);
    return func_021AB0F0(func_021AB0D4((void *)func_02188C98((u8 *)p->f4), &t));
}


void func_021C8AD0(int *p)
{
    int d = func_021C8A9C((u32)p);

    ((struct Obj00876 *)p)->f18 = ((struct Obj00876 *)p)->f18 + 1;
    if (((struct Obj00876 *)p)->f18 % d == 0) {
        ((struct Obj00876 *)p)->f14 = (((struct Obj00876 *)p)->f14 + 1) % 4;
        func_0216D550((u32 *)(*(int *)&((struct Obj00876 *)p)->fC), 8);
        func_0216D5E0(*(int *)&((struct Obj00876 *)p)->fC, ((struct Obj00876 *)p)->f14);
        func_0216D548((u32 *)(*(int *)&((struct Obj00876 *)p)->fC), 8);
    }
}

void func_021C8B14(P *p)
{
    func_0216D410(p->fC, func_021C8A7C((u32)p));
    func_0216D548((u32 *)p->fC, 8);
    if (func_02006224(func_02006148(0x694)) == 0)
        func_020061E4(0x694);
}

void func_021C8B48(P *p)
{
    void *e = func_021C8984(func_021C8AAC(p));
    if (e != 0)
        p->f10 = e;
}


int func_021C8B5C(u32 a)
{
if (func_021639C0(((struct Obj00876 *)((u8 *)(a)))->fC, func_021C8A8C(a)) != 0) {
    return 1;
}
return 0;
}

void func_021C8B78(P *p)
{
    func_0216D550((u32 *)p->fC, 8);
    if (p->f10 != 0)
        func_0216D5E0(p->fC, func_021C8A8C((u32)p));
}
