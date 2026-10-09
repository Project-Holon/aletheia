/*
 * file:     unit_021E7924.c
 * unit:     yes
 * function: func_021E7924, func_021E7950, func_021E795C, func_021E7974, func_021E798C, func_021E7998, func_021E7A08, func_021E7A78
 * address:  0x021E7924
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
 *   d_021F2998     0x021F2998  data   ov093  a4
 *   func_021EF948  0x021EF948  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F2684     0x021F2684  data   ov093  a4
 *   d_021F265C     0x021F265C  data   ov093  a4
 *   func_021C7D34 0x021C7D34 thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D7B74 0x021D7B74 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   d_021F2634 0x021F2634 data a4
 *   d_021F269C     0x021F269C  data   ov093  a4
 */
#include "../../matched/include/Obj13545.h"
#include "../../matched/include/Obj13546.h"
#include "../../matched/include/Obj10101.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct Word { u32 v; } Word;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 val);
extern int func_021EF948(int k);
extern void *func_021C88A4(char *p, int a, int b);
extern Word func_021E8940(int k);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int func_021C7D34(char *p, int i);
extern u8 func_021C7F68(int *, int, u8 *);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C8860(struct S *, u32);
void func_021E7924(int a, int b, int c);
int *func_021E7950(int *p);
void func_021E795C(int a, int b, int c);
void func_021E7974(int a, int b, int c);
int *func_021E798C(int *p);
void func_021E7998(int a, int b, int c);
int *func_021E79FC(int *p);
void func_021E7A08(int a, int b, int c);
int *func_021E7A6C(int *p);
void func_021E7A78(int a, int b, int c);
int *func_021E7B34(int *p);
/* 021E795C  shape F1: gate on func_021D775C(3) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021E7972; movs r0, #0x51; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
extern int d_021F2998[];
extern int d_021F2684[];
extern int d_021F265C[];
extern int d_021F2634[];
/*
 * func_021E8940 returns a one-word struct: that is the `push {r3,..}; sub sp, #4`
 * frame word (docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md).
 */
extern int d_021F269C[];



void func_021E7924(int a, int b, int c)
{
    if (c == func_021D775C(3) && func_021D775C(0x3c) == 0xb)
        func_021D76BC(0x3d, func_021D775C(0x3d) + 1);
}



int *func_021E7950(int *p)
{
    *p = 2;
    return d_021F2998;
}



void func_021E795C(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D76BC(0x51, 1);
}




/* 021E7974  shape F1: gate on func_021D775C(3) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021E798A; movs r0, #0x4b; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
void func_021E7974(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D76BC(0x4b, 1);
}


int *func_021E798C(int *p)
{
    *p = 1;
    return d_021F269C;
}


void func_021E7998(int a, int b, int c)
{
    int k;
    u8 *p;

    if (c == func_021D775C(3)) {
        k = 6;
        if (func_021EF948(k) == 0) {
            p = func_021C88A4((char *)b, 0x1b, c);
            ((struct Obj13545 *)p)->f4 = k;
            *(Word *)(p + 8) = func_021E8940(5);
            func_021C8838(p + 0x10, 1, 0xb2);
            func_021C88C8((void *)b, p);
        } else {
            p = func_021C88A4((char *)b, 0x1c, c);
            ((struct Obj13545 *)p)->f4 = k;
            func_021C88C8((void *)b, p);
        }
    }
}



int *func_021E79FC(int *p)
{
    *p = 1;
    return d_021F2684;
}



void func_021E7A08(int a, int b, int c)
{
    int k;
    u8 *p;

    if (c == func_021D775C(3)) {
        k = 7;
        if (func_021EF948(k) == 0) {
            p = func_021C88A4((char *)b, 0x1b, c);
            ((struct Obj13546 *)p)->f4 = k;
            *(Word *)(p + 8) = func_021E8940(5);
            func_021C8838(p + 0x10, 1, 0xb4);
            func_021C88C8((void *)b, p);
        } else {
            p = func_021C88A4((char *)b, 0x1c, c);
            ((struct Obj13546 *)p)->f4 = k;
            func_021C88C8((void *)b, p);
        }
    }
}



int *func_021E7A6C(int *p)
{
    *p = 1;
    return d_021F265C;
}



/*
 * lever: the byte-valued count remains u8; +7 is a one-bit field assignment.
 */
void func_021E7A78(int a, int b, int c)
{
    u8 list[4];
    u8 k, i;
    u8 n;
    int slot;
    u8 *x;
    u8 *p;
    if (c == func_021D775C(3)) {
        k = func_021D775C(4);
        slot = func_021C7D34((char *)b, k);
        if (slot != 6) {
            n = func_021C7F68((int *)b, (u16)(0x900 | slot), list);
            for (i = 0; i < n; i++) {
                if (list[i] != k) {
                    x = func_021C7CF4((int *)b, list[i]);
                    p = func_021C88A4((char *)b, 7, c);
                    p[6] = list[i];
                    ((struct Obj10101 *)p)->f4 = func_021D7B74(x, 16);
                    ((struct Flag { u8 bit : 1; } *)(p + 7))->bit = 1;
                    func_021C8838(p + 12, 2, 0x451);
                    func_021C8860((struct S *)(p + 12), p[6]);
                    func_021C88C8((void *)b, p);
                }
            }
        }
    }
}



int *func_021E7B34(int *p)
{
    *p = 1;
    return d_021F2634;
}
