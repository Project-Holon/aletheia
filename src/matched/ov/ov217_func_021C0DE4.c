/*
 * function: ListViewState_Reset
 * address:  0x021C0DE4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear the byte at +0, the u32 at +4 and set the u32 at +8 to -0x18.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10965.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void ListViewState_Reset(void *p)
{
    ((struct Obj10965 *)p)->f0 = 0;
    ((struct Obj10965 *)p)->f4 = 0;
    ((struct Obj10965 *)p)->f8 = -0x18;
}
