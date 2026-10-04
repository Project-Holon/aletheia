/*
 * function: func_020163B0
 * address:  0x020163B0
 * packet:   pkt_020163B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Stores a word at +0x48.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj15687.h"

void func_020163B0(char *p, int v)
{
    ((struct Obj15687 *)p)->f48 = v;
}
