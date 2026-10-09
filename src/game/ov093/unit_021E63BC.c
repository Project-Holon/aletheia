/*
 * file:     unit_021E63BC.c
 * unit:     yes
 * function: func_021E63BC, func_021E6420, func_021E6444, func_021E6480, func_021E64AC, func_021E64B8, func_021E6500
 * address:  0x021E63BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F2AF8     0x021F2AF8  data   ov093  a4
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F25DC     0x021F25DC  data  a4
 *   d_021F25D4     0x021F25D4  data   ov093  a4
 *   d_021F27D4     0x021F27D4  data   ov093  a4
 */
#include "../../matched/include/Obj13535.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern int func_021C8288(u8 *p);
extern int func_021D76BC(int key, u32 val);
extern void func_021D7704(int a, int b);
void func_021E63BC(int u, void *a, u32 b);
void func_021E6410(void);
int *func_021E6414(int *p);
void func_021E6420(int a, void *b, int c);
void func_021E6444(int a, void *b, int c);
void func_021E6480(int a, void *b, int c);
int *func_021E64AC(int *p);
void func_021E64B8(int u, void *a, u32 b);
int *func_021E64F4(int *p);
void func_021E6500(int u, void *a, u32 b);
int *func_021E653C(int *p);
extern int d_021F2AF8[];
extern int d_021F25DC[];
extern int d_021F25D4[];
extern int d_021F27D4[];




void func_021E63BC(int u, void *a, u32 b)
{
    u8 *e;

    if (b == func_021D775C(3)) {
        e = func_021C88A4(a, 0x17, b);
        e[8] = b;
        ((struct Obj13535 *)e)->f4 = 5;
        func_021C88C8(a, e);
        e = func_021C88A4(a, 4, b);
        func_021C8838(e + 4, 2, 0x21a);
        func_021C8860((struct S *)(e + 4), b);
        func_021C88C8(a, e);
    }
}




void func_021E6410(void)
{
}




int *func_021E6414(int *p)
{
    *p = 3;
    return d_021F2AF8;
}




void func_021E6420(int a, void *b, int c)
{
    if (c == func_021D775C(3) && func_021C8288(b) == 1)
        func_021D76BC(0x51, 1);
}




void func_021E6444(int a, void *b, int c)
{
    u8 *m;

    if (c == func_021D775C(3)) {
        m = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(m + 4, 2, 0x229);
        func_021C8860((struct S *)(m + 4), c);
        func_021C88C8(b, m);
    }
}



void func_021E6480(int a, void *b, int c)
{
    if (c == func_021D775C(3) && (u8)(func_021C8288(b) + 254) <= 2)
        func_021D7704(0x31, 2 << 10);
}


int *func_021E64AC(int *p)
{
    *p = 1;
    return d_021F27D4;
}


void func_021E64B8(int u, void *a, u32 b)
{
    u8 *e;

    if (b == func_021D775C(3)) {
        e = func_021C88A4(a, 4, b);
        func_021C8838(e + 4, 2, 0x223);
        func_021C8860((struct S *)(e + 4), b);
        func_021C88C8(a, e);
    }
}



int *func_021E64F4(int *p)
{
    *p = 1;
    return d_021F25DC;
}



void func_021E6500(int u, void *a, u32 b)
{
    u8 *e;

    if (b == func_021D775C(3)) {
        e = func_021C88A4(a, 4, b);
        func_021C8838(e + 4, 2, 0x226);
        func_021C8860((struct S *)(e + 4), b);
        func_021C88C8(a, e);
    }
}



int *func_021E653C(int *p)
{
    *p = 1;
    return d_021F25D4;
}
