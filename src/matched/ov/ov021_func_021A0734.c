/*
 * function: FIELD_LIGHT_LoadZoneTable
 * address:  0x021A0734
 * packet:   pkt_ov021_021A0734
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_LIGHT_LoadTable  0x021A0748  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19696.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void FIELD_LIGHT_LoadTable(u8 *a, u32 b, u32 c);

void FIELD_LIGHT_LoadZoneTable(u8 *a, u32 b)
{
    ((struct Obj19696 *)a)->f354 = b;
    FIELD_LIGHT_LoadTable(a, 0x3d, b);
}
