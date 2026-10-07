/*
 * file:     field_msgbg_p33.c
 * unit:     yes
 * function: func_0218DC5C, func_0218DC6C, func_0218DC70, func_0218DC74, func_0218DC84, func_0218DCF4, func_0218DCFC, func_0218DD04, func_0218DD08, func_0218DD0C, func_0218DD10, func_0218DD14, func_0218DD38, func_0218DD4C, func_0218DD5C, func_0218DD6C, func_0218DD70, func_0218DD80, func_0218DD84, func_0218DD98, func_0218DD9C, func_0218DDA4, func_0218DDB4, func_0218DE78, func_0218DEF0, func_0218DEFC, func_0218DF80, func_0218DFE0, func_0218E018
 * address:  0x0218DC5C
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
 *   func_02193B04  0x02193B04  thumb  ov021
 *   d_021DD9E0     0x021DD9E0  data ov021 a2
 *   g_021DD9E0     0x021DD9E0  data ov021 a2
 *   func_021A7360  0x021A7360  thumb ov021
 *   func_021A7404  0x021A7404  thumb  ov021
 *   func_021A7418  0x021A7418  thumb
 *   d_021D3DD4     0x021D3DD4  data a2
 *   func_021C0688  0x021C0688  thumb ov021
 *   func_021C068C  0x021C068C  thumb ov021
 *   func_021C06B4  0x021C06B4  thumb ov021
 *   func_021C06A8  0x021C06A8  thumb ov021
 *   func_02082BCC  0x02082BCC  arm
 *   g_02FFFC3C  0x02FFFC3C  data  a4
 *   func_02169598  0x02169598  thumb ov010
 *   func_021694FC  0x021694FC  thumb ov010
 *   func_02169538  0x02169538  thumb ov010
 *   func_02030734  0x02030734  arm
 *   d_021DDA28     0x021DDA28  data  ov021  a4
 *   func_02048B78  0x02048B78  arm
 *   func_02048B88  0x02048B88  arm
 *   func_0207D184  0x0207D184  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0218E18C  0x0218E18C  thumb ov021
 *   func_0218EEFC  0x0218EEFC  thumb ov021
 */
#include "../../matched/include/Obj17896.h"
#include "../../matched/include/Obj17897.h"
#include "../../matched/include/Obj12063.h"
#include "../../matched/include/Obj17898.h"
#include "../../matched/include/Obj19552.h"
#include "../../matched/include/Obj19553.h"
#include "../../matched/include/Obj17899.h"
#include "../../matched/include/Obj00165.h"
#include "../../matched/include/Obj05978.h"
#include "../../matched/include/Obj07208.h"
#include "../../matched/include/Obj17902.h"
#include "../../matched/include/Obj17903.h"
#include "../../matched/include/Obj17904.h"
#include "../../matched/include/Obj09174.h"
#include "../../matched/include/Obj02370.h"
#include "../../matched/include/Obj03107.h"
#include "../../matched/include/Obj12588.h"
#include "../../matched/include/Obj01847.h"
#include "../../matched/include/Obj19554.h"
#include "../../matched/include/Obj02689.h"
#include "../../matched/include/Obj04990.h"
#include "../../matched/include/Obj00519.h"

struct D;
struct Light;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef struct { u32 a, b, c; } Vec3;

typedef struct { u16 a; u16 b; u16 c; } S6;

