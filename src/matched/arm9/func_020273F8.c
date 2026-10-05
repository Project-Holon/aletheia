/*
 * function: func_020273F8
 * address:  0x020273F8
 * packet:   pkt_020273F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 *
 * symbols:
 *   func_020273F8  0x020273F8  thumb
 */
#include "../include/Obj05718.h"

void func_020273F8(char *p, unsigned short v)
{
    ((struct Obj05718 *)p)->f48 = (((struct Obj05718 *)p)->f48 & ~0xff) | 2;
    ((struct Obj05718 *)p)->f4E = v;
}
