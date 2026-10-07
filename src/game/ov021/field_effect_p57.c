/*
 * file:     field_effect_p57.c
 * unit:     yes
 * function: func_021AC384, func_021AC3A4, func_021AC3F8, func_021AC494, func_021AC4B8, func_021AC4CC, func_021AC514, func_021AC528
 * address:  0x021AC384
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
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D98C  0x0216D98C  thumb  ov010
 *   func_0216DAB4  0x0216DAB4  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D92C  0x0216D92C  thumb  ov010
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_0204F720  0x0204F720  arm
 *   func_0204F638  0x0204F638  arm
 *   d_021DE038  0x021DE038  data
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D90AC     0x021D90AC  data  a4
 */
#include "../../matched/include/Obj07513.h"
#include "../../matched/include/Obj12096.h"

struct BbActSys;
struct Trip;
struct Actor;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct H { u32 f0, f4, f8, fc, f10; } H;

typedef struct W { u32 f0; H *h; u32 f8, fc, f10; u32 f14; } W;

typedef int            s32_021AC3F8;

typedef struct Vec3 { s32_021AC3F8 x, y, z; } Vec3;

typedef struct P { u32 f0; u32 f4; } P;

typedef signed int     s32_021AC4B8;

typedef int            s32_021AC528;

typedef struct Arg { u32 a; Vec3 v; } Arg;

extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern int func_0216E1C4(int a0, int a1);
extern void *func_0216D67C(void *a0);
extern int func_0216D98C(int a0);
extern int func_0216DAB4(void *a0);
extern u32 func_0216D57C(void *p, u32 v);
extern void func_021AC154(u32 a);
extern void *func_0216E3C4(void *p);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
extern void func_0216D92C(u8 *p, s32_021AC3F8 *q);
extern void func_0207C9D0(Vec3 *a, Vec3 *b, Vec3 *c);
extern void func_0216D8B0(u8 *p, u8 *q);
extern void func_0204F720(void *p, u32 idx, u32 *flag);
extern void func_0204F638(u8 *a0, int i, struct Trip *src);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_021ABE18(u8 *p);
extern u32 func_021ABE24(u8 *p);
extern void func_021C6AE0(u32 a);
extern int func_021C6AF0(u32 a, u32 b, u32 c);
extern void func_021C6AF8(u32 *p, u32 v);
extern void func_021C6AFC(u32 *a, u32 b);
extern int func_021C6574(u32 a, u32 b, u32 c);
extern u32 func_021C6580(u32, u32);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
void func_021AC384(u32 a, W *w);
void func_021AC3A4(u32 a, u32 *b);
void func_021AC3F8(u32 unused, u32 *p);
P *func_021AC494(u32 a, int heap);
void func_021AC4B8(u32 a, u8 *p);
void func_021AC4CC(u32 *a);
int func_021AC514(u32 a);
void func_021AC528(u32 a, u32 b);
extern char d_021DE038[];
extern u8 d_021D90AC[];


void func_021AC384(u32 a, W *w)
{
    if (w->f14 != 0xFFFF)
        func_02050468((struct BbActSys *)w->h->f10, (u16)w->f14, 1);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021AC3A4(u32 a, u32 *b)
{
    if (func_0216E1C4(b[2], (int)(b + 3)) == 0) {
        func_021AC154(a);
        return;
    }
    if (func_0216D98C((int)func_0216D67C((void *)b[2])) == 0) {
        func_021AC154(a);
        return;
    }
    if (func_0216DAB4((void *)b[2]) == 1 || func_0216D57C((void *)b[2], 0x8000) != 0)
        b[0] = 1;
    else
        b[0] = 0;
}


void func_021AC3F8(u32 unused, u32 *p)
{
    Vec3 v1;
    Vec3 v2;
    u32 one;
    u32 zero;
    u32 r4 = p[5];
    u8 *r6 = func_0216E3C4((void *)p[2]);
    if (p[0] == 0) {
        one = 1;
        func_0216D88C((const struct Actor *)p[2], (struct VecFx32 *)&v1);
        func_0216D92C((u8 *)p[2], (s32_021AC3F8 *)(&v2));
        func_0207C9D0(&v1, &v2, &v1);
        if ((u8)(r6[3] + 246) <= 1) {
            func_0216D8B0((u8 *)p[2], (u8 *)(&v2));
            if (r6[7] == 0)
                v2.y = -0x800;
            func_0207C9D0(&v1, &v2, &v1);
        }
        func_0204F720((void *)(*(u32 *)(p[1] + 0x14)), r4, &one);
        v1.y += 0x1000;
        func_0204F638((u8 *)(*(u32 *)(p[1] + 0x14)), r4, (struct Trip *)(&v1));
    } else {
        zero = 0;
        func_0204F720((void *)(*(u32 *)(p[1] + 0x14)), r4, &zero);
    }
}


P *func_021AC494(u32 a, int heap)
{
    P *p;

    p = (P *)func_02030734(heap, 8, 1, d_021DE038, 0x52);
    p->f0 = a;
    func_021AC4CC((u32 *)p);
    return p;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AC4B8(u32 a, u8 *p)
{
    func_021AC514((u32)p);
    func_020307B0(p);
}


void func_021AC4CC(u32 *a)
{
    u32 buf[9];
    u32 r6 = func_021ABE18((u8 *)a[0]);
    u32 r4 = func_021ABE24((u8 *)a[0]);
    func_021C6AE0((u32)buf);
    func_021C6AF0((u32)buf, r4, 0x30);
    func_021C6AF8((u32 *)buf, r4);
    func_021C6AFC(buf, 0x60);
    ((struct Obj07513 *)a)->f4 = func_021C6574(r6, (u32)buf, 0);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AC514(u32 a)
{
    u32 b;
    u32 c;
    u32 d;
return func_021C6580(func_021ABE18((u8 *)(((struct Obj12096 *)((u8 *)(a)))->f0)), ((struct Obj12096 *)((u8 *)(a)))->f4);
}


void func_021AC528(u32 a, u32 b)
{
    Vec3 v;
    Arg s;
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    v.y += 0x1000;
    v.z += 0x6000;
    s.a = func_021ABEA0(b, 1);
    s.v = v;
    func_021ABFA8(b, d_021D90AC, 0, 0, &s, 0);
}
