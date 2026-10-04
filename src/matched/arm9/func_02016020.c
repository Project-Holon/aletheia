/*
 * function: func_02016020
 * address:  0x02016020
 * packet:   pkt_02015F50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Stores its second
 * argument into the word at +0x30. Seeded from overlay call sites.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj15670.h"

typedef unsigned int u32;

void func_02016020(void *p, u32 v)
{
    ((struct Obj15670 *)p)->f30 = v;
}
