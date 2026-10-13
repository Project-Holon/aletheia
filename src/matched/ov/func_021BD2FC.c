/*
 * function: PLACE_NAME_LETTER_GetHeightRaw
 * address:  0x021BD2FC
 * packet:   pkt_021BD2FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf byte getter at +0x41.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18227.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 PLACE_NAME_LETTER_GetHeightRaw(u8 *p)
{
    return ((struct Obj18227 *)p)->f41;
}
