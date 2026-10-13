/*
 * function: BTL_POKEPARAM_GetTurnCount
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
 *   BTL_POKEPARAM_GetTurnCount   0x021D5BA4  thumb ov093
 *
 * Unlabelled ov093 leaf hidden in a .word run: returns the unsigned halfword
 * at +0x146 of its argument.  Matched to supply the `matched` witness for the
 * pending ov096 caller TR_AI_CmdLoadTurnCountOfPoke.
 */
#include "../include/Obj18410.h"

unsigned short BTL_POKEPARAM_GetTurnCount(int *p)
{
    return ((struct Obj18410 *)p)->f146;
}
