/*
 * function: func_02015FF0
 * address:  0x02015FF0
 * packet:   pkt_02015FF0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 *
 * symbols:
 *   func_02015FF0  0x02015FF0  thumb
 */
#include "../include/Obj00933.h"

void func_02015FF0(char *p, int v)
{
    ((struct Obj00933 *)p)->f140 = (((struct Obj00933 *)p)->f140 & 0xFF7FFFFF) | ((v & 1) << 23);
}
