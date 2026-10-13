/*
 * function: FIELD_SUBSCREEN_GetMenuSelectedButton
 * address:  0x021A12A4
 * packet:   pkt_021A12A4
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
 *   FIELD_SUBSCREEN_GetMode  0x021A0F90  thumb  ov021
 *   FIELD_MENU_GetSelectedButtonId  0x021A8E10  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17993.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_SUBSCREEN_GetMode(u8 *p);
extern u32 FIELD_MENU_GetSelectedButtonId(u32);

u32 FIELD_SUBSCREEN_GetMenuSelectedButton(void *a)
{
if (FIELD_SUBSCREEN_GetMode((u8 *)a) != 1) {
    return 0;
}
return FIELD_MENU_GetSelectedButtonId(((struct Obj17993 *)((u8 *)(a)))->f20);
}

