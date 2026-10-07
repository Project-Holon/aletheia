/*
 * file:     weather_task_p09.c
 * unit:     yes
 * function: func_021A2254, func_021A22E0, func_021A231C, func_021A232C, func_021A2390, func_021A23B0, func_021A23D4
 * address:  0x021A2254
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
 *   func_021A2BC4  0x021A2BC4  thumb  ov021
 *   _s32_div_f     0x0209C0A4  arm
 *   func_021A01AC  0x021A01AC  thumb  ov021
 *   func_021A01CC  0x021A01CC  thumb  ov021
 *   func_021A01B4  0x021A01B4  thumb  ov021
 *   func_021A01BC  0x021A01BC  thumb  ov021
 *   func_021A01D8  0x021A01D8  thumb  ov021
 *   func_021A01A4  0x021A01A4  thumb  ov021
 *   func_021A01FC  0x021A01FC  thumb  ov021
 *   func_021A01D4  0x021A01D4  thumb  ov021
 *   func_021A2CC8  0x021A2CC8  thumb  ov021
 *   func_021A0244  0x021A0244  thumb  ov021
 *   func_021A2CF8  0x021A2CF8  thumb  ov021
 *   func_021A0354  0x021A0354  thumb  ov021
 */
#include "../../matched/include/Obj02702.h"
#include "../../matched/include/Obj12713.h"
#include "../../matched/include/Obj00954.h"
#include "../../matched/include/Obj18002.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern int func_021A2BC4(u32 a);
int func_021A01AC(u32 a, u32 b);
int func_021A01CC(u32 a, u32 b);
int func_021A01B4(u32 a, u32 b);
int func_021A01BC(u32 a, u32 b);
void func_021A01D8(u8 *p);
int func_021A01A4(u32 a, u32 b);
extern void func_021A01FC(u8 *p, u32 a, u32 b, u32 c);
extern u32 func_021A01D4(u8 *p);
extern void func_021A2CC8(void *p, int a, int b, int c);
extern int func_021A0244(u8 *p);
extern u8 func_021A2CF8(char *p);
u8 func_021A0354(u8 *p);
void func_021A2254(u8 *p, void (*fn)(u8 *, int, u32), int n, int m, int k, u16 w);
void func_021A22E0(u32 *p, int a, int b, int c);
void func_021A231C(u32 *p, int x);
void func_021A232C(u8 *p, int a, int b, int c, int d);
void func_021A2390(u32 *p, int a, int b, int c);
int func_021A23B0(u32 a);
int func_021A23D4(int *p);


/*
 * Addresses are Black-image addresses.
 */
void func_021A2254(u8 *p, void (*fn)(u8 *, int, u32), int n, int m, int k, u16 w)
{
    int j;
    u8 *cur;
    int cnt;
    int i;
    u8 *next;

    fn(p, n, w);
    cnt = 0;
    cur = *(u8 * *)&((struct Obj02702 *)p)->f774;
    if (cur == 0) {
        return;
    }
    next = *(u8 * *)&((struct Obj12713 *)cur)->f34;
    i = 0;
    if (n <= 0) {
        return;
    }
    do {
        j = 0;
        if (cnt > 0) {
            do {
                ((void (*)(u8 *))(*(u32 *)(*(u32 *)(p + 0x20) + 0x48)))(cur);
                if (func_021A2BC4((u32)cur) == 0) {
                    break;
                }
                j++;
            } while (j < cnt);
        }
        cur = next;
        next = *(u8 * *)&((struct Obj12713 *)cur)->f34;
        if (i >= m) {
            if (i % m == 0) {
                cnt += k;
            }
        }
        if (cur == *(u8 * *)&((struct Obj02702 *)p)->f774) {
            break;
        }
        i++;
    } while (i < n);
}


void func_021A22E0(u32 *p, int a, int b, int c)
{
    if (c == 1) {
        func_021A01AC(p[1], 0);
        func_021A01CC(p[1], 0x1F);
        func_021A01B4(p[1], a);
        func_021A01BC(p[1], b);
        func_021A01D8((u8 *)p[1]);
        func_021A01A4(p[1], 1);
    }
}


void func_021A231C(u32 *p, int x)
{
    if (x == 1)
        func_021A01A4(p[1], 0);
}


void func_021A232C(u8 *p, int a, int b, int c, int d)
{
    int h;

    if (d == 1) {
        func_021A01FC((u8 *)(((struct Obj00954 *)p)->f4), b, a, c);
        return;
    }
    if (d == 2) {
        if (a == func_021A01D4((u8 *)(((struct Obj00954 *)p)->f4))) {
            func_021A01FC((u8 *)(((struct Obj00954 *)p)->f4), b, a, c);
            return;
        }
        h = c / 2;
        func_021A01FC((u8 *)(((struct Obj00954 *)p)->f4), 0x7FDF, func_021A01D4((u8 *)(((struct Obj00954 *)p)->f4)), h);
        func_021A2CC8(p, a, b, h);
    }
}


void func_021A2390(u32 *p, int a, int b, int c)
{
    if (c == 1)
        func_021A01FC((u8 *)p[1], a, func_021A01D4((u8 *)p[1]), b);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A23B0(u32 a)
{
if (func_021A0244((u8 *)(((struct Obj18002 *)((u8 *)(a)))->f4)) != 0) {
    return 0;
}
if (func_021A2CF8((char *)a) == 0) {
    return 1;
}
return 0;
}


int func_021A23D4(int *p)
{
    if (func_021A0354((u8 *)p[4]) == 1) {
        return 1;
    }
    return 0;
}
