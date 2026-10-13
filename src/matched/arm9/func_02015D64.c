/*
 * function: MCSS_SetDrawScale
 * address:  0x02015D64
 * packet:   pkt_02015D64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x110. Inverse of MCSS_GetDrawScale.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08769.h"

typedef unsigned int u32;

void MCSS_SetDrawScale(void *p, u32 *src)
{
    ((struct Obj08769 *)p)->f110 = src[0];
    ((struct Obj08769 *)p)->f114 = src[1];
    ((struct Obj08769 *)p)->f118 = src[2];
}
