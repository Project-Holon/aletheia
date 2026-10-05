/*
 * function: func_02015D14
 * address:  0x02015D14
 * packet:   pkt_02015D14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0xF8. Inverse of func_02015CF8.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08763.h"

typedef unsigned int u32;

void func_02015D14(void *p, u32 *src)
{
    ((struct Obj08763 *)p)->fF8 = src[0];
    ((struct Obj08763 *)p)->fFC = src[1];
    ((struct Obj08763 *)p)->f100 = src[2];
}
