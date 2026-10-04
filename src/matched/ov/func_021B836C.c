/*
 * function: func_021B836C
 * address:  0x021B836C
 * packet:   pkt_021B836C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with a field of each argument.
 *
 * symbols:
 *   func_021B8820  0x021B8820  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18118.h"
#include "../include/Obj18119.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021B8820(u32 a, u32 b);

void func_021B836C(u8 *p, u8 *q)
{
    func_021B8820(((struct Obj18118 *)p)->f24, ((struct Obj18119 *)q)->f3C);
}
