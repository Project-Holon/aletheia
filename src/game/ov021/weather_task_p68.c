/*
 * file:     weather_task_p68.c
 * unit:     yes
 * function: func_021A5A30, func_021A5A34, func_021A5A68, func_021A5AD4, func_021A5B4C, func_021A5B6C, func_021A5B7C
 * address:  0x021A5A30
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
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A5C3C  0x021A5C3C  thumb  ov021
 *   func_021A6014  0x021A6014  thumb  ov021
 *   func_021A64B4  0x021A64B4  thumb  ov021
 *   func_021A5BC0  0x021A5BC0  thumb  ov021
 *   func_021A5F98  0x021A5F98  thumb  ov021
 *   func_021A635C  0x021A635C  thumb  ov021
 *   func_021A3AC4  0x021A3AC4  thumb  ov021
 *   func_021A6738  0x021A6738  thumb  ov021
 *   func_021A672C  0x021A672C  thumb  ov021
 *   func_0219E424  0x0219E424  thumb  ov021
 *   func_021A66F8  0x021A66F8  thumb  ov021
 *   func_021A6B08  0x021A6B08  thumb  ov021
 *   func_021A6B30  0x021A6B30  thumb  ov021
 *   func_021A6B50  0x021A6B50  thumb  ov021
 */
#include "../../matched/include/Obj04234.h"
#include "../../matched/include/Obj01119.h"
#include "../../matched/include/Obj19806.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

u16 func_0216D5F8(void *p);
void *func_0216D4B4(char *p);
void func_0216D5E0(int a0, int a1);
void func_0216D674(void *p, u16 v);
void func_021A3964(u8 *p, u32 v);
extern u32 func_021A3974(u8 *p);
extern int func_021A5C3C(u8 *p, u32 a, u32 b, u32 c, u32 d);
extern int func_021A6014(int *a, int b, int c, int d, int e);
extern int func_021A64B4(int *a, int b, int c, int d, int e);
extern void func_021A5BC0(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_021A5F98(int *a, u32 sel, u32 c, u32 d, u32 e, u32 f);
extern void func_021A635C(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e);
void func_021A3AC4(u32 a, u32 v);
void func_021A6738(void *a);
void func_021A672C(void *a);
extern int func_0219E424(u32 o, u32 k, u32 x);
extern int  func_021A66F8(u8 *p, u32 f);
extern void func_021A6B08(u8 *p, u32 v);
extern void func_021A6B30(u8 *p);
extern void func_021A6B50(u8 *p, u32 v);
u32 func_021A5A30(u32 *p);
void func_021A5A34(u32 *p);
int func_021A5A68(u8 *p, u32 a, u32 b, u32 c, u32 d);
void func_021A5AD4(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e);
void func_021A5B4C(u32 *p, u32 a, int mode);
int func_021A5B6C(u32 a, u32 b, u32 c, u32 d);
void func_021A5B7C(u8 *p);


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


/*
 * Addresses are Black-image addresses.
 */
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
    if (func_021A66F8(p, 8)) {
        func_021A6B08(p + 8, 0);
    } else if (func_021A66F8(p, 0x10)) {
        func_021A6B08(p + 8, 1);
    } else {
        func_021A6B30(p + 8);
    }
    func_021A6B50(p + 8, ((struct Obj19806 *)p)->f1C);
}
