/*
 * unit:     yes
 * function: func_021E7998, func_021E79FC
 * address:  0x021E7998
 * packet:   pkt_ov093_021E7998
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021E8940 returns a one-word struct: that is the `push {r3,..}; sub sp, #4`
 * frame word (docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md).
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021EF948  0x021EF948  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F2684     0x021F2684  data   ov093  a4
 */
#include "../include/Obj13545.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct Word { u32 v; } Word;

extern int func_021D775C(int key);
extern int func_021EF948(int k);
extern u8 *func_021C88A4(int a, int k, int c);
extern Word func_021E8940(int k);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int d_021F2684[];

void func_021E7998(int a, int b, int c)
{
    int k;
    u8 *p;

    if (c == func_021D775C(3)) {
        k = 6;
        if (func_021EF948(k) == 0) {
            p = func_021C88A4(b, 0x1b, c);
            ((struct Obj13545 *)p)->f4 = k;
            *(Word *)(p + 8) = func_021E8940(5);
            func_021C8838(p + 0x10, 1, 0xb2);
            func_021C88C8((void *)b, p);
        } else {
            p = func_021C88A4(b, 0x1c, c);
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
