/*
 * file:     unit_021E61BC.c
 * unit:     yes
 * function: func_021E61BC, func_021E6210, func_021E6214, func_021E6220, func_021E6278
 * address:  0x021E61BC
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
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   d_021F2AA8     0x021F2AA8  data   ov093  a4
 *   d_021F2F40     0x021F2F40  data   ov093  a4
 */
#include "../../matched/include/Obj13530.h"
#include "../../matched/include/Obj13531.h"
#include "../../matched/include/Obj13532.h"

struct S;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(struct S *l, u32 v);
extern void func_021C88C8(void *a, void *b);
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
void func_021E61BC(u8 *p, void *a, int b);
void func_021E6210(void);
int *func_021E6214(int *p);
void func_021E6220(int u, void *a, u32 b);
void func_021E6274(void);
void func_021E6278(int u, void *a, u32 b);
int *func_021E62E8(int *p);
extern int d_021F2AA8[];
extern int d_021F2F40[];


void func_021E61BC(u8 *p, void *a, int b)
{
    u8 *q;
    u8 *r;
    if (b != BTL_EVENT_GetVar(3))
        return;
    q = func_021C88A4(a, 0x17, b);
    q[8] = b;
    ((struct Obj13530 *)q)->f4 = 3;
    func_021C88C8(a, q);
    r = func_021C88A4(a, 4, b);
    func_021C8838(r + 4, 2, 0x211);
    func_021C8860((struct S *)(r + 4), b);
    func_021C88C8(a, r);
}


void func_021E6210(void)
{
}


int *func_021E6214(int *p)
{
    *p = 5;
    return d_021F2F40;
}


void func_021E6220(int u, void *a, u32 b)
{
    u8 *e;

    if (b == BTL_EVENT_GetVar(3)) {
        e = func_021C88A4(a, 0x17, b);
        e[8] = b;
        ((struct Obj13531 *)e)->f4 = 6;
        func_021C88C8(a, e);
        e = func_021C88A4(a, 4, b);
        func_021C8838(e + 4, 2, 0x21d);
        func_021C8860((struct S *)(e + 4), b);
        func_021C88C8(a, e);
    }
}



void func_021E6274(void)
{
}



void func_021E6278(int u, void *a, u32 b)
{
    u8 *e;
    u8 k;

    if (b == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        if (BTL_POKEPARAM_TestTurnFlag(func_021C7CF4(a, k), 7) != 0) {
            e = func_021C88A4(a, 0x16, b);
            e[8] = k;
            ((struct Obj13532 *)e)->f4 = 7;
            func_021C88C8(a, e);
            e = func_021C88A4(a, 4, b);
            func_021C8838(e + 4, 2, 0x208);
            func_021C8860((struct S *)(e + 4), k);
            func_021C88C8(a, e);
        }
    }
}



int *func_021E62E8(int *p)
{
    *p = 2;
    return d_021F2AA8;
}
