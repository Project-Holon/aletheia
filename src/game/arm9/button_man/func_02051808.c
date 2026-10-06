/*
 * function: func_02051808
 * address:  0x02051808
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns the word at offset 0x68 as a short. Filed as the witness for ov094 func_021FD1CC.
 */
#include "../../../matched/include/Obj16175.h"

short func_02051808(char *p)
{
    return ((struct Obj16175 *)p)->f68;
}
