/*
 * function: func_021F5FC0
 * address:  0x021F5FC0
 * packet:   pkt_021F5FC0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4D50  0x021F4D50  thumb  ov135

 * Create the resource, register the three 68/69/6a entries and latch state 0x8.
 */
#include "../include/Obj00448.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern u32 func_0201F81C(u32 a, u32 b);
extern void func_0201F878(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_021F4D50(u8 *p, u16 a, int count, int b);

int func_021F5FC0(u8 *p)
{
    *(u32 *)&((struct Obj00448 *)p)->fDE8 = func_0201F81C(3, 0x48);
    func_0201F878(*(u32 *)&((struct Obj00448 *)p)->fDE8, *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x68, 1, 0x48);
    func_0201F878(*(u32 *)&((struct Obj00448 *)p)->fDE8, *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x69, 2, 0x48);
    func_0201F878(*(u32 *)&((struct Obj00448 *)p)->fDE8, *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x6a, 3, 0x48);
    func_021F4D50(p, 0, 3, 0x14);
    ((struct Obj00448 *)p)->f28 = 0x8;
    return 2;
}
