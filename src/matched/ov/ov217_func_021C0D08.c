/*
 * function: func_021C0D08
 * address:  0x021C0D08
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 44)) to func_021C29D8.
 *
 * symbols:
 *   func_021C29D8  0x021C29D8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25993.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 func_021C29D8(void *a0);

void func_021C0D08(u8 *a0)
{
    func_021C29D8((void *)(((struct Obj25993 *)a0)->f2C));
}

