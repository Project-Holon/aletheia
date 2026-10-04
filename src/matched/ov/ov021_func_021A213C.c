/*
 * function: func_021A213C
 * address:  0x021A213C
 * packet:   pkt_ov021_021A213C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub, filed for the ov026 lane.
 *
 * symbols:
 *   func_021A213C 0x021A213C thumb ov021
 *   func_021A065C 0x021A065C thumb ov021
 */
#include "../include/Obj00954.h"

typedef unsigned char  u8;

extern int func_021A065C(u8 *p);

int func_021A213C(u8 *p)
{
    return func_021A065C(*(u8 * *)&((struct Obj00954 *)p)->f8);
}
