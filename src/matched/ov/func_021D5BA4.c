/*
 * function: func_021D5BA4
 * address:  0x021D5BA4
 * packet:   pkt_021D5BA4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5BA4   0x021D5BA4  thumb ov093
 *
 * Unlabelled ov093 leaf hidden in a .word run: returns the unsigned halfword
 * at +0x146 of its argument.  Matched to supply the `matched` witness for the
 * pending ov096 caller func_02189A9C.
 */
#include "../include/Obj18410.h"

unsigned short func_021D5BA4(int *p)
{
    return ((struct Obj18410 *)p)->f146;
}
