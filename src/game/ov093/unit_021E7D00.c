/*
 * file:     unit_021E7D00.c
 * unit:     yes
 * function: func_021E7D00, func_021E7D48, func_021E7D54
 * address:  0x021E7D00
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
 *   func_0689D098  0x0689D098  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C812C  0x021C812C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021C8138  0x021C8138  thumb  ov093
 *   d_021F28C8     0x021F28C8  data   ov093  a4
 */
#include "../../matched/include/Obj21544.h"

struct S;
struct Q7;
struct QQ;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(struct S *l, u32 v);
extern void func_021C88C8(void *a, void *b);
extern u8 *func_021C812C(u8 *p);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern u16 func_021C8138(struct Q7 *p);
extern int func_0689D098(int a, int b, int c);
void func_021E7D00(int a, u8 *b, int c);
int *func_021E7D48(int *p);
void func_021E7D54(void *a, void *b, int c);
extern int d_021F28C8[];


void func_021E7D00(int a, u8 *b, int c)
{
    u8 *p;
    if (c == BTL_EVENT_GetVar(3)) {
        p = func_021C88A4((char *)b, 0x31, c);
        p[4] = BTL_EVENT_GetVar(6);
        func_021C8838(p + 8, 2, 1131);
        func_021C8860((struct S *)(p + 8), p[4]);
        func_021C88C8(b, p);
    }
}


int *func_021E7D48(int *p)
{
    *p = 2;
    return d_021F28C8;
}


void func_021E7D54(void *a, void *b, int c)
{
    int x;
    u16 y;
    u8 *p;
    if (c == BTL_EVENT_GetVar(2)) {
        x = (int)func_021C812C((u8 *)((int)b));
        y = BTL_EVENT_GetFactorKey(a);
        if (func_0689D098(x, y, func_021C8138(b)) == 1) {
            p = func_021C88A4(b, 0x30, c);
            ((struct Obj21544 *)p)->f4 = y;
            func_021C88C8(b, p);
        }
    }
}
