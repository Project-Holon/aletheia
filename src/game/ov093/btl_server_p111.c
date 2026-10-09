/*
 * file:     btl_server_p111.c
 * unit:     yes
 * function: func_021CBEA8, func_021CBF30, func_021CBF40, func_021CBF50, func_021CBF60, func_021CBF70, func_021CBF80, func_021CBF90, func_021CBFA0
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
 *   func_021CC398   0x021CC398  thumb
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021CBFF8  0x021CBFF8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../../matched/include/Obj09980.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct Word { u32 v; } Word;

extern u32 func_021B873C(char **p);
extern u32 func_021D78AC(u32 range);
extern u8 func_021D5440(u8 *p);
extern unsigned char func_021B9A40(unsigned int x);
extern Word func_021E8940(int v);
extern int func_021CBFF8(int a, int b, Word c);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);
int func_021CBEA8(u8 *p, int x);
void func_021CBF30(int a, int b, int c, int d);
void func_021CBF40(int a, int b, int c, int d);
void func_021CBF50(int a, int b, int c, int d);
void func_021CBF60(int a, int b, int c, int d);
void func_021CBF70(int a, int b, int c, int d);
void func_021CBF80(int a, int b, int c, int d);
void func_021CBF90(int a, int b, int c, int d);
int func_021CBFA0(u8 *p, u8 *q);




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




/* 021CBF60  stack-arg wrapper: func_021CC350(a, b, c, d, 0x3) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #3; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF60(int a, int b, int c, int d) { func_021CC350(a, b, c, d, 0x3); }




/* 021CBF70  stack-arg wrapper: func_021CC350(a, b, c, d, 0x1) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #1; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF70(int a, int b, int c, int d) { func_021CC350(a, b, c, d, 0x1); }




/* 021CBF80  stack-arg wrapper: func_021CC350(a, b, c, d, 0x6) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #6; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF80(int a, int b, int c, int d) { func_021CC350(a, b, c, d, 0x6); }



/* 021CBF90  stack-arg wrapper: func_021CC398(a, b, c, d, 0x7) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #7; str r4, [sp]; bl func_021CC398; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF90(int a, int b, int c, int d) { func_021CC398(a, b, c, d, 0x7); }



int func_021CBFA0(u8 *p, u8 *q)
{
    int m;
    u8 *w;
    Word t;
    m = func_021B9A40(func_021D5440(q));
    t = func_021E8940(5);
    if (func_021CBFF8(m, 3, t)) {
        w = func_021C88A4((char *)p, 4, 0x1f);
        func_021C8838(w + 4, 1, 0x88);
        func_021C8860((struct S *)(w + 4), m);
        func_021C88C8(p, w);
        return 1;
    }
    return 0;
}
