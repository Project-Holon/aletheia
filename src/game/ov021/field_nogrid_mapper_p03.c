/*
 * file:     field_nogrid_mapper_p03.c
 * unit:     yes
 * function: func_021B9278, func_021B9280, func_021B9338, func_021B9368, func_021B93D4, func_021B9404, func_021B9434, func_021B9464, func_021B9478, func_021B949C, func_021B94C0, func_021B94D8, func_021B9510
 * address:  0x021B9278
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
 *   _s32_div_f  0x0209C0A4  arm
 *   func_021B7EE4  0x021B7EE4  thumb  ov021
 *   func_021B80E0  0x021B80E0  thumb  ov021
 *   func_021B810C  0x021B810C  thumb  ov021
 *   func_021B8028  0x021B8028  thumb  ov021
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_021B7DE0  0x021B7DE0  thumb  ov021
 *   func_021B87FC  0x021B87FC  thumb
 */
#include "../../matched/include/Obj18139.h"
#include "../../matched/include/Obj02052.h"
#include "../../matched/include/Obj02659.h"
#include "../../matched/include/Obj04891.h"
#include "../../matched/include/Obj03136.h"

struct Sub;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

typedef struct { u8 b[0x48]; } E48;

typedef struct { u16 f0; volatile u16 n; u8 pad[0x10]; E48 *arr; } SR;

u32 func_021B7EE4(u32 a, u32 b, u32 c, u32 d);
void func_021B80E0(u32 a, u32 b, u32 c);
void func_021B810C(struct Sub *o);
void func_021B8028(u32 a, u32 b);
s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
int func_021B7DE0(u32 a, u32 b);
u8 *func_021B87FC(u8 *p, u32 idx);
int func_021B9278(u32 a);
int func_021B9280(u8 *a, u32 arg2, u32 arg3, u8 *tbl);
int func_021B9338(u8 *p, u8 *base, u32 arg3, int arg4);
int func_021B9368(u8 *p, u32 a1, u32 a2, int a3, u32 a5);
int func_021B93D4(int dir);
int func_021B9404(int dir);
int func_021B9434(int dir);
u16 *func_021B9464(u16 *p);
void func_021B9478(u16 *p, u16 v);
void func_021B949C(u16 *p, u16 v);
int func_021B94C0(u16 *p, u16 v);
int func_021B94D8(u16 *r, E48 *e, SR *sr);
u8 *func_021B9510(u16 *p, u8 *q, u32 v);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B9278(u32 a)
{
return (((struct Obj18139 *)((u8 *)(a)))->f14 << 4);
}


int func_021B9280(u8 *a, u32 arg2, u32 arg3, u8 *tbl)
{
    u8 *row1 = *(u8 * *)&((struct Obj02659 *)tbl)->f10 + ((struct Obj02052 *)a)->f0 * 0x70;
    u8 *row2 = *(u8 * *)&((struct Obj02659 *)tbl)->f10 + ((struct Obj02052 *)a)->f4 * 0x70;
    int sC;
    int s8;
    int num;
    int i;

    s8 = -1;
    sC = -1;
    for (i = 0; i < 4; i++) {
        u32 v1 = *(u32 *)(row1 + i * 4);
        if (v1 != 0xFFFF) {
            if (a == *(u8 * *)&((struct Obj02659 *)tbl)->f14 + v1 * 0x48)
                sC = *(int *)(row1 + i * 4 + 0x20);
        }
        {
            u32 v2 = *(u32 *)(row2 + i * 4);
            if (v2 != 0xFFFF) {
                if (a == *(u8 * *)&((struct Obj02659 *)tbl)->f14 + v2 * 0x48)
                    s8 = *(int *)(row2 + i * 4 + 0x20);
            }
        }
    }
    if (sC < 0)
        sC = s8;
    if (s8 < 0)
        s8 = sC;
    if (arg2 > arg3 - 0x10)
        arg2 = arg3 - 0x10;
    num = s8 - sC;
    if (arg3 - 0x10 != 0)
        num = (int)((u32)num * arg2) / (int)(arg3 - 0x10);
    return num + sC;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021B9338(u8 *p, u8 *base, u32 arg3, int arg4)
{
    int r = func_021B9280(base, ((struct Obj04891 *)p)->fC, arg3, *(u8 * *)&((struct Obj04891 *)p)->f24);
    int f = ((struct Obj04891 *)p)->f14;

    ((struct Obj04891 *)p)->f18 = r;
    if ((f < 0 ? -f : f) >= r) {
        if (f > 0)
            ((struct Obj04891 *)p)->f14 = r;
        else
            ((struct Obj04891 *)p)->f14 = -r;
    }
    return arg4;
}


int func_021B9368(u8 *p, u32 a1, u32 a2, int a3, u32 a5)
{
    int i;

    func_021B7EE4(((struct Obj03136 *)p)->f1C, a1, a2, a3);
    func_021B80E0(((struct Obj03136 *)p)->f1C, 4, a2);
    func_021B810C((struct Sub *)(((struct Obj03136 *)p)->f1C));
    func_021B80E0(((struct Obj03136 *)p)->f1C, 0, a2);
    for (i = 0; i < 16; i++) {
        if (a3 == i)
            func_021B8028(((struct Obj03136 *)p)->f1C, a5);
        func_021B810C((struct Sub *)(((struct Obj03136 *)p)->f1C));
    }
    if (func_0203EFC8((void *)a1, (void *)(((struct Obj03136 *)p)->f1C + 0x5c), 8) == 0)
        return 0;
    return func_021B7DE0(((struct Obj03136 *)p)->f1C, ((struct Obj03136 *)p)->f1C + 0x5c);
}

int func_021B93D4(int dir)
{
    switch (dir) {
    case 1: return 3;
    case 3: return 1;
    case 4: return 2;
    case 2: return 4;
    }
    return 0;
}

int func_021B9404(int dir)
{
    switch (dir) {
    case 1: return 2;
    case 3: return 4;
    case 4: return 1;
    case 2: return 3;
    }
    return 0;
}

int func_021B9434(int dir)
{
    switch (dir) {
    case 1: return 4;
    case 3: return 2;
    case 4: return 3;
    case 2: return 1;
    }
    return 0;
}


u16 *func_021B9464(u16 *p)
{
    int i;

    for (i = 0; i < 0x12; i++) {
        p[i] = 0xFFFF;
    }
    return p;
}


void func_021B9478(u16 *p, u16 v)
{
    int i;

    for (i = 0; i < 0x12; i++) {
        if (p[i] == 0xFFFF) {
            p[i] = v;
            return;
        }
    }
}


void func_021B949C(u16 *p, u16 v)
{
    int i;

    for (i = 0; i < 0x12; i++) {
        if (v == p[i]) {
            p[i] = 0xFFFF;
            return;
        }
    }
}


int func_021B94C0(u16 *p, u16 v)
{
    int i;
    for (i = 0; i < 0x12; i++)
        if (p[i] == v)
            return 1;
    return 0;
}

/*
 * The element count is a volatile u16: the original reads it once for the
 * loop entry guard and again on every bottom test, while the array base is
 * hoisted.  A plain u16 count is CSEd into one register (6 bytes shorter).
 */
int func_021B94D8(u16 *r, E48 *e, SR *sr)
{
    int i;
    int found = 0;
    for (i = 0; i < sr->n; i++) {
        if (e == &sr->arr[i])
            found = i;
    }
    return func_021B94C0(r, found);
}


u8 *func_021B9510(u16 *p, u8 *q, u32 v)
{
    if (func_021B94C0(p, (u16)v) == 0)
        return func_021B87FC(q, v);
    return 0;
}
