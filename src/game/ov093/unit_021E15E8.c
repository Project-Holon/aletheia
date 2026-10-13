/*
 * file:     unit_021E15E8.c
 * unit:     yes
 * function: func_021E15E8, func_021E1630, func_021E163C, func_021E1668, func_021E1784, func_021E17B0, func_021E17DC
 * address:  0x021E15E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_POKEPARAM_GetCounter  0x021D69AC  thumb  ov093
 *   data_021F2BD0 0x021F2BD0 data a4
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   data_021F2BE8 0x021F2BE8 data a4
 *   d_021F2948     0x021F2948  data   ov093  a4
 */
#include "../../matched/include/Obj00889.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern u32 BTL_CALC_Random(u32 range);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern unsigned char BTL_POKEPARAM_GetCounter(unsigned char *base, int idx);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(struct S *, u32);
void func_021E15E8(int a, void *p, int id);
int *func_021E1630(int *p);
void func_021E163C(int a, int b, int c);
void func_021E1668(int unused, void *q, int id);
u32 *func_021E1778(u32 *p);
void func_021E1784(int a, int b, int c);
void func_021E17B0(int a, int b, int c);
void func_021E17DC(void *a, void *b, int c);
u32 *func_021E18E0(u32 *p);
extern u32 data_021F2BD0[];
extern u32 data_021F2BE8[];
extern int d_021F2948[];


void func_021E15E8(int a, void *p, int id)
{
    u8 k;
    u16 w;
    u16 r;
    if (id == BTL_EVENT_GetVar(3)) {
        k = func_021D59B4(func_021C7CF4(p, id), 15);
        w = BTL_CALC_Random(101) + 50;
        r = (k * w) / 100;
        if (r == 0) r = 1;
        BTL_EVENT_OverwriteVar(0x37, r);
    }
}


int *func_021E1630(int *p)
{
    *p = 2;
    return d_021F2948;
}


void func_021E163C(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(2) && BTL_POKEPARAM_GetCounter(func_021C7CF4((int *)b, c), 0) >= 3)
        BTL_EVENT_OverwriteVar(34, 26);
}



/*
 * follower: 021E1778 store-return stub included; zero local reused for n+1.
 */
void func_021E1668(int unused, void *q, int id)
{
    void *m;
    u8 *r;
    u32 n;
    int zero;
    if (id == BTL_EVENT_GetVar(3)) {
        m = func_021C7CF4(q, id);
        zero = 0;
        n = BTL_POKEPARAM_GetCounter(m, 0);
        if (n >= 3) return;
        r = func_021C88A4(q, 38, id);
        r[4] = id;
        r[5] = zero;
        zero = n + 1;
        r[6] = zero;
        func_021C88C8(q, r);
        r = func_021C88A4(q, 4, id);
        func_021C8838(r + 4, 2, 0x2d1);
        func_021C8860((struct S *)(r + 4), id);
        func_021C8860((struct S *)(r + 4), zero);
        func_021C88C8(q, r);
        r = func_021C88A4(q, 14, id);
        r[15] = 1;
        r[16] = id;
        *(int *)(r + 4) = 2;
        r[12] = 1;
        r[14] = 1;
        func_021C88C8(q, r);
        r = func_021C88A4(q, 38, id);
        ((struct Obj00889 *)r)->f0 |= 0x1000000;
        r[4] = id;
        r[5] = 1;
        r[6] = BTL_POKEPARAM_GetCounter(m, 1) + 1;
        func_021C88C8(q, r);
        r = func_021C88A4(q, 14, id);
        r[15] = 1;
        r[16] = id;
        *(int *)(r + 4) = 4;
        r[12] = 1;
        r[14] = 1;
        func_021C88C8(q, r);
        r = func_021C88A4(q, 38, id);
        ((struct Obj00889 *)r)->f0 |= 0x1000000;
        r[4] = id;
        r[5] = 2;
        r[6] = BTL_POKEPARAM_GetCounter(m, 2) + 1;
        func_021C88C8(q, r);
    }
}



u32 *func_021E1778(u32 *p)
{
    *p = 3;
    return data_021F2BD0;
}




void func_021E1784(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(2) && BTL_POKEPARAM_GetCounter(func_021C7CF4((int *)b, c), 0) == 0)
        BTL_EVENT_OverwriteVar(34, 26);
}




static inline void func_021E17B0_set48(int v)
{
    BTL_EVENT_OverwriteVar(48, v);
}




/*
 * The product passed through a static inline helper is computed before the
 * helper's constant first argument is loaded (no result copy).
 */
void func_021E17B0(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3))
        func_021E17B0_set48(BTL_POKEPARAM_GetCounter(func_021C7CF4((int *)b, c), 0) * 100);
}



/*
 * follower: 021E18E0 store-and-return stub included.
 */
void func_021E17DC(void *a, void *b, int c)
{
    void *m;
    int x;
    int y;
    int z;
    u8 *p;
    if (c != BTL_EVENT_GetVar(2)) return;
    m = func_021C7CF4(b, c);
    x = BTL_POKEPARAM_GetCounter(m, 1);
    y = BTL_POKEPARAM_GetCounter(m, 2);
    z = BTL_POKEPARAM_GetCounter(m, 0);
    if (x != 0) {
        p = func_021C88A4(b, 14, c);
        p[15] = 1;
        p[16] = c;
        *(u32 *)(p + 4) = 2;
        p[12] = -x;
        func_021C88C8(b, p);
        p = func_021C88A4(b, 38, c);
        p[4] = c;
        p[5] = 1;
        p[6] = 0;
        func_021C88C8(b, p);
    }
    if (y != 0) {
        p = func_021C88A4(b, 14, c);
        p[15] = 1;
        p[16] = c;
        *(u32 *)(p + 4) = 4;
        p[12] = -y;
        func_021C88C8(b, p);
        p = func_021C88A4(b, 38, c);
        p[4] = c;
        p[5] = 2;
        p[6] = 0;
        func_021C88C8(b, p);
    }
    if (z != 0) {
        p = func_021C88A4(b, 38, c);
        p[4] = c;
        p[5] = 0;
        p[6] = 0;
        func_021C88C8(b, p);
        p = func_021C88A4(b, 4, c);
        func_021C8838(p + 4, 2, 724);
        func_021C8860((struct S *)(p + 4), c);
        func_021C88C8(b, p);
    }
}



u32 *func_021E18E0(u32 *p)
{
    *p = 3;
    return data_021F2BE8;
}
