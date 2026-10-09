/*
 * file:     unit_021DB560.c
 * unit:     yes
 * function: func_021DB560, func_021DB5B4, func_021DB5C0, func_021DB62C, func_021DB644
 * address:  0x021DB560
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
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7090   0x021D7090  thumb
 *   d_021F05F0     0x021F05F0  data   ov093  a4
 *   d_021F0920     0x021F0920  data   ov093  a4
 */
#include "../../matched/include/Obj21328.h"
#include "../../matched/include/Obj07814.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
void func_021DB560(void *a, void *p, int id);
int *func_021DB5B4(int *p);
void func_021DB5C0(void *a, void *p, int id);
void func_021DB62C(int a, int b, int c);
int *func_021DB644(int *p);
extern int d_021F05F0[];
extern int d_021F0920[];


void func_021DB560(void *a, void *p, int id)
{
    u8 *r;

    if (id == func_021D775C(4)) {
        if (func_021D76BC(0x41, 1) != 0) {
            r = (u8 *)func_021C88A4(p, 4, id);
            ((struct Obj21328 *)r)->f0 |= 0x800000;
            func_021C8838(r + 4, 2, 0x1c6);
            func_021C8860((struct S *)(r + 4), id);
            func_021C88C8(p, r);
        }
    }
}


int *func_021DB5B4(int *p)
{
    *p = 1;
    return d_021F05F0;
}


void func_021DB5C0(void *a, void *p, int id)
{
    u16 v;
    u8 *r;

    if (id == func_021D775C(4)) {
        v = func_021D775C(0x20);
        func_021D76BC(0x20, 0);
        if (v != 0) {
            r = (u8 *)func_021C88A4(p, 7, id);
            ((struct Obj07814 *)r)->f0 |= 0x800000;
            r[6] = func_021D775C(3);
            ((struct Obj07814 *)r)->f4 = v;
            func_021C8838(r + 0xc, 2, 0x1c9);
            func_021C8860((struct S *)(r + 0xc), r[6]);
            func_021C88C8(p, r);
        }
    }
}



/* 021DB62C  shape F3: gate on func_021D775C(2) then func_021D7090 */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r3, r4, r5, lr}; adds r5, r0, #0; movs r0, #2; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021DB642; adds r0, r5, #0; bl func_021D7090; pop {r3, r4, r5, pc}.
 */
void func_021DB62C(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D7090(a);
}


int *func_021DB644(int *p)
{
    *p = 2;
    return d_021F0920;
}
