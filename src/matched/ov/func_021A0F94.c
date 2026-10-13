/*
 * function: FIELD_SUBSCREEN_GetPanelResult
 * address:  0x021A0F94
 * packet:   pkt_021A0F94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17991.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int FIELD_SUBSCREEN_GetPanelResult(u32 a)
{
if (a != 0) {
    return ((struct Obj17991 *)((u8 *)(a)))->f10;
}
return 0;
}

