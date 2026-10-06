/*
 * function: func_021C1DCC
 * address:  0x021C1DCC
 * packet:   pkt_ov093_021C1DCC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0201C1BC   0x0201C1BC  thumb
 *   sub_0201BD28   0x0201BD28  thumb
 *   func_021D7B3C  0x021D7B3C  thumb  ov093
 *   func_021C1E14  0x021C1E14  thumb  ov093
 *   func_021C5D88  0x021C5D88  thumb  ov093
 */
#include "../include/Obj09967.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 sub_0201C1BC(u16 move);
extern u32 sub_0201BD28(u16 id, u32 field);
extern u32 func_021D7B3C(u32 a, u32 b);
extern int func_021C1E14(u8 *p, u8 *q, u32 a, u32 b);
extern void func_021C5D88(u8 *p, u8 *a, int b);

void func_021C1DCC(u8 *p, u8 *q, u32 a, u8 *b, u32 s)
{
    if (sub_0201C1BC(((struct Obj09967 *)q)->f0) == 8) {
        if (func_021C1E14(p, (u8 *)a, (u32)b, (u16)func_021D7B3C(s, sub_0201BD28(((struct Obj09967 *)q)->f0, 0x19)))) {
            func_021C5D88(p, b, 0x383);
        }
    }
}
