/*
 * function: func_021FD6F0
 * address:  0x021FD6F0
 * packet:   pkt_021FD6F0
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FCEA8  0x021FCEA8  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23294.h"

typedef unsigned int   u32;
extern u32 func_021FCEA8(int unused, int kind, u32 value, u32 id);

void func_021FD6F0(char *p)
{
    func_021FCEA8((int)p, 6, *(int *)(((struct Obj23294 *)p)->f140 + 0x28), 0xff);
}
