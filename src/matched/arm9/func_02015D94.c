/*
 * function: MCSS_SetShadowOffset
 * address:  0x02015D94
 * packet:   pkt_02015D94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x17C.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08771.h"

void MCSS_SetShadowOffset(char *p, int *src)
{
    ((struct Obj08771 *)p)->f17C = src[0];
    ((struct Obj08771 *)p)->f180 = src[1];
    ((struct Obj08771 *)p)->f184 = src[2];
}
