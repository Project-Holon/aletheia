/*
 * function: func_021BA150
 * address:  0x021BA150
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Set the u32 at +0x80 to 1.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25809.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BA150(void *p)
{
    ((struct Obj25809 *)p)->f80 = 1;
}
