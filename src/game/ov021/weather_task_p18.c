/*
 * file:     weather_task_p18.c
 * unit:     yes
 * function: func_021A5788, func_021A57C0, func_021A5810, func_021A5880, func_021A5920, func_021A5928, func_021A5964, func_021A596C, func_021A59DC, func_021A59EC, func_021A5A00, func_021A5A0C, func_021A5A18, func_021A5A24, func_021A5A30, func_021A5A34, func_021A5A68, func_021A5AD4, func_021A5B4C, func_021A5B6C, func_021A5B7C, func_021A5BC0, func_021A5C3C
 * address:  0x021A5788
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
 *   func_021A3898  0x021A3898  thumb  ov021
 *   func_02164208  0x02164208  thumb  ov010
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_02163E34  0x02163E34  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_02162564  0x02162564  thumb  ov010
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626B8  0x021626B8  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_021A395C  0x021A395C  thumb  ov021
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216E0AC  0x0216E0AC  thumb  ov010
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_0219E2C0  0x0219E2C0  thumb  ov021
 *   func_021A6B88  0x021A6B88  thumb  ov021
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A3CB0  0x021A3CB0  thumb  ov021
 *   func_021A3CE8  0x021A3CE8  thumb  ov021
 *   d_021DDF04     0x021DDF04  data  a4
 *   d_021DDEE0     0x021DDEE0  data  a4
 *   d_021DDEE0b    0x021DDEE0  data  a4
 *   func_020307B0  0x020307B0  arm
 *   func_021A3AB8  0x021A3AB8  thumb  ov021
 *   func_021A3CC0  0x021A3CC0  thumb  ov021
 *   func_021A6BB4  0x021A6BB4  thumb  ov021
 *   func_021A682C  0x021A682C  thumb  ov021
 *   func_021A6C30  0x021A6C30  thumb  ov021
 *   func_021A66F8  0x021A66F8  thumb  ov021
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_0219E664  0x0219E664  thumb  ov021
 *   func_021B8028  0x021B8028  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 *   func_021A6014  0x021A6014  thumb  ov021
 *   func_021A64B4  0x021A64B4  thumb  ov021
 *   func_021A5F98  0x021A5F98  thumb  ov021
 *   func_021A635C  0x021A635C  thumb  ov021
 *   func_021A3AC4  0x021A3AC4  thumb  ov021
 *   func_021A6738  0x021A6738  thumb  ov021
 *   func_021A672C  0x021A672C  thumb  ov021
 *   func_0219E424  0x0219E424  thumb  ov021
 *   func_021A6B08  0x021A6B08  thumb  ov021
 *   func_021A6B30  0x021A6B30  thumb  ov021
 *   func_021A6B50  0x021A6B50  thumb  ov021
 *   func_021A5EA0  0x021A5EA0  thumb  ov021
 *   func_021A5EA4  0x021A5EA4  thumb  ov021
 *   func_021A5EDC  0x021A5EDC  thumb  ov021
 *   func_021A5F14  0x021A5F14  thumb  ov021
 *   func_021A5F38  0x021A5F38  thumb  ov021
 *   func_021A5F74  0x021A5F74  thumb  ov021
 *   func_021A5CA4  0x021A5CA4  thumb  ov021
 *   func_021A5D04  0x021A5D04  thumb  ov021
 *   func_021A5DD8  0x021A5DD8  thumb  ov021
 *   func_021A5E28  0x021A5E28  thumb  ov021
 */
#include "../../matched/include/Obj09571.h"
#include "../../matched/include/Obj00262.h"
#include "../../matched/include/Obj01499.h"
#include "../../matched/include/Obj05027.h"
#include "../../matched/include/Obj09572.h"
#include "../../matched/include/Obj18054.h"
#include "../../matched/include/Obj18055.h"
#include "../../matched/include/Obj18056.h"
#include "../../matched/include/Obj18057.h"
#include "../../matched/include/Obj18058.h"
#include "../../matched/include/Obj04234.h"
#include "../../matched/include/Obj01119.h"
#include "../../matched/include/Obj19806.h"
#include "../../matched/include/Obj01119.h"
#include "../../matched/include/Obj04234.h"

struct VecFx32;
struct Actor;
struct BigObj;
struct Ctx;
struct Q;
typedef unsigned int u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A5788;

typedef unsigned char u8;

typedef struct Vec3 {
    int x;
    int y;
    int z;
} Vec3;

typedef unsigned short u16;

typedef signed short s16;

typedef signed char s8;

