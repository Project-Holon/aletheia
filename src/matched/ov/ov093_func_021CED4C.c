/*
 * function: func_021CED4C
 * address:  0x021CED4C
 * packet:   pkt_ov093_021CED4C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9CE0  0x021E9CE0  thumb  ov093
 *   func_021CE0BC  0x021CE0BC  thumb  ov093
 *   func_021E9B14  0x021E9B14  thumb  ov093
 *   func_021E9B20  0x021E9B20  thumb  ov093
 *   func_021CE150  0x021CE150  thumb  ov093
 *   func_021CEA94  0x021CEA94  thumb  ov093
 *   func_021CE3C8  0x021CE3C8  thumb  ov093
 */
#include "../include/Obj05199.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021E9CE0(u8 *p, u8 a, u8 b);
extern int func_021CE0BC(u8 *p, void *q);
extern void func_021E9B14(unsigned int *p);
extern int func_021E9B20(u8 *p);
extern void func_021CE150(u8 *p, void *q);
extern int func_021CEA94(u8 *p, u32 *state);
extern int func_021CE3C8(u8 *p, int *state);

u32 func_021CED4C(u8 *p, s32 *st)
{
    u32 r;
    switch (*st) {
    case 0:
        func_021E9CE0((u8 *)(((struct Obj05199 *)p)->f54), p[0x1b0], p[0x1b1]);
        *st = *st + 1;
        break;
    case 1:
        r = 0;
        if (func_021CE0BC(p, 0) != 0) {
            func_021E9B14((unsigned int *)(((struct Obj05199 *)p)->f54));
            *st = 2;
            return r;
        }
        if (func_021E9B20((u8 *)(((struct Obj05199 *)p)->f54)) != 0) {
            func_021CE150(p, (void *)((u32)func_021CEA94));
        }
        break;
    case 2:
        if (func_021E9B20((u8 *)(((struct Obj05199 *)p)->f54)) != 0) {
            func_021CE150(p, (void *)((u32)func_021CE3C8));
        }
        break;
    }
    return 0;
}
