/*
 * function: FIELD_FLASH_SetTweenSize
 * address:  0x021C7EF0
 * packet:   pkt_021C7EF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter at +0x0.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18327.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FIELD_FLASH_SetTweenSize(u8 *p, u32 v)
{
    ((struct Obj18327 *)p)->f0 = v;
}
