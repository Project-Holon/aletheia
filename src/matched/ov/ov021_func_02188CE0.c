/*
 * function: func_02188CE0
 * address:  0x02188CE0
 * packet:   pkt_ov021_02188CE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf getter at +0x98 (between func_02188CD8 and
 * func_02188CE8); sole blocker of ov019 func_0217B264's call.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19490.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

u32 func_02188CE0(u8 *p)
{
    return ((struct Obj19490 *)p)->f98;
}
