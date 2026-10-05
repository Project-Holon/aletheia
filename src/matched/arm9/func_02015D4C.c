/*
 * function: func_02015D4C
 * address:  0x02015D4C
 * packet:   pkt_02015D4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0x110.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08767.h"

typedef unsigned int u32;

void func_02015D4C(void *p, u32 *out)
{
    out[0] = ((struct Obj08767 *)p)->f110;
    out[1] = ((struct Obj08767 *)p)->f114;
    out[2] = ((struct Obj08767 *)p)->f118;
}
