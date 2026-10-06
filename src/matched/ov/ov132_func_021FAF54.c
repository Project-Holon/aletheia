/*
 * function: func_021FAF54
 * address:  0x021FAF54
 * packet:   pkt_021FAF54
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10543.h"

typedef unsigned int   u32;
struct Cursor;
extern u32 func_0201134C(struct Cursor *p);

int func_021FAF54(int a, char *b)
{
    func_0201134C(((struct Obj10543 *)b)->f4);
    if (((struct Obj10543 *)b)->f16 & 2)
        ((struct Obj10543 *)b)->f16 |= 4;
    return 1;
}
