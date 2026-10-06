/*
 * function: func_021DC054
 * address:  0x021DC054
 * packet:   pkt_ov093_021DC054
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj05217.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021B9A24(u32 a, u32 b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);

void func_021DC054(int u, void *a, u32 b)
{
    u8 *e;
    u8 v;
    if (b == func_021D775C(2)
        && (v = func_021D775C(3), func_021B9A24(b, v)) == 0
        && func_021D775C(0x20) < 0) {
        e = func_021C88A4(a, 0xe, b);
        ((struct Obj05217 *)e)->f0 |= 0x20 << 18;
        ((struct Obj05217 *)e)->f4 = 1;
        e[0xc] = 2;
        e[0xe] = 1;
        e[0xf] = 1;
        e[0x10] = b;
        func_021C88C8(a, e);
    }
}
