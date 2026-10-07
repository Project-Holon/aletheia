/*
 * file:     bsubway_scr_p06.c
 * unit:     yes
 * function: func_021C8C88, func_021C8CF0, func_021C8CF8, func_021C8D08, func_021C8D18
 * address:  0x021C8C88
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
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_02006148  0x02006148  thumb
 *   func_021C8BFC  0x021C8BFC  thumb
 *   func_021C8BC4  0x021C8BC4  thumb
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 */
#include "../../matched/include/Obj12135.h"
#include "../../matched/include/Obj12136.h"

struct Desc;
struct Obj;
struct Obj00020;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

struct Work8C88 {
    void *sys;
    u8 *owner;
    u8 *f8;
    void *fC;
    u32 f10;
    u32 f14;
    u32 f18;
    int f1C;
    int f20;
    int f24;
};

typedef int (*TaskFn)(void *task, int *state, void *work);

typedef signed char    s8;

typedef struct { u32 x, y, z; } V;

typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; } P;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern int func_02006148(u32 a0);
extern int func_021C8BFC(int a, int *st, int *p);
extern int func_021C8BC4(u32 a);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern u32 func_02188C98(u8 *p);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F0(u32 a);
void *func_021C8C88(u32 prio, void *sys, struct Obj00020 *owner);
int func_021C8CF0(u32 a);
int func_021C8CF8(u32 a);
int func_021C8D08(u32 a);
u16 func_021C8D18(P *p);


/*
 * Creates task func_021C8BFC with a 0x28 byte work area, fills it from the
 * owner, and loads three resources (0x55E, 0x6E2, 0x769) through
 * func_02006148.
 *
 * Addresses are Black-image addresses.
 */
void *func_021C8C88(u32 prio, void *sys, struct Obj00020 *owner)
{
    void *v = func_02188CB4(owner);
    void *task = func_020122C0(sys, (void *)prio, (TaskFn)func_021C8BFC, 0x28);
    struct Work8C88 *w = func_020124E8(task);

    w->sys = sys;
    w->owner = (u8 *)owner;
    w->f8 = (u8 *)v;
    w->fC = func_021A3074(w->f8);
    w->f10 = 0;
    w->f14 = 0;
    w->f18 = 0;
    w->f1C = func_02006148(0x55E);
    w->f20 = func_02006148(0x6E2);
    w->f24 = func_02006148(0x769);
    return task;
}


/*
 * Tail-call thunk: forwards to func_021C8BC4 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_021C8CF0(u32 a)
{
    return func_021C8BC4(a);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C8CF8(u32 a)
{
if (((struct Obj12135 *)((u8 *)(a)))->f10 != 0) {
    return *(u16 *)((u8 *)(((struct Obj12135 *)((u8 *)(a)))->f10) + 2);
}
return 0;
}


int func_021C8D08(u32 a)
{
if (((struct Obj12136 *)((u8 *)(a)))->f14 != 0) {
    return *(u16 *)((u8 *)(((struct Obj12136 *)((u8 *)(a)))->f14) + 2);
}
return 0;
}

u16 func_021C8D18(P *p)
{
    V t;
    func_021A3038((unsigned char *)p->f8, (struct VecFx32 *)&t);
    return func_021AB0F0(func_021AB0D4((void *)func_02188C98((u8 *)p->f4), &t));
}
