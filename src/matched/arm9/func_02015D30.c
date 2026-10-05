/*
 * function: func_02015D30
 * address:  0x02015D30
 * packet:   pkt_02015D30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x104.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08765.h"

typedef unsigned int u32;

void func_02015D30(void *p, u32 *src)
{
    ((struct Obj08765 *)p)->f104 = src[0];
    ((struct Obj08765 *)p)->f108 = src[1];
    ((struct Obj08765 *)p)->f10C = src[2];
}
