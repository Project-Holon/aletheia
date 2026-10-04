/*
 * function: func_021C08F0
 * address:  0x021C08F0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 960)), 960 to func_02030EAC.
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25975.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02030EAC(u32, u32);

void func_021C08F0(u8 *a0, u32 a1)
{
    func_02030EAC((u32)(((struct Obj25975 *)a0)->f3C0), 960);
}

