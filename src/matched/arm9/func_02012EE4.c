/*
 * function: func_02012EE4
 * address:  0x02012EE4
 * packet:   pkt_02012EE4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf accessor: stores v at base + 0x688.
 *
 * symbols:
 *   func_02012EE4  0x02012EE4  thumb
 */
#include "../include/Obj15631.h"

char *func_02012EE4(char *base, int v)
{
    ((struct Obj15631 *)base)->f688 = v;
    return base;
}
