/*
 * file:     unit_021E15E8_p01.c
 * unit:     yes
 * function: func_021E163C, func_021E1668
 * address:  0x021E163C
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D69AC  0x021D69AC  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   data_021F2BD0 0x021F2BD0 data a4
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 */
#include "../../matched/include/Obj00889.h"

struct S;
typedef unsigned char u8;

typedef unsigned int   u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern unsigned char func_021D69AC(unsigned char *base, int idx);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(struct S *, u32);
void func_021E163C(int a, int b, int c);
void func_021E1668(int unused, void *q, int id);
u32 *func_021E1778(u32 *p);
extern u32 data_021F2BD0[];


void func_021E163C(int a, int b, int c)
{
    if (c == func_021D775C(2) && func_021D69AC(func_021C7CF4((int *)b, c), 0) >= 3)
        func_021D76BC(34, 26);
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
    if (id == func_021D775C(3)) {
        m = func_021C7CF4(q, id);
        zero = 0;
        n = func_021D69AC(m, 0);
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
        r[6] = func_021D69AC(m, 1) + 1;
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
        r[6] = func_021D69AC(m, 2) + 1;
        func_021C88C8(q, r);
    }
}

u32 *func_021E1778(u32 *p)
{
    *p = 3;
    return data_021F2BD0;
}
