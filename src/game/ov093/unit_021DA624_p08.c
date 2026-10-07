/*
 * file:     unit_021DA624_p08.c
 * unit:     yes
 * function: func_021DAD84, func_021DADD8, func_021DAE04, func_021DAE38
 * address:  0x021DAD84
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
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F0B94 0x021F0B94 data a4
 *   func_021D76BC 0x021D76BC thumb ov093
 */
#include "../../matched/include/Obj21314.h"
#include "../../matched/include/Obj21317.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern int func_021D76BC(int,unsigned int);
void func_021DAD84(int unused, void *a, int id, int *f);
void func_021DADD8(int a, int b, int c, int *d);
const unsigned int *func_021DADF8(int *n);
void func_021DAE04(int a, int b, int c, int *d);
void func_021DAE38(int unused, void *a, int id, int *f);
extern const unsigned int d_021F0B94[];


void func_021DAD84(int unused, void *a, int id, int *f)
{
    u8 *r;

    if (id == func_021D775C(2) && f[1] != 0) {
        r = (u8 *)func_021C88A4(a, 4, id);
        ((struct Obj21314 *)r)->f0 |= 0x800000;
        func_021C8838(r + 4, 2, 0x1bd);
        func_021C8860((struct S *)(r + 4), id);
        func_021C88C8(a, r);
        f[1] = 0;
    }
}

void func_021DADD8(int a, int b, int c, int *d) { if (c == func_021D775C(2) && func_021D775C(12) == 7) *d = 0; }

const unsigned int *func_021DADF8(int *n) { *n = 4; return d_021F0B94; }

void func_021DAE04(int a, int b, int c, int *d) { unsigned short k; k = func_021D775C(18); *d = 0; if (k == 153 || k == 120) { if (func_021D775C(34) == 0) { *d = func_021D76BC(34,19); d[1] = k; } } }


void func_021DAE38(int unused, void *a, int id, int *f)
{
    u8 *r;
    u32 k;

    if (*f != 0) {
        k = (u8)func_021D775C(2);
        r = (u8 *)func_021C88A4(a, 4, id);
        ((struct Obj21317 *)r)->f0 |= 0x800000;
        func_021C8838(r + 4, 2, 0x389);
        func_021C8860((struct S *)(r + 4), k);
        func_021C8860((struct S *)(r + 4), f[1]);
        func_021C88C8(a, r);
        *f = 0;
    }
}
