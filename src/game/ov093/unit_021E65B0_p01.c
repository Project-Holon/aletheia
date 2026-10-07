/*
 * file:     unit_021E65B0_p01.c
 * unit:     yes
 * function: func_021E65B0, func_021E6654
 * address:  0x021E65B0
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
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_020213C0  0x020213C0  thumb
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F2B28     0x021F2B28  data   ov093  a4
 *   func_021D76BC   0x021D76BC  thumb
 */
#include "../../matched/include/Obj06277.h"

struct QI;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5B40(struct QI *p);
extern int func_020213C0(u32 a);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
void func_021E65B0(int u, void *a, u32 b);
int *func_021E6648(int *p);
/* 021E6654 shape F1: gate on func_021D775C(3) */ void func_021E6654(int a, int b, int c);
extern int d_021F2B28[];


void func_021E65B0(int u, void *a, u32 b)
{
    u8 *e;
    u8 k;
    u16 t;

    if (b == func_021D775C(3)) {
        k = func_021D775C(6);
        t = (int)func_021D5B40(func_021C7CF4(a, k));
        if (func_020213C0(t) != 0) {
            e = func_021C88A4(a, 0x20, b);
            e[6] = k;
            ((struct Obj06277 *)e)->f4 = 0;
            func_021C8838(e + 0xc, 2, 0x308);
            func_021C8860((struct S *)(e + 0xc), b);
            func_021C8860((struct S *)(e + 0xc), t);
            func_021C88C8(a, e);
            e = func_021C88A4(a, 0x22, b);
            ((struct Obj06277 *)e)->f0 |= 2 << 23;
            ((struct Obj06277 *)e)->f6 = t;
            e[4] = b;
            func_021C88C8(a, e);
        }
    }
}


int *func_021E6648(int *p)
{
    *p = 3;
    return d_021F2B28;
}


/* 021E6654  shape F1: gate on func_021D775C(3) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021E666A; movs r0, #0x51; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
void func_021E6654(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D76BC(0x51, 1);
}
