/*
 * file:     bsubway_scr_p14.c
 * unit:     yes
 * function: func_021C92B0, func_021C9314, func_021C9334, func_021C9360, func_021C939C, func_021C93D0, func_021C93E4, func_021C9450, func_021C94AC, func_021C94B4
 * address:  0x021C92B0
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
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_02047504  0x02047504  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047738  0x02047738  arm
 *   func_020478B8  0x020478B8  arm
 *   func_02047910  0x02047910  arm
 *   d_021DAC44  0x021DAC44  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02047AC8  0x02047AC8  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   d_021DE558  0x021DE558  data  ov021  a4
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0218BA04  0x0218BA04  thumb  ov021
 */
#include "../../matched/include/Obj20227.h"
#include "../../matched/include/Obj20228.h"
#include "../../matched/include/Obj12137.h"
#include "../../matched/include/Obj12138.h"

struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Rec;
struct Arg;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef struct S4 { u32 v[4]; } S4;

typedef unsigned short u16;

typedef struct { u32 x, y, z; } V;

typedef struct { u8 pad[0x10]; u8 f10; u8 f11; u8 f12; u8 f13; u32 f14; u32 f18; u32 f1C; u32 f20; u32 f24; u8 pad28[0xc]; u32 f34; u32 f38; } E_021C9314;

typedef struct { u8 pad[0x10]; u8 f10; u8 f11; u8 f12; u8 f13; u32 f14; u32 f18; u32 f1C; u32 f20; u32 f24; u8 pad28[0xc]; u32 f34; u32 f38; } E_021C9334;

typedef struct { u32 a[6]; u32 b[9]; } T;

typedef struct { u8 pad[0x14]; u32 f14; } E_021C9360;

typedef signed short   s16;

typedef signed char    s8;

extern int func_021AC1AC(u32 a);
extern void func_021AC1CC(u32, u32 *);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_0204762C(struct Rec *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern int func_02047910(void *a, int idx, int amount);
extern int func_020478B8(void *a, int idx, int amount);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_0207ADC4(void *p);
extern void func_021AC1B8(u32 a, T *t);
extern int func_02047AC8(void *a0, struct Arg *a1);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern void func_02082D44(void *src, void *dst, int n);
extern void func_0218BA04(u32 a, u32 b, u32 *c, u32 d);
void func_021C92B0(u32 a, u32 *q);
void func_021C9314(void *task, E_021C9314 *e);
void func_021C9334(void *task, E_021C9334 *e);
void func_021C9360(u32 a, E_021C9360 *e);
u32 *func_021C939C(u32 a, u32 heap);
void func_021C93D0(void **q);
void func_021C93E4(u32 a, u8 *q, u32 x, u32 y, u32 z, u32 w, u32 n, u32 cnt);
u32 func_021C9450(u32 a, u32 b, u32 c, u32 d, int e, int f);
int func_021C94AC(u32 a);
int func_021C94B4(u32 a);
extern T d_021DAC44;
extern char d_021DE558[];


/*
 * Addresses are Black-image addresses.
 */
void func_021C92B0(u32 a, u32 *q)
{
    *(S4 *)q = *((S4 *)func_021AC1AC(a));
    func_021AC1CC(a, q + 1);
    q[8] = (u32)func_02047400((void *)(((u32 *)q[0])[3]), 0, (void *)(((u32 *)q[0])[3]));
    q[6] = (u32)func_02047564((struct G3dOwner *)q[8], (const struct G3dOwner *)(((u32 *)q[0])[8]), 0);
    q[7] = (u32)func_02047564((struct G3dOwner *)q[8], (const struct G3dOwner *)(((u32 *)q[0])[9]), 0);
    q[5] = (u32)func_0204767C(q[8], q + 6, 2);
    func_020477A4((struct G3dSys *)q[5], 0);
    func_020477A4((struct G3dSys *)q[5], 1);
}

void func_021C9314(void *task, E_021C9314 *e)
{
    func_0204762C((struct Rec *)e->f18);
    func_0204762C((struct Rec *)e->f1C);
    func_02047738((struct Rec *)e->f14);
    func_02047504((struct Rec *)e->f20);
}

void func_021C9334(void *task, E_021C9334 *e)
{
    func_02047910((void *)e->f14, 0, 0x1000);
    if (e->f10 == 1 && func_020478B8((void *)e->f14, 1, 0x1000) == 0)
        e->f10 = 0;
}

void func_021C9360(u32 a, E_021C9360 *e)
{
    T t = d_021DAC44;
    func_0207ADC4(t.b);
    func_021AC1B8(a, &t);
    func_02047AC8((void *)e->f14, (struct Arg *)(&t));
}

u32 *func_021C939C(u32 a, u32 heap)
{
    u32 *q = func_02030734(heap, 4, 1, d_021DE558, 0x4f);
    q[0] = func_0204A1BC(0x9c, a, 0, heap);
    return q;
}

void func_021C93D0(void **q)
{
    func_020307B0(q[0]);
    func_020307B0(q);
}


void func_021C93E4(u32 a, u8 *q, u32 x, u32 y, u32 z, u32 w, u32 n, u32 cnt)
{
    u8 *t = (u8 *)func_021C94AC(a);
    u8 *qb = q + 4;
    u8 *tb = t + 4;
    u32 i;

    for (i = 0; i < cnt; i++) {
        func_02082D44(tb + (x + (y + i) * ((struct Obj20228 *)t)->f0) * 0x18,
                      qb + (z + (w + i) * ((struct Obj20227 *)q)->f0) * 0x18, n * 0x18);
    }
}


u32 func_021C9450(u32 a, u32 b, u32 c, u32 d, int e, int f)
{
    u32 *t = (u32 *)func_021C94B4(a);
    u32 *e0 = t + 1;
    u32 i;
    u32 loc[4];

    for (i = 0; i < t[0]; i++) {
        func_02082D44(e0 + i * 4, loc, 0x10);
        loc[0] += e << 16;
        loc[2] -= f << 16;
        func_0218BA04(b, c, loc, d + i);
    }
    return d + t[0];
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C94AC(u32 a)
{
return (((struct Obj12137 *)((u8 *)(a)))->f0 + *(u16 *)((u8 *)(((struct Obj12137 *)((u8 *)(a)))->f0)));
}


int func_021C94B4(u32 a)
{
return (((struct Obj12138 *)((u8 *)(a)))->f0 + *(u16 *)((u8 *)(((struct Obj12138 *)((u8 *)(a)))->f0) + 2));
}
