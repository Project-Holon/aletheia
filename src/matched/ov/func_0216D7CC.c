/*
 * function: func_0216D7CC
 * address:  0x0216D7CC
 * packet:   pkt_0216D7CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Increments the halfword at +0x28 of the object in r0.
 *
 * Filed as the TARGET of 27 ov021 `bl` sites (rule 10): ov010's listing emits
 * these 8 bytes as a `.word` because nothing traced an entry point here -- its
 * only callers are the ov021 sites -- so no `label` witness exists anywhere and
 * a region hint cannot invent one.  The source is the witness.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00113.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_0216D7CC(u8 *p)
{
    ((struct Obj00113 *)p)->f28 = ((struct Obj00113 *)p)->f28 + 1;
}
