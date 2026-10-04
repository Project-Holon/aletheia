/*
 * function: func_021BF13C
 * address:  0x021BF13C
 * packet:   pkt_ov217_021BF13C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BF7CC 0x021BF7CC thumb ov217
 *   func_021C0F5C 0x021C0F5C thumb ov217
 *   d_021C369A 0x021C369A data a1
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25925.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 func_021BF7CC(void *p);
extern u32 func_021C0F5C(u32 a0, u32 a1);
extern u8 d_021C369A[];
void func_021BF13C(char *p)
{
    u32 o = ((struct Obj25925 *)p)->f350;
    u32 i = func_021BF7CC(p);
    func_021C0F5C(o, d_021C369A[i]);
}
