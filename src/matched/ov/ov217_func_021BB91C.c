/*
 * function: func_021BB91C
 * address:  0x021BB91C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Set the u32 at +0x158 to 1.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25845.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BB91C(void *p)
{
    ((struct Obj25845 *)p)->f158 = 1;
}