extern int func_02193B04(u32 a, u32 b, u32 c, u32 d);
extern u32 *func_021A7360(const struct D *p, u32 c, u32 heap);
extern int func_021A7404(u8 *p, int a1);
extern void func_021A7418(void *p);
extern u32 func_021C0688(u8 *p);
extern int func_021C068C(int x, int z, int o, u8 i);
extern int func_021C06B4(u8 i, int o);
extern int func_021C06A8(u8 i, int o);
extern void func_02082BCC(void *p, int v, int n);
extern u32 func_02169598(u8 *p);
extern u16 func_021694FC(u8 *p);
extern void func_02169538(unsigned char *a, int *out);
extern void *func_02030734(u16, int, int, void *, int);
extern int func_02048B78(struct Light *l);
extern void func_02048B88(struct Light *l, unsigned int *out);
extern u16 func_0207D184(int a);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_0218E18C(char *p, int a);
extern void func_0218EEFC(int n, u32 x, u32 flags, u32 heap, void *a);
void func_0218DC5C(u8 *a, Vec3 *b);
u32 func_0218DC6C(u8 *p);
void *func_0218DC70(u8 *p);
int func_0218DC74(u32 a, u32 b, u32 c);
void func_0218DC84(int a, int b, const int *q, int c);
int func_0218DCF4(u32 *a0);
int func_0218DCFC(u32 *a0);
int func_0218DD04(u8 *p);
int func_0218DD08(u8 *p);
int func_0218DD0C(u8 *p);
u16 func_0218DD10(u8 *p);
void func_0218DD14(int *dst, char *src, int a, int b);
void func_0218DD38(void **a);
void func_0218DD4C(void **a);
int func_0218DD5C(u32 *p);
u32 func_0218DD6C(u32 *p);
int func_0218DD70(u32 a);
void func_0218DD80(u8 *p, u32 v);
int func_0218DD84(u32 a);
u32 func_0218DD98(u8 *p);
int func_0218DD9C(u32 a, u32 b, u32 c, u32 d);
void func_0218DDA4(u8 *a, Vec3 *b);
void func_0218DDB4(const char *p, int *q, char *r);
void func_0218DE78(char *p);
void func_0218DEF0(char *p);
void func_0218DEFC(char *p, int o, int v);
void func_0218DF80(u8 *a);
int func_0218DFE0(u8 *a, u32 idx, int flag, u32 *out);
char *func_0218E018(int a0, int a1, struct Light *a2, int a3, u16 heap);
extern u16 d_021DD9E0[];
extern u16 g_021DD9E0[];
extern S6 d_021D3DD4;
extern int d_021DDA28;


void func_0218DC5C(u8 *a, Vec3 *b)
{
    *b = *(Vec3 *)(a + 0x54);
}


/*
 * Loads the 32-bit word at byte +0x64 of the object.
 */
u32 func_0218DC6C(u8 *p)
{
    return ((struct Obj17896 *)p)->f64;
}


/*
 * Loads the 32-bit word at byte +0x6c of the object.
 */
