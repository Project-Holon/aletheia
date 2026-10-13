/*
 * function: FIELD_PLAYER_NOGRID_IsBlocked
 * address:  0x021A59DC
 * packet:   pkt_021A59DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18054.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int FIELD_PLAYER_NOGRID_IsBlocked(u32 a)
{
if (((struct Obj18054 *)((u8 *)(a)))->f0 == 3) {
    return 1;
}
return 0;
}

