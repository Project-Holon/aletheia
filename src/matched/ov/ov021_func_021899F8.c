/*
 * function: func_021899F8
 * address:  0x021899F8
 * packet:   pkt_ov021_021899F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf setter: the word at +0x12C.
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19502.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

void func_021899F8(u8 *p, u32 v)
{
    ((struct Obj19502 *)p)->f12C = v;
}