void func_021A3898(unsigned char *p, struct VecFx32 *out);
void func_02164208(int dir, int *p, int amt);
void *func_021A3960(unsigned char *p);
void func_02163E34(void *h, Vec021A5788 *v, int *out);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern int  func_02163E58(u8 *a, Vec3 *p, int *out);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012844(const struct BigObj *p);
extern int func_02162564(char *p, struct Q *q);
extern void *func_021625CC(char *p, unsigned i);
extern int func_021626B8(char *a0, int a1);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021A395C(u8 *p);
extern u16 func_0216D5A0(void *p);
extern u16 func_0216D598(void *o);
extern void func_0216E0AC(void *o, void *d);
extern void *func_0219E348(void *a);
extern void func_0219E2C0(void *a, void *r);
extern int func_021A6B88(void *a);
extern u32 func_021A3974(u8 *p);
extern int func_021A3CB0(u32 a, u32 b);
extern void func_021A3CE8(u8 *p);
extern u32 func_020307B0(void *p);
extern u16 func_021A3AB8(u32 a, u32 v);
extern int func_021A3CC0(u32 a);
extern void func_021A6BB4(u8 *p, u32 a1, u32 a2);
extern u32  func_021A682C(u8 *p, u32 a1, u32 a2);
extern void func_021A6C30(u8 *p);
extern u32 func_021A66F8(u32 p, u32 f);
extern void func_0219E2F4(void *o, void *out);
extern int func_0219E664(void *o, u32 k, void *buf);
extern void func_021B8028(u32 v);
u16 func_0216D5F8(void *p);
void *func_0216D4B4(char *p);
void func_0216D5E0(int a0, int a1);
void func_0216D674(void *p, u16 v);
void func_021A3964(u8 *p, u32 v);
extern int func_021A6014(int *a, int b, int c, int d, int e);
extern int func_021A64B4(int *a, int b, int c, int d, int e);
extern void func_021A5F98(int *a, u32 sel, u32 c, u32 d, u32 e, u32 f);
extern void func_021A635C(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e);
void func_021A3AC4(u32 a, u32 v);
void func_021A6738(void *a);
void func_021A672C(void *a);
extern int func_0219E424(u32 o, u32 k, u32 x);
extern void func_021A6B08(u8 *p, u32 v);
extern void func_021A6B30(u8 *p);
extern void func_021A6B50(u8 *p, u32 v);
extern void func_021A5EA0(void *p, void *a, int b, int c, int d, int e);
extern void func_021A5EA4(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern void func_021A5EDC(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern void func_021A5F14(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern void func_021A5F38(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern void func_021A5F74(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern int func_021A5CA4(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern int func_021A5D04(void *a, void *b, int c, int d, int e, int f);
extern int func_021A5DD8(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern int func_021A5E28(void *a, void *b, int c, int d, int e, int f);
void func_021A5788(u32 *p, int k, int *out);
int func_021A57C0(u8 *p, int dir);
int func_021A5810(u8 *p, int dir);
u8 *func_021A5880(u8 *obj, int heap);
void func_021A5920(void *a0);
void func_021A5928(u8 *p, int v);
void func_021A5964(u32 *p);
void func_021A596C(u8 *p, u32 b, u32 c);
int func_021A59DC(u32 a);
u32 func_021A59EC(u32 p);
void func_021A5A00(u8 *p, void *r);
void func_021A5A0C(u8 *p, void *a1);
int func_021A5A18(u8 *p, u32 k, void *buf);
void func_021A5A24(u8 *p);
u32 func_021A5A30(u32 *p);
void func_021A5A34(u32 *p);
int func_021A5A68(u8 *p, u32 a, u32 b, u32 c, u32 d);
void func_021A5AD4(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e);
void func_021A5B4C(u32 *p, u32 a, int mode);
int func_021A5B6C(u32 a, u32 b, u32 c, u32 d);
void func_021A5B7C(u8 *p);
void func_021A5BC0(u8 *p, u32 k, u32 b, u32 c, u32 d, u32 e);
int func_021A5C3C(u8 *p, u32 b, u32 c, u32 d, u32 e);
extern char d_021DDF04;
extern u16  d_021DDEE0[2];
extern u16  d_021DDEE0b[2];



void func_021A5788(u32 *p, int k, int *out)
{
    Vec021A5788 v;

    func_021A3898(*(unsigned char * *)&((struct Obj09571 *)p)->fC, (struct VecFx32 *)&v);
    if (k != 9)
        func_02164208(k, (int *)(&v), 0x10000);
    func_02163E34(func_021A3960(*(unsigned char * *)&((struct Obj09571 *)p)->fC), &v, out);
}



/*
 * Addresses are Black-image addresses.
 */
int func_021A57C0(u8 *p, int dir)
{
    u8 *a;
    int y;
    Vec3 pos;
    int lim;

    a = func_021A3960(*(u8 * *)&((struct Obj00262 *)p)->fC);
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&pos);
    y = pos.y;
    func_02164208(dir, (int *)(&pos), 0x10000);
    if (func_02163E58(a, &pos, &lim) == 1) {
        if (y < lim) {
            return 1;
        }
        if (y > lim) {
            return 2;
        }
    }
    return 0;
}



int func_021A5810(u8 *p, int dir)
{
    u8 *a;
    int h;
    int i;
    Vec3 pos;

    a = func_021A3960(*(u8 * *)&((struct Obj00262 *)p)->fC);
    h = func_02012844(func_020120F4(func_02188C80(*(u8 * *)&((struct Obj00262 *)p)->f10)));
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&pos);
    func_02164208(dir, (int *)(&pos), 0x10000);
    i = func_02162564((char *)h, (struct Q *)(&pos));
    if (i == 0xffff) {
        return 0;
    }
    if (func_021626B8(func_021625CC((char *)h, (u16)i), dir)) {
        return 1;
    }
    return 0;
}


u8 *func_021A5880(u8 *obj, int heap)
{
    u8 *p;

    p = func_02030734(heap, 0x24, 1, &d_021DDF04, 0x1a0);
    *(u8 * *)&((struct Obj01499 *)p)->f14 = obj;
    ((struct Obj01499 *)p)->f18 = func_021A395C(obj);
    ((struct Obj01499 *)p)->f1C = func_021A3960(*(u8 * *)&((struct Obj01499 *)p)->f14);
    if (func_0216D5A0(((struct Obj01499 *)p)->f1C) != 0x45) {
        d_021DDEE0[1] = func_0216D598(((struct Obj01499 *)p)->f1C);
        func_0216E0AC(((struct Obj01499 *)p)->f1C, d_021DDEE0b);
    }
    ((struct Obj01499 *)p)->f20 = (int)func_0219E348(((struct Obj01499 *)p)->f1C);
    {
        u16 v[4] = {0, 0, 0, 0};
        func_0219E2C0(((struct Obj01499 *)p)->f1C, v);
    }
    func_021A6B88(p + 0xc);
    {
        int t = func_021A3974(*(u8 * *)&((struct Obj01499 *)p)->f14);
        switch (t) {
        case 2:
            func_021A3CB0((u32)(*(u8 * *)&((struct Obj01499 *)p)->f14), 4);
            func_021A3CE8(*(u8 * *)&((struct Obj01499 *)p)->f14);
            break;
        case 3:
            func_021A3CB0((u32)(*(u8 * *)&((struct Obj01499 *)p)->f14), 0x100);
            func_021A3CE8(*(u8 * *)&((struct Obj01499 *)p)->f14);
            break;
        }
    }
    return p;
}







/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5920(void *a0)
{
    func_020307B0(a0);
}








void func_021A5928(u8 *p, int v)
{
    if (func_0216D5A0((void *)(((struct Obj05027 *)p)->f1C)) != 0x45) {
        d_021DDEE0[1] = func_0216D598((void *)(((struct Obj05027 *)p)->f1C));
        func_0216E0AC((void *)(((struct Obj05027 *)p)->f1C), d_021DDEE0b);
    }
    ((struct Obj05027 *)p)->f20 = (int)func_0219E348((void *)(((struct Obj05027 *)p)->f1C));
    func_0219E2C0((void *)(((struct Obj05027 *)p)->f1C), (void *)v);
}








/*
 * Unlabelled leaf: clears the word at +0x20.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5964(u32 *p)
{
    p[8] = 0;
}







void func_021A596C(u8 *p, u32 b, u32 c)
{
    u32 t;
    u32 x;
    u32 y;

    t = func_021A3AB8(((struct Obj09572 *)p)->f14, c);
    func_021A3CC0(((struct Obj09572 *)p)->f14);
    func_021A6BB4(p + 0xc, t, ((struct Obj09572 *)p)->f1C);
    x = func_021A682C(p, t, 0);
    y = func_021A5A68(p, x, b, c, 0);
    func_021A5B4C((u32 *)p, c, y);
    func_021A5AD4(p, y, x, b, c, 0);
    func_021A5B7C(p);
    func_021A6C30(p + 0xc);
}







/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A59DC(u32 a)
{
if (((struct Obj18054 *)((u8 *)(a)))->f0 == 3) {
    return 1;
}
return 0;
}







u32 func_021A59EC(u32 p)
{
    u32 r = 1;
    if (func_021A66F8(p, 1) == 0) {
        r = 0;
    }
    return r;
}







/*
 * Tail-call thunk: forwards the object's word at +0x1c to func_0219E2C0.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5A00(u8 *p, void *r)
{
    func_0219E2C0(((struct Obj18055 *)p)->f1C, r);
}







/*
 * Tail-call thunk: forwards the object's word at +0x1c to func_0219E2F4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5A0C(u8 *p, void *a1)
{
    func_0219E2F4((void *)(((struct Obj18056 *)p)->f1C), a1);
}







/*
 * Tail-call thunk: forwards the object's word at +0x1c to func_0219E664.
 *
 * Addresses are Black-image addresses.
 */
int func_021A5A18(u8 *p, u32 k, void *buf)
{
    return func_0219E664(((struct Obj18057 *)p)->f1C, k, buf);
}







/*
 * Tail-call thunk: forwards the object's word at +0x20 to func_021B8028.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5A24(u8 *p)
{
    func_021B8028(((struct Obj18058 *)p)->f20);
}






/*
 * Unlabelled leaf getter at +0x20.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A5A30(u32 *p)
{
    return p[8];
}






void func_021A5A34(u32 *p)
{
    u32 h;
    int v;

    if (p[0] == 3) {
        h = p[7];
        v = func_0216D5F8((void *)h);
        func_0216D4B4((char *)h);
        func_0216D5E0(h, v);
        func_0216D674((void *)h, 0);
        func_021A3964((u8 *)p[5], 0);
    }
}






int func_021A5A68(u8 *p, u32 a, u32 b, u32 c, u32 d)
{
    int r;

    switch (func_021A3974((u8 *)(*(u32 *)&((struct Obj04234 *)p)->f14))) {
    case 0:
        r = func_021A5C3C(p, b, c, (u16)a, d);
        break;
    case 1:
        r = func_021A6014((int *)p, b, c, (u16)a, d);
        break;
    case 2:
    case 3:
        r = func_021A64B4((int *)p, b, c, (u16)a, d);
        break;
    }
    return r;
}






void func_021A5AD4(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    switch (func_021A3974((u8 *)(*(u32 *)&((struct Obj01119 *)p)->f14))) {
    case 0:
        func_021A5BC0(p, a, c, d, (u16)b, e);
        break;
    case 1:
        func_021A5F98((int *)p, a, c, d, (u16)b, e);
        break;
    case 2:
    case 3:
        func_021A635C(p, a, c, d, (u16)b, e);
        break;
    }
}






void func_021A5B4C(u32 *p, u32 a, int mode)
{
    func_021A3AC4(p[5], a);
    func_021A6738(p);
    if (mode == 2)
        func_021A672C(p);
}






/*
 * Tail call with the last three arguments.
 *
 * Addresses are Black-image addresses.
 */
int func_021A5B6C(u32 a, u32 b, u32 c, u32 d)
{
    return func_0219E424(b, c, d);
}






void func_021A5B7C(u8 *p)
{
    if (func_021A66F8((u32)p, 8)) {
        func_021A6B08(p + 8, 0);
    } else if (func_021A66F8((u32)p, 0x10)) {
        func_021A6B08(p + 8, 1);
    } else {
        func_021A6B30(p + 8);
    }
    func_021A6B50(p + 8, ((struct Obj19806 *)p)->f1C);
}




void func_021A5BC0(u8 *p, u32 k, u32 b, u32 c, u32 d, u32 e)
{
    void *a = ((struct Obj01119 *)p)->f1C;

    switch (k) {
    case 0:
        func_021A5EA0(p, a, b, c, d, e);
        break;
    case 1:
        func_021A5EA4(p, a, b, c, d, e);
        break;
    case 2:
        func_021A5EDC(p, a, b, c, d, e);
        break;
    case 3:
        func_021A5F14(p, a, b, c, d, e);
        break;
    case 4:
        func_021A5F38(p, a, b, c, d, e);
        break;
    case 5:
        func_021A5F74(p, a, b, c, d, e);
        break;
    }
}



int func_021A5C3C(u8 *p, u32 b, u32 c, u32 d, u32 e)
{
    int sw = ((struct Obj04234 *)p)->f0;
    int r = 0;
    void *a = ((struct Obj04234 *)p)->f1C;

    switch (sw) {
    case 0:
        r = func_021A5CA4(p, a, b, c, d, e);
        break;
    case 1:
        r = func_021A5D04(p, a, b, c, d, e);
        break;
    case 2:
        r = func_021A5DD8(p, a, b, c, d, e);
        break;
    case 3:
        r = func_021A5E28(p, a, b, c, d, e);
        break;
    }
    return r;
}
