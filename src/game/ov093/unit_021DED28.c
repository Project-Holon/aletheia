/*
 * file:     unit_021DED28.c
 * unit:     yes
 * function: func_021DED28, func_021DED60, func_021DED6C, func_021DEDEC
 * address:  0x021DED28
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
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021E8C9C  0x021E8C9C  thumb  ov093
 *   func_021DCFF8   0x021DCFF8  thumb ov093
 *   func_021D70A8   0x021D70A8  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   func_0209C2B0   0x0209C2B0  arm
 *   d_021F152C     0x021F152C  data   ov093  a4
 *   d_021F143C     0x021F143C  data   ov093  a4
 */
#include "../../matched/include/Obj12154.h"

union U;
struct QQ;
struct S;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 val);
extern void func_021E8C9C(union U *p, int v);
int func_021DCFF8(int a, int b);
int func_0209C2B0(int a, int b);
extern u16 func_021D70A8(struct QQ *p);
void *func_021C88A4(char *p, int a, int b);
void func_021C8838(void *p, int a, int b);
void func_021C8860(struct S *p, unsigned int a);
void func_021C88C8(void *a, void *b);
void func_021DED28(int a, int b, int c);
int *func_021DED60(int *p);
void func_021DED6C(void *a, int b, int c);
int *func_021DEDEC(int *p);
extern int d_021F152C[];
extern int d_021F143C[];


void func_021DED28(int a, int b, int c)
{
    int t;

    if (c == func_021D775C(3) && func_021D775C(0x1d) == 8) {
        t = func_021D775C(0x1e);
        func_021E8C9C((union U *)(&t), 8);
        func_021D76BC(0x1e, t);
    }
}


int *func_021DED60(int *p)
{
    *p = 1;
    return d_021F152C;
}


/*
 * Three func_021D775C gates (3, 0x4d zero, 0x32 non-zero), then the 0x32
 * handle and func_021DCFF8(a, 2) go to the ARM helper at 0x0209C2B0, whose
 * zero result becomes 1.  Record #5 gets c and that halfword plus the same
 * two-string tail as func_021DD908.  The second argument lives on the stack
 * because all six saved registers are taken.
 */
void func_021DED6C(void *a, int b, int c)
{
    int r, v;
    u8 *p;

    if (c != func_021D775C(3))
        return;
    if (func_021D775C(0x4d) != 0)
        return;
    r = func_021D775C(0x32);
    if (r == 0)
        return;
    v = func_0209C2B0(r, func_021DCFF8((int)a, 2));
    if (v == 0)
        v = 1;
    p = func_021C88A4((char *)b, 5, c);
    ((struct Obj12154 *)p)->f6 = c;
    ((struct Obj12154 *)p)->f4 = v;
    func_021C8838(p + 8, 2, 0x392);
    func_021C8860((struct S *)(p + 8), c);
    func_021C8860((struct S *)(p + 8), func_021D70A8(a));
    func_021C88C8((void *)b, p);
}


int *func_021DEDEC(int *p)
{
    *p = 1;
    return d_021F143C;
}
