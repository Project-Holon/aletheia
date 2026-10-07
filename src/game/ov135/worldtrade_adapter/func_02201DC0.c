/*
 * function: func_02201DC0
 * address:  0x02201DC0
 * packet:   pkt_02201DC0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4EC0  0x021F4EC0  thumb  ov135
 *

 *
 * Enter the 201DC0 sub-state: flag the u16 at +0x32, set the two work values and stamp the state.
 */
#include "../../../matched/include/Obj12240.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern void func_021F4EC0(u8 *p, u32 a, u32 b);

int func_02201DC0(u8 *p)
{
    ((struct Obj12240 *)p)->f32 = 1;
    func_021F4EC0(p, 9, 7);
    ((struct Obj12240 *)p)->f28 = 0x28;
    return 2;
}
