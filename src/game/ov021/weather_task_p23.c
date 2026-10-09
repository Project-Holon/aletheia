/*
 * file:     weather_task_p23.c
 * unit:     yes
 * function: func_021A63F0, func_021A6428, func_021A6454, func_021A6478, func_021A64B4
 * address:  0x021A63F0
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
 *   func_0216D5F8  0x0216D5F8  thumb
 *   func_02197E7C  0x02197E7C  thumb
 *   func_0216D410  0x0216D410  thumb
 *   func_021A3964  0x021A3964  thumb
 *   func_021A6C6C  0x021A6C6C  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A652C  0x021A652C  thumb  ov021
 *   func_021A658C  0x021A658C  thumb  ov021
 *   func_021A661C  0x021A661C  thumb  ov021
 *   func_021A666C  0x021A666C  thumb  ov021
 */
#include "../../matched/include/Obj04234.h"

typedef unsigned short u16;

typedef struct {
    int f0;
    int pad[4];
    unsigned char *f14;
} S_021A5EA4;

typedef unsigned int u32;

typedef unsigned char u8;

extern u16 func_0216D5F8(void *p);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *p, int a);
extern void func_021A3964(u8 *p, u32 v);
extern int func_021A6C6C(u8 *p, u32 k);
extern void func_020061E4(u32 a);
extern void *func_021A3960(unsigned char *p);
extern int func_021A652C(void *a, void *x, int c, int d, int e, int f);
extern int func_021A658C(void *a, void *x, int c, int d, int e, int f);
extern int func_021A661C(void *a, void *x, int c, int d, int e, int f);
extern u32 func_021A666C(void *a, void *b, u32 c, u32 d, u32 e, u32 f);
void func_021A63F0(S_021A5EA4 *a, void *b, int c, int d, u16 e);
void func_021A6428(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f);
void func_021A6454(S_021A5EA4 *a, void *b, int c, int d, u16 e);
void func_021A6478(S_021A5EA4 *a, void *b, int c, int d, u16 e);
int func_021A64B4(int *a, int b, int c, int d, int e);



void func_021A63F0(S_021A5EA4 *a, void *b, int c, int d, u16 e)
{
    if (e == 9) {
        e = func_0216D5F8(b);
    }
    func_0216D410(b, func_02197E7C(e, 0));
    a->f0 = 0;
    func_021A3964(a->f14, 0);
}



void func_021A6428(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f)
{
    func_0216D410(b, func_02197E7C(e, (f == 1) ? 0x14 : 0x10));
    a->f0 = 1;
    func_021A3964(a->f14, 1);
}



void func_021A6454(S_021A5EA4 *a, void *b, int c, int d, u16 e)
{
    func_0216D410(b, func_02197E7C(e, 0x28));
    a->f0 = 2;
    func_021A3964(a->f14, 2);
}



void func_021A6478(S_021A5EA4 *a, void *b, int c, int d, u16 e)
{
    func_0216D410(b, func_02197E7C(e, 0x1c));
    a->f0 = 3;
    func_021A3964(a->f14, 0);
    if (func_021A6C6C((u8 *)a, e) == 0) {
        func_020061E4(0x55a);
    }
}



int func_021A64B4(int *a, int b, int c, int d, int e)
{
    void *x = func_021A3960(*(unsigned char * *)&((struct Obj04234 *)a)->f14);
    int r = 0;
    switch (a[0]) {
    case 0: r = func_021A652C(a, x, b, c, d, e); break;
    case 1: r = func_021A658C(a, x, b, c, d, e); break;
    case 2: r = func_021A661C(a, x, b, c, d, e); break;
    case 3: r = func_021A666C(a, x, b, c, d, e); break;
    }
    return r;
}
