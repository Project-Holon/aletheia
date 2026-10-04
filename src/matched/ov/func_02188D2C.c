/*
 * function: func_02188D2C
 * address:  0x02188D2C
 * packet:   pkt_02188D2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188D2C   0x02188D2C  thumb ov021
 *
 * Unlabelled ov021 leaf accessor: returns the word at +0x34 of its argument.
 * Matched to supply the `matched` witness for the ten pending callers that
 * reference it.
 */
#include "../include/Obj17877.h"

int func_02188D2C(int *p)
{
    return ((struct Obj17877 *)p)->f34;
}
