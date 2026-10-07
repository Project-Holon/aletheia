/*
 * file:     unit_021E324C_p02.c
 * unit:     yes
 * function: func_021E3330, func_021E338C, func_021E33BC, func_021E33EC
 * address:  0x021E3330
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
 *   func_021C824C  0x021C824C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021D805C  0x021D805C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../../matched/include/Obj21473.h"

struct QI;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021C824C(u8 *p, int v);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5B40(struct QI *p);
extern u32 func_021D805C(void *p, u32 n);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
void func_021E3330(int u, void *p, int key);
void func_021E338C(int u, void *a, int b);
void func_021E33BC(int u, void *a, int b);
void func_021E33EC(int u, int a, int b);


void func_021E3330(int u, void *p, int key)
{
    u16 x;
    int k;
    if (key == func_021D775C(2)) {
        if (func_021C824C(p, key) == 0) {
            func_021D76BC(0x22, 0x1a);
            return;
        }
        x = (u16)(int)func_021D5B40(func_021C7CF4(p, key));
        k = 11;
        func_021D805C((void *)x, k);
        if (x == 0 || func_021D805C((void *)x, k) == 0)
            func_021D76BC(0x22, 0x1a);
    }
}


void func_021E338C(int u, void *a, int b)
{
    if (b == func_021D775C(2))
        func_021D76BC(0x16, func_021D805C((void *)((u16)(int)func_021D5B40(func_021C7CF4(a, b))), 0xc));
}


void func_021E33BC(int u, void *a, int b)
{
    if (b == func_021D775C(3))
        func_021D76BC(0x30, func_021D805C((void *)((u16)(int)func_021D5B40(func_021C7CF4(a, b))), 0xb));
}


void func_021E33EC(int u, int a, int b)
{
    u8 *s;

    if (b == func_021D775C(2)) {
        s = func_021C88A4((char *)a, 0x23, b);
        ((struct Obj21473 *)s)->f4 = 1;
        func_021C88C8((void *)a, s);
    }
}
