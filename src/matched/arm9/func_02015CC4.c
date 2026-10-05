/*
 * function: func_02015CC4
 * address:  0x02015CC4
 * packet:   pkt_02015CC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0x128.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08757.h"

typedef unsigned int u32;

void func_02015CC4(void *p, u32 *out)
{
    out[0] = ((struct Obj08757 *)p)->f128;
    out[1] = ((struct Obj08757 *)p)->f12C;
    out[2] = ((struct Obj08757 *)p)->f130;
}
