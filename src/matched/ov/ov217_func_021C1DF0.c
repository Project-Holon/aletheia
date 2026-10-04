/*
 * function: func_021C1DF0
 * address:  0x021C1DF0
 * packet:   pkt_021C1DF0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C0E08  0x021C0E08  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14762.h"

typedef unsigned short u16;

extern int func_021C0E08(int a0, int a1);

void func_021C1DF0(char *p)
{
    ((struct Obj14762 *)p)->fC = func_021C0E08(0xa, ((struct Obj14762 *)p)->f0);
}
