/*
 * function: FIELD_G3D_MAP_GetBuffer
 * address:  0x02169528
 * packet:   pkt_ov010_02169528
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor: copies the word at +0xD4 to *out.
 *
 * symbols:
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19043.h"

void FIELD_G3D_MAP_GetBuffer(unsigned char *a, int *out)
{
    *out = ((struct Obj19043 *)a)->fD4;
}
