/*
 * function: FIELD_G3D_MAPPER_SlotResGetWfbc
 * address:  0x0218DD08
 * packet:   pkt_ov021_0218DD08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor: returns the word at +0x8.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19552.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

int FIELD_G3D_MAPPER_SlotResGetWfbc(u8 *p)
{
    return ((struct Obj19552 *)p)->f8;
}
