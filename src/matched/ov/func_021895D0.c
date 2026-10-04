/*
 * function: func_021895D0
 * address:  0x021895D0
 * packet:   pkt_021895D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call passing the object, a pass-through argument and the leading u16.
 *
 * symbols:
 *   func_021895E8  0x021895E8  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09444.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021895E8(unsigned char *p, int id, int c);

void func_021895D0(u8 *p, u32 a)
{
    func_021895E8(p, a, ((struct Obj09444 *)p)->f0);
}
