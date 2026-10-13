/*
 * function: FIELD_G3D_MAP_GetTotalBytes
 * address:  0x02169538
 * packet:   pkt_ov010_02169538
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor: copies the word at +0xBC to *out.
 *
 * symbols:
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19047.h"

void FIELD_G3D_MAP_GetTotalBytes(unsigned char *a, int *out)
{
    *out = ((struct Obj19047 *)a)->fBC;
}
