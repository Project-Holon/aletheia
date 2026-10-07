/*
 * file:     pokemontrade_proc_p09.c
 * unit:     yes
 * function: func_021D92DC, func_021D92FC, func_021D9328, func_021D935C, func_021D9384, func_021D93AC, func_021D93D4, func_021D93E0, func_021D9404, func_021D9410, func_021D941C, func_021D9434, func_021D9468, func_021D94A0, func_021D94D4
 * address:  0x021D92DC
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021DD4F4 0x021DD4F4 thumb ov119
 *   func_021E62D4 0x021E62D4 thumb ov119
 *   func_02039338 0x02039338 arm
 *   func_021DF8A0 0x021DF8A0 thumb ov119
 *   func_020221A4 0x020221A4 thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_0202208C  0x0202208C  thumb
 *   func_021E36D8  0x021E36D8  thumb  ov119
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021E36A8  0x021E36A8  thumb  ov119
 *   func_021E1B14  0x021E1B14  thumb  ov119
 *   func_021E2438  0x021E2438  thumb  ov119
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_021D8F20 0x021D8F20 thumb ov119
 *   func_02017E1C 0x02017E1C thumb
 *   func_0201AC80 0x0201AC80 thumb
 */
#include "../../matched/include/Obj22717.h"
#include "../../matched/include/Obj22719.h"
#include "../../matched/include/Obj22722.h"
#include "../../matched/include/Obj22723.h"
#include "../../matched/include/Obj22724.h"

struct Entry;
struct Link;
struct S119DD4F4;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern void func_021DD4F4(struct S119DD4F4 *p, int i, int j);
extern void func_021E62D4(void *, int, int);
extern u16 func_02039338(void);
extern void func_021DF8A0(void *, int, int);
extern u32 func_020221A4(void);
extern void func_021D8E84(void *, int);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021E36D8(void *p, int idx);
extern int func_021D8AA8(void *p);
extern void func_021E36A8(void *p, int a, int b, void *c, int d, int e);
extern void func_021E1B14(char *p, int i, void *mon);
extern void func_021E2438(char *p, int i);
extern void *func_021D8FA4(void *,int);
extern int func_021D8F20(void *,int);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_0201AC80(void *p);
void func_021D92DC(u32 a, u32 b, u8 *src, u8 *base, void *e);
void func_021D92FC(u32 a, u32 b, u8 *src, u8 *base, void *e);
void func_021D9328(u32 a, u32 b, int *src, void *base, void *e);
void func_021D935C(u32 a, u32 b, u32 c, void *base, void *e);
void func_021D9384(u32 a, u32 b, short *src, u8 *base, void *e);
void func_021D93AC(u32 a, u32 b, u8 *src, void *base, void *e);
void func_021D93D4(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_021D93E0(u32 a, u32 b, u8 *src, u8 *base, void *e);
void func_021D9404(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_021D9410(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_021D941C(void *p);
void func_021D9434(void *p);
void func_021D9468(void *p, int a, void *b);
void func_021D94A0(void *p, int a);
int func_021D94D4(char *p);

void func_021D92DC(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == func_020399A8())
        (base + a)[0x11e0] = *src;
}

void func_021D92FC(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == func_020399A8()) {
        if (a != func_0203D1A4((struct Link *)func_020399A8()))
            ((struct Obj22717 *)base)->f1060 = *src;
    }
}

void func_021D9328(u32 a, u32 b, int *src, void *base, void *e)
{
    if (e == func_020399A8()) {
        if (a != func_0203D1A4((struct Link *)func_020399A8())) {
            func_021DD4F4(base, 1, *src);
            func_021E62D4(base, 1, *src);
        }
    }
}

void func_021D935C(u32 a, u32 b, u32 c, void *base, void *e)
{
    if (e == func_020399A8()) {
        if (a != func_0203D1A4((struct Link *)func_020399A8()))
            func_021D94A0(base, 1);
    }
}

void func_021D9384(u32 a, u32 b, short *src, u8 *base, void *e)
{
    if (e == func_020399A8()) {
        if (a != func_02039338())
            ((struct Obj22719 *)base)->f107E = *src;
    }
}

void func_021D93AC(u32 a, u32 b, u8 *src, void *base, void *e)
{
    if (e == func_020399A8()) {
        if (a != func_02039338())
            func_021DF8A0(base, *src, 1);
    }
}


void func_021D93D4(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    if ((u32)func_020399A8() == e)
        return;
}

void func_021D93E0(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == func_020399A8()) {
        if (a != func_02039338())
            ((struct Obj22722 *)base)->fFA0 = *src;
    }
}


void func_021D9404(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    if ((u32)func_020399A8() == e)
        return;
}


/*
 * Byte-identical twin of func_021D93D4 (same 12-byte predicate stub).
 */
void func_021D9410(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    if ((u32)func_020399A8() == e)
        return;
}

void func_021D941C(void *p)
{
    if (func_020221A4() != 0)
        func_021D8E84(p, 0);
}


/*
 * Start a 7-argument timer/slot request (0,0,0,0,6,1,*(u16*)(p+0x5f4)) then
 * hand func_021D8E84 the func_021D941C callback. Non-SDK dep of
 * func_021DFDA0's case-5 arm.
 *
 * Addresses are Black-image addresses.
 */
void func_021D9434(void *p)
{
    func_0202208C(0, 0, 0, 0, 6, 1, ((struct Obj22723 *)p)->f5F4);
    func_021D8E84(p, (int)func_021D941C);
}


/*
 * Start a transfer on the object when the length is non-zero.
 */
void func_021D9468(void *p, int a, void *b)
{
    int t;

    if (b == 0)
        return;
    func_021E36D8(p, a);
    t = func_021D8AA8(p);
    func_021E36A8(p, a, 1 - a, b, 1, t);
    func_021E1B14(p, a, b);
}


/*
 * Arm or re-arm the three receivers depending on the object state.
 */
void func_021D94A0(void *p, int a)
{
    int i;

    if (func_021D8AA8(p) == 0) {
        func_021E36D8(p, a);
        func_021E2438(p, a);
        return;
    }
    for (i = 0; i < 3; i++)
        func_021E62D4(p, a, i);
}

int func_021D94D4(char *p) { int w; void *v; int z; if(func_021D8AA8(p)==0) {v=func_021D8FA4(p,0);w=func_021D8F20(p,0);} else {v=func_021D8FA4(p,1);w=func_021D8F20(p,1);} z=0;if(func_02017E1C(v,160,0)==0)return z;if(func_02017E1C(v,76,0))return z;if(func_0201AC80((void *)(((struct Obj22724 *)p)->f838))==1 && w!=0)return 1;return 0; }
