/*
 * function: func_021DADB4
 * address:  0x021DADB4
 * packet:   pkt_021DADB4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none)
 *
 * Competition-server completion callback: records a nonzero result at +0x15c and drops the pending-request count at +0x134 (unlabelled; its address is a code pointer in func_021DA6B8's pool).
 */
#include "../include/Obj14335.h"

void func_021DADB4(int result, char *obj)
{
    if (result != 0)
        ((struct Obj14335 *)obj)->f15C = result;
    (((struct Obj14335 *)obj)->f134)--;
}
