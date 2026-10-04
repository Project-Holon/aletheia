/*
 * function: func_02012FB0
 * address:  0x02012FB0
 * packet:   pkt_02012FB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor: reads the byte at base + 0x1CF.
 *
 * symbols:
 *   func_02012FB0  0x02012FB0  thumb
 */
#include "../include/Obj15639.h"

int func_02012FB0(unsigned char *base)
{
    return ((struct Obj15639 *)base)->f1CF;
}
