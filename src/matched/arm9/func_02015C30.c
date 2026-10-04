/*
 * function: func_02015C30
 * address:  0x02015C30
 * packet:   pkt_02015C30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module (saves nothing, so disasm.py emits
 * it as a run of .word). Copies three words out of the structure at +0xE0.
 * The inverse of func_02015C48; in the ov118 event state machine
 * (0x021D7130) it is the out-direction marshaller.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08751.h"

typedef unsigned int u32;

void func_02015C30(void *p, u32 *out)
{
    out[0] = ((struct Obj08751 *)p)->fE0;
    out[1] = ((struct Obj08751 *)p)->fE4;
    out[2] = ((struct Obj08751 *)p)->fE8;
}
