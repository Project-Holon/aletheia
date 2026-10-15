/*
 * function: WIFI_2DCHAR_ReleasePalette
 * address:  0x021C4594
 * packet:   pkt_021C4594
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14020.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void CLACT_ReleasePalette(u32 i);

void WIFI_2DCHAR_ReleasePalette(u8 *p)
{
    CLACT_ReleasePalette((u32)(((struct Obj14020 *)p)->f2F4));
    *(u32 *)&((struct Obj14020 *)p)->f2F4 = (u32)-1;
}
