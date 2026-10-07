/*
 * file:     btl_server_p114.c
 * unit:     yes
 * function: func_021CBEA8, func_021CBF30, func_021CBF40, func_021CBF50
 * address:  0x021CBEA8
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
 *   func_021B873C  0x021B873C  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021CC350   0x021CC350  thumb
 */
#include "../../matched/include/Obj09980.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern u32 func_021B873C(char **p);
extern u32 func_021D78AC(u32 range);
int func_021CBEA8(u8 *p, int x);
/* 021CBF30 stack-arg wrapper: func_021CC350(a, b, c, d, 0x2) */ void func_021CBF30(int a, int b, int c, int d);
/* 021CBF40 stack-arg wrapper: func_021CC350(a, b, c, d, 0x5) */ void func_021CBF40(int a, int b, int c, int d);
/* 021CBF50 stack-arg wrapper: func_021CC350(a, b, c, d, 0x4) */ void func_021CBF50(int a, int b, int c, int d);


/*
 * note:     the divide by 6 belongs to the fixed-point multiply's statement
 *           (`x = FX_MUL(x, k) / 6;`); the `>> 12` goes inside the compare.
 *           A separate `q = x / 6;` statement lets the compiler move the
 *           divide after the call, and a separate shift statement moves the
 *           shift before it.
 */
int func_021CBEA8(u8 *p, int x)
{
    u32 v = func_021B873C(*(char ** *)&((struct Obj09980 *)p)->f4);
    int k;
    if (v > 600) k = 0x2800;
    else if (v > 450) k = 0x2000;
    else if (v > 300) k = 0x1800;
    else if (v > 150) k = 0x1000;
    else if (v > 30) k = 0x800;
    else return 0;
    if (x > 0xff000) x = 0xff000;
    x = (int)(((long long)x * k + 0x800) >> 12) / 6;
    if (func_021D78AC(256) < (u32)(x >> 12))
        return 1;
    return 0;
}


/* 021CBF30  stack-arg wrapper: func_021CC350(a, b, c, d, 0x2) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #2; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF30(int a, int b, int c, int d) { func_021CC350(a, b, c, d, 0x2); }


/* 021CBF40  stack-arg wrapper: func_021CC350(a, b, c, d, 0x5) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #5; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF40(int a, int b, int c, int d) { func_021CC350(a, b, c, d, 0x5); }


/* 021CBF50  stack-arg wrapper: func_021CC350(a, b, c, d, 0x4) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #4; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF50(int a, int b, int c, int d) { func_021CC350(a, b, c, d, 0x4); }
