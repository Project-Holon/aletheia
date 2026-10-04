/*
 * function: func_021BF11C
 * address:  0x021BF11C
 * packet:   pkt_ov217_021BF11C
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
 *   d_021C36B8 0x021C36B8 data a1
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25924.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 func_021BF7CC(void *p);
extern u32 func_021C0F5C(u32 a0, u32 a1);
extern u8 d_021C36B8[];
void func_021BF11C(char *p)
{
    u32 i = func_021BF7CC(p);
    func_021C0F5C(((struct Obj25924 *)p)->f34C, d_021C36B8[i]);
}