void *func_0218DC70(u8 *p)
{
    return ((struct Obj17897 *)p)->f6C;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0218DC74(u32 a, u32 b, u32 c)
{
return func_02193B04(((struct Obj12063 *)((u8 *)(a)))->f6C, b, c, ((struct Obj12063 *)((u8 *)(a)))->f0);
}


void func_0218DC84(int a, int b, const int *q, int c)
{
    int x;
    int y;

    d_021DD9E0[1] = a;
    x = q[0];
    if (x == -1) {
        d_021DD9E0[0] = d_021DD9E0[0] & ~0xff;
    } else {
        d_021DD9E0[0] = (d_021DD9E0[0] & ~0xff) | 1;
        d_021DD9E0[3] = x;
    }
    y = q[1];
    if (y == -1) {
        d_021DD9E0[0] = d_021DD9E0[0] & 0xffff00ff;
    } else {
        d_021DD9E0[0] = (d_021DD9E0[0] & 0xffff00ff) | 0x100;
        d_021DD9E0[5] = y;
    }
    func_021A7360((const struct D *)g_021DD9E0, b, (u16)c);
}


/*
 * Tail-call thunk: forwards to func_0218DD5C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_0218DCF4(u32 *a0)
{
    return func_0218DD5C(a0);
}


/*
 * Tail-call thunk: forwards to func_0218DD6C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_0218DCFC(u32 *a0)
{
    return func_0218DD6C(a0);
}


/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
int func_0218DD04(u8 *p)
{
    return ((struct Obj17898 *)p)->f4;
}


/*
 * Unlabelled leaf accessor: returns the word at +0x8.
 *
 * Addresses are Black-image addresses.
 */
int func_0218DD08(u8 *p)
{
    return ((struct Obj19552 *)p)->f8;
}


/*
 * Unlabelled leaf accessor: returns the word at +0xC.
 *
 * Addresses are Black-image addresses.
 */
int func_0218DD0C(u8 *p)
{
    return ((struct Obj19553 *)p)->fC;
}


/*
 * Loads the 16-bit halfword at +0x10 of the object.
 */
u16 func_0218DD10(u8 *p)
{
    return ((struct Obj17899 *)p)->f10;
}


/*
 * Fills a 0x14-byte descriptor from src: word0 from func_021A7404(src+0x68, a),
 * then src+0x64/+0x6c, the argument a, and b as a halfword at +0x10.
 * Callee of func_0218CEE4.  EXACT* (unlabelled follower 0x0218DD38).
 */
void func_0218DD14(int *dst, char *src, int a, int b)
{
    dst[0] = func_021A7404((u8 *)(((struct Obj00165 *)src)->f68), a);
    dst[1] = ((struct Obj00165 *)src)->f64;
    dst[2] = ((struct Obj00165 *)src)->f6C;
    dst[3] = a;
    ((struct Obj05978 *)dst)->f10 = b;
}


void func_0218DD38(void **a)
{
    if (*a != 0) {
        func_021A7418(*a);
        *a = 0;
    }
}


void func_0218DD4C(void **a)
{
    if (*a != 0)
        func_021A7418(*a);
}




/*
 * Disasm reads its bytes as `.word` because it saves no lr; it is the
 * callee of the thunk at 0x0218DCF4.
 *
 * Addresses are Black-image addresses.
 */
int func_0218DD5C(u32 *p)
{
    return *p != 0;
}


/*
 * Unlabelled leaf getter (no lr save), callee of func_0218DCFC.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0218DD6C(u32 *p)
{
    return *p;
}


int func_0218DD70(u32 a)
{
((struct Obj07208 *)((u8 *)(a)))->f0 = (~0);
((struct Obj07208 *)((u8 *)(a)))->f4 = 0;
((struct Obj07208 *)((u8 *)(a)))->f8 = 0;
((struct Obj07208 *)((u8 *)(a)))->fC = 0;
return a;
}


/*
 * Field setter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
void func_0218DD80(u8 *p, u32 v)
{
    ((struct Obj17902 *)p)->f0 = v;
}


int func_0218DD84(u32 a)
{
if (((struct Obj17903 *)((u8 *)(a)))->f0 != (~0)) {
    return 1;
}
return 0;
}


/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0218DD98(u8 *p)
{
    return ((struct Obj17904 *)p)->f0;
}


int func_0218DD9C(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj09174 *)((u8 *)(a)))->f4 = b;
((struct Obj09174 *)((u8 *)(a)))->f8 = c;
((struct Obj09174 *)((u8 *)(a)))->fC = d;
return a;
}


void func_0218DDA4(u8 *a, Vec3 *b)
{
    *b = *(Vec3 *)(a + 4);
}


void func_0218DDB4(const char *p, int *q, char *r)
{
    S6 tmp = d_021D3DD4;
    int cnt = 0;
    int base = ((struct Obj03107 *)r)->f100;
    int n = func_021C0688((u8 *)(((struct Obj02370 *)p)->f70));
    int z;
    int x;
    int i;

    x = q[0] / 0x10000;
    z = q[2] / 0x10000;
    for (i = 0; i < n; i++) {
        if (func_021C068C(x, z, ((struct Obj02370 *)p)->f70, i)) {
            int k = base + ++cnt - 1;
            char *e;
            if (k >= 0x10)
                break;
            e = r + k * 16;
            *(S6 *)e = tmp;
            ((struct Obj12588 *)e)->f8 = func_021C06B4(i, ((struct Obj02370 *)p)->f70);
            ((struct Obj12588 *)e)->fC = func_021C06A8(i, ((struct Obj02370 *)p)->f70);
        }
    }
    ((struct Obj03107 *)r)->f100 += (u16)cnt;
}


void func_0218DE78(char *p)
{
    int v;

    func_02082BCC(((struct Obj01847 *)p)->f44, 0xff, ((struct Obj01847 *)p)->f2E);
    ((struct Obj01847 *)p)->f41 = 0;
    ((struct Obj01847 *)p)->f42 = ((struct Obj01847 *)p)->f43;
    ((struct Obj01847 *)p)->f43 = 0;
    ((struct Obj01847 *)p)->f4C = 0;
    if (*(volatile int *)0x02FFFC3C - ((struct Obj01847 *)p)->f50 >= 2) {
        ((struct Obj01847 *)p)->f4D = 0xff;
        ((struct Obj01847 *)p)->f48 = 0;
        return;
    }
    v = *(volatile u16 *)0x04000006;
    ((struct Obj01847 *)p)->f4D = v;
    if (v > 0xc0 || v <= 10) {
        ((struct Obj01847 *)p)->f48 = 0xf000;
        return;
    }
    ((struct Obj01847 *)p)->f48 = 0xf000 - ((v - 10) << 10);
}


void func_0218DEF0(char *p)
{
    ((struct Obj19554 *)p)->f50 = *(u32 *)0x02FFFC3C;
}


void func_0218DEFC(char *p, int o, int v)
{
    int a;
    int b;
    int t;
    int c;
    int i;

    if (func_02169598((u8 *)o) == 0)
        return;
    if (func_021694FC((u8 *)o) == 0)
        return;
    func_02169538((unsigned char *)o, &a);
    t = ((struct Obj02689 *)p)->f48 - a;
    for (i = ((struct Obj02689 *)p)->f41; i > 0; i--) {
        func_02169538((unsigned char *)(*(int *)(*(char * *)&((struct Obj02689 *)p)->f24 + *(u8 *)(((struct Obj02689 *)p)->f44 + i - 1) * 0x28)), &b);
        c = ((struct Obj02689 *)p)->f48 - b;
        if (c >= 0 && t >= c)
            break;
        if (t < 0)
            break;
        *(u8 *)(((struct Obj02689 *)p)->f44 + i) = *(u8 *)(((struct Obj02689 *)p)->f44 + i - 1);
    }
    *(u8 *)(((struct Obj02689 *)p)->f44 + i) = v;
    ((struct Obj02689 *)p)->f41 = ((struct Obj02689 *)p)->f41 + 1;
}


/*
 * Counts how many leading entries fit the width budget.
 *
 * Addresses are Black-image addresses.
 */
void func_0218DF80(u8 *a)
{
    int n;
    int i;
    int sum = 0;
    int w;

    ((struct Obj04990 *)a)->f4C = 0;
    n = ((struct Obj04990 *)a)->f42 - (((struct Obj04990 *)a)->f2E - ((struct Obj04990 *)a)->f40);
    if (n > 0) {
        for (i = 0; i < n; i++) {
            u8 *cnt = a + 0x4C;
            int idx = (*(u8 **)(a + 0x44))[i];
            if (idx == 0xFF) break;
            func_02169538((unsigned char *)(*(int *)(*(u8 * *)&((struct Obj04990 *)a)->f24 + idx * 0x28)), &w);
            sum += w;
            if (((struct Obj04990 *)a)->f48 < sum) break;
            *cnt = *cnt + 1;
        }
    }
}


int func_0218DFE0(u8 *a, u32 idx, int flag, u32 *out)
{
    u32 v = (*(u8 **)(a + 0x44))[idx];
    if (v == 0xff)
        return 0;
    *out = v;
    if (flag == 0) {
        if (idx < *(a + 0x4c))
            return 1;
    } else {
        if (idx >= *(a + 0x4c))
            return 1;
    }
    return 0;
}


char *func_0218E018(int a0, int a1, struct Light *a2, int a3, u16 heap)
{
    int t;
    char *p = func_02030734(heap, 0x1b0, 1, &d_021DDA28, 0x80);
    ((struct Obj00519 *)p)->f10 = a0;
    ((struct Obj00519 *)p)->f14 = a1;
    ((struct Obj00519 *)p)->fC = (int)a2;
    ((struct Obj00519 *)p)->f20 = 0;
    ((struct Obj00519 *)p)->f0 = heap;
    ((struct Obj00519 *)p)->f24 = 0;
    ((struct Obj00519 *)p)->f28 = 0;
    ((struct Obj00519 *)p)->f2C = 0;
    ((struct Obj00519 *)p)->f48 = 0;
    ((struct Obj00519 *)p)->f4C = 0;
    ((struct Obj00519 *)p)->f50 = 0;
    ((struct Obj00519 *)p)->f6C = 0;
    ((struct Obj00519 *)p)->f70 = 0;
    ((struct Obj00519 *)p)->f74 = 0;
    ((struct Obj00519 *)p)->f30 = 0;
    ((struct Obj00519 *)p)->f34 = 0;
    ((struct Obj00519 *)p)->f38 = 0;
    ((struct Obj00519 *)p)->f7A = 0;
    ((struct Obj00519 *)p)->f78 = 0;
    ((struct Obj00519 *)p)->f7C = 0x78;
    ((struct Obj00519 *)p)->fE9 = 1;
    if (func_02048B78((struct Light *)a2) == 0) {
        func_02048B88(a2, (unsigned int *)(&t));
        ((struct Obj00519 *)p)->f80 = func_0207D184(t);
    }
    ((struct Obj00519 *)p)->f4 = func_020490F4(0x3c, ((struct Obj00519 *)p)->f0);
    ((struct Obj00519 *)p)->f8 = func_020490F4(0x6c, ((struct Obj00519 *)p)->f0);
    ((struct Obj00519 *)p)->fEA = 0xffff;
    func_0218E18C(p, a3);
    func_0218EEFC(7, 6, 2, heap, p);
    ((struct Obj00519 *)p)->f1AC = 0;
    return p;
}
