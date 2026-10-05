/*
 * function: func_02169530
 * address:  0x02169530
 * packet:   pkt_ov010_02169530
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf accessor: copies the word at +0x14 to *out.
 *
 * symbols:
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19045.h"

void func_02169530(unsigned char *a, int *out)
{
    *out = ((struct Obj19045 *)a)->f14;
}
