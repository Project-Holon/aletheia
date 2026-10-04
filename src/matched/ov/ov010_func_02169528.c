/*
 * function: func_02169528
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

void func_02169528(unsigned char *a, int *out)
{
    *out = ((struct Obj19043 *)a)->fD4;
}
