/*
 * function: MCSS_GetOfsPosition
 * address:  0x02015C60
 * packet:   pkt_02015C60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0x11C. Twin of MCSS_SetOfsPosition.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08752.h"

typedef unsigned int u32;

void MCSS_GetOfsPosition(void *p, u32 *out)
{
    out[0] = ((struct Obj08752 *)p)->f11C;
    out[1] = ((struct Obj08752 *)p)->f120;
    out[2] = ((struct Obj08752 *)p)->f124;
}
