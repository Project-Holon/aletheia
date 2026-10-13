/*
 * function: FIELD_TILE_MOVE_GetBumpAcmd
 * address:  0x021C8D08
 * packet:   pkt_021C8D08
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
#include "../include/Obj12136.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int FIELD_TILE_MOVE_GetBumpAcmd(u32 a)
{
if (((struct Obj12136 *)((u8 *)(a)))->f14 != 0) {
    return *(u16 *)((u8 *)(((struct Obj12136 *)((u8 *)(a)))->f14) + 2);
}
return 0;
}

