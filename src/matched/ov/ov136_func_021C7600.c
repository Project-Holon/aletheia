/*
 * function: func_021C7600
 * address:  0x021C7600
 * packet:   pkt_ov136_021C7600
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C7178 0x021C7178 thumb
 *   func_021C7430 0x021C7430 thumb
 */
#include "../include/Obj10611.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C7430(u8 *, int, u16, u16);
extern int func_021C7178(u8 *, u32);
int func_021C7600(u8 *p)
{
    func_021C7430(p, 9, ((struct Obj10611 *)p)->f22, 0);
    ((struct Obj10611 *)p)->f14 = 1;
    ((struct Obj10611 *)p)->f28 = 6;
    return func_021C7178(p, 1);
}
