/*
 * function: func_021FD904
 * address:  0x021FD904
 * packet:   pkt_021FD904
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FD904   0x021FD904  thumb ov132
 *
 * Unlabelled ov132 leaf hidden in a .word run: returns the word at +0x48.
 * Matched to supply the `matched` witness for the pending ov010 caller
 * MUSICAL_EVENT_CreateLocalPerformer.
 */
#include "../include/Obj23300.h"

int func_021FD904(int *p)
{
    return ((struct Obj23300 *)p)->f48;
}
