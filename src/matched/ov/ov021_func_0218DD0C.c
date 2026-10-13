/*
 * function: FIELD_G3D_MAPPER_SlotResGetSlotIndex
 * address:  0x0218DD0C
 * packet:   pkt_ov021_0218DD0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor: returns the word at +0xC.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19553.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

int FIELD_G3D_MAPPER_SlotResGetSlotIndex(u8 *p)
{
    return ((struct Obj19553 *)p)->fC;
}
