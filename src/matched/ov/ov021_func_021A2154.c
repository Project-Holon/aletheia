/*
 * function: func_021A2154
 * address:  0x021A2154
 * packet:   pkt_ov021_021A2154
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
 *   func_021A2154 0x021A2154 thumb ov021
 *   func_021A063C 0x021A063C thumb ov021
 */
#include "../include/Obj00954.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void func_021A063C(u8 *p, u32 b, u32 c);

void func_021A2154(u8 *p, u32 b, u32 c)
{
    func_021A063C(*(u8 * *)&((struct Obj00954 *)p)->f8, b, c);
}
