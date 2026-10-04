/*
 * function: func_02015C94
 * address:  0x02015C94
 * packet:   pkt_02015C94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of the
 * structure at +0xEC. The inverse of func_02015CAC; same shape as
 * func_02015C30 one word-group further along.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08756.h"

typedef unsigned int u32;

void func_02015C94(void *p, u32 *out)
{
    out[0] = ((struct Obj08756 *)p)->fEC;
    out[1] = ((struct Obj08756 *)p)->fF0;
    out[2] = ((struct Obj08756 *)p)->fF4;
}
