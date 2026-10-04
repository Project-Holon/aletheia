/*
 * function: func_02051820
 * address:  0x02051820
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns the word at offset 0x6c as a short. Filed as the witness for ov094 func_021FD1CC.
 */
#include "../include/Obj16177.h"

short func_02051820(char *p)
{
    return ((struct Obj16177 *)p)->f6C;
}
