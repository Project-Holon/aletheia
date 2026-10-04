/*
 * function: func_021E48C0
 * address:  0x021E48C0
 * packet:   pkt_ov093_021E48C0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E899C  0x021E899C  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj06272.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct B { u16 lo:8; u16 mid:7; u16 hi:1; };

extern int func_021D775C(int key);
extern u8 *func_021C88A4(u8 *p, int a, int b);
extern int func_021E899C(u32 a);
extern void func_021C88C8(void *a, void *b);

void func_021E48C0(int a0, u8 *s, int k)
{
    u8 *e;

    if (k == func_021D775C(3)) {
        e = func_021C88A4(s, 0x1b, k);
        ((struct Obj06272 *)e)->f4 = 3;
        ((struct Obj06272 *)e)->f8 = func_021E899C(k);
        e[0xc] = 1;
        ((struct B *)(e + 0x12))->lo = 2;
        ((struct Obj06272 *)e)->f10 = 0x24a;
        ((struct B *)(e + 0x12))->mid = 1;
        ((struct Obj06272 *)e)->f14 = k;
        func_021C88C8(s, e);
    }
}
