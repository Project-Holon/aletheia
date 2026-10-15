/*
 * function: CTVT_COMM_GetMarkerSlot
 * address:  0x021B8B68
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u8 at +0x3ae of the second argument.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24088.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u8 CTVT_COMM_GetMarkerSlot(int unused, char *p)
{
    return ((struct Obj24088 *)p)->f3AE;
}
