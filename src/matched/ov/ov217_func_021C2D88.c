/*
 * function: func_021C2D88
 * address:  0x021C2D88
 * packet:   pkt_021C2D88
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call passing three fields (the last doubled).
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10968.h"

typedef unsigned char u8;

extern int func_02082D44(int, int, int);

int func_021C2D88(char *p)
{
    return func_02082D44(((struct Obj10968 *)p)->fC, ((struct Obj10968 *)p)->f8,
                         ((struct Obj10968 *)p)->f10 << 1);
}
