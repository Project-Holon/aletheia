/*
 * function: func_021B8108
 * address:  0x021B8108
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Test the u32 at +0x08 against 7.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24080.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

int func_021B8108(void *unused, void *p)
{
    if (((struct Obj24080 *)p)->f8 == 7) {
        return 1;
    }
    return 0;
}
