/*
 * function: FIELD_G3D_MAP_GetModelRes
 * address:  0x02169560
 * packet:   pkt_ov010_02169560
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf accessor: returns the word at +0x84.
 *
 * symbols:
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19049.h"

int FIELD_G3D_MAP_GetModelRes(unsigned char *a)
{
    return ((struct Obj19049 *)a)->f84;
}
