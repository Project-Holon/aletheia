/*
 * function: func_021C6580
 * address:  0x021C6580
 * packet:   pkt_021C6580
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call on a strided element of the array at +8.
 *
 * symbols:
 *   func_021C6940  0x021C6940  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18310.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021C6940(u8 *p);

void func_021C6580(u8 *p, int i)
{
    func_021C6940((u8 *)(((struct Obj18310 *)p)->f8 + i * 0x2c));
}
