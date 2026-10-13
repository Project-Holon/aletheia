/*
 * function: sakeGetStartRequestResult
 * address:  0x021DD2CC
 * packet:   pkt_021DD2CC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Symbols:
 *   (none)
 *
 * ARM leaf getter: returns the word at +0x48 of the ov175 object (the
 * handle sakeiRunRequest stashes there from its callback).
 */
#include "../include/Obj24398.h"

typedef unsigned long u32;

u32 sakeGetStartRequestResult(char *obj)
{
    return ((struct Obj24398 *)obj)->f48;
}
