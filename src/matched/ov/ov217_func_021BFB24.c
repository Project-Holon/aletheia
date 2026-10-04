/*
 * function: func_021BFB24
 * address:  0x021BFB24
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 28)) to func_021C0E3C.
 *
 * symbols:
 *   func_021C0E3C  0x021C0E3C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25949.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C0E3C(void *p);

void func_021BFB24(u8 *a0)
{
    func_021C0E3C((void *)((u32)(((struct Obj25949 *)a0)->f1C)));
}

