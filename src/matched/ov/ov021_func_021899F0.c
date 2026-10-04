/*
 * function: func_021899F0
 * address:  0x021899F0
 * packet:   pkt_ov021_021899F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf getter: the word at +0x12C (func_021899F8 is its setter).
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19501.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

u32 func_021899F0(u8 *p)
{
    return ((struct Obj19501 *)p)->f12C;
}
