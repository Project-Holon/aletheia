/*
 * function: func_0200E5CC
 * address:  0x0200E5CC
 * packet:   pkt_0200E5CC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled arm9 leaf: true when bit 15 of the halfword at +0x5C4 is clear.
 * Filed as the relocation witness for ov021 func_021D09D0 (wave A1).
 */
#include "../include/Obj15607.h"

typedef unsigned short u16;

int func_0200E5CC(void *p)
{
    if (((struct Obj15607 *)p)->f5C4 & 0x8000) {
        return 0;
    }
    return 1;
}
