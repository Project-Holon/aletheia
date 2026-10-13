/*
 * function: FIELD_TILE_MOVE_GetSlideStepAcmd
 * address:  0x021C8CF8
 * packet:   pkt_021C8CF8
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
#include "../include/Obj12135.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int FIELD_TILE_MOVE_GetSlideStepAcmd(u32 a)
{
if (((struct Obj12135 *)((u8 *)(a)))->f10 != 0) {
    return *(u16 *)((u8 *)(((struct Obj12135 *)((u8 *)(a)))->f10) + 2);
}
return 0;
}

